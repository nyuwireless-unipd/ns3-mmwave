#include "ns3module.h"
static PyMethodDef applications_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications.FatalImpl",
    NULL,
    -1,
    applications_FatalImpl_functions,
};
#endif

static PyObject *
initapplications_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "applications.FatalImpl", applications_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef applications_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications.Hash.Function",
    NULL,
    -1,
    applications_Hash_Function_functions,
};
#endif

static PyObject *
initapplications_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "applications.Hash.Function", applications_Hash_Function_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    /* Import the 'ns3::Hash::Function::Fnv1a' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return NULL;
        }
        _PyNs3HashFunctionFnv1a_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Fnv1a");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Hash::Function::Hash32' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return NULL;
        }
        _PyNs3HashFunctionHash32_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Hash32");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Hash::Function::Hash64' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return NULL;
        }
        _PyNs3HashFunctionHash64_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Hash64");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Hash::Function::Murmur3' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return NULL;
        }
        _PyNs3HashFunctionMurmur3_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Murmur3");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    return m;
}
static PyMethodDef applications_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications.Hash",
    NULL,
    -1,
    applications_Hash_functions,
};
#endif

static PyObject *
initapplications_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "applications.Hash", applications_Hash_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    /* Import the 'ns3::Hash::Implementation' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return NULL;
        }
        _PyNs3HashImplementation_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Implementation");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    submodule = initapplications_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef applications_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications.TracedValueCallback",
    NULL,
    -1,
    applications_TracedValueCallback_functions,
};
#endif

static PyObject *
initapplications_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "applications.TracedValueCallback", applications_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef applications_addressUtils_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_addressUtils_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications.addressUtils",
    NULL,
    -1,
    applications_addressUtils_functions,
};
#endif

static PyObject *
initapplications_addressUtils(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_addressUtils_moduledef);
    #else
    m = Py_InitModule3((char *) "applications.addressUtils", applications_addressUtils_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef applications_internal_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_internal_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications.internal",
    NULL,
    -1,
    applications_internal_functions,
};
#endif

static PyObject *
initapplications_internal(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_internal_moduledef);
    #else
    m = Py_InitModule3((char *) "applications.internal", applications_internal_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef applications_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3Address_Type;
std::map<void*, PyObject*> *_PyNs3Address_wrapper_registry;


PyTypeObject *_PyNs3ApplicationContainer_Type;
std::map<void*, PyObject*> *_PyNs3ApplicationContainer_wrapper_registry;


PyTypeObject *_PyNs3AsciiFile_Type;
std::map<void*, PyObject*> *_PyNs3AsciiFile_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelper_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelper_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelperForDevice_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelperForDevice_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionList_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionList_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionListItem_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionListItem_wrapper_registry;


PyTypeObject *_PyNs3Average__Double_Type;
std::map<void*, PyObject*> *_PyNs3Average__Double_wrapper_registry;


PyTypeObject *_PyNs3Buffer_Type;
std::map<void*, PyObject*> *_PyNs3Buffer_wrapper_registry;


PyTypeObject *_PyNs3BufferIterator_Type;
std::map<void*, PyObject*> *_PyNs3BufferIterator_wrapper_registry;


PyTypeObject *_PyNs3ByteTagIterator_Type;
std::map<void*, PyObject*> *_PyNs3ByteTagIterator_wrapper_registry;


PyTypeObject *_PyNs3ByteTagIteratorItem_Type;
std::map<void*, PyObject*> *_PyNs3ByteTagIteratorItem_wrapper_registry;


PyTypeObject *_PyNs3ByteTagList_Type;
std::map<void*, PyObject*> *_PyNs3ByteTagList_wrapper_registry;


PyTypeObject *_PyNs3ByteTagListIterator_Type;
std::map<void*, PyObject*> *_PyNs3ByteTagListIterator_wrapper_registry;


PyTypeObject *_PyNs3ByteTagListIteratorItem_Type;
std::map<void*, PyObject*> *_PyNs3ByteTagListIteratorItem_wrapper_registry;


PyTypeObject *_PyNs3CallbackBase_Type;
std::map<void*, PyObject*> *_PyNs3CallbackBase_wrapper_registry;


PyTypeObject *_PyNs3ChannelList_Type;
std::map<void*, PyObject*> *_PyNs3ChannelList_wrapper_registry;


PyTypeObject *_PyNs3DataOutputCallback_Type;
std::map<void*, PyObject*> *_PyNs3DataOutputCallback_wrapper_registry;


PyTypeObject *_PyNs3DataRate_Type;
std::map<void*, PyObject*> *_PyNs3DataRate_wrapper_registry;


PyTypeObject *_PyNs3DelayJitterEstimation_Type;
std::map<void*, PyObject*> *_PyNs3DelayJitterEstimation_wrapper_registry;


PyTypeObject *_PyNs3EventId_Type;
std::map<void*, PyObject*> *_PyNs3EventId_wrapper_registry;


PyTypeObject *_PyNs3Hasher_Type;
std::map<void*, PyObject*> *_PyNs3Hasher_wrapper_registry;


PyTypeObject *_PyNs3Inet6SocketAddress_Type;
std::map<void*, PyObject*> *_PyNs3Inet6SocketAddress_wrapper_registry;


PyTypeObject *_PyNs3InetSocketAddress_Type;
std::map<void*, PyObject*> *_PyNs3InetSocketAddress_wrapper_registry;


PyTypeObject *_PyNs3Ipv4Address_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4Address_wrapper_registry;


PyTypeObject *_PyNs3Ipv4Mask_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4Mask_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Address_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Address_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Prefix_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Prefix_wrapper_registry;


PyTypeObject *_PyNs3Mac16Address_Type;
std::map<void*, PyObject*> *_PyNs3Mac16Address_wrapper_registry;


PyTypeObject *_PyNs3Mac48Address_Type;
std::map<void*, PyObject*> *_PyNs3Mac48Address_wrapper_registry;


PyTypeObject *_PyNs3Mac64Address_Type;
std::map<void*, PyObject*> *_PyNs3Mac64Address_wrapper_registry;


PyTypeObject *_PyNs3NetDeviceContainer_Type;
std::map<void*, PyObject*> *_PyNs3NetDeviceContainer_wrapper_registry;


PyTypeObject *_PyNs3NodeContainer_Type;
std::map<void*, PyObject*> *_PyNs3NodeContainer_wrapper_registry;


PyTypeObject *_PyNs3NodeList_Type;
std::map<void*, PyObject*> *_PyNs3NodeList_wrapper_registry;


PyTypeObject *_PyNs3NonCopyable_Type;
std::map<void*, PyObject*> *_PyNs3NonCopyable_wrapper_registry;


PyTypeObject *_PyNs3ObjectBase_Type;
std::map<void*, PyObject*> *_PyNs3ObjectBase_wrapper_registry;


PyTypeObject *_PyNs3ObjectDeleter_Type;
std::map<void*, PyObject*> *_PyNs3ObjectDeleter_wrapper_registry;


PyTypeObject *_PyNs3ObjectFactory_Type;
std::map<void*, PyObject*> *_PyNs3ObjectFactory_wrapper_registry;


PyTypeObject *_PyNs3PacketMetadata_Type;
std::map<void*, PyObject*> *_PyNs3PacketMetadata_wrapper_registry;


PyTypeObject *_PyNs3PacketMetadataItem_Type;
std::map<void*, PyObject*> *_PyNs3PacketMetadataItem_wrapper_registry;


PyTypeObject *_PyNs3PacketMetadataItemIterator_Type;
std::map<void*, PyObject*> *_PyNs3PacketMetadataItemIterator_wrapper_registry;


PyTypeObject *_PyNs3PacketSocketAddress_Type;
std::map<void*, PyObject*> *_PyNs3PacketSocketAddress_wrapper_registry;


PyTypeObject *_PyNs3PacketSocketHelper_Type;
std::map<void*, PyObject*> *_PyNs3PacketSocketHelper_wrapper_registry;


PyTypeObject *_PyNs3PacketTagIterator_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagIterator_wrapper_registry;


PyTypeObject *_PyNs3PacketTagIteratorItem_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagIteratorItem_wrapper_registry;


PyTypeObject *_PyNs3PacketTagList_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagList_wrapper_registry;


PyTypeObject *_PyNs3PacketTagListTagData_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagListTagData_wrapper_registry;


PyTypeObject *_PyNs3PbbAddressTlvBlock_Type;
std::map<void*, PyObject*> *_PyNs3PbbAddressTlvBlock_wrapper_registry;


PyTypeObject *_PyNs3PbbTlvBlock_Type;
std::map<void*, PyObject*> *_PyNs3PbbTlvBlock_wrapper_registry;


PyTypeObject *_PyNs3PcapFile_Type;
std::map<void*, PyObject*> *_PyNs3PcapFile_wrapper_registry;


PyTypeObject *_PyNs3PcapHelper_Type;
std::map<void*, PyObject*> *_PyNs3PcapHelper_wrapper_registry;


PyTypeObject *_PyNs3PcapHelperForDevice_Type;
std::map<void*, PyObject*> *_PyNs3PcapHelperForDevice_wrapper_registry;


PyTypeObject *_PyNs3SimpleNetDeviceHelper_Type;
std::map<void*, PyObject*> *_PyNs3SimpleNetDeviceHelper_wrapper_registry;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map;


PyTypeObject *_PyNs3Simulator_Type;
std::map<void*, PyObject*> *_PyNs3Simulator_wrapper_registry;


PyTypeObject *_PyNs3StatisticalSummary_Type;
std::map<void*, PyObject*> *_PyNs3StatisticalSummary_wrapper_registry;


PyTypeObject *_PyNs3SystemWallClockMs_Type;
std::map<void*, PyObject*> *_PyNs3SystemWallClockMs_wrapper_registry;


PyTypeObject *_PyNs3Tag_Type;


PyTypeObject *_PyNs3TagBuffer_Type;
std::map<void*, PyObject*> *_PyNs3TagBuffer_wrapper_registry;


PyTypeObject *_PyNs3TimeWithUnit_Type;
std::map<void*, PyObject*> *_PyNs3TimeWithUnit_wrapper_registry;


PyTypeObject *_PyNs3TypeId_Type;
std::map<void*, PyObject*> *_PyNs3TypeId_wrapper_registry;


PyTypeObject *_PyNs3TypeIdAttributeInformation_Type;
std::map<void*, PyObject*> *_PyNs3TypeIdAttributeInformation_wrapper_registry;


PyTypeObject *_PyNs3TypeIdTraceSourceInformation_Type;
std::map<void*, PyObject*> *_PyNs3TypeIdTraceSourceInformation_wrapper_registry;


PyTypeObject *_PyNs3Empty_Type;
std::map<void*, PyObject*> *_PyNs3Empty_wrapper_registry;


PyTypeObject *_PyNs3Int64x64_t_Type;
std::map<void*, PyObject*> *_PyNs3Int64x64_t_wrapper_registry;


PyTypeObject *_PyNs3Chunk_Type;


PyTypeObject *_PyNs3DeviceNameTag_Type;


PyTypeObject *_PyNs3FlowIdTag_Type;


PyTypeObject *_PyNs3Header_Type;


PyTypeObject *_PyNs3LlcSnapHeader_Type;


PyTypeObject *_PyNs3Object_Type;


PyTypeObject *_PyNs3ObjectAggregateIterator_Type;
std::map<void*, PyObject*> *_PyNs3ObjectAggregateIterator_wrapper_registry;


PyTypeObject *_PyNs3PacketBurst_Type;


PyTypeObject *_PyNs3PacketSocketTag_Type;


PyTypeObject *_PyNs3PcapFileWrapper_Type;


PyTypeObject *_PyNs3Queue_Type;


PyTypeObject *_PyNs3RadiotapHeader_Type;


PyTypeObject *_PyNs3RandomVariableStream_Type;


PyTypeObject *_PyNs3RedQueue_Type;


PyTypeObject *_PyNs3RedQueueStats_Type;
std::map<void*, PyObject*> *_PyNs3RedQueueStats_wrapper_registry;


PyTypeObject *_PyNs3SequentialRandomVariable_Type;


PyTypeObject *_PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3Socket_Type;


PyTypeObject *_PyNs3SocketAddressTag_Type;


PyTypeObject *_PyNs3SocketFactory_Type;


PyTypeObject *_PyNs3SocketIpTosTag_Type;


PyTypeObject *_PyNs3SocketIpTtlTag_Type;


PyTypeObject *_PyNs3SocketIpv6HopLimitTag_Type;


PyTypeObject *_PyNs3SocketIpv6TclassTag_Type;


PyTypeObject *_PyNs3SocketSetDontFragmentTag_Type;


PyTypeObject *_PyNs3Time_Type;
std::map<void*, PyObject*> *_PyNs3Time_wrapper_registry;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


PyTypeObject *_PyNs3Trailer_Type;


PyTypeObject *_PyNs3TriangularRandomVariable_Type;


PyTypeObject *_PyNs3UniformRandomVariable_Type;


PyTypeObject *_PyNs3WeibullRandomVariable_Type;


PyTypeObject *_PyNs3ZetaRandomVariable_Type;


PyTypeObject *_PyNs3ZipfRandomVariable_Type;


PyTypeObject *_PyNs3Application_Type;


PyTypeObject *_PyNs3AttributeAccessor_Type;


PyTypeObject *_PyNs3AttributeChecker_Type;


PyTypeObject *_PyNs3AttributeValue_Type;


PyTypeObject *_PyNs3BooleanChecker_Type;


PyTypeObject *_PyNs3BooleanValue_Type;


PyTypeObject *_PyNs3CallbackChecker_Type;


PyTypeObject *_PyNs3CallbackImplBase_Type;


PyTypeObject *_PyNs3CallbackValue_Type;


PyTypeObject *_PyNs3Channel_Type;


PyTypeObject *_PyNs3ConstantRandomVariable_Type;


PyTypeObject *_PyNs3DataCalculator_Type;


PyTypeObject *_PyNs3DataCollectionObject_Type;


PyTypeObject *_PyNs3DataOutputInterface_Type;


PyTypeObject *_PyNs3DataRateChecker_Type;


PyTypeObject *_PyNs3DataRateValue_Type;


PyTypeObject *_PyNs3DeterministicRandomVariable_Type;


PyTypeObject *_PyNs3DoubleValue_Type;


PyTypeObject *_PyNs3DropTailQueue_Type;


PyTypeObject *_PyNs3EmpiricalRandomVariable_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3EnumChecker_Type;


PyTypeObject *_PyNs3EnumValue_Type;


PyTypeObject *_PyNs3ErlangRandomVariable_Type;


PyTypeObject *_PyNs3ErrorModel_Type;


PyTypeObject *_PyNs3EthernetHeader_Type;


PyTypeObject *_PyNs3EthernetTrailer_Type;


PyTypeObject *_PyNs3EventImpl_Type;


PyTypeObject *_PyNs3ExponentialRandomVariable_Type;


PyTypeObject *_PyNs3GammaRandomVariable_Type;


PyTypeObject *_PyNs3IntegerValue_Type;


PyTypeObject *_PyNs3Ipv4AddressChecker_Type;


PyTypeObject *_PyNs3Ipv4AddressValue_Type;


PyTypeObject *_PyNs3Ipv4MaskChecker_Type;


PyTypeObject *_PyNs3Ipv4MaskValue_Type;


PyTypeObject *_PyNs3Ipv6AddressChecker_Type;


PyTypeObject *_PyNs3Ipv6AddressValue_Type;


PyTypeObject *_PyNs3Ipv6PrefixChecker_Type;


PyTypeObject *_PyNs3Ipv6PrefixValue_Type;


PyTypeObject *_PyNs3ListErrorModel_Type;


PyTypeObject *_PyNs3LogNormalRandomVariable_Type;


PyTypeObject *_PyNs3Mac16AddressChecker_Type;


PyTypeObject *_PyNs3Mac16AddressValue_Type;


PyTypeObject *_PyNs3Mac48AddressChecker_Type;


PyTypeObject *_PyNs3Mac48AddressValue_Type;


PyTypeObject *_PyNs3Mac64AddressChecker_Type;


PyTypeObject *_PyNs3Mac64AddressValue_Type;


PyTypeObject *_PyNs3MinMaxAvgTotalCalculator__Double_Type;


PyTypeObject *_PyNs3MinMaxAvgTotalCalculator__Unsigned_int_Type;


PyTypeObject *_PyNs3NetDevice_Type;


PyTypeObject *_PyNs3NixVector_Type;


PyTypeObject *_PyNs3Node_Type;


PyTypeObject *_PyNs3NormalRandomVariable_Type;


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3OutputStreamWrapper_Type;


PyTypeObject *_PyNs3Packet_Type;


PyTypeObject *_PyNs3PacketSizeMinMaxAvgTotalCalculator_Type;


PyTypeObject *_PyNs3PacketSocket_Type;


PyTypeObject *_PyNs3PacketSocketClient_Type;


PyTypeObject *_PyNs3PacketSocketFactory_Type;


PyTypeObject *_PyNs3PacketSocketServer_Type;


PyTypeObject *_PyNs3ParetoRandomVariable_Type;


PyTypeObject *_PyNs3PbbAddressBlock_Type;


PyTypeObject *_PyNs3PbbAddressBlockIpv4_Type;


PyTypeObject *_PyNs3PbbAddressBlockIpv6_Type;


PyTypeObject *_PyNs3PbbMessage_Type;


PyTypeObject *_PyNs3PbbMessageIpv4_Type;


PyTypeObject *_PyNs3PbbMessageIpv6_Type;


PyTypeObject *_PyNs3PbbPacket_Type;


PyTypeObject *_PyNs3PbbTlv_Type;


PyTypeObject *_PyNs3Probe_Type;


PyTypeObject *_PyNs3RateErrorModel_Type;


PyTypeObject *_PyNs3ReceiveListErrorModel_Type;


PyTypeObject *_PyNs3SimpleChannel_Type;


PyTypeObject *_PyNs3SimpleNetDevice_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3UintegerValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


PyTypeObject *_PyNs3BurstErrorModel_Type;


PyTypeObject *_PyNs3CounterCalculator__Unsigned_int_Type;


PyTypeObject *_PyNs3PacketCounterCalculator_Type;


PyTypeObject *_PyNs3PacketProbe_Type;


PyTypeObject *_PyNs3PbbAddressTlv_Type;


std::map<void*, PyObject*> PyNs3BulkSendHelper_wrapper_registry;


static int
_wrap_PyNs3BulkSendHelper__tp_init__0(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BulkSendHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BulkSendHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::BulkSendHelper(*((PyNs3BulkSendHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3BulkSendHelper__tp_init__1(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *protocol;
    Py_ssize_t protocol_len;
    PyObject *address;
    ns3::Address address2;
    const char *keywords[] = {"protocol", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O", (char **) keywords, &protocol, &protocol_len, &address)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(address, (PyObject*) &PyNs3Address_Type)) {
        address2 = *((PyNs3Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        address2 = *((PyNs3Inet6SocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        address2 = *((PyNs3InetSocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv4Address_Type)) {
        address2 = *((PyNs3Ipv4Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv6Address_Type)) {
        address2 = *((PyNs3Ipv6Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac16Address_Type)) {
        address2 = *((PyNs3Mac16Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac48Address_Type)) {
        address2 = *((PyNs3Mac48Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac64Address_Type)) {
        address2 = *((PyNs3Mac64Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        address2 = *((PyNs3PacketSocketAddress *) address)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(address)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::BulkSendHelper(std::string(protocol, protocol_len), address2);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3BulkSendHelper__tp_init(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3BulkSendHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BulkSendHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3BulkSendHelper_SetAttribute(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3BulkSendHelper_Install__0(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3BulkSendHelper_Install__1(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3BulkSendHelper_Install__2(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3BulkSendHelper_Install(PyNs3BulkSendHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3BulkSendHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BulkSendHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3BulkSendHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


static PyObject*
_wrap_PyNs3BulkSendHelper__copy__(PyNs3BulkSendHelper *self)
{

    PyNs3BulkSendHelper *py_copy;
    py_copy = PyObject_New(PyNs3BulkSendHelper, &PyNs3BulkSendHelper_Type);
    py_copy->obj = new ns3::BulkSendHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3BulkSendHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BulkSendHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3BulkSendHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3BulkSendHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BulkSendHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3BulkSendHelper__tp_dealloc(PyNs3BulkSendHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3BulkSendHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3BulkSendHelper_wrapper_registry.end()) {
        PyNs3BulkSendHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::BulkSendHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BulkSendHelper__tp_richcompare (PyNs3BulkSendHelper *PYBINDGEN_UNUSED(self), PyNs3BulkSendHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BulkSendHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3BulkSendHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.BulkSendHelper",            /* tp_name */
    sizeof(PyNs3BulkSendHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BulkSendHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BulkSendHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BulkSendHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BulkSendHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3OnOffHelper_wrapper_registry;


static int
_wrap_PyNs3OnOffHelper__tp_init__0(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OnOffHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OnOffHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::OnOffHelper(*((PyNs3OnOffHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OnOffHelper__tp_init__1(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *protocol;
    Py_ssize_t protocol_len;
    PyObject *address;
    ns3::Address address2;
    const char *keywords[] = {"protocol", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O", (char **) keywords, &protocol, &protocol_len, &address)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(address, (PyObject*) &PyNs3Address_Type)) {
        address2 = *((PyNs3Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        address2 = *((PyNs3Inet6SocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        address2 = *((PyNs3InetSocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv4Address_Type)) {
        address2 = *((PyNs3Ipv4Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv6Address_Type)) {
        address2 = *((PyNs3Ipv6Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac16Address_Type)) {
        address2 = *((PyNs3Mac16Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac48Address_Type)) {
        address2 = *((PyNs3Mac48Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac64Address_Type)) {
        address2 = *((PyNs3Mac64Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        address2 = *((PyNs3PacketSocketAddress *) address)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(address)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::OnOffHelper(std::string(protocol, protocol_len), address2);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OnOffHelper__tp_init(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OnOffHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OnOffHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3OnOffHelper_SetAttribute(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OnOffHelper_SetConstantRate(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataRate *dataRate;
    unsigned int packetSize = 512;
    const char *keywords[] = {"dataRate", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!|I", (char **) keywords, &PyNs3DataRate_Type, &dataRate, &packetSize)) {
        return NULL;
    }
    self->obj->SetConstantRate(*((PyNs3DataRate *) dataRate)->obj, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3OnOffHelper_Install__0(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3OnOffHelper_Install__1(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3OnOffHelper_Install__2(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3OnOffHelper_Install(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3OnOffHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OnOffHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3OnOffHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3OnOffHelper_AssignStreams(PyNs3OnOffHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    PyNs3NodeContainer *c;
    int64_t stream;
    const char *keywords[] = {"c", "stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!L", (char **) keywords, &PyNs3NodeContainer_Type, &c, &stream)) {
        return NULL;
    }
    retval = self->obj->AssignStreams(*((PyNs3NodeContainer *) c)->obj, stream);
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3OnOffHelper__copy__(PyNs3OnOffHelper *self)
{

    PyNs3OnOffHelper *py_copy;
    py_copy = PyObject_New(PyNs3OnOffHelper, &PyNs3OnOffHelper_Type);
    py_copy->obj = new ns3::OnOffHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OnOffHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OnOffHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3OnOffHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetConstantRate", (PyCFunction) _wrap_PyNs3OnOffHelper_SetConstantRate, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3OnOffHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3OnOffHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OnOffHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OnOffHelper__tp_dealloc(PyNs3OnOffHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OnOffHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OnOffHelper_wrapper_registry.end()) {
        PyNs3OnOffHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::OnOffHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OnOffHelper__tp_richcompare (PyNs3OnOffHelper *PYBINDGEN_UNUSED(self), PyNs3OnOffHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OnOffHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3OnOffHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.OnOffHelper",            /* tp_name */
    sizeof(PyNs3OnOffHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OnOffHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OnOffHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OnOffHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OnOffHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3PacketLossCounter_wrapper_registry;


static int
_wrap_PyNs3PacketLossCounter__tp_init__0(PyNs3PacketLossCounter *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PacketLossCounter *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PacketLossCounter_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PacketLossCounter(*((PyNs3PacketLossCounter *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3PacketLossCounter__tp_init__1(PyNs3PacketLossCounter *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int bitmapSize;
    const char *keywords[] = {"bitmapSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &bitmapSize)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (bitmapSize > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PacketLossCounter(bitmapSize);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3PacketLossCounter__tp_init(PyNs3PacketLossCounter *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PacketLossCounter__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PacketLossCounter__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3PacketLossCounter_GetLost(PyNs3PacketLossCounter *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetLost();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3PacketLossCounter_SetBitMapSize(PyNs3PacketLossCounter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int size;
    const char *keywords[] = {"size", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &size)) {
        return NULL;
    }
    if (size > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetBitMapSize(size);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PacketLossCounter_NotifyReceived(PyNs3PacketLossCounter *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int seq;
    const char *keywords[] = {"seq", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &seq)) {
        return NULL;
    }
    self->obj->NotifyReceived(seq);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PacketLossCounter_GetBitMapSize(PyNs3PacketLossCounter *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetBitMapSize();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3PacketLossCounter__copy__(PyNs3PacketLossCounter *self)
{

    PyNs3PacketLossCounter *py_copy;
    py_copy = PyObject_New(PyNs3PacketLossCounter, &PyNs3PacketLossCounter_Type);
    py_copy->obj = new ns3::PacketLossCounter(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PacketLossCounter_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PacketLossCounter_methods[] = {
    {(char *) "GetLost", (PyCFunction) _wrap_PyNs3PacketLossCounter_GetLost, METH_NOARGS, NULL },
    {(char *) "SetBitMapSize", (PyCFunction) _wrap_PyNs3PacketLossCounter_SetBitMapSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyReceived", (PyCFunction) _wrap_PyNs3PacketLossCounter_NotifyReceived, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBitMapSize", (PyCFunction) _wrap_PyNs3PacketLossCounter_GetBitMapSize, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PacketLossCounter__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3PacketLossCounter__tp_dealloc(PyNs3PacketLossCounter *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PacketLossCounter_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PacketLossCounter_wrapper_registry.end()) {
        PyNs3PacketLossCounter_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::PacketLossCounter *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PacketLossCounter__tp_richcompare (PyNs3PacketLossCounter *PYBINDGEN_UNUSED(self), PyNs3PacketLossCounter *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PacketLossCounter_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3PacketLossCounter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.PacketLossCounter",            /* tp_name */
    sizeof(PyNs3PacketLossCounter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PacketLossCounter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3PacketLossCounter__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PacketLossCounter_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PacketLossCounter__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3PacketSinkHelper_wrapper_registry;


static int
_wrap_PyNs3PacketSinkHelper__tp_init__0(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PacketSinkHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PacketSinkHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PacketSinkHelper(*((PyNs3PacketSinkHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3PacketSinkHelper__tp_init__1(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *protocol;
    Py_ssize_t protocol_len;
    PyObject *address;
    ns3::Address address2;
    const char *keywords[] = {"protocol", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O", (char **) keywords, &protocol, &protocol_len, &address)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(address, (PyObject*) &PyNs3Address_Type)) {
        address2 = *((PyNs3Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        address2 = *((PyNs3Inet6SocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        address2 = *((PyNs3InetSocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv4Address_Type)) {
        address2 = *((PyNs3Ipv4Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv6Address_Type)) {
        address2 = *((PyNs3Ipv6Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac16Address_Type)) {
        address2 = *((PyNs3Mac16Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac48Address_Type)) {
        address2 = *((PyNs3Mac48Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac64Address_Type)) {
        address2 = *((PyNs3Mac64Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        address2 = *((PyNs3PacketSocketAddress *) address)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(address)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PacketSinkHelper(std::string(protocol, protocol_len), address2);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3PacketSinkHelper__tp_init(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PacketSinkHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PacketSinkHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3PacketSinkHelper_SetAttribute(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3PacketSinkHelper_Install__0(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3PacketSinkHelper_Install__1(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3PacketSinkHelper_Install__2(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3PacketSinkHelper_Install(PyNs3PacketSinkHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3PacketSinkHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PacketSinkHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3PacketSinkHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


static PyObject*
_wrap_PyNs3PacketSinkHelper__copy__(PyNs3PacketSinkHelper *self)
{

    PyNs3PacketSinkHelper *py_copy;
    py_copy = PyObject_New(PyNs3PacketSinkHelper, &PyNs3PacketSinkHelper_Type);
    py_copy->obj = new ns3::PacketSinkHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PacketSinkHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PacketSinkHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3PacketSinkHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3PacketSinkHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PacketSinkHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3PacketSinkHelper__tp_dealloc(PyNs3PacketSinkHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PacketSinkHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PacketSinkHelper_wrapper_registry.end()) {
        PyNs3PacketSinkHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::PacketSinkHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PacketSinkHelper__tp_richcompare (PyNs3PacketSinkHelper *PYBINDGEN_UNUSED(self), PyNs3PacketSinkHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PacketSinkHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3PacketSinkHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.PacketSinkHelper",            /* tp_name */
    sizeof(PyNs3PacketSinkHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PacketSinkHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3PacketSinkHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PacketSinkHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PacketSinkHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3Ping6Helper_wrapper_registry;


static int
_wrap_PyNs3Ping6Helper__tp_init__0(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ping6Helper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ping6Helper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ping6Helper(*((PyNs3Ping6Helper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Ping6Helper__tp_init__1(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ping6Helper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Ping6Helper__tp_init(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ping6Helper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ping6Helper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3Ping6Helper_SetRemote(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ip;
    const char *keywords[] = {"ip", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &ip)) {
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv6Address *) ip)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6Helper_SetAttribute(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6Helper_SetLocal(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ip;
    const char *keywords[] = {"ip", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &ip)) {
        return NULL;
    }
    self->obj->SetLocal(*((PyNs3Ipv6Address *) ip)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6Helper_SetIfIndex(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int ifIndex;
    const char *keywords[] = {"ifIndex", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &ifIndex)) {
        return NULL;
    }
    self->obj->SetIfIndex(ifIndex);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6Helper_Install(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6Helper_SetRoutersAddress(PyNs3Ping6Helper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::vector< ns3::Ipv6Address > routers_value;
    const char *keywords[] = {"routers", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__std__vector__lt___ns3__Ipv6Address___gt__, &routers_value)) {
        return NULL;
    }
    self->obj->SetRoutersAddress(routers_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ping6Helper__copy__(PyNs3Ping6Helper *self)
{

    PyNs3Ping6Helper *py_copy;
    py_copy = PyObject_New(PyNs3Ping6Helper, &PyNs3Ping6Helper_Type);
    py_copy->obj = new ns3::Ping6Helper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ping6Helper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ping6Helper_methods[] = {
    {(char *) "SetRemote", (PyCFunction) _wrap_PyNs3Ping6Helper_SetRemote, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3Ping6Helper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLocal", (PyCFunction) _wrap_PyNs3Ping6Helper_SetLocal, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIfIndex", (PyCFunction) _wrap_PyNs3Ping6Helper_SetIfIndex, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3Ping6Helper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetRoutersAddress", (PyCFunction) _wrap_PyNs3Ping6Helper_SetRoutersAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ping6Helper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ping6Helper__tp_dealloc(PyNs3Ping6Helper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ping6Helper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ping6Helper_wrapper_registry.end()) {
        PyNs3Ping6Helper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ping6Helper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ping6Helper__tp_richcompare (PyNs3Ping6Helper *PYBINDGEN_UNUSED(self), PyNs3Ping6Helper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ping6Helper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Ping6Helper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Ping6Helper",            /* tp_name */
    sizeof(PyNs3Ping6Helper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ping6Helper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ping6Helper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ping6Helper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ping6Helper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3RadvdHelper_wrapper_registry;


static int
_wrap_PyNs3RadvdHelper__tp_init__0(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RadvdHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RadvdHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RadvdHelper(*((PyNs3RadvdHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3RadvdHelper__tp_init__1(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RadvdHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3RadvdHelper__tp_init(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RadvdHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RadvdHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3RadvdHelper_ClearPrefixes(PyNs3RadvdHelper *self)
{
    PyObject *py_retval;
    
    self->obj->ClearPrefixes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdHelper_DisableDefaultRouterForInterface(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->DisableDefaultRouterForInterface(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdHelper_SetAttribute(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdHelper_EnableDefaultRouterForInterface(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->EnableDefaultRouterForInterface(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdHelper_Install(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdHelper_GetRadvdInterface(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::RadvdInterface > retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    PyNs3RadvdInterface *py_RadvdInterface;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    retval = self->obj->GetRadvdInterface(interface);
    if (!(const_cast<ns3::RadvdInterface *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::RadvdInterface *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_RadvdInterface = NULL;
    } else {
        py_RadvdInterface = (PyNs3RadvdInterface *) wrapper_lookup_iter->second;
        Py_INCREF(py_RadvdInterface);
    }
    
    if (py_RadvdInterface == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::RadvdInterface *> (ns3::PeekPointer (retval)))), &PyNs3RadvdInterface_Type);
        py_RadvdInterface = PyObject_New(PyNs3RadvdInterface, wrapper_type);
    
        py_RadvdInterface->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::RadvdInterface *> (ns3::PeekPointer (retval))->Ref();
        py_RadvdInterface->obj = const_cast<ns3::RadvdInterface *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_RadvdInterface->obj] = (PyObject *) py_RadvdInterface;
    }
    py_retval = Py_BuildValue((char *) "N", py_RadvdInterface);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdHelper_AddAnnouncedPrefix(PyNs3RadvdHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv6Address *prefix;
    unsigned int prefixLength;
    const char *keywords[] = {"interface", "prefix", "prefixLength", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!I", (char **) keywords, &interface, &PyNs3Ipv6Address_Type, &prefix, &prefixLength)) {
        return NULL;
    }
    self->obj->AddAnnouncedPrefix(interface, *((PyNs3Ipv6Address *) prefix)->obj, prefixLength);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3RadvdHelper__copy__(PyNs3RadvdHelper *self)
{

    PyNs3RadvdHelper *py_copy;
    py_copy = PyObject_New(PyNs3RadvdHelper, &PyNs3RadvdHelper_Type);
    py_copy->obj = new ns3::RadvdHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3RadvdHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RadvdHelper_methods[] = {
    {(char *) "ClearPrefixes", (PyCFunction) _wrap_PyNs3RadvdHelper_ClearPrefixes, METH_NOARGS, NULL },
    {(char *) "DisableDefaultRouterForInterface", (PyCFunction) _wrap_PyNs3RadvdHelper_DisableDefaultRouterForInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3RadvdHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableDefaultRouterForInterface", (PyCFunction) _wrap_PyNs3RadvdHelper_EnableDefaultRouterForInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3RadvdHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRadvdInterface", (PyCFunction) _wrap_PyNs3RadvdHelper_GetRadvdInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddAnnouncedPrefix", (PyCFunction) _wrap_PyNs3RadvdHelper_AddAnnouncedPrefix, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RadvdHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3RadvdHelper__tp_dealloc(PyNs3RadvdHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3RadvdHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3RadvdHelper_wrapper_registry.end()) {
        PyNs3RadvdHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::RadvdHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RadvdHelper__tp_richcompare (PyNs3RadvdHelper *PYBINDGEN_UNUSED(self), PyNs3RadvdHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RadvdHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3RadvdHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.RadvdHelper",            /* tp_name */
    sizeof(PyNs3RadvdHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RadvdHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RadvdHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RadvdHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RadvdHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3UdpClientHelper_wrapper_registry;


static int
_wrap_PyNs3UdpClientHelper__tp_init__0(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpClientHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpClientHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpClientHelper(*((PyNs3UdpClientHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpClientHelper__tp_init__1(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpClientHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpClientHelper__tp_init__2(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpClientHelper(*((PyNs3Ipv4Address *) ip)->obj, port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpClientHelper__tp_init__3(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv6Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpClientHelper(*((PyNs3Ipv6Address *) ip)->obj, port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpClientHelper__tp_init__4(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *ip;
    ns3::Address ip2;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Oi", (char **) keywords, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Address_Type)) {
        ip2 = *((PyNs3Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        ip2 = *((PyNs3Inet6SocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        ip2 = *((PyNs3InetSocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv4Address_Type)) {
        ip2 = *((PyNs3Ipv4Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv6Address_Type)) {
        ip2 = *((PyNs3Ipv6Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac16Address_Type)) {
        ip2 = *((PyNs3Mac16Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac48Address_Type)) {
        ip2 = *((PyNs3Mac48Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac64Address_Type)) {
        ip2 = *((PyNs3Mac64Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        ip2 = *((PyNs3PacketSocketAddress *) ip)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(ip)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpClientHelper(ip2, port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3UdpClientHelper__tp_init(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3UdpClientHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpClientHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpClientHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3UdpClientHelper__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3UdpClientHelper__tp_init__4(self, args, kwargs, &exceptions[4]);
    if (!exceptions[4]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        return retval;
    }
    error_list = PyList_New(5);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyList_SET_ITEM(error_list, 3, PyObject_Str(exceptions[3]));
    Py_DECREF(exceptions[3]);
    PyList_SET_ITEM(error_list, 4, PyObject_Str(exceptions[4]));
    Py_DECREF(exceptions[4]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpClientHelper_SetAttribute(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpClientHelper_Install(PyNs3UdpClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpClientHelper__copy__(PyNs3UdpClientHelper *self)
{

    PyNs3UdpClientHelper *py_copy;
    py_copy = PyObject_New(PyNs3UdpClientHelper, &PyNs3UdpClientHelper_Type);
    py_copy->obj = new ns3::UdpClientHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3UdpClientHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpClientHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3UdpClientHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3UdpClientHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpClientHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3UdpClientHelper__tp_dealloc(PyNs3UdpClientHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3UdpClientHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3UdpClientHelper_wrapper_registry.end()) {
        PyNs3UdpClientHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::UdpClientHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpClientHelper__tp_richcompare (PyNs3UdpClientHelper *PYBINDGEN_UNUSED(self), PyNs3UdpClientHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpClientHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpClientHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpClientHelper",            /* tp_name */
    sizeof(PyNs3UdpClientHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpClientHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpClientHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpClientHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpClientHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3UdpEchoClientHelper_wrapper_registry;


static int
_wrap_PyNs3UdpEchoClientHelper__tp_init__0(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpEchoClientHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpEchoClientHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpEchoClientHelper(*((PyNs3UdpEchoClientHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpEchoClientHelper__tp_init__1(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *ip;
    ns3::Address ip2;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Oi", (char **) keywords, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Address_Type)) {
        ip2 = *((PyNs3Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        ip2 = *((PyNs3Inet6SocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        ip2 = *((PyNs3InetSocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv4Address_Type)) {
        ip2 = *((PyNs3Ipv4Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv6Address_Type)) {
        ip2 = *((PyNs3Ipv6Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac16Address_Type)) {
        ip2 = *((PyNs3Mac16Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac48Address_Type)) {
        ip2 = *((PyNs3Mac48Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac64Address_Type)) {
        ip2 = *((PyNs3Mac64Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        ip2 = *((PyNs3PacketSocketAddress *) ip)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(ip)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpEchoClientHelper(ip2, port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpEchoClientHelper__tp_init__2(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpEchoClientHelper(*((PyNs3Ipv4Address *) ip)->obj, port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpEchoClientHelper__tp_init__3(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv6Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpEchoClientHelper(*((PyNs3Ipv6Address *) ip)->obj, port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3UdpEchoClientHelper__tp_init(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[4] = {0,};
    retval = _wrap_PyNs3UdpEchoClientHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClientHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClientHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClientHelper__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    error_list = PyList_New(4);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyList_SET_ITEM(error_list, 3, PyObject_Str(exceptions[3]));
    Py_DECREF(exceptions[3]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}



PyObject *
_wrap_PyNs3UdpEchoClientHelper_SetFill__0(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Application *app;
    ns3::Application *app_ptr;
    const char *fill;
    Py_ssize_t fill_len;
    const char *keywords[] = {"app", "fill", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3Application_Type, &app, &fill, &fill_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    app_ptr = (app ? app->obj : NULL);
    self->obj->SetFill(ns3::Ptr< ns3::Application  > (app_ptr), std::string(fill, fill_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoClientHelper_SetFill__1(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Application *app;
    ns3::Application *app_ptr;
    int fill;
    unsigned int dataLength;
    const char *keywords[] = {"app", "fill", "dataLength", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!iI", (char **) keywords, &PyNs3Application_Type, &app, &fill, &dataLength)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    app_ptr = (app ? app->obj : NULL);
    if (fill > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetFill(ns3::Ptr< ns3::Application  > (app_ptr), fill, dataLength);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3UdpEchoClientHelper_SetFill(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpEchoClientHelper_SetFill__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClientHelper_SetFill__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3UdpEchoClientHelper_SetAttribute(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3UdpEchoClientHelper_Install__0(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoClientHelper_Install__1(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoClientHelper_Install__2(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3UdpEchoClientHelper_Install(PyNs3UdpEchoClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpEchoClientHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClientHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClientHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


static PyObject*
_wrap_PyNs3UdpEchoClientHelper__copy__(PyNs3UdpEchoClientHelper *self)
{

    PyNs3UdpEchoClientHelper *py_copy;
    py_copy = PyObject_New(PyNs3UdpEchoClientHelper, &PyNs3UdpEchoClientHelper_Type);
    py_copy->obj = new ns3::UdpEchoClientHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3UdpEchoClientHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpEchoClientHelper_methods[] = {
    {(char *) "SetFill", (PyCFunction) _wrap_PyNs3UdpEchoClientHelper_SetFill, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3UdpEchoClientHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3UdpEchoClientHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpEchoClientHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3UdpEchoClientHelper__tp_dealloc(PyNs3UdpEchoClientHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3UdpEchoClientHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3UdpEchoClientHelper_wrapper_registry.end()) {
        PyNs3UdpEchoClientHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::UdpEchoClientHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpEchoClientHelper__tp_richcompare (PyNs3UdpEchoClientHelper *PYBINDGEN_UNUSED(self), PyNs3UdpEchoClientHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpEchoClientHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpEchoClientHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpEchoClientHelper",            /* tp_name */
    sizeof(PyNs3UdpEchoClientHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpEchoClientHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpEchoClientHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpEchoClientHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpEchoClientHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3UdpEchoServerHelper_wrapper_registry;


static int
_wrap_PyNs3UdpEchoServerHelper__tp_init__0(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpEchoServerHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpEchoServerHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpEchoServerHelper(*((PyNs3UdpEchoServerHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpEchoServerHelper__tp_init__1(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int port;
    const char *keywords[] = {"port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpEchoServerHelper(port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3UdpEchoServerHelper__tp_init(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpEchoServerHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoServerHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpEchoServerHelper_SetAttribute(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3UdpEchoServerHelper_Install__0(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoServerHelper_Install__1(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoServerHelper_Install__2(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3UdpEchoServerHelper_Install(PyNs3UdpEchoServerHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpEchoServerHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoServerHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoServerHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


static PyObject*
_wrap_PyNs3UdpEchoServerHelper__copy__(PyNs3UdpEchoServerHelper *self)
{

    PyNs3UdpEchoServerHelper *py_copy;
    py_copy = PyObject_New(PyNs3UdpEchoServerHelper, &PyNs3UdpEchoServerHelper_Type);
    py_copy->obj = new ns3::UdpEchoServerHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3UdpEchoServerHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpEchoServerHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3UdpEchoServerHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3UdpEchoServerHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpEchoServerHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3UdpEchoServerHelper__tp_dealloc(PyNs3UdpEchoServerHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3UdpEchoServerHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3UdpEchoServerHelper_wrapper_registry.end()) {
        PyNs3UdpEchoServerHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::UdpEchoServerHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpEchoServerHelper__tp_richcompare (PyNs3UdpEchoServerHelper *PYBINDGEN_UNUSED(self), PyNs3UdpEchoServerHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpEchoServerHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpEchoServerHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpEchoServerHelper",            /* tp_name */
    sizeof(PyNs3UdpEchoServerHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpEchoServerHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpEchoServerHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpEchoServerHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpEchoServerHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3UdpServerHelper_wrapper_registry;


static int
_wrap_PyNs3UdpServerHelper__tp_init__0(PyNs3UdpServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpServerHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpServerHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpServerHelper(*((PyNs3UdpServerHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpServerHelper__tp_init__1(PyNs3UdpServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpServerHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpServerHelper__tp_init__2(PyNs3UdpServerHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int port;
    const char *keywords[] = {"port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpServerHelper(port);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3UdpServerHelper__tp_init(PyNs3UdpServerHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpServerHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpServerHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpServerHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpServerHelper_SetAttribute(PyNs3UdpServerHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpServerHelper_GetServer(PyNs3UdpServerHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::UdpServer > retval;
    PyNs3UdpServer *py_UdpServer;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetServer();
    if (!(const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3UdpServer__PythonHelper).name())
    {
        py_UdpServer = reinterpret_cast< PyNs3UdpServer* >(reinterpret_cast< PyNs3UdpServer__PythonHelper* >(const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval)))->m_pyself);
        py_UdpServer->obj = const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval));
        Py_INCREF(py_UdpServer);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_UdpServer = NULL;
        } else {
            py_UdpServer = (PyNs3UdpServer *) wrapper_lookup_iter->second;
            Py_INCREF(py_UdpServer);
        }
    
        if (py_UdpServer == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval)))), &PyNs3UdpServer_Type);
            py_UdpServer = PyObject_GC_New(PyNs3UdpServer, wrapper_type);
            py_UdpServer->inst_dict = NULL;
    
            py_UdpServer->inst_dict = NULL;
            py_UdpServer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval))->Ref();
            py_UdpServer->obj = const_cast<ns3::UdpServer *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_UdpServer->obj] = (PyObject *) py_UdpServer;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_UdpServer);
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpServerHelper_Install(PyNs3UdpServerHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpServerHelper__copy__(PyNs3UdpServerHelper *self)
{

    PyNs3UdpServerHelper *py_copy;
    py_copy = PyObject_New(PyNs3UdpServerHelper, &PyNs3UdpServerHelper_Type);
    py_copy->obj = new ns3::UdpServerHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3UdpServerHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpServerHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3UdpServerHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetServer", (PyCFunction) _wrap_PyNs3UdpServerHelper_GetServer, METH_NOARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3UdpServerHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpServerHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3UdpServerHelper__tp_dealloc(PyNs3UdpServerHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3UdpServerHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3UdpServerHelper_wrapper_registry.end()) {
        PyNs3UdpServerHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::UdpServerHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpServerHelper__tp_richcompare (PyNs3UdpServerHelper *PYBINDGEN_UNUSED(self), PyNs3UdpServerHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpServerHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpServerHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpServerHelper",            /* tp_name */
    sizeof(PyNs3UdpServerHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpServerHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpServerHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpServerHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpServerHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3UdpTraceClientHelper_wrapper_registry;


static int
_wrap_PyNs3UdpTraceClientHelper__tp_init__0(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpTraceClientHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpTraceClientHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpTraceClientHelper(*((PyNs3UdpTraceClientHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpTraceClientHelper__tp_init__1(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpTraceClientHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpTraceClientHelper__tp_init__2(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *ip;
    ns3::Address ip2;
    int port;
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"ip", "port", "filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Ois#", (char **) keywords, &ip, &port, &filename, &filename_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Address_Type)) {
        ip2 = *((PyNs3Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        ip2 = *((PyNs3Inet6SocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        ip2 = *((PyNs3InetSocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv4Address_Type)) {
        ip2 = *((PyNs3Ipv4Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv6Address_Type)) {
        ip2 = *((PyNs3Ipv6Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac16Address_Type)) {
        ip2 = *((PyNs3Mac16Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac48Address_Type)) {
        ip2 = *((PyNs3Mac48Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac64Address_Type)) {
        ip2 = *((PyNs3Mac64Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        ip2 = *((PyNs3PacketSocketAddress *) ip)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(ip)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpTraceClientHelper(ip2, port, std::string(filename, filename_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpTraceClientHelper__tp_init__3(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4Address *ip;
    int port;
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"ip", "port", "filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!is#", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port, &filename, &filename_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpTraceClientHelper(*((PyNs3Ipv4Address *) ip)->obj, port, std::string(filename, filename_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3UdpTraceClientHelper__tp_init__4(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6Address *ip;
    int port;
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"ip", "port", "filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!is#", (char **) keywords, &PyNs3Ipv6Address_Type, &ip, &port, &filename, &filename_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::UdpTraceClientHelper(*((PyNs3Ipv6Address *) ip)->obj, port, std::string(filename, filename_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3UdpTraceClientHelper__tp_init(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3UdpTraceClientHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClientHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClientHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClientHelper__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClientHelper__tp_init__4(self, args, kwargs, &exceptions[4]);
    if (!exceptions[4]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        return retval;
    }
    error_list = PyList_New(5);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyList_SET_ITEM(error_list, 3, PyObject_Str(exceptions[3]));
    Py_DECREF(exceptions[3]);
    PyList_SET_ITEM(error_list, 4, PyObject_Str(exceptions[4]));
    Py_DECREF(exceptions[4]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpTraceClientHelper_SetAttribute(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpTraceClientHelper_Install(PyNs3UdpTraceClientHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpTraceClientHelper__copy__(PyNs3UdpTraceClientHelper *self)
{

    PyNs3UdpTraceClientHelper *py_copy;
    py_copy = PyObject_New(PyNs3UdpTraceClientHelper, &PyNs3UdpTraceClientHelper_Type);
    py_copy->obj = new ns3::UdpTraceClientHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3UdpTraceClientHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpTraceClientHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3UdpTraceClientHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3UdpTraceClientHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpTraceClientHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3UdpTraceClientHelper__tp_dealloc(PyNs3UdpTraceClientHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3UdpTraceClientHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3UdpTraceClientHelper_wrapper_registry.end()) {
        PyNs3UdpTraceClientHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::UdpTraceClientHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpTraceClientHelper__tp_richcompare (PyNs3UdpTraceClientHelper *PYBINDGEN_UNUSED(self), PyNs3UdpTraceClientHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpTraceClientHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpTraceClientHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpTraceClientHelper",            /* tp_name */
    sizeof(PyNs3UdpTraceClientHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpTraceClientHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpTraceClientHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpTraceClientHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpTraceClientHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};



std::map<void*, PyObject*> PyNs3V4PingHelper_wrapper_registry;


static int
_wrap_PyNs3V4PingHelper__tp_init__0(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3V4PingHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3V4PingHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::V4PingHelper(*((PyNs3V4PingHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3V4PingHelper__tp_init__1(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4Address *remote;
    const char *keywords[] = {"remote", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &remote)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::V4PingHelper(*((PyNs3Ipv4Address *) remote)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3V4PingHelper__tp_init(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3V4PingHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3V4PingHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3V4PingHelper_SetAttribute(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->SetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3V4PingHelper_Install__0(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *nodes;
    const char *keywords[] = {"nodes", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &nodes)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(*((PyNs3NodeContainer *) nodes)->obj);
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3V4PingHelper_Install__1(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::ApplicationContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3V4PingHelper_Install__2(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3ApplicationContainer *py_ApplicationContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::ApplicationContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_ApplicationContainer = PyObject_New(PyNs3ApplicationContainer, &PyNs3ApplicationContainer_Type);
    py_ApplicationContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_ApplicationContainer->obj = new ns3::ApplicationContainer(retval);
    PyNs3ApplicationContainer_wrapper_registry[(void *) py_ApplicationContainer->obj] = (PyObject *) py_ApplicationContainer;
    py_retval = Py_BuildValue((char *) "N", py_ApplicationContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3V4PingHelper_Install(PyNs3V4PingHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3V4PingHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3V4PingHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3V4PingHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


static PyObject*
_wrap_PyNs3V4PingHelper__copy__(PyNs3V4PingHelper *self)
{

    PyNs3V4PingHelper *py_copy;
    py_copy = PyObject_New(PyNs3V4PingHelper, &PyNs3V4PingHelper_Type);
    py_copy->obj = new ns3::V4PingHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3V4PingHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3V4PingHelper_methods[] = {
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3V4PingHelper_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3V4PingHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3V4PingHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3V4PingHelper__tp_dealloc(PyNs3V4PingHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3V4PingHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3V4PingHelper_wrapper_registry.end()) {
        PyNs3V4PingHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::V4PingHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3V4PingHelper__tp_richcompare (PyNs3V4PingHelper *PYBINDGEN_UNUSED(self), PyNs3V4PingHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3V4PingHelper_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3V4PingHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.V4PingHelper",            /* tp_name */
    sizeof(PyNs3V4PingHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3V4PingHelper__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3V4PingHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3V4PingHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3V4PingHelper__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};





static int
_wrap_PyNs3SeqTsHeader__tp_init__0(PyNs3SeqTsHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SeqTsHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SeqTsHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SeqTsHeader(*((PyNs3SeqTsHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SeqTsHeader__tp_init__1(PyNs3SeqTsHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SeqTsHeader();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SeqTsHeader__tp_init(PyNs3SeqTsHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SeqTsHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SeqTsHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3SeqTsHeader_SetSeq(PyNs3SeqTsHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int seq;
    const char *keywords[] = {"seq", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &seq)) {
        return NULL;
    }
    self->obj->SetSeq(seq);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_Deserialize(PyNs3SeqTsHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SeqTsHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_Serialize(PyNs3SeqTsHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *start;
    const char *keywords[] = {"start", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &start)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3BufferIterator *) start)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_GetInstanceTypeId(PyNs3SeqTsHeader *self)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = self->obj->GetInstanceTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_GetSerializedSize(PyNs3SeqTsHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_GetTs(PyNs3SeqTsHeader *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetTs();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3SeqTsHeader_GetSeq(PyNs3SeqTsHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSeq();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3SeqTsHeader__copy__(PyNs3SeqTsHeader *self)
{

    PyNs3SeqTsHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3SeqTsHeader, &PyNs3SeqTsHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SeqTsHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SeqTsHeader_methods[] = {
    {(char *) "SetSeq", (PyCFunction) _wrap_PyNs3SeqTsHeader_SetSeq, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SeqTsHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SeqTsHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SeqTsHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SeqTsHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SeqTsHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "GetTs", (PyCFunction) _wrap_PyNs3SeqTsHeader_GetTs, METH_NOARGS, NULL },
    {(char *) "GetSeq", (PyCFunction) _wrap_PyNs3SeqTsHeader_GetSeq, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SeqTsHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SeqTsHeader__tp_clear(PyNs3SeqTsHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SeqTsHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SeqTsHeader__tp_traverse(PyNs3SeqTsHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SeqTsHeader__tp_dealloc(PyNs3SeqTsHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SeqTsHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SeqTsHeader__tp_richcompare (PyNs3SeqTsHeader *PYBINDGEN_UNUSED(self), PyNs3SeqTsHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SeqTsHeader_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3SeqTsHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.SeqTsHeader",            /* tp_name */
    sizeof(PyNs3SeqTsHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SeqTsHeader__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SeqTsHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SeqTsHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SeqTsHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SeqTsHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SeqTsHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SeqTsHeader__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




pybindgen::TypeMap PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____typeid_map;



static int
_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_init__0(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_init__1(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> >(*((PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_init(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____copy__(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *self)
{

    PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *py_copy;
    py_copy = PyObject_New(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__, &PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type);
    
    py_copy->obj = new ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___methods[] = {
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_dealloc(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> > *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_richcompare (PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *PYBINDGEN_UNUSED(self), PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__ *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__",            /* tp_name */
    sizeof(PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




pybindgen::TypeMap PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____typeid_map;



static int
_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_init__0(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_init__1(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> >(*((PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_init(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____copy__(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *self)
{

    PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *py_copy;
    py_copy = PyObject_New(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__, &PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type);
    
    py_copy->obj = new ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___methods[] = {
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_dealloc(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> > *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_richcompare (PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *PYBINDGEN_UNUSED(self), PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__ *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__",            /* tp_name */
    sizeof(PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3BulkSendApplication__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3BulkSendApplication *self)
{
    PyObject *py_retval;
    PyNs3BulkSendApplication__PythonHelper *helper = dynamic_cast< PyNs3BulkSendApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3BulkSendApplication__PythonHelper::_wrap_DoInitialize(PyNs3BulkSendApplication *self)
{
    PyObject *py_retval;
    PyNs3BulkSendApplication__PythonHelper *helper = dynamic_cast< PyNs3BulkSendApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3BulkSendApplication__PythonHelper::_wrap_NotifyNewAggregate(PyNs3BulkSendApplication *self)
{
    PyObject *py_retval;
    PyNs3BulkSendApplication__PythonHelper *helper = dynamic_cast< PyNs3BulkSendApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3BulkSendApplication__PythonHelper::_wrap_DoDispose(PyNs3BulkSendApplication *self)
{
    PyObject *py_retval;
    PyNs3BulkSendApplication__PythonHelper *helper = dynamic_cast< PyNs3BulkSendApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class BulkSendApplication is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3BulkSendApplication__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BulkSendApplication *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::BulkSendApplication::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = (ns3::BulkSendApplication*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3BulkSendApplication__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BulkSendApplication *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = (ns3::BulkSendApplication*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3BulkSendApplication__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BulkSendApplication *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = (ns3::BulkSendApplication*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BulkSendApplication* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3BulkSendApplication__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3BulkSendApplication__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3BulkSendApplication__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3BulkSendApplication__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3BulkSendApplication__tp_init__0(PyNs3BulkSendApplication *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BulkSendApplication *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BulkSendApplication_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BulkSendApplication_Type)
    {
        self->obj = new PyNs3BulkSendApplication__PythonHelper(*((PyNs3BulkSendApplication *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BulkSendApplication__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BulkSendApplication(*((PyNs3BulkSendApplication *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3BulkSendApplication__tp_init__1(PyNs3BulkSendApplication *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BulkSendApplication_Type)
    {
        self->obj = new PyNs3BulkSendApplication__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BulkSendApplication__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BulkSendApplication();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3BulkSendApplication__tp_init(PyNs3BulkSendApplication *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3BulkSendApplication__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BulkSendApplication__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3BulkSendApplication_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::BulkSendApplication::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3BulkSendApplication_SetMaxBytes(PyNs3BulkSendApplication *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int maxBytes;
    const char *keywords[] = {"maxBytes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &maxBytes)) {
        return NULL;
    }
    self->obj->SetMaxBytes(maxBytes);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BulkSendApplication_GetSocket(PyNs3BulkSendApplication *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Socket > retval;
    PyNs3Socket *py_Socket;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetSocket();
    if (!(const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Socket__PythonHelper).name())
    {
        py_Socket = reinterpret_cast< PyNs3Socket* >(reinterpret_cast< PyNs3Socket__PythonHelper* >(const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Socket);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Socket *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Socket = NULL;
        } else {
            py_Socket = (PyNs3Socket *) wrapper_lookup_iter->second;
            Py_INCREF(py_Socket);
        }
    
        if (py_Socket == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))), &PyNs3Socket_Type);
            py_Socket = PyObject_GC_New(PyNs3Socket, wrapper_type);
            py_Socket->inst_dict = NULL;
    
            py_Socket->inst_dict = NULL;
            py_Socket->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Socket *> (ns3::PeekPointer (retval))->Ref();
            py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Socket->obj] = (PyObject *) py_Socket;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Socket);
    return py_retval;
}


static PyObject*
_wrap_PyNs3BulkSendApplication__copy__(PyNs3BulkSendApplication *self)
{

    PyNs3BulkSendApplication *py_copy;
    py_copy = PyObject_GC_New(PyNs3BulkSendApplication, &PyNs3BulkSendApplication_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::BulkSendApplication(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BulkSendApplication_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3BulkSendApplication_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetMaxBytes", (PyCFunction) _wrap_PyNs3BulkSendApplication_SetMaxBytes, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSocket", (PyCFunction) _wrap_PyNs3BulkSendApplication_GetSocket, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3BulkSendApplication__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3BulkSendApplication__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3BulkSendApplication__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3BulkSendApplication__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BulkSendApplication__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3BulkSendApplication__tp_clear(PyNs3BulkSendApplication *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::BulkSendApplication *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3BulkSendApplication__tp_traverse(PyNs3BulkSendApplication *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3BulkSendApplication__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3BulkSendApplication__tp_dealloc(PyNs3BulkSendApplication *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3BulkSendApplication__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BulkSendApplication__tp_richcompare (PyNs3BulkSendApplication *PYBINDGEN_UNUSED(self), PyNs3BulkSendApplication *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BulkSendApplication_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3BulkSendApplication_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.BulkSendApplication",            /* tp_name */
    sizeof(PyNs3BulkSendApplication),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BulkSendApplication__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3BulkSendApplication__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3BulkSendApplication__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BulkSendApplication__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BulkSendApplication_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3BulkSendApplication, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BulkSendApplication__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3OnOffApplication__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3OnOffApplication *self)
{
    PyObject *py_retval;
    PyNs3OnOffApplication__PythonHelper *helper = dynamic_cast< PyNs3OnOffApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OnOffApplication__PythonHelper::_wrap_DoInitialize(PyNs3OnOffApplication *self)
{
    PyObject *py_retval;
    PyNs3OnOffApplication__PythonHelper *helper = dynamic_cast< PyNs3OnOffApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OnOffApplication__PythonHelper::_wrap_NotifyNewAggregate(PyNs3OnOffApplication *self)
{
    PyObject *py_retval;
    PyNs3OnOffApplication__PythonHelper *helper = dynamic_cast< PyNs3OnOffApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3OnOffApplication__PythonHelper::_wrap_DoDispose(PyNs3OnOffApplication *self)
{
    PyObject *py_retval;
    PyNs3OnOffApplication__PythonHelper *helper = dynamic_cast< PyNs3OnOffApplication__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class OnOffApplication is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3OnOffApplication__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OnOffApplication *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::OnOffApplication::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = (ns3::OnOffApplication*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OnOffApplication__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OnOffApplication *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = (ns3::OnOffApplication*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OnOffApplication__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OnOffApplication *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = (ns3::OnOffApplication*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OnOffApplication* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OnOffApplication__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3OnOffApplication__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3OnOffApplication__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OnOffApplication__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3OnOffApplication__tp_init__0(PyNs3OnOffApplication *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OnOffApplication *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OnOffApplication_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3OnOffApplication_Type)
    {
        self->obj = new PyNs3OnOffApplication__PythonHelper(*((PyNs3OnOffApplication *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3OnOffApplication__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::OnOffApplication(*((PyNs3OnOffApplication *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3OnOffApplication__tp_init__1(PyNs3OnOffApplication *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3OnOffApplication_Type)
    {
        self->obj = new PyNs3OnOffApplication__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3OnOffApplication__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::OnOffApplication();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3OnOffApplication__tp_init(PyNs3OnOffApplication *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OnOffApplication__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OnOffApplication__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3OnOffApplication_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::OnOffApplication::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OnOffApplication_SetMaxBytes(PyNs3OnOffApplication *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int maxBytes;
    const char *keywords[] = {"maxBytes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &maxBytes)) {
        return NULL;
    }
    self->obj->SetMaxBytes(maxBytes);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OnOffApplication_GetSocket(PyNs3OnOffApplication *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Socket > retval;
    PyNs3Socket *py_Socket;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetSocket();
    if (!(const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Socket__PythonHelper).name())
    {
        py_Socket = reinterpret_cast< PyNs3Socket* >(reinterpret_cast< PyNs3Socket__PythonHelper* >(const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Socket);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Socket *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Socket = NULL;
        } else {
            py_Socket = (PyNs3Socket *) wrapper_lookup_iter->second;
            Py_INCREF(py_Socket);
        }
    
        if (py_Socket == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))), &PyNs3Socket_Type);
            py_Socket = PyObject_GC_New(PyNs3Socket, wrapper_type);
            py_Socket->inst_dict = NULL;
    
            py_Socket->inst_dict = NULL;
            py_Socket->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Socket *> (ns3::PeekPointer (retval))->Ref();
            py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Socket->obj] = (PyObject *) py_Socket;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Socket);
    return py_retval;
}


PyObject *
_wrap_PyNs3OnOffApplication_AssignStreams(PyNs3OnOffApplication *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = self->obj->AssignStreams(stream);
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3OnOffApplication__copy__(PyNs3OnOffApplication *self)
{

    PyNs3OnOffApplication *py_copy;
    py_copy = PyObject_GC_New(PyNs3OnOffApplication, &PyNs3OnOffApplication_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::OnOffApplication(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OnOffApplication_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OnOffApplication_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetMaxBytes", (PyCFunction) _wrap_PyNs3OnOffApplication_SetMaxBytes, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSocket", (PyCFunction) _wrap_PyNs3OnOffApplication_GetSocket, METH_NOARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3OnOffApplication_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3OnOffApplication__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3OnOffApplication__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3OnOffApplication__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3OnOffApplication__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OnOffApplication__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OnOffApplication__tp_clear(PyNs3OnOffApplication *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::OnOffApplication *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3OnOffApplication__tp_traverse(PyNs3OnOffApplication *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3OnOffApplication__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3OnOffApplication__tp_dealloc(PyNs3OnOffApplication *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OnOffApplication__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OnOffApplication__tp_richcompare (PyNs3OnOffApplication *PYBINDGEN_UNUSED(self), PyNs3OnOffApplication *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OnOffApplication_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3OnOffApplication_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.OnOffApplication",            /* tp_name */
    sizeof(PyNs3OnOffApplication),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OnOffApplication__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3OnOffApplication__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OnOffApplication__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OnOffApplication__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OnOffApplication_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OnOffApplication, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OnOffApplication__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3PacketSink__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    PyNs3PacketSink__PythonHelper *helper = dynamic_cast< PyNs3PacketSink__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3PacketSink__PythonHelper::_wrap_DoInitialize(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    PyNs3PacketSink__PythonHelper *helper = dynamic_cast< PyNs3PacketSink__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3PacketSink__PythonHelper::_wrap_NotifyNewAggregate(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    PyNs3PacketSink__PythonHelper *helper = dynamic_cast< PyNs3PacketSink__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3PacketSink__PythonHelper::_wrap_DoDispose(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    PyNs3PacketSink__PythonHelper *helper = dynamic_cast< PyNs3PacketSink__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class PacketSink is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3PacketSink__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PacketSink *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::PacketSink::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = (ns3::PacketSink*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3PacketSink__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PacketSink *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = (ns3::PacketSink*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3PacketSink__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PacketSink *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = (ns3::PacketSink*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PacketSink* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3PacketSink__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3PacketSink__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3PacketSink__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3PacketSink__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3PacketSink__tp_init__0(PyNs3PacketSink *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PacketSink *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PacketSink_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3PacketSink_Type)
    {
        self->obj = new PyNs3PacketSink__PythonHelper(*((PyNs3PacketSink *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PacketSink__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::PacketSink(*((PyNs3PacketSink *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3PacketSink__tp_init__1(PyNs3PacketSink *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3PacketSink_Type)
    {
        self->obj = new PyNs3PacketSink__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PacketSink__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::PacketSink();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3PacketSink__tp_init(PyNs3PacketSink *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PacketSink__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PacketSink__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3PacketSink_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::PacketSink::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3PacketSink_GetListeningSocket(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Socket > retval;
    PyNs3Socket *py_Socket;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetListeningSocket();
    if (!(const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Socket__PythonHelper).name())
    {
        py_Socket = reinterpret_cast< PyNs3Socket* >(reinterpret_cast< PyNs3Socket__PythonHelper* >(const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Socket);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Socket *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Socket = NULL;
        } else {
            py_Socket = (PyNs3Socket *) wrapper_lookup_iter->second;
            Py_INCREF(py_Socket);
        }
    
        if (py_Socket == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer (retval)))), &PyNs3Socket_Type);
            py_Socket = PyObject_GC_New(PyNs3Socket, wrapper_type);
            py_Socket->inst_dict = NULL;
    
            py_Socket->inst_dict = NULL;
            py_Socket->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Socket *> (ns3::PeekPointer (retval))->Ref();
            py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Socket->obj] = (PyObject *) py_Socket;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Socket);
    return py_retval;
}


PyObject *
_wrap_PyNs3PacketSink_GetAcceptedSockets(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    std::list< ns3::Ptr< ns3::Socket > > retval;
    Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__ *py_std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__;
    
    retval = self->obj->GetAcceptedSockets();
    py_std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__ = PyObject_New(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__, &Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt___Type);
    py_std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__->obj = new std::list< ns3::Ptr< ns3::Socket > >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3PacketSink_GetTotalRx(PyNs3PacketSink *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetTotalRx();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3PacketSink__copy__(PyNs3PacketSink *self)
{

    PyNs3PacketSink *py_copy;
    py_copy = PyObject_GC_New(PyNs3PacketSink, &PyNs3PacketSink_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::PacketSink(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PacketSink_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3PacketSink_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetListeningSocket", (PyCFunction) _wrap_PyNs3PacketSink_GetListeningSocket, METH_NOARGS, NULL },
    {(char *) "GetAcceptedSockets", (PyCFunction) _wrap_PyNs3PacketSink_GetAcceptedSockets, METH_NOARGS, NULL },
    {(char *) "GetTotalRx", (PyCFunction) _wrap_PyNs3PacketSink_GetTotalRx, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3PacketSink__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3PacketSink__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3PacketSink__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3PacketSink__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PacketSink__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3PacketSink__tp_clear(PyNs3PacketSink *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::PacketSink *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3PacketSink__tp_traverse(PyNs3PacketSink *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3PacketSink__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3PacketSink__tp_dealloc(PyNs3PacketSink *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3PacketSink__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PacketSink__tp_richcompare (PyNs3PacketSink *PYBINDGEN_UNUSED(self), PyNs3PacketSink *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PacketSink_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3PacketSink_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.PacketSink",            /* tp_name */
    sizeof(PyNs3PacketSink),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PacketSink__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3PacketSink__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3PacketSink__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3PacketSink__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PacketSink_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3PacketSink, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PacketSink__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3Ping6__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Ping6 *self)
{
    PyObject *py_retval;
    PyNs3Ping6__PythonHelper *helper = dynamic_cast< PyNs3Ping6__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3Ping6__PythonHelper::_wrap_DoInitialize(PyNs3Ping6 *self)
{
    PyObject *py_retval;
    PyNs3Ping6__PythonHelper *helper = dynamic_cast< PyNs3Ping6__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3Ping6__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Ping6 *self)
{
    PyObject *py_retval;
    PyNs3Ping6__PythonHelper *helper = dynamic_cast< PyNs3Ping6__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3Ping6__PythonHelper::_wrap_DoDispose(PyNs3Ping6 *self)
{
    PyObject *py_retval;
    PyNs3Ping6__PythonHelper *helper = dynamic_cast< PyNs3Ping6__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Ping6 is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3Ping6__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Ping6 *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Ping6::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = (ns3::Ping6*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Ping6__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Ping6 *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = (ns3::Ping6*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Ping6__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Ping6 *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = (ns3::Ping6*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Ping6* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Ping6__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3Ping6__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3Ping6__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Ping6__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3Ping6__tp_init__0(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ping6 *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ping6_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Ping6_Type)
    {
        self->obj = new PyNs3Ping6__PythonHelper(*((PyNs3Ping6 *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Ping6__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Ping6(*((PyNs3Ping6 *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3Ping6__tp_init__1(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Ping6_Type)
    {
        self->obj = new PyNs3Ping6__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Ping6__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Ping6();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3Ping6__tp_init(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ping6__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ping6__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3Ping6_SetLocal(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ipv6;
    const char *keywords[] = {"ipv6", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &ipv6)) {
        return NULL;
    }
    self->obj->SetLocal(*((PyNs3Ipv6Address *) ipv6)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ping6::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6_SetRemote(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ipv6;
    const char *keywords[] = {"ipv6", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &ipv6)) {
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv6Address *) ipv6)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6_SetRouters(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::vector< ns3::Ipv6Address > routers_value;
    const char *keywords[] = {"routers", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__std__vector__lt___ns3__Ipv6Address___gt__, &routers_value)) {
        return NULL;
    }
    self->obj->SetRouters(routers_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Ping6_SetIfIndex(PyNs3Ping6 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int ifIndex;
    const char *keywords[] = {"ifIndex", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &ifIndex)) {
        return NULL;
    }
    self->obj->SetIfIndex(ifIndex);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ping6__copy__(PyNs3Ping6 *self)
{

    PyNs3Ping6 *py_copy;
    py_copy = PyObject_GC_New(PyNs3Ping6, &PyNs3Ping6_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::Ping6(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ping6_methods[] = {
    {(char *) "SetLocal", (PyCFunction) _wrap_PyNs3Ping6_SetLocal, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ping6_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRemote", (PyCFunction) _wrap_PyNs3Ping6_SetRemote, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetRouters", (PyCFunction) _wrap_PyNs3Ping6_SetRouters, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIfIndex", (PyCFunction) _wrap_PyNs3Ping6_SetIfIndex, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Ping6__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Ping6__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Ping6__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Ping6__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ping6__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ping6__tp_clear(PyNs3Ping6 *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ping6 *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ping6__tp_traverse(PyNs3Ping6 *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Ping6__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Ping6__tp_dealloc(PyNs3Ping6 *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ping6__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ping6__tp_richcompare (PyNs3Ping6 *PYBINDGEN_UNUSED(self), PyNs3Ping6 *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ping6_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Ping6_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Ping6",            /* tp_name */
    sizeof(PyNs3Ping6),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ping6__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3Ping6__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ping6__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ping6__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ping6_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ping6, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ping6__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3Radvd__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Radvd *self)
{
    PyObject *py_retval;
    PyNs3Radvd__PythonHelper *helper = dynamic_cast< PyNs3Radvd__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3Radvd__PythonHelper::_wrap_DoInitialize(PyNs3Radvd *self)
{
    PyObject *py_retval;
    PyNs3Radvd__PythonHelper *helper = dynamic_cast< PyNs3Radvd__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3Radvd__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Radvd *self)
{
    PyObject *py_retval;
    PyNs3Radvd__PythonHelper *helper = dynamic_cast< PyNs3Radvd__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3Radvd__PythonHelper::_wrap_DoDispose(PyNs3Radvd *self)
{
    PyObject *py_retval;
    PyNs3Radvd__PythonHelper *helper = dynamic_cast< PyNs3Radvd__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Radvd is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3Radvd__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Radvd *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Radvd::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = (ns3::Radvd*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Radvd__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Radvd *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = (ns3::Radvd*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Radvd__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Radvd *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = (ns3::Radvd*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Radvd* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Radvd__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3Radvd__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3Radvd__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3Radvd__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}
static PyObject* _wrap_PyNs3Radvd__get_MAX_INITIAL_RTR_ADVERTISEMENTS(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::Radvd::MAX_INITIAL_RTR_ADVERTISEMENTS));
    return py_retval;
}
static PyObject* _wrap_PyNs3Radvd__get_MAX_INITIAL_RTR_ADVERT_INTERVAL(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::Radvd::MAX_INITIAL_RTR_ADVERT_INTERVAL));
    return py_retval;
}
static PyObject* _wrap_PyNs3Radvd__get_MAX_RA_DELAY_TIME(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::Radvd::MAX_RA_DELAY_TIME));
    return py_retval;
}
static PyObject* _wrap_PyNs3Radvd__get_MIN_DELAY_BETWEEN_RAS(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::Radvd::MIN_DELAY_BETWEEN_RAS));
    return py_retval;
}
static PyGetSetDef Ns3RadvdMeta__getsets[] = {
    {
        (char*) "MAX_INITIAL_RTR_ADVERTISEMENTS", /* attribute name */
        (getter) _wrap_PyNs3Radvd__get_MAX_INITIAL_RTR_ADVERTISEMENTS, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "MAX_RA_DELAY_TIME", /* attribute name */
        (getter) _wrap_PyNs3Radvd__get_MAX_RA_DELAY_TIME, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "MAX_INITIAL_RTR_ADVERT_INTERVAL", /* attribute name */
        (getter) _wrap_PyNs3Radvd__get_MAX_INITIAL_RTR_ADVERT_INTERVAL, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "MIN_DELAY_BETWEEN_RAS", /* attribute name */
        (getter) _wrap_PyNs3Radvd__get_MIN_DELAY_BETWEEN_RAS, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject PyNs3RadvdMeta_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
	(char *) "Ns3RadvdMeta",		        /* tp_name */
	0,					/* tp_basicsize */
	0,					/* tp_itemsize */
	0,	 				/* tp_dealloc */
	0,					/* tp_print */
	0,					/* tp_getattr */
	0,					/* tp_setattr */
	0,					/* tp_compare */
	0,					/* tp_repr */
	0,					/* tp_as_number */
	0,					/* tp_as_sequence */
	0,		       			/* tp_as_mapping */
	0,					/* tp_hash */
	0,					/* tp_call */
	0,					/* tp_str */
	0,					/* tp_getattro */
	0,					/* tp_setattro */
	0,					/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC|Py_TPFLAGS_BASETYPE, /* tp_flags */
 	0,					/* tp_doc */
	0,					/* tp_traverse */
 	0,					/* tp_clear */
	0,					/* tp_richcompare */
	0,					/* tp_weaklistoffset */
	0,					/* tp_iter */
	0,					/* tp_iternext */
	0,					/* tp_methods */
	0,					/* tp_members */
	Ns3RadvdMeta__getsets,				/* tp_getset */
	0,					/* tp_base */
	0,					/* tp_dict */
	0,	                                /* tp_descr_get */
	0,  		                        /* tp_descr_set */
	0,					/* tp_dictoffset */
	0,					/* tp_init */
	0,					/* tp_alloc */
	0,					/* tp_new */
	0,               			/* tp_free */
        0,                                      /* tp_is_gc */
        0,                                      /* tp_bases */
        0,                                      /* tp_mro */
        0,                                      /* tp_cache */
        0,                                      /* tp_subclasses */
        0,                                      /* tp_weaklist */
        0                                       /* tp_del */
};



static int
_wrap_PyNs3Radvd__tp_init__0(PyNs3Radvd *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Radvd *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Radvd_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Radvd_Type)
    {
        self->obj = new PyNs3Radvd__PythonHelper(*((PyNs3Radvd *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Radvd__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Radvd(*((PyNs3Radvd *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3Radvd__tp_init__1(PyNs3Radvd *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Radvd_Type)
    {
        self->obj = new PyNs3Radvd__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Radvd__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Radvd();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3Radvd__tp_init(PyNs3Radvd *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Radvd__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Radvd__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3Radvd_AddConfiguration(PyNs3Radvd *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RadvdInterface *routerInterface;
    ns3::RadvdInterface *routerInterface_ptr;
    const char *keywords[] = {"routerInterface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RadvdInterface_Type, &routerInterface)) {
        return NULL;
    }
    routerInterface_ptr = (routerInterface ? routerInterface->obj : NULL);
    self->obj->AddConfiguration(ns3::Ptr< ns3::RadvdInterface  > (routerInterface_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Radvd_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Radvd::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Radvd_AssignStreams(PyNs3Radvd *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = self->obj->AssignStreams(stream);
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Radvd__copy__(PyNs3Radvd *self)
{

    PyNs3Radvd *py_copy;
    py_copy = PyObject_GC_New(PyNs3Radvd, &PyNs3Radvd_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::Radvd(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Radvd_methods[] = {
    {(char *) "AddConfiguration", (PyCFunction) _wrap_PyNs3Radvd_AddConfiguration, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Radvd_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3Radvd_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Radvd__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Radvd__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Radvd__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Radvd__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Radvd__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Radvd__tp_clear(PyNs3Radvd *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Radvd *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Radvd__tp_traverse(PyNs3Radvd *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Radvd__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Radvd__tp_dealloc(PyNs3Radvd *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Radvd__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Radvd__tp_richcompare (PyNs3Radvd *PYBINDGEN_UNUSED(self), PyNs3Radvd *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Radvd_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3Radvd_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Radvd",            /* tp_name */
    sizeof(PyNs3Radvd),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Radvd__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3Radvd__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Radvd__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Radvd__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Radvd_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Radvd, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Radvd__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};





static int
_wrap_PyNs3RadvdInterface__tp_init__0(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RadvdInterface *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RadvdInterface_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RadvdInterface(*((PyNs3RadvdInterface *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3RadvdInterface__tp_init__1(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RadvdInterface(interface);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3RadvdInterface__tp_init__2(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    unsigned int interface;
    unsigned int maxRtrAdvInterval;
    unsigned int minRtrAdvInterval;
    const char *keywords[] = {"interface", "maxRtrAdvInterval", "minRtrAdvInterval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "III", (char **) keywords, &interface, &maxRtrAdvInterval, &minRtrAdvInterval)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RadvdInterface(interface, maxRtrAdvInterval, minRtrAdvInterval);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3RadvdInterface__tp_init(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3RadvdInterface__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RadvdInterface__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3RadvdInterface__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetMinRtrAdvInterval(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int minRtrAdvInterval;
    const char *keywords[] = {"minRtrAdvInterval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &minRtrAdvInterval)) {
        return NULL;
    }
    self->obj->SetMinRtrAdvInterval(minRtrAdvInterval);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetHomeAgentPreference(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetHomeAgentPreference();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsManagedFlag(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsManagedFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsHomeAgentInfo(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsHomeAgentInfo();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetDefaultPreference(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetDefaultPreference();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetHomeAgentLifeTime(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetHomeAgentLifeTime();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetManagedFlag(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool managedFlag;
    PyObject *py_managedFlag;
    const char *keywords[] = {"managedFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_managedFlag)) {
        return NULL;
    }
    managedFlag = (bool) PyObject_IsTrue(py_managedFlag);
    self->obj->SetManagedFlag(managedFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetHomeAgentInfo(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool homeAgentFlag;
    PyObject *py_homeAgentFlag;
    const char *keywords[] = {"homeAgentFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_homeAgentFlag)) {
        return NULL;
    }
    homeAgentFlag = (bool) PyObject_IsTrue(py_homeAgentFlag);
    self->obj->SetHomeAgentInfo(homeAgentFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsInitialRtrAdv(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsInitialRtrAdv();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsMobRtrSupportFlag(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsMobRtrSupportFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetMinRtrAdvInterval(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetMinRtrAdvInterval();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetMaxRtrAdvInterval(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetMaxRtrAdvInterval();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsSendAdvert(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsSendAdvert();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetMinDelayBetweenRAs(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int minDelayBetweenRAs;
    const char *keywords[] = {"minDelayBetweenRAs", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &minDelayBetweenRAs)) {
        return NULL;
    }
    self->obj->SetMinDelayBetweenRAs(minDelayBetweenRAs);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetMaxRtrAdvInterval(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int maxRtrAdvInterval;
    const char *keywords[] = {"maxRtrAdvInterval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &maxRtrAdvInterval)) {
        return NULL;
    }
    self->obj->SetMaxRtrAdvInterval(maxRtrAdvInterval);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetCurHopLimit(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetCurHopLimit();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetLastRaTxTime(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetLastRaTxTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_AddPrefix(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RadvdPrefix *routerPrefix;
    ns3::RadvdPrefix *routerPrefix_ptr;
    const char *keywords[] = {"routerPrefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RadvdPrefix_Type, &routerPrefix)) {
        return NULL;
    }
    routerPrefix_ptr = (routerPrefix ? routerPrefix->obj : NULL);
    self->obj->AddPrefix(ns3::Ptr< ns3::RadvdPrefix  > (routerPrefix_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsHomeAgentFlag(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsHomeAgentFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetLastRaTxTime(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *now;
    const char *keywords[] = {"now", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &now)) {
        return NULL;
    }
    self->obj->SetLastRaTxTime(*((PyNs3Time *) now)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetReachableTime(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int reachableTime;
    const char *keywords[] = {"reachableTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &reachableTime)) {
        return NULL;
    }
    self->obj->SetReachableTime(reachableTime);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetHomeAgentLifeTime(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int homeAgentLifeTime;
    const char *keywords[] = {"homeAgentLifeTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &homeAgentLifeTime)) {
        return NULL;
    }
    self->obj->SetHomeAgentLifeTime(homeAgentLifeTime);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetHomeAgentFlag(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool homeAgentFlag;
    PyObject *py_homeAgentFlag;
    const char *keywords[] = {"homeAgentFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_homeAgentFlag)) {
        return NULL;
    }
    homeAgentFlag = (bool) PyObject_IsTrue(py_homeAgentFlag);
    self->obj->SetHomeAgentFlag(homeAgentFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetLinkMtu(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int linkMtu;
    const char *keywords[] = {"linkMtu", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &linkMtu)) {
        return NULL;
    }
    self->obj->SetLinkMtu(linkMtu);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetPrefixes(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    std::list< ns3::Ptr< ns3::RadvdPrefix > > retval;
    Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__ *py_std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__;
    
    retval = self->obj->GetPrefixes();
    py_std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__ = PyObject_New(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__, &Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt___Type);
    py_std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__->obj = new std::list< ns3::Ptr< ns3::RadvdPrefix > >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetHomeAgentPreference(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int homeAgentPreference;
    const char *keywords[] = {"homeAgentPreference", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &homeAgentPreference)) {
        return NULL;
    }
    self->obj->SetHomeAgentPreference(homeAgentPreference);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsSourceLLAddress(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsSourceLLAddress();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsOtherConfigFlag(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsOtherConfigFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetRetransTimer(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int retransTimer;
    const char *keywords[] = {"retransTimer", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &retransTimer)) {
        return NULL;
    }
    self->obj->SetRetransTimer(retransTimer);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetSourceLLAddress(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool sourceLLAddress;
    PyObject *py_sourceLLAddress;
    const char *keywords[] = {"sourceLLAddress", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_sourceLLAddress)) {
        return NULL;
    }
    sourceLLAddress = (bool) PyObject_IsTrue(py_sourceLLAddress);
    self->obj->SetSourceLLAddress(sourceLLAddress);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetCurHopLimit(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int curHopLimit;
    const char *keywords[] = {"curHopLimit", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &curHopLimit)) {
        return NULL;
    }
    if (curHopLimit > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetCurHopLimit(curHopLimit);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetMobRtrSupportFlag(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool mobRtrSupportFlag;
    PyObject *py_mobRtrSupportFlag;
    const char *keywords[] = {"mobRtrSupportFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_mobRtrSupportFlag)) {
        return NULL;
    }
    mobRtrSupportFlag = (bool) PyObject_IsTrue(py_mobRtrSupportFlag);
    self->obj->SetMobRtrSupportFlag(mobRtrSupportFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetDefaultLifeTime(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetDefaultLifeTime();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetDefaultLifeTime(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int defaultLifeTime;
    const char *keywords[] = {"defaultLifeTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &defaultLifeTime)) {
        return NULL;
    }
    self->obj->SetDefaultLifeTime(defaultLifeTime);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_IsIntervalOpt(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsIntervalOpt();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetLinkMtu(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetLinkMtu();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetRetransTimer(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetRetransTimer();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetMinDelayBetweenRAs(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetMinDelayBetweenRAs();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetOtherConfigFlag(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool otherConfigFlag;
    PyObject *py_otherConfigFlag;
    const char *keywords[] = {"otherConfigFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_otherConfigFlag)) {
        return NULL;
    }
    otherConfigFlag = (bool) PyObject_IsTrue(py_otherConfigFlag);
    self->obj->SetOtherConfigFlag(otherConfigFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetSendAdvert(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool sendAdvert;
    PyObject *py_sendAdvert;
    const char *keywords[] = {"sendAdvert", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_sendAdvert)) {
        return NULL;
    }
    sendAdvert = (bool) PyObject_IsTrue(py_sendAdvert);
    self->obj->SetSendAdvert(sendAdvert);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetDefaultPreference(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int defaultPreference;
    const char *keywords[] = {"defaultPreference", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &defaultPreference)) {
        return NULL;
    }
    if (defaultPreference > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDefaultPreference(defaultPreference);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetInterface(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetInterface();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_SetIntervalOpt(PyNs3RadvdInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool intervalOpt;
    PyObject *py_intervalOpt;
    const char *keywords[] = {"intervalOpt", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_intervalOpt)) {
        return NULL;
    }
    intervalOpt = (bool) PyObject_IsTrue(py_intervalOpt);
    self->obj->SetIntervalOpt(intervalOpt);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdInterface_GetReachableTime(PyNs3RadvdInterface *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetReachableTime();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3RadvdInterface__copy__(PyNs3RadvdInterface *self)
{

    PyNs3RadvdInterface *py_copy;
    py_copy = PyObject_New(PyNs3RadvdInterface, &PyNs3RadvdInterface_Type);
    
    py_copy->obj = new ns3::RadvdInterface(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RadvdInterface_methods[] = {
    {(char *) "SetMinRtrAdvInterval", (PyCFunction) _wrap_PyNs3RadvdInterface_SetMinRtrAdvInterval, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHomeAgentPreference", (PyCFunction) _wrap_PyNs3RadvdInterface_GetHomeAgentPreference, METH_NOARGS, NULL },
    {(char *) "IsManagedFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_IsManagedFlag, METH_NOARGS, NULL },
    {(char *) "IsHomeAgentInfo", (PyCFunction) _wrap_PyNs3RadvdInterface_IsHomeAgentInfo, METH_NOARGS, NULL },
    {(char *) "GetDefaultPreference", (PyCFunction) _wrap_PyNs3RadvdInterface_GetDefaultPreference, METH_NOARGS, NULL },
    {(char *) "GetHomeAgentLifeTime", (PyCFunction) _wrap_PyNs3RadvdInterface_GetHomeAgentLifeTime, METH_NOARGS, NULL },
    {(char *) "SetManagedFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_SetManagedFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHomeAgentInfo", (PyCFunction) _wrap_PyNs3RadvdInterface_SetHomeAgentInfo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsInitialRtrAdv", (PyCFunction) _wrap_PyNs3RadvdInterface_IsInitialRtrAdv, METH_NOARGS, NULL },
    {(char *) "IsMobRtrSupportFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_IsMobRtrSupportFlag, METH_NOARGS, NULL },
    {(char *) "GetMinRtrAdvInterval", (PyCFunction) _wrap_PyNs3RadvdInterface_GetMinRtrAdvInterval, METH_NOARGS, NULL },
    {(char *) "GetMaxRtrAdvInterval", (PyCFunction) _wrap_PyNs3RadvdInterface_GetMaxRtrAdvInterval, METH_NOARGS, NULL },
    {(char *) "IsSendAdvert", (PyCFunction) _wrap_PyNs3RadvdInterface_IsSendAdvert, METH_NOARGS, NULL },
    {(char *) "SetMinDelayBetweenRAs", (PyCFunction) _wrap_PyNs3RadvdInterface_SetMinDelayBetweenRAs, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMaxRtrAdvInterval", (PyCFunction) _wrap_PyNs3RadvdInterface_SetMaxRtrAdvInterval, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetCurHopLimit", (PyCFunction) _wrap_PyNs3RadvdInterface_GetCurHopLimit, METH_NOARGS, NULL },
    {(char *) "GetLastRaTxTime", (PyCFunction) _wrap_PyNs3RadvdInterface_GetLastRaTxTime, METH_NOARGS, NULL },
    {(char *) "AddPrefix", (PyCFunction) _wrap_PyNs3RadvdInterface_AddPrefix, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsHomeAgentFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_IsHomeAgentFlag, METH_NOARGS, NULL },
    {(char *) "SetLastRaTxTime", (PyCFunction) _wrap_PyNs3RadvdInterface_SetLastRaTxTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetReachableTime", (PyCFunction) _wrap_PyNs3RadvdInterface_SetReachableTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHomeAgentLifeTime", (PyCFunction) _wrap_PyNs3RadvdInterface_SetHomeAgentLifeTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHomeAgentFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_SetHomeAgentFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLinkMtu", (PyCFunction) _wrap_PyNs3RadvdInterface_SetLinkMtu, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPrefixes", (PyCFunction) _wrap_PyNs3RadvdInterface_GetPrefixes, METH_NOARGS, NULL },
    {(char *) "SetHomeAgentPreference", (PyCFunction) _wrap_PyNs3RadvdInterface_SetHomeAgentPreference, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsSourceLLAddress", (PyCFunction) _wrap_PyNs3RadvdInterface_IsSourceLLAddress, METH_NOARGS, NULL },
    {(char *) "IsOtherConfigFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_IsOtherConfigFlag, METH_NOARGS, NULL },
    {(char *) "SetRetransTimer", (PyCFunction) _wrap_PyNs3RadvdInterface_SetRetransTimer, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSourceLLAddress", (PyCFunction) _wrap_PyNs3RadvdInterface_SetSourceLLAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetCurHopLimit", (PyCFunction) _wrap_PyNs3RadvdInterface_SetCurHopLimit, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMobRtrSupportFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_SetMobRtrSupportFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDefaultLifeTime", (PyCFunction) _wrap_PyNs3RadvdInterface_GetDefaultLifeTime, METH_NOARGS, NULL },
    {(char *) "SetDefaultLifeTime", (PyCFunction) _wrap_PyNs3RadvdInterface_SetDefaultLifeTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsIntervalOpt", (PyCFunction) _wrap_PyNs3RadvdInterface_IsIntervalOpt, METH_NOARGS, NULL },
    {(char *) "GetLinkMtu", (PyCFunction) _wrap_PyNs3RadvdInterface_GetLinkMtu, METH_NOARGS, NULL },
    {(char *) "GetRetransTimer", (PyCFunction) _wrap_PyNs3RadvdInterface_GetRetransTimer, METH_NOARGS, NULL },
    {(char *) "GetMinDelayBetweenRAs", (PyCFunction) _wrap_PyNs3RadvdInterface_GetMinDelayBetweenRAs, METH_NOARGS, NULL },
    {(char *) "SetOtherConfigFlag", (PyCFunction) _wrap_PyNs3RadvdInterface_SetOtherConfigFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSendAdvert", (PyCFunction) _wrap_PyNs3RadvdInterface_SetSendAdvert, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultPreference", (PyCFunction) _wrap_PyNs3RadvdInterface_SetDefaultPreference, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInterface", (PyCFunction) _wrap_PyNs3RadvdInterface_GetInterface, METH_NOARGS, NULL },
    {(char *) "SetIntervalOpt", (PyCFunction) _wrap_PyNs3RadvdInterface_SetIntervalOpt, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetReachableTime", (PyCFunction) _wrap_PyNs3RadvdInterface_GetReachableTime, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RadvdInterface__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3RadvdInterface__tp_dealloc(PyNs3RadvdInterface *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::RadvdInterface *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RadvdInterface__tp_richcompare (PyNs3RadvdInterface *PYBINDGEN_UNUSED(self), PyNs3RadvdInterface *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RadvdInterface_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3RadvdInterface_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.RadvdInterface",            /* tp_name */
    sizeof(PyNs3RadvdInterface),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RadvdInterface__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RadvdInterface__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RadvdInterface_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RadvdInterface__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};





static int
_wrap_PyNs3RadvdPrefix__tp_init__0(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RadvdPrefix *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RadvdPrefix_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RadvdPrefix(*((PyNs3RadvdPrefix *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3RadvdPrefix__tp_init__1(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6Address *network;
    int prefixLength;
    unsigned int preferredLifeTime = 604800;
    unsigned int validLifeTime = 2592000;
    bool onLinkFlag;
    PyObject *py_onLinkFlag = NULL;
    bool autonomousFlag;
    PyObject *py_autonomousFlag = NULL;
    bool routerAddrFlag;
    PyObject *py_routerAddrFlag = NULL;
    const char *keywords[] = {"network", "prefixLength", "preferredLifeTime", "validLifeTime", "onLinkFlag", "autonomousFlag", "routerAddrFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i|IIOOO", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &prefixLength, &preferredLifeTime, &validLifeTime, &py_onLinkFlag, &py_autonomousFlag, &py_routerAddrFlag)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (prefixLength > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    onLinkFlag = py_onLinkFlag? (bool) PyObject_IsTrue(py_onLinkFlag) : true;
    autonomousFlag = py_autonomousFlag? (bool) PyObject_IsTrue(py_autonomousFlag) : true;
    routerAddrFlag = py_routerAddrFlag? (bool) PyObject_IsTrue(py_routerAddrFlag) : false;
    self->obj = new ns3::RadvdPrefix(*((PyNs3Ipv6Address *) network)->obj, prefixLength, preferredLifeTime, validLifeTime, onLinkFlag, autonomousFlag, routerAddrFlag);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3RadvdPrefix__tp_init(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RadvdPrefix__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RadvdPrefix__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3RadvdPrefix_IsRouterAddrFlag(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsRouterAddrFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetNetwork(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    const char *keywords[] = {"network", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &network)) {
        return NULL;
    }
    self->obj->SetNetwork(*((PyNs3Ipv6Address *) network)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetOnLinkFlag(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool onLinkFlag;
    PyObject *py_onLinkFlag;
    const char *keywords[] = {"onLinkFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_onLinkFlag)) {
        return NULL;
    }
    onLinkFlag = (bool) PyObject_IsTrue(py_onLinkFlag);
    self->obj->SetOnLinkFlag(onLinkFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetValidLifeTime(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int validLifeTime;
    const char *keywords[] = {"validLifeTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &validLifeTime)) {
        return NULL;
    }
    self->obj->SetValidLifeTime(validLifeTime);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_IsOnLinkFlag(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsOnLinkFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_GetPrefixLength(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetPrefixLength();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetPreferredLifeTime(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int preferredLifeTime;
    const char *keywords[] = {"preferredLifeTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &preferredLifeTime)) {
        return NULL;
    }
    self->obj->SetPreferredLifeTime(preferredLifeTime);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetAutonomousFlag(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool autonomousFlag;
    PyObject *py_autonomousFlag;
    const char *keywords[] = {"autonomousFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_autonomousFlag)) {
        return NULL;
    }
    autonomousFlag = (bool) PyObject_IsTrue(py_autonomousFlag);
    self->obj->SetAutonomousFlag(autonomousFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_GetPreferredLifeTime(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetPreferredLifeTime();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetPrefixLength(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int prefixLength;
    const char *keywords[] = {"prefixLength", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &prefixLength)) {
        return NULL;
    }
    if (prefixLength > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPrefixLength(prefixLength);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_GetNetwork(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetNetwork();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_SetRouterAddrFlag(PyNs3RadvdPrefix *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool routerAddrFlag;
    PyObject *py_routerAddrFlag;
    const char *keywords[] = {"routerAddrFlag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_routerAddrFlag)) {
        return NULL;
    }
    routerAddrFlag = (bool) PyObject_IsTrue(py_routerAddrFlag);
    self->obj->SetRouterAddrFlag(routerAddrFlag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_IsAutonomousFlag(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsAutonomousFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3RadvdPrefix_GetValidLifeTime(PyNs3RadvdPrefix *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetValidLifeTime();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3RadvdPrefix__copy__(PyNs3RadvdPrefix *self)
{

    PyNs3RadvdPrefix *py_copy;
    py_copy = PyObject_New(PyNs3RadvdPrefix, &PyNs3RadvdPrefix_Type);
    
    py_copy->obj = new ns3::RadvdPrefix(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RadvdPrefix_methods[] = {
    {(char *) "IsRouterAddrFlag", (PyCFunction) _wrap_PyNs3RadvdPrefix_IsRouterAddrFlag, METH_NOARGS, NULL },
    {(char *) "SetNetwork", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetNetwork, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetOnLinkFlag", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetOnLinkFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetValidLifeTime", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetValidLifeTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsOnLinkFlag", (PyCFunction) _wrap_PyNs3RadvdPrefix_IsOnLinkFlag, METH_NOARGS, NULL },
    {(char *) "GetPrefixLength", (PyCFunction) _wrap_PyNs3RadvdPrefix_GetPrefixLength, METH_NOARGS, NULL },
    {(char *) "SetPreferredLifeTime", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetPreferredLifeTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAutonomousFlag", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetAutonomousFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPreferredLifeTime", (PyCFunction) _wrap_PyNs3RadvdPrefix_GetPreferredLifeTime, METH_NOARGS, NULL },
    {(char *) "SetPrefixLength", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetPrefixLength, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNetwork", (PyCFunction) _wrap_PyNs3RadvdPrefix_GetNetwork, METH_NOARGS, NULL },
    {(char *) "SetRouterAddrFlag", (PyCFunction) _wrap_PyNs3RadvdPrefix_SetRouterAddrFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsAutonomousFlag", (PyCFunction) _wrap_PyNs3RadvdPrefix_IsAutonomousFlag, METH_NOARGS, NULL },
    {(char *) "GetValidLifeTime", (PyCFunction) _wrap_PyNs3RadvdPrefix_GetValidLifeTime, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RadvdPrefix__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3RadvdPrefix__tp_dealloc(PyNs3RadvdPrefix *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::RadvdPrefix *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RadvdPrefix__tp_richcompare (PyNs3RadvdPrefix *PYBINDGEN_UNUSED(self), PyNs3RadvdPrefix *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RadvdPrefix_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3RadvdPrefix_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.RadvdPrefix",            /* tp_name */
    sizeof(PyNs3RadvdPrefix),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RadvdPrefix__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RadvdPrefix__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RadvdPrefix_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RadvdPrefix__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3UdpClient__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3UdpClient *self)
{
    PyObject *py_retval;
    PyNs3UdpClient__PythonHelper *helper = dynamic_cast< PyNs3UdpClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpClient__PythonHelper::_wrap_DoInitialize(PyNs3UdpClient *self)
{
    PyObject *py_retval;
    PyNs3UdpClient__PythonHelper *helper = dynamic_cast< PyNs3UdpClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpClient__PythonHelper::_wrap_NotifyNewAggregate(PyNs3UdpClient *self)
{
    PyObject *py_retval;
    PyNs3UdpClient__PythonHelper *helper = dynamic_cast< PyNs3UdpClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpClient__PythonHelper::_wrap_DoDispose(PyNs3UdpClient *self)
{
    PyObject *py_retval;
    PyNs3UdpClient__PythonHelper *helper = dynamic_cast< PyNs3UdpClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class UdpClient is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3UdpClient__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::UdpClient::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = (ns3::UdpClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpClient__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = (ns3::UdpClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpClient__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = (ns3::UdpClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpClient__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3UdpClient__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3UdpClient__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpClient__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3UdpClient__tp_init__0(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpClient *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpClient_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpClient_Type)
    {
        self->obj = new PyNs3UdpClient__PythonHelper(*((PyNs3UdpClient *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpClient(*((PyNs3UdpClient *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UdpClient__tp_init__1(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpClient_Type)
    {
        self->obj = new PyNs3UdpClient__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpClient();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3UdpClient__tp_init(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpClient__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpClient__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpClient_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::UdpClient::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}



PyObject *
_wrap_PyNs3UdpClient_SetRemote__0(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv4Address *) ip)->obj, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpClient_SetRemote__1(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv6Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv6Address *) ip)->obj, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpClient_SetRemote__2(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyObject *ip;
    ns3::Address ip2;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Oi", (char **) keywords, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Address_Type)) {
        ip2 = *((PyNs3Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        ip2 = *((PyNs3Inet6SocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        ip2 = *((PyNs3InetSocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv4Address_Type)) {
        ip2 = *((PyNs3Ipv4Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv6Address_Type)) {
        ip2 = *((PyNs3Ipv6Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac16Address_Type)) {
        ip2 = *((PyNs3Mac16Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac48Address_Type)) {
        ip2 = *((PyNs3Mac48Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac64Address_Type)) {
        ip2 = *((PyNs3Mac64Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        ip2 = *((PyNs3PacketSocketAddress *) ip)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(ip)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(ip2, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3UdpClient_SetRemote(PyNs3UdpClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpClient_SetRemote__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpClient_SetRemote__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpClient_SetRemote__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


static PyObject*
_wrap_PyNs3UdpClient__copy__(PyNs3UdpClient *self)
{

    PyNs3UdpClient *py_copy;
    py_copy = PyObject_GC_New(PyNs3UdpClient, &PyNs3UdpClient_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::UdpClient(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpClient_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3UdpClient_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRemote", (PyCFunction) _wrap_PyNs3UdpClient_SetRemote, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3UdpClient__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3UdpClient__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3UdpClient__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3UdpClient__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpClient__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3UdpClient__tp_clear(PyNs3UdpClient *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::UdpClient *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3UdpClient__tp_traverse(PyNs3UdpClient *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3UdpClient__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3UdpClient__tp_dealloc(PyNs3UdpClient *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3UdpClient__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpClient__tp_richcompare (PyNs3UdpClient *PYBINDGEN_UNUSED(self), PyNs3UdpClient *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpClient_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpClient_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpClient",            /* tp_name */
    sizeof(PyNs3UdpClient),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpClient__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3UdpClient__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3UdpClient__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpClient__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpClient_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3UdpClient, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpClient__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3UdpEchoClient__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3UdpEchoClient *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoClient__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpEchoClient__PythonHelper::_wrap_DoInitialize(PyNs3UdpEchoClient *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoClient__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpEchoClient__PythonHelper::_wrap_NotifyNewAggregate(PyNs3UdpEchoClient *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoClient__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpEchoClient__PythonHelper::_wrap_DoDispose(PyNs3UdpEchoClient *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoClient__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class UdpEchoClient is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3UdpEchoClient__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpEchoClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::UdpEchoClient::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = (ns3::UdpEchoClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoClient__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpEchoClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = (ns3::UdpEchoClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoClient__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpEchoClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = (ns3::UdpEchoClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpEchoClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoClient__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3UdpEchoClient__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3UdpEchoClient__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoClient__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3UdpEchoClient__tp_init__0(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpEchoClient *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpEchoClient_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpEchoClient_Type)
    {
        self->obj = new PyNs3UdpEchoClient__PythonHelper(*((PyNs3UdpEchoClient *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpEchoClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpEchoClient(*((PyNs3UdpEchoClient *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UdpEchoClient__tp_init__1(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpEchoClient_Type)
    {
        self->obj = new PyNs3UdpEchoClient__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpEchoClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpEchoClient();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3UdpEchoClient__tp_init(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpEchoClient__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClient__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpEchoClient_SetDataSize(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int dataSize;
    const char *keywords[] = {"dataSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &dataSize)) {
        return NULL;
    }
    self->obj->SetDataSize(dataSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3UdpEchoClient_SetFill__0(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *fill;
    Py_ssize_t fill_len;
    const char *keywords[] = {"fill", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &fill, &fill_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetFill(std::string(fill, fill_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoClient_SetFill__1(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    int fill;
    unsigned int dataSize;
    const char *keywords[] = {"fill", "dataSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iI", (char **) keywords, &fill, &dataSize)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (fill > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetFill(fill, dataSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3UdpEchoClient_SetFill(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpEchoClient_SetFill__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClient_SetFill__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3UdpEchoClient_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::UdpEchoClient::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}



PyObject *
_wrap_PyNs3UdpEchoClient_SetRemote__0(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv4Address *) ip)->obj, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoClient_SetRemote__1(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv6Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv6Address *) ip)->obj, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpEchoClient_SetRemote__2(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyObject *ip;
    ns3::Address ip2;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Oi", (char **) keywords, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Address_Type)) {
        ip2 = *((PyNs3Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        ip2 = *((PyNs3Inet6SocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        ip2 = *((PyNs3InetSocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv4Address_Type)) {
        ip2 = *((PyNs3Ipv4Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv6Address_Type)) {
        ip2 = *((PyNs3Ipv6Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac16Address_Type)) {
        ip2 = *((PyNs3Mac16Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac48Address_Type)) {
        ip2 = *((PyNs3Mac48Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac64Address_Type)) {
        ip2 = *((PyNs3Mac64Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        ip2 = *((PyNs3PacketSocketAddress *) ip)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(ip)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(ip2, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3UdpEchoClient_SetRemote(PyNs3UdpEchoClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpEchoClient_SetRemote__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClient_SetRemote__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoClient_SetRemote__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3UdpEchoClient_GetDataSize(PyNs3UdpEchoClient *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetDataSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpEchoClient__copy__(PyNs3UdpEchoClient *self)
{

    PyNs3UdpEchoClient *py_copy;
    py_copy = PyObject_GC_New(PyNs3UdpEchoClient, &PyNs3UdpEchoClient_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::UdpEchoClient(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpEchoClient_methods[] = {
    {(char *) "SetDataSize", (PyCFunction) _wrap_PyNs3UdpEchoClient_SetDataSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFill", (PyCFunction) _wrap_PyNs3UdpEchoClient_SetFill, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3UdpEchoClient_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRemote", (PyCFunction) _wrap_PyNs3UdpEchoClient_SetRemote, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDataSize", (PyCFunction) _wrap_PyNs3UdpEchoClient_GetDataSize, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3UdpEchoClient__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3UdpEchoClient__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3UdpEchoClient__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3UdpEchoClient__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpEchoClient__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3UdpEchoClient__tp_clear(PyNs3UdpEchoClient *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::UdpEchoClient *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3UdpEchoClient__tp_traverse(PyNs3UdpEchoClient *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3UdpEchoClient__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3UdpEchoClient__tp_dealloc(PyNs3UdpEchoClient *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3UdpEchoClient__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpEchoClient__tp_richcompare (PyNs3UdpEchoClient *PYBINDGEN_UNUSED(self), PyNs3UdpEchoClient *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpEchoClient_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpEchoClient_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpEchoClient",            /* tp_name */
    sizeof(PyNs3UdpEchoClient),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpEchoClient__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3UdpEchoClient__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3UdpEchoClient__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpEchoClient__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpEchoClient_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3UdpEchoClient, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpEchoClient__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3UdpEchoServer__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3UdpEchoServer *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoServer__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpEchoServer__PythonHelper::_wrap_DoInitialize(PyNs3UdpEchoServer *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoServer__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpEchoServer__PythonHelper::_wrap_NotifyNewAggregate(PyNs3UdpEchoServer *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoServer__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpEchoServer__PythonHelper::_wrap_DoDispose(PyNs3UdpEchoServer *self)
{
    PyObject *py_retval;
    PyNs3UdpEchoServer__PythonHelper *helper = dynamic_cast< PyNs3UdpEchoServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class UdpEchoServer is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3UdpEchoServer__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpEchoServer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::UdpEchoServer::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = (ns3::UdpEchoServer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoServer__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpEchoServer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = (ns3::UdpEchoServer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoServer__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpEchoServer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = (ns3::UdpEchoServer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpEchoServer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoServer__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3UdpEchoServer__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3UdpEchoServer__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpEchoServer__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3UdpEchoServer__tp_init__0(PyNs3UdpEchoServer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpEchoServer *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpEchoServer_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpEchoServer_Type)
    {
        self->obj = new PyNs3UdpEchoServer__PythonHelper(*((PyNs3UdpEchoServer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpEchoServer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpEchoServer(*((PyNs3UdpEchoServer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UdpEchoServer__tp_init__1(PyNs3UdpEchoServer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpEchoServer_Type)
    {
        self->obj = new PyNs3UdpEchoServer__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpEchoServer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpEchoServer();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3UdpEchoServer__tp_init(PyNs3UdpEchoServer *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpEchoServer__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpEchoServer__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpEchoServer_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::UdpEchoServer::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpEchoServer__copy__(PyNs3UdpEchoServer *self)
{

    PyNs3UdpEchoServer *py_copy;
    py_copy = PyObject_GC_New(PyNs3UdpEchoServer, &PyNs3UdpEchoServer_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::UdpEchoServer(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpEchoServer_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3UdpEchoServer_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3UdpEchoServer__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3UdpEchoServer__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3UdpEchoServer__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3UdpEchoServer__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpEchoServer__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3UdpEchoServer__tp_clear(PyNs3UdpEchoServer *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::UdpEchoServer *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3UdpEchoServer__tp_traverse(PyNs3UdpEchoServer *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3UdpEchoServer__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3UdpEchoServer__tp_dealloc(PyNs3UdpEchoServer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3UdpEchoServer__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpEchoServer__tp_richcompare (PyNs3UdpEchoServer *PYBINDGEN_UNUSED(self), PyNs3UdpEchoServer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpEchoServer_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpEchoServer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpEchoServer",            /* tp_name */
    sizeof(PyNs3UdpEchoServer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpEchoServer__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3UdpEchoServer__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3UdpEchoServer__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpEchoServer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpEchoServer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3UdpEchoServer, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpEchoServer__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3UdpServer__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    PyNs3UdpServer__PythonHelper *helper = dynamic_cast< PyNs3UdpServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpServer__PythonHelper::_wrap_DoInitialize(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    PyNs3UdpServer__PythonHelper *helper = dynamic_cast< PyNs3UdpServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpServer__PythonHelper::_wrap_NotifyNewAggregate(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    PyNs3UdpServer__PythonHelper *helper = dynamic_cast< PyNs3UdpServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpServer__PythonHelper::_wrap_DoDispose(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    PyNs3UdpServer__PythonHelper *helper = dynamic_cast< PyNs3UdpServer__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class UdpServer is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3UdpServer__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpServer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::UdpServer::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = (ns3::UdpServer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpServer__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpServer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = (ns3::UdpServer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpServer__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpServer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = (ns3::UdpServer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpServer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpServer__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3UdpServer__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3UdpServer__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpServer__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3UdpServer__tp_init__0(PyNs3UdpServer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpServer *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpServer_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpServer_Type)
    {
        self->obj = new PyNs3UdpServer__PythonHelper(*((PyNs3UdpServer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpServer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpServer(*((PyNs3UdpServer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UdpServer__tp_init__1(PyNs3UdpServer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpServer_Type)
    {
        self->obj = new PyNs3UdpServer__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpServer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpServer();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3UdpServer__tp_init(PyNs3UdpServer *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UdpServer__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpServer__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpServer_GetPacketWindowSize(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetPacketWindowSize();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpServer_GetLost(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetLost();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpServer_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::UdpServer::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpServer_SetPacketWindowSize(PyNs3UdpServer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int size;
    const char *keywords[] = {"size", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &size)) {
        return NULL;
    }
    if (size > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPacketWindowSize(size);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpServer_GetReceived(PyNs3UdpServer *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetReceived();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpServer__copy__(PyNs3UdpServer *self)
{

    PyNs3UdpServer *py_copy;
    py_copy = PyObject_GC_New(PyNs3UdpServer, &PyNs3UdpServer_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::UdpServer(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpServer_methods[] = {
    {(char *) "GetPacketWindowSize", (PyCFunction) _wrap_PyNs3UdpServer_GetPacketWindowSize, METH_NOARGS, NULL },
    {(char *) "GetLost", (PyCFunction) _wrap_PyNs3UdpServer_GetLost, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3UdpServer_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetPacketWindowSize", (PyCFunction) _wrap_PyNs3UdpServer_SetPacketWindowSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetReceived", (PyCFunction) _wrap_PyNs3UdpServer_GetReceived, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3UdpServer__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3UdpServer__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3UdpServer__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3UdpServer__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpServer__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3UdpServer__tp_clear(PyNs3UdpServer *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::UdpServer *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3UdpServer__tp_traverse(PyNs3UdpServer *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3UdpServer__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3UdpServer__tp_dealloc(PyNs3UdpServer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3UdpServer__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpServer__tp_richcompare (PyNs3UdpServer *PYBINDGEN_UNUSED(self), PyNs3UdpServer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpServer_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpServer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpServer",            /* tp_name */
    sizeof(PyNs3UdpServer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpServer__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3UdpServer__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3UdpServer__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpServer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpServer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3UdpServer, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpServer__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3UdpTraceClient__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3UdpTraceClient *self)
{
    PyObject *py_retval;
    PyNs3UdpTraceClient__PythonHelper *helper = dynamic_cast< PyNs3UdpTraceClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpTraceClient__PythonHelper::_wrap_DoInitialize(PyNs3UdpTraceClient *self)
{
    PyObject *py_retval;
    PyNs3UdpTraceClient__PythonHelper *helper = dynamic_cast< PyNs3UdpTraceClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpTraceClient__PythonHelper::_wrap_NotifyNewAggregate(PyNs3UdpTraceClient *self)
{
    PyObject *py_retval;
    PyNs3UdpTraceClient__PythonHelper *helper = dynamic_cast< PyNs3UdpTraceClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3UdpTraceClient__PythonHelper::_wrap_DoDispose(PyNs3UdpTraceClient *self)
{
    PyObject *py_retval;
    PyNs3UdpTraceClient__PythonHelper *helper = dynamic_cast< PyNs3UdpTraceClient__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class UdpTraceClient is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3UdpTraceClient__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpTraceClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::UdpTraceClient::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = (ns3::UdpTraceClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpTraceClient__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpTraceClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = (ns3::UdpTraceClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpTraceClient__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UdpTraceClient *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = (ns3::UdpTraceClient*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UdpTraceClient* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpTraceClient__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3UdpTraceClient__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3UdpTraceClient__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3UdpTraceClient__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3UdpTraceClient__tp_init__0(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UdpTraceClient *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UdpTraceClient_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpTraceClient_Type)
    {
        self->obj = new PyNs3UdpTraceClient__PythonHelper(*((PyNs3UdpTraceClient *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpTraceClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpTraceClient(*((PyNs3UdpTraceClient *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UdpTraceClient__tp_init__1(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpTraceClient_Type)
    {
        self->obj = new PyNs3UdpTraceClient__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpTraceClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpTraceClient();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UdpTraceClient__tp_init__2(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4Address *ip;
    int port;
    char *traceFile;
    const char *keywords[] = {"ip", "port", "traceFile", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!is", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port, &traceFile)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UdpTraceClient_Type)
    {
        self->obj = new PyNs3UdpTraceClient__PythonHelper(*((PyNs3Ipv4Address *) ip)->obj, port, traceFile);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UdpTraceClient__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UdpTraceClient(*((PyNs3Ipv4Address *) ip)->obj, port, traceFile);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3UdpTraceClient__tp_init(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpTraceClient__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClient__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClient__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3UdpTraceClient_GetMaxPacketSize(PyNs3UdpTraceClient *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMaxPacketSize();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpTraceClient_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::UdpTraceClient::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}



PyObject *
_wrap_PyNs3UdpTraceClient_SetRemote__0(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv4Address *) ip)->obj, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpTraceClient_SetRemote__1(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *ip;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv6Address_Type, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(*((PyNs3Ipv6Address *) ip)->obj, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3UdpTraceClient_SetRemote__2(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyObject *ip;
    ns3::Address ip2;
    int port;
    const char *keywords[] = {"ip", "port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Oi", (char **) keywords, &ip, &port)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Address_Type)) {
        ip2 = *((PyNs3Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        ip2 = *((PyNs3Inet6SocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        ip2 = *((PyNs3InetSocketAddress *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv4Address_Type)) {
        ip2 = *((PyNs3Ipv4Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Ipv6Address_Type)) {
        ip2 = *((PyNs3Ipv6Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac16Address_Type)) {
        ip2 = *((PyNs3Mac16Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac48Address_Type)) {
        ip2 = *((PyNs3Mac48Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3Mac64Address_Type)) {
        ip2 = *((PyNs3Mac64Address *) ip)->obj;
    } else if (PyObject_IsInstance(ip, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        ip2 = *((PyNs3PacketSocketAddress *) ip)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(ip)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetRemote(ip2, port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3UdpTraceClient_SetRemote(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3UdpTraceClient_SetRemote__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClient_SetRemote__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3UdpTraceClient_SetRemote__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    error_list = PyList_New(3);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3UdpTraceClient_SetMaxPacketSize(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int maxPacketSize;
    const char *keywords[] = {"maxPacketSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &maxPacketSize)) {
        return NULL;
    }
    if (maxPacketSize > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMaxPacketSize(maxPacketSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UdpTraceClient_SetTraceFile(PyNs3UdpTraceClient *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &filename, &filename_len)) {
        return NULL;
    }
    self->obj->SetTraceFile(std::string(filename, filename_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3UdpTraceClient__copy__(PyNs3UdpTraceClient *self)
{

    PyNs3UdpTraceClient *py_copy;
    py_copy = PyObject_GC_New(PyNs3UdpTraceClient, &PyNs3UdpTraceClient_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::UdpTraceClient(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UdpTraceClient_methods[] = {
    {(char *) "GetMaxPacketSize", (PyCFunction) _wrap_PyNs3UdpTraceClient_GetMaxPacketSize, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3UdpTraceClient_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRemote", (PyCFunction) _wrap_PyNs3UdpTraceClient_SetRemote, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMaxPacketSize", (PyCFunction) _wrap_PyNs3UdpTraceClient_SetMaxPacketSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTraceFile", (PyCFunction) _wrap_PyNs3UdpTraceClient_SetTraceFile, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3UdpTraceClient__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3UdpTraceClient__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3UdpTraceClient__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3UdpTraceClient__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UdpTraceClient__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3UdpTraceClient__tp_clear(PyNs3UdpTraceClient *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::UdpTraceClient *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3UdpTraceClient__tp_traverse(PyNs3UdpTraceClient *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3UdpTraceClient__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3UdpTraceClient__tp_dealloc(PyNs3UdpTraceClient *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3UdpTraceClient__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UdpTraceClient__tp_richcompare (PyNs3UdpTraceClient *PYBINDGEN_UNUSED(self), PyNs3UdpTraceClient *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UdpTraceClient_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3UdpTraceClient_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.UdpTraceClient",            /* tp_name */
    sizeof(PyNs3UdpTraceClient),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UdpTraceClient__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3UdpTraceClient__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3UdpTraceClient__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UdpTraceClient__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UdpTraceClient_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3UdpTraceClient, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UdpTraceClient__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3V4Ping__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3V4Ping *self)
{
    PyObject *py_retval;
    PyNs3V4Ping__PythonHelper *helper = dynamic_cast< PyNs3V4Ping__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3V4Ping__PythonHelper::_wrap_DoInitialize(PyNs3V4Ping *self)
{
    PyObject *py_retval;
    PyNs3V4Ping__PythonHelper *helper = dynamic_cast< PyNs3V4Ping__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Application is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3V4Ping__PythonHelper::_wrap_NotifyNewAggregate(PyNs3V4Ping *self)
{
    PyObject *py_retval;
    PyNs3V4Ping__PythonHelper *helper = dynamic_cast< PyNs3V4Ping__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3V4Ping__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::V4Ping *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj;
    reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = (ns3::V4Ping*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3V4Ping__PythonHelper::StartApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::V4Ping *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StartApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj;
    reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = (ns3::V4Ping*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StartApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3V4Ping__PythonHelper::StopApplication()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::V4Ping *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "StopApplication"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj;
    reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = (ns3::V4Ping*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "StopApplication", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3V4Ping* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3V4Ping__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Application *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Application::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Application* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = (ns3::Application*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Application* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3V4Ping__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3V4Ping__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3V4Ping__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3V4Ping__tp_init__0(PyNs3V4Ping *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3V4Ping *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3V4Ping_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3V4Ping_Type)
    {
        self->obj = new PyNs3V4Ping__PythonHelper(*((PyNs3V4Ping *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3V4Ping__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::V4Ping(*((PyNs3V4Ping *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3V4Ping__tp_init__1(PyNs3V4Ping *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3V4Ping_Type)
    {
        self->obj = new PyNs3V4Ping__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3V4Ping__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::V4Ping();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3V4Ping__tp_init(PyNs3V4Ping *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3V4Ping__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3V4Ping__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3V4Ping_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::V4Ping::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3V4Ping__copy__(PyNs3V4Ping *self)
{

    PyNs3V4Ping *py_copy;
    py_copy = PyObject_GC_New(PyNs3V4Ping, &PyNs3V4Ping_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::V4Ping(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3V4Ping_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3V4Ping_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3V4Ping__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3V4Ping__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3V4Ping__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3V4Ping__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3V4Ping__tp_clear(PyNs3V4Ping *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::V4Ping *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3V4Ping__tp_traverse(PyNs3V4Ping *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3V4Ping__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3V4Ping__tp_dealloc(PyNs3V4Ping *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3V4Ping__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3V4Ping__tp_richcompare (PyNs3V4Ping *PYBINDGEN_UNUSED(self), PyNs3V4Ping *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3V4Ping_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3V4Ping_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.V4Ping",            /* tp_name */
    sizeof(PyNs3V4Ping),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3V4Ping__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3V4Ping__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3V4Ping__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3V4Ping__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3V4Ping_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3V4Ping, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3V4Ping__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




PyObject *
PyNs3ApplicationPacketProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ApplicationPacketProbe *self)
{
    PyObject *py_retval;
    PyNs3ApplicationPacketProbe__PythonHelper *helper = dynamic_cast< PyNs3ApplicationPacketProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3ApplicationPacketProbe__PythonHelper::_wrap_DoInitialize(PyNs3ApplicationPacketProbe *self)
{
    PyObject *py_retval;
    PyNs3ApplicationPacketProbe__PythonHelper *helper = dynamic_cast< PyNs3ApplicationPacketProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3ApplicationPacketProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ApplicationPacketProbe *self)
{
    PyObject *py_retval;
    PyNs3ApplicationPacketProbe__PythonHelper *helper = dynamic_cast< PyNs3ApplicationPacketProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3ApplicationPacketProbe__PythonHelper::_wrap_DoDispose(PyNs3ApplicationPacketProbe *self)
{
    PyObject *py_retval;
    PyNs3ApplicationPacketProbe__PythonHelper *helper = dynamic_cast< PyNs3ApplicationPacketProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

bool
PyNs3ApplicationPacketProbe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ApplicationPacketProbe *self_obj_before;
    PyObject *py_retval;
    bool retval;
    const char *traceSource_ptr;
    Py_ssize_t traceSource_len;
    PyNs3Object *py_Object;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyObject *py_boolretval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByObject"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ApplicationPacketProbe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = (ns3::ApplicationPacketProbe*) this;
    traceSource_ptr = (traceSource).c_str();
    traceSource_len = (traceSource).size();
    if (typeid(*(const_cast<ns3::Object *> (ns3::PeekPointer (obj)))).name() == typeid(PyNs3Object__PythonHelper).name())
    {
        py_Object = (PyNs3Object*) (((PyNs3Object__PythonHelper*) const_cast<ns3::Object *> (ns3::PeekPointer (obj)))->m_pyself);
        py_Object->obj = const_cast<ns3::Object *> (ns3::PeekPointer (obj));
        Py_INCREF(py_Object);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Object *> (ns3::PeekPointer (obj)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Object = NULL;
        } else {
            py_Object = (PyNs3Object *) wrapper_lookup_iter->second;
            Py_INCREF(py_Object);
        }
    
        if (py_Object == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::Object *> (ns3::PeekPointer (obj))), &PyNs3Object_Type);
            py_Object = PyObject_GC_New(PyNs3Object, wrapper_type);
            py_Object->inst_dict = NULL;
    
            py_Object->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Object *> (ns3::PeekPointer (obj))->Ref();
            py_Object->obj = const_cast<ns3::Object *> (ns3::PeekPointer (obj));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Object->obj] = (PyObject *) py_Object;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByObject", (char *) "s#N", traceSource_ptr, traceSource_len, py_Object);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ApplicationPacketProbe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ApplicationPacketProbe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3ApplicationPacketProbe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ApplicationPacketProbe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ApplicationPacketProbe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = (ns3::ApplicationPacketProbe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ApplicationPacketProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3ApplicationPacketProbe__PythonHelper::IsEnabled() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Probe *self_obj_before;
    PyObject *py_retval;
    bool retval;
    PyObject *py_boolretval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "IsEnabled"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Probe::IsEnabled();
    }
    self_obj_before = reinterpret_cast< PyNs3Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = const_cast< ns3::Probe* >((const ns3::Probe*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "IsEnabled", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Probe::IsEnabled();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Probe::IsEnabled();
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ApplicationPacketProbe__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = const_cast< ns3::Object* >((const ns3::Object*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Object::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3ApplicationPacketProbe__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3ApplicationPacketProbe__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3ApplicationPacketProbe__PythonHelper::NotifyNewAggregate()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Object *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyNewAggregate"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Object::NotifyNewAggregate();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Object* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = (ns3::Object*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyNewAggregate", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Object* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3ApplicationPacketProbe__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ObjectBase *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::ObjectBase::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = (ns3::ObjectBase*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ObjectBase* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3ApplicationPacketProbe__tp_init__0(PyNs3ApplicationPacketProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ApplicationPacketProbe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ApplicationPacketProbe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ApplicationPacketProbe_Type)
    {
        self->obj = new PyNs3ApplicationPacketProbe__PythonHelper(*((PyNs3ApplicationPacketProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ApplicationPacketProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ApplicationPacketProbe(*((PyNs3ApplicationPacketProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ApplicationPacketProbe__tp_init__1(PyNs3ApplicationPacketProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ApplicationPacketProbe_Type)
    {
        self->obj = new PyNs3ApplicationPacketProbe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ApplicationPacketProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ApplicationPacketProbe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ApplicationPacketProbe__tp_init(PyNs3ApplicationPacketProbe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ApplicationPacketProbe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ApplicationPacketProbe__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    error_list = PyList_New(2);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3ApplicationPacketProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ApplicationPacketProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ApplicationPacketProbe_ConnectByObject(PyNs3ApplicationPacketProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3ApplicationPacketProbe__PythonHelper *helper_class = dynamic_cast<PyNs3ApplicationPacketProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::ApplicationPacketProbe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3ApplicationPacketProbe_ConnectByPath(PyNs3ApplicationPacketProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3ApplicationPacketProbe__PythonHelper *helper_class = dynamic_cast<PyNs3ApplicationPacketProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::ApplicationPacketProbe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ApplicationPacketProbe_SetValueByPath(PyNs3ApplicationPacketProbe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3Packet *packet;
    ns3::Packet *packet_ptr;
    PyObject *address;
    ns3::Address address2;
    const char *keywords[] = {"path", "packet", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!O", (char **) keywords, &path, &path_len, &PyNs3Packet_Type, &packet, &address)) {
        return NULL;
    }
    packet_ptr = (packet ? packet->obj : NULL);
    if (PyObject_IsInstance(address, (PyObject*) &PyNs3Address_Type)) {
        address2 = *((PyNs3Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        address2 = *((PyNs3Inet6SocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        address2 = *((PyNs3InetSocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv4Address_Type)) {
        address2 = *((PyNs3Ipv4Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv6Address_Type)) {
        address2 = *((PyNs3Ipv6Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac16Address_Type)) {
        address2 = *((PyNs3Mac16Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac48Address_Type)) {
        address2 = *((PyNs3Mac48Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac64Address_Type)) {
        address2 = *((PyNs3Mac64Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        address2 = *((PyNs3PacketSocketAddress *) address)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(address)->tp_name);
        return NULL;
    }
    ns3::ApplicationPacketProbe::SetValueByPath(std::string(path, path_len), ns3::Ptr< ns3::Packet  > (packet_ptr), address2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ApplicationPacketProbe_SetValue(PyNs3ApplicationPacketProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Packet *packet;
    ns3::Packet *packet_ptr;
    PyObject *address;
    ns3::Address address2;
    const char *keywords[] = {"packet", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O", (char **) keywords, &PyNs3Packet_Type, &packet, &address)) {
        return NULL;
    }
    packet_ptr = (packet ? packet->obj : NULL);
    if (PyObject_IsInstance(address, (PyObject*) &PyNs3Address_Type)) {
        address2 = *((PyNs3Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Inet6SocketAddress_Type)) {
        address2 = *((PyNs3Inet6SocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3InetSocketAddress_Type)) {
        address2 = *((PyNs3InetSocketAddress *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv4Address_Type)) {
        address2 = *((PyNs3Ipv4Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Ipv6Address_Type)) {
        address2 = *((PyNs3Ipv6Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac16Address_Type)) {
        address2 = *((PyNs3Mac16Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac48Address_Type)) {
        address2 = *((PyNs3Mac48Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac64Address_Type)) {
        address2 = *((PyNs3Mac64Address *) address)->obj;
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3PacketSocketAddress_Type)) {
        address2 = *((PyNs3PacketSocketAddress *) address)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Inet6SocketAddress, InetSocketAddress, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address, PacketSocketAddress), not %s", Py_TYPE(address)->tp_name);
        return NULL;
    }
    self->obj->SetValue(ns3::Ptr< ns3::Packet  > (packet_ptr), address2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3ApplicationPacketProbe__copy__(PyNs3ApplicationPacketProbe *self)
{

    PyNs3ApplicationPacketProbe *py_copy;
    py_copy = PyObject_GC_New(PyNs3ApplicationPacketProbe, &PyNs3ApplicationPacketProbe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ApplicationPacketProbe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ApplicationPacketProbe_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ApplicationPacketProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3ApplicationPacketProbe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3ApplicationPacketProbe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3ApplicationPacketProbe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3ApplicationPacketProbe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ApplicationPacketProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ApplicationPacketProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ApplicationPacketProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ApplicationPacketProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ApplicationPacketProbe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ApplicationPacketProbe__tp_clear(PyNs3ApplicationPacketProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ApplicationPacketProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ApplicationPacketProbe__tp_traverse(PyNs3ApplicationPacketProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ApplicationPacketProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ApplicationPacketProbe__tp_dealloc(PyNs3ApplicationPacketProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ApplicationPacketProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ApplicationPacketProbe__tp_richcompare (PyNs3ApplicationPacketProbe *PYBINDGEN_UNUSED(self), PyNs3ApplicationPacketProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ApplicationPacketProbe_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_NE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_GT:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    } /* closes switch (opid) */
    Py_INCREF(Py_NotImplemented);
    return Py_NotImplemented;
}

PyTypeObject PyNs3ApplicationPacketProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.ApplicationPacketProbe",            /* tp_name */
    sizeof(PyNs3ApplicationPacketProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ApplicationPacketProbe__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3ApplicationPacketProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ApplicationPacketProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ApplicationPacketProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ApplicationPacketProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ApplicationPacketProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ApplicationPacketProbe__tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


/* --- containers --- */



static void
Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_clear(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt____tp_dealloc(Pystd__vector__lt___ns3__Ipv6Address___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt____tp_iter(Pystd__vector__lt___ns3__Ipv6Address___gt__ *self)
{
    Pystd__vector__lt___ns3__Ipv6Address___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter, &Pystd__vector__lt___ns3__Ipv6Address___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::Ipv6Address >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_iter(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::Ipv6Address >::iterator iter;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address((*iter));
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Ipv6Address(PyObject *value, ns3::Ipv6Address *address)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *tmp_Ipv6Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv6Address_Type, &tmp_Ipv6Address)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_Ipv6Address->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__Ipv6Address___gt__(PyObject *arg, std::vector< ns3::Ipv6Address > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__Ipv6Address___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__Ipv6Address___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ipv6Address item;
            if (!_wrap_convert_py2c__ns3__Ipv6Address(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__Ipv6Address___gt__ instance, or a list of ns3::Ipv6Address");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt____tp_init(Pystd__vector__lt___ns3__Ipv6Address___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::Ipv6Address >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__Ipv6Address___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__Ipv6Address___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__vector__lt___ns3__Ipv6Address___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__Ipv6Address___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__vector__lt___ns3__Ipv6Address___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__vector__lt___ns3__Ipv6Address___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__Ipv6Address___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__Ipv6Address___gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static void
Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_clear(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_traverse(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ *self)
{
    Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *iter = PyObject_GC_New(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter, &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::list< ns3::Ptr< ns3::Packet > >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iternext(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    PyObject *py_retval;
    std::list< ns3::Ptr< ns3::Packet > >::iterator iter;
    PyNs3Packet *py_Packet;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    if (!(const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter))))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter))));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Packet = NULL;
    } else {
        py_Packet = (PyNs3Packet *) wrapper_lookup_iter->second;
        Py_INCREF(py_Packet);
    }
    
    if (py_Packet == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter))))), &PyNs3Packet_Type);
        py_Packet = PyObject_New(PyNs3Packet, wrapper_type);
    
        py_Packet->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter)))->Ref();
        py_Packet->obj = const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter)));
        PyNs3Empty_wrapper_registry[(void *) py_Packet->obj] = (PyObject *) py_Packet;
    }
    py_retval = Py_BuildValue((char *) "N", py_Packet);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Ptr__lt___ns3__Packet___gt__(PyObject *value, ns3::Ptr< ns3::Packet > *address)
{
    PyObject *py_retval;
    PyNs3Packet *tmp_Packet;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Packet_Type, &tmp_Packet)) {
        Py_DECREF(py_retval);
        return 0;
    }
    // dangerous!
    *address = ns3::Ptr< ns3::Packet  > (tmp_Packet->obj);
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__(PyObject *arg, std::list< ns3::Ptr< ns3::Packet > > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type)) {
        *container = *((Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ptr< ns3::Packet > item;
            if (!_wrap_convert_py2c__ns3__Ptr__lt___ns3__Packet___gt__(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ instance, or a list of ns3::Ptr< ns3::Packet >");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_init(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::list< ns3::Ptr< ns3::Packet > >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static void
Pystd__list__lt___unsigned_int___gt__Iter__tp_clear(Pystd__list__lt___unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__list__lt___unsigned_int___gt__Iter__tp_traverse(Pystd__list__lt___unsigned_int___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__list__lt___unsigned_int___gt____tp_dealloc(Pystd__list__lt___unsigned_int___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__list__lt___unsigned_int___gt__Iter__tp_dealloc(Pystd__list__lt___unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__list__lt___unsigned_int___gt____tp_iter(Pystd__list__lt___unsigned_int___gt__ *self)
{
    Pystd__list__lt___unsigned_int___gt__Iter *iter = PyObject_GC_New(Pystd__list__lt___unsigned_int___gt__Iter, &Pystd__list__lt___unsigned_int___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::list< unsigned int >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__list__lt___unsigned_int___gt__Iter__tp_iter(Pystd__list__lt___unsigned_int___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__list__lt___unsigned_int___gt__Iter__tp_iternext(Pystd__list__lt___unsigned_int___gt__Iter *self)
{
    PyObject *py_retval;
    std::list< unsigned int >::iterator iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong((*iter)));
    return py_retval;
}

int _wrap_convert_py2c__unsigned_int(PyObject *value, unsigned int *address)
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &*address)) {
        Py_DECREF(py_retval);
        return 0;
    }
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__list__lt___unsigned_int___gt__(PyObject *arg, std::list< unsigned int > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__list__lt___unsigned_int___gt___Type)) {
        *container = *((Pystd__list__lt___unsigned_int___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            unsigned int item;
            if (!_wrap_convert_py2c__unsigned_int(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__list__lt___unsigned_int___gt__ instance, or a list of unsigned int");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__list__lt___unsigned_int___gt____tp_init(Pystd__list__lt___unsigned_int___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::list< unsigned int >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__list__lt___unsigned_int___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__list__lt___unsigned_int___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___unsigned_int___gt__",            /* tp_name */
    sizeof(Pystd__list__lt___unsigned_int___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___unsigned_int___gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___unsigned_int___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__list__lt___unsigned_int___gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__list__lt___unsigned_int___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___unsigned_int___gt__Iter",            /* tp_name */
    sizeof(Pystd__list__lt___unsigned_int___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___unsigned_int___gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__list__lt___unsigned_int___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__list__lt___unsigned_int___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___unsigned_int___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__list__lt___unsigned_int___gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static void
Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_clear(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_traverse(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt____tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt____tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__ *self)
{
    Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter *iter = PyObject_GC_New(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter, &Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::list< ns3::Ptr< ns3::Socket > >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_iternext(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter *self)
{
    PyObject *py_retval;
    std::list< ns3::Ptr< ns3::Socket > >::iterator iter;
    PyNs3Socket *py_Socket;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    if (!(const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter))))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter))))).name() == typeid(PyNs3Socket__PythonHelper).name())
    {
        py_Socket = reinterpret_cast< PyNs3Socket* >(reinterpret_cast< PyNs3Socket__PythonHelper* >(const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter))))->m_pyself);
        py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter)));
        Py_INCREF(py_Socket);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter))));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Socket = NULL;
        } else {
            py_Socket = (PyNs3Socket *) wrapper_lookup_iter->second;
            Py_INCREF(py_Socket);
        }
    
        if (py_Socket == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter))))), &PyNs3Socket_Type);
            py_Socket = PyObject_GC_New(PyNs3Socket, wrapper_type);
            py_Socket->inst_dict = NULL;
    
            py_Socket->inst_dict = NULL;
            py_Socket->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter)))->Ref();
            py_Socket->obj = const_cast<ns3::Socket *> (ns3::PeekPointer ((*iter)));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Socket->obj] = (PyObject *) py_Socket;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Socket);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Ptr__lt___ns3__Socket___gt__(PyObject *value, ns3::Ptr< ns3::Socket > *address)
{
    PyObject *py_retval;
    PyNs3Socket *tmp_Socket;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Socket_Type, &tmp_Socket)) {
        Py_DECREF(py_retval);
        return 0;
    }
    // dangerous!
    *address = ns3::Ptr< ns3::Socket  > (tmp_Socket->obj);
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__(PyObject *arg, std::list< ns3::Ptr< ns3::Socket > > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt___Type)) {
        *container = *((Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ptr< ns3::Socket > item;
            if (!_wrap_convert_py2c__ns3__Ptr__lt___ns3__Socket___gt__(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__ instance, or a list of ns3::Ptr< ns3::Socket >");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt____tp_init(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::list< ns3::Ptr< ns3::Socket > >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};




static void
Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_clear(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_traverse(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt____tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt____tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__ *self)
{
    Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter *iter = PyObject_GC_New(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter, &Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::list< ns3::Ptr< ns3::RadvdPrefix > >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_iternext(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter *self)
{
    PyObject *py_retval;
    std::list< ns3::Ptr< ns3::RadvdPrefix > >::iterator iter;
    PyNs3RadvdPrefix *py_RadvdPrefix;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    if (!(const_cast<ns3::RadvdPrefix *> (ns3::PeekPointer ((*iter))))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::RadvdPrefix *> (ns3::PeekPointer ((*iter))));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_RadvdPrefix = NULL;
    } else {
        py_RadvdPrefix = (PyNs3RadvdPrefix *) wrapper_lookup_iter->second;
        Py_INCREF(py_RadvdPrefix);
    }
    
    if (py_RadvdPrefix == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::RadvdPrefix *> (ns3::PeekPointer ((*iter))))), &PyNs3RadvdPrefix_Type);
        py_RadvdPrefix = PyObject_New(PyNs3RadvdPrefix, wrapper_type);
    
        py_RadvdPrefix->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::RadvdPrefix *> (ns3::PeekPointer ((*iter)))->Ref();
        py_RadvdPrefix->obj = const_cast<ns3::RadvdPrefix *> (ns3::PeekPointer ((*iter)));
        PyNs3Empty_wrapper_registry[(void *) py_RadvdPrefix->obj] = (PyObject *) py_RadvdPrefix;
    }
    py_retval = Py_BuildValue((char *) "N", py_RadvdPrefix);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Ptr__lt___ns3__RadvdPrefix___gt__(PyObject *value, ns3::Ptr< ns3::RadvdPrefix > *address)
{
    PyObject *py_retval;
    PyNs3RadvdPrefix *tmp_RadvdPrefix;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3RadvdPrefix_Type, &tmp_RadvdPrefix)) {
        Py_DECREF(py_retval);
        return 0;
    }
    // dangerous!
    *address = ns3::Ptr< ns3::RadvdPrefix  > (tmp_RadvdPrefix->obj);
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__(PyObject *arg, std::list< ns3::Ptr< ns3::RadvdPrefix > > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt___Type)) {
        *container = *((Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ptr< ns3::RadvdPrefix > item;
            if (!_wrap_convert_py2c__ns3__Ptr__lt___ns3__RadvdPrefix___gt__(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__ instance, or a list of ns3::Ptr< ns3::RadvdPrefix >");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt____tp_init(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::list< ns3::Ptr< ns3::RadvdPrefix > >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt____tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt____tp_init,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "applications.Std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_dealloc,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)NULL,       /* tp_getattr */
    (setattrfunc)NULL,       /* tp_setattr */
    (cmpfunc)NULL,           /* tp_compare */
    (reprfunc)NULL,             /* tp_repr */
    (PyNumberMethods*)NULL,     /* tp_as_number */
    (PySequenceMethods*)NULL, /* tp_as_sequence */
    (PyMappingMethods*)NULL,   /* tp_as_mapping */
    (hashfunc)NULL,             /* tp_hash */
    (ternaryfunc)NULL,          /* tp_call */
    (reprfunc)NULL,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter__tp_iternext,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)NULL,             /* tp_init */
    (allocfunc)PyType_GenericAlloc,           /* tp_alloc */
    (newfunc)PyType_GenericNew,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)NULL,             /* tp_is_gc */
    NULL,                              /* tp_bases */
    NULL,                              /* tp_mro */
    NULL,                              /* tp_cache */
    NULL,                              /* tp_subclasses */
    NULL,                              /* tp_weaklist */
    (destructor) NULL                  /* tp_del */
};


/* --- enumerations --- */













































#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef applications_moduledef = {
    PyModuleDef_HEAD_INIT,
    "applications",
    NULL,
    -1,
    applications_functions,
};
#endif


#if PY_VERSION_HEX >= 0x03000000
    #define MOD_ERROR NULL
    #define MOD_INIT(name) PyObject* PyInit_##name(void)
    #define MOD_RETURN(val) val
#else
    #define MOD_ERROR
    #define MOD_INIT(name) void init##name(void)
    #define MOD_RETURN(val)
#endif
#if defined(__cplusplus)
extern "C"
#endif
#if defined(__GNUC__) && __GNUC__ >= 4
__attribute__ ((visibility("default")))
#endif


MOD_INIT(applications)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&applications_moduledef);
    #else
    m = Py_InitModule3((char *) "applications", applications_functions, NULL);
    #endif
    if (m == NULL) {
        return MOD_ERROR;
    }
    PyModule_AddIntConstant(m, (char *) "STD_IOS_IN", std::ios::in);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_OUT", std::ios::out);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_ATE", std::ios::ate);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_APP", std::ios::app);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_TRUNC", std::ios::trunc);
    PyModule_AddIntConstant(m, (char *) "STD_IOS_BINARY", std::ios::binary);
    /* Import the 'ns3::Address' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Address_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Address");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Address_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Address_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Address_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ApplicationContainer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ApplicationContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ApplicationContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ApplicationContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ApplicationContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ApplicationContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AsciiFile' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AsciiFile_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AsciiFile");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AsciiFile_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AsciiFile_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AsciiFile_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AsciiTraceHelper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AsciiTraceHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AsciiTraceHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AsciiTraceHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AsciiTraceHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AsciiTraceHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AsciiTraceHelperForDevice' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AsciiTraceHelperForDevice_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AsciiTraceHelperForDevice");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AsciiTraceHelperForDevice_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AsciiTraceHelperForDevice_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AsciiTraceHelperForDevice_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AttributeConstructionList' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AttributeConstructionList_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AttributeConstructionList");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AttributeConstructionList_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AttributeConstructionList_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AttributeConstructionList_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AttributeConstructionList::Item' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AttributeConstructionListItem_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Item");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AttributeConstructionListItem_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AttributeConstructionListItem_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AttributeConstructionListItem_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Average< double >' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Average__Double_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Average__Double");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Average__Double_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Average__Double_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Average__Double_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Buffer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Buffer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Buffer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Buffer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Buffer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Buffer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Buffer::Iterator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3BufferIterator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Iterator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3BufferIterator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3BufferIterator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3BufferIterator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ByteTagIterator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ByteTagIterator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ByteTagIterator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ByteTagIterator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ByteTagIterator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ByteTagIterator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ByteTagIterator::Item' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ByteTagIteratorItem_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Item");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ByteTagIteratorItem_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ByteTagIteratorItem_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ByteTagIteratorItem_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ByteTagList' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ByteTagList_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ByteTagList");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ByteTagList_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ByteTagList_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ByteTagList_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ByteTagList::Iterator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ByteTagListIterator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Iterator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ByteTagListIterator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ByteTagListIterator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ByteTagListIterator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ByteTagList::Iterator::Item' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ByteTagListIteratorItem_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Item");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ByteTagListIteratorItem_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ByteTagListIteratorItem_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ByteTagListIteratorItem_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::CallbackBase' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3CallbackBase_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "CallbackBase");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3CallbackBase_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3CallbackBase_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3CallbackBase_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ChannelList' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ChannelList_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ChannelList");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ChannelList_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ChannelList_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ChannelList_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::DataOutputCallback' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataOutputCallback_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataOutputCallback");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3DataOutputCallback_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3DataOutputCallback_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3DataOutputCallback_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::DataRate' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataRate_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataRate");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3DataRate_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3DataRate_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3DataRate_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::DelayJitterEstimation' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DelayJitterEstimation_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DelayJitterEstimation");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3DelayJitterEstimation_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3DelayJitterEstimation_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3DelayJitterEstimation_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::EventId' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EventId_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EventId");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3EventId_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3EventId_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3EventId_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Hasher' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Hasher_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Hasher");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Hasher_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Hasher_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Hasher_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Inet6SocketAddress' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Inet6SocketAddress_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Inet6SocketAddress");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Inet6SocketAddress_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Inet6SocketAddress_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Inet6SocketAddress_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::InetSocketAddress' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3InetSocketAddress_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "InetSocketAddress");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3InetSocketAddress_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3InetSocketAddress_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3InetSocketAddress_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv4Address' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4Address_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4Address");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv4Address_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv4Address_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv4Address_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv4Mask' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4Mask_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4Mask");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv4Mask_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv4Mask_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv4Mask_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv6Address' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6Address_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6Address");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv6Address_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv6Address_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv6Address_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv6Prefix' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6Prefix_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6Prefix");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv6Prefix_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv6Prefix_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv6Prefix_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Mac16Address' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac16Address_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac16Address");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Mac16Address_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Mac16Address_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Mac16Address_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Mac48Address' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac48Address_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac48Address");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Mac48Address_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Mac48Address_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Mac48Address_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Mac64Address' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac64Address_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac64Address");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Mac64Address_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Mac64Address_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Mac64Address_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::NetDeviceContainer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NetDeviceContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NetDeviceContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3NetDeviceContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3NetDeviceContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3NetDeviceContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::NodeContainer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NodeContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NodeContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3NodeContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3NodeContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3NodeContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::NodeList' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NodeList_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NodeList");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3NodeList_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3NodeList_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3NodeList_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::NonCopyable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NonCopyable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NonCopyable");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3NonCopyable_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3NonCopyable_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3NonCopyable_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ObjectBase' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectBase_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ObjectBase");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ObjectBase_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ObjectBase_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ObjectBase_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ObjectDeleter' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectDeleter_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ObjectDeleter");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ObjectDeleter_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ObjectDeleter_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ObjectDeleter_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::ObjectFactory' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectFactory_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ObjectFactory");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ObjectFactory_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ObjectFactory_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ObjectFactory_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketMetadata' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketMetadata_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketMetadata");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketMetadata_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketMetadata_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketMetadata_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketMetadata::Item' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketMetadataItem_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Item");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketMetadataItem_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketMetadataItem_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketMetadataItem_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketMetadata::ItemIterator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketMetadataItemIterator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ItemIterator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketMetadataItemIterator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketMetadataItemIterator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketMetadataItemIterator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketSocketAddress' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocketAddress_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocketAddress");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketSocketAddress_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketSocketAddress_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketSocketAddress_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketSocketHelper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocketHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocketHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketSocketHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketSocketHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketSocketHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketTagIterator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketTagIterator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketTagIterator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketTagIterator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketTagIterator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketTagIterator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketTagIterator::Item' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketTagIteratorItem_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Item");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketTagIteratorItem_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketTagIteratorItem_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketTagIteratorItem_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketTagList' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketTagList_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketTagList");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketTagList_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketTagList_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketTagList_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketTagList::TagData' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketTagListTagData_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TagData");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PacketTagListTagData_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PacketTagListTagData_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PacketTagListTagData_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PbbAddressTlvBlock' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbAddressTlvBlock_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbAddressTlvBlock");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PbbAddressTlvBlock_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PbbAddressTlvBlock_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PbbAddressTlvBlock_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PbbTlvBlock' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbTlvBlock_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbTlvBlock");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PbbTlvBlock_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PbbTlvBlock_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PbbTlvBlock_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PcapFile' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapFile_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapFile");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PcapFile_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PcapFile_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PcapFile_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PcapHelper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PcapHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PcapHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PcapHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PcapHelperForDevice' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapHelperForDevice_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapHelperForDevice");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PcapHelperForDevice_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PcapHelperForDevice_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PcapHelperForDevice_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleNetDeviceHelper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleNetDeviceHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleNetDeviceHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleNetDeviceHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3SimpleNetDeviceHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3SimpleNetDeviceHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::Object, ns3::ObjectBase, ns3::ObjectDeleter >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::Object, ns3::ObjectBase, ns3::ObjectDeleter >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Simulator' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Simulator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Simulator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Simulator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Simulator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Simulator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::StatisticalSummary' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3StatisticalSummary_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "StatisticalSummary");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3StatisticalSummary_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3StatisticalSummary_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3StatisticalSummary_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SystemWallClockMs' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SystemWallClockMs_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SystemWallClockMs");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SystemWallClockMs_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3SystemWallClockMs_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3SystemWallClockMs_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Tag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Tag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Tag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::TagBuffer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TagBuffer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TagBuffer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TagBuffer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TagBuffer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TagBuffer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TimeWithUnit' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TimeWithUnit_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TimeWithUnit");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TimeWithUnit_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TimeWithUnit_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TimeWithUnit_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TypeId' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TypeId_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TypeId");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TypeId_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TypeId_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TypeId_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TypeId::AttributeInformation' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TypeIdAttributeInformation_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AttributeInformation");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TypeIdAttributeInformation_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TypeIdAttributeInformation_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TypeIdAttributeInformation_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TypeId::TraceSourceInformation' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TypeIdTraceSourceInformation_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TraceSourceInformation");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TypeIdTraceSourceInformation_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TypeIdTraceSourceInformation_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TypeIdTraceSourceInformation_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::empty' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Empty_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "empty");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Empty_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Empty_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Empty_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::int64x64_t' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Int64x64_t_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "int64x64_t");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Int64x64_t_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Int64x64_t_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Int64x64_t_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Chunk' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Chunk_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Chunk");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DeviceNameTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DeviceNameTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DeviceNameTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::FlowIdTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3FlowIdTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "FlowIdTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Header' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Header_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Header");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::LlcSnapHeader' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3LlcSnapHeader_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "LlcSnapHeader");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Object' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Object_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Object");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Object::AggregateIterator' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectAggregateIterator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AggregateIterator");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ObjectAggregateIterator_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ObjectAggregateIterator_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ObjectAggregateIterator_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PacketBurst' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketBurst_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketBurst");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketSocketTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocketTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocketTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PcapFileWrapper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapFileWrapper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapFileWrapper");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Queue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Queue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Queue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::RadiotapHeader' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3RadiotapHeader_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "RadiotapHeader");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::RandomVariableStream' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3RandomVariableStream_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "RandomVariableStream");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::RedQueue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3RedQueue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "RedQueue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::RedQueue::Stats' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3RedQueueStats_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Stats");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3RedQueueStats_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3RedQueueStats_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3RedQueueStats_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SequentialRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SequentialRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SequentialRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SimpleRefCount< ns3::AttributeAccessor, ns3::empty, ns3::DefaultDeleter<ns3::AttributeAccessor> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::AttributeAccessor, ns3::empty, ns3::DefaultDeleter<ns3::AttributeAccessor> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::AttributeChecker, ns3::empty, ns3::DefaultDeleter<ns3::AttributeChecker> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::AttributeChecker, ns3::empty, ns3::DefaultDeleter<ns3::AttributeChecker> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::AttributeValue, ns3::empty, ns3::DefaultDeleter<ns3::AttributeValue> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::AttributeValue, ns3::empty, ns3::DefaultDeleter<ns3::AttributeValue> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::CallbackImplBase, ns3::empty, ns3::DefaultDeleter<ns3::CallbackImplBase> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::CallbackImplBase, ns3::empty, ns3::DefaultDeleter<ns3::CallbackImplBase> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::EventImpl, ns3::empty, ns3::DefaultDeleter<ns3::EventImpl> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::EventImpl, ns3::empty, ns3::DefaultDeleter<ns3::EventImpl> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::Hash::Implementation, ns3::empty, ns3::DefaultDeleter<ns3::Hash::Implementation> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::Hash::Implementation, ns3::empty, ns3::DefaultDeleter<ns3::Hash::Implementation> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::NixVector, ns3::empty, ns3::DefaultDeleter<ns3::NixVector> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::NixVector, ns3::empty, ns3::DefaultDeleter<ns3::NixVector> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::OutputStreamWrapper, ns3::empty, ns3::DefaultDeleter<ns3::OutputStreamWrapper> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::OutputStreamWrapper, ns3::empty, ns3::DefaultDeleter<ns3::OutputStreamWrapper> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::Packet, ns3::empty, ns3::DefaultDeleter<ns3::Packet> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::Packet, ns3::empty, ns3::DefaultDeleter<ns3::Packet> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::PbbAddressBlock, ns3::empty, ns3::DefaultDeleter<ns3::PbbAddressBlock> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::PbbAddressBlock, ns3::empty, ns3::DefaultDeleter<ns3::PbbAddressBlock> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3PbbAddressBlock_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbAddressBlock__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::PbbMessage, ns3::empty, ns3::DefaultDeleter<ns3::PbbMessage> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::PbbMessage, ns3::empty, ns3::DefaultDeleter<ns3::PbbMessage> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3PbbMessage_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbMessage__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::PbbPacket, ns3::Header, ns3::DefaultDeleter<ns3::PbbPacket> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::PbbPacket, ns3::Header, ns3::DefaultDeleter<ns3::PbbPacket> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3PbbPacket_Ns3Header_Ns3DefaultDeleter__lt__ns3PbbPacket__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::PbbTlv, ns3::empty, ns3::DefaultDeleter<ns3::PbbTlv> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::PbbTlv, ns3::empty, ns3::DefaultDeleter<ns3::PbbTlv> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3PbbTlv_Ns3Empty_Ns3DefaultDeleter__lt__ns3PbbTlv__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::TraceSourceAccessor, ns3::empty, ns3::DefaultDeleter<ns3::TraceSourceAccessor> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::TraceSourceAccessor, ns3::empty, ns3::DefaultDeleter<ns3::TraceSourceAccessor> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Socket' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Socket_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Socket");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketAddressTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketAddressTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketAddressTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketFactory' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketFactory_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketFactory");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketIpTosTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketIpTosTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketIpTosTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketIpTtlTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketIpTtlTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketIpTtlTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketIpv6HopLimitTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketIpv6HopLimitTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketIpv6HopLimitTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketIpv6TclassTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketIpv6TclassTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketIpv6TclassTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SocketSetDontFragmentTag' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SocketSetDontFragmentTag_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SocketSetDontFragmentTag");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Time' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Time_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Time");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Time_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Time_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Time_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TraceSourceAccessor' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TraceSourceAccessor_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TraceSourceAccessor");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Trailer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Trailer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Trailer");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::TriangularRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TriangularRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TriangularRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::UniformRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3UniformRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "UniformRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::WeibullRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3WeibullRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "WeibullRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ZetaRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ZetaRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ZetaRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ZipfRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ZipfRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ZipfRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Application' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Application_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Application");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::AttributeAccessor' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AttributeAccessor_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AttributeAccessor");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::AttributeChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AttributeChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AttributeChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::AttributeValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AttributeValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AttributeValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::BooleanChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3BooleanChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "BooleanChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::BooleanValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3BooleanValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "BooleanValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::CallbackChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3CallbackChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "CallbackChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::CallbackImplBase' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3CallbackImplBase_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "CallbackImplBase");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::CallbackValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3CallbackValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "CallbackValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Channel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Channel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Channel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ConstantRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ConstantRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ConstantRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DataCalculator' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataCalculator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataCalculator");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DataCollectionObject' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataCollectionObject_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataCollectionObject");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DataOutputInterface' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataOutputInterface_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataOutputInterface");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DataRateChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataRateChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataRateChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DataRateValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DataRateValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DataRateValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DeterministicRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DeterministicRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DeterministicRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DoubleValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DoubleValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DoubleValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::DropTailQueue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DropTailQueue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DropTailQueue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EmpiricalRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EmpiricalRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EmpiricalRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EmptyAttributeValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EmptyAttributeValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EmptyAttributeValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EnumChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EnumChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EnumChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EnumValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EnumValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EnumValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ErlangRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ErlangRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ErlangRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ErrorModel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ErrorModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ErrorModel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EthernetHeader' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EthernetHeader_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EthernetHeader");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EthernetTrailer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EthernetTrailer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EthernetTrailer");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::EventImpl' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EventImpl_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EventImpl");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ExponentialRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ExponentialRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ExponentialRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::GammaRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3GammaRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "GammaRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::IntegerValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntegerValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntegerValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4AddressChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4AddressChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4AddressChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4AddressValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4AddressValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4AddressValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4MaskChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4MaskChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4MaskChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4MaskValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4MaskValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4MaskValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6AddressChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6AddressChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6AddressChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6AddressValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6AddressValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6AddressValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6PrefixChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6PrefixChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6PrefixChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6PrefixValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6PrefixValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6PrefixValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ListErrorModel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ListErrorModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ListErrorModel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::LogNormalRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3LogNormalRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "LogNormalRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Mac16AddressChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac16AddressChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac16AddressChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Mac16AddressValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac16AddressValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac16AddressValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Mac48AddressChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac48AddressChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac48AddressChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Mac48AddressValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac48AddressValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac48AddressValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Mac64AddressChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac64AddressChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac64AddressChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Mac64AddressValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Mac64AddressValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Mac64AddressValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::MinMaxAvgTotalCalculator< double >' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3MinMaxAvgTotalCalculator__Double_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "MinMaxAvgTotalCalculator__Double");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::MinMaxAvgTotalCalculator< unsigned int >' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3MinMaxAvgTotalCalculator__Unsigned_int_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "MinMaxAvgTotalCalculator__Unsigned_int");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::NetDevice' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NetDevice_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NetDevice");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::NixVector' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NixVector_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NixVector");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Node' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Node_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Node");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::NormalRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NormalRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NormalRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ObjectFactoryChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectFactoryChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ObjectFactoryChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ObjectFactoryValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ObjectFactoryValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ObjectFactoryValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::OutputStreamWrapper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3OutputStreamWrapper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "OutputStreamWrapper");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Packet' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Packet_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Packet");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketSizeMinMaxAvgTotalCalculator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSizeMinMaxAvgTotalCalculator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSizeMinMaxAvgTotalCalculator");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketSocket' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocket_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocket");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketSocketClient' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocketClient_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocketClient");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketSocketFactory' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocketFactory_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocketFactory");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketSocketServer' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketSocketServer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketSocketServer");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ParetoRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ParetoRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ParetoRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbAddressBlock' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbAddressBlock_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbAddressBlock");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbAddressBlockIpv4' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbAddressBlockIpv4_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbAddressBlockIpv4");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbAddressBlockIpv6' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbAddressBlockIpv6_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbAddressBlockIpv6");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbMessage' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbMessage_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbMessage");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbMessageIpv4' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbMessageIpv4_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbMessageIpv4");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbMessageIpv6' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbMessageIpv6_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbMessageIpv6");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbPacket' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbPacket_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbPacket");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbTlv' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbTlv_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbTlv");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Probe' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Probe_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Probe");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::RateErrorModel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3RateErrorModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "RateErrorModel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ReceiveListErrorModel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ReceiveListErrorModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ReceiveListErrorModel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SimpleChannel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleChannel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleChannel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SimpleNetDevice' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleNetDevice_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleNetDevice");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::TimeValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TimeValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TimeValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::TypeIdChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TypeIdChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TypeIdChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::TypeIdValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TypeIdValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TypeIdValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::UintegerValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3UintegerValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "UintegerValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::AddressChecker' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AddressChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AddressChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::AddressValue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AddressValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AddressValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::BurstErrorModel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3BurstErrorModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "BurstErrorModel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::CounterCalculator< unsigned int >' class from module 'ns.stats' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.stats");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3CounterCalculator__Unsigned_int_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "CounterCalculator__Unsigned_int");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketCounterCalculator' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketCounterCalculator_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketCounterCalculator");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PacketProbe' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PacketProbe_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PacketProbe");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::PbbAddressTlv' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PbbAddressTlv_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PbbAddressTlv");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    PyModule_AddObject(m, (char *) "_PyNs3BulkSendHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3BulkSendHelper_wrapper_registry, NULL));
    /* Register the 'ns3::BulkSendHelper' class */
    if (PyType_Ready(&PyNs3BulkSendHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BulkSendHelper", (PyObject *) &PyNs3BulkSendHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OnOffHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OnOffHelper_wrapper_registry, NULL));
    /* Register the 'ns3::OnOffHelper' class */
    if (PyType_Ready(&PyNs3OnOffHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "OnOffHelper", (PyObject *) &PyNs3OnOffHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3PacketLossCounter_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3PacketLossCounter_wrapper_registry, NULL));
    /* Register the 'ns3::PacketLossCounter' class */
    if (PyType_Ready(&PyNs3PacketLossCounter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PacketLossCounter", (PyObject *) &PyNs3PacketLossCounter_Type);
    PyModule_AddObject(m, (char *) "_PyNs3PacketSinkHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3PacketSinkHelper_wrapper_registry, NULL));
    /* Register the 'ns3::PacketSinkHelper' class */
    if (PyType_Ready(&PyNs3PacketSinkHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PacketSinkHelper", (PyObject *) &PyNs3PacketSinkHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Ping6Helper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Ping6Helper_wrapper_registry, NULL));
    /* Register the 'ns3::Ping6Helper' class */
    if (PyType_Ready(&PyNs3Ping6Helper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ping6Helper", (PyObject *) &PyNs3Ping6Helper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3RadvdHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3RadvdHelper_wrapper_registry, NULL));
    /* Register the 'ns3::RadvdHelper' class */
    if (PyType_Ready(&PyNs3RadvdHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RadvdHelper", (PyObject *) &PyNs3RadvdHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3UdpClientHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3UdpClientHelper_wrapper_registry, NULL));
    /* Register the 'ns3::UdpClientHelper' class */
    if (PyType_Ready(&PyNs3UdpClientHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpClientHelper", (PyObject *) &PyNs3UdpClientHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3UdpEchoClientHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3UdpEchoClientHelper_wrapper_registry, NULL));
    /* Register the 'ns3::UdpEchoClientHelper' class */
    if (PyType_Ready(&PyNs3UdpEchoClientHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpEchoClientHelper", (PyObject *) &PyNs3UdpEchoClientHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3UdpEchoServerHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3UdpEchoServerHelper_wrapper_registry, NULL));
    /* Register the 'ns3::UdpEchoServerHelper' class */
    if (PyType_Ready(&PyNs3UdpEchoServerHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpEchoServerHelper", (PyObject *) &PyNs3UdpEchoServerHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3UdpServerHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3UdpServerHelper_wrapper_registry, NULL));
    /* Register the 'ns3::UdpServerHelper' class */
    if (PyType_Ready(&PyNs3UdpServerHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpServerHelper", (PyObject *) &PyNs3UdpServerHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3UdpTraceClientHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3UdpTraceClientHelper_wrapper_registry, NULL));
    /* Register the 'ns3::UdpTraceClientHelper' class */
    if (PyType_Ready(&PyNs3UdpTraceClientHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpTraceClientHelper", (PyObject *) &PyNs3UdpTraceClientHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3V4PingHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3V4PingHelper_wrapper_registry, NULL));
    /* Register the 'ns3::V4PingHelper' class */
    if (PyType_Ready(&PyNs3V4PingHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "V4PingHelper", (PyObject *) &PyNs3V4PingHelper_Type);
    /* Register the 'ns3::SeqTsHeader' class */
    PyNs3SeqTsHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SeqTsHeader_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SeqTsHeader", (PyObject *) &PyNs3SeqTsHeader_Type);
    PyModule_AddObject(m, (char *) "_PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____typeid_map", PyCObject_FromVoidPtr(&PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____typeid_map, NULL));
    PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____typeid_map.register_wrapper(typeid(ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> >), &PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type);
    /* Register the 'ns3::SimpleRefCount< ns3::RadvdInterface, ns3::empty, ns3::DefaultDeleter<ns3::RadvdInterface> >' class */
    PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type.tp_base = &PyNs3Empty_Type;
    if (PyType_Ready(&PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt__", (PyObject *) &PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type);
    PyModule_AddObject(m, (char *) "_PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____typeid_map", PyCObject_FromVoidPtr(&PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____typeid_map, NULL));
    PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____typeid_map.register_wrapper(typeid(ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> >), &PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type);
    /* Register the 'ns3::SimpleRefCount< ns3::RadvdPrefix, ns3::empty, ns3::DefaultDeleter<ns3::RadvdPrefix> >' class */
    PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type.tp_base = &PyNs3Empty_Type;
    if (PyType_Ready(&PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt__", (PyObject *) &PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::BulkSendApplication), &PyNs3BulkSendApplication_Type);
    /* Register the 'ns3::BulkSendApplication' class */
    PyNs3BulkSendApplication_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3BulkSendApplication_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BulkSendApplication", (PyObject *) &PyNs3BulkSendApplication_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::OnOffApplication), &PyNs3OnOffApplication_Type);
    /* Register the 'ns3::OnOffApplication' class */
    PyNs3OnOffApplication_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3OnOffApplication_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "OnOffApplication", (PyObject *) &PyNs3OnOffApplication_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::PacketSink), &PyNs3PacketSink_Type);
    /* Register the 'ns3::PacketSink' class */
    PyNs3PacketSink_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3PacketSink_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PacketSink", (PyObject *) &PyNs3PacketSink_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Ping6), &PyNs3Ping6_Type);
    /* Register the 'ns3::Ping6' class */
    PyNs3Ping6_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3Ping6_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ping6", (PyObject *) &PyNs3Ping6_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Radvd), &PyNs3Radvd_Type);
    /* Register the 'ns3::Radvd' class */
    
    PyNs3RadvdMeta_Type.tp_base = Py_TYPE(&PyNs3Application_Type);
    /* Some fields need to be manually inheritted from the parent metaclass */
    PyNs3RadvdMeta_Type.tp_traverse = Py_TYPE(&PyNs3Application_Type)->tp_traverse;
    PyNs3RadvdMeta_Type.tp_clear = Py_TYPE(&PyNs3Application_Type)->tp_clear;
    PyNs3RadvdMeta_Type.tp_is_gc = Py_TYPE(&PyNs3Application_Type)->tp_is_gc;
    /* PyType tp_setattro is too restrictive */
    PyNs3RadvdMeta_Type.tp_setattro = PyObject_GenericSetAttr;
    PyType_Ready(&PyNs3RadvdMeta_Type);
    
    PyNs3Radvd_Type.tp_base = &PyNs3Application_Type;
    Py_TYPE(&PyNs3Radvd_Type) = &PyNs3RadvdMeta_Type;
    if (PyType_Ready(&PyNs3Radvd_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Radvd", (PyObject *) &PyNs3Radvd_Type);
    PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt____typeid_map.register_wrapper(typeid(ns3::RadvdInterface), &PyNs3RadvdInterface_Type);
    /* Register the 'ns3::RadvdInterface' class */
    PyNs3RadvdInterface_Type.tp_base = &PyNs3SimpleRefCount__Ns3RadvdInterface_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdInterface__gt___Type;
    if (PyType_Ready(&PyNs3RadvdInterface_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RadvdInterface", (PyObject *) &PyNs3RadvdInterface_Type);
    PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt____typeid_map.register_wrapper(typeid(ns3::RadvdPrefix), &PyNs3RadvdPrefix_Type);
    /* Register the 'ns3::RadvdPrefix' class */
    PyNs3RadvdPrefix_Type.tp_base = &PyNs3SimpleRefCount__Ns3RadvdPrefix_Ns3Empty_Ns3DefaultDeleter__lt__ns3RadvdPrefix__gt___Type;
    if (PyType_Ready(&PyNs3RadvdPrefix_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RadvdPrefix", (PyObject *) &PyNs3RadvdPrefix_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::UdpClient), &PyNs3UdpClient_Type);
    /* Register the 'ns3::UdpClient' class */
    PyNs3UdpClient_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3UdpClient_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpClient", (PyObject *) &PyNs3UdpClient_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::UdpEchoClient), &PyNs3UdpEchoClient_Type);
    /* Register the 'ns3::UdpEchoClient' class */
    PyNs3UdpEchoClient_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3UdpEchoClient_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpEchoClient", (PyObject *) &PyNs3UdpEchoClient_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::UdpEchoServer), &PyNs3UdpEchoServer_Type);
    /* Register the 'ns3::UdpEchoServer' class */
    PyNs3UdpEchoServer_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3UdpEchoServer_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpEchoServer", (PyObject *) &PyNs3UdpEchoServer_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::UdpServer), &PyNs3UdpServer_Type);
    /* Register the 'ns3::UdpServer' class */
    PyNs3UdpServer_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3UdpServer_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpServer", (PyObject *) &PyNs3UdpServer_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::UdpTraceClient), &PyNs3UdpTraceClient_Type);
    /* Register the 'ns3::UdpTraceClient' class */
    PyNs3UdpTraceClient_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3UdpTraceClient_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UdpTraceClient", (PyObject *) &PyNs3UdpTraceClient_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::V4Ping), &PyNs3V4Ping_Type);
    /* Register the 'ns3::V4Ping' class */
    PyNs3V4Ping_Type.tp_base = &PyNs3Application_Type;
    if (PyType_Ready(&PyNs3V4Ping_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "V4Ping", (PyObject *) &PyNs3V4Ping_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ApplicationPacketProbe), &PyNs3ApplicationPacketProbe_Type);
    /* Register the 'ns3::ApplicationPacketProbe' class */
    PyNs3ApplicationPacketProbe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3ApplicationPacketProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ApplicationPacketProbe", (PyObject *) &PyNs3ApplicationPacketProbe_Type);
    /* Register the 'std::vector< ns3::Ipv6Address >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ipv6Address___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ipv6Address___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ipv6Address___gt__", (PyObject *) &Pystd__vector__lt___ns3__Ipv6Address___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ipv6Address___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__Ipv6Address___gt__Iter_Type);
    /* Register the 'std::list< ns3::Ptr< ns3::Packet > >' class */
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type);
    /* Register the 'std::list< unsigned int >' class */
    if (PyType_Ready(&Pystd__list__lt___unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___unsigned_int___gt__", (PyObject *) &Pystd__list__lt___unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___unsigned_int___gt__Iter", (PyObject *) &Pystd__list__lt___unsigned_int___gt__Iter_Type);
    /* Register the 'std::list< ns3::Ptr< ns3::Socket > >' class */
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__Socket___gt_____gt__Iter_Type);
    /* Register the 'std::list< ns3::Ptr< ns3::RadvdPrefix > >' class */
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__RadvdPrefix___gt_____gt__Iter_Type);
    submodule = initapplications_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initapplications_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initapplications_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    submodule = initapplications_addressUtils();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "addressUtils", submodule);
    submodule = initapplications_internal();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "internal", submodule);
    return MOD_RETURN(m);
}
