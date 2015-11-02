#include "ns3module.h"
static PyMethodDef point_to_point_layout_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef point_to_point_layout_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "point_to_point_layout.FatalImpl",
    NULL,
    -1,
    point_to_point_layout_FatalImpl_functions,
};
#endif

static PyObject *
initpoint_to_point_layout_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&point_to_point_layout_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "point_to_point_layout.FatalImpl", point_to_point_layout_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef point_to_point_layout_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef point_to_point_layout_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "point_to_point_layout.Hash.Function",
    NULL,
    -1,
    point_to_point_layout_Hash_Function_functions,
};
#endif

static PyObject *
initpoint_to_point_layout_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&point_to_point_layout_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "point_to_point_layout.Hash.Function", point_to_point_layout_Hash_Function_functions, NULL);
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
static PyMethodDef point_to_point_layout_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef point_to_point_layout_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "point_to_point_layout.Hash",
    NULL,
    -1,
    point_to_point_layout_Hash_functions,
};
#endif

static PyObject *
initpoint_to_point_layout_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&point_to_point_layout_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "point_to_point_layout.Hash", point_to_point_layout_Hash_functions, NULL);
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
    submodule = initpoint_to_point_layout_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef point_to_point_layout_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef point_to_point_layout_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "point_to_point_layout.TracedValueCallback",
    NULL,
    -1,
    point_to_point_layout_TracedValueCallback_functions,
};
#endif

static PyObject *
initpoint_to_point_layout_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&point_to_point_layout_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "point_to_point_layout.TracedValueCallback", point_to_point_layout_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef point_to_point_layout_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3Address_Type;
std::map<void*, PyObject*> *_PyNs3Address_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelper_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelper_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelperForDevice_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelperForDevice_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelperForIpv4_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelperForIpv4_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelperForIpv6_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelperForIpv6_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionList_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionList_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionListItem_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionListItem_wrapper_registry;


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


PyTypeObject *_PyNs3Ipv4AddressHelper_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4AddressHelper_wrapper_registry;


PyTypeObject *_PyNs3Ipv4InterfaceAddress_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4InterfaceAddress_wrapper_registry;


PyTypeObject *_PyNs3Ipv4InterfaceContainer_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4InterfaceContainer_wrapper_registry;


PyTypeObject *_PyNs3Ipv4Mask_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4Mask_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Address_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Address_wrapper_registry;


PyTypeObject *_PyNs3Ipv6AddressHelper_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6AddressHelper_wrapper_registry;


PyTypeObject *_PyNs3Ipv6InterfaceAddress_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6InterfaceAddress_wrapper_registry;


PyTypeObject *_PyNs3Ipv6InterfaceContainer_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6InterfaceContainer_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Prefix_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Prefix_wrapper_registry;


PyTypeObject *_PyNs3Mac48Address_Type;
std::map<void*, PyObject*> *_PyNs3Mac48Address_wrapper_registry;


PyTypeObject *_PyNs3NetDeviceContainer_Type;
std::map<void*, PyObject*> *_PyNs3NetDeviceContainer_wrapper_registry;


PyTypeObject *_PyNs3NodeContainer_Type;
std::map<void*, PyObject*> *_PyNs3NodeContainer_wrapper_registry;


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


PyTypeObject *_PyNs3PacketTagIterator_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagIterator_wrapper_registry;


PyTypeObject *_PyNs3PacketTagIteratorItem_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagIteratorItem_wrapper_registry;


PyTypeObject *_PyNs3PacketTagList_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagList_wrapper_registry;


PyTypeObject *_PyNs3PacketTagListTagData_Type;
std::map<void*, PyObject*> *_PyNs3PacketTagListTagData_wrapper_registry;


PyTypeObject *_PyNs3PcapFile_Type;
std::map<void*, PyObject*> *_PyNs3PcapFile_wrapper_registry;


PyTypeObject *_PyNs3PcapHelper_Type;
std::map<void*, PyObject*> *_PyNs3PcapHelper_wrapper_registry;


PyTypeObject *_PyNs3PcapHelperForDevice_Type;
std::map<void*, PyObject*> *_PyNs3PcapHelperForDevice_wrapper_registry;


