.. include:: replace.txt
.. highlight:: cpp

.. heading hierarchy:
   ------------- Chapter
   ************* Section (#.#)
   ============= Subsection (#.#.#)
   ############# Paragraph (no number)


=================================
 MmWave module
=================================
This is an ns-3 mmWave module for the simulation of 5G mmWave cellular networks.
A description of this module can be found in [MZ2018]_.

The mmWave module for ns-3 can be used to simulate 5G cellular networks at
mmWave frequencies. This module builds on top of the LTE one, and currently
includes features such as:

* Support of a wide range of channel models, including the latest 3GPP model for frequency spectrum above 6 GHz. Ray tracing and measured traces can also be modeled.

* Custom PHY and MAC classes, inspired to the PHY and MAC of 3GPP NR. They support dynamic TDD, and are parameterized and highly customizable in order to be flexible enough for testing different designs.

* Custom schedulers for the dynamic TDD format

* Carrier Aggregation at the MAC layer

* Enhancements to the RLC layer with re-segmentation of packets for retransmissions

* Dual Connectivity with LTE base stations, with fast secondary cell handover and channel tracking

* Simulation of core network elements (with also the MME as a real node)

The following papers describe in detail the features implemented in the mmWave
module:

* [MZ2018]_ is a comprehensive tutorial with a detailed description of the whole module. We advise the researchers interested in this module to start reading from this paper;

* [ZP2018]_ describes the Carrier Aggregation implementation;

* [ZP2020]_ describes the integration of the spatial channel model based on the 3GPP specifications TR 38.901 V15.0.0;

* [PM2016]_ describes the Dual Connectivity feature.

These other papers describe features that were implemented in older releases: 

* [ZP2017]_ describes the implementation of the 3GPP channel model based on TR 38.900;

* [RP2018]_ describes the multi-sector addition to the 3GPP channel model;

If you use this module in your research, please cite::

  M. Mezzavilla, M. Zhang, M. Polese, R. Ford, S. Dutta, S. Rangan, M. Zorzi, "End-to-End Simulation of 5G mmWave Networks," in IEEE Communications Surveys & Tutorials, vol. 20, no. 3, pp. 2237-2263, thirdquarter 2018.

Bibtex available `here <https://ieeexplore.ieee.org/document/8344116>`_.

Model Description
*****************

The source code for the new module lives in the directory ``src/mmwave``.

MmWaveSpectrumPhy
=================

The class MmWaveSpectrumPhy inherits from SpectrumPhy and handles the transmission
and reception of signals through the SpectrumChannel. Each mmWave device has one
or multiple MmWaveSpectrumPhy instances, which are controlled by the PHY layer and
act as interface(s) towards the SpectrumChannel(s).


When the current slot is assigned for data or control transmission to a certain
device, its PHY layer triggers the associated MmWaveSpectrumPhy instance by
calling the method StartTxDataFrames () or StartTxDlControlFrames (), respectively.
The MmWaveSpectrumPhy instance creates the structure
MmwaveSpectrumSignalParametersDataFrame or MmWaveSpectrumSignalParametersDlCtrlFrame
containing the signal parameters, such as the signal duration, the Power Spectral
Density (PSD) and the information carried, and forwards it to the SpectrumChannel
by calling the method StartTx (). This behavior is depicted in
Figure :ref:`fig-mmwave-spectrum-phy-tx`.


.. _fig-mmwave-spectrum-phy-tx:

.. figure:: figures/mmwave-spectrum-phy-tx.*
   :align: center

   Call graph for data or control transmission.

When a signal is received, the SpectrumChannel triggers the MmWaveSpectrumPhy
instance by scheduling a call to the method StartRx ().
First, it checks if the signal carries data or control information and then
calls the method StartRxData () or StartRxCtrl (), respectively. If the signal
is neither a mmWave data nor mmWave control signal, or it belongs to another
cell, it is treated as interferer.
Figure :ref:`fig-mmwave-spectrum-phy-rx` shows the call graph in case of data
reception.

.. _fig-mmwave-spectrum-phy-rx:

.. figure:: figures/mmwave-spectrum-phy-rx.*
   :align: center

   Call graph for data reception.

Reception of a data signal
##########################

The method StartRxData () stores the received packets and schedule a call to
EndRxData () after the signal duration.
The method EndRxData () determined if the received transport block is corrupted
or not by applying the error model implemented in the class MmWaveMiErrorModel.
If the transport block is not corrupted, it fires the callback m_phyRxDataEndOkCallback
to trigger the PHY layer reception operations.
Also, it takes care of updating the corresponding HARQ process status and of
sending the HARQ feedback by relying on the associated MmWaveHarqPhy instance.

Reception of a control signal
#############################

The method StartRxCtrl () stores the received packets and schedules a call to
EndRxCtrl () after the signal duration.
The error model is not applied to control messages, then the method EndRxCtrl ()
simply fires the callback m_phyRxCtrlEndOkCallback to trigger the PHY layer.

MmWaveBeamformingModel
======================

MmWaveBeamformingModel is a base class handling the beamforming operations.
The classes deriving from MmWaveBeamformingModel implement specific beamforming
schemes.
It holds a pointer to an instance of the class ThreeGppAntennaArrayModel implementing
the antenna model.
The main method is SetBeamformingVectorForDevice (), which computes the
beamforming vector to communicate with a specific device and configures
the antenna.

MmWaveDftBeamforming
####################

The class MmWaveDftBeamforming implements the DFT beamforming algorithm (TODO
add ref). It holds a pointer to the mobility model associated to the device in
order to retrieve its position.
When the method SetBeamformingVectorForDevice () is called, it computes the
beamforming vector using a DFT-based algorithm and properly configures the
antenna weights by calling the method SetBeamformingVector () on the
associated antenna object.

MmWaveSvdBeamforming
####################

This class implements an ideal beamforming algorithm based on the SVD 
decomposition of the channel matrix. The beamforming vectors 
are computed using the power method described in [ZP2017]_, Section 5. This is 
an ideal method, in the sense that it assumes the perfect knowledge of the 
channel matrix.

References
##########

.. [ZP2020] T. Zugno, M. Polese, N. Patriciello, B. Bojović, S. Lagen, M. Zorzi, 
   “Implementation of A Spatial Channel Model for ns-3”, Submitted to the 
   Workshop on ns-3 (WNS3 ’20).

.. [MZ2018] Marco Mezzavilla, Menglei Zhang, Michele Polese, Russell Ford,
   Sourjya Dutta, Sundeep Rangan, Michele Zorzi, “End-to-End Simulation of 5G
   mmWave Networks”, IEEE Communications Surveys and Tutorials. 2018.

.. [ZP2018] Tommaso Zugno, Michele Polese, and Michele Zorzi. 2018. “Integration of carrier
   aggregation and dual connectivity for the ns-3 mmWave module.”
   In Proceedings of the 10th Workshop on ns-3 (WNS3 '18). ACM, New York, NY,
   USA, 45-52.

.. [ZP2017] Menglei Zhang, Michele Polese, Marco Mezzavilla, Sundeep Rangan, and
   Michele Zorzi. 2017. “ns-3 Implementation of the 3GPP MIMO Channel Model for
   Frequency Spectrum above 6 GHz.” In Proceedings of the Workshop on
   ns-3 (WNS3 '17). ACM, New York, NY, USA, 71-78.

.. [RP2018] M. Rebato, M. Polese, and M. Zorzi, “Multi-Sector and Multi-Panel
   Performance in 5G mmWave Cellular Networks,” in IEEE Global Communications
   Conference: Communication QoS, Reliability and Modeling (Globecom2018 CQRM),
   Abu Dhabi, UAE, Dec 2018

.. [PM2016] M. Polese, M. Mezzavilla, and M. Zorzi, “Performance Comparison of
   Dual Connectivity and Hard Handover for LTE-5G Tight Integration,” in SIMUTools
   2016
