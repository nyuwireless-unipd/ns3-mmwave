/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "rrc-energy.h"

#include "ns3/log.h"
#include "ns3/li-ion-energy-source.h"
#include <ns3/simulator.h>
#include <ns3/nstime.h>
#include <iomanip>
#include <limits>
namespace ns3 {

/* ... */

RrcEnergy::RrcEnergy()
:m_time_last_tx(0),
m_time_last_rx(0),
m_total(0)
{

}

RrcEnergy::~RrcEnergy()
{

}

void
RrcEnergy::Only_uplink_tx(double idletime)
{
    m_total += idletime;
    std::cout<<"Only_uplink_tx: 4 "<<idletime<<" m_total: "<< m_total<<std::endl;
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);
    double energyDecreasedIdle=0.0000000000216 * idletime;
	double energyDecreasedTx = 0.00073542744;
	m_time_last_tx=Simulator::Now().GetMilliSeconds();

	if(m_time_last_rx==m_time_last_tx)
	{
		only_tx(energyDecreasedTx);
		both_downlink_and_uplink(idletime);

	}
	else
	{
		only_tx(energyDecreasedTx+energyDecreasedIdle);
		std::cout<<"Transmit chain is consuming power "<< (energyDecreasedTx+energyDecreasedIdle) <<" joules"<<std::endl;
	}
}

void RrcEnergy::Only_downlink_rx(double idleTime)
{
    m_total += idleTime;
    std::cout<<"Only_downlink_rx: 5 "<<idleTime<<" m_total: "<<m_total<<std::endl;
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);

    double energyDecreasedIdle=0.0000000000216 * idleTime;
	double energyDecreasedRx = 0.000153771192;
	if(m_time_last_rx == m_time_last_tx && m_time_last_tx != 0)
	{
	    std::cout<<"m_time_last_rx: "<<m_time_last_rx<< "m_time_last_tx "<<m_time_last_tx<<std::endl;
		only_tx(energyDecreasedRx);
		both_downlink_and_uplink(idleTime);

	}
	else
	{
		only_tx(energyDecreasedRx+energyDecreasedIdle);
		std::cout<<"Receive chain is consuming power "<< (energyDecreasedRx+energyDecreasedIdle) <<" joules"<<std::endl;
	}

	m_time_last_rx=Simulator::Now().GetMilliSeconds();


}

void RrcEnergy::Only_idle_decrease(double idleTime)
{
    m_total += idleTime;
    std::cout << std::setprecision(16) << std::fixed;
    std::cout<<"Only_idle_decrease: 3 "<<idleTime<<" m_total: "<<m_total<<std::endl;

	//double supplyVoltage=3.6;
	double energyDecreasedIdle=0.0000000000320 * idleTime;//(6/1000)*supplyVoltage*idleTime;

    Callback<void, double> only_tx;
    only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);
	only_tx(energyDecreasedIdle);
}

void RrcEnergy::Only_deepsleep_decrease(double idleTime)
{
    m_total += idleTime;
    std::cout<<"Only_psm_decrease: 1 "<<idleTime<<" m_total: "<<m_total<<std::endl;
    Callback<void, double> only_tx;
    only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);

    //double supplyVoltage=3.6;
    //double energyDecreasedPsm=0.001*supplyVoltage*idleTime/1000000000;
    double energyDecreasedPsm = (0.0000000000000000108)*idleTime;//*supplyVoltage*idleTime/1000000000;
    only_tx(energyDecreasedPsm);
}

void RrcEnergy::Only_drx_decrease(double idleTime)
{
    m_total += idleTime;
    std::cout<<"Only_drx_decrease: 2 "<<idleTime<<" m_total: "<<m_total<<std::endl;
    Callback<void, double> only_tx;
    only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);

    //double supplyVoltage=3.6;
    double energyDecreasedDrx=0.0000000000216*idleTime;//(6/1000)*supplyVoltage*idleTime/1000000000;
    only_tx(energyDecreasedDrx);
}

void RrcEnergy::Only_paging_decrease(double idleTime)
{
    m_total += idleTime;
    std::cout<<"Only_paging_decrease: 7 "<<idleTime<<" m_total: "<<m_total<<std::endl;
    Callback<void, double> only_tx;
    only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);

    //double supplyVoltage=3.6;
    double energyDecreasedPaging=0.0000000000216*idleTime;//(6/1000)*supplyVoltage*idleTime/1000000000;
    only_tx(energyDecreasedPaging);
}

void RrcEnergy::both_downlink_and_uplink(double idleTime)
{
    //m_total += idleTime;
    std::cout<<"both_downlink_and_uplink: 6 "<<idleTime<<" m_total: "<<m_total<<std::endl;
	Callback<void, double> only_tx;
	only_tx = MakeCallback(&LiIonEnergySource::DecreaseRemainingEnergy, &LIES);
	//double supplyVoltage=3.6;
	//double energyDecreasedIdle=0.032*supplyVoltage*0.001;
	double energyDecreasedIdle= 0.00073542744;//(220/1000)*supplyVoltage*(0.000928570);
	only_tx(energyDecreasedIdle);
	std::cout<<"Both Transmit and Receive chain is consuming power "<<std::endl;
}

}