PyTypeObject *_PyNs3PcapHelperForIpv4_Type;
std::map<void*, PyObject*> *_PyNs3PcapHelperForIpv4_wrapper_registry;


PyTypeObject *_PyNs3PcapHelperForIpv6_Type;
std::map<void*, PyObject*> *_PyNs3PcapHelperForIpv6_wrapper_registry;


PyTypeObject *_PyNs3PointToPointHelper_Type;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map;


PyTypeObject *_PyNs3Simulator_Type;
std::map<void*, PyObject*> *_PyNs3Simulator_wrapper_registry;


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


PyTypeObject *_PyNs3Header_Type;


PyTypeObject *_PyNs3InternetStackHelper_Type;


PyTypeObject *_PyNs3Ipv4Header_Type;


PyTypeObject *_PyNs3Ipv6Header_Type;


PyTypeObject *_PyNs3Object_Type;


PyTypeObject *_PyNs3ObjectAggregateIterator_Type;
std::map<void*, PyObject*> *_PyNs3ObjectAggregateIterator_wrapper_registry;


PyTypeObject *_PyNs3PcapFileWrapper_Type;


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


PyTypeObject *_PyNs3SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3Socket_Type;


PyTypeObject *_PyNs3SocketAddressTag_Type;


PyTypeObject *_PyNs3SocketIpTosTag_Type;


PyTypeObject *_PyNs3SocketIpTtlTag_Type;


PyTypeObject *_PyNs3SocketIpv6HopLimitTag_Type;


PyTypeObject *_PyNs3SocketIpv6TclassTag_Type;


PyTypeObject *_PyNs3SocketSetDontFragmentTag_Type;


PyTypeObject *_PyNs3Time_Type;
std::map<void*, PyObject*> *_PyNs3Time_wrapper_registry;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


PyTypeObject *_PyNs3Trailer_Type;


PyTypeObject *_PyNs3AttributeAccessor_Type;


PyTypeObject *_PyNs3AttributeChecker_Type;


PyTypeObject *_PyNs3AttributeValue_Type;


PyTypeObject *_PyNs3CallbackChecker_Type;


PyTypeObject *_PyNs3CallbackImplBase_Type;


PyTypeObject *_PyNs3CallbackValue_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3EventImpl_Type;


PyTypeObject *_PyNs3Ipv4_Type;


PyTypeObject *_PyNs3Ipv4AddressChecker_Type;


PyTypeObject *_PyNs3Ipv4AddressValue_Type;


PyTypeObject *_PyNs3Ipv4L3Protocol_Type;


PyTypeObject *_PyNs3Ipv4MaskChecker_Type;


PyTypeObject *_PyNs3Ipv4MaskValue_Type;


PyTypeObject *_PyNs3Ipv4MulticastRoute_Type;


PyTypeObject *_PyNs3Ipv4Route_Type;


PyTypeObject *_PyNs3Ipv4RoutingProtocol_Type;


PyTypeObject *_PyNs3Ipv6_Type;


PyTypeObject *_PyNs3Ipv6AddressChecker_Type;


PyTypeObject *_PyNs3Ipv6AddressValue_Type;


PyTypeObject *_PyNs3Ipv6L3Protocol_Type;


PyTypeObject *_PyNs3Ipv6PmtuCache_Type;


PyTypeObject *_PyNs3Ipv6PrefixChecker_Type;


PyTypeObject *_PyNs3Ipv6PrefixValue_Type;


PyTypeObject *_PyNs3Mac48AddressChecker_Type;


PyTypeObject *_PyNs3Mac48AddressValue_Type;


PyTypeObject *_PyNs3NetDevice_Type;


PyTypeObject *_PyNs3NixVector_Type;


PyTypeObject *_PyNs3Node_Type;


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3OutputStreamWrapper_Type;


PyTypeObject *_PyNs3Packet_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


std::map<void*, PyObject*> PyNs3PointToPointDumbbellHelper_wrapper_registry;


