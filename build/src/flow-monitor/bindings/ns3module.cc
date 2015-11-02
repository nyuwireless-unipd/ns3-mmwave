#include "ns3module.h"
static PyMethodDef flow_monitor_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef flow_monitor_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "flow_monitor.FatalImpl",
    NULL,
    -1,
    flow_monitor_FatalImpl_functions,
};
#endif

static PyObject *
initflow_monitor_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&flow_monitor_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "flow_monitor.FatalImpl", flow_monitor_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef flow_monitor_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef flow_monitor_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "flow_monitor.Hash.Function",
    NULL,
    -1,
    flow_monitor_Hash_Function_functions,
};
#endif

static PyObject *
initflow_monitor_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&flow_monitor_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "flow_monitor.Hash.Function", flow_monitor_Hash_Function_functions, NULL);
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
static PyMethodDef flow_monitor_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef flow_monitor_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "flow_monitor.Hash",
    NULL,
    -1,
    flow_monitor_Hash_functions,
};
#endif

static PyObject *
initflow_monitor_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&flow_monitor_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "flow_monitor.Hash", flow_monitor_Hash_functions, NULL);
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
    submodule = initflow_monitor_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef flow_monitor_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef flow_monitor_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "flow_monitor.TracedValueCallback",
    NULL,
    -1,
    flow_monitor_TracedValueCallback_functions,
};
#endif

static PyObject *
initflow_monitor_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&flow_monitor_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "flow_monitor.TracedValueCallback", flow_monitor_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef flow_monitor_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3Address_Type;
std::map<void*, PyObject*> *_PyNs3Address_wrapper_registry;


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


PyTypeObject *_PyNs3Ipv4InterfaceAddress_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4InterfaceAddress_wrapper_registry;


PyTypeObject *_PyNs3Ipv4Mask_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4Mask_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Address_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Address_wrapper_registry;


PyTypeObject *_PyNs3Ipv6InterfaceAddress_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6InterfaceAddress_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Prefix_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Prefix_wrapper_registry;


PyTypeObject *_PyNs3Mac48Address_Type;
std::map<void*, PyObject*> *_PyNs3Mac48Address_wrapper_registry;


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


PyTypeObject *_PyNs3Ipv4Header_Type;


PyTypeObject *_PyNs3Ipv6Header_Type;


PyTypeObject *_PyNs3Object_Type;


PyTypeObject *_PyNs3ObjectAggregateIterator_Type;
std::map<void*, PyObject*> *_PyNs3ObjectAggregateIterator_wrapper_registry;


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


std::map<void*, PyObject*> PyNs3FlowMonitorHelper_wrapper_registry;

static int
_wrap_PyNs3FlowMonitorHelper__tp_init(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::FlowMonitorHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_SerializeToXmlString(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    int indent;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"indent", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iOO", (char **) keywords, &indent, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    retval = self->obj->SerializeToXmlString(indent, enableHistograms, enableProbes);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_InstallAll(PyNs3FlowMonitorHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FlowMonitor > retval;
    PyNs3FlowMonitor *py_FlowMonitor;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->InstallAll();
    if (!(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3FlowMonitor__PythonHelper).name())
    {
        py_FlowMonitor = reinterpret_cast< PyNs3FlowMonitor* >(reinterpret_cast< PyNs3FlowMonitor__PythonHelper* >(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))->m_pyself);
        py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
        Py_INCREF(py_FlowMonitor);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_FlowMonitor = NULL;
        } else {
            py_FlowMonitor = (PyNs3FlowMonitor *) wrapper_lookup_iter->second;
            Py_INCREF(py_FlowMonitor);
        }
    
        if (py_FlowMonitor == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))), &PyNs3FlowMonitor_Type);
            py_FlowMonitor = PyObject_GC_New(PyNs3FlowMonitor, wrapper_type);
            py_FlowMonitor->inst_dict = NULL;
    
            py_FlowMonitor->inst_dict = NULL;
            py_FlowMonitor->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval))->Ref();
            py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_FlowMonitor->obj] = (PyObject *) py_FlowMonitor;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowMonitor);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_GetMonitor(PyNs3FlowMonitorHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FlowMonitor > retval;
    PyNs3FlowMonitor *py_FlowMonitor;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetMonitor();
    if (!(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3FlowMonitor__PythonHelper).name())
    {
        py_FlowMonitor = reinterpret_cast< PyNs3FlowMonitor* >(reinterpret_cast< PyNs3FlowMonitor__PythonHelper* >(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))->m_pyself);
        py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
        Py_INCREF(py_FlowMonitor);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_FlowMonitor = NULL;
        } else {
            py_FlowMonitor = (PyNs3FlowMonitor *) wrapper_lookup_iter->second;
            Py_INCREF(py_FlowMonitor);
        }
    
        if (py_FlowMonitor == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))), &PyNs3FlowMonitor_Type);
            py_FlowMonitor = PyObject_GC_New(PyNs3FlowMonitor, wrapper_type);
            py_FlowMonitor->inst_dict = NULL;
    
            py_FlowMonitor->inst_dict = NULL;
            py_FlowMonitor->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval))->Ref();
            py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_FlowMonitor->obj] = (PyObject *) py_FlowMonitor;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowMonitor);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_GetClassifier(PyNs3FlowMonitorHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FlowClassifier > retval;
    PyNs3FlowClassifier *py_FlowClassifier;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetClassifier();
    if (!(const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_FlowClassifier = NULL;
    } else {
        py_FlowClassifier = (PyNs3FlowClassifier *) wrapper_lookup_iter->second;
        Py_INCREF(py_FlowClassifier);
    }
    
    if (py_FlowClassifier == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval)))), &PyNs3FlowClassifier_Type);
        py_FlowClassifier = PyObject_New(PyNs3FlowClassifier, wrapper_type);
    
        py_FlowClassifier->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval))->Ref();
        py_FlowClassifier->obj = const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_FlowClassifier->obj] = (PyObject *) py_FlowClassifier;
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowClassifier);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_SerializeToXmlFile(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *fileName;
    Py_ssize_t fileName_len;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"fileName", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#OO", (char **) keywords, &fileName, &fileName_len, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    self->obj->SerializeToXmlFile(std::string(fileName, fileName_len), enableHistograms, enableProbes);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_GetClassifier6(PyNs3FlowMonitorHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FlowClassifier > retval;
    PyNs3FlowClassifier *py_FlowClassifier;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetClassifier6();
    if (!(const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_FlowClassifier = NULL;
    } else {
        py_FlowClassifier = (PyNs3FlowClassifier *) wrapper_lookup_iter->second;
        Py_INCREF(py_FlowClassifier);
    }
    
    if (py_FlowClassifier == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval)))), &PyNs3FlowClassifier_Type);
        py_FlowClassifier = PyObject_New(PyNs3FlowClassifier, wrapper_type);
    
        py_FlowClassifier->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval))->Ref();
        py_FlowClassifier->obj = const_cast<ns3::FlowClassifier *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_FlowClassifier->obj] = (PyObject *) py_FlowClassifier;
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowClassifier);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitorHelper_SetMonitorAttribute(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *n1;
    Py_ssize_t n1_len;
    PyNs3AttributeValue *v1;
    const char *keywords[] = {"n1", "v1", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &n1, &n1_len, &PyNs3AttributeValue_Type, &v1)) {
        return NULL;
    }
    self->obj->SetMonitorAttribute(std::string(n1, n1_len), *((PyNs3AttributeValue *) v1)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3FlowMonitorHelper_Install__0(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FlowMonitor > retval;
    PyNs3NodeContainer *nodes;
    const char *keywords[] = {"nodes", NULL};
    PyNs3FlowMonitor *py_FlowMonitor;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &nodes)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->Install(*((PyNs3NodeContainer *) nodes)->obj);
    if (!(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3FlowMonitor__PythonHelper).name())
    {
        py_FlowMonitor = reinterpret_cast< PyNs3FlowMonitor* >(reinterpret_cast< PyNs3FlowMonitor__PythonHelper* >(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))->m_pyself);
        py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
        Py_INCREF(py_FlowMonitor);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_FlowMonitor = NULL;
        } else {
            py_FlowMonitor = (PyNs3FlowMonitor *) wrapper_lookup_iter->second;
            Py_INCREF(py_FlowMonitor);
        }
    
        if (py_FlowMonitor == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))), &PyNs3FlowMonitor_Type);
            py_FlowMonitor = PyObject_GC_New(PyNs3FlowMonitor, wrapper_type);
            py_FlowMonitor->inst_dict = NULL;
    
            py_FlowMonitor->inst_dict = NULL;
            py_FlowMonitor->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval))->Ref();
            py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_FlowMonitor->obj] = (PyObject *) py_FlowMonitor;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowMonitor);
    return py_retval;
}

PyObject *
_wrap_PyNs3FlowMonitorHelper_Install__1(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FlowMonitor > retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3FlowMonitor *py_FlowMonitor;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
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
    retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    if (!(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3FlowMonitor__PythonHelper).name())
    {
        py_FlowMonitor = reinterpret_cast< PyNs3FlowMonitor* >(reinterpret_cast< PyNs3FlowMonitor__PythonHelper* >(const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))->m_pyself);
        py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
        Py_INCREF(py_FlowMonitor);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_FlowMonitor = NULL;
        } else {
            py_FlowMonitor = (PyNs3FlowMonitor *) wrapper_lookup_iter->second;
            Py_INCREF(py_FlowMonitor);
        }
    
        if (py_FlowMonitor == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval)))), &PyNs3FlowMonitor_Type);
            py_FlowMonitor = PyObject_GC_New(PyNs3FlowMonitor, wrapper_type);
            py_FlowMonitor->inst_dict = NULL;
    
            py_FlowMonitor->inst_dict = NULL;
            py_FlowMonitor->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval))->Ref();
            py_FlowMonitor->obj = const_cast<ns3::FlowMonitor *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_FlowMonitor->obj] = (PyObject *) py_FlowMonitor;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowMonitor);
    return py_retval;
}

