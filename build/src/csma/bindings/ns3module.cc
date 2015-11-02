#include "ns3module.h"
static PyMethodDef csma_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef csma_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "csma.FatalImpl",
    NULL,
    -1,
    csma_FatalImpl_functions,
};
#endif

static PyObject *
initcsma_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&csma_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "csma.FatalImpl", csma_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef csma_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef csma_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "csma.Hash.Function",
    NULL,
    -1,
    csma_Hash_Function_functions,
};
#endif

static PyObject *
initcsma_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&csma_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "csma.Hash.Function", csma_Hash_Function_functions, NULL);
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
static PyMethodDef csma_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef csma_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "csma.Hash",
    NULL,
    -1,
    csma_Hash_functions,
};
#endif

static PyObject *
initcsma_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&csma_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "csma.Hash", csma_Hash_functions, NULL);
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
    submodule = initcsma_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef csma_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef csma_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "csma.TracedValueCallback",
    NULL,
    -1,
    csma_TracedValueCallback_functions,
};
#endif

static PyObject *
initcsma_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&csma_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "csma.TracedValueCallback", csma_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef csma_functions[] = {
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


PyTypeObject *_PyNs3DataRate_Type;
std::map<void*, PyObject*> *_PyNs3DataRate_wrapper_registry;


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


PyTypeObject *_PyNs3Queue_Type;


PyTypeObject *_PyNs3RandomVariableStream_Type;


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


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3Time_Type;
std::map<void*, PyObject*> *_PyNs3Time_wrapper_registry;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


PyTypeObject *_PyNs3Trailer_Type;


PyTypeObject *_PyNs3TriangularRandomVariable_Type;


PyTypeObject *_PyNs3UniformRandomVariable_Type;


PyTypeObject *_PyNs3WeibullRandomVariable_Type;


PyTypeObject *_PyNs3ZetaRandomVariable_Type;


PyTypeObject *_PyNs3ZipfRandomVariable_Type;


PyTypeObject *_PyNs3AttributeAccessor_Type;


PyTypeObject *_PyNs3AttributeChecker_Type;


PyTypeObject *_PyNs3AttributeValue_Type;


PyTypeObject *_PyNs3CallbackChecker_Type;


PyTypeObject *_PyNs3CallbackImplBase_Type;


PyTypeObject *_PyNs3CallbackValue_Type;


PyTypeObject *_PyNs3Channel_Type;


PyTypeObject *_PyNs3ConstantRandomVariable_Type;


PyTypeObject *_PyNs3DataRateChecker_Type;


PyTypeObject *_PyNs3DataRateValue_Type;


PyTypeObject *_PyNs3DeterministicRandomVariable_Type;


PyTypeObject *_PyNs3EmpiricalRandomVariable_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3ErlangRandomVariable_Type;


PyTypeObject *_PyNs3ErrorModel_Type;


PyTypeObject *_PyNs3EventImpl_Type;


PyTypeObject *_PyNs3ExponentialRandomVariable_Type;


PyTypeObject *_PyNs3GammaRandomVariable_Type;


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


PyTypeObject *_PyNs3Mac48AddressChecker_Type;


PyTypeObject *_PyNs3Mac48AddressValue_Type;


PyTypeObject *_PyNs3NetDevice_Type;


PyTypeObject *_PyNs3NixVector_Type;


PyTypeObject *_PyNs3Node_Type;


PyTypeObject *_PyNs3NormalRandomVariable_Type;


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3OutputStreamWrapper_Type;


PyTypeObject *_PyNs3Packet_Type;


PyTypeObject *_PyNs3ParetoRandomVariable_Type;


PyTypeObject *_PyNs3RateErrorModel_Type;


PyTypeObject *_PyNs3ReceiveListErrorModel_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


PyTypeObject *_PyNs3BurstErrorModel_Type;


std::map<void*, PyObject*> PyNs3Backoff_wrapper_registry;
static PyObject* _wrap_PyNs3Backoff__get_m_ceiling(PyNs3Backoff *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->m_ceiling));
    return py_retval;
}
static int _wrap_PyNs3Backoff__set_m_ceiling(PyNs3Backoff *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->m_ceiling)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Backoff__get_m_maxRetries(PyNs3Backoff *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->m_maxRetries));
    return py_retval;
}
static int _wrap_PyNs3Backoff__set_m_maxRetries(PyNs3Backoff *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->m_maxRetries)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Backoff__get_m_maxSlots(PyNs3Backoff *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->m_maxSlots));
    return py_retval;
}
static int _wrap_PyNs3Backoff__set_m_maxSlots(PyNs3Backoff *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->m_maxSlots)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Backoff__get_m_minSlots(PyNs3Backoff *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->m_minSlots));
    return py_retval;
}
static int _wrap_PyNs3Backoff__set_m_minSlots(PyNs3Backoff *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->m_minSlots)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Backoff__get_m_slotTime(PyNs3Backoff *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->m_slotTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3Backoff__set_m_slotTime(PyNs3Backoff *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_slotTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Backoff__getsets[] = {
    {
        (char*) "m_maxRetries", /* attribute name */
        (getter) _wrap_PyNs3Backoff__get_m_maxRetries, /* C function to get the attribute */
        (setter) _wrap_PyNs3Backoff__set_m_maxRetries, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_maxSlots", /* attribute name */
        (getter) _wrap_PyNs3Backoff__get_m_maxSlots, /* C function to get the attribute */
        (setter) _wrap_PyNs3Backoff__set_m_maxSlots, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_ceiling", /* attribute name */
        (getter) _wrap_PyNs3Backoff__get_m_ceiling, /* C function to get the attribute */
        (setter) _wrap_PyNs3Backoff__set_m_ceiling, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_slotTime", /* attribute name */
        (getter) _wrap_PyNs3Backoff__get_m_slotTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3Backoff__set_m_slotTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_minSlots", /* attribute name */
        (getter) _wrap_PyNs3Backoff__get_m_minSlots, /* C function to get the attribute */
        (setter) _wrap_PyNs3Backoff__set_m_minSlots, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Backoff__tp_init__0(PyNs3Backoff *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Backoff *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Backoff_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Backoff(*((PyNs3Backoff *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Backoff__tp_init__1(PyNs3Backoff *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Backoff();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Backoff__tp_init__2(PyNs3Backoff *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Time *slotTime;
    unsigned int minSlots;
    unsigned int maxSlots;
    unsigned int ceiling;
    unsigned int maxRetries;
    const char *keywords[] = {"slotTime", "minSlots", "maxSlots", "ceiling", "maxRetries", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!IIII", (char **) keywords, &PyNs3Time_Type, &slotTime, &minSlots, &maxSlots, &ceiling, &maxRetries)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Backoff(*((PyNs3Time *) slotTime)->obj, minSlots, maxSlots, ceiling, maxRetries);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Backoff__tp_init(PyNs3Backoff *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Backoff__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Backoff__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Backoff__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Backoff_GetBackoffTime(PyNs3Backoff *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetBackoffTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3Backoff_IncrNumRetries(PyNs3Backoff *self)
{
    PyObject *py_retval;
    
    self->obj->IncrNumRetries();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Backoff_MaxRetriesReached(PyNs3Backoff *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->MaxRetriesReached();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Backoff_ResetBackoffTime(PyNs3Backoff *self)
{
    PyObject *py_retval;
    
    self->obj->ResetBackoffTime();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Backoff_AssignStreams(PyNs3Backoff *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3Backoff__copy__(PyNs3Backoff *self)
{

    PyNs3Backoff *py_copy;
    py_copy = PyObject_New(PyNs3Backoff, &PyNs3Backoff_Type);
    py_copy->obj = new ns3::Backoff(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Backoff_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Backoff_methods[] = {
    {(char *) "GetBackoffTime", (PyCFunction) _wrap_PyNs3Backoff_GetBackoffTime, METH_NOARGS, NULL },
    {(char *) "IncrNumRetries", (PyCFunction) _wrap_PyNs3Backoff_IncrNumRetries, METH_NOARGS, NULL },
    {(char *) "MaxRetriesReached", (PyCFunction) _wrap_PyNs3Backoff_MaxRetriesReached, METH_NOARGS, NULL },
    {(char *) "ResetBackoffTime", (PyCFunction) _wrap_PyNs3Backoff_ResetBackoffTime, METH_NOARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3Backoff_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Backoff__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Backoff__tp_dealloc(PyNs3Backoff *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Backoff_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Backoff_wrapper_registry.end()) {
        PyNs3Backoff_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Backoff *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Backoff__tp_richcompare (PyNs3Backoff *PYBINDGEN_UNUSED(self), PyNs3Backoff *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Backoff_Type)) {
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

PyTypeObject PyNs3Backoff_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "csma.Backoff",            /* tp_name */
    sizeof(PyNs3Backoff),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Backoff__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Backoff__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Backoff_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Backoff__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Backoff__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3CsmaDeviceRec_wrapper_registry;
static PyObject* _wrap_PyNs3CsmaDeviceRec__get_active(PyNs3CsmaDeviceRec *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(self->obj->active));
    return py_retval;
}
static int _wrap_PyNs3CsmaDeviceRec__set_active(PyNs3CsmaDeviceRec *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->active = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3CsmaDeviceRec__get_devicePtr(PyNs3CsmaDeviceRec *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3CsmaNetDevice *py_CsmaNetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!(const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (self->obj->devicePtr)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (self->obj->devicePtr)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_CsmaNetDevice = NULL;
    } else {
        py_CsmaNetDevice = (PyNs3CsmaNetDevice *) wrapper_lookup_iter->second;
        Py_INCREF(py_CsmaNetDevice);
    }
    
    if (py_CsmaNetDevice == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (self->obj->devicePtr)))), &PyNs3CsmaNetDevice_Type);
        py_CsmaNetDevice = PyObject_GC_New(PyNs3CsmaNetDevice, wrapper_type);
        py_CsmaNetDevice->inst_dict = NULL;
    
        py_CsmaNetDevice->inst_dict = NULL;
        py_CsmaNetDevice->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (self->obj->devicePtr))->Ref();
        py_CsmaNetDevice->obj = const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (self->obj->devicePtr));
        PyNs3ObjectBase_wrapper_registry[(void *) py_CsmaNetDevice->obj] = (PyObject *) py_CsmaNetDevice;
    }
    py_retval = Py_BuildValue((char *) "N", py_CsmaNetDevice);
    return py_retval;
}
static int _wrap_PyNs3CsmaDeviceRec__set_devicePtr(PyNs3CsmaDeviceRec *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3CsmaNetDevice *tmp_CsmaNetDevice;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3CsmaNetDevice_Type, &tmp_CsmaNetDevice)) {
        Py_DECREF(py_retval);
        return -1;
    }
    // dangerous!
    self->obj->devicePtr = ns3::Ptr< ns3::CsmaNetDevice  > (tmp_CsmaNetDevice->obj);
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3CsmaDeviceRec__getsets[] = {
    {
        (char*) "active", /* attribute name */
        (getter) _wrap_PyNs3CsmaDeviceRec__get_active, /* C function to get the attribute */
        (setter) _wrap_PyNs3CsmaDeviceRec__set_active, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "devicePtr", /* attribute name */
        (getter) _wrap_PyNs3CsmaDeviceRec__get_devicePtr, /* C function to get the attribute */
        (setter) _wrap_PyNs3CsmaDeviceRec__set_devicePtr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3CsmaDeviceRec__tp_init__0(PyNs3CsmaDeviceRec *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::CsmaDeviceRec();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3CsmaDeviceRec__tp_init__1(PyNs3CsmaDeviceRec *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3CsmaNetDevice *device;
    ns3::CsmaNetDevice *device_ptr;
    const char *keywords[] = {"device", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaNetDevice_Type, &device)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    device_ptr = (device ? device->obj : NULL);
    self->obj = new ns3::CsmaDeviceRec(ns3::Ptr< ns3::CsmaNetDevice  > (device_ptr));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3CsmaDeviceRec__tp_init__2(PyNs3CsmaDeviceRec *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3CsmaDeviceRec *o;
    const char *keywords[] = {"o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaDeviceRec_Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::CsmaDeviceRec(*((PyNs3CsmaDeviceRec *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3CsmaDeviceRec__tp_init(PyNs3CsmaDeviceRec *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3CsmaDeviceRec__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaDeviceRec__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaDeviceRec__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3CsmaDeviceRec_IsActive(PyNs3CsmaDeviceRec *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsActive();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3CsmaDeviceRec__copy__(PyNs3CsmaDeviceRec *self)
{

    PyNs3CsmaDeviceRec *py_copy;
    py_copy = PyObject_New(PyNs3CsmaDeviceRec, &PyNs3CsmaDeviceRec_Type);
    py_copy->obj = new ns3::CsmaDeviceRec(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3CsmaDeviceRec_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3CsmaDeviceRec_methods[] = {
    {(char *) "IsActive", (PyCFunction) _wrap_PyNs3CsmaDeviceRec_IsActive, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3CsmaDeviceRec__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3CsmaDeviceRec__tp_dealloc(PyNs3CsmaDeviceRec *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3CsmaDeviceRec_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3CsmaDeviceRec_wrapper_registry.end()) {
        PyNs3CsmaDeviceRec_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::CsmaDeviceRec *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3CsmaDeviceRec__tp_richcompare (PyNs3CsmaDeviceRec *PYBINDGEN_UNUSED(self), PyNs3CsmaDeviceRec *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3CsmaDeviceRec_Type)) {
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

PyTypeObject PyNs3CsmaDeviceRec_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "csma.CsmaDeviceRec",            /* tp_name */
    sizeof(PyNs3CsmaDeviceRec),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3CsmaDeviceRec__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3CsmaDeviceRec__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3CsmaDeviceRec_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3CsmaDeviceRec__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3CsmaDeviceRec__tp_init,             /* tp_init */
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
PyNs3CsmaHelper__PythonHelper::EnableAsciiInternal(ns3::Ptr< ns3::OutputStreamWrapper > stream, std::string prefix, ns3::Ptr< ns3::NetDevice > nd, bool explicitFilename)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::CsmaHelper *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = (ns3::CsmaHelper*) this;
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
        reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3CsmaHelper__PythonHelper::EnablePcapInternal(std::string prefix, ns3::Ptr< ns3::NetDevice > nd, bool promiscuous, bool explicitFilename)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::CsmaHelper *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = (ns3::CsmaHelper*) this;
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
        reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3CsmaHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3CsmaHelper__tp_init__0(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3CsmaHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3CsmaHelper_Type)
    {
        self->obj = new PyNs3CsmaHelper__PythonHelper(*((PyNs3CsmaHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3CsmaHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::CsmaHelper(*((PyNs3CsmaHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3CsmaHelper__tp_init__1(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3CsmaHelper_Type)
    {
        self->obj = new PyNs3CsmaHelper__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3CsmaHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::CsmaHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3CsmaHelper__tp_init(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3CsmaHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3CsmaHelper_SetChannelAttribute(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *n1;
    Py_ssize_t n1_len;
    PyNs3AttributeValue *v1;
    const char *keywords[] = {"n1", "v1", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &n1, &n1_len, &PyNs3AttributeValue_Type, &v1)) {
        return NULL;
    }
    self->obj->SetChannelAttribute(std::string(n1, n1_len), *((PyNs3AttributeValue *) v1)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaHelper_SetDeviceAttribute(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *n1;
    Py_ssize_t n1_len;
    PyNs3AttributeValue *v1;
    const char *keywords[] = {"n1", "v1", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &n1, &n1_len, &PyNs3AttributeValue_Type, &v1)) {
        return NULL;
    }
    self->obj->SetDeviceAttribute(std::string(n1, n1_len), *((PyNs3AttributeValue *) v1)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaHelper_SetQueue(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *type;
    Py_ssize_t type_len;
    const char *n1 = NULL;
    Py_ssize_t n1_len;
    PyNs3AttributeValue *v1 = NULL;
    ns3::EmptyAttributeValue v1_default = ns3::EmptyAttributeValue();
    const char *n2 = NULL;
    Py_ssize_t n2_len;
    PyNs3AttributeValue *v2 = NULL;
    ns3::EmptyAttributeValue v2_default = ns3::EmptyAttributeValue();
    const char *n3 = NULL;
    Py_ssize_t n3_len;
    PyNs3AttributeValue *v3 = NULL;
    ns3::EmptyAttributeValue v3_default = ns3::EmptyAttributeValue();
    const char *n4 = NULL;
    Py_ssize_t n4_len;
    PyNs3AttributeValue *v4 = NULL;
    ns3::EmptyAttributeValue v4_default = ns3::EmptyAttributeValue();
    const char *keywords[] = {"type", "n1", "v1", "n2", "v2", "n3", "v3", "n4", "v4", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|s#O!s#O!s#O!s#O!", (char **) keywords, &type, &type_len, &n1, &n1_len, &PyNs3AttributeValue_Type, &v1, &n2, &n2_len, &PyNs3AttributeValue_Type, &v2, &n3, &n3_len, &PyNs3AttributeValue_Type, &v3, &n4, &n4_len, &PyNs3AttributeValue_Type, &v4)) {
        return NULL;
    }
    self->obj->SetQueue(std::string(type, type_len), (n1 ? std::string(n1, n1_len) : ""), (v1 ? (*((PyNs3AttributeValue *) v1)->obj) : v1_default), (n2 ? std::string(n2, n2_len) : ""), (v2 ? (*((PyNs3AttributeValue *) v2)->obj) : v2_default), (n3 ? std::string(n3, n3_len) : ""), (v3 ? (*((PyNs3AttributeValue *) v3)->obj) : v3_default), (n4 ? std::string(n4, n4_len) : ""), (v4 ? (*((PyNs3AttributeValue *) v4)->obj) : v4_default));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3CsmaHelper_Install__0(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
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
    ns3::NetDeviceContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__1(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    const char *keywords[] = {"name", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &name, &name_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::NetDeviceContainer retval = self->obj->Install(std::string(name, name_len));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__2(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    PyNs3CsmaChannel *channel;
    ns3::CsmaChannel *channel_ptr;
    const char *keywords[] = {"node", "channel", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Node_Type, &node, &PyNs3CsmaChannel_Type, &channel)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    channel_ptr = (channel ? channel->obj : NULL);
    ns3::NetDeviceContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr), ns3::Ptr< ns3::CsmaChannel  > (channel_ptr));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__3(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *channelName;
    Py_ssize_t channelName_len;
    const char *keywords[] = {"node", "channelName", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3Node_Type, &node, &channelName, &channelName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    ns3::NetDeviceContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr), std::string(channelName, channelName_len));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__4(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    PyNs3CsmaChannel *channel;
    ns3::CsmaChannel *channel_ptr;
    const char *keywords[] = {"nodeName", "channel", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &nodeName, &nodeName_len, &PyNs3CsmaChannel_Type, &channel)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    channel_ptr = (channel ? channel->obj : NULL);
    ns3::NetDeviceContainer retval = self->obj->Install(std::string(nodeName, nodeName_len), ns3::Ptr< ns3::CsmaChannel  > (channel_ptr));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__5(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *channelName;
    Py_ssize_t channelName_len;
    const char *keywords[] = {"nodeName", "channelName", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &nodeName, &nodeName_len, &channelName, &channelName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::NetDeviceContainer retval = self->obj->Install(std::string(nodeName, nodeName_len), std::string(channelName, channelName_len));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__6(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
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
_wrap_PyNs3CsmaHelper_Install__7(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    PyNs3CsmaChannel *channel;
    ns3::CsmaChannel *channel_ptr;
    const char *keywords[] = {"c", "channel", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3NodeContainer_Type, &c, &PyNs3CsmaChannel_Type, &channel)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    channel_ptr = (channel ? channel->obj : NULL);
    ns3::NetDeviceContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj, ns3::Ptr< ns3::CsmaChannel  > (channel_ptr));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaHelper_Install__8(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *channelName;
    Py_ssize_t channelName_len;
    const char *keywords[] = {"c", "channelName", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!s#", (char **) keywords, &PyNs3NodeContainer_Type, &c, &channelName, &channelName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::NetDeviceContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj, std::string(channelName, channelName_len));
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3CsmaHelper_Install(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[9] = {0,};
    retval = _wrap_PyNs3CsmaHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__4(self, args, kwargs, &exceptions[4]);
    if (!exceptions[4]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__5(self, args, kwargs, &exceptions[5]);
    if (!exceptions[5]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__6(self, args, kwargs, &exceptions[6]);
    if (!exceptions[6]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        Py_DECREF(exceptions[5]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_Install__7(self, args, kwargs, &exceptions[7]);
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
    retval = _wrap_PyNs3CsmaHelper_Install__8(self, args, kwargs, &exceptions[8]);
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
    error_list = PyList_New(9);
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
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return NULL;
}


PyObject *
_wrap_PyNs3CsmaHelper_AssignStreams(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3CsmaHelper_EnableAsciiAll__0(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAsciiAll__1(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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

PyObject * _wrap_PyNs3CsmaHelper_EnableAsciiAll(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3CsmaHelper_EnableAsciiAll__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAsciiAll__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3CsmaHelper_EnablePcap__0(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnablePcap__1(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnablePcap__2(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnablePcap__3(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnablePcap__4(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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

PyObject * _wrap_PyNs3CsmaHelper_EnablePcap(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3CsmaHelper_EnablePcap__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnablePcap__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnablePcap__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnablePcap__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnablePcap__4(self, args, kwargs, &exceptions[4]);
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
_wrap_PyNs3CsmaHelper_EnableAscii__0(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__1(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__2(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__3(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__4(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__5(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__6(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__7(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__8(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaHelper_EnableAscii__9(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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

PyObject * _wrap_PyNs3CsmaHelper_EnableAscii(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[10] = {0,};
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__4(self, args, kwargs, &exceptions[4]);
    if (!exceptions[4]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__5(self, args, kwargs, &exceptions[5]);
    if (!exceptions[5]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__6(self, args, kwargs, &exceptions[6]);
    if (!exceptions[6]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        Py_DECREF(exceptions[3]);
        Py_DECREF(exceptions[4]);
        Py_DECREF(exceptions[5]);
        return retval;
    }
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__7(self, args, kwargs, &exceptions[7]);
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
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__8(self, args, kwargs, &exceptions[8]);
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
    retval = _wrap_PyNs3CsmaHelper_EnableAscii__9(self, args, kwargs, &exceptions[9]);
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
_wrap_PyNs3CsmaHelper_EnablePcapAll(PyNs3CsmaHelper *self, PyObject *args, PyObject *kwargs)
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


static PyObject*
_wrap_PyNs3CsmaHelper__copy__(PyNs3CsmaHelper *self)
{

    PyNs3CsmaHelper *py_copy;
    py_copy = PyObject_GC_New(PyNs3CsmaHelper, &PyNs3CsmaHelper_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::CsmaHelper(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PcapHelperForDevice_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3CsmaHelper_methods[] = {
    {(char *) "SetChannelAttribute", (PyCFunction) _wrap_PyNs3CsmaHelper_SetChannelAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDeviceAttribute", (PyCFunction) _wrap_PyNs3CsmaHelper_SetDeviceAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetQueue", (PyCFunction) _wrap_PyNs3CsmaHelper_SetQueue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3CsmaHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3CsmaHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableAsciiAll", (PyCFunction) _wrap_PyNs3CsmaHelper_EnableAsciiAll, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnablePcap", (PyCFunction) _wrap_PyNs3CsmaHelper_EnablePcap, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableAscii", (PyCFunction) _wrap_PyNs3CsmaHelper_EnableAscii, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnablePcapAll", (PyCFunction) _wrap_PyNs3CsmaHelper_EnablePcapAll, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3CsmaHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3CsmaHelper__tp_clear(PyNs3CsmaHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::CsmaHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3CsmaHelper__tp_traverse(PyNs3CsmaHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3CsmaHelper__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3CsmaHelper__tp_dealloc(PyNs3CsmaHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PcapHelperForDevice_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PcapHelperForDevice_wrapper_registry.end()) {
        PyNs3PcapHelperForDevice_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3CsmaHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3CsmaHelper__tp_richcompare (PyNs3CsmaHelper *PYBINDGEN_UNUSED(self), PyNs3CsmaHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3CsmaHelper_Type)) {
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

PyTypeObject PyNs3CsmaHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "csma.CsmaHelper",            /* tp_name */
    sizeof(PyNs3CsmaHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3CsmaHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3CsmaHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3CsmaHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3CsmaHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3CsmaHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3CsmaHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3CsmaHelper__tp_init,             /* tp_init */
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
PyNs3CsmaChannel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    PyNs3CsmaChannel__PythonHelper *helper = dynamic_cast< PyNs3CsmaChannel__PythonHelper* >(self->obj);
    
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
PyNs3CsmaChannel__PythonHelper::_wrap_DoInitialize(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    PyNs3CsmaChannel__PythonHelper *helper = dynamic_cast< PyNs3CsmaChannel__PythonHelper* >(self->obj);
    
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
PyNs3CsmaChannel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    PyNs3CsmaChannel__PythonHelper *helper = dynamic_cast< PyNs3CsmaChannel__PythonHelper* >(self->obj);
    
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
PyNs3CsmaChannel__PythonHelper::_wrap_DoDispose(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    PyNs3CsmaChannel__PythonHelper *helper = dynamic_cast< PyNs3CsmaChannel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

uint32_t
PyNs3CsmaChannel__PythonHelper::GetNDevices() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::CsmaChannel *self_obj_before;
    PyObject *py_retval;
    uint32_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNDevices"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CsmaChannel::GetNDevices();
    }
    self_obj_before = reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = const_cast< ns3::CsmaChannel* >((const ns3::CsmaChannel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNDevices", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CsmaChannel::GetNDevices();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CsmaChannel::GetNDevices();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Ptr< ns3::NetDevice >
PyNs3CsmaChannel__PythonHelper::GetDevice(uint32_t i) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::CsmaChannel *self_obj_before;
    PyObject *py_retval;
    ns3::Ptr< ns3::NetDevice > retval;
    PyNs3NetDevice *tmp_NetDevice;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetDevice"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CsmaChannel::GetDevice(i);
    }
    self_obj_before = reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = const_cast< ns3::CsmaChannel* >((const ns3::CsmaChannel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetDevice", (char *) "N", PyLong_FromUnsignedLong(i));
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CsmaChannel::GetDevice(i);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3NetDevice_Type, &tmp_NetDevice)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CsmaChannel::GetDevice(i);
    }
    // dangerous!
    retval = ns3::Ptr< ns3::NetDevice  > (tmp_NetDevice->obj);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3CsmaChannel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3CsmaChannel__PythonHelper::GetInstanceTypeId() const
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
PyNs3CsmaChannel__PythonHelper::DoDispose()
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
PyNs3CsmaChannel__PythonHelper::DoInitialize()
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
PyNs3CsmaChannel__PythonHelper::NotifyNewAggregate()
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
PyNs3CsmaChannel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3CsmaChannel__tp_init(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3CsmaChannel_Type)
    {
        self->obj = new PyNs3CsmaChannel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3CsmaChannel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::CsmaChannel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}



PyObject *
_wrap_PyNs3CsmaChannel_Reattach__0(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    bool retval;
    unsigned int deviceId;
    const char *keywords[] = {"deviceId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &deviceId)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->Reattach(deviceId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaChannel_Reattach__1(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    bool retval;
    PyNs3CsmaNetDevice *device;
    ns3::CsmaNetDevice *device_ptr;
    const char *keywords[] = {"device", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaNetDevice_Type, &device)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    device_ptr = (device ? device->obj : NULL);
    retval = self->obj->Reattach(ns3::Ptr< ns3::CsmaNetDevice  > (device_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject * _wrap_PyNs3CsmaChannel_Reattach(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3CsmaChannel_Reattach__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaChannel_Reattach__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3CsmaChannel_GetNumActDevices(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetNumActDevices();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetState(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    ns3::WireState retval;
    
    retval = self->obj->GetState();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetDelay(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetDelay();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_TransmitStart(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    unsigned int srcId;
    const char *keywords[] = {"p", "srcId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Packet_Type, &p, &srcId)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    retval = self->obj->TransmitStart(ns3::Ptr< ns3::Packet  > (p_ptr), srcId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::CsmaChannel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetDevice(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::NetDevice > retval;
    unsigned int i;
    PyNs3CsmaChannel__PythonHelper *helper_class = dynamic_cast<PyNs3CsmaChannel__PythonHelper*> (self->obj);
    const char *keywords[] = {"i", NULL};
    PyNs3NetDevice *py_NetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->GetDevice(i)) : (self->obj->ns3::CsmaChannel::GetDevice(i));
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
_wrap_PyNs3CsmaChannel_GetNDevices(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3CsmaChannel__PythonHelper *helper_class = dynamic_cast<PyNs3CsmaChannel__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetNDevices()) : (self->obj->ns3::CsmaChannel::GetNDevices());
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_Attach(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int32_t retval;
    PyNs3CsmaNetDevice *device;
    ns3::CsmaNetDevice *device_ptr;
    const char *keywords[] = {"device", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaNetDevice_Type, &device)) {
        return NULL;
    }
    device_ptr = (device ? device->obj : NULL);
    retval = self->obj->Attach(ns3::Ptr< ns3::CsmaNetDevice  > (device_ptr));
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetDeviceNum(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int32_t retval;
    PyNs3CsmaNetDevice *device;
    ns3::CsmaNetDevice *device_ptr;
    const char *keywords[] = {"device", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaNetDevice_Type, &device)) {
        return NULL;
    }
    device_ptr = (device ? device->obj : NULL);
    retval = self->obj->GetDeviceNum(ns3::Ptr< ns3::CsmaNetDevice  > (device_ptr));
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetDataRate(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    PyNs3DataRate *py_DataRate;
    
    ns3::DataRate retval = self->obj->GetDataRate();
    py_DataRate = PyObject_New(PyNs3DataRate, &PyNs3DataRate_Type);
    py_DataRate->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DataRate->obj = new ns3::DataRate(retval);
    PyNs3DataRate_wrapper_registry[(void *) py_DataRate->obj] = (PyObject *) py_DataRate;
    py_retval = Py_BuildValue((char *) "N", py_DataRate);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_IsBusy(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBusy();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}



PyObject *
_wrap_PyNs3CsmaChannel_Detach__0(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    bool retval;
    PyNs3CsmaNetDevice *device;
    ns3::CsmaNetDevice *device_ptr;
    const char *keywords[] = {"device", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaNetDevice_Type, &device)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    device_ptr = (device ? device->obj : NULL);
    retval = self->obj->Detach(ns3::Ptr< ns3::CsmaNetDevice  > (device_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3CsmaChannel_Detach__1(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    bool retval;
    unsigned int deviceId;
    const char *keywords[] = {"deviceId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &deviceId)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    retval = self->obj->Detach(deviceId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject * _wrap_PyNs3CsmaChannel_Detach(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3CsmaChannel_Detach__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaChannel_Detach__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3CsmaChannel_TransmitEnd(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->TransmitEnd();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_PropagationCompleteEvent(PyNs3CsmaChannel *self)
{
    PyObject *py_retval;
    
    self->obj->PropagationCompleteEvent();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_IsActive(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    unsigned int deviceId;
    const char *keywords[] = {"deviceId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &deviceId)) {
        return NULL;
    }
    retval = self->obj->IsActive(deviceId);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaChannel_GetCsmaDevice(PyNs3CsmaChannel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::CsmaNetDevice > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3CsmaNetDevice *py_CsmaNetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->GetCsmaDevice(i);
    if (!(const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_CsmaNetDevice = NULL;
    } else {
        py_CsmaNetDevice = (PyNs3CsmaNetDevice *) wrapper_lookup_iter->second;
        Py_INCREF(py_CsmaNetDevice);
    }
    
    if (py_CsmaNetDevice == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (retval)))), &PyNs3CsmaNetDevice_Type);
        py_CsmaNetDevice = PyObject_GC_New(PyNs3CsmaNetDevice, wrapper_type);
        py_CsmaNetDevice->inst_dict = NULL;
    
        py_CsmaNetDevice->inst_dict = NULL;
        py_CsmaNetDevice->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (retval))->Ref();
        py_CsmaNetDevice->obj = const_cast<ns3::CsmaNetDevice *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_CsmaNetDevice->obj] = (PyObject *) py_CsmaNetDevice;
    }
    py_retval = Py_BuildValue((char *) "N", py_CsmaNetDevice);
    return py_retval;
}

static PyMethodDef PyNs3CsmaChannel_methods[] = {
    {(char *) "Reattach", (PyCFunction) _wrap_PyNs3CsmaChannel_Reattach, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNumActDevices", (PyCFunction) _wrap_PyNs3CsmaChannel_GetNumActDevices, METH_NOARGS, NULL },
    {(char *) "GetState", (PyCFunction) _wrap_PyNs3CsmaChannel_GetState, METH_NOARGS, NULL },
    {(char *) "GetDelay", (PyCFunction) _wrap_PyNs3CsmaChannel_GetDelay, METH_NOARGS, NULL },
    {(char *) "TransmitStart", (PyCFunction) _wrap_PyNs3CsmaChannel_TransmitStart, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3CsmaChannel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetDevice", (PyCFunction) _wrap_PyNs3CsmaChannel_GetDevice, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNDevices", (PyCFunction) _wrap_PyNs3CsmaChannel_GetNDevices, METH_NOARGS, NULL },
    {(char *) "Attach", (PyCFunction) _wrap_PyNs3CsmaChannel_Attach, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDeviceNum", (PyCFunction) _wrap_PyNs3CsmaChannel_GetDeviceNum, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDataRate", (PyCFunction) _wrap_PyNs3CsmaChannel_GetDataRate, METH_NOARGS, NULL },
    {(char *) "IsBusy", (PyCFunction) _wrap_PyNs3CsmaChannel_IsBusy, METH_NOARGS, NULL },
    {(char *) "Detach", (PyCFunction) _wrap_PyNs3CsmaChannel_Detach, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TransmitEnd", (PyCFunction) _wrap_PyNs3CsmaChannel_TransmitEnd, METH_NOARGS, NULL },
    {(char *) "PropagationCompleteEvent", (PyCFunction) _wrap_PyNs3CsmaChannel_PropagationCompleteEvent, METH_NOARGS, NULL },
    {(char *) "IsActive", (PyCFunction) _wrap_PyNs3CsmaChannel_IsActive, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetCsmaDevice", (PyCFunction) _wrap_PyNs3CsmaChannel_GetCsmaDevice, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3CsmaChannel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3CsmaChannel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3CsmaChannel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3CsmaChannel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3CsmaChannel__tp_clear(PyNs3CsmaChannel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::CsmaChannel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3CsmaChannel__tp_traverse(PyNs3CsmaChannel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3CsmaChannel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3CsmaChannel__tp_dealloc(PyNs3CsmaChannel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3CsmaChannel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3CsmaChannel__tp_richcompare (PyNs3CsmaChannel *PYBINDGEN_UNUSED(self), PyNs3CsmaChannel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3CsmaChannel_Type)) {
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

PyTypeObject PyNs3CsmaChannel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "csma.CsmaChannel",            /* tp_name */
    sizeof(PyNs3CsmaChannel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3CsmaChannel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3CsmaChannel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3CsmaChannel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3CsmaChannel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3CsmaChannel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3CsmaChannel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3CsmaChannel__tp_init,             /* tp_init */
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
_wrap_PyNs3CsmaNetDevice__tp_init(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::CsmaNetDevice();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetEncapsulationMode(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::CsmaNetDevice::EncapsulationMode mode;
    const char *keywords[] = {"mode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &mode)) {
        return NULL;
    }
    self->obj->SetEncapsulationMode(mode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3CsmaNetDevice_GetMulticast__0(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3CsmaNetDevice_GetMulticast__1(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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

PyObject * _wrap_PyNs3CsmaNetDevice_GetMulticast(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3CsmaNetDevice_GetMulticast__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CsmaNetDevice_GetMulticast__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3CsmaNetDevice_IsPointToPoint(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsPointToPoint();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_IsReceiveEnabled(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsReceiveEnabled();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetBackoffParams(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *slotTime;
    unsigned int minSlots;
    unsigned int maxSlots;
    unsigned int maxRetries;
    unsigned int ceiling;
    const char *keywords[] = {"slotTime", "minSlots", "maxSlots", "maxRetries", "ceiling", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!IIII", (char **) keywords, &PyNs3Time_Type, &slotTime, &minSlots, &maxSlots, &maxRetries, &ceiling)) {
        return NULL;
    }
    self->obj->SetBackoffParams(*((PyNs3Time *) slotTime)->obj, minSlots, maxSlots, maxRetries, ceiling);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_Send(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac48Address_Type)) {
        dest2 = *((PyNs3Mac48Address *) dest)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac48Address), not %s", Py_TYPE(dest)->tp_name);
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
_wrap_PyNs3CsmaNetDevice_GetIfIndex(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetIfIndex();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_NeedsArp(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->NeedsArp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetChannel(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Channel > retval;
    PyNs3Channel *py_Channel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetChannel();
    if (!(const_cast<ns3::Channel *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Channel *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Channel__PythonHelper).name())
    {
        py_Channel = reinterpret_cast< PyNs3Channel* >(reinterpret_cast< PyNs3Channel__PythonHelper* >(const_cast<ns3::Channel *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Channel->obj = const_cast<ns3::Channel *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Channel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Channel *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Channel = NULL;
        } else {
            py_Channel = (PyNs3Channel *) wrapper_lookup_iter->second;
            Py_INCREF(py_Channel);
        }
    
        if (py_Channel == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Channel *> (ns3::PeekPointer (retval)))), &PyNs3Channel_Type);
            py_Channel = PyObject_GC_New(PyNs3Channel, wrapper_type);
            py_Channel->inst_dict = NULL;
    
            py_Channel->inst_dict = NULL;
            py_Channel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Channel *> (ns3::PeekPointer (retval))->Ref();
            py_Channel->obj = const_cast<ns3::Channel *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Channel->obj] = (PyObject *) py_Channel;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Channel);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_IsSendEnabled(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsSendEnabled();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetEncapsulationMode(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    ns3::CsmaNetDevice::EncapsulationMode retval;
    
    retval = self->obj->GetEncapsulationMode();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetNode(PyNs3CsmaNetDevice *self)
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
_wrap_PyNs3CsmaNetDevice_SendFrom(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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
    } else if (PyObject_IsInstance(source, (PyObject*) &PyNs3Mac48Address_Type)) {
        source2 = *((PyNs3Mac48Address *) source)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac48Address), not %s", Py_TYPE(source)->tp_name);
        return NULL;
    }
    if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Address_Type)) {
        dest2 = *((PyNs3Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Ipv4Address_Type)) {
        dest2 = *((PyNs3Ipv4Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Ipv6Address_Type)) {
        dest2 = *((PyNs3Ipv6Address *) dest)->obj;
    } else if (PyObject_IsInstance(dest, (PyObject*) &PyNs3Mac48Address_Type)) {
        dest2 = *((PyNs3Mac48Address *) dest)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac48Address), not %s", Py_TYPE(dest)->tp_name);
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
_wrap_PyNs3CsmaNetDevice_SetPromiscReceiveCallback(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *cb;
    ns3::Ptr<PythonCallbackImpl0> cb_cb_impl;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &cb)) {
        return NULL;
    }
    if (!PyCallable_Check(cb)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'cb' must be callbale");
        return NULL;
    }
    cb_cb_impl = ns3::Create<PythonCallbackImpl0> (cb);
    self->obj->SetPromiscReceiveCallback(ns3::Callback<bool, ns3::Ptr<ns3::NetDevice>, ns3::Ptr<ns3::Packet const>, unsigned short, ns3::Address const&, ns3::Address const&, ns3::NetDevice::PacketType, ns3::empty, ns3::empty, ns3::empty> (cb_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_IsBroadcast(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBroadcast();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetMtu(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMtu();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_IsBridge(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBridge();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetQueue(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Queue > retval;
    PyNs3Queue *py_Queue;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetQueue();
    if (!(const_cast<ns3::Queue *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Queue *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Queue__PythonHelper).name())
    {
        py_Queue = reinterpret_cast< PyNs3Queue* >(reinterpret_cast< PyNs3Queue__PythonHelper* >(const_cast<ns3::Queue *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Queue->obj = const_cast<ns3::Queue *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Queue);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Queue *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Queue = NULL;
        } else {
            py_Queue = (PyNs3Queue *) wrapper_lookup_iter->second;
            Py_INCREF(py_Queue);
        }
    
        if (py_Queue == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Queue *> (ns3::PeekPointer (retval)))), &PyNs3Queue_Type);
            py_Queue = PyObject_GC_New(PyNs3Queue, wrapper_type);
            py_Queue->inst_dict = NULL;
    
            py_Queue->inst_dict = NULL;
            py_Queue->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Queue *> (ns3::PeekPointer (retval))->Ref();
            py_Queue->obj = const_cast<ns3::Queue *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Queue->obj] = (PyObject *) py_Queue;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Queue);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::CsmaNetDevice::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetNode(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3CsmaNetDevice_Receive(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    PyNs3CsmaNetDevice *sender;
    ns3::CsmaNetDevice *sender_ptr;
    const char *keywords[] = {"p", "sender", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Packet_Type, &p, &PyNs3CsmaNetDevice_Type, &sender)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    sender_ptr = (sender ? sender->obj : NULL);
    self->obj->Receive(ns3::Ptr< ns3::Packet  > (p_ptr), ns3::Ptr< ns3::CsmaNetDevice  > (sender_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetAddress(PyNs3CsmaNetDevice *self)
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
_wrap_PyNs3CsmaNetDevice_IsLinkUp(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsLinkUp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetReceiveErrorModel(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3ErrorModel *em;
    ns3::ErrorModel *em_ptr;
    const char *keywords[] = {"em", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ErrorModel_Type, &em)) {
        return NULL;
    }
    em_ptr = (em ? em->obj : NULL);
    self->obj->SetReceiveErrorModel(ns3::Ptr< ns3::ErrorModel  > (em_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetAddress(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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
    } else if (PyObject_IsInstance(address, (PyObject*) &PyNs3Mac48Address_Type)) {
        address2 = *((PyNs3Mac48Address *) address)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Address, Ipv4Address, Ipv6Address, Mac48Address), not %s", Py_TYPE(address)->tp_name);
        return NULL;
    }
    self->obj->SetAddress(address2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_GetBroadcast(PyNs3CsmaNetDevice *self)
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
_wrap_PyNs3CsmaNetDevice_SetSendEnable(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool enable;
    PyObject *py_enable;
    const char *keywords[] = {"enable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_enable)) {
        return NULL;
    }
    enable = (bool) PyObject_IsTrue(py_enable);
    self->obj->SetSendEnable(enable);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_Attach(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3CsmaChannel *ch;
    ns3::CsmaChannel *ch_ptr;
    const char *keywords[] = {"ch", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CsmaChannel_Type, &ch)) {
        return NULL;
    }
    ch_ptr = (ch ? ch->obj : NULL);
    retval = self->obj->Attach(ns3::Ptr< ns3::CsmaChannel  > (ch_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetReceiveCallback(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *cb;
    ns3::Ptr<PythonCallbackImpl1> cb_cb_impl;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &cb)) {
        return NULL;
    }
    if (!PyCallable_Check(cb)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'cb' must be callbale");
        return NULL;
    }
    cb_cb_impl = ns3::Create<PythonCallbackImpl1> (cb);
    self->obj->SetReceiveCallback(ns3::Callback<bool, ns3::Ptr<ns3::NetDevice>, ns3::Ptr<ns3::Packet const>, unsigned short, ns3::Address const&, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (cb_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_IsMulticast(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsMulticast();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetMtu(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3CsmaNetDevice_SupportsSendFrom(PyNs3CsmaNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->SupportsSendFrom();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetInterframeGap(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        return NULL;
    }
    self->obj->SetInterframeGap(*((PyNs3Time *) t)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetReceiveEnable(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool enable;
    PyObject *py_enable;
    const char *keywords[] = {"enable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_enable)) {
        return NULL;
    }
    enable = (bool) PyObject_IsTrue(py_enable);
    self->obj->SetReceiveEnable(enable);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_AssignStreams(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3CsmaNetDevice_SetQueue(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Queue *queue;
    ns3::Queue *queue_ptr;
    const char *keywords[] = {"queue", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Queue_Type, &queue)) {
        return NULL;
    }
    queue_ptr = (queue ? queue->obj : NULL);
    self->obj->SetQueue(ns3::Ptr< ns3::Queue  > (queue_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CsmaNetDevice_SetIfIndex(PyNs3CsmaNetDevice *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef PyNs3CsmaNetDevice_methods[] = {
    {(char *) "SetEncapsulationMode", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetEncapsulationMode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMulticast", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetMulticast, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsPointToPoint", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsPointToPoint, METH_NOARGS, NULL },
    {(char *) "IsReceiveEnabled", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsReceiveEnabled, METH_NOARGS, NULL },
    {(char *) "SetBackoffParams", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetBackoffParams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Send", (PyCFunction) _wrap_PyNs3CsmaNetDevice_Send, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetIfIndex", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetIfIndex, METH_NOARGS, NULL },
    {(char *) "NeedsArp", (PyCFunction) _wrap_PyNs3CsmaNetDevice_NeedsArp, METH_NOARGS, NULL },
    {(char *) "GetChannel", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetChannel, METH_NOARGS, NULL },
    {(char *) "IsSendEnabled", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsSendEnabled, METH_NOARGS, NULL },
    {(char *) "GetEncapsulationMode", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetEncapsulationMode, METH_NOARGS, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetNode, METH_NOARGS, NULL },
    {(char *) "SendFrom", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SendFrom, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPromiscReceiveCallback", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetPromiscReceiveCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsBroadcast", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsBroadcast, METH_NOARGS, NULL },
    {(char *) "GetMtu", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetMtu, METH_NOARGS, NULL },
    {(char *) "IsBridge", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsBridge, METH_NOARGS, NULL },
    {(char *) "GetQueue", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetQueue, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetNode", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Receive", (PyCFunction) _wrap_PyNs3CsmaNetDevice_Receive, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAddress", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetAddress, METH_NOARGS, NULL },
    {(char *) "IsLinkUp", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsLinkUp, METH_NOARGS, NULL },
    {(char *) "SetReceiveErrorModel", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetReceiveErrorModel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAddress", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBroadcast", (PyCFunction) _wrap_PyNs3CsmaNetDevice_GetBroadcast, METH_NOARGS, NULL },
    {(char *) "SetSendEnable", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetSendEnable, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Attach", (PyCFunction) _wrap_PyNs3CsmaNetDevice_Attach, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetReceiveCallback", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetReceiveCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsMulticast", (PyCFunction) _wrap_PyNs3CsmaNetDevice_IsMulticast, METH_NOARGS, NULL },
    {(char *) "SetMtu", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetMtu, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SupportsSendFrom", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SupportsSendFrom, METH_NOARGS, NULL },
    {(char *) "SetInterframeGap", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetInterframeGap, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetReceiveEnable", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetReceiveEnable, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3CsmaNetDevice_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetQueue", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetQueue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIfIndex", (PyCFunction) _wrap_PyNs3CsmaNetDevice_SetIfIndex, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3CsmaNetDevice__tp_clear(PyNs3CsmaNetDevice *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::CsmaNetDevice *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3CsmaNetDevice__tp_traverse(PyNs3CsmaNetDevice *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3CsmaNetDevice__tp_dealloc(PyNs3CsmaNetDevice *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3CsmaNetDevice__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3CsmaNetDevice__tp_richcompare (PyNs3CsmaNetDevice *PYBINDGEN_UNUSED(self), PyNs3CsmaNetDevice *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3CsmaNetDevice_Type)) {
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

PyTypeObject PyNs3CsmaNetDevice_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "csma.CsmaNetDevice",            /* tp_name */
    sizeof(PyNs3CsmaNetDevice),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3CsmaNetDevice__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3CsmaNetDevice__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3CsmaNetDevice__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3CsmaNetDevice__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3CsmaNetDevice_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3CsmaNetDevice, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3CsmaNetDevice__tp_init,             /* tp_init */
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
    (char *) "csma.Std__list__lt___unsigned_int___gt__",            /* tp_name */
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
    (char *) "csma.Std__list__lt___unsigned_int___gt__Iter",            /* tp_name */
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


/* --- enumerations --- */

























#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef csma_moduledef = {
    PyModuleDef_HEAD_INIT,
    "csma",
    NULL,
    -1,
    csma_functions,
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


MOD_INIT(csma)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&csma_moduledef);
    #else
    m = Py_InitModule3((char *) "csma", csma_functions, NULL);
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
    /* Import the 'ns3::Queue' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Queue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Queue");
    
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
    /* Import the 'ns3::ParetoRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ParetoRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ParetoRandomVariable");
    
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
    /* Import the 'ns3::BurstErrorModel' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3BurstErrorModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "BurstErrorModel");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    PyModule_AddObject(m, (char *) "_PyNs3Backoff_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Backoff_wrapper_registry, NULL));
    /* Register the 'ns3::Backoff' class */
    if (PyType_Ready(&PyNs3Backoff_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Backoff", (PyObject *) &PyNs3Backoff_Type);
    PyModule_AddObject(m, (char *) "_PyNs3CsmaDeviceRec_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3CsmaDeviceRec_wrapper_registry, NULL));
    /* Register the 'ns3::CsmaDeviceRec' class */
    if (PyType_Ready(&PyNs3CsmaDeviceRec_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "CsmaDeviceRec", (PyObject *) &PyNs3CsmaDeviceRec_Type);
    /* Register the 'ns3::CsmaHelper' class */
    PyNs3CsmaHelper_Type.tp_base = &PyNs3PcapHelperForDevice_Type;
    PyNs3CsmaHelper_Type.tp_bases = PyTuple_New(2);
        Py_INCREF((PyObject *) &PyNs3PcapHelperForDevice_Type);
        PyTuple_SET_ITEM(PyNs3CsmaHelper_Type.tp_bases, 0, (PyObject *) &PyNs3PcapHelperForDevice_Type);
        Py_INCREF((PyObject *) &PyNs3AsciiTraceHelperForDevice_Type);
        PyTuple_SET_ITEM(PyNs3CsmaHelper_Type.tp_bases, 1, (PyObject *) &PyNs3AsciiTraceHelperForDevice_Type);
    if (PyType_Ready(&PyNs3CsmaHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "CsmaHelper", (PyObject *) &PyNs3CsmaHelper_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::CsmaChannel), &PyNs3CsmaChannel_Type);
    /* Register the 'ns3::CsmaChannel' class */
    PyNs3CsmaChannel_Type.tp_base = &PyNs3Channel_Type;
    if (PyType_Ready(&PyNs3CsmaChannel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "CsmaChannel", (PyObject *) &PyNs3CsmaChannel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::CsmaNetDevice), &PyNs3CsmaNetDevice_Type);
    /* Register the 'ns3::CsmaNetDevice' class */
    PyNs3CsmaNetDevice_Type.tp_base = &PyNs3NetDevice_Type;
    if (PyType_Ready(&PyNs3CsmaNetDevice_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "CsmaNetDevice", (PyObject *) &PyNs3CsmaNetDevice_Type);
    /* Register the 'std::list< unsigned int >' class */
    if (PyType_Ready(&Pystd__list__lt___unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___unsigned_int___gt__", (PyObject *) &Pystd__list__lt___unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___unsigned_int___gt__Iter", (PyObject *) &Pystd__list__lt___unsigned_int___gt__Iter_Type);
    PyModule_AddIntConstant(m, (char *) "IDLE", ns3::IDLE);
    PyModule_AddIntConstant(m, (char *) "TRANSMITTING", ns3::TRANSMITTING);
    PyModule_AddIntConstant(m, (char *) "PROPAGATING", ns3::PROPAGATING);
    {
        PyObject *tmp_value;
         // ns3::CsmaNetDevice::ILLEGAL
        tmp_value = PyLong_FromLong(ns3::CsmaNetDevice::ILLEGAL);
        PyDict_SetItemString((PyObject*) PyNs3CsmaNetDevice_Type.tp_dict, "ILLEGAL", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::CsmaNetDevice::DIX
        tmp_value = PyLong_FromLong(ns3::CsmaNetDevice::DIX);
        PyDict_SetItemString((PyObject*) PyNs3CsmaNetDevice_Type.tp_dict, "DIX", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::CsmaNetDevice::LLC
        tmp_value = PyLong_FromLong(ns3::CsmaNetDevice::LLC);
        PyDict_SetItemString((PyObject*) PyNs3CsmaNetDevice_Type.tp_dict, "LLC", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initcsma_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initcsma_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initcsma_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    return MOD_RETURN(m);
}