static int
_wrap_PyNs3PointToPointDumbbellHelper__tp_init__0(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PointToPointDumbbellHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PointToPointDumbbellHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PointToPointDumbbellHelper(*((PyNs3PointToPointDumbbellHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3PointToPointDumbbellHelper__tp_init__1(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    unsigned int nLeftLeaf;
    PyNs3PointToPointHelper *leftHelper;
    unsigned int nRightLeaf;
    PyNs3PointToPointHelper *rightHelper;
    PyNs3PointToPointHelper *bottleneckHelper;
    const char *keywords[] = {"nLeftLeaf", "leftHelper", "nRightLeaf", "rightHelper", "bottleneckHelper", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!IO!O!", (char **) keywords, &nLeftLeaf, &PyNs3PointToPointHelper_Type, &leftHelper, &nRightLeaf, &PyNs3PointToPointHelper_Type, &rightHelper, &PyNs3PointToPointHelper_Type, &bottleneckHelper)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PointToPointDumbbellHelper(nLeftLeaf, *((PyNs3PointToPointHelper *) leftHelper)->obj, nRightLeaf, *((PyNs3PointToPointHelper *) rightHelper)->obj, *((PyNs3PointToPointHelper *) bottleneckHelper)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3PointToPointDumbbellHelper__tp_init(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PointToPointDumbbellHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PointToPointDumbbellHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PointToPointDumbbellHelper_LeftCount(PyNs3PointToPointDumbbellHelper *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->LeftCount();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_GetRightIpv4Address(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4Address *py_Ipv4Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv4Address retval = self->obj->GetRightIpv4Address(i);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_AssignIpv4Addresses(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4AddressHelper *leftIp;
    PyNs3Ipv4AddressHelper *rightIp;
    PyNs3Ipv4AddressHelper *routerIp;
    const char *keywords[] = {"leftIp", "rightIp", "routerIp", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!", (char **) keywords, &PyNs3Ipv4AddressHelper_Type, &leftIp, &PyNs3Ipv4AddressHelper_Type, &rightIp, &PyNs3Ipv4AddressHelper_Type, &routerIp)) {
        return NULL;
    }
    self->obj->AssignIpv4Addresses(*((PyNs3Ipv4AddressHelper *) leftIp)->obj, *((PyNs3Ipv4AddressHelper *) rightIp)->obj, *((PyNs3Ipv4AddressHelper *) routerIp)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_GetLeft__0(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    const char *keywords[] = {NULL};
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->GetLeft();
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}

PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_GetLeft__1(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->GetLeft(i);
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}

PyObject * _wrap_PyNs3PointToPointDumbbellHelper_GetLeft(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PointToPointDumbbellHelper_GetLeft__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PointToPointDumbbellHelper_GetLeft__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PointToPointDumbbellHelper_GetRight__0(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    const char *keywords[] = {NULL};
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->GetRight();
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}

PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_GetRight__1(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->GetRight(i);
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}

PyObject * _wrap_PyNs3PointToPointDumbbellHelper_GetRight(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PointToPointDumbbellHelper_GetRight__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PointToPointDumbbellHelper_GetRight__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PointToPointDumbbellHelper_GetRightIpv6Address(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv6Address *py_Ipv6Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv6Address retval = self->obj->GetRightIpv6Address(i);
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_GetLeftIpv4Address(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4Address *py_Ipv4Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv4Address retval = self->obj->GetLeftIpv4Address(i);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_GetLeftIpv6Address(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv6Address *py_Ipv6Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv6Address retval = self->obj->GetLeftIpv6Address(i);
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_AssignIpv6Addresses(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *prefix;
    const char *keywords[] = {"network", "prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &prefix)) {
        return NULL;
    }
    self->obj->AssignIpv6Addresses(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) prefix)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_BoundingBox(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double ulx;
    double uly;
    double lrx;
    double lry;
    const char *keywords[] = {"ulx", "uly", "lrx", "lry", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddd", (char **) keywords, &ulx, &uly, &lrx, &lry)) {
        return NULL;
    }
    self->obj->BoundingBox(ulx, uly, lrx, lry);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_RightCount(PyNs3PointToPointDumbbellHelper *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->RightCount();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointDumbbellHelper_InstallStack(PyNs3PointToPointDumbbellHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3InternetStackHelper *stack;
    const char *keywords[] = {"stack", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3InternetStackHelper_Type, &stack)) {
        return NULL;
    }
    self->obj->InstallStack(*((PyNs3InternetStackHelper *) stack)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3PointToPointDumbbellHelper__copy__(PyNs3PointToPointDumbbellHelper *self)
{

    PyNs3PointToPointDumbbellHelper *py_copy;
    py_copy = PyObject_New(PyNs3PointToPointDumbbellHelper, &PyNs3PointToPointDumbbellHelper_Type);
    py_copy->obj = new ns3::PointToPointDumbbellHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PointToPointDumbbellHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PointToPointDumbbellHelper_methods[] = {
    {(char *) "LeftCount", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_LeftCount, METH_NOARGS, NULL },
    {(char *) "GetRightIpv4Address", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_GetRightIpv4Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignIpv4Addresses", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_AssignIpv4Addresses, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLeft", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_GetLeft, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRight", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_GetRight, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRightIpv6Address", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_GetRightIpv6Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLeftIpv4Address", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_GetLeftIpv4Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLeftIpv6Address", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_GetLeftIpv6Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignIpv6Addresses", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_AssignIpv6Addresses, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "BoundingBox", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_BoundingBox, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RightCount", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_RightCount, METH_NOARGS, NULL },
    {(char *) "InstallStack", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper_InstallStack, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PointToPointDumbbellHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3PointToPointDumbbellHelper__tp_dealloc(PyNs3PointToPointDumbbellHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PointToPointDumbbellHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PointToPointDumbbellHelper_wrapper_registry.end()) {
        PyNs3PointToPointDumbbellHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::PointToPointDumbbellHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PointToPointDumbbellHelper__tp_richcompare (PyNs3PointToPointDumbbellHelper *PYBINDGEN_UNUSED(self), PyNs3PointToPointDumbbellHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PointToPointDumbbellHelper_Type)) {
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

PyTypeObject PyNs3PointToPointDumbbellHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.PointToPointDumbbellHelper",            /* tp_name */
    sizeof(PyNs3PointToPointDumbbellHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PointToPointDumbbellHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3PointToPointDumbbellHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PointToPointDumbbellHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PointToPointDumbbellHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3PointToPointGridHelper_wrapper_registry;


static int
_wrap_PyNs3PointToPointGridHelper__tp_init__0(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PointToPointGridHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PointToPointGridHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PointToPointGridHelper(*((PyNs3PointToPointGridHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3PointToPointGridHelper__tp_init__1(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    unsigned int nRows;
    unsigned int nCols;
    PyNs3PointToPointHelper *pointToPoint;
    const char *keywords[] = {"nRows", "nCols", "pointToPoint", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IIO!", (char **) keywords, &nRows, &nCols, &PyNs3PointToPointHelper_Type, &pointToPoint)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PointToPointGridHelper(nRows, nCols, *((PyNs3PointToPointHelper *) pointToPoint)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3PointToPointGridHelper__tp_init(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PointToPointGridHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PointToPointGridHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PointToPointGridHelper_InstallStack(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3InternetStackHelper *stack;
    const char *keywords[] = {"stack", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3InternetStackHelper_Type, &stack)) {
        return NULL;
    }
    self->obj->InstallStack(*((PyNs3InternetStackHelper *) stack)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointGridHelper_AssignIpv4Addresses(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4AddressHelper *rowIp;
    PyNs3Ipv4AddressHelper *colIp;
    const char *keywords[] = {"rowIp", "colIp", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4AddressHelper_Type, &rowIp, &PyNs3Ipv4AddressHelper_Type, &colIp)) {
        return NULL;
    }
    self->obj->AssignIpv4Addresses(*((PyNs3Ipv4AddressHelper *) rowIp)->obj, *((PyNs3Ipv4AddressHelper *) colIp)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointGridHelper_GetIpv4Address(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int row;
    unsigned int col;
    const char *keywords[] = {"row", "col", NULL};
    PyNs3Ipv4Address *py_Ipv4Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "II", (char **) keywords, &row, &col)) {
        return NULL;
    }
    ns3::Ipv4Address retval = self->obj->GetIpv4Address(row, col);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointGridHelper_AssignIpv6Addresses(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *prefix;
    const char *keywords[] = {"network", "prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &prefix)) {
        return NULL;
    }
    self->obj->AssignIpv6Addresses(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) prefix)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointGridHelper_BoundingBox(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double ulx;
    double uly;
    double lrx;
    double lry;
    const char *keywords[] = {"ulx", "uly", "lrx", "lry", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddd", (char **) keywords, &ulx, &uly, &lrx, &lry)) {
        return NULL;
    }
    self->obj->BoundingBox(ulx, uly, lrx, lry);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointGridHelper_GetIpv6Address(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int row;
    unsigned int col;
    const char *keywords[] = {"row", "col", NULL};
    PyNs3Ipv6Address *py_Ipv6Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "II", (char **) keywords, &row, &col)) {
        return NULL;
    }
    ns3::Ipv6Address retval = self->obj->GetIpv6Address(row, col);
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointGridHelper_GetNode(PyNs3PointToPointGridHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    unsigned int row;
    unsigned int col;
    const char *keywords[] = {"row", "col", NULL};
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "II", (char **) keywords, &row, &col)) {
        return NULL;
    }
    retval = self->obj->GetNode(row, col);
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}


static PyObject*
_wrap_PyNs3PointToPointGridHelper__copy__(PyNs3PointToPointGridHelper *self)
{

    PyNs3PointToPointGridHelper *py_copy;
    py_copy = PyObject_New(PyNs3PointToPointGridHelper, &PyNs3PointToPointGridHelper_Type);
    py_copy->obj = new ns3::PointToPointGridHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PointToPointGridHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PointToPointGridHelper_methods[] = {
    {(char *) "InstallStack", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_InstallStack, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignIpv4Addresses", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_AssignIpv4Addresses, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetIpv4Address", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_GetIpv4Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignIpv6Addresses", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_AssignIpv6Addresses, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "BoundingBox", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_BoundingBox, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetIpv6Address", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_GetIpv6Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3PointToPointGridHelper_GetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PointToPointGridHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3PointToPointGridHelper__tp_dealloc(PyNs3PointToPointGridHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PointToPointGridHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PointToPointGridHelper_wrapper_registry.end()) {
        PyNs3PointToPointGridHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::PointToPointGridHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PointToPointGridHelper__tp_richcompare (PyNs3PointToPointGridHelper *PYBINDGEN_UNUSED(self), PyNs3PointToPointGridHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PointToPointGridHelper_Type)) {
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

PyTypeObject PyNs3PointToPointGridHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.PointToPointGridHelper",            /* tp_name */
    sizeof(PyNs3PointToPointGridHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PointToPointGridHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3PointToPointGridHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PointToPointGridHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PointToPointGridHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3PointToPointStarHelper_wrapper_registry;


static int
_wrap_PyNs3PointToPointStarHelper__tp_init__0(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PointToPointStarHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PointToPointStarHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PointToPointStarHelper(*((PyNs3PointToPointStarHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3PointToPointStarHelper__tp_init__1(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    unsigned int numSpokes;
    PyNs3PointToPointHelper *p2pHelper;
    const char *keywords[] = {"numSpokes", "p2pHelper", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &numSpokes, &PyNs3PointToPointHelper_Type, &p2pHelper)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PointToPointStarHelper(numSpokes, *((PyNs3PointToPointHelper *) p2pHelper)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3PointToPointStarHelper__tp_init(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PointToPointStarHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PointToPointStarHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PointToPointStarHelper_GetHubIpv6Address(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv6Address *py_Ipv6Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv6Address retval = self->obj->GetHubIpv6Address(i);
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_GetSpokeIpv4Address(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4Address *py_Ipv4Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv4Address retval = self->obj->GetSpokeIpv4Address(i);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_AssignIpv4Addresses(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4AddressHelper *address;
    const char *keywords[] = {"address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4AddressHelper_Type, &address)) {
        return NULL;
    }
    self->obj->AssignIpv4Addresses(*((PyNs3Ipv4AddressHelper *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_GetHubIpv4Address(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv4Address *py_Ipv4Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv4Address retval = self->obj->GetHubIpv4Address(i);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_GetHub(PyNs3PointToPointStarHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetHub();
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_AssignIpv6Addresses(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *network;
    PyNs3Ipv6Prefix *prefix;
    const char *keywords[] = {"network", "prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv6Address_Type, &network, &PyNs3Ipv6Prefix_Type, &prefix)) {
        return NULL;
    }
    self->obj->AssignIpv6Addresses(*((PyNs3Ipv6Address *) network)->obj, *((PyNs3Ipv6Prefix *) prefix)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_BoundingBox(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double ulx;
    double uly;
    double lrx;
    double lry;
    const char *keywords[] = {"ulx", "uly", "lrx", "lry", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddd", (char **) keywords, &ulx, &uly, &lrx, &lry)) {
        return NULL;
    }
    self->obj->BoundingBox(ulx, uly, lrx, lry);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_GetSpokeIpv6Address(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Ipv6Address *py_Ipv6Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    ns3::Ipv6Address retval = self->obj->GetSpokeIpv6Address(i);
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_InstallStack(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3InternetStackHelper *stack;
    const char *keywords[] = {"stack", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3InternetStackHelper_Type, &stack)) {
        return NULL;
    }
    self->obj->InstallStack(*((PyNs3InternetStackHelper *) stack)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_GetSpokeNode(PyNs3PointToPointStarHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->GetSpokeNode(i);
    if (!(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = reinterpret_cast< PyNs3Node* >(reinterpret_cast< PyNs3Node__PythonHelper* >(const_cast<ns3::Node *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Node *> (ns3::PeekPointer (retval)))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->inst_dict = NULL;
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (retval))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Node);
    return py_retval;
}


PyObject *
_wrap_PyNs3PointToPointStarHelper_SpokeCount(PyNs3PointToPointStarHelper *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->SpokeCount();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3PointToPointStarHelper__copy__(PyNs3PointToPointStarHelper *self)
{

    PyNs3PointToPointStarHelper *py_copy;
    py_copy = PyObject_New(PyNs3PointToPointStarHelper, &PyNs3PointToPointStarHelper_Type);
    py_copy->obj = new ns3::PointToPointStarHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PointToPointStarHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PointToPointStarHelper_methods[] = {
    {(char *) "GetHubIpv6Address", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_GetHubIpv6Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSpokeIpv4Address", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_GetSpokeIpv4Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignIpv4Addresses", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_AssignIpv4Addresses, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHubIpv4Address", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_GetHubIpv4Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHub", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_GetHub, METH_NOARGS, NULL },
    {(char *) "AssignIpv6Addresses", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_AssignIpv6Addresses, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "BoundingBox", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_BoundingBox, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSpokeIpv6Address", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_GetSpokeIpv6Address, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InstallStack", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_InstallStack, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSpokeNode", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_GetSpokeNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SpokeCount", (PyCFunction) _wrap_PyNs3PointToPointStarHelper_SpokeCount, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PointToPointStarHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3PointToPointStarHelper__tp_dealloc(PyNs3PointToPointStarHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PointToPointStarHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PointToPointStarHelper_wrapper_registry.end()) {
        PyNs3PointToPointStarHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::PointToPointStarHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PointToPointStarHelper__tp_richcompare (PyNs3PointToPointStarHelper *PYBINDGEN_UNUSED(self), PyNs3PointToPointStarHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PointToPointStarHelper_Type)) {
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

PyTypeObject PyNs3PointToPointStarHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.PointToPointStarHelper",            /* tp_name */
    sizeof(PyNs3PointToPointStarHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PointToPointStarHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3PointToPointStarHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PointToPointStarHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PointToPointStarHelper__tp_init,             /* tp_init */
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
Pystd__vector__lt___bool___gt__Iter__tp_clear(Pystd__vector__lt___bool___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___bool___gt__Iter__tp_traverse(Pystd__vector__lt___bool___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___bool___gt____tp_dealloc(Pystd__vector__lt___bool___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___bool___gt__Iter__tp_dealloc(Pystd__vector__lt___bool___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___bool___gt____tp_iter(Pystd__vector__lt___bool___gt__ *self)
{
    Pystd__vector__lt___bool___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___bool___gt__Iter, &Pystd__vector__lt___bool___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< bool >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___bool___gt__Iter__tp_iter(Pystd__vector__lt___bool___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___bool___gt__Iter__tp_iternext(Pystd__vector__lt___bool___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< bool >::iterator iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong((*iter)));
    return py_retval;
}

int _wrap_convert_py2c__bool(PyObject *value, bool *address)
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___bool___gt__(PyObject *arg, std::vector< bool > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___bool___gt___Type)) {
        *container = *((Pystd__vector__lt___bool___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            bool item;
            if (!_wrap_convert_py2c__bool(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___bool___gt__ instance, or a list of bool");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___bool___gt____tp_init(Pystd__vector__lt___bool___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< bool >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___bool___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___bool___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.Std__vector__lt___bool___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___bool___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___bool___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___bool___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___bool___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___bool___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.Std__vector__lt___bool___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___bool___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___bool___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___bool___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___bool___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___bool___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___bool___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_clear(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_traverse(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt____tp_dealloc(Pystd__map__lt___unsigned_int__unsigned_int___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_dealloc(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt____tp_iter(Pystd__map__lt___unsigned_int__unsigned_int___gt__ *self)
{
    Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter *iter = PyObject_GC_New(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter, &Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::map< unsigned int, unsigned int >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_iter(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_iternext(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter *self)
{
    PyObject *py_retval;
    std::map< unsigned int, unsigned int >::iterator iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_retval = Py_BuildValue((char *) "NN", PyLong_FromUnsignedLong(iter->first), PyLong_FromUnsignedLong(iter->second));
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


int _wrap_convert_py2c__std__map__lt___unsigned_int__unsigned_int___gt__(PyObject *arg, std::map< unsigned int, unsigned int > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__map__lt___unsigned_int__unsigned_int___gt___Type)) {
        *container = *((Pystd__map__lt___unsigned_int__unsigned_int___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *tup = PyList_GET_ITEM(arg, i);
            if (!PyTuple_Check(tup) || PyTuple_Size(tup) != 2) {
                PyErr_SetString(PyExc_TypeError, "items must be tuples with two elements");
                return 0;
            }
            std::pair< unsigned int, unsigned int > item;
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 0), &item.first)) {
                return 0;
            }
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 1), &item.second)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__map__lt___unsigned_int__unsigned_int___gt__ instance, or a list of unsigned int");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt____tp_init(Pystd__map__lt___unsigned_int__unsigned_int___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::map< unsigned int, unsigned int >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__map__lt___unsigned_int__unsigned_int___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__map__lt___unsigned_int__unsigned_int___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.Std__map__lt___unsigned_int__unsigned_int___gt__",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__unsigned_int___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "point_to_point_layout.Std__map__lt___unsigned_int__unsigned_int___gt__Iter",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter__tp_iternext,     /* tp_iternext */
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
static struct PyModuleDef point_to_point_layout_moduledef = {
    PyModuleDef_HEAD_INIT,
    "point_to_point_layout",
    NULL,
    -1,
    point_to_point_layout_functions,
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


MOD_INIT(point_to_point_layout)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&point_to_point_layout_moduledef);
    #else
    m = Py_InitModule3((char *) "point_to_point_layout", point_to_point_layout_functions, NULL);
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
    /* Import the 'ns3::AsciiTraceHelperForIpv4' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AsciiTraceHelperForIpv4_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AsciiTraceHelperForIpv4");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AsciiTraceHelperForIpv4_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AsciiTraceHelperForIpv4_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AsciiTraceHelperForIpv4_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::AsciiTraceHelperForIpv6' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3AsciiTraceHelperForIpv6_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "AsciiTraceHelperForIpv6");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3AsciiTraceHelperForIpv6_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3AsciiTraceHelperForIpv6_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3AsciiTraceHelperForIpv6_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::Ipv4AddressHelper' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4AddressHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4AddressHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv4AddressHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv4AddressHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv4AddressHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv4InterfaceAddress' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4InterfaceAddress_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4InterfaceAddress");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv4InterfaceAddress_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv4InterfaceAddress_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv4InterfaceAddress_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv4InterfaceContainer' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4InterfaceContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4InterfaceContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv4InterfaceContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv4InterfaceContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv4InterfaceContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::Ipv6AddressHelper' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6AddressHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6AddressHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv6AddressHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv6AddressHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv6AddressHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv6InterfaceAddress' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6InterfaceAddress_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6InterfaceAddress");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv6InterfaceAddress_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv6InterfaceAddress_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv6InterfaceAddress_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Ipv6InterfaceContainer' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6InterfaceContainer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6InterfaceContainer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv6InterfaceContainer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv6InterfaceContainer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv6InterfaceContainer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::PcapHelperForIpv4' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapHelperForIpv4_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapHelperForIpv4");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PcapHelperForIpv4_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PcapHelperForIpv4_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PcapHelperForIpv4_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PcapHelperForIpv6' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapHelperForIpv6_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapHelperForIpv6");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3PcapHelperForIpv6_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3PcapHelperForIpv6_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3PcapHelperForIpv6_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::PointToPointHelper' class from module 'ns.point_to_point' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.point_to_point");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PointToPointHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PointToPointHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
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
    /* Import the 'ns3::Header' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Header_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Header");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::InternetStackHelper' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3InternetStackHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "InternetStackHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4Header' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4Header_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4Header");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6Header' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6Header_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6Header");
    
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
    /* Import the 'ns3::PcapFileWrapper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3PcapFileWrapper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "PcapFileWrapper");
    
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
    /* Import the 'ns3::SimpleRefCount< ns3::Ipv4MulticastRoute, ns3::empty, ns3::DefaultDeleter<ns3::Ipv4MulticastRoute> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::Ipv4MulticastRoute, ns3::empty, ns3::DefaultDeleter<ns3::Ipv4MulticastRoute> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3Ipv4MulticastRoute_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4MulticastRoute__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::SimpleRefCount< ns3::Ipv4Route, ns3::empty, ns3::DefaultDeleter<ns3::Ipv4Route> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::Ipv4Route, ns3::empty, ns3::DefaultDeleter<ns3::Ipv4Route> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::EmptyAttributeValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EmptyAttributeValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EmptyAttributeValue");
    
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
    /* Import the 'ns3::Ipv4' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4");
    
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
    /* Import the 'ns3::Ipv4L3Protocol' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4L3Protocol_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4L3Protocol");
    
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
    /* Import the 'ns3::Ipv4MulticastRoute' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4MulticastRoute_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4MulticastRoute");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4Route' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4Route_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4Route");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv4RoutingProtocol' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4RoutingProtocol_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4RoutingProtocol");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6");
    
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
    /* Import the 'ns3::Ipv6L3Protocol' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6L3Protocol_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6L3Protocol");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Ipv6PmtuCache' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv6PmtuCache_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv6PmtuCache");
    
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
    PyModule_AddObject(m, (char *) "_PyNs3PointToPointDumbbellHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3PointToPointDumbbellHelper_wrapper_registry, NULL));
    /* Register the 'ns3::PointToPointDumbbellHelper' class */
    if (PyType_Ready(&PyNs3PointToPointDumbbellHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PointToPointDumbbellHelper", (PyObject *) &PyNs3PointToPointDumbbellHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3PointToPointGridHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3PointToPointGridHelper_wrapper_registry, NULL));
    /* Register the 'ns3::PointToPointGridHelper' class */
    if (PyType_Ready(&PyNs3PointToPointGridHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PointToPointGridHelper", (PyObject *) &PyNs3PointToPointGridHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3PointToPointStarHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3PointToPointStarHelper_wrapper_registry, NULL));
    /* Register the 'ns3::PointToPointStarHelper' class */
    if (PyType_Ready(&PyNs3PointToPointStarHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PointToPointStarHelper", (PyObject *) &PyNs3PointToPointStarHelper_Type);
    /* Register the 'std::vector< bool >' class */
    if (PyType_Ready(&Pystd__vector__lt___bool___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__vector__lt___bool___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___bool___gt__", (PyObject *) &Pystd__vector__lt___bool___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___bool___gt__Iter", (PyObject *) &Pystd__vector__lt___bool___gt__Iter_Type);
    /* Register the 'std::map< unsigned int, unsigned int >' class */
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__Iter", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type);
    submodule = initpoint_to_point_layout_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initpoint_to_point_layout_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initpoint_to_point_layout_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    return MOD_RETURN(m);
}
