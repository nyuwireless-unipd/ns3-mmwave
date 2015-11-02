#include "ns3module.h"
static PyMethodDef lr_wpan_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef lr_wpan_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "lr_wpan.FatalImpl",
    NULL,
    -1,
    lr_wpan_FatalImpl_functions,
};
#endif

static PyObject *
initlr_wpan_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&lr_wpan_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "lr_wpan.FatalImpl", lr_wpan_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef lr_wpan_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef lr_wpan_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "lr_wpan.Hash.Function",
    NULL,
    -1,
    lr_wpan_Hash_Function_functions,
};
#endif

static PyObject *
initlr_wpan_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&lr_wpan_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "lr_wpan.Hash.Function", lr_wpan_Hash_Function_functions, NULL);
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
static PyMethodDef lr_wpan_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef lr_wpan_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "lr_wpan.Hash",
    NULL,
    -1,
    lr_wpan_Hash_functions,
};
#endif

static PyObject *
initlr_wpan_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&lr_wpan_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "lr_wpan.Hash", lr_wpan_Hash_functions, NULL);
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
    submodule = initlr_wpan_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef lr_wpan_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef lr_wpan_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "lr_wpan.TracedValueCallback",
    NULL,
    -1,
    lr_wpan_TracedValueCallback_functions,
};
#endif

static PyObject *
initlr_wpan_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&lr_wpan_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "lr_wpan.TracedValueCallback", lr_wpan_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef lr_wpan_internal_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef lr_wpan_internal_moduledef = {
    PyModuleDef_HEAD_INIT,
    "lr_wpan.internal",
    NULL,
    -1,
    lr_wpan_internal_functions,
};
#endif