PyObject * _wrap_PyNs3FlowMonitorHelper_Install(PyNs3FlowMonitorHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitorHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitorHelper_Install__1(self, args, kwargs, &exceptions[1]);
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

static PyMethodDef PyNs3FlowMonitorHelper_methods[] = {
    {(char *) "SerializeToXmlString", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_SerializeToXmlString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InstallAll", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_InstallAll, METH_NOARGS, NULL },
    {(char *) "GetMonitor", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_GetMonitor, METH_NOARGS, NULL },
    {(char *) "GetClassifier", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_GetClassifier, METH_NOARGS, NULL },
    {(char *) "SerializeToXmlFile", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_SerializeToXmlFile, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetClassifier6", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_GetClassifier6, METH_NOARGS, NULL },
    {(char *) "SetMonitorAttribute", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_SetMonitorAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3FlowMonitorHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowMonitorHelper__tp_dealloc(PyNs3FlowMonitorHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FlowMonitorHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FlowMonitorHelper_wrapper_registry.end()) {
        PyNs3FlowMonitorHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::FlowMonitorHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowMonitorHelper__tp_richcompare (PyNs3FlowMonitorHelper *PYBINDGEN_UNUSED(self), PyNs3FlowMonitorHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowMonitorHelper_Type)) {
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

PyTypeObject PyNs3FlowMonitorHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.FlowMonitorHelper",            /* tp_name */
    sizeof(PyNs3FlowMonitorHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowMonitorHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3FlowMonitorHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowMonitorHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowMonitorHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Histogram_wrapper_registry;


static int
_wrap_PyNs3Histogram__tp_init__0(PyNs3Histogram *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Histogram *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Histogram_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Histogram(*((PyNs3Histogram *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Histogram__tp_init__1(PyNs3Histogram *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    double binWidth;
    const char *keywords[] = {"binWidth", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &binWidth)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Histogram(binWidth);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Histogram__tp_init__2(PyNs3Histogram *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Histogram();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Histogram__tp_init(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Histogram__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Histogram__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Histogram__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Histogram_SetDefaultBinWidth(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double binWidth;
    const char *keywords[] = {"binWidth", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &binWidth)) {
        return NULL;
    }
    self->obj->SetDefaultBinWidth(binWidth);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinCount(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinCount(index);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinWidth(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinWidth(index);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetNBins(PyNs3Histogram *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNBins();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinEnd(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinEnd(index);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_AddValue(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &value)) {
        return NULL;
    }
    self->obj->AddValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Histogram_GetBinStart(PyNs3Histogram *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    retval = self->obj->GetBinStart(index);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Histogram__copy__(PyNs3Histogram *self)
{

    PyNs3Histogram *py_copy;
    py_copy = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_copy->obj = new ns3::Histogram(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Histogram_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Histogram_methods[] = {
    {(char *) "SetDefaultBinWidth", (PyCFunction) _wrap_PyNs3Histogram_SetDefaultBinWidth, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBinCount", (PyCFunction) _wrap_PyNs3Histogram_GetBinCount, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBinWidth", (PyCFunction) _wrap_PyNs3Histogram_GetBinWidth, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNBins", (PyCFunction) _wrap_PyNs3Histogram_GetNBins, METH_NOARGS, NULL },
    {(char *) "GetBinEnd", (PyCFunction) _wrap_PyNs3Histogram_GetBinEnd, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddValue", (PyCFunction) _wrap_PyNs3Histogram_AddValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBinStart", (PyCFunction) _wrap_PyNs3Histogram_GetBinStart, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Histogram__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Histogram__tp_dealloc(PyNs3Histogram *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Histogram_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Histogram_wrapper_registry.end()) {
        PyNs3Histogram_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Histogram *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Histogram__tp_richcompare (PyNs3Histogram *PYBINDGEN_UNUSED(self), PyNs3Histogram *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Histogram_Type)) {
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

PyTypeObject PyNs3Histogram_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Histogram",            /* tp_name */
    sizeof(PyNs3Histogram),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Histogram__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Histogram__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Histogram_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Histogram__tp_init,             /* tp_init */
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




pybindgen::TypeMap PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map;



static int
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__0(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__1(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >(*((PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____copy__(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self)
{

    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *py_copy;
    py_copy = PyObject_New(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__, &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type);
    
    py_copy->obj = new ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___methods[] = {
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_dealloc(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> > *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_richcompare (PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *PYBINDGEN_UNUSED(self), PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__ *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type)) {
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

PyTypeObject PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__",            /* tp_name */
    sizeof(PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____tp_init,             /* tp_init */
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
_wrap_PyNs3FlowClassifier__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'FlowClassifier' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}

static PyMethodDef PyNs3FlowClassifier_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowClassifier__tp_dealloc(PyNs3FlowClassifier *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::FlowClassifier *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowClassifier__tp_richcompare (PyNs3FlowClassifier *PYBINDGEN_UNUSED(self), PyNs3FlowClassifier *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowClassifier_Type)) {
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

PyTypeObject PyNs3FlowClassifier_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.FlowClassifier",            /* tp_name */
    sizeof(PyNs3FlowClassifier),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowClassifier__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3FlowClassifier__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowClassifier_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowClassifier__tp_init,             /* tp_init */
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
PyNs3FlowMonitor__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class FlowMonitor is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3FlowMonitor__PythonHelper::_wrap_DoInitialize(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
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
PyNs3FlowMonitor__PythonHelper::_wrap_NotifyNewAggregate(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
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
PyNs3FlowMonitor__PythonHelper::_wrap_DoDispose(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper = dynamic_cast< PyNs3FlowMonitor__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class FlowMonitor is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::TypeId
PyNs3FlowMonitor__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FlowMonitor *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::FlowMonitor::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = const_cast< ns3::FlowMonitor* >((const ns3::FlowMonitor*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::FlowMonitor::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::FlowMonitor::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3FlowMonitor__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FlowMonitor *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::FlowMonitor::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = (ns3::FlowMonitor*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FlowMonitor__PythonHelper::NotifyConstructionCompleted()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FlowMonitor *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "NotifyConstructionCompleted"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::FlowMonitor::NotifyConstructionCompleted();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = (ns3::FlowMonitor*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "NotifyConstructionCompleted", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FlowMonitor* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FlowMonitor__PythonHelper::DoInitialize()
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
PyNs3FlowMonitor__PythonHelper::NotifyNewAggregate()
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


static int
_wrap_PyNs3FlowMonitor__tp_init__0(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FlowMonitor *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowMonitor_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3FlowMonitor_Type)
    {
        self->obj = new PyNs3FlowMonitor__PythonHelper(*((PyNs3FlowMonitor *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FlowMonitor__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::FlowMonitor(*((PyNs3FlowMonitor *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3FlowMonitor__tp_init__1(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3FlowMonitor_Type)
    {
        self->obj = new PyNs3FlowMonitor__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FlowMonitor__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::FlowMonitor();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3FlowMonitor__tp_init(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitor__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitor__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3FlowMonitor_ReportLastRx(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!III", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportLastRx(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_StopRightNow(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    
    self->obj->StopRightNow();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportFirstTx(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!III", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportFirstTx(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_AddProbe(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    const char *keywords[] = {"probe", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowProbe_Type, &probe)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->AddProbe(ns3::Ptr< ns3::FlowProbe  > (probe_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_SerializeToXmlString(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    int indent;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"indent", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iOO", (char **) keywords, &indent, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    retval = self->obj->SerializeToXmlString(indent, enableHistograms, enableProbes);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}



PyObject *
_wrap_PyNs3FlowMonitor_CheckForLostPackets__0(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->CheckForLostPackets();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3FlowMonitor_CheckForLostPackets__1(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Time *maxDelay;
    const char *keywords[] = {"maxDelay", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &maxDelay)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->CheckForLostPackets(*((PyNs3Time *) maxDelay)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3FlowMonitor_CheckForLostPackets(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitor_CheckForLostPackets__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitor_CheckForLostPackets__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3FlowMonitor_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::FlowMonitor::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_AddFlowClassifier(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowClassifier *classifier;
    ns3::FlowClassifier *classifier_ptr;
    const char *keywords[] = {"classifier", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowClassifier_Type, &classifier)) {
        return NULL;
    }
    classifier_ptr = (classifier ? classifier->obj : NULL);
    self->obj->AddFlowClassifier(ns3::Ptr< ns3::FlowClassifier  > (classifier_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_GetAllProbes(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    std::vector< ns3::Ptr< ns3::FlowProbe > > retval;
    Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__ *py_std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__;
    
    retval = self->obj->GetAllProbes();
    py_std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__ = PyObject_New(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__, &Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt___Type);
    py_std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__->obj = new std::vector< ns3::Ptr< ns3::FlowProbe > >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_Stop(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *time;
    const char *keywords[] = {"time", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &time)) {
        return NULL;
    }
    self->obj->Stop(*((PyNs3Time *) time)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_StartRightNow(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    
    self->obj->StartRightNow();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_SerializeToXmlFile(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *fileName;
    Py_ssize_t fileName_len;
    bool enableHistograms;
    PyObject *py_enableHistograms;
    bool enableProbes;
    PyObject *py_enableProbes;
    const char *keywords[] = {"fileName", "enableHistograms", "enableProbes", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#OO", (char **) keywords, &fileName, &fileName_len, &py_enableHistograms, &py_enableProbes)) {
        return NULL;
    }
    enableHistograms = (bool) PyObject_IsTrue(py_enableHistograms);
    enableProbes = (bool) PyObject_IsTrue(py_enableProbes);
    self->obj->SerializeToXmlFile(std::string(fileName, fileName_len), enableHistograms, enableProbes);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_Start(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *time;
    const char *keywords[] = {"time", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &time)) {
        return NULL;
    }
    self->obj->Start(*((PyNs3Time *) time)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_GetFlowStats(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowMonitor::FlowStats > retval;
    Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__;
    
    retval = self->obj->GetFlowStats();
    py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ = PyObject_New(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__, &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type);
    py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__->obj = new std::map< unsigned int, ns3::FlowMonitor::FlowStats >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_GetInstanceTypeId(PyNs3FlowMonitor *self)
{
    PyObject *py_retval;
    PyNs3FlowMonitor__PythonHelper *helper_class = dynamic_cast<PyNs3FlowMonitor__PythonHelper*> (self->obj);
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = (helper_class == NULL)? (self->obj->GetInstanceTypeId()) : (self->obj->ns3::FlowMonitor::GetInstanceTypeId());
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportForwarding(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!III", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportForwarding(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowMonitor_ReportDrop(PyNs3FlowMonitor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3FlowProbe *probe;
    ns3::FlowProbe *probe_ptr;
    unsigned int flowId;
    unsigned int packetId;
    unsigned int packetSize;
    unsigned int reasonCode;
    const char *keywords[] = {"probe", "flowId", "packetId", "packetSize", "reasonCode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!IIII", (char **) keywords, &PyNs3FlowProbe_Type, &probe, &flowId, &packetId, &packetSize, &reasonCode)) {
        return NULL;
    }
    probe_ptr = (probe ? probe->obj : NULL);
    self->obj->ReportDrop(ns3::Ptr< ns3::FlowProbe  > (probe_ptr), flowId, packetId, packetSize, reasonCode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3FlowMonitor__copy__(PyNs3FlowMonitor *self)
{

    PyNs3FlowMonitor *py_copy;
    py_copy = PyObject_GC_New(PyNs3FlowMonitor, &PyNs3FlowMonitor_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::FlowMonitor(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FlowMonitor_methods[] = {
    {(char *) "ReportLastRx", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportLastRx, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "StopRightNow", (PyCFunction) _wrap_PyNs3FlowMonitor_StopRightNow, METH_NOARGS, NULL },
    {(char *) "ReportFirstTx", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportFirstTx, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddProbe", (PyCFunction) _wrap_PyNs3FlowMonitor_AddProbe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SerializeToXmlString", (PyCFunction) _wrap_PyNs3FlowMonitor_SerializeToXmlString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "CheckForLostPackets", (PyCFunction) _wrap_PyNs3FlowMonitor_CheckForLostPackets, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3FlowMonitor_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AddFlowClassifier", (PyCFunction) _wrap_PyNs3FlowMonitor_AddFlowClassifier, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAllProbes", (PyCFunction) _wrap_PyNs3FlowMonitor_GetAllProbes, METH_NOARGS, NULL },
    {(char *) "Stop", (PyCFunction) _wrap_PyNs3FlowMonitor_Stop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "StartRightNow", (PyCFunction) _wrap_PyNs3FlowMonitor_StartRightNow, METH_NOARGS, NULL },
    {(char *) "SerializeToXmlFile", (PyCFunction) _wrap_PyNs3FlowMonitor_SerializeToXmlFile, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Start", (PyCFunction) _wrap_PyNs3FlowMonitor_Start, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFlowStats", (PyCFunction) _wrap_PyNs3FlowMonitor_GetFlowStats, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3FlowMonitor_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "ReportForwarding", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportForwarding, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ReportDrop", (PyCFunction) _wrap_PyNs3FlowMonitor_ReportDrop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3FlowMonitor__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FlowMonitor__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FlowMonitor__tp_clear(PyNs3FlowMonitor *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::FlowMonitor *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3FlowMonitor__tp_traverse(PyNs3FlowMonitor *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3FlowMonitor__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3FlowMonitor__tp_dealloc(PyNs3FlowMonitor *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FlowMonitor__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowMonitor__tp_richcompare (PyNs3FlowMonitor *PYBINDGEN_UNUSED(self), PyNs3FlowMonitor *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowMonitor_Type)) {
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

PyTypeObject PyNs3FlowMonitor_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.FlowMonitor",            /* tp_name */
    sizeof(PyNs3FlowMonitor),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowMonitor__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3FlowMonitor__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FlowMonitor__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowMonitor__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowMonitor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FlowMonitor, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowMonitor__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3FlowMonitorFlowStats_wrapper_registry;
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_bytesDropped(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned long long > retval;
    Pystd__vector__lt___unsigned_long_long___gt__ *py_std__vector__lt___unsigned_long_long___gt__;
    
    py_std__vector__lt___unsigned_long_long___gt__ = PyObject_New(Pystd__vector__lt___unsigned_long_long___gt__, &Pystd__vector__lt___unsigned_long_long___gt___Type);
    py_std__vector__lt___unsigned_long_long___gt__->obj = new std::vector< unsigned long long >(self->obj->bytesDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_long_long___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_bytesDropped(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned long long > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_long_long___gt__, &self->obj->bytesDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_delayHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->delayHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_delayHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->delayHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_delaySum(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->delaySum);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_delaySum(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->delaySum = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_flowInterruptionsHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->flowInterruptionsHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_flowInterruptionsHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->flowInterruptionsHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_jitterHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->jitterHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_jitterHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->jitterHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_jitterSum(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->jitterSum);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_jitterSum(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->jitterSum = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_lastDelay(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->lastDelay);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_lastDelay(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->lastDelay = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_lostPackets(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->lostPackets));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_lostPackets(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->lostPackets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_packetSizeHistogram(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *py_Histogram;
    
    py_Histogram = PyObject_New(PyNs3Histogram, &PyNs3Histogram_Type);
    py_Histogram->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Histogram->obj = new ns3::Histogram(self->obj->packetSizeHistogram);
    PyNs3Histogram_wrapper_registry[(void *) py_Histogram->obj] = (PyObject *) py_Histogram;
    py_retval = Py_BuildValue((char *) "N", py_Histogram);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_packetSizeHistogram(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Histogram *tmp_Histogram;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Histogram_Type, &tmp_Histogram)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->packetSizeHistogram = *tmp_Histogram->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_packetsDropped(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned int > retval;
    Pystd__vector__lt___unsigned_int___gt__ *py_std__vector__lt___unsigned_int___gt__;
    
    py_std__vector__lt___unsigned_int___gt__ = PyObject_New(Pystd__vector__lt___unsigned_int___gt__, &Pystd__vector__lt___unsigned_int___gt___Type);
    py_std__vector__lt___unsigned_int___gt__->obj = new std::vector< unsigned int >(self->obj->packetsDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_int___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_packetsDropped(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned int > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &self->obj->packetsDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_rxBytes(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->rxBytes);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_rxBytes(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->rxBytes)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_rxPackets(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->rxPackets));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_rxPackets(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->rxPackets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstRxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeFirstRxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstRxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeFirstRxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstTxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeFirstTxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstTxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeFirstTxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeLastRxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeLastRxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeLastRxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeLastRxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timeLastTxPacket(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->timeLastTxPacket);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timeLastTxPacket(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->timeLastTxPacket = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_timesForwarded(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->timesForwarded));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_timesForwarded(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->timesForwarded)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_txBytes(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->txBytes);
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_txBytes(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->txBytes)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowMonitorFlowStats__get_txPackets(PyNs3FlowMonitorFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->txPackets));
    return py_retval;
}
static int _wrap_PyNs3FlowMonitorFlowStats__set_txPackets(PyNs3FlowMonitorFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->txPackets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3FlowMonitorFlowStats__getsets[] = {
    {
        (char*) "delayHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_delayHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_delayHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "lostPackets", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_lostPackets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_lostPackets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timesForwarded", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timesForwarded, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timesForwarded, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeLastTxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeLastTxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeLastTxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "rxPackets", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_rxPackets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_rxPackets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packetSizeHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_packetSizeHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_packetSizeHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeFirstTxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstTxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstTxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packetsDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_packetsDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_packetsDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "txPackets", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_txPackets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_txPackets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "flowInterruptionsHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_flowInterruptionsHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_flowInterruptionsHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "bytesDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_bytesDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_bytesDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "txBytes", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_txBytes, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_txBytes, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "jitterHistogram", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_jitterHistogram, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_jitterHistogram, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "rxBytes", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_rxBytes, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_rxBytes, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "delaySum", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_delaySum, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_delaySum, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeLastRxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeLastRxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeLastRxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "timeFirstRxPacket", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_timeFirstRxPacket, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_timeFirstRxPacket, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "jitterSum", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_jitterSum, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_jitterSum, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "lastDelay", /* attribute name */
        (getter) _wrap_PyNs3FlowMonitorFlowStats__get_lastDelay, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowMonitorFlowStats__set_lastDelay, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3FlowMonitorFlowStats__tp_init__0(PyNs3FlowMonitorFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::FlowMonitor::FlowStats();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3FlowMonitorFlowStats__tp_init__1(PyNs3FlowMonitorFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FlowMonitorFlowStats *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowMonitorFlowStats_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FlowMonitor::FlowStats(*((PyNs3FlowMonitorFlowStats *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3FlowMonitorFlowStats__tp_init(PyNs3FlowMonitorFlowStats *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowMonitorFlowStats__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowMonitorFlowStats__tp_init__1(self, args, kwargs, &exceptions[1]);
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


static PyObject*
_wrap_PyNs3FlowMonitorFlowStats__copy__(PyNs3FlowMonitorFlowStats *self)
{

    PyNs3FlowMonitorFlowStats *py_copy;
    py_copy = PyObject_New(PyNs3FlowMonitorFlowStats, &PyNs3FlowMonitorFlowStats_Type);
    py_copy->obj = new ns3::FlowMonitor::FlowStats(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3FlowMonitorFlowStats_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FlowMonitorFlowStats_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FlowMonitorFlowStats__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowMonitorFlowStats__tp_dealloc(PyNs3FlowMonitorFlowStats *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FlowMonitorFlowStats_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FlowMonitorFlowStats_wrapper_registry.end()) {
        PyNs3FlowMonitorFlowStats_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::FlowMonitor::FlowStats *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowMonitorFlowStats__tp_richcompare (PyNs3FlowMonitorFlowStats *PYBINDGEN_UNUSED(self), PyNs3FlowMonitorFlowStats *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowMonitorFlowStats_Type)) {
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

PyTypeObject PyNs3FlowMonitorFlowStats_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.FlowMonitor.FlowStats",            /* tp_name */
    sizeof(PyNs3FlowMonitorFlowStats),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowMonitorFlowStats__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3FlowMonitorFlowStats__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowMonitorFlowStats_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3FlowMonitorFlowStats__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowMonitorFlowStats__tp_init,             /* tp_init */
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
PyNs3FlowProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3FlowProbe__PythonHelper::_wrap_DoInitialize(PyNs3FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3FlowProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3FlowProbe__PythonHelper::_wrap_DoDispose(PyNs3FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3FlowProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class FlowProbe is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3FlowProbe__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FlowProbe *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::FlowProbe::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FlowProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FlowProbe* >(m_pyself)->obj = (ns3::FlowProbe*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FlowProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FlowProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FlowProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3FlowProbe__PythonHelper::GetInstanceTypeId() const
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
PyNs3FlowProbe__PythonHelper::DoInitialize()
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
PyNs3FlowProbe__PythonHelper::NotifyNewAggregate()
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
PyNs3FlowProbe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3FlowProbe__tp_init(PyNs3FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyNs3FlowMonitor *flowMonitor;
    ns3::FlowMonitor *flowMonitor_ptr;
    const char *keywords[] = {"flowMonitor", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowMonitor_Type, &flowMonitor)) {
        return -1;
    }
    flowMonitor_ptr = (flowMonitor ? flowMonitor->obj : NULL);
    if (Py_TYPE(self) != &PyNs3FlowProbe_Type)
    {
        self->obj = new PyNs3FlowProbe__PythonHelper(ns3::Ptr< ns3::FlowMonitor  > (flowMonitor_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FlowProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'protected'
        PyErr_SetString(PyExc_TypeError, "class 'FlowProbe' cannot be constructed");
        return -1;
    }
    return 0;
}


PyObject *
_wrap_PyNs3FlowProbe_AddPacketStats(PyNs3FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    unsigned int packetSize;
    PyNs3Time *delayFromFirstProbe;
    const char *keywords[] = {"flowId", "packetSize", "delayFromFirstProbe", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IIO!", (char **) keywords, &flowId, &packetSize, &PyNs3Time_Type, &delayFromFirstProbe)) {
        return NULL;
    }
    self->obj->AddPacketStats(flowId, packetSize, *((PyNs3Time *) delayFromFirstProbe)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::FlowProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowProbe_AddPacketDropStats(PyNs3FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    unsigned int packetSize;
    unsigned int reasonCode;
    const char *keywords[] = {"flowId", "packetSize", "reasonCode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "III", (char **) keywords, &flowId, &packetSize, &reasonCode)) {
        return NULL;
    }
    self->obj->AddPacketDropStats(flowId, packetSize, reasonCode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FlowProbe_GetStats(PyNs3FlowProbe *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowProbe::FlowStats > retval;
    Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__;
    
    retval = self->obj->GetStats();
    py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ = PyObject_New(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__, &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type);
    py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__->obj = new std::map< unsigned int, ns3::FlowProbe::FlowStats >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__);
    return py_retval;
}

static PyMethodDef PyNs3FlowProbe_methods[] = {
    {(char *) "AddPacketStats", (PyCFunction) _wrap_PyNs3FlowProbe_AddPacketStats, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3FlowProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AddPacketDropStats", (PyCFunction) _wrap_PyNs3FlowProbe_AddPacketDropStats, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetStats", (PyCFunction) _wrap_PyNs3FlowProbe_GetStats, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3FlowProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3FlowProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3FlowProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3FlowProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FlowProbe__tp_clear(PyNs3FlowProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::FlowProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3FlowProbe__tp_traverse(PyNs3FlowProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3FlowProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3FlowProbe__tp_dealloc(PyNs3FlowProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FlowProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowProbe__tp_richcompare (PyNs3FlowProbe *PYBINDGEN_UNUSED(self), PyNs3FlowProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowProbe_Type)) {
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

PyTypeObject PyNs3FlowProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.FlowProbe",            /* tp_name */
    sizeof(PyNs3FlowProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowProbe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3FlowProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FlowProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FlowProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FlowProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowProbe__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3FlowProbeFlowStats_wrapper_registry;
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_bytes(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->bytes);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_bytes(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->bytes)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_bytesDropped(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned long long > retval;
    Pystd__vector__lt___unsigned_long_long___gt__ *py_std__vector__lt___unsigned_long_long___gt__;
    
    py_std__vector__lt___unsigned_long_long___gt__ = PyObject_New(Pystd__vector__lt___unsigned_long_long___gt__, &Pystd__vector__lt___unsigned_long_long___gt___Type);
    py_std__vector__lt___unsigned_long_long___gt__->obj = new std::vector< unsigned long long >(self->obj->bytesDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_long_long___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_bytesDropped(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned long long > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_long_long___gt__, &self->obj->bytesDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_delayFromFirstProbeSum(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->delayFromFirstProbeSum);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_delayFromFirstProbeSum(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->delayFromFirstProbeSum = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_packets(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->packets));
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_packets(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->packets)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3FlowProbeFlowStats__get_packetsDropped(PyNs3FlowProbeFlowStats *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned int > retval;
    Pystd__vector__lt___unsigned_int___gt__ *py_std__vector__lt___unsigned_int___gt__;
    
    py_std__vector__lt___unsigned_int___gt__ = PyObject_New(Pystd__vector__lt___unsigned_int___gt__, &Pystd__vector__lt___unsigned_int___gt___Type);
    py_std__vector__lt___unsigned_int___gt__->obj = new std::vector< unsigned int >(self->obj->packetsDropped);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___unsigned_int___gt__);
    return py_retval;
}
static int _wrap_PyNs3FlowProbeFlowStats__set_packetsDropped(PyNs3FlowProbeFlowStats *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< unsigned int > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__, &self->obj->packetsDropped)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3FlowProbeFlowStats__getsets[] = {
    {
        (char*) "bytesDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_bytesDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_bytesDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "delayFromFirstProbeSum", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_delayFromFirstProbeSum, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_delayFromFirstProbeSum, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "bytes", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_bytes, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_bytes, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packets", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_packets, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_packets, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "packetsDropped", /* attribute name */
        (getter) _wrap_PyNs3FlowProbeFlowStats__get_packetsDropped, /* C function to get the attribute */
        (setter) _wrap_PyNs3FlowProbeFlowStats__set_packetsDropped, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3FlowProbeFlowStats__tp_init__0(PyNs3FlowProbeFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FlowProbeFlowStats *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FlowProbeFlowStats_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FlowProbe::FlowStats(*((PyNs3FlowProbeFlowStats *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3FlowProbeFlowStats__tp_init__1(PyNs3FlowProbeFlowStats *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::FlowProbe::FlowStats();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3FlowProbeFlowStats__tp_init(PyNs3FlowProbeFlowStats *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FlowProbeFlowStats__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FlowProbeFlowStats__tp_init__1(self, args, kwargs, &exceptions[1]);
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


static PyObject*
_wrap_PyNs3FlowProbeFlowStats__copy__(PyNs3FlowProbeFlowStats *self)
{

    PyNs3FlowProbeFlowStats *py_copy;
    py_copy = PyObject_New(PyNs3FlowProbeFlowStats, &PyNs3FlowProbeFlowStats_Type);
    py_copy->obj = new ns3::FlowProbe::FlowStats(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3FlowProbeFlowStats_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FlowProbeFlowStats_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FlowProbeFlowStats__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FlowProbeFlowStats__tp_dealloc(PyNs3FlowProbeFlowStats *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FlowProbeFlowStats_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FlowProbeFlowStats_wrapper_registry.end()) {
        PyNs3FlowProbeFlowStats_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::FlowProbe::FlowStats *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FlowProbeFlowStats__tp_richcompare (PyNs3FlowProbeFlowStats *PYBINDGEN_UNUSED(self), PyNs3FlowProbeFlowStats *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FlowProbeFlowStats_Type)) {
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

PyTypeObject PyNs3FlowProbeFlowStats_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.FlowProbe.FlowStats",            /* tp_name */
    sizeof(PyNs3FlowProbeFlowStats),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FlowProbeFlowStats__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3FlowProbeFlowStats__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FlowProbeFlowStats_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3FlowProbeFlowStats__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FlowProbeFlowStats__tp_init,             /* tp_init */
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
_wrap_PyNs3Ipv4FlowClassifier__tp_init(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::Ipv4FlowClassifier();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3Ipv4FlowClassifier_FindFlow(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    const char *keywords[] = {"flowId", NULL};
    PyNs3Ipv4FlowClassifierFiveTuple *py_FiveTuple;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &flowId)) {
        return NULL;
    }
    ns3::Ipv4FlowClassifier::FiveTuple retval = self->obj->FindFlow(flowId);
    py_FiveTuple = PyObject_New(PyNs3Ipv4FlowClassifierFiveTuple, &PyNs3Ipv4FlowClassifierFiveTuple_Type);
    py_FiveTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FiveTuple->obj = new ns3::Ipv4FlowClassifier::FiveTuple(retval);
    PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry[(void *) py_FiveTuple->obj] = (PyObject *) py_FiveTuple;
    py_retval = Py_BuildValue((char *) "N", py_FiveTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv4FlowClassifier_Classify(PyNs3Ipv4FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Header *ipHeader;
    PyNs3Packet *ipPayload;
    ns3::Packet *ipPayload_ptr;
    uint32_t out_flowId;
    uint32_t out_packetId;
    const char *keywords[] = {"ipHeader", "ipPayload", "out_flowId", "out_packetId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!II", (char **) keywords, &PyNs3Ipv4Header_Type, &ipHeader, &PyNs3Packet_Type, &ipPayload, &out_flowId, &out_packetId)) {
        return NULL;
    }
    ipPayload_ptr = (ipPayload ? ipPayload->obj : NULL);
    retval = self->obj->Classify(*((PyNs3Ipv4Header *) ipHeader)->obj, ns3::Ptr< ns3::Packet  > (ipPayload_ptr), &out_flowId, &out_packetId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3Ipv4FlowClassifier_methods[] = {
    {(char *) "FindFlow", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifier_FindFlow, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Classify", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifier_Classify, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4FlowClassifier__tp_dealloc(PyNs3Ipv4FlowClassifier *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::Ipv4FlowClassifier *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4FlowClassifier__tp_richcompare (PyNs3Ipv4FlowClassifier *PYBINDGEN_UNUSED(self), PyNs3Ipv4FlowClassifier *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4FlowClassifier_Type)) {
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

PyTypeObject PyNs3Ipv4FlowClassifier_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Ipv4FlowClassifier",            /* tp_name */
    sizeof(PyNs3Ipv4FlowClassifier),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4FlowClassifier__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Ipv4FlowClassifier__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4FlowClassifier_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4FlowClassifier__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry;
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->destinationAddress);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destinationAddress = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationPort(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->destinationPort);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationPort(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destinationPort = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_protocol(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->protocol);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_protocol(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->protocol = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourceAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->sourceAddress);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourceAddress(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->sourceAddress = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourcePort(PyNs3Ipv4FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sourcePort);
    return py_retval;
}
static int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourcePort(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->sourcePort = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Ipv4FlowClassifierFiveTuple__getsets[] = {
    {
        (char*) "sourcePort", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourcePort, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourcePort, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sourceAddress", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_sourceAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_sourceAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destinationAddress", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "protocol", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_protocol, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_protocol, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destinationPort", /* attribute name */
        (getter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__get_destinationPort, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__set_destinationPort, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__0(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv4FlowClassifier::FiveTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__1(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4FlowClassifierFiveTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4FlowClassifierFiveTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv4FlowClassifier::FiveTuple(*((PyNs3Ipv4FlowClassifierFiveTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init(PyNs3Ipv4FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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


static PyObject*
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__copy__(PyNs3Ipv4FlowClassifierFiveTuple *self)
{

    PyNs3Ipv4FlowClassifierFiveTuple *py_copy;
    py_copy = PyObject_New(PyNs3Ipv4FlowClassifierFiveTuple, &PyNs3Ipv4FlowClassifierFiveTuple_Type);
    py_copy->obj = new ns3::Ipv4FlowClassifier::FiveTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv4FlowClassifierFiveTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv4FlowClassifierFiveTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_dealloc(PyNs3Ipv4FlowClassifierFiveTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry.end()) {
        PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv4FlowClassifier::FiveTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_richcompare (PyNs3Ipv4FlowClassifierFiveTuple *PYBINDGEN_UNUSED(self), PyNs3Ipv4FlowClassifierFiveTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4FlowClassifierFiveTuple_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        if (*self->obj < *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        if (*self->obj == *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
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

PyTypeObject PyNs3Ipv4FlowClassifierFiveTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Ipv4FlowClassifier.FiveTuple",            /* tp_name */
    sizeof(PyNs3Ipv4FlowClassifierFiveTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4FlowClassifierFiveTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Ipv4FlowClassifierFiveTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4FlowClassifierFiveTuple__tp_init,             /* tp_init */
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
PyNs3Ipv4FlowProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Ipv4FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv4FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv4FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3Ipv4FlowProbe__PythonHelper::_wrap_DoInitialize(PyNs3Ipv4FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv4FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv4FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3Ipv4FlowProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Ipv4FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv4FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv4FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3Ipv4FlowProbe__PythonHelper::_wrap_DoDispose(PyNs3Ipv4FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv4FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv4FlowProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Ipv4FlowProbe is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3Ipv4FlowProbe__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Ipv4FlowProbe *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Ipv4FlowProbe::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Ipv4FlowProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Ipv4FlowProbe* >(m_pyself)->obj = (ns3::Ipv4FlowProbe*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Ipv4FlowProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Ipv4FlowProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Ipv4FlowProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3Ipv4FlowProbe__PythonHelper::GetInstanceTypeId() const
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
PyNs3Ipv4FlowProbe__PythonHelper::DoInitialize()
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
PyNs3Ipv4FlowProbe__PythonHelper::NotifyNewAggregate()
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
PyNs3Ipv4FlowProbe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Ipv4FlowProbe__tp_init(PyNs3Ipv4FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyNs3FlowMonitor *monitor;
    ns3::FlowMonitor *monitor_ptr;
    PyNs3Ipv4FlowClassifier *classifier;
    ns3::Ipv4FlowClassifier *classifier_ptr;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"monitor", "classifier", "node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!", (char **) keywords, &PyNs3FlowMonitor_Type, &monitor, &PyNs3Ipv4FlowClassifier_Type, &classifier, &PyNs3Node_Type, &node)) {
        return -1;
    }
    monitor_ptr = (monitor ? monitor->obj : NULL);
    classifier_ptr = (classifier ? classifier->obj : NULL);
    node_ptr = (node ? node->obj : NULL);
    if (Py_TYPE(self) != &PyNs3Ipv4FlowProbe_Type)
    {
        self->obj = new PyNs3Ipv4FlowProbe__PythonHelper(ns3::Ptr< ns3::FlowMonitor  > (monitor_ptr), ns3::Ptr< ns3::Ipv4FlowClassifier  > (classifier_ptr), ns3::Ptr< ns3::Node  > (node_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Ipv4FlowProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Ipv4FlowProbe(ns3::Ptr< ns3::FlowMonitor  > (monitor_ptr), ns3::Ptr< ns3::Ipv4FlowClassifier  > (classifier_ptr), ns3::Ptr< ns3::Node  > (node_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3Ipv4FlowProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv4FlowProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3Ipv4FlowProbe_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv4FlowProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Ipv4FlowProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Ipv4FlowProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Ipv4FlowProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Ipv4FlowProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv4FlowProbe__tp_clear(PyNs3Ipv4FlowProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv4FlowProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv4FlowProbe__tp_traverse(PyNs3Ipv4FlowProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Ipv4FlowProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Ipv4FlowProbe__tp_dealloc(PyNs3Ipv4FlowProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv4FlowProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv4FlowProbe__tp_richcompare (PyNs3Ipv4FlowProbe *PYBINDGEN_UNUSED(self), PyNs3Ipv4FlowProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv4FlowProbe_Type)) {
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

PyTypeObject PyNs3Ipv4FlowProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Ipv4FlowProbe",            /* tp_name */
    sizeof(PyNs3Ipv4FlowProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv4FlowProbe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv4FlowProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv4FlowProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv4FlowProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv4FlowProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv4FlowProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv4FlowProbe__tp_init,             /* tp_init */
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
_wrap_PyNs3Ipv6FlowClassifier__tp_init(PyNs3Ipv6FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::Ipv6FlowClassifier();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3Ipv6FlowClassifier_FindFlow(PyNs3Ipv6FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowId;
    const char *keywords[] = {"flowId", NULL};
    PyNs3Ipv6FlowClassifierFiveTuple *py_FiveTuple;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &flowId)) {
        return NULL;
    }
    ns3::Ipv6FlowClassifier::FiveTuple retval = self->obj->FindFlow(flowId);
    py_FiveTuple = PyObject_New(PyNs3Ipv6FlowClassifierFiveTuple, &PyNs3Ipv6FlowClassifierFiveTuple_Type);
    py_FiveTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FiveTuple->obj = new ns3::Ipv6FlowClassifier::FiveTuple(retval);
    PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry[(void *) py_FiveTuple->obj] = (PyObject *) py_FiveTuple;
    py_retval = Py_BuildValue((char *) "N", py_FiveTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3Ipv6FlowClassifier_Classify(PyNs3Ipv6FlowClassifier *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv6Header *ipHeader;
    PyNs3Packet *ipPayload;
    ns3::Packet *ipPayload_ptr;
    uint32_t out_flowId;
    uint32_t out_packetId;
    const char *keywords[] = {"ipHeader", "ipPayload", "out_flowId", "out_packetId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!II", (char **) keywords, &PyNs3Ipv6Header_Type, &ipHeader, &PyNs3Packet_Type, &ipPayload, &out_flowId, &out_packetId)) {
        return NULL;
    }
    ipPayload_ptr = (ipPayload ? ipPayload->obj : NULL);
    retval = self->obj->Classify(*((PyNs3Ipv6Header *) ipHeader)->obj, ns3::Ptr< ns3::Packet  > (ipPayload_ptr), &out_flowId, &out_packetId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

static PyMethodDef PyNs3Ipv6FlowClassifier_methods[] = {
    {(char *) "FindFlow", (PyCFunction) _wrap_PyNs3Ipv6FlowClassifier_FindFlow, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Classify", (PyCFunction) _wrap_PyNs3Ipv6FlowClassifier_Classify, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv6FlowClassifier__tp_dealloc(PyNs3Ipv6FlowClassifier *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::Ipv6FlowClassifier *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv6FlowClassifier__tp_richcompare (PyNs3Ipv6FlowClassifier *PYBINDGEN_UNUSED(self), PyNs3Ipv6FlowClassifier *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6FlowClassifier_Type)) {
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

PyTypeObject PyNs3Ipv6FlowClassifier_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Ipv6FlowClassifier",            /* tp_name */
    sizeof(PyNs3Ipv6FlowClassifier),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6FlowClassifier__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Ipv6FlowClassifier__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6FlowClassifier_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6FlowClassifier__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry;
static PyObject* _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_destinationAddress(PyNs3Ipv6FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(self->obj->destinationAddress);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}
static int _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_destinationAddress(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv6Address *tmp_Ipv6Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv6Address_Type, &tmp_Ipv6Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destinationAddress = *tmp_Ipv6Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_destinationPort(PyNs3Ipv6FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->destinationPort);
    return py_retval;
}
static int _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_destinationPort(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destinationPort = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_protocol(PyNs3Ipv6FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->protocol);
    return py_retval;
}
static int _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_protocol(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->protocol = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_sourceAddress(PyNs3Ipv6FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(self->obj->sourceAddress);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}
static int _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_sourceAddress(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv6Address *tmp_Ipv6Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv6Address_Type, &tmp_Ipv6Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->sourceAddress = *tmp_Ipv6Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_sourcePort(PyNs3Ipv6FlowClassifierFiveTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sourcePort);
    return py_retval;
}
static int _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_sourcePort(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    int tmp;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &tmp)) {
        Py_DECREF(py_retval);
        return -1;
    }
    if (tmp > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->sourcePort = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Ipv6FlowClassifierFiveTuple__getsets[] = {
    {
        (char*) "sourcePort", /* attribute name */
        (getter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_sourcePort, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_sourcePort, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sourceAddress", /* attribute name */
        (getter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_sourceAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_sourceAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destinationAddress", /* attribute name */
        (getter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_destinationAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_destinationAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "protocol", /* attribute name */
        (getter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_protocol, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_protocol, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destinationPort", /* attribute name */
        (getter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__get_destinationPort, /* C function to get the attribute */
        (setter) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__set_destinationPort, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_init__0(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Ipv6FlowClassifier::FiveTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_init__1(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv6FlowClassifierFiveTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6FlowClassifierFiveTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ipv6FlowClassifier::FiveTuple(*((PyNs3Ipv6FlowClassifierFiveTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_init(PyNs3Ipv6FlowClassifierFiveTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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


static PyObject*
_wrap_PyNs3Ipv6FlowClassifierFiveTuple__copy__(PyNs3Ipv6FlowClassifierFiveTuple *self)
{

    PyNs3Ipv6FlowClassifierFiveTuple *py_copy;
    py_copy = PyObject_New(PyNs3Ipv6FlowClassifierFiveTuple, &PyNs3Ipv6FlowClassifierFiveTuple_Type);
    py_copy->obj = new ns3::Ipv6FlowClassifier::FiveTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ipv6FlowClassifierFiveTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ipv6FlowClassifierFiveTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_dealloc(PyNs3Ipv6FlowClassifierFiveTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry.end()) {
        PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ipv6FlowClassifier::FiveTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_richcompare (PyNs3Ipv6FlowClassifierFiveTuple *PYBINDGEN_UNUSED(self), PyNs3Ipv6FlowClassifierFiveTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6FlowClassifierFiveTuple_Type)) {
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    }
    switch (opid)
    {
    case Py_LT:
        if (*self->obj < *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
    case Py_LE:
        Py_INCREF(Py_NotImplemented);
        return Py_NotImplemented;
    case Py_EQ:
        if (*self->obj == *other->obj) {
            Py_INCREF(Py_True);
            return Py_True;
        } else {
            Py_INCREF(Py_False);
            return Py_False;
        }
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

PyTypeObject PyNs3Ipv6FlowClassifierFiveTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Ipv6FlowClassifier.FiveTuple",            /* tp_name */
    sizeof(PyNs3Ipv6FlowClassifierFiveTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6FlowClassifierFiveTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Ipv6FlowClassifierFiveTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6FlowClassifierFiveTuple__tp_init,             /* tp_init */
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
PyNs3Ipv6FlowProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Ipv6FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv6FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv6FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3Ipv6FlowProbe__PythonHelper::_wrap_DoInitialize(PyNs3Ipv6FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv6FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv6FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3Ipv6FlowProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Ipv6FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv6FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv6FlowProbe__PythonHelper* >(self->obj);
    
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
PyNs3Ipv6FlowProbe__PythonHelper::_wrap_DoDispose(PyNs3Ipv6FlowProbe *self)
{
    PyObject *py_retval;
    PyNs3Ipv6FlowProbe__PythonHelper *helper = dynamic_cast< PyNs3Ipv6FlowProbe__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Ipv6FlowProbe is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3Ipv6FlowProbe__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Ipv6FlowProbe *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Ipv6FlowProbe::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Ipv6FlowProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Ipv6FlowProbe* >(m_pyself)->obj = (ns3::Ipv6FlowProbe*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Ipv6FlowProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Ipv6FlowProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Ipv6FlowProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3Ipv6FlowProbe__PythonHelper::GetInstanceTypeId() const
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
PyNs3Ipv6FlowProbe__PythonHelper::DoInitialize()
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
PyNs3Ipv6FlowProbe__PythonHelper::NotifyNewAggregate()
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
PyNs3Ipv6FlowProbe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Ipv6FlowProbe__tp_init(PyNs3Ipv6FlowProbe *self, PyObject *args, PyObject *kwargs)
{
    PyNs3FlowMonitor *monitor;
    ns3::FlowMonitor *monitor_ptr;
    PyNs3Ipv6FlowClassifier *classifier;
    ns3::Ipv6FlowClassifier *classifier_ptr;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"monitor", "classifier", "node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!", (char **) keywords, &PyNs3FlowMonitor_Type, &monitor, &PyNs3Ipv6FlowClassifier_Type, &classifier, &PyNs3Node_Type, &node)) {
        return -1;
    }
    monitor_ptr = (monitor ? monitor->obj : NULL);
    classifier_ptr = (classifier ? classifier->obj : NULL);
    node_ptr = (node ? node->obj : NULL);
    if (Py_TYPE(self) != &PyNs3Ipv6FlowProbe_Type)
    {
        self->obj = new PyNs3Ipv6FlowProbe__PythonHelper(ns3::Ptr< ns3::FlowMonitor  > (monitor_ptr), ns3::Ptr< ns3::Ipv6FlowClassifier  > (classifier_ptr), ns3::Ptr< ns3::Node  > (node_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Ipv6FlowProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Ipv6FlowProbe(ns3::Ptr< ns3::FlowMonitor  > (monitor_ptr), ns3::Ptr< ns3::Ipv6FlowClassifier  > (classifier_ptr), ns3::Ptr< ns3::Node  > (node_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3Ipv6FlowProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Ipv6FlowProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3Ipv6FlowProbe_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Ipv6FlowProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Ipv6FlowProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Ipv6FlowProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Ipv6FlowProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Ipv6FlowProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Ipv6FlowProbe__tp_clear(PyNs3Ipv6FlowProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Ipv6FlowProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Ipv6FlowProbe__tp_traverse(PyNs3Ipv6FlowProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Ipv6FlowProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Ipv6FlowProbe__tp_dealloc(PyNs3Ipv6FlowProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Ipv6FlowProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ipv6FlowProbe__tp_richcompare (PyNs3Ipv6FlowProbe *PYBINDGEN_UNUSED(self), PyNs3Ipv6FlowProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ipv6FlowProbe_Type)) {
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

PyTypeObject PyNs3Ipv6FlowProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Ipv6FlowProbe",            /* tp_name */
    sizeof(PyNs3Ipv6FlowProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ipv6FlowProbe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Ipv6FlowProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Ipv6FlowProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Ipv6FlowProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ipv6FlowProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Ipv6FlowProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ipv6FlowProbe__tp_init,             /* tp_init */
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
Pystd__vector__lt___unsigned_int___gt__Iter__tp_clear(Pystd__vector__lt___unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___unsigned_int___gt__Iter__tp_traverse(Pystd__vector__lt___unsigned_int___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___unsigned_int___gt____tp_dealloc(Pystd__vector__lt___unsigned_int___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___unsigned_int___gt__Iter__tp_dealloc(Pystd__vector__lt___unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___unsigned_int___gt____tp_iter(Pystd__vector__lt___unsigned_int___gt__ *self)
{
    Pystd__vector__lt___unsigned_int___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___unsigned_int___gt__Iter, &Pystd__vector__lt___unsigned_int___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< unsigned int >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___unsigned_int___gt__Iter__tp_iter(Pystd__vector__lt___unsigned_int___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___unsigned_int___gt__Iter__tp_iternext(Pystd__vector__lt___unsigned_int___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< unsigned int >::iterator iter;
    
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


int _wrap_convert_py2c__std__vector__lt___unsigned_int___gt__(PyObject *arg, std::vector< unsigned int > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___unsigned_int___gt___Type)) {
        *container = *((Pystd__vector__lt___unsigned_int___gt__*)arg)->obj;
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
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___unsigned_int___gt__ instance, or a list of unsigned int");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___unsigned_int___gt____tp_init(Pystd__vector__lt___unsigned_int___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< unsigned int >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___unsigned_int___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___unsigned_int___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__vector__lt___unsigned_int___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___unsigned_int___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___unsigned_int___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___unsigned_int___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___unsigned_int___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___unsigned_int___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__vector__lt___unsigned_int___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___unsigned_int___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___unsigned_int___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___unsigned_int___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___unsigned_int___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___unsigned_int___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___unsigned_int___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_clear(Pystd__vector__lt___unsigned_long_long___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_traverse(Pystd__vector__lt___unsigned_long_long___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___unsigned_long_long___gt____tp_dealloc(Pystd__vector__lt___unsigned_long_long___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_dealloc(Pystd__vector__lt___unsigned_long_long___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___unsigned_long_long___gt____tp_iter(Pystd__vector__lt___unsigned_long_long___gt__ *self)
{
    Pystd__vector__lt___unsigned_long_long___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___unsigned_long_long___gt__Iter, &Pystd__vector__lt___unsigned_long_long___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< unsigned long long >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_iter(Pystd__vector__lt___unsigned_long_long___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_iternext(Pystd__vector__lt___unsigned_long_long___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< unsigned long long >::iterator iter;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_retval = Py_BuildValue((char *) "K", (*iter));
    return py_retval;
}

int _wrap_convert_py2c__long_long_unsigned_int(PyObject *value, long long unsigned int *address)
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &*address)) {
        Py_DECREF(py_retval);
        return 0;
    }
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___unsigned_long_long___gt__(PyObject *arg, std::vector< unsigned long long > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___unsigned_long_long___gt___Type)) {
        *container = *((Pystd__vector__lt___unsigned_long_long___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            long long unsigned int item;
            if (!_wrap_convert_py2c__long_long_unsigned_int(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___unsigned_long_long___gt__ instance, or a list of long long unsigned int");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___unsigned_long_long___gt____tp_init(Pystd__vector__lt___unsigned_long_long___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< unsigned long long >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___unsigned_long_long___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___unsigned_long_long___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__vector__lt___unsigned_long_long___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___unsigned_long_long___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___unsigned_long_long___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___unsigned_long_long___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___unsigned_long_long___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___unsigned_long_long___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__vector__lt___unsigned_long_long___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___unsigned_long_long___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___unsigned_long_long___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_clear(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_traverse(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *self)
{
    Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *iter = PyObject_GC_New(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter, &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::map< unsigned int, ns3::FlowMonitor::FlowStats >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iternext(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowMonitor::FlowStats >::iterator iter;
    PyNs3FlowMonitorFlowStats *py_FlowStats;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_FlowStats = PyObject_New(PyNs3FlowMonitorFlowStats, &PyNs3FlowMonitorFlowStats_Type);
    py_FlowStats->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FlowStats->obj = new ns3::FlowMonitor::FlowStats(iter->second);
    PyNs3FlowMonitorFlowStats_wrapper_registry[(void *) py_FlowStats->obj] = (PyObject *) py_FlowStats;
    py_retval = Py_BuildValue((char *) "NN", PyLong_FromUnsignedLong(iter->first), py_FlowStats);
    return py_retval;
}

int _wrap_convert_py2c__ns3__FlowMonitor__FlowStats(PyObject *value, ns3::FlowMonitor::FlowStats *address)
{
    PyObject *py_retval;
    PyNs3FlowMonitorFlowStats *tmp_FlowStats;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3FlowMonitorFlowStats_Type, &tmp_FlowStats)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_FlowStats->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__(PyObject *arg, std::map< unsigned int, ns3::FlowMonitor::FlowStats > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type)) {
        *container = *((Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *tup = PyList_GET_ITEM(arg, i);
            if (!PyTuple_Check(tup) || PyTuple_Size(tup) != 2) {
                PyErr_SetString(PyExc_TypeError, "items must be tuples with two elements");
                return 0;
            }
            std::pair< unsigned int, ns3::FlowMonitor::FlowStats > item;
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 0), &item.first)) {
                return 0;
            }
            if (!_wrap_convert_py2c__ns3__FlowMonitor__FlowStats(PyTuple_GET_ITEM(tup, 1), &item.second)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ instance, or a list of ns3::FlowMonitor::FlowStats");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_init(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::map< unsigned int, ns3::FlowMonitor::FlowStats >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_clear(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_traverse(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt____tp_dealloc(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt____tp_iter(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__ *self)
{
    Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter, &Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::Ptr< ns3::FlowProbe > >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_iter(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_iternext(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::Ptr< ns3::FlowProbe > >::iterator iter;
    PyNs3FlowProbe *py_FlowProbe;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    if (!(const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter))))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter))))).name() == typeid(PyNs3FlowProbe__PythonHelper).name())
    {
        py_FlowProbe = reinterpret_cast< PyNs3FlowProbe* >(reinterpret_cast< PyNs3FlowProbe__PythonHelper* >(const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter))))->m_pyself);
        py_FlowProbe->obj = const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter)));
        Py_INCREF(py_FlowProbe);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter))));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_FlowProbe = NULL;
        } else {
            py_FlowProbe = (PyNs3FlowProbe *) wrapper_lookup_iter->second;
            Py_INCREF(py_FlowProbe);
        }
    
        if (py_FlowProbe == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter))))), &PyNs3FlowProbe_Type);
            py_FlowProbe = PyObject_GC_New(PyNs3FlowProbe, wrapper_type);
            py_FlowProbe->inst_dict = NULL;
    
            py_FlowProbe->inst_dict = NULL;
            py_FlowProbe->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter)))->Ref();
            py_FlowProbe->obj = const_cast<ns3::FlowProbe *> (ns3::PeekPointer ((*iter)));
            PyNs3ObjectBase_wrapper_registry[(void *) py_FlowProbe->obj] = (PyObject *) py_FlowProbe;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_FlowProbe);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Ptr__lt___ns3__FlowProbe___gt__(PyObject *value, ns3::Ptr< ns3::FlowProbe > *address)
{
    PyObject *py_retval;
    PyNs3FlowProbe *tmp_FlowProbe;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3FlowProbe_Type, &tmp_FlowProbe)) {
        Py_DECREF(py_retval);
        return 0;
    }
    // dangerous!
    *address = ns3::Ptr< ns3::FlowProbe  > (tmp_FlowProbe->obj);
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__(PyObject *arg, std::vector< ns3::Ptr< ns3::FlowProbe > > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ptr< ns3::FlowProbe > item;
            if (!_wrap_convert_py2c__ns3__Ptr__lt___ns3__FlowProbe___gt__(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__ instance, or a list of ns3::Ptr< ns3::FlowProbe >");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt____tp_init(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::Ptr< ns3::FlowProbe > >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_clear(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_traverse(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_dealloc(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *self)
{
    Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *iter = PyObject_GC_New(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter, &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::map< unsigned int, ns3::FlowProbe::FlowStats >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iter(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iternext(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter *self)
{
    PyObject *py_retval;
    std::map< unsigned int, ns3::FlowProbe::FlowStats >::iterator iter;
    PyNs3FlowProbeFlowStats *py_FlowStats;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_FlowStats = PyObject_New(PyNs3FlowProbeFlowStats, &PyNs3FlowProbeFlowStats_Type);
    py_FlowStats->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_FlowStats->obj = new ns3::FlowProbe::FlowStats(iter->second);
    PyNs3FlowProbeFlowStats_wrapper_registry[(void *) py_FlowStats->obj] = (PyObject *) py_FlowStats;
    py_retval = Py_BuildValue((char *) "NN", PyLong_FromUnsignedLong(iter->first), py_FlowStats);
    return py_retval;
}

int _wrap_convert_py2c__ns3__FlowProbe__FlowStats(PyObject *value, ns3::FlowProbe::FlowStats *address)
{
    PyObject *py_retval;
    PyNs3FlowProbeFlowStats *tmp_FlowStats;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3FlowProbeFlowStats_Type, &tmp_FlowStats)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_FlowStats->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__(PyObject *arg, std::map< unsigned int, ns3::FlowProbe::FlowStats > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type)) {
        *container = *((Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *tup = PyList_GET_ITEM(arg, i);
            if (!PyTuple_Check(tup) || PyTuple_Size(tup) != 2) {
                PyErr_SetString(PyExc_TypeError, "items must be tuples with two elements");
                return 0;
            }
            std::pair< unsigned int, ns3::FlowProbe::FlowStats > item;
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 0), &item.first)) {
                return 0;
            }
            if (!_wrap_convert_py2c__ns3__FlowProbe__FlowStats(PyTuple_GET_ITEM(tup, 1), &item.second)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ instance, or a list of ns3::FlowProbe::FlowStats");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_init(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::map< unsigned int, ns3::FlowProbe::FlowStats >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "flow_monitor.Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter",            /* tp_name */
    sizeof(Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter__tp_iternext,     /* tp_iternext */
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
    (char *) "flow_monitor.Std__map__lt___unsigned_int__unsigned_int___gt__",            /* tp_name */
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
    (char *) "flow_monitor.Std__map__lt___unsigned_int__unsigned_int___gt__Iter",            /* tp_name */
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
static struct PyModuleDef flow_monitor_moduledef = {
    PyModuleDef_HEAD_INIT,
    "flow_monitor",
    NULL,
    -1,
    flow_monitor_functions,
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


MOD_INIT(flow_monitor)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&flow_monitor_moduledef);
    #else
    m = Py_InitModule3((char *) "flow_monitor", flow_monitor_functions, NULL);
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
    PyModule_AddObject(m, (char *) "_PyNs3FlowMonitorHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3FlowMonitorHelper_wrapper_registry, NULL));
    /* Register the 'ns3::FlowMonitorHelper' class */
    if (PyType_Ready(&PyNs3FlowMonitorHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FlowMonitorHelper", (PyObject *) &PyNs3FlowMonitorHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Histogram_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Histogram_wrapper_registry, NULL));
    /* Register the 'ns3::Histogram' class */
    if (PyType_Ready(&PyNs3Histogram_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Histogram", (PyObject *) &PyNs3Histogram_Type);
    PyModule_AddObject(m, (char *) "_PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map", PyCObject_FromVoidPtr(&PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map, NULL));
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map.register_wrapper(typeid(ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >), &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type);
    /* Register the 'ns3::SimpleRefCount< ns3::FlowClassifier, ns3::empty, ns3::DefaultDeleter<ns3::FlowClassifier> >' class */
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type.tp_base = &PyNs3Empty_Type;
    if (PyType_Ready(&PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt__", (PyObject *) &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type);
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map.register_wrapper(typeid(ns3::FlowClassifier), &PyNs3FlowClassifier_Type);
    /* Register the 'ns3::FlowClassifier' class */
    PyNs3FlowClassifier_Type.tp_base = &PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt___Type;
    if (PyType_Ready(&PyNs3FlowClassifier_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FlowClassifier", (PyObject *) &PyNs3FlowClassifier_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::FlowMonitor), &PyNs3FlowMonitor_Type);
    /* Register the 'ns3::FlowMonitor' class */
    PyNs3FlowMonitor_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3FlowMonitor_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FlowMonitor", (PyObject *) &PyNs3FlowMonitor_Type);
    PyModule_AddObject(m, (char *) "_PyNs3FlowMonitorFlowStats_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3FlowMonitorFlowStats_wrapper_registry, NULL));
    /* Register the 'ns3::FlowMonitor::FlowStats' class */
    if (PyType_Ready(&PyNs3FlowMonitorFlowStats_Type)) {
        return MOD_ERROR;
    }
    PyDict_SetItemString((PyObject*) PyNs3FlowMonitor_Type.tp_dict, (char *) "FlowStats", (PyObject *) &PyNs3FlowMonitorFlowStats_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::FlowProbe), &PyNs3FlowProbe_Type);
    /* Register the 'ns3::FlowProbe' class */
    PyNs3FlowProbe_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3FlowProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FlowProbe", (PyObject *) &PyNs3FlowProbe_Type);
    PyModule_AddObject(m, (char *) "_PyNs3FlowProbeFlowStats_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3FlowProbeFlowStats_wrapper_registry, NULL));
    /* Register the 'ns3::FlowProbe::FlowStats' class */
    if (PyType_Ready(&PyNs3FlowProbeFlowStats_Type)) {
        return MOD_ERROR;
    }
    PyDict_SetItemString((PyObject*) PyNs3FlowProbe_Type.tp_dict, (char *) "FlowStats", (PyObject *) &PyNs3FlowProbeFlowStats_Type);
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map.register_wrapper(typeid(ns3::Ipv4FlowClassifier), &PyNs3Ipv4FlowClassifier_Type);
    /* Register the 'ns3::Ipv4FlowClassifier' class */
    PyNs3Ipv4FlowClassifier_Type.tp_base = &PyNs3FlowClassifier_Type;
    if (PyType_Ready(&PyNs3Ipv4FlowClassifier_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ipv4FlowClassifier", (PyObject *) &PyNs3Ipv4FlowClassifier_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Ipv4FlowClassifierFiveTuple_wrapper_registry, NULL));
    /* Register the 'ns3::Ipv4FlowClassifier::FiveTuple' class */
    if (PyType_Ready(&PyNs3Ipv4FlowClassifierFiveTuple_Type)) {
        return MOD_ERROR;
    }
    PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowClassifier_Type.tp_dict, (char *) "FiveTuple", (PyObject *) &PyNs3Ipv4FlowClassifierFiveTuple_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Ipv4FlowProbe), &PyNs3Ipv4FlowProbe_Type);
    /* Register the 'ns3::Ipv4FlowProbe' class */
    PyNs3Ipv4FlowProbe_Type.tp_base = &PyNs3FlowProbe_Type;
    if (PyType_Ready(&PyNs3Ipv4FlowProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ipv4FlowProbe", (PyObject *) &PyNs3Ipv4FlowProbe_Type);
    PyNs3SimpleRefCount__Ns3FlowClassifier_Ns3Empty_Ns3DefaultDeleter__lt__ns3FlowClassifier__gt____typeid_map.register_wrapper(typeid(ns3::Ipv6FlowClassifier), &PyNs3Ipv6FlowClassifier_Type);
    /* Register the 'ns3::Ipv6FlowClassifier' class */
    PyNs3Ipv6FlowClassifier_Type.tp_base = &PyNs3FlowClassifier_Type;
    if (PyType_Ready(&PyNs3Ipv6FlowClassifier_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ipv6FlowClassifier", (PyObject *) &PyNs3Ipv6FlowClassifier_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Ipv6FlowClassifierFiveTuple_wrapper_registry, NULL));
    /* Register the 'ns3::Ipv6FlowClassifier::FiveTuple' class */
    if (PyType_Ready(&PyNs3Ipv6FlowClassifierFiveTuple_Type)) {
        return MOD_ERROR;
    }
    PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowClassifier_Type.tp_dict, (char *) "FiveTuple", (PyObject *) &PyNs3Ipv6FlowClassifierFiveTuple_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Ipv6FlowProbe), &PyNs3Ipv6FlowProbe_Type);
    /* Register the 'ns3::Ipv6FlowProbe' class */
    PyNs3Ipv6FlowProbe_Type.tp_base = &PyNs3FlowProbe_Type;
    if (PyType_Ready(&PyNs3Ipv6FlowProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ipv6FlowProbe", (PyObject *) &PyNs3Ipv6FlowProbe_Type);
    /* Register the 'std::vector< unsigned int >' class */
    if (PyType_Ready(&Pystd__vector__lt___unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__vector__lt___unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___unsigned_int___gt__", (PyObject *) &Pystd__vector__lt___unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___unsigned_int___gt__Iter", (PyObject *) &Pystd__vector__lt___unsigned_int___gt__Iter_Type);
    /* Register the 'std::vector< unsigned long long >' class */
    if (PyType_Ready(&Pystd__vector__lt___unsigned_long_long___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__vector__lt___unsigned_long_long___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___unsigned_long_long___gt__", (PyObject *) &Pystd__vector__lt___unsigned_long_long___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___unsigned_long_long___gt__Iter", (PyObject *) &Pystd__vector__lt___unsigned_long_long___gt__Iter_Type);
    /* Register the 'std::map< unsigned int, ns3::FlowMonitor::FlowStats >' class */
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__", (PyObject *) &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter", (PyObject *) &Pystd__map__lt___unsigned_int__ns3__FlowMonitor__FlowStats___gt__Iter_Type);
    /* Register the 'std::vector< ns3::Ptr< ns3::FlowProbe > >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__", (PyObject *) &Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__Ptr__lt___ns3__FlowProbe___gt_____gt__Iter_Type);
    /* Register the 'std::map< unsigned int, ns3::FlowProbe::FlowStats >' class */
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__", (PyObject *) &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter", (PyObject *) &Pystd__map__lt___unsigned_int__ns3__FlowProbe__FlowStats___gt__Iter_Type);
    /* Register the 'std::map< unsigned int, unsigned int >' class */
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__Iter", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type);
    {
        PyObject *tmp_value;
         // ns3::Ipv4FlowProbe::DROP_NO_ROUTE
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_NO_ROUTE);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_NO_ROUTE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_TTL_EXPIRE
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_TTL_EXPIRE);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_TTL_EXPIRE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_BAD_CHECKSUM
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_BAD_CHECKSUM);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_BAD_CHECKSUM", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_QUEUE
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_QUEUE);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_QUEUE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_INTERFACE_DOWN
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_INTERFACE_DOWN);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_INTERFACE_DOWN", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_ROUTE_ERROR
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_ROUTE_ERROR);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_ROUTE_ERROR", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_FRAGMENT_TIMEOUT
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_FRAGMENT_TIMEOUT);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_FRAGMENT_TIMEOUT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv4FlowProbe::DROP_INVALID_REASON
        tmp_value = PyLong_FromLong(ns3::Ipv4FlowProbe::DROP_INVALID_REASON);
        PyDict_SetItemString((PyObject*) PyNs3Ipv4FlowProbe_Type.tp_dict, "DROP_INVALID_REASON", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::Ipv6FlowProbe::DROP_NO_ROUTE
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_NO_ROUTE);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_NO_ROUTE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_TTL_EXPIRE
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_TTL_EXPIRE);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_TTL_EXPIRE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_BAD_CHECKSUM
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_BAD_CHECKSUM);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_BAD_CHECKSUM", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_QUEUE
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_QUEUE);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_QUEUE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_INTERFACE_DOWN
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_INTERFACE_DOWN);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_INTERFACE_DOWN", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_ROUTE_ERROR
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_ROUTE_ERROR);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_ROUTE_ERROR", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_UNKNOWN_PROTOCOL
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_UNKNOWN_PROTOCOL);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_UNKNOWN_PROTOCOL", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_UNKNOWN_OPTION
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_UNKNOWN_OPTION);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_UNKNOWN_OPTION", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_MALFORMED_HEADER
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_MALFORMED_HEADER);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_MALFORMED_HEADER", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_FRAGMENT_TIMEOUT
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_FRAGMENT_TIMEOUT);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_FRAGMENT_TIMEOUT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Ipv6FlowProbe::DROP_INVALID_REASON
        tmp_value = PyLong_FromLong(ns3::Ipv6FlowProbe::DROP_INVALID_REASON);
        PyDict_SetItemString((PyObject*) PyNs3Ipv6FlowProbe_Type.tp_dict, "DROP_INVALID_REASON", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initflow_monitor_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initflow_monitor_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initflow_monitor_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    return MOD_RETURN(m);
}