static PyObject *
initlr_wpan_internal(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&lr_wpan_internal_moduledef);
    #else
    m = Py_InitModule3((char *) "lr_wpan.internal", lr_wpan_internal_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef lr_wpan_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3Address_Type;
std::map<void*, PyObject*> *_PyNs3Address_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelper_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelper_wrapper_registry;


PyTypeObject *_PyNs3AsciiTraceHelperForDevice_Type;
std::map<void*, PyObject*> *_PyNs3AsciiTraceHelperForDevice_wrapper_registry;


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


PyTypeObject *_PyNs3SequenceNumber8_Type;
std::map<void*, PyObject*> *_PyNs3SequenceNumber8_wrapper_registry;


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


PyTypeObject *_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3NixVector_Ns3Empty_Ns3DefaultDeleter__lt__ns3NixVector__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3SpectrumPhy_Type;


PyTypeObject *_PyNs3SpectrumSignalParameters_Type;


PyTypeObject *_PyNs3Time_Type;
std::map<void*, PyObject*> *_PyNs3Time_wrapper_registry;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


PyTypeObject *_PyNs3Trailer_Type;


PyTypeObject *_PyNs3AttributeAccessor_Type;


PyTypeObject *_PyNs3AttributeChecker_Type;


PyTypeObject *_PyNs3AttributeValue_Type;


PyTypeObject *_PyNs3BooleanChecker_Type;


PyTypeObject *_PyNs3BooleanValue_Type;


PyTypeObject *_PyNs3CallbackChecker_Type;


PyTypeObject *_PyNs3CallbackImplBase_Type;


PyTypeObject *_PyNs3CallbackValue_Type;


PyTypeObject *_PyNs3DoubleValue_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3EnumChecker_Type;


PyTypeObject *_PyNs3EnumValue_Type;


PyTypeObject *_PyNs3EventImpl_Type;


PyTypeObject *_PyNs3IntegerValue_Type;


PyTypeObject *_PyNs3Ipv4AddressChecker_Type;


PyTypeObject *_PyNs3Ipv4AddressValue_Type;


PyTypeObject *_PyNs3Ipv4MaskChecker_Type;


PyTypeObject *_PyNs3Ipv4MaskValue_Type;


PyTypeObject *_PyNs3Ipv6AddressChecker_Type;


PyTypeObject *_PyNs3Ipv6AddressValue_Type;


PyTypeObject *_PyNs3Ipv6PrefixChecker_Type;


PyTypeObject *_PyNs3Ipv6PrefixValue_Type;


PyTypeObject *_PyNs3Mac16AddressChecker_Type;


PyTypeObject *_PyNs3Mac16AddressValue_Type;


PyTypeObject *_PyNs3Mac48AddressChecker_Type;


PyTypeObject *_PyNs3Mac48AddressValue_Type;


PyTypeObject *_PyNs3Mac64AddressChecker_Type;


PyTypeObject *_PyNs3Mac64AddressValue_Type;


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


PyTypeObject *_PyNs3UintegerValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


std::map<void*, PyObject*> PyNs3LrWpanEdPower_wrapper_registry;
static PyObject* _wrap_PyNs3LrWpanEdPower__get_averagePower(PyNs3LrWpanEdPower *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->averagePower);
    return py_retval;
}
static int _wrap_PyNs3LrWpanEdPower__set_averagePower(PyNs3LrWpanEdPower *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->averagePower)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanEdPower__get_lastUpdate(PyNs3LrWpanEdPower *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->lastUpdate);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3LrWpanEdPower__set_lastUpdate(PyNs3LrWpanEdPower *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->lastUpdate = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanEdPower__get_measurementLength(PyNs3LrWpanEdPower *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->measurementLength);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3LrWpanEdPower__set_measurementLength(PyNs3LrWpanEdPower *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->measurementLength = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3LrWpanEdPower__getsets[] = {
    {
        (char*) "lastUpdate", /* attribute name */
        (getter) _wrap_PyNs3LrWpanEdPower__get_lastUpdate, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanEdPower__set_lastUpdate, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "averagePower", /* attribute name */
        (getter) _wrap_PyNs3LrWpanEdPower__get_averagePower, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanEdPower__set_averagePower, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "measurementLength", /* attribute name */
        (getter) _wrap_PyNs3LrWpanEdPower__get_measurementLength, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanEdPower__set_measurementLength, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3LrWpanEdPower__tp_init__0(PyNs3LrWpanEdPower *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanEdPower *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanEdPower_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanEdPower(*((PyNs3LrWpanEdPower *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanEdPower__tp_init__1(PyNs3LrWpanEdPower *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanEdPower();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanEdPower__tp_init(PyNs3LrWpanEdPower *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanEdPower__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanEdPower__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanEdPower__copy__(PyNs3LrWpanEdPower *self)
{

    PyNs3LrWpanEdPower *py_copy;
    py_copy = PyObject_New(PyNs3LrWpanEdPower, &PyNs3LrWpanEdPower_Type);
    py_copy->obj = new ns3::LrWpanEdPower(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3LrWpanEdPower_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanEdPower_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanEdPower__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanEdPower__tp_dealloc(PyNs3LrWpanEdPower *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3LrWpanEdPower_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3LrWpanEdPower_wrapper_registry.end()) {
        PyNs3LrWpanEdPower_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::LrWpanEdPower *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanEdPower__tp_richcompare (PyNs3LrWpanEdPower *PYBINDGEN_UNUSED(self), PyNs3LrWpanEdPower *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanEdPower_Type)) {
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

PyTypeObject PyNs3LrWpanEdPower_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanEdPower",            /* tp_name */
    sizeof(PyNs3LrWpanEdPower),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanEdPower__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanEdPower__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanEdPower_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3LrWpanEdPower__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanEdPower__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry;
static PyObject* _wrap_PyNs3LrWpanPhyDataAndSymbolRates__get_bitRate(PyNs3LrWpanPhyDataAndSymbolRates *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->bitRate);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyDataAndSymbolRates__set_bitRate(PyNs3LrWpanPhyDataAndSymbolRates *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->bitRate)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyDataAndSymbolRates__get_symbolRate(PyNs3LrWpanPhyDataAndSymbolRates *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->symbolRate);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyDataAndSymbolRates__set_symbolRate(PyNs3LrWpanPhyDataAndSymbolRates *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->symbolRate)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3LrWpanPhyDataAndSymbolRates__getsets[] = {
    {
        (char*) "symbolRate", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyDataAndSymbolRates__get_symbolRate, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyDataAndSymbolRates__set_symbolRate, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "bitRate", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyDataAndSymbolRates__get_bitRate, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyDataAndSymbolRates__set_bitRate, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_init__0(PyNs3LrWpanPhyDataAndSymbolRates *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanPhyDataAndSymbolRates();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_init__1(PyNs3LrWpanPhyDataAndSymbolRates *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanPhyDataAndSymbolRates *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanPhyDataAndSymbolRates_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanPhyDataAndSymbolRates(*((PyNs3LrWpanPhyDataAndSymbolRates *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_init(PyNs3LrWpanPhyDataAndSymbolRates *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanPhyDataAndSymbolRates__copy__(PyNs3LrWpanPhyDataAndSymbolRates *self)
{

    PyNs3LrWpanPhyDataAndSymbolRates *py_copy;
    py_copy = PyObject_New(PyNs3LrWpanPhyDataAndSymbolRates, &PyNs3LrWpanPhyDataAndSymbolRates_Type);
    py_copy->obj = new ns3::LrWpanPhyDataAndSymbolRates(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanPhyDataAndSymbolRates_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanPhyDataAndSymbolRates__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_dealloc(PyNs3LrWpanPhyDataAndSymbolRates *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry.end()) {
        PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::LrWpanPhyDataAndSymbolRates *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_richcompare (PyNs3LrWpanPhyDataAndSymbolRates *PYBINDGEN_UNUSED(self), PyNs3LrWpanPhyDataAndSymbolRates *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanPhyDataAndSymbolRates_Type)) {
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

PyTypeObject PyNs3LrWpanPhyDataAndSymbolRates_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanPhyDataAndSymbolRates",            /* tp_name */
    sizeof(PyNs3LrWpanPhyDataAndSymbolRates),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanPhyDataAndSymbolRates_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3LrWpanPhyDataAndSymbolRates__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanPhyDataAndSymbolRates__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3LrWpanPhyPibAttributes_wrapper_registry;
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phyCCAMode(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->phyCCAMode);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phyCCAMode(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->phyCCAMode = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phyCurrentChannel(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->phyCurrentChannel);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phyCurrentChannel(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->phyCurrentChannel = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phyCurrentPage(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->phyCurrentPage));
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phyCurrentPage(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->phyCurrentPage)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phyMaxFrameDuration(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->phyMaxFrameDuration));
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phyMaxFrameDuration(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->phyMaxFrameDuration)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phySHRDuration(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->phySHRDuration));
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phySHRDuration(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->phySHRDuration)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phySymbolsPerOctet(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->phySymbolsPerOctet);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phySymbolsPerOctet(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->phySymbolsPerOctet)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPibAttributes__get_phyTransmitPower(PyNs3LrWpanPhyPibAttributes *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->phyTransmitPower);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPibAttributes__set_phyTransmitPower(PyNs3LrWpanPhyPibAttributes *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->phyTransmitPower = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3LrWpanPhyPibAttributes__getsets[] = {
    {
        (char*) "phyCurrentPage", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phyCurrentPage, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phyCurrentPage, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phyTransmitPower", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phyTransmitPower, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phyTransmitPower, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phySymbolsPerOctet", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phySymbolsPerOctet, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phySymbolsPerOctet, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phyMaxFrameDuration", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phyMaxFrameDuration, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phyMaxFrameDuration, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phyCurrentChannel", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phyCurrentChannel, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phyCurrentChannel, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phyCCAMode", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phyCCAMode, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phyCCAMode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phySHRDuration", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPibAttributes__get_phySHRDuration, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPibAttributes__set_phySHRDuration, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3LrWpanPhyPibAttributes__tp_init__0(PyNs3LrWpanPhyPibAttributes *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanPhyPibAttributes();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanPhyPibAttributes__tp_init__1(PyNs3LrWpanPhyPibAttributes *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanPhyPibAttributes *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanPhyPibAttributes_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanPhyPibAttributes(*((PyNs3LrWpanPhyPibAttributes *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanPhyPibAttributes__tp_init(PyNs3LrWpanPhyPibAttributes *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanPhyPibAttributes__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanPhyPibAttributes__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanPhyPibAttributes__copy__(PyNs3LrWpanPhyPibAttributes *self)
{

    PyNs3LrWpanPhyPibAttributes *py_copy;
    py_copy = PyObject_New(PyNs3LrWpanPhyPibAttributes, &PyNs3LrWpanPhyPibAttributes_Type);
    py_copy->obj = new ns3::LrWpanPhyPibAttributes(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3LrWpanPhyPibAttributes_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanPhyPibAttributes_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanPhyPibAttributes__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanPhyPibAttributes__tp_dealloc(PyNs3LrWpanPhyPibAttributes *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3LrWpanPhyPibAttributes_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3LrWpanPhyPibAttributes_wrapper_registry.end()) {
        PyNs3LrWpanPhyPibAttributes_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::LrWpanPhyPibAttributes *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanPhyPibAttributes__tp_richcompare (PyNs3LrWpanPhyPibAttributes *PYBINDGEN_UNUSED(self), PyNs3LrWpanPhyPibAttributes *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanPhyPibAttributes_Type)) {
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

PyTypeObject PyNs3LrWpanPhyPibAttributes_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanPhyPibAttributes",            /* tp_name */
    sizeof(PyNs3LrWpanPhyPibAttributes),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanPhyPibAttributes__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanPhyPibAttributes__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanPhyPibAttributes_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3LrWpanPhyPibAttributes__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanPhyPibAttributes__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry;
static PyObject* _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__get_phr(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->phr);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__set_phr(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->phr)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__get_shrPreamble(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->shrPreamble);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__set_shrPreamble(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->shrPreamble)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__get_shrSfd(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->shrSfd);
    return py_retval;
}
static int _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__set_shrSfd(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->shrSfd)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3LrWpanPhyPpduHeaderSymbolNumber__getsets[] = {
    {
        (char*) "shrSfd", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__get_shrSfd, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__set_shrSfd, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phr", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__get_phr, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__set_phr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "shrPreamble", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__get_shrPreamble, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__set_shrPreamble, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_init__0(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanPhyPpduHeaderSymbolNumber();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_init__1(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanPhyPpduHeaderSymbolNumber *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanPhyPpduHeaderSymbolNumber_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanPhyPpduHeaderSymbolNumber(*((PyNs3LrWpanPhyPpduHeaderSymbolNumber *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_init(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__copy__(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self)
{

    PyNs3LrWpanPhyPpduHeaderSymbolNumber *py_copy;
    py_copy = PyObject_New(PyNs3LrWpanPhyPpduHeaderSymbolNumber, &PyNs3LrWpanPhyPpduHeaderSymbolNumber_Type);
    py_copy->obj = new ns3::LrWpanPhyPpduHeaderSymbolNumber(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanPhyPpduHeaderSymbolNumber_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_dealloc(PyNs3LrWpanPhyPpduHeaderSymbolNumber *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry.end()) {
        PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::LrWpanPhyPpduHeaderSymbolNumber *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_richcompare (PyNs3LrWpanPhyPpduHeaderSymbolNumber *PYBINDGEN_UNUSED(self), PyNs3LrWpanPhyPpduHeaderSymbolNumber *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanPhyPpduHeaderSymbolNumber_Type)) {
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

PyTypeObject PyNs3LrWpanPhyPpduHeaderSymbolNumber_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanPhyPpduHeaderSymbolNumber",            /* tp_name */
    sizeof(PyNs3LrWpanPhyPpduHeaderSymbolNumber),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanPhyPpduHeaderSymbolNumber_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3LrWpanPhyPpduHeaderSymbolNumber__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanPhyPpduHeaderSymbolNumber__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3LrWpanSpectrumValueHelper_wrapper_registry;


static int
_wrap_PyNs3LrWpanSpectrumValueHelper__tp_init__0(PyNs3LrWpanSpectrumValueHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanSpectrumValueHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanSpectrumValueHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanSpectrumValueHelper(*((PyNs3LrWpanSpectrumValueHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanSpectrumValueHelper__tp_init__1(PyNs3LrWpanSpectrumValueHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanSpectrumValueHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanSpectrumValueHelper__tp_init(PyNs3LrWpanSpectrumValueHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanSpectrumValueHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanSpectrumValueHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanSpectrumValueHelper__copy__(PyNs3LrWpanSpectrumValueHelper *self)
{

    PyNs3LrWpanSpectrumValueHelper *py_copy;
    py_copy = PyObject_New(PyNs3LrWpanSpectrumValueHelper, &PyNs3LrWpanSpectrumValueHelper_Type);
    py_copy->obj = new ns3::LrWpanSpectrumValueHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3LrWpanSpectrumValueHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanSpectrumValueHelper_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanSpectrumValueHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanSpectrumValueHelper__tp_dealloc(PyNs3LrWpanSpectrumValueHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3LrWpanSpectrumValueHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3LrWpanSpectrumValueHelper_wrapper_registry.end()) {
        PyNs3LrWpanSpectrumValueHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::LrWpanSpectrumValueHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanSpectrumValueHelper__tp_richcompare (PyNs3LrWpanSpectrumValueHelper *PYBINDGEN_UNUSED(self), PyNs3LrWpanSpectrumValueHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanSpectrumValueHelper_Type)) {
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

PyTypeObject PyNs3LrWpanSpectrumValueHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanSpectrumValueHelper",            /* tp_name */
    sizeof(PyNs3LrWpanSpectrumValueHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanSpectrumValueHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanSpectrumValueHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanSpectrumValueHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanSpectrumValueHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3McpsDataConfirmParams_wrapper_registry;
static PyObject* _wrap_PyNs3McpsDataConfirmParams__get_m_msduHandle(PyNs3McpsDataConfirmParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_msduHandle);
    return py_retval;
}
static int _wrap_PyNs3McpsDataConfirmParams__set_m_msduHandle(PyNs3McpsDataConfirmParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_msduHandle = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataConfirmParams__get_m_status(PyNs3McpsDataConfirmParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_status);
    return py_retval;
}
static int _wrap_PyNs3McpsDataConfirmParams__set_m_status(PyNs3McpsDataConfirmParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &self->obj->m_status)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3McpsDataConfirmParams__getsets[] = {
    {
        (char*) "m_status", /* attribute name */
        (getter) _wrap_PyNs3McpsDataConfirmParams__get_m_status, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataConfirmParams__set_m_status, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_msduHandle", /* attribute name */
        (getter) _wrap_PyNs3McpsDataConfirmParams__get_m_msduHandle, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataConfirmParams__set_m_msduHandle, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3McpsDataConfirmParams__tp_init__0(PyNs3McpsDataConfirmParams *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::McpsDataConfirmParams();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3McpsDataConfirmParams__tp_init__1(PyNs3McpsDataConfirmParams *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3McpsDataConfirmParams *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3McpsDataConfirmParams_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::McpsDataConfirmParams(*((PyNs3McpsDataConfirmParams *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3McpsDataConfirmParams__tp_init(PyNs3McpsDataConfirmParams *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3McpsDataConfirmParams__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3McpsDataConfirmParams__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3McpsDataConfirmParams__copy__(PyNs3McpsDataConfirmParams *self)
{

    PyNs3McpsDataConfirmParams *py_copy;
    py_copy = PyObject_New(PyNs3McpsDataConfirmParams, &PyNs3McpsDataConfirmParams_Type);
    py_copy->obj = new ns3::McpsDataConfirmParams(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3McpsDataConfirmParams_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3McpsDataConfirmParams_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3McpsDataConfirmParams__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3McpsDataConfirmParams__tp_dealloc(PyNs3McpsDataConfirmParams *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3McpsDataConfirmParams_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3McpsDataConfirmParams_wrapper_registry.end()) {
        PyNs3McpsDataConfirmParams_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::McpsDataConfirmParams *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3McpsDataConfirmParams__tp_richcompare (PyNs3McpsDataConfirmParams *PYBINDGEN_UNUSED(self), PyNs3McpsDataConfirmParams *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3McpsDataConfirmParams_Type)) {
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

PyTypeObject PyNs3McpsDataConfirmParams_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.McpsDataConfirmParams",            /* tp_name */
    sizeof(PyNs3McpsDataConfirmParams),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3McpsDataConfirmParams__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3McpsDataConfirmParams__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3McpsDataConfirmParams_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3McpsDataConfirmParams__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3McpsDataConfirmParams__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3McpsDataIndicationParams_wrapper_registry;
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_dsn(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_dsn);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_dsn(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_dsn = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_dstAddr(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac16Address *py_Mac16Address;
    
    py_Mac16Address = PyObject_New(PyNs3Mac16Address, &PyNs3Mac16Address_Type);
    py_Mac16Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac16Address->obj = new ns3::Mac16Address(self->obj->m_dstAddr);
    PyNs3Mac16Address_wrapper_registry[(void *) py_Mac16Address->obj] = (PyObject *) py_Mac16Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac16Address);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_dstAddr(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac16Address *tmp_Mac16Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Mac16Address_Type, &tmp_Mac16Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_dstAddr = *tmp_Mac16Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_dstAddrMode(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_dstAddrMode);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_dstAddrMode(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_dstAddrMode = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_dstPanId(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_dstPanId);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_dstPanId(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_dstPanId = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_mpduLinkQuality(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_mpduLinkQuality);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_mpduLinkQuality(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_mpduLinkQuality = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_srcAddr(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac16Address *py_Mac16Address;
    
    py_Mac16Address = PyObject_New(PyNs3Mac16Address, &PyNs3Mac16Address_Type);
    py_Mac16Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac16Address->obj = new ns3::Mac16Address(self->obj->m_srcAddr);
    PyNs3Mac16Address_wrapper_registry[(void *) py_Mac16Address->obj] = (PyObject *) py_Mac16Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac16Address);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_srcAddr(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac16Address *tmp_Mac16Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Mac16Address_Type, &tmp_Mac16Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_srcAddr = *tmp_Mac16Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_srcAddrMode(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_srcAddrMode);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_srcAddrMode(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_srcAddrMode = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataIndicationParams__get_m_srcPanId(PyNs3McpsDataIndicationParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_srcPanId);
    return py_retval;
}
static int _wrap_PyNs3McpsDataIndicationParams__set_m_srcPanId(PyNs3McpsDataIndicationParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_srcPanId = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3McpsDataIndicationParams__getsets[] = {
    {
        (char*) "m_srcPanId", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_srcPanId, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_srcPanId, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_srcAddrMode", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_srcAddrMode, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_srcAddrMode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_mpduLinkQuality", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_mpduLinkQuality, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_mpduLinkQuality, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dstAddrMode", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_dstAddrMode, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_dstAddrMode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dstAddr", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_dstAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_dstAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dsn", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_dsn, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_dsn, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dstPanId", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_dstPanId, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_dstPanId, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_srcAddr", /* attribute name */
        (getter) _wrap_PyNs3McpsDataIndicationParams__get_m_srcAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataIndicationParams__set_m_srcAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3McpsDataIndicationParams__tp_init__0(PyNs3McpsDataIndicationParams *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::McpsDataIndicationParams();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3McpsDataIndicationParams__tp_init__1(PyNs3McpsDataIndicationParams *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3McpsDataIndicationParams *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3McpsDataIndicationParams_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::McpsDataIndicationParams(*((PyNs3McpsDataIndicationParams *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3McpsDataIndicationParams__tp_init(PyNs3McpsDataIndicationParams *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3McpsDataIndicationParams__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3McpsDataIndicationParams__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3McpsDataIndicationParams__copy__(PyNs3McpsDataIndicationParams *self)
{

    PyNs3McpsDataIndicationParams *py_copy;
    py_copy = PyObject_New(PyNs3McpsDataIndicationParams, &PyNs3McpsDataIndicationParams_Type);
    py_copy->obj = new ns3::McpsDataIndicationParams(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3McpsDataIndicationParams_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3McpsDataIndicationParams_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3McpsDataIndicationParams__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3McpsDataIndicationParams__tp_dealloc(PyNs3McpsDataIndicationParams *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3McpsDataIndicationParams_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3McpsDataIndicationParams_wrapper_registry.end()) {
        PyNs3McpsDataIndicationParams_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::McpsDataIndicationParams *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3McpsDataIndicationParams__tp_richcompare (PyNs3McpsDataIndicationParams *PYBINDGEN_UNUSED(self), PyNs3McpsDataIndicationParams *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3McpsDataIndicationParams_Type)) {
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

PyTypeObject PyNs3McpsDataIndicationParams_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.McpsDataIndicationParams",            /* tp_name */
    sizeof(PyNs3McpsDataIndicationParams),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3McpsDataIndicationParams__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3McpsDataIndicationParams__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3McpsDataIndicationParams_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3McpsDataIndicationParams__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3McpsDataIndicationParams__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3McpsDataRequestParams_wrapper_registry;
static PyObject* _wrap_PyNs3McpsDataRequestParams__get_m_dstAddr(PyNs3McpsDataRequestParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac16Address *py_Mac16Address;
    
    py_Mac16Address = PyObject_New(PyNs3Mac16Address, &PyNs3Mac16Address_Type);
    py_Mac16Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac16Address->obj = new ns3::Mac16Address(self->obj->m_dstAddr);
    PyNs3Mac16Address_wrapper_registry[(void *) py_Mac16Address->obj] = (PyObject *) py_Mac16Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac16Address);
    return py_retval;
}
static int _wrap_PyNs3McpsDataRequestParams__set_m_dstAddr(PyNs3McpsDataRequestParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac16Address *tmp_Mac16Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Mac16Address_Type, &tmp_Mac16Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_dstAddr = *tmp_Mac16Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataRequestParams__get_m_dstAddrMode(PyNs3McpsDataRequestParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_dstAddrMode);
    return py_retval;
}
static int _wrap_PyNs3McpsDataRequestParams__set_m_dstAddrMode(PyNs3McpsDataRequestParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &self->obj->m_dstAddrMode)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataRequestParams__get_m_dstPanId(PyNs3McpsDataRequestParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_dstPanId);
    return py_retval;
}
static int _wrap_PyNs3McpsDataRequestParams__set_m_dstPanId(PyNs3McpsDataRequestParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_dstPanId = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataRequestParams__get_m_msduHandle(PyNs3McpsDataRequestParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_msduHandle);
    return py_retval;
}
static int _wrap_PyNs3McpsDataRequestParams__set_m_msduHandle(PyNs3McpsDataRequestParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_msduHandle = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataRequestParams__get_m_srcAddrMode(PyNs3McpsDataRequestParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_srcAddrMode);
    return py_retval;
}
static int _wrap_PyNs3McpsDataRequestParams__set_m_srcAddrMode(PyNs3McpsDataRequestParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &self->obj->m_srcAddrMode)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3McpsDataRequestParams__get_m_txOptions(PyNs3McpsDataRequestParams *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_txOptions);
    return py_retval;
}
static int _wrap_PyNs3McpsDataRequestParams__set_m_txOptions(PyNs3McpsDataRequestParams *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_txOptions = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3McpsDataRequestParams__getsets[] = {
    {
        (char*) "m_srcAddrMode", /* attribute name */
        (getter) _wrap_PyNs3McpsDataRequestParams__get_m_srcAddrMode, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataRequestParams__set_m_srcAddrMode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_txOptions", /* attribute name */
        (getter) _wrap_PyNs3McpsDataRequestParams__get_m_txOptions, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataRequestParams__set_m_txOptions, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_msduHandle", /* attribute name */
        (getter) _wrap_PyNs3McpsDataRequestParams__get_m_msduHandle, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataRequestParams__set_m_msduHandle, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dstAddrMode", /* attribute name */
        (getter) _wrap_PyNs3McpsDataRequestParams__get_m_dstAddrMode, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataRequestParams__set_m_dstAddrMode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dstAddr", /* attribute name */
        (getter) _wrap_PyNs3McpsDataRequestParams__get_m_dstAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataRequestParams__set_m_dstAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_dstPanId", /* attribute name */
        (getter) _wrap_PyNs3McpsDataRequestParams__get_m_dstPanId, /* C function to get the attribute */
        (setter) _wrap_PyNs3McpsDataRequestParams__set_m_dstPanId, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3McpsDataRequestParams__tp_init__0(PyNs3McpsDataRequestParams *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3McpsDataRequestParams *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3McpsDataRequestParams_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::McpsDataRequestParams(*((PyNs3McpsDataRequestParams *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3McpsDataRequestParams__tp_init__1(PyNs3McpsDataRequestParams *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::McpsDataRequestParams();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3McpsDataRequestParams__tp_init(PyNs3McpsDataRequestParams *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3McpsDataRequestParams__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3McpsDataRequestParams__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3McpsDataRequestParams__copy__(PyNs3McpsDataRequestParams *self)
{

    PyNs3McpsDataRequestParams *py_copy;
    py_copy = PyObject_New(PyNs3McpsDataRequestParams, &PyNs3McpsDataRequestParams_Type);
    py_copy->obj = new ns3::McpsDataRequestParams(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3McpsDataRequestParams_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3McpsDataRequestParams_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3McpsDataRequestParams__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3McpsDataRequestParams__tp_dealloc(PyNs3McpsDataRequestParams *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3McpsDataRequestParams_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3McpsDataRequestParams_wrapper_registry.end()) {
        PyNs3McpsDataRequestParams_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::McpsDataRequestParams *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3McpsDataRequestParams__tp_richcompare (PyNs3McpsDataRequestParams *PYBINDGEN_UNUSED(self), PyNs3McpsDataRequestParams *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3McpsDataRequestParams_Type)) {
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

PyTypeObject PyNs3McpsDataRequestParams_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.McpsDataRequestParams",            /* tp_name */
    sizeof(PyNs3McpsDataRequestParams),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3McpsDataRequestParams__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3McpsDataRequestParams__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3McpsDataRequestParams_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3McpsDataRequestParams__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3McpsDataRequestParams__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry;


static int
_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init__0(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::TracedValue< ns3::LrWpanMacState >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init__1(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3TracedValue__Ns3LrWpanMacState *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TracedValue__Ns3LrWpanMacState_Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::TracedValue< ns3::LrWpanMacState >(*((PyNs3TracedValue__Ns3LrWpanMacState *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init__2(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    ns3::LrWpanMacState  v;
    const char *keywords[] = {"v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &v)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::TracedValue< ns3::LrWpanMacState >(v);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3TracedValue__Ns3LrWpanMacState_Set(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanMacState  v;
    const char *keywords[] = {"v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &v)) {
        return NULL;
    }
    self->obj->Set(v);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanMacState_Disconnect(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *path;
    Py_ssize_t path_len;
    const char *keywords[] = {"cb", "path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3CallbackBase_Type, &cb, &path, &path_len)) {
        return NULL;
    }
    self->obj->Disconnect(*((PyNs3CallbackBase *) cb)->obj, std::string(path, path_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanMacState_Get(PyNs3TracedValue__Ns3LrWpanMacState *self)
{
    PyObject *py_retval;
    ns3::LrWpanMacState retval;
    
    retval = self->obj->Get();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanMacState_ConnectWithoutContext(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    self->obj->ConnectWithoutContext(*((PyNs3CallbackBase *) cb)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanMacState_DisconnectWithoutContext(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    self->obj->DisconnectWithoutContext(*((PyNs3CallbackBase *) cb)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanMacState_Connect(PyNs3TracedValue__Ns3LrWpanMacState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *path;
    Py_ssize_t path_len;
    const char *keywords[] = {"cb", "path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3CallbackBase_Type, &cb, &path, &path_len)) {
        return NULL;
    }
    self->obj->Connect(*((PyNs3CallbackBase *) cb)->obj, std::string(path, path_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3TracedValue__Ns3LrWpanMacState__copy__(PyNs3TracedValue__Ns3LrWpanMacState *self)
{

    PyNs3TracedValue__Ns3LrWpanMacState *py_copy;
    py_copy = PyObject_New(PyNs3TracedValue__Ns3LrWpanMacState, &PyNs3TracedValue__Ns3LrWpanMacState_Type);
    py_copy->obj = new ns3::TracedValue< ns3::LrWpanMacState >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3TracedValue__Ns3LrWpanMacState_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Disconnect", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState_Disconnect, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState_Get, METH_NOARGS, NULL },
    {(char *) "ConnectWithoutContext", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState_ConnectWithoutContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DisconnectWithoutContext", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState_DisconnectWithoutContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Connect", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState_Connect, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanMacState__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_dealloc(PyNs3TracedValue__Ns3LrWpanMacState *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry.end()) {
        PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::TracedValue< ns3::LrWpanMacState > *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_richcompare (PyNs3TracedValue__Ns3LrWpanMacState *PYBINDGEN_UNUSED(self), PyNs3TracedValue__Ns3LrWpanMacState *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3TracedValue__Ns3LrWpanMacState_Type)) {
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

PyTypeObject PyNs3TracedValue__Ns3LrWpanMacState_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.TracedValue__Ns3LrWpanMacState",            /* tp_name */
    sizeof(PyNs3TracedValue__Ns3LrWpanMacState),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3TracedValue__Ns3LrWpanMacState_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3TracedValue__Ns3LrWpanMacState__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry;


static int
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init__0(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::TracedValue< ns3::LrWpanPhyEnumeration >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init__1(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3TracedValue__Ns3LrWpanPhyEnumeration *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::TracedValue< ns3::LrWpanPhyEnumeration >(*((PyNs3TracedValue__Ns3LrWpanPhyEnumeration *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init__2(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    ns3::LrWpanPhyEnumeration  v;
    const char *keywords[] = {"v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &v)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::TracedValue< ns3::LrWpanPhyEnumeration >(v);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Set(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration  v;
    const char *keywords[] = {"v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &v)) {
        return NULL;
    }
    self->obj->Set(v);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Disconnect(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *path;
    Py_ssize_t path_len;
    const char *keywords[] = {"cb", "path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3CallbackBase_Type, &cb, &path, &path_len)) {
        return NULL;
    }
    self->obj->Disconnect(*((PyNs3CallbackBase *) cb)->obj, std::string(path, path_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Get(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration retval;
    
    retval = self->obj->Get();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_ConnectWithoutContext(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    self->obj->ConnectWithoutContext(*((PyNs3CallbackBase *) cb)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_DisconnectWithoutContext(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    self->obj->DisconnectWithoutContext(*((PyNs3CallbackBase *) cb)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Connect(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3CallbackBase *cb;
    const char *path;
    Py_ssize_t path_len;
    const char *keywords[] = {"cb", "path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3CallbackBase_Type, &cb, &path, &path_len)) {
        return NULL;
    }
    self->obj->Connect(*((PyNs3CallbackBase *) cb)->obj, std::string(path, path_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__copy__(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self)
{

    PyNs3TracedValue__Ns3LrWpanPhyEnumeration *py_copy;
    py_copy = PyObject_New(PyNs3TracedValue__Ns3LrWpanPhyEnumeration, &PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Type);
    py_copy->obj = new ns3::TracedValue< ns3::LrWpanPhyEnumeration >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3TracedValue__Ns3LrWpanPhyEnumeration_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Disconnect", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Disconnect, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Get, METH_NOARGS, NULL },
    {(char *) "ConnectWithoutContext", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_ConnectWithoutContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DisconnectWithoutContext", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_DisconnectWithoutContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Connect", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Connect, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_dealloc(PyNs3TracedValue__Ns3LrWpanPhyEnumeration *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry.end()) {
        PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::TracedValue< ns3::LrWpanPhyEnumeration > *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_richcompare (PyNs3TracedValue__Ns3LrWpanPhyEnumeration *PYBINDGEN_UNUSED(self), PyNs3TracedValue__Ns3LrWpanPhyEnumeration *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Type)) {
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

PyTypeObject PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.TracedValue__Ns3LrWpanPhyEnumeration",            /* tp_name */
    sizeof(PyNs3TracedValue__Ns3LrWpanPhyEnumeration),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3TracedValue__Ns3LrWpanPhyEnumeration_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3TracedValue__Ns3LrWpanPhyEnumeration__tp_init,             /* tp_init */
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




void
PyNs3LrWpanHelper__PythonHelper::EnablePcapInternal(std::string prefix, ns3::Ptr< ns3::NetDevice > nd, bool promiscuous, bool explicitFilename)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LrWpanHelper *self_obj_before;
    PyObject *py_retval;
    const char *prefix_ptr;
    Py_ssize_t prefix_len;
    PyNs3NetDevice *py_NetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "EnablePcapInternal"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = (ns3::LrWpanHelper*) this;
    prefix_ptr = (prefix).c_str();
    prefix_len = (prefix).size();
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_NetDevice = NULL;
    } else {
        py_NetDevice = (PyNs3NetDevice *) wrapper_lookup_iter->second;
        Py_INCREF(py_NetDevice);
    }
    
    if (py_NetDevice == NULL)
    {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd))), &PyNs3NetDevice_Type);
        py_NetDevice = PyObject_GC_New(PyNs3NetDevice, wrapper_type);
        py_NetDevice->inst_dict = NULL;
    
        py_NetDevice->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd))->Ref();
        py_NetDevice->obj = const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd));
        PyNs3ObjectBase_wrapper_registry[(void *) py_NetDevice->obj] = (PyObject *) py_NetDevice;
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "EnablePcapInternal", (char *) "s#NNN", prefix_ptr, prefix_len, py_NetDevice, PyBool_FromLong(promiscuous), PyBool_FromLong(explicitFilename));
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3LrWpanHelper__PythonHelper::EnableAsciiInternal(ns3::Ptr< ns3::OutputStreamWrapper > stream, std::string prefix, ns3::Ptr< ns3::NetDevice > nd, bool explicitFilename)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LrWpanHelper *self_obj_before;
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *py_OutputStreamWrapper;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    const char *prefix_ptr;
    Py_ssize_t prefix_len;
    PyNs3NetDevice *py_NetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "EnableAsciiInternal"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = (ns3::LrWpanHelper*) this;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::OutputStreamWrapper *> (ns3::PeekPointer (stream)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_OutputStreamWrapper = NULL;
    } else {
        py_OutputStreamWrapper = (PyNs3OutputStreamWrapper *) wrapper_lookup_iter->second;
        Py_INCREF(py_OutputStreamWrapper);
    }
    
    if (py_OutputStreamWrapper == NULL)
    {
        wrapper_type = PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map.lookup_wrapper(typeid(*const_cast<ns3::OutputStreamWrapper *> (ns3::PeekPointer (stream))), &PyNs3OutputStreamWrapper_Type);
        py_OutputStreamWrapper = PyObject_New(PyNs3OutputStreamWrapper, wrapper_type);
    
        py_OutputStreamWrapper->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::OutputStreamWrapper *> (ns3::PeekPointer (stream))->Ref();
        py_OutputStreamWrapper->obj = const_cast<ns3::OutputStreamWrapper *> (ns3::PeekPointer (stream));
        PyNs3Empty_wrapper_registry[(void *) py_OutputStreamWrapper->obj] = (PyObject *) py_OutputStreamWrapper;
    }
    prefix_ptr = (prefix).c_str();
    prefix_len = (prefix).size();
    wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd)));
    if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
        py_NetDevice = NULL;
    } else {
        py_NetDevice = (PyNs3NetDevice *) wrapper_lookup_iter2->second;
        Py_INCREF(py_NetDevice);
    }
    
    if (py_NetDevice == NULL)
    {
        wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd))), &PyNs3NetDevice_Type);
        py_NetDevice = PyObject_GC_New(PyNs3NetDevice, wrapper_type2);
        py_NetDevice->inst_dict = NULL;
    
        py_NetDevice->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd))->Ref();
        py_NetDevice->obj = const_cast<ns3::NetDevice *> (ns3::PeekPointer (nd));
        PyNs3ObjectBase_wrapper_registry[(void *) py_NetDevice->obj] = (PyObject *) py_NetDevice;
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "EnableAsciiInternal", (char *) "Ns#NN", py_OutputStreamWrapper, prefix_ptr, prefix_len, py_NetDevice, PyBool_FromLong(explicitFilename));
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LrWpanHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3LrWpanHelper__tp_init__0(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3LrWpanHelper_Type)
    {
        self->obj = new PyNs3LrWpanHelper__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LrWpanHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LrWpanHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3LrWpanHelper__tp_init__1(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    bool useMultiModelSpectrumChannel;
    PyObject *py_useMultiModelSpectrumChannel;
    const char *keywords[] = {"useMultiModelSpectrumChannel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_useMultiModelSpectrumChannel)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    useMultiModelSpectrumChannel = (bool) PyObject_IsTrue(py_useMultiModelSpectrumChannel);
    if (Py_TYPE(self) != &PyNs3LrWpanHelper_Type)
    {
        self->obj = new PyNs3LrWpanHelper__PythonHelper(useMultiModelSpectrumChannel);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LrWpanHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LrWpanHelper(useMultiModelSpectrumChannel);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3LrWpanHelper__tp_init(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanHelper_AssignStreams(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    PyNs3NetDeviceContainer *c;
    int64_t stream;
    const char *keywords[] = {"c", "stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!L", (char **) keywords, &PyNs3NetDeviceContainer_Type, &c, &stream)) {
        return NULL;
    }
    retval = self->obj->AssignStreams(*((PyNs3NetDeviceContainer *) c)->obj, stream);
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_AssociateToPan(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NetDeviceContainer *c;
    int panId;
    const char *keywords[] = {"c", "panId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3NetDeviceContainer_Type, &c, &panId)) {
        return NULL;
    }
    if (panId > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->AssociateToPan(*((PyNs3NetDeviceContainer *) c)->obj, panId);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_EnableLogComponents(PyNs3LrWpanHelper *self)
{
    PyObject *py_retval;
    
    self->obj->EnableLogComponents();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_LrWpanPhyEnumerationPrinter(PyNs3LrWpanHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    ns3::LrWpanPhyEnumeration e;
    const char *keywords[] = {"e", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &e)) {
        return NULL;
    }
    retval = ns3::LrWpanHelper::LrWpanPhyEnumerationPrinter(e);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_SetChannel(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *channelName;
    Py_ssize_t channelName_len;
    const char *keywords[] = {"channelName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &channelName, &channelName_len)) {
        return NULL;
    }
    self->obj->SetChannel(std::string(channelName, channelName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_Install(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        return NULL;
    }
    ns3::NetDeviceContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_LrWpanMacStatePrinter(PyNs3LrWpanHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    ns3::LrWpanMacState e;
    const char *keywords[] = {"e", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &e)) {
        return NULL;
    }
    retval = ns3::LrWpanHelper::LrWpanMacStatePrinter(e);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanHelper_EnableAsciiAll__0(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    const char *keywords[] = {"prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &prefix, &prefix_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EnableAsciiAll(std::string(prefix, prefix_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAsciiAll__1(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->EnableAsciiAll(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanHelper_EnableAsciiAll(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanHelper_EnableAsciiAll__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAsciiAll__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanHelper_EnablePcap__0(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    PyNs3NetDevice *nd;
    ns3::NetDevice *nd_ptr;
    bool promiscuous;
    PyObject *py_promiscuous = NULL;
    bool explicitFilename;
    PyObject *py_explicitFilename = NULL;
    const char *keywords[] = {"prefix", "nd", "promiscuous", "explicitFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!|OO", (char **) keywords, &prefix, &prefix_len, &PyNs3NetDevice_Type, &nd, &py_promiscuous, &py_explicitFilename)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    nd_ptr = (nd ? nd->obj : NULL);
    promiscuous = py_promiscuous? (bool) PyObject_IsTrue(py_promiscuous) : false;
    explicitFilename = py_explicitFilename? (bool) PyObject_IsTrue(py_explicitFilename) : false;
    self->obj->EnablePcap(std::string(prefix, prefix_len), ns3::Ptr< ns3::NetDevice  > (nd_ptr), promiscuous, explicitFilename);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnablePcap__1(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    const char *ndName;
    Py_ssize_t ndName_len;
    bool promiscuous;
    PyObject *py_promiscuous = NULL;
    bool explicitFilename;
    PyObject *py_explicitFilename = NULL;
    const char *keywords[] = {"prefix", "ndName", "promiscuous", "explicitFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#|OO", (char **) keywords, &prefix, &prefix_len, &ndName, &ndName_len, &py_promiscuous, &py_explicitFilename)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    promiscuous = py_promiscuous? (bool) PyObject_IsTrue(py_promiscuous) : false;
    explicitFilename = py_explicitFilename? (bool) PyObject_IsTrue(py_explicitFilename) : false;
    self->obj->EnablePcap(std::string(prefix, prefix_len), std::string(ndName, ndName_len), promiscuous, explicitFilename);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnablePcap__2(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    PyNs3NetDeviceContainer *d;
    bool promiscuous;
    PyObject *py_promiscuous = NULL;
    const char *keywords[] = {"prefix", "d", "promiscuous", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!|O", (char **) keywords, &prefix, &prefix_len, &PyNs3NetDeviceContainer_Type, &d, &py_promiscuous)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    promiscuous = py_promiscuous? (bool) PyObject_IsTrue(py_promiscuous) : false;
    self->obj->EnablePcap(std::string(prefix, prefix_len), *((PyNs3NetDeviceContainer *) d)->obj, promiscuous);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnablePcap__3(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    PyNs3NodeContainer *n;
    bool promiscuous;
    PyObject *py_promiscuous = NULL;
    const char *keywords[] = {"prefix", "n", "promiscuous", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!|O", (char **) keywords, &prefix, &prefix_len, &PyNs3NodeContainer_Type, &n, &py_promiscuous)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    promiscuous = py_promiscuous? (bool) PyObject_IsTrue(py_promiscuous) : false;
    self->obj->EnablePcap(std::string(prefix, prefix_len), *((PyNs3NodeContainer *) n)->obj, promiscuous);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnablePcap__4(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    unsigned int nodeid;
    unsigned int deviceid;
    bool promiscuous;
    PyObject *py_promiscuous = NULL;
    const char *keywords[] = {"prefix", "nodeid", "deviceid", "promiscuous", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#II|O", (char **) keywords, &prefix, &prefix_len, &nodeid, &deviceid, &py_promiscuous)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    promiscuous = py_promiscuous? (bool) PyObject_IsTrue(py_promiscuous) : false;
    self->obj->EnablePcap(std::string(prefix, prefix_len), nodeid, deviceid, promiscuous);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanHelper_EnablePcap(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3LrWpanHelper_EnablePcap__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnablePcap__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnablePcap__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnablePcap__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnablePcap__4(self, args, kwargs, &exceptions[4]);
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
    return NULL;
}


PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__0(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    PyNs3NetDevice *nd;
    ns3::NetDevice *nd_ptr;
    bool explicitFilename;
    PyObject *py_explicitFilename = NULL;
    const char *keywords[] = {"prefix", "nd", "explicitFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!|O", (char **) keywords, &prefix, &prefix_len, &PyNs3NetDevice_Type, &nd, &py_explicitFilename)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    nd_ptr = (nd ? nd->obj : NULL);
    explicitFilename = py_explicitFilename? (bool) PyObject_IsTrue(py_explicitFilename) : false;
    self->obj->EnableAscii(std::string(prefix, prefix_len), ns3::Ptr< ns3::NetDevice  > (nd_ptr), explicitFilename);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__1(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    PyNs3NetDevice *nd;
    ns3::NetDevice *nd_ptr;
    const char *keywords[] = {"stream", "nd", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream, &PyNs3NetDevice_Type, &nd)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    nd_ptr = (nd ? nd->obj : NULL);
    self->obj->EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), ns3::Ptr< ns3::NetDevice  > (nd_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__2(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    const char *ndName;
    Py_ssize_t ndName_len;
    bool explicitFilename;
    PyObject *py_explicitFilename = NULL;
    const char *keywords[] = {"prefix", "ndName", "explicitFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#|O", (char **) keywords, &prefix, &prefix_len, &ndName, &ndName_len, &py_explicitFilename)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    explicitFilename = py_explicitFilename? (bool) PyObject_IsTrue(py_explicitFilename) : false;
    self->obj->EnableAscii(std::string(prefix, prefix_len), std::string(ndName, ndName_len), explicitFilename);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__3(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    const char *ndName;
    Py_ssize_t ndName_len;
    const char *keywords[] = {"stream", "ndName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream, &ndName, &ndName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), std::string(ndName, ndName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__4(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    PyNs3NetDeviceContainer *d;
    const char *keywords[] = {"prefix", "d", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &prefix, &prefix_len, &PyNs3NetDeviceContainer_Type, &d)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EnableAscii(std::string(prefix, prefix_len), *((PyNs3NetDeviceContainer *) d)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__5(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    PyNs3NetDeviceContainer *d;
    const char *keywords[] = {"stream", "d", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream, &PyNs3NetDeviceContainer_Type, &d)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), *((PyNs3NetDeviceContainer *) d)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__6(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    PyNs3NodeContainer *n;
    const char *keywords[] = {"prefix", "n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &prefix, &prefix_len, &PyNs3NodeContainer_Type, &n)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EnableAscii(std::string(prefix, prefix_len), *((PyNs3NodeContainer *) n)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__7(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    PyNs3NodeContainer *n;
    const char *keywords[] = {"stream", "n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream, &PyNs3NodeContainer_Type, &n)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), *((PyNs3NodeContainer *) n)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__8(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    unsigned int nodeid;
    unsigned int deviceid;
    bool explicitFilename;
    PyObject *py_explicitFilename;
    const char *keywords[] = {"prefix", "nodeid", "deviceid", "explicitFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#IIO", (char **) keywords, &prefix, &prefix_len, &nodeid, &deviceid, &py_explicitFilename)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    explicitFilename = (bool) PyObject_IsTrue(py_explicitFilename);
    self->obj->EnableAscii(std::string(prefix, prefix_len), nodeid, deviceid, explicitFilename);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnableAscii__9(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    unsigned int nodeid;
    unsigned int deviceid;
    const char *keywords[] = {"stream", "nodeid", "deviceid", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!II", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream, &nodeid, &deviceid)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), nodeid, deviceid);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanHelper_EnableAscii(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[10] = {0,};
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__4(self, args, kwargs, &exceptions[4]);
    if (!exceptions[4]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__5(self, args, kwargs, &exceptions[5]);
    if (!exceptions[5]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__6(self, args, kwargs, &exceptions[6]);
    if (!exceptions[6]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        Py_DECREF(exceptions[5]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__7(self, args, kwargs, &exceptions[7]);
    if (!exceptions[7]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        Py_DECREF(exceptions[5]);
        Py_DECREF(exceptions[6]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__8(self, args, kwargs, &exceptions[8]);
    if (!exceptions[8]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        Py_DECREF(exceptions[5]);
        Py_DECREF(exceptions[6]);
        Py_DECREF(exceptions[7]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanHelper_EnableAscii__9(self, args, kwargs, &exceptions[9]);
    if (!exceptions[9]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        Py_DECREF(exceptions[5]);
        Py_DECREF(exceptions[6]);
        Py_DECREF(exceptions[7]);
        Py_DECREF(exceptions[8]);
        return retval;
    }
    error_list = PyList_New(10);
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
    PyList_SET_ITEM(error_list, 5, PyObject_Str(exceptions[5]));
    Py_DECREF(exceptions[5]);
    PyList_SET_ITEM(error_list, 6, PyObject_Str(exceptions[6]));
    Py_DECREF(exceptions[6]);
    PyList_SET_ITEM(error_list, 7, PyObject_Str(exceptions[7]));
    Py_DECREF(exceptions[7]);
    PyList_SET_ITEM(error_list, 8, PyObject_Str(exceptions[8]));
    Py_DECREF(exceptions[8]);
    PyList_SET_ITEM(error_list, 9, PyObject_Str(exceptions[9]));
    Py_DECREF(exceptions[9]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}

PyObject *
_wrap_PyNs3LrWpanHelper_EnablePcapAll(PyNs3LrWpanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    bool promiscuous;
    PyObject *py_promiscuous = NULL;
    const char *keywords[] = {"prefix", "promiscuous", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|O", (char **) keywords, &prefix, &prefix_len, &py_promiscuous)) {
        return NULL;
    }
    promiscuous = py_promiscuous? (bool) PyObject_IsTrue(py_promiscuous) : false;
    self->obj->EnablePcapAll(std::string(prefix, prefix_len), promiscuous);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3LrWpanHelper_methods[] = {
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3LrWpanHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssociateToPan", (PyCFunction) _wrap_PyNs3LrWpanHelper_AssociateToPan, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableLogComponents", (PyCFunction) _wrap_PyNs3LrWpanHelper_EnableLogComponents, METH_NOARGS, NULL },
    {(char *) "LrWpanPhyEnumerationPrinter", (PyCFunction) _wrap_PyNs3LrWpanHelper_LrWpanPhyEnumerationPrinter, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetChannel", (PyCFunction) _wrap_PyNs3LrWpanHelper_SetChannel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3LrWpanHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "LrWpanMacStatePrinter", (PyCFunction) _wrap_PyNs3LrWpanHelper_LrWpanMacStatePrinter, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "EnableAsciiAll", (PyCFunction) _wrap_PyNs3LrWpanHelper_EnableAsciiAll, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnablePcap", (PyCFunction) _wrap_PyNs3LrWpanHelper_EnablePcap, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableAscii", (PyCFunction) _wrap_PyNs3LrWpanHelper_EnableAscii, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnablePcapAll", (PyCFunction) _wrap_PyNs3LrWpanHelper_EnablePcapAll, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanHelper__tp_clear(PyNs3LrWpanHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::LrWpanHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3LrWpanHelper__tp_traverse(PyNs3LrWpanHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3LrWpanHelper__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3LrWpanHelper__tp_dealloc(PyNs3LrWpanHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PcapHelperForDevice_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PcapHelperForDevice_wrapper_registry.end()) {
        PyNs3PcapHelperForDevice_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanHelper__tp_richcompare (PyNs3LrWpanHelper *PYBINDGEN_UNUSED(self), PyNs3LrWpanHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanHelper_Type)) {
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

PyTypeObject PyNs3LrWpanHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanHelper",            /* tp_name */
    sizeof(PyNs3LrWpanHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanHelper__tp_init,             /* tp_init */
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
_wrap_PyNs3LrWpanLqiTag__tp_init__0(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanLqiTag *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanLqiTag_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanLqiTag(*((PyNs3LrWpanLqiTag *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanLqiTag__tp_init__1(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanLqiTag();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanLqiTag__tp_init__2(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int lqi;
    const char *keywords[] = {"lqi", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &lqi)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (lqi > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanLqiTag(lqi);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanLqiTag__tp_init(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3LrWpanLqiTag__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanLqiTag__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanLqiTag__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3LrWpanLqiTag_Set(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int lqi;
    const char *keywords[] = {"lqi", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &lqi)) {
        return NULL;
    }
    if (lqi > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->Set(lqi);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanLqiTag_Deserialize(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3TagBuffer *i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TagBuffer_Type, &i)) {
        return NULL;
    }
    self->obj->Deserialize(*((PyNs3TagBuffer *) i)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanLqiTag_Get(PyNs3LrWpanLqiTag *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->Get();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanLqiTag_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanLqiTag::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanLqiTag_Serialize(PyNs3LrWpanLqiTag *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3TagBuffer *i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TagBuffer_Type, &i)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3TagBuffer *) i)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanLqiTag_GetInstanceTypeId(PyNs3LrWpanLqiTag *self)
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
_wrap_PyNs3LrWpanLqiTag_GetSerializedSize(PyNs3LrWpanLqiTag *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanLqiTag__copy__(PyNs3LrWpanLqiTag *self)
{

    PyNs3LrWpanLqiTag *py_copy;
    py_copy = PyObject_GC_New(PyNs3LrWpanLqiTag, &PyNs3LrWpanLqiTag_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::LrWpanLqiTag(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanLqiTag_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_Get, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3LrWpanLqiTag_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanLqiTag__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanLqiTag__tp_clear(PyNs3LrWpanLqiTag *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::LrWpanLqiTag *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3LrWpanLqiTag__tp_traverse(PyNs3LrWpanLqiTag *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3LrWpanLqiTag__tp_dealloc(PyNs3LrWpanLqiTag *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanLqiTag__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanLqiTag__tp_richcompare (PyNs3LrWpanLqiTag *PYBINDGEN_UNUSED(self), PyNs3LrWpanLqiTag *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanLqiTag_Type)) {
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

PyTypeObject PyNs3LrWpanLqiTag_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanLqiTag",            /* tp_name */
    sizeof(PyNs3LrWpanLqiTag),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanLqiTag__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanLqiTag__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanLqiTag__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanLqiTag__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanLqiTag_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanLqiTag, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanLqiTag__tp_init,             /* tp_init */
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
_wrap_PyNs3LrWpanMacHeader__tp_init__0(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanMacHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanMacHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanMacHeader(*((PyNs3LrWpanMacHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanMacHeader__tp_init__1(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanMacHeader();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanMacHeader__tp_init__2(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    ns3::LrWpanMacHeader::LrWpanMacType wpanMacType;
    int seqNum;
    const char *keywords[] = {"wpanMacType", "seqNum", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ii", (char **) keywords, &wpanMacType, &seqNum)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (seqNum > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanMacHeader(wpanMacType, seqNum);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanMacHeader__tp_init(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3LrWpanMacHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacHeader__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3LrWpanMacHeader_SetSecCtrlReserved(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int res;
    const char *keywords[] = {"res", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &res)) {
        return NULL;
    }
    if (res > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSecCtrlReserved(res);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsAcknowledgment(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsAcknowledgment();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetFrmPend(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetFrmPend();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsData(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsData();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsSecEnable(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsSecEnable();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanMacHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetDstAddrMode(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetDstAddrMode();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetNoFrmPend(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetNoFrmPend();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3LrWpanMacHeader_SetKeyId__0(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    int keyIndex;
    const char *keywords[] = {"keyIndex", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &keyIndex)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (keyIndex > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetKeyId(keyIndex);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanMacHeader_SetKeyId__1(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    unsigned int keySrc;
    int keyIndex;
    const char *keywords[] = {"keySrc", "keyIndex", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Ii", (char **) keywords, &keySrc, &keyIndex)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (keyIndex > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetKeyId(keySrc, keyIndex);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanMacHeader_SetKeyId__2(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    uint64_t keySrc;
    int keyIndex;
    const char *keywords[] = {"keySrc", "keyIndex", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "Ki", (char **) keywords, &keySrc, &keyIndex)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (keyIndex > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetKeyId(keySrc, keyIndex);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanMacHeader_SetKeyId(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3LrWpanMacHeader_SetKeyId__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacHeader_SetKeyId__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacHeader_SetKeyId__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3LrWpanMacHeader_Serialize(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3LrWpanMacHeader_SetDstAddrFields__0(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    int panId;
    PyNs3Mac16Address *addr;
    const char *keywords[] = {"panId", "addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iO!", (char **) keywords, &panId, &PyNs3Mac16Address_Type, &addr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (panId > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetDstAddrFields(panId, *((PyNs3Mac16Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanMacHeader_SetDstAddrFields__1(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    int panId;
    PyNs3Mac64Address *addr;
    const char *keywords[] = {"panId", "addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iO!", (char **) keywords, &panId, &PyNs3Mac64Address_Type, &addr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (panId > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetDstAddrFields(panId, *((PyNs3Mac64Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanMacHeader_SetDstAddrFields(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanMacHeader_SetDstAddrFields__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacHeader_SetDstAddrFields__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanMacHeader_SetSecDisable(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetSecDisable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetNoAckReq(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetNoAckReq();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetFrmCounter(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetFrmCounter();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetKeyIdIndex(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetKeyIdIndex();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}



PyObject *
_wrap_PyNs3LrWpanMacHeader_SetSrcAddrFields__0(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    int panId;
    PyNs3Mac16Address *addr;
    const char *keywords[] = {"panId", "addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iO!", (char **) keywords, &panId, &PyNs3Mac16Address_Type, &addr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (panId > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetSrcAddrFields(panId, *((PyNs3Mac16Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanMacHeader_SetSrcAddrFields__1(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    int panId;
    PyNs3Mac64Address *addr;
    const char *keywords[] = {"panId", "addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "iO!", (char **) keywords, &panId, &PyNs3Mac64Address_Type, &addr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    if (panId > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetSrcAddrFields(panId, *((PyNs3Mac64Address *) addr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanMacHeader_SetSrcAddrFields(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanMacHeader_SetSrcAddrFields__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacHeader_SetSrcAddrFields__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanMacHeader_SetSeqNum(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int seqNum;
    const char *keywords[] = {"seqNum", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &seqNum)) {
        return NULL;
    }
    if (seqNum > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSeqNum(seqNum);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetSecEnable(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetSecEnable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetSecControl(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int secLevel;
    const char *keywords[] = {"secLevel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &secLevel)) {
        return NULL;
    }
    if (secLevel > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSecControl(secLevel);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetDstAddrMode(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int addrMode;
    const char *keywords[] = {"addrMode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &addrMode)) {
        return NULL;
    }
    if (addrMode > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDstAddrMode(addrMode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetSecLevel(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetSecLevel();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetFrameControl(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetFrameControl();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetPanIdComp(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetPanIdComp();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetType(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanMacHeader::LrWpanMacType wpanMacType;
    const char *keywords[] = {"wpanMacType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &wpanMacType)) {
        return NULL;
    }
    self->obj->SetType(wpanMacType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetKeyIdMode(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int keyIdMode;
    const char *keywords[] = {"keyIdMode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &keyIdMode)) {
        return NULL;
    }
    if (keyIdMode > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetKeyIdMode(keyIdMode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsPanIdComp(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsPanIdComp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetExtSrcAddr(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    PyNs3Mac64Address *py_Mac64Address;
    
    ns3::Mac64Address retval = self->obj->GetExtSrcAddr();
    py_Mac64Address = PyObject_New(PyNs3Mac64Address, &PyNs3Mac64Address_Type);
    py_Mac64Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac64Address->obj = new ns3::Mac64Address(retval);
    PyNs3Mac64Address_wrapper_registry[(void *) py_Mac64Address->obj] = (PyObject *) py_Mac64Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac64Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetFrameVer(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int ver;
    const char *keywords[] = {"ver", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &ver)) {
        return NULL;
    }
    if (ver > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetFrameVer(ver);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_Deserialize(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3LrWpanMacHeader_GetKeyIdSrc64(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint64_t retval;
    
    retval = self->obj->GetKeyIdSrc64();
    py_retval = Py_BuildValue((char *) "K", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetSrcAddrMode(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int addrMode;
    const char *keywords[] = {"addrMode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &addrMode)) {
        return NULL;
    }
    if (addrMode > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSrcAddrMode(addrMode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetDstPanId(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetDstPanId();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsCommand(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsCommand();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetNoPanIdComp(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetNoPanIdComp();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsFrmPend(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsFrmPend();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetFrameVer(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetFrameVer();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetExtDstAddr(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    PyNs3Mac64Address *py_Mac64Address;
    
    ns3::Mac64Address retval = self->obj->GetExtDstAddr();
    py_Mac64Address = PyObject_New(PyNs3Mac64Address, &PyNs3Mac64Address_Type);
    py_Mac64Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac64Address->obj = new ns3::Mac64Address(retval);
    PyNs3Mac64Address_wrapper_registry[(void *) py_Mac64Address->obj] = (PyObject *) py_Mac64Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac64Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetKeyIdMode(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetKeyIdMode();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetShortDstAddr(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    PyNs3Mac16Address *py_Mac16Address;
    
    ns3::Mac16Address retval = self->obj->GetShortDstAddr();
    py_Mac16Address = PyObject_New(PyNs3Mac16Address, &PyNs3Mac16Address_Type);
    py_Mac16Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac16Address->obj = new ns3::Mac16Address(retval);
    PyNs3Mac16Address_wrapper_registry[(void *) py_Mac16Address->obj] = (PyObject *) py_Mac16Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac16Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetInstanceTypeId(PyNs3LrWpanMacHeader *self)
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
_wrap_PyNs3LrWpanMacHeader_GetSerializedSize(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetSrcAddrMode(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetSrcAddrMode();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetFrameControl(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int frameControl;
    const char *keywords[] = {"frameControl", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &frameControl)) {
        return NULL;
    }
    if (frameControl > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetFrameControl(frameControl);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetFrmCounter(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int frmCntr;
    const char *keywords[] = {"frmCntr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &frmCntr)) {
        return NULL;
    }
    self->obj->SetFrmCounter(frmCntr);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetSecLevel(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int secLevel;
    const char *keywords[] = {"secLevel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &secLevel)) {
        return NULL;
    }
    if (secLevel > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSecLevel(secLevel);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetFrmCtrlRes(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetFrmCtrlRes();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetShortSrcAddr(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    PyNs3Mac16Address *py_Mac16Address;
    
    ns3::Mac16Address retval = self->obj->GetShortSrcAddr();
    py_Mac16Address = PyObject_New(PyNs3Mac16Address, &PyNs3Mac16Address_Type);
    py_Mac16Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac16Address->obj = new ns3::Mac16Address(retval);
    PyNs3Mac16Address_wrapper_registry[(void *) py_Mac16Address->obj] = (PyObject *) py_Mac16Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac16Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetType(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    ns3::LrWpanMacHeader::LrWpanMacType retval;
    
    retval = self->obj->GetType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetAckReq(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    
    self->obj->SetAckReq();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetSrcPanId(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetSrcPanId();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetKeyIdSrc32(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetKeyIdSrc32();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsBeacon(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBeacon();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_IsAckReq(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsAckReq();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetSecControl(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetSecControl();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetSeqNum(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetSeqNum();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_GetSecCtrlReserved(PyNs3LrWpanMacHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetSecCtrlReserved();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacHeader_SetFrmCtrlRes(PyNs3LrWpanMacHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int res;
    const char *keywords[] = {"res", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &res)) {
        return NULL;
    }
    if (res > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetFrmCtrlRes(res);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanMacHeader__copy__(PyNs3LrWpanMacHeader *self)
{

    PyNs3LrWpanMacHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3LrWpanMacHeader, &PyNs3LrWpanMacHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::LrWpanMacHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanMacHeader_methods[] = {
    {(char *) "SetSecCtrlReserved", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSecCtrlReserved, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsAcknowledgment", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsAcknowledgment, METH_NOARGS, NULL },
    {(char *) "SetFrmPend", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetFrmPend, METH_NOARGS, NULL },
    {(char *) "IsData", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsData, METH_NOARGS, NULL },
    {(char *) "IsSecEnable", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsSecEnable, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetDstAddrMode", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetDstAddrMode, METH_NOARGS, NULL },
    {(char *) "SetNoFrmPend", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetNoFrmPend, METH_NOARGS, NULL },
    {(char *) "SetKeyId", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetKeyId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDstAddrFields", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetDstAddrFields, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSecDisable", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSecDisable, METH_NOARGS, NULL },
    {(char *) "SetNoAckReq", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetNoAckReq, METH_NOARGS, NULL },
    {(char *) "GetFrmCounter", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetFrmCounter, METH_NOARGS, NULL },
    {(char *) "GetKeyIdIndex", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetKeyIdIndex, METH_NOARGS, NULL },
    {(char *) "SetSrcAddrFields", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSrcAddrFields, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSeqNum", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSeqNum, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSecEnable", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSecEnable, METH_NOARGS, NULL },
    {(char *) "SetSecControl", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSecControl, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDstAddrMode", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetDstAddrMode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSecLevel", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSecLevel, METH_NOARGS, NULL },
    {(char *) "GetFrameControl", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetFrameControl, METH_NOARGS, NULL },
    {(char *) "SetPanIdComp", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetPanIdComp, METH_NOARGS, NULL },
    {(char *) "SetType", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetKeyIdMode", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetKeyIdMode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsPanIdComp", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsPanIdComp, METH_NOARGS, NULL },
    {(char *) "GetExtSrcAddr", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetExtSrcAddr, METH_NOARGS, NULL },
    {(char *) "SetFrameVer", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetFrameVer, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetKeyIdSrc64", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetKeyIdSrc64, METH_NOARGS, NULL },
    {(char *) "SetSrcAddrMode", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSrcAddrMode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDstPanId", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetDstPanId, METH_NOARGS, NULL },
    {(char *) "IsCommand", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsCommand, METH_NOARGS, NULL },
    {(char *) "SetNoPanIdComp", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetNoPanIdComp, METH_NOARGS, NULL },
    {(char *) "IsFrmPend", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsFrmPend, METH_NOARGS, NULL },
    {(char *) "GetFrameVer", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetFrameVer, METH_NOARGS, NULL },
    {(char *) "GetExtDstAddr", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetExtDstAddr, METH_NOARGS, NULL },
    {(char *) "GetKeyIdMode", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetKeyIdMode, METH_NOARGS, NULL },
    {(char *) "GetShortDstAddr", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetShortDstAddr, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "GetSrcAddrMode", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSrcAddrMode, METH_NOARGS, NULL },
    {(char *) "SetFrameControl", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetFrameControl, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFrmCounter", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetFrmCounter, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSecLevel", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetSecLevel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFrmCtrlRes", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetFrmCtrlRes, METH_NOARGS, NULL },
    {(char *) "GetShortSrcAddr", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetShortSrcAddr, METH_NOARGS, NULL },
    {(char *) "GetType", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetType, METH_NOARGS, NULL },
    {(char *) "SetAckReq", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetAckReq, METH_NOARGS, NULL },
    {(char *) "GetSrcPanId", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSrcPanId, METH_NOARGS, NULL },
    {(char *) "GetKeyIdSrc32", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetKeyIdSrc32, METH_NOARGS, NULL },
    {(char *) "IsBeacon", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsBeacon, METH_NOARGS, NULL },
    {(char *) "IsAckReq", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_IsAckReq, METH_NOARGS, NULL },
    {(char *) "GetSecControl", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSecControl, METH_NOARGS, NULL },
    {(char *) "GetSeqNum", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSeqNum, METH_NOARGS, NULL },
    {(char *) "GetSecCtrlReserved", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_GetSecCtrlReserved, METH_NOARGS, NULL },
    {(char *) "SetFrmCtrlRes", (PyCFunction) _wrap_PyNs3LrWpanMacHeader_SetFrmCtrlRes, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanMacHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanMacHeader__tp_clear(PyNs3LrWpanMacHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::LrWpanMacHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3LrWpanMacHeader__tp_traverse(PyNs3LrWpanMacHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3LrWpanMacHeader__tp_dealloc(PyNs3LrWpanMacHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanMacHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanMacHeader__tp_richcompare (PyNs3LrWpanMacHeader *PYBINDGEN_UNUSED(self), PyNs3LrWpanMacHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanMacHeader_Type)) {
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

PyTypeObject PyNs3LrWpanMacHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanMacHeader",            /* tp_name */
    sizeof(PyNs3LrWpanMacHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanMacHeader__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanMacHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanMacHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanMacHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanMacHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanMacHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanMacHeader__tp_init,             /* tp_init */
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




pybindgen::TypeMap PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____typeid_map;



static int
_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_init__0(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_init__1(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> >(*((PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_init(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____copy__(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *self)
{

    PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *py_copy;
    py_copy = PyObject_New(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__, &PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type);
    
    py_copy->obj = new ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___methods[] = {
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_dealloc(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> > *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_richcompare (PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *PYBINDGEN_UNUSED(self), PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__ *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type)) {
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

PyTypeObject PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__",            /* tp_name */
    sizeof(PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____tp_init,             /* tp_init */
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
PyNs3LrWpanCsmaCa__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    PyNs3LrWpanCsmaCa__PythonHelper *helper = dynamic_cast< PyNs3LrWpanCsmaCa__PythonHelper* >(self->obj);
    
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
PyNs3LrWpanCsmaCa__PythonHelper::_wrap_DoInitialize(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    PyNs3LrWpanCsmaCa__PythonHelper *helper = dynamic_cast< PyNs3LrWpanCsmaCa__PythonHelper* >(self->obj);
    
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
PyNs3LrWpanCsmaCa__PythonHelper::_wrap_NotifyNewAggregate(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    PyNs3LrWpanCsmaCa__PythonHelper *helper = dynamic_cast< PyNs3LrWpanCsmaCa__PythonHelper* >(self->obj);
    
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
PyNs3LrWpanCsmaCa__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LrWpanCsmaCa *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LrWpanCsmaCa* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LrWpanCsmaCa* >(m_pyself)->obj = (ns3::LrWpanCsmaCa*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LrWpanCsmaCa* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LrWpanCsmaCa* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LrWpanCsmaCa* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3LrWpanCsmaCa__PythonHelper::GetInstanceTypeId() const
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
PyNs3LrWpanCsmaCa__PythonHelper::DoInitialize()
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
PyNs3LrWpanCsmaCa__PythonHelper::NotifyNewAggregate()
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
PyNs3LrWpanCsmaCa__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3LrWpanCsmaCa__tp_init(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3LrWpanCsmaCa_Type)
    {
        self->obj = new PyNs3LrWpanCsmaCa__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LrWpanCsmaCa__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LrWpanCsmaCa();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetUnitBackoffPeriod(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint64_t unitBackoffPeriod;
    const char *keywords[] = {"unitBackoffPeriod", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "K", (char **) keywords, &unitBackoffPeriod)) {
        return NULL;
    }
    self->obj->SetUnitBackoffPeriod(unitBackoffPeriod);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_PlmeCcaConfirm(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration status;
    const char *keywords[] = {"status", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &status)) {
        return NULL;
    }
    self->obj->PlmeCcaConfirm(status);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanCsmaCa::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetMacMaxCSMABackoffs(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int macMaxCSMABackoffs;
    const char *keywords[] = {"macMaxCSMABackoffs", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &macMaxCSMABackoffs)) {
        return NULL;
    }
    if (macMaxCSMABackoffs > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMacMaxCSMABackoffs(macMaxCSMABackoffs);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_Start(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->Start();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_CanProceed(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->CanProceed();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_RandomBackoffDelay(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->RandomBackoffDelay();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetLrWpanMacStateCallback(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *macState;
    ns3::Ptr<PythonCallbackImpl3> macState_cb_impl;
    const char *keywords[] = {"macState", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &macState)) {
        return NULL;
    }
    if (!PyCallable_Check(macState)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'macState' must be callbale");
        return NULL;
    }
    macState_cb_impl = ns3::Create<PythonCallbackImpl3> (macState);
    self->obj->SetLrWpanMacStateCallback(ns3::Callback<void, ns3::LrWpanMacState, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (macState_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetNB(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetNB();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetMac(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::LrWpanMac > retval;
    PyNs3LrWpanMac *py_LrWpanMac;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetMac();
    if (!(const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3LrWpanMac__PythonHelper).name())
    {
        py_LrWpanMac = reinterpret_cast< PyNs3LrWpanMac* >(reinterpret_cast< PyNs3LrWpanMac__PythonHelper* >(const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))->m_pyself);
        py_LrWpanMac->obj = const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval));
        Py_INCREF(py_LrWpanMac);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_LrWpanMac = NULL;
        } else {
            py_LrWpanMac = (PyNs3LrWpanMac *) wrapper_lookup_iter->second;
            Py_INCREF(py_LrWpanMac);
        }
    
        if (py_LrWpanMac == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))), &PyNs3LrWpanMac_Type);
            py_LrWpanMac = PyObject_GC_New(PyNs3LrWpanMac, wrapper_type);
            py_LrWpanMac->inst_dict = NULL;
    
            py_LrWpanMac->inst_dict = NULL;
            py_LrWpanMac->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval))->Ref();
            py_LrWpanMac->obj = const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_LrWpanMac->obj] = (PyObject *) py_LrWpanMac;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_LrWpanMac);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_RequestCCA(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->RequestCCA();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetMacMaxBE(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int macMaxBE;
    const char *keywords[] = {"macMaxBE", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &macMaxBE)) {
        return NULL;
    }
    if (macMaxBE > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMacMaxBE(macMaxBE);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_IsUnSlottedCsmaCa(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsUnSlottedCsmaCa();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetUnSlottedCsmaCa(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->SetUnSlottedCsmaCa();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetMacMaxBE(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetMacMaxBE();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetSlottedCsmaCa(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->SetSlottedCsmaCa();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetMac(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanMac *mac;
    ns3::LrWpanMac *mac_ptr;
    const char *keywords[] = {"mac", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanMac_Type, &mac)) {
        return NULL;
    }
    mac_ptr = (mac ? mac->obj : NULL);
    self->obj->SetMac(ns3::Ptr< ns3::LrWpanMac  > (mac_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetMacMaxCSMABackoffs(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetMacMaxCSMABackoffs();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_SetMacMinBE(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int macMinBE;
    const char *keywords[] = {"macMinBE", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &macMinBE)) {
        return NULL;
    }
    if (macMinBE > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMacMinBE(macMinBE);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetTimeToNextSlot(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetTimeToNextSlot();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_IsSlottedCsmaCa(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsSlottedCsmaCa();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetMacMinBE(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetMacMinBE();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_GetUnitBackoffPeriod(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    uint64_t retval;
    
    retval = self->obj->GetUnitBackoffPeriod();
    py_retval = Py_BuildValue((char *) "K", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanCsmaCa_AssignStreams(PyNs3LrWpanCsmaCa *self, PyObject *args, PyObject *kwargs)
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


PyObject *
_wrap_PyNs3LrWpanCsmaCa_Cancel(PyNs3LrWpanCsmaCa *self)
{
    PyObject *py_retval;
    
    self->obj->Cancel();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3LrWpanCsmaCa_methods[] = {
    {(char *) "SetUnitBackoffPeriod", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetUnitBackoffPeriod, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeCcaConfirm", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_PlmeCcaConfirm, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetMacMaxCSMABackoffs", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetMacMaxCSMABackoffs, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Start", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_Start, METH_NOARGS, NULL },
    {(char *) "CanProceed", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_CanProceed, METH_NOARGS, NULL },
    {(char *) "RandomBackoffDelay", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_RandomBackoffDelay, METH_NOARGS, NULL },
    {(char *) "SetLrWpanMacStateCallback", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetLrWpanMacStateCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNB", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetNB, METH_NOARGS, NULL },
    {(char *) "GetMac", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetMac, METH_NOARGS, NULL },
    {(char *) "RequestCCA", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_RequestCCA, METH_NOARGS, NULL },
    {(char *) "SetMacMaxBE", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetMacMaxBE, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsUnSlottedCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_IsUnSlottedCsmaCa, METH_NOARGS, NULL },
    {(char *) "SetUnSlottedCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetUnSlottedCsmaCa, METH_NOARGS, NULL },
    {(char *) "GetMacMaxBE", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetMacMaxBE, METH_NOARGS, NULL },
    {(char *) "SetSlottedCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetSlottedCsmaCa, METH_NOARGS, NULL },
    {(char *) "SetMac", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetMac, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMacMaxCSMABackoffs", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetMacMaxCSMABackoffs, METH_NOARGS, NULL },
    {(char *) "SetMacMinBE", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_SetMacMinBE, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTimeToNextSlot", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetTimeToNextSlot, METH_NOARGS, NULL },
    {(char *) "IsSlottedCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_IsSlottedCsmaCa, METH_NOARGS, NULL },
    {(char *) "GetMacMinBE", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetMacMinBE, METH_NOARGS, NULL },
    {(char *) "GetUnitBackoffPeriod", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_GetUnitBackoffPeriod, METH_NOARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Cancel", (PyCFunction) _wrap_PyNs3LrWpanCsmaCa_Cancel, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3LrWpanCsmaCa__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3LrWpanCsmaCa__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3LrWpanCsmaCa__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanCsmaCa__tp_clear(PyNs3LrWpanCsmaCa *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LrWpanCsmaCa *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LrWpanCsmaCa__tp_traverse(PyNs3LrWpanCsmaCa *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3LrWpanCsmaCa__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3LrWpanCsmaCa__tp_dealloc(PyNs3LrWpanCsmaCa *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanCsmaCa__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanCsmaCa__tp_richcompare (PyNs3LrWpanCsmaCa *PYBINDGEN_UNUSED(self), PyNs3LrWpanCsmaCa *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanCsmaCa_Type)) {
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

PyTypeObject PyNs3LrWpanCsmaCa_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanCsmaCa",            /* tp_name */
    sizeof(PyNs3LrWpanCsmaCa),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanCsmaCa__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanCsmaCa__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanCsmaCa__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanCsmaCa__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanCsmaCa_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanCsmaCa, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanCsmaCa__tp_init,             /* tp_init */
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
_wrap_PyNs3LrWpanErrorModel__tp_init__0(PyNs3LrWpanErrorModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanErrorModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanErrorModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanErrorModel(*((PyNs3LrWpanErrorModel *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanErrorModel__tp_init__1(PyNs3LrWpanErrorModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanErrorModel();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanErrorModel__tp_init(PyNs3LrWpanErrorModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanErrorModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanErrorModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanErrorModel_GetChunkSuccessRate(PyNs3LrWpanErrorModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    double snr;
    unsigned int nbits;
    const char *keywords[] = {"snr", "nbits", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dI", (char **) keywords, &snr, &nbits)) {
        return NULL;
    }
    retval = self->obj->GetChunkSuccessRate(snr, nbits);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanErrorModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanErrorModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanErrorModel__copy__(PyNs3LrWpanErrorModel *self)
{

    PyNs3LrWpanErrorModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3LrWpanErrorModel, &PyNs3LrWpanErrorModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::LrWpanErrorModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanErrorModel_methods[] = {
    {(char *) "GetChunkSuccessRate", (PyCFunction) _wrap_PyNs3LrWpanErrorModel_GetChunkSuccessRate, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanErrorModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanErrorModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanErrorModel__tp_clear(PyNs3LrWpanErrorModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LrWpanErrorModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LrWpanErrorModel__tp_traverse(PyNs3LrWpanErrorModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3LrWpanErrorModel__tp_dealloc(PyNs3LrWpanErrorModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanErrorModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanErrorModel__tp_richcompare (PyNs3LrWpanErrorModel *PYBINDGEN_UNUSED(self), PyNs3LrWpanErrorModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanErrorModel_Type)) {
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

PyTypeObject PyNs3LrWpanErrorModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanErrorModel",            /* tp_name */
    sizeof(PyNs3LrWpanErrorModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanErrorModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanErrorModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanErrorModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanErrorModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanErrorModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanErrorModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanErrorModel__tp_init,             /* tp_init */
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
_wrap_PyNs3LrWpanInterferenceHelper__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'LrWpanInterferenceHelper' cannot be constructed ()");
    return -1;
}


PyObject *
_wrap_PyNs3LrWpanInterferenceHelper_ClearSignals(PyNs3LrWpanInterferenceHelper *self)
{
    PyObject *py_retval;
    
    self->obj->ClearSignals();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3LrWpanInterferenceHelper_methods[] = {
    {(char *) "ClearSignals", (PyCFunction) _wrap_PyNs3LrWpanInterferenceHelper_ClearSignals, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanInterferenceHelper__tp_dealloc(PyNs3LrWpanInterferenceHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::LrWpanInterferenceHelper *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanInterferenceHelper__tp_richcompare (PyNs3LrWpanInterferenceHelper *PYBINDGEN_UNUSED(self), PyNs3LrWpanInterferenceHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanInterferenceHelper_Type)) {
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

PyTypeObject PyNs3LrWpanInterferenceHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanInterferenceHelper",            /* tp_name */
    sizeof(PyNs3LrWpanInterferenceHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanInterferenceHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanInterferenceHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanInterferenceHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanInterferenceHelper__tp_init,             /* tp_init */
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
PyNs3LrWpanMac__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    PyNs3LrWpanMac__PythonHelper *helper = dynamic_cast< PyNs3LrWpanMac__PythonHelper* >(self->obj);
    
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
PyNs3LrWpanMac__PythonHelper::_wrap_DoInitialize(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    PyNs3LrWpanMac__PythonHelper *helper = dynamic_cast< PyNs3LrWpanMac__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class LrWpanMac is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3LrWpanMac__PythonHelper::_wrap_NotifyNewAggregate(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    PyNs3LrWpanMac__PythonHelper *helper = dynamic_cast< PyNs3LrWpanMac__PythonHelper* >(self->obj);
    
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
PyNs3LrWpanMac__PythonHelper::_wrap_DoDispose(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    PyNs3LrWpanMac__PythonHelper *helper = dynamic_cast< PyNs3LrWpanMac__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class LrWpanMac is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3LrWpanMac__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LrWpanMac *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::LrWpanMac::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = (ns3::LrWpanMac*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3LrWpanMac__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LrWpanMac *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::LrWpanMac::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = (ns3::LrWpanMac*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LrWpanMac* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3LrWpanMac__PythonHelper::GetInstanceTypeId() const
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
PyNs3LrWpanMac__PythonHelper::NotifyNewAggregate()
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
PyNs3LrWpanMac__PythonHelper::NotifyConstructionCompleted()
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
static PyObject* _wrap_PyNs3LrWpanMac__get_m_aBaseSlotDuration(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_aBaseSlotDuration);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_aBaseSlotDuration(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_aBaseSlotDuration)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_aBaseSuperframeDuration(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_aBaseSuperframeDuration);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_aBaseSuperframeDuration(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_aBaseSuperframeDuration)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_aNumSuperframeSlots(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_aNumSuperframeSlots);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_aNumSuperframeSlots(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_aNumSuperframeSlots)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macBeaconOrder(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_macBeaconOrder);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macBeaconOrder(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_macBeaconOrder)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macBeaconTxTime(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_macBeaconTxTime);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macBeaconTxTime(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_macBeaconTxTime)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macDsn(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3SequenceNumber8 *py_SequenceNumber8;
    
    py_SequenceNumber8 = PyObject_New(PyNs3SequenceNumber8, &PyNs3SequenceNumber8_Type);
    py_SequenceNumber8->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_SequenceNumber8->obj = new ns3::SequenceNumber8(self->obj->m_macDsn);
    PyNs3SequenceNumber8_wrapper_registry[(void *) py_SequenceNumber8->obj] = (PyObject *) py_SequenceNumber8;
    py_retval = Py_BuildValue((char *) "N", py_SequenceNumber8);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macDsn(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3SequenceNumber8 *tmp_SequenceNumber8;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3SequenceNumber8_Type, &tmp_SequenceNumber8)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_macDsn = *tmp_SequenceNumber8->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macMaxFrameRetries(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->m_macMaxFrameRetries);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macMaxFrameRetries(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_macMaxFrameRetries = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macPanId(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->m_macPanId);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macPanId(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->m_macPanId = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macPromiscuousMode(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(self->obj->m_macPromiscuousMode));
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macPromiscuousMode(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_macPromiscuousMode = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macRxOnWhenIdle(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(self->obj->m_macRxOnWhenIdle));
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macRxOnWhenIdle(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_macRxOnWhenIdle = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macSuperframeOrder(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_macSuperframeOrder);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macSuperframeOrder(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_macSuperframeOrder)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3LrWpanMac__get_m_macSyncSymbolOffset(PyNs3LrWpanMac *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "K", self->obj->m_macSyncSymbolOffset);
    return py_retval;
}
static int _wrap_PyNs3LrWpanMac__set_m_macSyncSymbolOffset(PyNs3LrWpanMac *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "K", &self->obj->m_macSyncSymbolOffset)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3LrWpanMac__getsets[] = {
    {
        (char*) "m_macRxOnWhenIdle", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macRxOnWhenIdle, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macRxOnWhenIdle, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macPromiscuousMode", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macPromiscuousMode, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macPromiscuousMode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macPanId", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macPanId, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macPanId, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macBeaconTxTime", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macBeaconTxTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macBeaconTxTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macSuperframeOrder", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macSuperframeOrder, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macSuperframeOrder, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_aBaseSlotDuration", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_aBaseSlotDuration, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_aBaseSlotDuration, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macMaxFrameRetries", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macMaxFrameRetries, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macMaxFrameRetries, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macBeaconOrder", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macBeaconOrder, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macBeaconOrder, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macDsn", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macDsn, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macDsn, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_aNumSuperframeSlots", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_aNumSuperframeSlots, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_aNumSuperframeSlots, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_macSyncSymbolOffset", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_macSyncSymbolOffset, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_macSyncSymbolOffset, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_aBaseSuperframeDuration", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_m_aBaseSuperframeDuration, /* C function to get the attribute */
        (setter) _wrap_PyNs3LrWpanMac__set_m_aBaseSuperframeDuration, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};
static PyObject* _wrap_PyNs3LrWpanMac__get_aMinMPDUOverhead(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::LrWpanMac::aMinMPDUOverhead));
    return py_retval;
}
static PyGetSetDef Ns3LrWpanMacMeta__getsets[] = {
    {
        (char*) "aMinMPDUOverhead", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMac__get_aMinMPDUOverhead, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject PyNs3LrWpanMacMeta_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
	(char *) "Ns3LrWpanMacMeta",		        /* tp_name */
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
	Ns3LrWpanMacMeta__getsets,				/* tp_getset */
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
_wrap_PyNs3LrWpanMac__tp_init__0(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanMac *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanMac_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3LrWpanMac_Type)
    {
        self->obj = new PyNs3LrWpanMac__PythonHelper(*((PyNs3LrWpanMac *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LrWpanMac__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LrWpanMac(*((PyNs3LrWpanMac *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3LrWpanMac__tp_init__1(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3LrWpanMac_Type)
    {
        self->obj = new PyNs3LrWpanMac__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LrWpanMac__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LrWpanMac();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3LrWpanMac__tp_init(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanMac__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMac__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanMac_SetShortAddress(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Mac16Address *address;
    const char *keywords[] = {"address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Mac16Address_Type, &address)) {
        return NULL;
    }
    self->obj->SetShortAddress(*((PyNs3Mac16Address *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetPanId(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetPanId();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_PlmeSetAttributeConfirm(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration status;
    ns3::LrWpanPibAttributeIdentifier id;
    const char *keywords[] = {"status", "id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ii", (char **) keywords, &status, &id)) {
        return NULL;
    }
    self->obj->PlmeSetAttributeConfirm(status, id);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_PlmeSetTRXStateConfirm(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration status;
    const char *keywords[] = {"status", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &status)) {
        return NULL;
    }
    self->obj->PlmeSetTRXStateConfirm(status);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanMac::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetPhy(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanPhy *phy;
    ns3::LrWpanPhy *phy_ptr;
    const char *keywords[] = {"phy", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanPhy_Type, &phy)) {
        return NULL;
    }
    phy_ptr = (phy ? phy->obj : NULL);
    self->obj->SetPhy(ns3::Ptr< ns3::LrWpanPhy  > (phy_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_PlmeEdConfirm(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration status;
    int energyLevel;
    const char *keywords[] = {"status", "energyLevel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ii", (char **) keywords, &status, &energyLevel)) {
        return NULL;
    }
    if (energyLevel > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->PlmeEdConfirm(status, energyLevel);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetMcpsDataConfirmCallback(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl6> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl6> (c);
    self->obj->SetMcpsDataConfirmCallback(ns3::Callback<void, ns3::McpsDataConfirmParams, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetMacMaxFrameRetries(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int retries;
    const char *keywords[] = {"retries", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &retries)) {
        return NULL;
    }
    if (retries > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMacMaxFrameRetries(retries);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetExtendedAddress(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Mac64Address *address;
    const char *keywords[] = {"address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Mac64Address_Type, &address)) {
        return NULL;
    }
    self->obj->SetExtendedAddress(*((PyNs3Mac64Address *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_PdDataConfirm(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration status;
    const char *keywords[] = {"status", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &status)) {
        return NULL;
    }
    self->obj->PdDataConfirm(status);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetRxOnWhenIdle(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool rxOnWhenIdle;
    PyObject *py_rxOnWhenIdle;
    const char *keywords[] = {"rxOnWhenIdle", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_rxOnWhenIdle)) {
        return NULL;
    }
    rxOnWhenIdle = (bool) PyObject_IsTrue(py_rxOnWhenIdle);
    self->obj->SetRxOnWhenIdle(rxOnWhenIdle);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_PlmeCcaConfirm(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration status;
    const char *keywords[] = {"status", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &status)) {
        return NULL;
    }
    self->obj->PlmeCcaConfirm(status);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_PdDataIndication(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int psduLength;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    int lqi;
    const char *keywords[] = {"psduLength", "p", "lqi", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!i", (char **) keywords, &psduLength, &PyNs3Packet_Type, &p, &lqi)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    if (lqi > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->PdDataIndication(psduLength, ns3::Ptr< ns3::Packet  > (p_ptr), lqi);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetAssociationStatus(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    ns3::LrWpanAssociationStatus retval;
    
    retval = self->obj->GetAssociationStatus();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_McpsDataRequest(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3McpsDataRequestParams *params;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    const char *keywords[] = {"params", "p", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3McpsDataRequestParams_Type, &params, &PyNs3Packet_Type, &p)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    self->obj->McpsDataRequest(*((PyNs3McpsDataRequestParams *) params)->obj, ns3::Ptr< ns3::Packet  > (p_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetExtendedAddress(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    PyNs3Mac64Address *py_Mac64Address;
    
    ns3::Mac64Address retval = self->obj->GetExtendedAddress();
    py_Mac64Address = PyObject_New(PyNs3Mac64Address, &PyNs3Mac64Address_Type);
    py_Mac64Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac64Address->obj = new ns3::Mac64Address(retval);
    PyNs3Mac64Address_wrapper_registry[(void *) py_Mac64Address->obj] = (PyObject *) py_Mac64Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac64Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetPanId(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int panId;
    const char *keywords[] = {"panId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &panId)) {
        return NULL;
    }
    if (panId > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPanId(panId);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetLrWpanMacState(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanMacState macState;
    const char *keywords[] = {"macState", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &macState)) {
        return NULL;
    }
    self->obj->SetLrWpanMacState(macState);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetMcpsDataIndicationCallback(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl5> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl5> (c);
    self->obj->SetMcpsDataIndicationCallback(ns3::Callback<void, ns3::McpsDataIndicationParams, ns3::Ptr<ns3::Packet>, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetRxOnWhenIdle(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetRxOnWhenIdle();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetMacAckWaitDuration(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    uint64_t retval;
    
    retval = self->obj->GetMacAckWaitDuration();
    py_retval = Py_BuildValue((char *) "K", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetAssociationStatus(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanAssociationStatus status;
    const char *keywords[] = {"status", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &status)) {
        return NULL;
    }
    self->obj->SetAssociationStatus(status);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetPhy(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::LrWpanPhy > retval;
    PyNs3LrWpanPhy *py_LrWpanPhy;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetPhy();
    if (!(const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_LrWpanPhy = NULL;
    } else {
        py_LrWpanPhy = (PyNs3LrWpanPhy *) wrapper_lookup_iter->second;
        Py_INCREF(py_LrWpanPhy);
    }
    
    if (py_LrWpanPhy == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval)))), &PyNs3LrWpanPhy_Type);
        py_LrWpanPhy = PyObject_GC_New(PyNs3LrWpanPhy, wrapper_type);
        py_LrWpanPhy->inst_dict = NULL;
    
        py_LrWpanPhy->inst_dict = NULL;
        py_LrWpanPhy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval))->Ref();
        py_LrWpanPhy->obj = const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_LrWpanPhy->obj] = (PyObject *) py_LrWpanPhy;
    }
    py_retval = Py_BuildValue((char *) "N", py_LrWpanPhy);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetMacMaxFrameRetries(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetMacMaxFrameRetries();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_GetShortAddress(PyNs3LrWpanMac *self)
{
    PyObject *py_retval;
    PyNs3Mac16Address *py_Mac16Address;
    
    ns3::Mac16Address retval = self->obj->GetShortAddress();
    py_Mac16Address = PyObject_New(PyNs3Mac16Address, &PyNs3Mac16Address_Type);
    py_Mac16Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac16Address->obj = new ns3::Mac16Address(retval);
    PyNs3Mac16Address_wrapper_registry[(void *) py_Mac16Address->obj] = (PyObject *) py_Mac16Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac16Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMac_SetCsmaCa(PyNs3LrWpanMac *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanCsmaCa *csmaCa;
    ns3::LrWpanCsmaCa *csmaCa_ptr;
    const char *keywords[] = {"csmaCa", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanCsmaCa_Type, &csmaCa)) {
        return NULL;
    }
    csmaCa_ptr = (csmaCa ? csmaCa->obj : NULL);
    self->obj->SetCsmaCa(ns3::Ptr< ns3::LrWpanCsmaCa  > (csmaCa_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanMac__copy__(PyNs3LrWpanMac *self)
{

    PyNs3LrWpanMac *py_copy;
    py_copy = PyObject_GC_New(PyNs3LrWpanMac, &PyNs3LrWpanMac_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::LrWpanMac(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanMac_methods[] = {
    {(char *) "SetShortAddress", (PyCFunction) _wrap_PyNs3LrWpanMac_SetShortAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPanId", (PyCFunction) _wrap_PyNs3LrWpanMac_GetPanId, METH_NOARGS, NULL },
    {(char *) "PlmeSetAttributeConfirm", (PyCFunction) _wrap_PyNs3LrWpanMac_PlmeSetAttributeConfirm, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeSetTRXStateConfirm", (PyCFunction) _wrap_PyNs3LrWpanMac_PlmeSetTRXStateConfirm, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanMac_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetPhy", (PyCFunction) _wrap_PyNs3LrWpanMac_SetPhy, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeEdConfirm", (PyCFunction) _wrap_PyNs3LrWpanMac_PlmeEdConfirm, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMcpsDataConfirmCallback", (PyCFunction) _wrap_PyNs3LrWpanMac_SetMcpsDataConfirmCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMacMaxFrameRetries", (PyCFunction) _wrap_PyNs3LrWpanMac_SetMacMaxFrameRetries, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetExtendedAddress", (PyCFunction) _wrap_PyNs3LrWpanMac_SetExtendedAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PdDataConfirm", (PyCFunction) _wrap_PyNs3LrWpanMac_PdDataConfirm, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetRxOnWhenIdle", (PyCFunction) _wrap_PyNs3LrWpanMac_SetRxOnWhenIdle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeCcaConfirm", (PyCFunction) _wrap_PyNs3LrWpanMac_PlmeCcaConfirm, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PdDataIndication", (PyCFunction) _wrap_PyNs3LrWpanMac_PdDataIndication, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAssociationStatus", (PyCFunction) _wrap_PyNs3LrWpanMac_GetAssociationStatus, METH_NOARGS, NULL },
    {(char *) "McpsDataRequest", (PyCFunction) _wrap_PyNs3LrWpanMac_McpsDataRequest, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetExtendedAddress", (PyCFunction) _wrap_PyNs3LrWpanMac_GetExtendedAddress, METH_NOARGS, NULL },
    {(char *) "SetPanId", (PyCFunction) _wrap_PyNs3LrWpanMac_SetPanId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLrWpanMacState", (PyCFunction) _wrap_PyNs3LrWpanMac_SetLrWpanMacState, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMcpsDataIndicationCallback", (PyCFunction) _wrap_PyNs3LrWpanMac_SetMcpsDataIndicationCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRxOnWhenIdle", (PyCFunction) _wrap_PyNs3LrWpanMac_GetRxOnWhenIdle, METH_NOARGS, NULL },
    {(char *) "GetMacAckWaitDuration", (PyCFunction) _wrap_PyNs3LrWpanMac_GetMacAckWaitDuration, METH_NOARGS, NULL },
    {(char *) "SetAssociationStatus", (PyCFunction) _wrap_PyNs3LrWpanMac_SetAssociationStatus, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPhy", (PyCFunction) _wrap_PyNs3LrWpanMac_GetPhy, METH_NOARGS, NULL },
    {(char *) "GetMacMaxFrameRetries", (PyCFunction) _wrap_PyNs3LrWpanMac_GetMacMaxFrameRetries, METH_NOARGS, NULL },
    {(char *) "GetShortAddress", (PyCFunction) _wrap_PyNs3LrWpanMac_GetShortAddress, METH_NOARGS, NULL },
    {(char *) "SetCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanMac_SetCsmaCa, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3LrWpanMac__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3LrWpanMac__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3LrWpanMac__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3LrWpanMac__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanMac__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanMac__tp_clear(PyNs3LrWpanMac *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LrWpanMac *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LrWpanMac__tp_traverse(PyNs3LrWpanMac *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3LrWpanMac__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3LrWpanMac__tp_dealloc(PyNs3LrWpanMac *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanMac__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanMac__tp_richcompare (PyNs3LrWpanMac *PYBINDGEN_UNUSED(self), PyNs3LrWpanMac *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanMac_Type)) {
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

PyTypeObject PyNs3LrWpanMac_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanMac",            /* tp_name */
    sizeof(PyNs3LrWpanMac),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanMac__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanMac__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanMac__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanMac__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanMac_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3LrWpanMac__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanMac, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanMac__tp_init,             /* tp_init */
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



static PyObject* _wrap_PyNs3LrWpanMacTrailer__get_LR_WPAN_MAC_FCS_LENGTH(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", ns3::LrWpanMacTrailer::LR_WPAN_MAC_FCS_LENGTH);
    return py_retval;
}
static PyGetSetDef Ns3LrWpanMacTrailerMeta__getsets[] = {
    {
        (char*) "LR_WPAN_MAC_FCS_LENGTH", /* attribute name */
        (getter) _wrap_PyNs3LrWpanMacTrailer__get_LR_WPAN_MAC_FCS_LENGTH, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject PyNs3LrWpanMacTrailerMeta_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
	(char *) "Ns3LrWpanMacTrailerMeta",		        /* tp_name */
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
	Ns3LrWpanMacTrailerMeta__getsets,				/* tp_getset */
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
_wrap_PyNs3LrWpanMacTrailer__tp_init__0(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanMacTrailer *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanMacTrailer_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanMacTrailer(*((PyNs3LrWpanMacTrailer *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanMacTrailer__tp_init__1(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanMacTrailer();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanMacTrailer__tp_init(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanMacTrailer__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanMacTrailer__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanMacTrailer_CheckFcs(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    const char *keywords[] = {"p", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Packet_Type, &p)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    retval = self->obj->CheckFcs(ns3::Ptr< ns3::Packet  > (p_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacTrailer_GetFcs(PyNs3LrWpanMacTrailer *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetFcs();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacTrailer_SetFcs(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    const char *keywords[] = {"p", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Packet_Type, &p)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    self->obj->SetFcs(ns3::Ptr< ns3::Packet  > (p_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacTrailer_Deserialize(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3LrWpanMacTrailer_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanMacTrailer::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacTrailer_Serialize(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3LrWpanMacTrailer_EnableFcs(PyNs3LrWpanMacTrailer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool enable;
    PyObject *py_enable;
    const char *keywords[] = {"enable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_enable)) {
        return NULL;
    }
    enable = (bool) PyObject_IsTrue(py_enable);
    self->obj->EnableFcs(enable);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacTrailer_GetInstanceTypeId(PyNs3LrWpanMacTrailer *self)
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
_wrap_PyNs3LrWpanMacTrailer_GetSerializedSize(PyNs3LrWpanMacTrailer *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanMacTrailer_IsFcsEnabled(PyNs3LrWpanMacTrailer *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsFcsEnabled();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanMacTrailer__copy__(PyNs3LrWpanMacTrailer *self)
{

    PyNs3LrWpanMacTrailer *py_copy;
    py_copy = PyObject_GC_New(PyNs3LrWpanMacTrailer, &PyNs3LrWpanMacTrailer_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::LrWpanMacTrailer(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanMacTrailer_methods[] = {
    {(char *) "CheckFcs", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_CheckFcs, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFcs", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_GetFcs, METH_NOARGS, NULL },
    {(char *) "SetFcs", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_SetFcs, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableFcs", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_EnableFcs, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "IsFcsEnabled", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer_IsFcsEnabled, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanMacTrailer__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanMacTrailer__tp_clear(PyNs3LrWpanMacTrailer *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::LrWpanMacTrailer *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3LrWpanMacTrailer__tp_traverse(PyNs3LrWpanMacTrailer *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3LrWpanMacTrailer__tp_dealloc(PyNs3LrWpanMacTrailer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanMacTrailer__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanMacTrailer__tp_richcompare (PyNs3LrWpanMacTrailer *PYBINDGEN_UNUSED(self), PyNs3LrWpanMacTrailer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanMacTrailer_Type)) {
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

PyTypeObject PyNs3LrWpanMacTrailer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanMacTrailer",            /* tp_name */
    sizeof(PyNs3LrWpanMacTrailer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanMacTrailer__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanMacTrailer__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanMacTrailer__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanMacTrailer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanMacTrailer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanMacTrailer, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanMacTrailer__tp_init,             /* tp_init */
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



static PyObject* _wrap_PyNs3LrWpanPhy__get_aMaxPhyPacketSize(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::LrWpanPhy::aMaxPhyPacketSize));
    return py_retval;
}
static PyObject* _wrap_PyNs3LrWpanPhy__get_aTurnaroundTime(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::LrWpanPhy::aTurnaroundTime));
    return py_retval;
}
static PyGetSetDef Ns3LrWpanPhyMeta__getsets[] = {
    {
        (char*) "aMaxPhyPacketSize", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhy__get_aMaxPhyPacketSize, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "aTurnaroundTime", /* attribute name */
        (getter) _wrap_PyNs3LrWpanPhy__get_aTurnaroundTime, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject PyNs3LrWpanPhyMeta_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
	(char *) "Ns3LrWpanPhyMeta",		        /* tp_name */
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
	Ns3LrWpanPhyMeta__getsets,				/* tp_getset */
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
_wrap_PyNs3LrWpanPhy__tp_init(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::LrWpanPhy();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetPdDataConfirmCallback(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl0> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl0> (c);
    self->obj->SetPdDataConfirmCallback(ns3::Callback<void, ns3::LrWpanPhyEnumeration, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetPlmeSetTRXStateConfirmCallback(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl0> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl0> (c);
    self->obj->SetPlmeSetTRXStateConfirmCallback(ns3::Callback<void, ns3::LrWpanPhyEnumeration, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanPhy::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetPlmeSetAttributeConfirmCallback(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl7> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl7> (c);
    self->obj->SetPlmeSetAttributeConfirmCallback(ns3::Callback<void, ns3::LrWpanPhyEnumeration, ns3::LrWpanPibAttributeIdentifier, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_PlmeGetAttributeRequest(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPibAttributeIdentifier id;
    const char *keywords[] = {"id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &id)) {
        return NULL;
    }
    self->obj->PlmeGetAttributeRequest(id);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_GetPhySHRDuration(PyNs3LrWpanPhy *self)
{
    PyObject *py_retval;
    uint64_t retval;
    
    retval = self->obj->GetPhySHRDuration();
    py_retval = Py_BuildValue((char *) "K", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_GetDataOrSymbolRate(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    bool isData;
    PyObject *py_isData;
    const char *keywords[] = {"isData", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_isData)) {
        return NULL;
    }
    isData = (bool) PyObject_IsTrue(py_isData);
    retval = self->obj->GetDataOrSymbolRate(isData);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_GetPhySymbolsPerOctet(PyNs3LrWpanPhy *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetPhySymbolsPerOctet();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetErrorModel(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanErrorModel *e;
    ns3::LrWpanErrorModel *e_ptr;
    const char *keywords[] = {"e", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanErrorModel_Type, &e)) {
        return NULL;
    }
    e_ptr = (e ? e->obj : NULL);
    self->obj->SetErrorModel(ns3::Ptr< ns3::LrWpanErrorModel  > (e_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_PlmeSetTRXStateRequest(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::LrWpanPhyEnumeration state;
    const char *keywords[] = {"state", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &state)) {
        return NULL;
    }
    self->obj->PlmeSetTRXStateRequest(state);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetPlmeEdConfirmCallback(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl1> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl1> (c);
    self->obj->SetPlmeEdConfirmCallback(ns3::Callback<void, ns3::LrWpanPhyEnumeration, unsigned char, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetPdDataIndicationCallback(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl2> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl2> (c);
    self->obj->SetPdDataIndicationCallback(ns3::Callback<void, unsigned int, ns3::Ptr<ns3::Packet>, unsigned char, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_PlmeCcaRequest(PyNs3LrWpanPhy *self)
{
    PyObject *py_retval;
    
    self->obj->PlmeCcaRequest();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_GetErrorModel(PyNs3LrWpanPhy *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::LrWpanErrorModel > retval;
    PyNs3LrWpanErrorModel *py_LrWpanErrorModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetErrorModel();
    if (!(const_cast<ns3::LrWpanErrorModel *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::LrWpanErrorModel *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_LrWpanErrorModel = NULL;
    } else {
        py_LrWpanErrorModel = (PyNs3LrWpanErrorModel *) wrapper_lookup_iter->second;
        Py_INCREF(py_LrWpanErrorModel);
    }
    
    if (py_LrWpanErrorModel == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::LrWpanErrorModel *> (ns3::PeekPointer (retval)))), &PyNs3LrWpanErrorModel_Type);
        py_LrWpanErrorModel = PyObject_GC_New(PyNs3LrWpanErrorModel, wrapper_type);
        py_LrWpanErrorModel->inst_dict = NULL;
    
        py_LrWpanErrorModel->inst_dict = NULL;
        py_LrWpanErrorModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::LrWpanErrorModel *> (ns3::PeekPointer (retval))->Ref();
        py_LrWpanErrorModel->obj = const_cast<ns3::LrWpanErrorModel *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_LrWpanErrorModel->obj] = (PyObject *) py_LrWpanErrorModel;
    }
    py_retval = Py_BuildValue((char *) "N", py_LrWpanErrorModel);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_PlmeEdRequest(PyNs3LrWpanPhy *self)
{
    PyObject *py_retval;
    
    self->obj->PlmeEdRequest();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_StartRx(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3SpectrumSignalParameters *params;
    ns3::SpectrumSignalParameters *params_ptr;
    const char *keywords[] = {"params", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SpectrumSignalParameters_Type, &params)) {
        return NULL;
    }
    params_ptr = (params ? params->obj : NULL);
    self->obj->StartRx(ns3::Ptr< ns3::SpectrumSignalParameters  > (params_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetDevice(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NetDevice *d;
    ns3::NetDevice *d_ptr;
    const char *keywords[] = {"d", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NetDevice_Type, &d)) {
        return NULL;
    }
    d_ptr = (d ? d->obj : NULL);
    self->obj->SetDevice(ns3::Ptr< ns3::NetDevice  > (d_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_GetDevice(PyNs3LrWpanPhy *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::NetDevice > retval;
    PyNs3NetDevice *py_NetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetDevice();
    if (!(const_cast<ns3::NetDevice *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::NetDevice *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_NetDevice = NULL;
    } else {
        py_NetDevice = (PyNs3NetDevice *) wrapper_lookup_iter->second;
        Py_INCREF(py_NetDevice);
    }
    
    if (py_NetDevice == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::NetDevice *> (ns3::PeekPointer (retval)))), &PyNs3NetDevice_Type);
        py_NetDevice = PyObject_GC_New(PyNs3NetDevice, wrapper_type);
        py_NetDevice->inst_dict = NULL;
    
        py_NetDevice->inst_dict = NULL;
        py_NetDevice->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::NetDevice *> (ns3::PeekPointer (retval))->Ref();
        py_NetDevice->obj = const_cast<ns3::NetDevice *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_NetDevice->obj] = (PyObject *) py_NetDevice;
    }
    py_retval = Py_BuildValue((char *) "N", py_NetDevice);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_SetPlmeCcaConfirmCallback(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *c;
    ns3::Ptr<PythonCallbackImpl0> c_cb_impl;
    const char *keywords[] = {"c", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &c)) {
        return NULL;
    }
    if (!PyCallable_Check(c)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'c' must be callbale");
        return NULL;
    }
    c_cb_impl = ns3::Create<PythonCallbackImpl0> (c);
    self->obj->SetPlmeCcaConfirmCallback(ns3::Callback<void, ns3::LrWpanPhyEnumeration, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (c_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3LrWpanPhy_PdDataRequest(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int psduLength;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    const char *keywords[] = {"psduLength", "p", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &psduLength, &PyNs3Packet_Type, &p)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    self->obj->PdDataRequest(psduLength, ns3::Ptr< ns3::Packet  > (p_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanPhy_AssignStreams(PyNs3LrWpanPhy *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef PyNs3LrWpanPhy_methods[] = {
    {(char *) "SetPdDataConfirmCallback", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetPdDataConfirmCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPlmeSetTRXStateConfirmCallback", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetPlmeSetTRXStateConfirmCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanPhy_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetPlmeSetAttributeConfirmCallback", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetPlmeSetAttributeConfirmCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeGetAttributeRequest", (PyCFunction) _wrap_PyNs3LrWpanPhy_PlmeGetAttributeRequest, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPhySHRDuration", (PyCFunction) _wrap_PyNs3LrWpanPhy_GetPhySHRDuration, METH_NOARGS, NULL },
    {(char *) "GetDataOrSymbolRate", (PyCFunction) _wrap_PyNs3LrWpanPhy_GetDataOrSymbolRate, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPhySymbolsPerOctet", (PyCFunction) _wrap_PyNs3LrWpanPhy_GetPhySymbolsPerOctet, METH_NOARGS, NULL },
    {(char *) "SetErrorModel", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetErrorModel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeSetTRXStateRequest", (PyCFunction) _wrap_PyNs3LrWpanPhy_PlmeSetTRXStateRequest, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPlmeEdConfirmCallback", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetPlmeEdConfirmCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPdDataIndicationCallback", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetPdDataIndicationCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PlmeCcaRequest", (PyCFunction) _wrap_PyNs3LrWpanPhy_PlmeCcaRequest, METH_NOARGS, NULL },
    {(char *) "GetErrorModel", (PyCFunction) _wrap_PyNs3LrWpanPhy_GetErrorModel, METH_NOARGS, NULL },
    {(char *) "PlmeEdRequest", (PyCFunction) _wrap_PyNs3LrWpanPhy_PlmeEdRequest, METH_NOARGS, NULL },
    {(char *) "StartRx", (PyCFunction) _wrap_PyNs3LrWpanPhy_StartRx, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDevice", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetDevice, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDevice", (PyCFunction) _wrap_PyNs3LrWpanPhy_GetDevice, METH_NOARGS, NULL },
    {(char *) "SetPlmeCcaConfirmCallback", (PyCFunction) _wrap_PyNs3LrWpanPhy_SetPlmeCcaConfirmCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PdDataRequest", (PyCFunction) _wrap_PyNs3LrWpanPhy_PdDataRequest, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3LrWpanPhy_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanPhy__tp_clear(PyNs3LrWpanPhy *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LrWpanPhy *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LrWpanPhy__tp_traverse(PyNs3LrWpanPhy *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3LrWpanPhy__tp_dealloc(PyNs3LrWpanPhy *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanPhy__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanPhy__tp_richcompare (PyNs3LrWpanPhy *PYBINDGEN_UNUSED(self), PyNs3LrWpanPhy *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanPhy_Type)) {
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

PyTypeObject PyNs3LrWpanPhy_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanPhy",            /* tp_name */
    sizeof(PyNs3LrWpanPhy),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanPhy__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanPhy__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanPhy__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanPhy__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanPhy_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanPhy, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanPhy__tp_init,             /* tp_init */
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
_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_init__0(PyNs3LrWpanSpectrumSignalParameters *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanSpectrumSignalParameters();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_init__1(PyNs3LrWpanSpectrumSignalParameters *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanSpectrumSignalParameters *p;
    const char *keywords[] = {"p", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanSpectrumSignalParameters_Type, &p)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanSpectrumSignalParameters(*((PyNs3LrWpanSpectrumSignalParameters *) p)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanSpectrumSignalParameters__tp_init(PyNs3LrWpanSpectrumSignalParameters *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanSpectrumSignalParameters__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanSpectrumSignalParameters__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanSpectrumSignalParameters_Copy(PyNs3LrWpanSpectrumSignalParameters *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::SpectrumSignalParameters > retval;
    PyNs3SpectrumSignalParameters *py_SpectrumSignalParameters;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->Copy();
    if (!(const_cast<ns3::SpectrumSignalParameters *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::SpectrumSignalParameters *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_SpectrumSignalParameters = NULL;
    } else {
        py_SpectrumSignalParameters = (PyNs3SpectrumSignalParameters *) wrapper_lookup_iter->second;
        Py_INCREF(py_SpectrumSignalParameters);
    }
    
    if (py_SpectrumSignalParameters == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::SpectrumSignalParameters *> (ns3::PeekPointer (retval)))), &PyNs3SpectrumSignalParameters_Type);
        py_SpectrumSignalParameters = PyObject_New(PyNs3SpectrumSignalParameters, wrapper_type);
    
        py_SpectrumSignalParameters->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::SpectrumSignalParameters *> (ns3::PeekPointer (retval))->Ref();
        py_SpectrumSignalParameters->obj = const_cast<ns3::SpectrumSignalParameters *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_SpectrumSignalParameters->obj] = (PyObject *) py_SpectrumSignalParameters;
    }
    py_retval = Py_BuildValue((char *) "N", py_SpectrumSignalParameters);
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanSpectrumSignalParameters__copy__(PyNs3LrWpanSpectrumSignalParameters *self)
{

    PyNs3LrWpanSpectrumSignalParameters *py_copy;
    py_copy = PyObject_New(PyNs3LrWpanSpectrumSignalParameters, &PyNs3LrWpanSpectrumSignalParameters_Type);
    
    py_copy->obj = new ns3::LrWpanSpectrumSignalParameters(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanSpectrumSignalParameters_methods[] = {
    {(char *) "Copy", (PyCFunction) _wrap_PyNs3LrWpanSpectrumSignalParameters_Copy, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanSpectrumSignalParameters__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_dealloc(PyNs3LrWpanSpectrumSignalParameters *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::LrWpanSpectrumSignalParameters *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_richcompare (PyNs3LrWpanSpectrumSignalParameters *PYBINDGEN_UNUSED(self), PyNs3LrWpanSpectrumSignalParameters *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanSpectrumSignalParameters_Type)) {
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

PyTypeObject PyNs3LrWpanSpectrumSignalParameters_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanSpectrumSignalParameters",            /* tp_name */
    sizeof(PyNs3LrWpanSpectrumSignalParameters),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanSpectrumSignalParameters_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanSpectrumSignalParameters__tp_init,             /* tp_init */
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
_wrap_PyNs3LrWpanNetDevice__tp_init__0(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LrWpanNetDevice *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanNetDevice_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::LrWpanNetDevice(*((PyNs3LrWpanNetDevice *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3LrWpanNetDevice__tp_init__1(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::LrWpanNetDevice();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3LrWpanNetDevice__tp_init(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanNetDevice__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanNetDevice__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanNetDevice_GetMulticast__0(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *multicastGroup;
    const char *keywords[] = {"multicastGroup", NULL};
    PyNs3Address *py_Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &multicastGroup)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Address retval = self->obj->GetMulticast(*((PyNs3Ipv4Address *) multicastGroup)->obj);
    py_Address = PyObject_New(PyNs3Address, &PyNs3Address_Type);
    py_Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Address->obj = new ns3::Address(retval);
    PyNs3Address_wrapper_registry[(void *) py_Address->obj] = (PyObject *) py_Address;
    py_retval = Py_BuildValue((char *) "N", py_Address);
    return py_retval;
}

PyObject *
_wrap_PyNs3LrWpanNetDevice_GetMulticast__1(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *addr;
    const char *keywords[] = {"addr", NULL};
    PyNs3Address *py_Address;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &addr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::Address retval = self->obj->GetMulticast(*((PyNs3Ipv6Address *) addr)->obj);
    py_Address = PyObject_New(PyNs3Address, &PyNs3Address_Type);
    py_Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Address->obj = new ns3::Address(retval);
    PyNs3Address_wrapper_registry[(void *) py_Address->obj] = (PyObject *) py_Address;
    py_retval = Py_BuildValue((char *) "N", py_Address);
    return py_retval;
}

PyObject * _wrap_PyNs3LrWpanNetDevice_GetMulticast(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LrWpanNetDevice_GetMulticast__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LrWpanNetDevice_GetMulticast__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LrWpanNetDevice_IsPointToPoint(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsPointToPoint();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LrWpanNetDevice::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetPhy(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanPhy *phy;
    ns3::LrWpanPhy *phy_ptr;
    const char *keywords[] = {"phy", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanPhy_Type, &phy)) {
        return NULL;
    }
    phy_ptr = (phy ? phy->obj : NULL);
    self->obj->SetPhy(ns3::Ptr< ns3::LrWpanPhy  > (phy_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_Send(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Packet *packet;
    ns3::Packet *packet_ptr;
    PyObject *dest;
    ns3::Address dest2;
    int protocolNumber;
    const char *keywords[] = {"packet", "dest", "protocolNumber", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!Oi", (char **) keywords, &PyNs3Packet_Type, &packet, &dest, &protocolNumber)) {
        return NULL;
    }
    packet_ptr = (packet ? packet->obj : NULL);
    if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Address_Type)) {
        dest2 = *((PyNs3Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Ipv4Address_Type)) {
        dest2 = *((PyNs3Ipv4Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Ipv6Address_Type)) {
        dest2 = *((PyNs3Ipv6Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac16Address_Type)) {
        dest2 = *((PyNs3Mac16Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac48Address_Type)) {
        dest2 = *((PyNs3Mac48Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac64Address_Type)) {
        dest2 = *((PyNs3Mac64Address *) dest)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address), not %s", Py_TYPE(dest)->tp_name);
        return NULL;
    }
    if (protocolNumber > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = self->obj->Send(ns3::Ptr< ns3::Packet  > (packet_ptr), dest2, protocolNumber);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetIfIndex(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetIfIndex();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_NeedsArp(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->NeedsArp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetNode(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetNode();
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
_wrap_PyNs3LrWpanNetDevice_GetMac(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::LrWpanMac > retval;
    PyNs3LrWpanMac *py_LrWpanMac;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetMac();
    if (!(const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3LrWpanMac__PythonHelper).name())
    {
        py_LrWpanMac = reinterpret_cast< PyNs3LrWpanMac* >(reinterpret_cast< PyNs3LrWpanMac__PythonHelper* >(const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))->m_pyself);
        py_LrWpanMac->obj = const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval));
        Py_INCREF(py_LrWpanMac);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_LrWpanMac = NULL;
        } else {
            py_LrWpanMac = (PyNs3LrWpanMac *) wrapper_lookup_iter->second;
            Py_INCREF(py_LrWpanMac);
        }
    
        if (py_LrWpanMac == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval)))), &PyNs3LrWpanMac_Type);
            py_LrWpanMac = PyObject_GC_New(PyNs3LrWpanMac, wrapper_type);
            py_LrWpanMac->inst_dict = NULL;
    
            py_LrWpanMac->inst_dict = NULL;
            py_LrWpanMac->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval))->Ref();
            py_LrWpanMac->obj = const_cast<ns3::LrWpanMac *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_LrWpanMac->obj] = (PyObject *) py_LrWpanMac;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_LrWpanMac);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetCsmaCa(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::LrWpanCsmaCa > retval;
    PyNs3LrWpanCsmaCa *py_LrWpanCsmaCa;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetCsmaCa();
    if (!(const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3LrWpanCsmaCa__PythonHelper).name())
    {
        py_LrWpanCsmaCa = reinterpret_cast< PyNs3LrWpanCsmaCa* >(reinterpret_cast< PyNs3LrWpanCsmaCa__PythonHelper* >(const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval)))->m_pyself);
        py_LrWpanCsmaCa->obj = const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval));
        Py_INCREF(py_LrWpanCsmaCa);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_LrWpanCsmaCa = NULL;
        } else {
            py_LrWpanCsmaCa = (PyNs3LrWpanCsmaCa *) wrapper_lookup_iter->second;
            Py_INCREF(py_LrWpanCsmaCa);
        }
    
        if (py_LrWpanCsmaCa == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval)))), &PyNs3LrWpanCsmaCa_Type);
            py_LrWpanCsmaCa = PyObject_GC_New(PyNs3LrWpanCsmaCa, wrapper_type);
            py_LrWpanCsmaCa->inst_dict = NULL;
    
            py_LrWpanCsmaCa->inst_dict = NULL;
            py_LrWpanCsmaCa->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval))->Ref();
            py_LrWpanCsmaCa->obj = const_cast<ns3::LrWpanCsmaCa *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_LrWpanCsmaCa->obj] = (PyObject *) py_LrWpanCsmaCa;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_LrWpanCsmaCa);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SendFrom(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Packet *packet;
    ns3::Packet *packet_ptr;
    PyObject *source;
    ns3::Address source2;
    PyObject *dest;
    ns3::Address dest2;
    int protocolNumber;
    const char *keywords[] = {"packet", "source", "dest", "protocolNumber", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!OOi", (char **) keywords, &PyNs3Packet_Type, &packet, &source, &dest, &protocolNumber)) {
        return NULL;
    }
    packet_ptr = (packet ? packet->obj : NULL);
    if (PyObject_IsInstance(source, (PyObject*) &PyNs3Address_Type)) {
        source2 = *((PyNs3Address *) source)->obj;
    } else if (PyObject_IsInstance(source, (PyObject*) &PyNs3Ipv4Address_Type)) {
        source2 = *((PyNs3Ipv4Address *) source)->obj;
    } else if (PyObject_IsInstance(source, (PyObject*) &PyNs3Ipv6Address_Type)) {
        source2 = *((PyNs3Ipv6Address *) source)->obj;
    } else if (PyObject_IsInstance(source, (PyObject*) &PyNs3Mac16Address_Type)) {
        source2 = *((PyNs3Mac16Address *) source)->obj;
    } else if (PyObject_IsInstance(source, (PyObject*) &PyNs3Mac48Address_Type)) {
        source2 = *((PyNs3Mac48Address *) source)->obj;
    } else if (PyObject_IsInstance(source, (PyObject*) &PyNs3Mac64Address_Type)) {
        source2 = *((PyNs3Mac64Address *) source)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address), not %s", Py_TYPE(source)->tp_name);
        return NULL;
    }
    if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Address_Type)) {
        dest2 = *((PyNs3Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Ipv4Address_Type)) {
        dest2 = *((PyNs3Ipv4Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Ipv6Address_Type)) {
        dest2 = *((PyNs3Ipv6Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac16Address_Type)) {
        dest2 = *((PyNs3Mac16Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac48Address_Type)) {
        dest2 = *((PyNs3Mac48Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac64Address_Type)) {
        dest2 = *((PyNs3Mac64Address *) dest)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address), not %s", Py_TYPE(dest)->tp_name);
        return NULL;
    }
    if (protocolNumber > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = self->obj->SendFrom(ns3::Ptr< ns3::Packet  > (packet_ptr), source2, dest2, protocolNumber);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_IsBroadcast(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBroadcast();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetMtu(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMtu();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_IsBridge(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBridge();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetNode(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    self->obj->SetNode(ns3::Ptr< ns3::Node  > (node_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetAddress(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    PyNs3Address *py_Address;
    
    ns3::Address retval = self->obj->GetAddress();
    py_Address = PyObject_New(PyNs3Address, &PyNs3Address_Type);
    py_Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Address->obj = new ns3::Address(retval);
    PyNs3Address_wrapper_registry[(void *) py_Address->obj] = (PyObject *) py_Address;
    py_retval = Py_BuildValue((char *) "N", py_Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_IsLinkUp(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsLinkUp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetIfIndex(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    self->obj->SetIfIndex(index);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetMac(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanMac *mac;
    ns3::LrWpanMac *mac_ptr;
    const char *keywords[] = {"mac", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanMac_Type, &mac)) {
        return NULL;
    }
    mac_ptr = (mac ? mac->obj : NULL);
    self->obj->SetMac(ns3::Ptr< ns3::LrWpanMac  > (mac_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetAddress(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *address;
    ns3::Address address2;
    const char *keywords[] = {"address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &address)) {
        return NULL;
    }
    if (PyObject_IsInstance(address, (PyObject*) &PyNs3Address_Type)) {
        address2 = *((PyNs3Address *) address)->obj;
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
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac16Address, Mac48Address, Mac64Address), not %s", Py_TYPE(address)->tp_name);
        return NULL;
    }
    self->obj->SetAddress(address2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetBroadcast(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    PyNs3Address *py_Address;
    
    ns3::Address retval = self->obj->GetBroadcast();
    py_Address = PyObject_New(PyNs3Address, &PyNs3Address_Type);
    py_Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Address->obj = new ns3::Address(retval);
    PyNs3Address_wrapper_registry[(void *) py_Address->obj] = (PyObject *) py_Address;
    py_retval = Py_BuildValue((char *) "N", py_Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetReceiveCallback(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *cb;
    ns3::Ptr<PythonCallbackImpl8> cb_cb_impl;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &cb)) {
        return NULL;
    }
    if (!PyCallable_Check(cb)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'cb' must be callbale");
        return NULL;
    }
    cb_cb_impl = ns3::Create<PythonCallbackImpl8> (cb);
    self->obj->SetReceiveCallback(ns3::Callback<bool, ns3::Ptr<ns3::NetDevice>, ns3::Ptr<ns3::Packet const>, unsigned short, ns3::Address const&, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (cb_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_IsMulticast(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsMulticast();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetMtu(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    int mtu;
    const char *keywords[] = {"mtu", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &mtu)) {
        return NULL;
    }
    if (mtu > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = self->obj->SetMtu(mtu);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_GetPhy(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::LrWpanPhy > retval;
    PyNs3LrWpanPhy *py_LrWpanPhy;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetPhy();
    if (!(const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_LrWpanPhy = NULL;
    } else {
        py_LrWpanPhy = (PyNs3LrWpanPhy *) wrapper_lookup_iter->second;
        Py_INCREF(py_LrWpanPhy);
    }
    
    if (py_LrWpanPhy == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval)))), &PyNs3LrWpanPhy_Type);
        py_LrWpanPhy = PyObject_GC_New(PyNs3LrWpanPhy, wrapper_type);
        py_LrWpanPhy->inst_dict = NULL;
    
        py_LrWpanPhy->inst_dict = NULL;
        py_LrWpanPhy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval))->Ref();
        py_LrWpanPhy->obj = const_cast<ns3::LrWpanPhy *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_LrWpanPhy->obj] = (PyObject *) py_LrWpanPhy;
    }
    py_retval = Py_BuildValue((char *) "N", py_LrWpanPhy);
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_SupportsSendFrom(PyNs3LrWpanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->SupportsSendFrom();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_McpsDataIndication(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3McpsDataIndicationParams *params;
    PyNs3Packet *pkt;
    ns3::Packet *pkt_ptr;
    const char *keywords[] = {"params", "pkt", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3McpsDataIndicationParams_Type, &params, &PyNs3Packet_Type, &pkt)) {
        return NULL;
    }
    pkt_ptr = (pkt ? pkt->obj : NULL);
    self->obj->McpsDataIndication(*((PyNs3McpsDataIndicationParams *) params)->obj, ns3::Ptr< ns3::Packet  > (pkt_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LrWpanNetDevice_AssignStreams(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
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


PyObject *
_wrap_PyNs3LrWpanNetDevice_SetCsmaCa(PyNs3LrWpanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3LrWpanCsmaCa *csmaca;
    ns3::LrWpanCsmaCa *csmaca_ptr;
    const char *keywords[] = {"csmaca", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LrWpanCsmaCa_Type, &csmaca)) {
        return NULL;
    }
    csmaca_ptr = (csmaca ? csmaca->obj : NULL);
    self->obj->SetCsmaCa(ns3::Ptr< ns3::LrWpanCsmaCa  > (csmaca_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3LrWpanNetDevice__copy__(PyNs3LrWpanNetDevice *self)
{

    PyNs3LrWpanNetDevice *py_copy;
    py_copy = PyObject_GC_New(PyNs3LrWpanNetDevice, &PyNs3LrWpanNetDevice_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::LrWpanNetDevice(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LrWpanNetDevice_methods[] = {
    {(char *) "GetMulticast", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetMulticast, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsPointToPoint", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_IsPointToPoint, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetPhy", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetPhy, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Send", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_Send, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetIfIndex", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetIfIndex, METH_NOARGS, NULL },
    {(char *) "NeedsArp", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_NeedsArp, METH_NOARGS, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetNode, METH_NOARGS, NULL },
    {(char *) "GetMac", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetMac, METH_NOARGS, NULL },
    {(char *) "GetCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetCsmaCa, METH_NOARGS, NULL },
    {(char *) "SendFrom", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SendFrom, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsBroadcast", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_IsBroadcast, METH_NOARGS, NULL },
    {(char *) "GetMtu", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetMtu, METH_NOARGS, NULL },
    {(char *) "IsBridge", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_IsBridge, METH_NOARGS, NULL },
    {(char *) "SetNode", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAddress", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetAddress, METH_NOARGS, NULL },
    {(char *) "IsLinkUp", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_IsLinkUp, METH_NOARGS, NULL },
    {(char *) "SetIfIndex", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetIfIndex, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMac", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetMac, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAddress", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBroadcast", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetBroadcast, METH_NOARGS, NULL },
    {(char *) "SetReceiveCallback", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetReceiveCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsMulticast", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_IsMulticast, METH_NOARGS, NULL },
    {(char *) "SetMtu", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetMtu, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPhy", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_GetPhy, METH_NOARGS, NULL },
    {(char *) "SupportsSendFrom", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SupportsSendFrom, METH_NOARGS, NULL },
    {(char *) "McpsDataIndication", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_McpsDataIndication, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetCsmaCa", (PyCFunction) _wrap_PyNs3LrWpanNetDevice_SetCsmaCa, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LrWpanNetDevice__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LrWpanNetDevice__tp_clear(PyNs3LrWpanNetDevice *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LrWpanNetDevice *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LrWpanNetDevice__tp_traverse(PyNs3LrWpanNetDevice *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3LrWpanNetDevice__tp_dealloc(PyNs3LrWpanNetDevice *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LrWpanNetDevice__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LrWpanNetDevice__tp_richcompare (PyNs3LrWpanNetDevice *PYBINDGEN_UNUSED(self), PyNs3LrWpanNetDevice *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LrWpanNetDevice_Type)) {
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

PyTypeObject PyNs3LrWpanNetDevice_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "lr_wpan.LrWpanNetDevice",            /* tp_name */
    sizeof(PyNs3LrWpanNetDevice),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LrWpanNetDevice__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LrWpanNetDevice__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LrWpanNetDevice__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LrWpanNetDevice__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LrWpanNetDevice_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LrWpanNetDevice, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LrWpanNetDevice__tp_init,             /* tp_init */
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
static struct PyModuleDef lr_wpan_moduledef = {
    PyModuleDef_HEAD_INIT,
    "lr_wpan",
    NULL,
    -1,
    lr_wpan_functions,
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


MOD_INIT(lr_wpan)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&lr_wpan_moduledef);
    #else
    m = Py_InitModule3((char *) "lr_wpan", lr_wpan_functions, NULL);
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
    /* Import the 'ns3::SequenceNumber8' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SequenceNumber8_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SequenceNumber8");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SequenceNumber8_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3SequenceNumber8_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3SequenceNumber8_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::SimpleRefCount< ns3::SpectrumSignalParameters, ns3::empty, ns3::DefaultDeleter<ns3::SpectrumSignalParameters> >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt___Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt__");
    
        if (PyErr_Occurred()) PyErr_Clear();
        /* Import the 'ns3::SimpleRefCount< ns3::SpectrumSignalParameters, ns3::empty, ns3::DefaultDeleter<ns3::SpectrumSignalParameters> >' class type map from module 'ns.core' */
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt____typeid_map");
        if (_cobj == NULL) {
            _PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt____typeid_map = new pybindgen::TypeMap;
            PyErr_Clear();
        } else {
            _PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt____typeid_map = reinterpret_cast<pybindgen::TypeMap*> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::SpectrumPhy' class from module 'ns.spectrum' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.spectrum");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SpectrumPhy_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SpectrumPhy");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::SpectrumSignalParameters' class from module 'ns.spectrum' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.spectrum");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SpectrumSignalParameters_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SpectrumSignalParameters");
    
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
    /* Import the 'ns3::DoubleValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DoubleValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DoubleValue");
    
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
    /* Import the 'ns3::EventImpl' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EventImpl_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EventImpl");
    
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
    PyModule_AddObject(m, (char *) "_PyNs3LrWpanEdPower_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3LrWpanEdPower_wrapper_registry, NULL));
    /* Register the 'ns3::LrWpanEdPower' class */
    if (PyType_Ready(&PyNs3LrWpanEdPower_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanEdPower", (PyObject *) &PyNs3LrWpanEdPower_Type);
    PyModule_AddObject(m, (char *) "_PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3LrWpanPhyDataAndSymbolRates_wrapper_registry, NULL));
    /* Register the 'ns3::LrWpanPhyDataAndSymbolRates' class */
    if (PyType_Ready(&PyNs3LrWpanPhyDataAndSymbolRates_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanPhyDataAndSymbolRates", (PyObject *) &PyNs3LrWpanPhyDataAndSymbolRates_Type);
    PyModule_AddObject(m, (char *) "_PyNs3LrWpanPhyPibAttributes_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3LrWpanPhyPibAttributes_wrapper_registry, NULL));
    /* Register the 'ns3::LrWpanPhyPibAttributes' class */
    if (PyType_Ready(&PyNs3LrWpanPhyPibAttributes_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanPhyPibAttributes", (PyObject *) &PyNs3LrWpanPhyPibAttributes_Type);
    PyModule_AddObject(m, (char *) "_PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3LrWpanPhyPpduHeaderSymbolNumber_wrapper_registry, NULL));
    /* Register the 'ns3::LrWpanPhyPpduHeaderSymbolNumber' class */
    if (PyType_Ready(&PyNs3LrWpanPhyPpduHeaderSymbolNumber_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanPhyPpduHeaderSymbolNumber", (PyObject *) &PyNs3LrWpanPhyPpduHeaderSymbolNumber_Type);
    PyModule_AddObject(m, (char *) "_PyNs3LrWpanSpectrumValueHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3LrWpanSpectrumValueHelper_wrapper_registry, NULL));
    /* Register the 'ns3::LrWpanSpectrumValueHelper' class */
    if (PyType_Ready(&PyNs3LrWpanSpectrumValueHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanSpectrumValueHelper", (PyObject *) &PyNs3LrWpanSpectrumValueHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3McpsDataConfirmParams_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3McpsDataConfirmParams_wrapper_registry, NULL));
    /* Register the 'ns3::McpsDataConfirmParams' class */
    if (PyType_Ready(&PyNs3McpsDataConfirmParams_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "McpsDataConfirmParams", (PyObject *) &PyNs3McpsDataConfirmParams_Type);
    PyModule_AddObject(m, (char *) "_PyNs3McpsDataIndicationParams_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3McpsDataIndicationParams_wrapper_registry, NULL));
    /* Register the 'ns3::McpsDataIndicationParams' class */
    if (PyType_Ready(&PyNs3McpsDataIndicationParams_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "McpsDataIndicationParams", (PyObject *) &PyNs3McpsDataIndicationParams_Type);
    PyModule_AddObject(m, (char *) "_PyNs3McpsDataRequestParams_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3McpsDataRequestParams_wrapper_registry, NULL));
    /* Register the 'ns3::McpsDataRequestParams' class */
    if (PyType_Ready(&PyNs3McpsDataRequestParams_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "McpsDataRequestParams", (PyObject *) &PyNs3McpsDataRequestParams_Type);
    PyModule_AddObject(m, (char *) "_PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3TracedValue__Ns3LrWpanMacState_wrapper_registry, NULL));
    /* Register the 'ns3::TracedValue< ns3::LrWpanMacState >' class */
    if (PyType_Ready(&PyNs3TracedValue__Ns3LrWpanMacState_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "TracedValue__Ns3LrWpanMacState", (PyObject *) &PyNs3TracedValue__Ns3LrWpanMacState_Type);
    PyModule_AddObject(m, (char *) "_PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3TracedValue__Ns3LrWpanPhyEnumeration_wrapper_registry, NULL));
    /* Register the 'ns3::TracedValue< ns3::LrWpanPhyEnumeration >' class */
    if (PyType_Ready(&PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "TracedValue__Ns3LrWpanPhyEnumeration", (PyObject *) &PyNs3TracedValue__Ns3LrWpanPhyEnumeration_Type);
    /* Register the 'ns3::LrWpanHelper' class */
    PyNs3LrWpanHelper_Type.tp_base = &PyNs3PcapHelperForDevice_Type;
    PyNs3LrWpanHelper_Type.tp_bases = PyTuple_New(2);
        Py_INCREF((PyObject *) &PyNs3PcapHelperForDevice_Type);
        PyTuple_SET_ITEM(PyNs3LrWpanHelper_Type.tp_bases, 0, (PyObject *) &PyNs3PcapHelperForDevice_Type);
        Py_INCREF((PyObject *) &PyNs3AsciiTraceHelperForDevice_Type);
        PyTuple_SET_ITEM(PyNs3LrWpanHelper_Type.tp_bases, 1, (PyObject *) &PyNs3AsciiTraceHelperForDevice_Type);
    if (PyType_Ready(&PyNs3LrWpanHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanHelper", (PyObject *) &PyNs3LrWpanHelper_Type);
    /* Register the 'ns3::LrWpanLqiTag' class */
    PyNs3LrWpanLqiTag_Type.tp_base = &PyNs3Tag_Type;
    if (PyType_Ready(&PyNs3LrWpanLqiTag_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanLqiTag", (PyObject *) &PyNs3LrWpanLqiTag_Type);
    /* Register the 'ns3::LrWpanMacHeader' class */
    PyNs3LrWpanMacHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3LrWpanMacHeader_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanMacHeader", (PyObject *) &PyNs3LrWpanMacHeader_Type);
    PyModule_AddObject(m, (char *) "_PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____typeid_map", PyCObject_FromVoidPtr(&PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____typeid_map, NULL));
    PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____typeid_map.register_wrapper(typeid(ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> >), &PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type);
    /* Register the 'ns3::SimpleRefCount< ns3::LrWpanInterferenceHelper, ns3::empty, ns3::DefaultDeleter<ns3::LrWpanInterferenceHelper> >' class */
    PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type.tp_base = &PyNs3Empty_Type;
    if (PyType_Ready(&PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt__", (PyObject *) &PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LrWpanCsmaCa), &PyNs3LrWpanCsmaCa_Type);
    /* Register the 'ns3::LrWpanCsmaCa' class */
    PyNs3LrWpanCsmaCa_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3LrWpanCsmaCa_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanCsmaCa", (PyObject *) &PyNs3LrWpanCsmaCa_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LrWpanErrorModel), &PyNs3LrWpanErrorModel_Type);
    /* Register the 'ns3::LrWpanErrorModel' class */
    PyNs3LrWpanErrorModel_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3LrWpanErrorModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanErrorModel", (PyObject *) &PyNs3LrWpanErrorModel_Type);
    PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt____typeid_map.register_wrapper(typeid(ns3::LrWpanInterferenceHelper), &PyNs3LrWpanInterferenceHelper_Type);
    /* Register the 'ns3::LrWpanInterferenceHelper' class */
    PyNs3LrWpanInterferenceHelper_Type.tp_base = &PyNs3SimpleRefCount__Ns3LrWpanInterferenceHelper_Ns3Empty_Ns3DefaultDeleter__lt__ns3LrWpanInterferenceHelper__gt___Type;
    if (PyType_Ready(&PyNs3LrWpanInterferenceHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanInterferenceHelper", (PyObject *) &PyNs3LrWpanInterferenceHelper_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LrWpanMac), &PyNs3LrWpanMac_Type);
    /* Register the 'ns3::LrWpanMac' class */
    
    PyNs3LrWpanMacMeta_Type.tp_base = Py_TYPE(&PyNs3Object_Type);
    /* Some fields need to be manually inheritted from the parent metaclass */
    PyNs3LrWpanMacMeta_Type.tp_traverse = Py_TYPE(&PyNs3Object_Type)->tp_traverse;
    PyNs3LrWpanMacMeta_Type.tp_clear = Py_TYPE(&PyNs3Object_Type)->tp_clear;
    PyNs3LrWpanMacMeta_Type.tp_is_gc = Py_TYPE(&PyNs3Object_Type)->tp_is_gc;
    /* PyType tp_setattro is too restrictive */
    PyNs3LrWpanMacMeta_Type.tp_setattro = PyObject_GenericSetAttr;
    PyType_Ready(&PyNs3LrWpanMacMeta_Type);
    
    PyNs3LrWpanMac_Type.tp_base = &PyNs3Object_Type;
    Py_TYPE(&PyNs3LrWpanMac_Type) = &PyNs3LrWpanMacMeta_Type;
    if (PyType_Ready(&PyNs3LrWpanMac_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanMac", (PyObject *) &PyNs3LrWpanMac_Type);
    /* Register the 'ns3::LrWpanMacTrailer' class */
    
    PyNs3LrWpanMacTrailerMeta_Type.tp_base = Py_TYPE(&PyNs3Trailer_Type);
    /* Some fields need to be manually inheritted from the parent metaclass */
    PyNs3LrWpanMacTrailerMeta_Type.tp_traverse = Py_TYPE(&PyNs3Trailer_Type)->tp_traverse;
    PyNs3LrWpanMacTrailerMeta_Type.tp_clear = Py_TYPE(&PyNs3Trailer_Type)->tp_clear;
    PyNs3LrWpanMacTrailerMeta_Type.tp_is_gc = Py_TYPE(&PyNs3Trailer_Type)->tp_is_gc;
    /* PyType tp_setattro is too restrictive */
    PyNs3LrWpanMacTrailerMeta_Type.tp_setattro = PyObject_GenericSetAttr;
    PyType_Ready(&PyNs3LrWpanMacTrailerMeta_Type);
    
    PyNs3LrWpanMacTrailer_Type.tp_base = &PyNs3Trailer_Type;
    Py_TYPE(&PyNs3LrWpanMacTrailer_Type) = &PyNs3LrWpanMacTrailerMeta_Type;
    if (PyType_Ready(&PyNs3LrWpanMacTrailer_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanMacTrailer", (PyObject *) &PyNs3LrWpanMacTrailer_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LrWpanPhy), &PyNs3LrWpanPhy_Type);
    /* Register the 'ns3::LrWpanPhy' class */
    
    PyNs3LrWpanPhyMeta_Type.tp_base = Py_TYPE(&PyNs3SpectrumPhy_Type);
    /* Some fields need to be manually inheritted from the parent metaclass */
    PyNs3LrWpanPhyMeta_Type.tp_traverse = Py_TYPE(&PyNs3SpectrumPhy_Type)->tp_traverse;
    PyNs3LrWpanPhyMeta_Type.tp_clear = Py_TYPE(&PyNs3SpectrumPhy_Type)->tp_clear;
    PyNs3LrWpanPhyMeta_Type.tp_is_gc = Py_TYPE(&PyNs3SpectrumPhy_Type)->tp_is_gc;
    /* PyType tp_setattro is too restrictive */
    PyNs3LrWpanPhyMeta_Type.tp_setattro = PyObject_GenericSetAttr;
    PyType_Ready(&PyNs3LrWpanPhyMeta_Type);
    
    PyNs3LrWpanPhy_Type.tp_base = &PyNs3SpectrumPhy_Type;
    Py_TYPE(&PyNs3LrWpanPhy_Type) = &PyNs3LrWpanPhyMeta_Type;
    if (PyType_Ready(&PyNs3LrWpanPhy_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanPhy", (PyObject *) &PyNs3LrWpanPhy_Type);
    PyNs3SimpleRefCount__Ns3SpectrumSignalParameters_Ns3Empty_Ns3DefaultDeleter__lt__ns3SpectrumSignalParameters__gt____typeid_map.register_wrapper(typeid(ns3::LrWpanSpectrumSignalParameters), &PyNs3LrWpanSpectrumSignalParameters_Type);
    /* Register the 'ns3::LrWpanSpectrumSignalParameters' class */
    PyNs3LrWpanSpectrumSignalParameters_Type.tp_base = &PyNs3SpectrumSignalParameters_Type;
    if (PyType_Ready(&PyNs3LrWpanSpectrumSignalParameters_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanSpectrumSignalParameters", (PyObject *) &PyNs3LrWpanSpectrumSignalParameters_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LrWpanNetDevice), &PyNs3LrWpanNetDevice_Type);
    /* Register the 'ns3::LrWpanNetDevice' class */
    PyNs3LrWpanNetDevice_Type.tp_base = &PyNs3NetDevice_Type;
    if (PyType_Ready(&PyNs3LrWpanNetDevice_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LrWpanNetDevice", (PyObject *) &PyNs3LrWpanNetDevice_Type);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_BUSY", ns3::IEEE_802_15_4_PHY_BUSY);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_BUSY_RX", ns3::IEEE_802_15_4_PHY_BUSY_RX);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_BUSY_TX", ns3::IEEE_802_15_4_PHY_BUSY_TX);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_FORCE_TRX_OFF", ns3::IEEE_802_15_4_PHY_FORCE_TRX_OFF);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_IDLE", ns3::IEEE_802_15_4_PHY_IDLE);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_INVALID_PARAMETER", ns3::IEEE_802_15_4_PHY_INVALID_PARAMETER);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_RX_ON", ns3::IEEE_802_15_4_PHY_RX_ON);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_SUCCESS", ns3::IEEE_802_15_4_PHY_SUCCESS);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_TRX_OFF", ns3::IEEE_802_15_4_PHY_TRX_OFF);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_TX_ON", ns3::IEEE_802_15_4_PHY_TX_ON);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_UNSUPPORTED_ATTRIBUTE", ns3::IEEE_802_15_4_PHY_UNSUPPORTED_ATTRIBUTE);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_READ_ONLY", ns3::IEEE_802_15_4_PHY_READ_ONLY);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_PHY_UNSPECIFIED", ns3::IEEE_802_15_4_PHY_UNSPECIFIED);
    PyModule_AddIntConstant(m, (char *) "TX_OPTION_NONE", ns3::TX_OPTION_NONE);
    PyModule_AddIntConstant(m, (char *) "TX_OPTION_ACK", ns3::TX_OPTION_ACK);
    PyModule_AddIntConstant(m, (char *) "TX_OPTION_GTS", ns3::TX_OPTION_GTS);
    PyModule_AddIntConstant(m, (char *) "TX_OPTION_INDIRECT", ns3::TX_OPTION_INDIRECT);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_SUCCESS", ns3::IEEE_802_15_4_SUCCESS);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_TRANSACTION_OVERFLOW", ns3::IEEE_802_15_4_TRANSACTION_OVERFLOW);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_TRANSACTION_EXPIRED", ns3::IEEE_802_15_4_TRANSACTION_EXPIRED);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_CHANNEL_ACCESS_FAILURE", ns3::IEEE_802_15_4_CHANNEL_ACCESS_FAILURE);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_INVALID_ADDRESS", ns3::IEEE_802_15_4_INVALID_ADDRESS);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_INVALID_GTS", ns3::IEEE_802_15_4_INVALID_GTS);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_NO_ACK", ns3::IEEE_802_15_4_NO_ACK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_COUNTER_ERROR", ns3::IEEE_802_15_4_COUNTER_ERROR);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_FRAME_TOO_LONG", ns3::IEEE_802_15_4_FRAME_TOO_LONG);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_UNAVAILABLE_KEY", ns3::IEEE_802_15_4_UNAVAILABLE_KEY);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_UNSUPPORTED_SECURITY", ns3::IEEE_802_15_4_UNSUPPORTED_SECURITY);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_INVALID_PARAMETER", ns3::IEEE_802_15_4_INVALID_PARAMETER);
    PyModule_AddIntConstant(m, (char *) "phyCurrentChannel", ns3::phyCurrentChannel);
    PyModule_AddIntConstant(m, (char *) "phyChannelsSupported", ns3::phyChannelsSupported);
    PyModule_AddIntConstant(m, (char *) "phyTransmitPower", ns3::phyTransmitPower);
    PyModule_AddIntConstant(m, (char *) "phyCCAMode", ns3::phyCCAMode);
    PyModule_AddIntConstant(m, (char *) "phyCurrentPage", ns3::phyCurrentPage);
    PyModule_AddIntConstant(m, (char *) "phyMaxFrameDuration", ns3::phyMaxFrameDuration);
    PyModule_AddIntConstant(m, (char *) "phySHRDuration", ns3::phySHRDuration);
    PyModule_AddIntConstant(m, (char *) "phySymbolsPerOctet", ns3::phySymbolsPerOctet);
    PyModule_AddIntConstant(m, (char *) "MAC_IDLE", ns3::MAC_IDLE);
    PyModule_AddIntConstant(m, (char *) "MAC_CSMA", ns3::MAC_CSMA);
    PyModule_AddIntConstant(m, (char *) "MAC_SENDING", ns3::MAC_SENDING);
    PyModule_AddIntConstant(m, (char *) "MAC_ACK_PENDING", ns3::MAC_ACK_PENDING);
    PyModule_AddIntConstant(m, (char *) "CHANNEL_ACCESS_FAILURE", ns3::CHANNEL_ACCESS_FAILURE);
    PyModule_AddIntConstant(m, (char *) "CHANNEL_IDLE", ns3::CHANNEL_IDLE);
    PyModule_AddIntConstant(m, (char *) "SET_PHY_TX_ON", ns3::SET_PHY_TX_ON);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_868MHZ_BPSK", ns3::IEEE_802_15_4_868MHZ_BPSK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_915MHZ_BPSK", ns3::IEEE_802_15_4_915MHZ_BPSK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_868MHZ_ASK", ns3::IEEE_802_15_4_868MHZ_ASK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_915MHZ_ASK", ns3::IEEE_802_15_4_915MHZ_ASK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_868MHZ_OQPSK", ns3::IEEE_802_15_4_868MHZ_OQPSK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_915MHZ_OQPSK", ns3::IEEE_802_15_4_915MHZ_OQPSK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_2_4GHZ_OQPSK", ns3::IEEE_802_15_4_2_4GHZ_OQPSK);
    PyModule_AddIntConstant(m, (char *) "IEEE_802_15_4_INVALID_PHY_OPTION", ns3::IEEE_802_15_4_INVALID_PHY_OPTION);
    PyModule_AddIntConstant(m, (char *) "ASSOCIATED", ns3::ASSOCIATED);
    PyModule_AddIntConstant(m, (char *) "PAN_AT_CAPACITY", ns3::PAN_AT_CAPACITY);
    PyModule_AddIntConstant(m, (char *) "PAN_ACCESS_DENIED", ns3::PAN_ACCESS_DENIED);
    PyModule_AddIntConstant(m, (char *) "ASSOCIATED_WITHOUT_ADDRESS", ns3::ASSOCIATED_WITHOUT_ADDRESS);
    PyModule_AddIntConstant(m, (char *) "DISASSOCIATED", ns3::DISASSOCIATED);
    PyModule_AddIntConstant(m, (char *) "NO_PANID_ADDR", ns3::NO_PANID_ADDR);
    PyModule_AddIntConstant(m, (char *) "ADDR_MODE_RESERVED", ns3::ADDR_MODE_RESERVED);
    PyModule_AddIntConstant(m, (char *) "SHORT_ADDR", ns3::SHORT_ADDR);
    PyModule_AddIntConstant(m, (char *) "EXT_ADDR", ns3::EXT_ADDR);
    {
        PyObject *tmp_value;
         // ns3::LrWpanMacHeader::LRWPAN_MAC_BEACON
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::LRWPAN_MAC_BEACON);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "LRWPAN_MAC_BEACON", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::LRWPAN_MAC_DATA
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::LRWPAN_MAC_DATA);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "LRWPAN_MAC_DATA", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::LRWPAN_MAC_ACKNOWLEDGMENT
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::LRWPAN_MAC_ACKNOWLEDGMENT);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "LRWPAN_MAC_ACKNOWLEDGMENT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::LRWPAN_MAC_COMMAND
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::LRWPAN_MAC_COMMAND);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "LRWPAN_MAC_COMMAND", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::LRWPAN_MAC_RESERVED
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::LRWPAN_MAC_RESERVED);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "LRWPAN_MAC_RESERVED", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::LrWpanMacHeader::NOADDR
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::NOADDR);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "NOADDR", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::RESADDR
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::RESADDR);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "RESADDR", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::SHORTADDR
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::SHORTADDR);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "SHORTADDR", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::EXTADDR
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::EXTADDR);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "EXTADDR", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::LrWpanMacHeader::IMPLICIT
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::IMPLICIT);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "IMPLICIT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::NOKEYSOURCE
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::NOKEYSOURCE);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "NOKEYSOURCE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::SHORTKEYSOURCE
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::SHORTKEYSOURCE);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "SHORTKEYSOURCE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::LrWpanMacHeader::LONGKEYSOURCE
        tmp_value = PyLong_FromLong(ns3::LrWpanMacHeader::LONGKEYSOURCE);
        PyDict_SetItemString((PyObject*) PyNs3LrWpanMacHeader_Type.tp_dict, "LONGKEYSOURCE", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initlr_wpan_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initlr_wpan_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initlr_wpan_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    submodule = initlr_wpan_internal();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "internal", submodule);
    return MOD_RETURN(m);
}
