#include "ns3module.h"
static PyMethodDef sixlowpan_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef sixlowpan_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "sixlowpan.FatalImpl",
    NULL,
    -1,
    sixlowpan_FatalImpl_functions,
};
#endif

static PyObject *
initsixlowpan_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&sixlowpan_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "sixlowpan.FatalImpl", sixlowpan_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef sixlowpan_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef sixlowpan_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "sixlowpan.Hash.Function",
    NULL,
    -1,
    sixlowpan_Hash_Function_functions,
};
#endif

static PyObject *
initsixlowpan_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&sixlowpan_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "sixlowpan.Hash.Function", sixlowpan_Hash_Function_functions, NULL);
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
static PyMethodDef sixlowpan_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef sixlowpan_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "sixlowpan.Hash",
    NULL,
    -1,
    sixlowpan_Hash_functions,
};
#endif

static PyObject *
initsixlowpan_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&sixlowpan_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "sixlowpan.Hash", sixlowpan_Hash_functions, NULL);
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
    submodule = initsixlowpan_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef sixlowpan_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef sixlowpan_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "sixlowpan.TracedValueCallback",
    NULL,
    -1,
    sixlowpan_TracedValueCallback_functions,
};
#endif

static PyObject *
initsixlowpan_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&sixlowpan_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "sixlowpan.TracedValueCallback", sixlowpan_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef sixlowpan_functions[] = {
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


PyTypeObject *_PyNs3Ipv6Header_Type;


PyTypeObject *_PyNs3Object_Type;


PyTypeObject *_PyNs3ObjectAggregateIterator_Type;
std::map<void*, PyObject*> *_PyNs3ObjectAggregateIterator_wrapper_registry;


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


PyTypeObject *_PyNs3ConstantRandomVariable_Type;


PyTypeObject *_PyNs3DeterministicRandomVariable_Type;


PyTypeObject *_PyNs3EmpiricalRandomVariable_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3ErlangRandomVariable_Type;


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


PyTypeObject *_PyNs3LogNormalRandomVariable_Type;


PyTypeObject *_PyNs3Mac48AddressChecker_Type;


PyTypeObject *_PyNs3Mac48AddressValue_Type;


PyTypeObject *_PyNs3NetDevice_Type;


PyTypeObject *_PyNs3NixVector_Type;


PyTypeObject *_PyNs3NormalRandomVariable_Type;


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3Packet_Type;


PyTypeObject *_PyNs3ParetoRandomVariable_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


std::map<void*, PyObject*> PyNs3SixLowPanDispatch_wrapper_registry;


static int
_wrap_PyNs3SixLowPanDispatch__tp_init__0(PyNs3SixLowPanDispatch *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanDispatch *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanDispatch_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanDispatch(*((PyNs3SixLowPanDispatch *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanDispatch__tp_init__1(PyNs3SixLowPanDispatch *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanDispatch();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanDispatch__tp_init(PyNs3SixLowPanDispatch *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanDispatch__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanDispatch__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanDispatch_GetNhcDispatchType(PyNs3SixLowPanDispatch *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanDispatch::NhcDispatch_e retval;
    int dispatch;
    const char *keywords[] = {"dispatch", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &dispatch)) {
        return NULL;
    }
    if (dispatch > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = ns3::SixLowPanDispatch::GetNhcDispatchType(dispatch);
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanDispatch_GetDispatchType(PyNs3SixLowPanDispatch *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanDispatch::Dispatch_e retval;
    int dispatch;
    const char *keywords[] = {"dispatch", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &dispatch)) {
        return NULL;
    }
    if (dispatch > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = ns3::SixLowPanDispatch::GetDispatchType(dispatch);
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanDispatch__copy__(PyNs3SixLowPanDispatch *self)
{

    PyNs3SixLowPanDispatch *py_copy;
    py_copy = PyObject_New(PyNs3SixLowPanDispatch, &PyNs3SixLowPanDispatch_Type);
    py_copy->obj = new ns3::SixLowPanDispatch(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3SixLowPanDispatch_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanDispatch_methods[] = {
    {(char *) "GetNhcDispatchType", (PyCFunction) _wrap_PyNs3SixLowPanDispatch_GetNhcDispatchType, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "GetDispatchType", (PyCFunction) _wrap_PyNs3SixLowPanDispatch_GetDispatchType, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanDispatch__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SixLowPanDispatch__tp_dealloc(PyNs3SixLowPanDispatch *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3SixLowPanDispatch_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3SixLowPanDispatch_wrapper_registry.end()) {
        PyNs3SixLowPanDispatch_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::SixLowPanDispatch *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SixLowPanDispatch__tp_richcompare (PyNs3SixLowPanDispatch *PYBINDGEN_UNUSED(self), PyNs3SixLowPanDispatch *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanDispatch_Type)) {
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

PyTypeObject PyNs3SixLowPanDispatch_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanDispatch",            /* tp_name */
    sizeof(PyNs3SixLowPanDispatch),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanDispatch__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3SixLowPanDispatch__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanDispatch_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanDispatch__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3SixLowPanHelper_wrapper_registry;


static int
_wrap_PyNs3SixLowPanHelper__tp_init__0(PyNs3SixLowPanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanHelper(*((PyNs3SixLowPanHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanHelper__tp_init__1(PyNs3SixLowPanHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanHelper__tp_init(PyNs3SixLowPanHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanHelper_SetDeviceAttribute(PyNs3SixLowPanHelper *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanHelper_Install(PyNs3SixLowPanHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NetDeviceContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3NetDeviceContainer *py_NetDeviceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NetDeviceContainer_Type, &c)) {
        return NULL;
    }
    ns3::NetDeviceContainer retval = self->obj->Install(*((PyNs3NetDeviceContainer *) c)->obj);
    py_NetDeviceContainer = PyObject_New(PyNs3NetDeviceContainer, &PyNs3NetDeviceContainer_Type);
    py_NetDeviceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NetDeviceContainer->obj = new ns3::NetDeviceContainer(retval);
    PyNs3NetDeviceContainer_wrapper_registry[(void *) py_NetDeviceContainer->obj] = (PyObject *) py_NetDeviceContainer;
    py_retval = Py_BuildValue((char *) "N", py_NetDeviceContainer);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHelper_AssignStreams(PyNs3SixLowPanHelper *self, PyObject *args, PyObject *kwargs)
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


static PyObject*
_wrap_PyNs3SixLowPanHelper__copy__(PyNs3SixLowPanHelper *self)
{

    PyNs3SixLowPanHelper *py_copy;
    py_copy = PyObject_New(PyNs3SixLowPanHelper, &PyNs3SixLowPanHelper_Type);
    py_copy->obj = new ns3::SixLowPanHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3SixLowPanHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanHelper_methods[] = {
    {(char *) "SetDeviceAttribute", (PyCFunction) _wrap_PyNs3SixLowPanHelper_SetDeviceAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3SixLowPanHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3SixLowPanHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3SixLowPanHelper__tp_dealloc(PyNs3SixLowPanHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3SixLowPanHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3SixLowPanHelper_wrapper_registry.end()) {
        PyNs3SixLowPanHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::SixLowPanHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SixLowPanHelper__tp_richcompare (PyNs3SixLowPanHelper *PYBINDGEN_UNUSED(self), PyNs3SixLowPanHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanHelper_Type)) {
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

PyTypeObject PyNs3SixLowPanHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanHelper",            /* tp_name */
    sizeof(PyNs3SixLowPanHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3SixLowPanHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanHelper__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanFrag1__tp_init__0(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanFrag1 *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanFrag1_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanFrag1(*((PyNs3SixLowPanFrag1 *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanFrag1__tp_init__1(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanFrag1();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanFrag1__tp_init(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanFrag1__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanFrag1__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanFrag1_GetDatagramTag(PyNs3SixLowPanFrag1 *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetDatagramTag();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFrag1_GetDatagramSize(PyNs3SixLowPanFrag1 *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetDatagramSize();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFrag1_Deserialize(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanFrag1_SetDatagramSize(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int datagramSize;
    const char *keywords[] = {"datagramSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &datagramSize)) {
        return NULL;
    }
    if (datagramSize > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDatagramSize(datagramSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFrag1_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanFrag1::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFrag1_Serialize(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanFrag1_GetInstanceTypeId(PyNs3SixLowPanFrag1 *self)
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
_wrap_PyNs3SixLowPanFrag1_GetSerializedSize(PyNs3SixLowPanFrag1 *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFrag1_SetDatagramTag(PyNs3SixLowPanFrag1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int datagramTag;
    const char *keywords[] = {"datagramTag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &datagramTag)) {
        return NULL;
    }
    if (datagramTag > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDatagramTag(datagramTag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanFrag1__copy__(PyNs3SixLowPanFrag1 *self)
{

    PyNs3SixLowPanFrag1 *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanFrag1, &PyNs3SixLowPanFrag1_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanFrag1(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanFrag1_methods[] = {
    {(char *) "GetDatagramTag", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_GetDatagramTag, METH_NOARGS, NULL },
    {(char *) "GetDatagramSize", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_GetDatagramSize, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDatagramSize", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_SetDatagramSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetDatagramTag", (PyCFunction) _wrap_PyNs3SixLowPanFrag1_SetDatagramTag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanFrag1__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanFrag1__tp_clear(PyNs3SixLowPanFrag1 *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanFrag1 *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanFrag1__tp_traverse(PyNs3SixLowPanFrag1 *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanFrag1__tp_dealloc(PyNs3SixLowPanFrag1 *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanFrag1__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanFrag1__tp_str(PyNs3SixLowPanFrag1 *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanFrag1__tp_richcompare (PyNs3SixLowPanFrag1 *PYBINDGEN_UNUSED(self), PyNs3SixLowPanFrag1 *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanFrag1_Type)) {
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

PyTypeObject PyNs3SixLowPanFrag1_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanFrag1",            /* tp_name */
    sizeof(PyNs3SixLowPanFrag1),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanFrag1__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanFrag1__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanFrag1__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanFrag1__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanFrag1__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanFrag1_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanFrag1, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanFrag1__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanFragN__tp_init__0(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanFragN *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanFragN_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanFragN(*((PyNs3SixLowPanFragN *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanFragN__tp_init__1(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanFragN();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanFragN__tp_init(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanFragN__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanFragN__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanFragN_GetDatagramTag(PyNs3SixLowPanFragN *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetDatagramTag();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_GetDatagramSize(PyNs3SixLowPanFragN *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetDatagramSize();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_Deserialize(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanFragN_SetDatagramSize(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int datagramSize;
    const char *keywords[] = {"datagramSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &datagramSize)) {
        return NULL;
    }
    if (datagramSize > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDatagramSize(datagramSize);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanFragN::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_Serialize(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanFragN_GetDatagramOffset(PyNs3SixLowPanFragN *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetDatagramOffset();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_GetInstanceTypeId(PyNs3SixLowPanFragN *self)
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
_wrap_PyNs3SixLowPanFragN_GetSerializedSize(PyNs3SixLowPanFragN *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_SetDatagramOffset(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int datagramOffset;
    const char *keywords[] = {"datagramOffset", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &datagramOffset)) {
        return NULL;
    }
    if (datagramOffset > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDatagramOffset(datagramOffset);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanFragN_SetDatagramTag(PyNs3SixLowPanFragN *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int datagramTag;
    const char *keywords[] = {"datagramTag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &datagramTag)) {
        return NULL;
    }
    if (datagramTag > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDatagramTag(datagramTag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanFragN__copy__(PyNs3SixLowPanFragN *self)
{

    PyNs3SixLowPanFragN *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanFragN, &PyNs3SixLowPanFragN_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanFragN(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanFragN_methods[] = {
    {(char *) "GetDatagramTag", (PyCFunction) _wrap_PyNs3SixLowPanFragN_GetDatagramTag, METH_NOARGS, NULL },
    {(char *) "GetDatagramSize", (PyCFunction) _wrap_PyNs3SixLowPanFragN_GetDatagramSize, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanFragN_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDatagramSize", (PyCFunction) _wrap_PyNs3SixLowPanFragN_SetDatagramSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanFragN_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanFragN_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDatagramOffset", (PyCFunction) _wrap_PyNs3SixLowPanFragN_GetDatagramOffset, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanFragN_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanFragN_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetDatagramOffset", (PyCFunction) _wrap_PyNs3SixLowPanFragN_SetDatagramOffset, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDatagramTag", (PyCFunction) _wrap_PyNs3SixLowPanFragN_SetDatagramTag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanFragN__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanFragN__tp_clear(PyNs3SixLowPanFragN *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanFragN *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanFragN__tp_traverse(PyNs3SixLowPanFragN *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanFragN__tp_dealloc(PyNs3SixLowPanFragN *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanFragN__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanFragN__tp_str(PyNs3SixLowPanFragN *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanFragN__tp_richcompare (PyNs3SixLowPanFragN *PYBINDGEN_UNUSED(self), PyNs3SixLowPanFragN *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanFragN_Type)) {
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

PyTypeObject PyNs3SixLowPanFragN_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanFragN",            /* tp_name */
    sizeof(PyNs3SixLowPanFragN),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanFragN__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanFragN__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanFragN__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanFragN__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanFragN__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanFragN_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanFragN, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanFragN__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanHc1__tp_init__0(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanHc1 *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanHc1_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanHc1(*((PyNs3SixLowPanHc1 *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanHc1__tp_init__1(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanHc1();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanHc1__tp_init(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanHc1__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanHc1__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanHc1_SetSrcCompression(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanHc1::LowPanHc1Addr_e srcCompression;
    const char *keywords[] = {"srcCompression", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &srcCompression)) {
        return NULL;
    }
    self->obj->SetSrcCompression(srcCompression);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetDstCompression(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    ns3::SixLowPanHc1::LowPanHc1Addr_e retval;
    
    retval = self->obj->GetDstCompression();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_SetHopLimit(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int limit;
    const char *keywords[] = {"limit", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &limit)) {
        return NULL;
    }
    if (limit > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHopLimit(limit);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_Deserialize(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanHc1_SetDstCompression(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanHc1::LowPanHc1Addr_e dstCompression;
    const char *keywords[] = {"dstCompression", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &dstCompression)) {
        return NULL;
    }
    self->obj->SetDstCompression(dstCompression);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetFlowLabel(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetFlowLabel();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_Serialize(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanHc1_GetNextHeader(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetNextHeader();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_SetFlowLabel(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowLabel;
    const char *keywords[] = {"flowLabel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &flowLabel)) {
        return NULL;
    }
    self->obj->SetFlowLabel(flowLabel);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_IsHc2HeaderPresent(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsHc2HeaderPresent();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_SetNextHeader(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int nextHeader;
    const char *keywords[] = {"nextHeader", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &nextHeader)) {
        return NULL;
    }
    if (nextHeader > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetNextHeader(nextHeader);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanHc1::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_SetTrafficClass(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int trafficClass;
    const char *keywords[] = {"trafficClass", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &trafficClass)) {
        return NULL;
    }
    if (trafficClass > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetTrafficClass(trafficClass);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_SetHc2HeaderPresent(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool hc2HeaderPresent;
    PyObject *py_hc2HeaderPresent;
    const char *keywords[] = {"hc2HeaderPresent", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_hc2HeaderPresent)) {
        return NULL;
    }
    hc2HeaderPresent = (bool) PyObject_IsTrue(py_hc2HeaderPresent);
    self->obj->SetHc2HeaderPresent(hc2HeaderPresent);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetInstanceTypeId(PyNs3SixLowPanHc1 *self)
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
_wrap_PyNs3SixLowPanHc1_GetSerializedSize(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetHopLimit(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetHopLimit();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetTrafficClass(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetTrafficClass();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_SetTcflCompression(PyNs3SixLowPanHc1 *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool tcflCompression;
    PyObject *py_tcflCompression;
    const char *keywords[] = {"tcflCompression", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_tcflCompression)) {
        return NULL;
    }
    tcflCompression = (bool) PyObject_IsTrue(py_tcflCompression);
    self->obj->SetTcflCompression(tcflCompression);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_GetSrcCompression(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    ns3::SixLowPanHc1::LowPanHc1Addr_e retval;
    
    retval = self->obj->GetSrcCompression();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanHc1_IsTcflCompression(PyNs3SixLowPanHc1 *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsTcflCompression();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanHc1__copy__(PyNs3SixLowPanHc1 *self)
{

    PyNs3SixLowPanHc1 *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanHc1, &PyNs3SixLowPanHc1_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanHc1(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanHc1_methods[] = {
    {(char *) "SetSrcCompression", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetSrcCompression, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDstCompression", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetDstCompression, METH_NOARGS, NULL },
    {(char *) "SetHopLimit", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetHopLimit, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanHc1_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDstCompression", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetDstCompression, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFlowLabel", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetFlowLabel, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanHc1_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNextHeader", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetNextHeader, METH_NOARGS, NULL },
    {(char *) "SetFlowLabel", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetFlowLabel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsHc2HeaderPresent", (PyCFunction) _wrap_PyNs3SixLowPanHc1_IsHc2HeaderPresent, METH_NOARGS, NULL },
    {(char *) "SetNextHeader", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetNextHeader, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetTrafficClass", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetTrafficClass, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHc2HeaderPresent", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetHc2HeaderPresent, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "GetHopLimit", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetHopLimit, METH_NOARGS, NULL },
    {(char *) "GetTrafficClass", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetTrafficClass, METH_NOARGS, NULL },
    {(char *) "SetTcflCompression", (PyCFunction) _wrap_PyNs3SixLowPanHc1_SetTcflCompression, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSrcCompression", (PyCFunction) _wrap_PyNs3SixLowPanHc1_GetSrcCompression, METH_NOARGS, NULL },
    {(char *) "IsTcflCompression", (PyCFunction) _wrap_PyNs3SixLowPanHc1_IsTcflCompression, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanHc1__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanHc1__tp_clear(PyNs3SixLowPanHc1 *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanHc1 *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanHc1__tp_traverse(PyNs3SixLowPanHc1 *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanHc1__tp_dealloc(PyNs3SixLowPanHc1 *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanHc1__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanHc1__tp_str(PyNs3SixLowPanHc1 *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanHc1__tp_richcompare (PyNs3SixLowPanHc1 *PYBINDGEN_UNUSED(self), PyNs3SixLowPanHc1 *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanHc1_Type)) {
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

PyTypeObject PyNs3SixLowPanHc1_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanHc1",            /* tp_name */
    sizeof(PyNs3SixLowPanHc1),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanHc1__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanHc1__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanHc1__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanHc1__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanHc1__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanHc1_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanHc1, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanHc1__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanIphc__tp_init__0(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanIphc *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanIphc_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanIphc(*((PyNs3SixLowPanIphc *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanIphc__tp_init__1(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanIphc();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanIphc__tp_init__2(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int dispatch;
    const char *keywords[] = {"dispatch", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &dispatch)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (dispatch > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanIphc(dispatch);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanIphc__tp_init(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3SixLowPanIphc__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanIphc__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanIphc__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3SixLowPanIphc_SetSam(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::HeaderCompression_e samField;
    const char *keywords[] = {"samField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &samField)) {
        return NULL;
    }
    self->obj->SetSam(samField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanIphc::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetNh(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetNh();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetSac(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool sacField;
    PyObject *py_sacField;
    const char *keywords[] = {"sacField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_sacField)) {
        return NULL;
    }
    sacField = (bool) PyObject_IsTrue(py_sacField);
    self->obj->SetSac(sacField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetCid(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetCid();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetHlim(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::Hlim_e retval;
    
    retval = self->obj->GetHlim();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetHlim(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::Hlim_e hlimField;
    const char *keywords[] = {"hlimField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &hlimField)) {
        return NULL;
    }
    self->obj->SetHlim(hlimField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetDstAddress(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *dstAddress;
    const char *keywords[] = {"dstAddress", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &dstAddress)) {
        return NULL;
    }
    self->obj->SetDstAddress(*((PyNs3Ipv6Address *) dstAddress)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetSrcAddress(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *srcAddress;
    const char *keywords[] = {"srcAddress", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv6Address_Type, &srcAddress)) {
        return NULL;
    }
    self->obj->SetSrcAddress(*((PyNs3Ipv6Address *) srcAddress)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetSrcContextId(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int srcContextId;
    const char *keywords[] = {"srcContextId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &srcContextId)) {
        return NULL;
    }
    if (srcContextId > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSrcContextId(srcContextId);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetM(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetM();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetNh(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool nhField;
    PyObject *py_nhField;
    const char *keywords[] = {"nhField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_nhField)) {
        return NULL;
    }
    nhField = (bool) PyObject_IsTrue(py_nhField);
    self->obj->SetNh(nhField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetTf(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::TrafficClassFlowLabel_e tfField;
    const char *keywords[] = {"tfField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &tfField)) {
        return NULL;
    }
    self->obj->SetTf(tfField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetFlowLabel(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int flowLabel;
    const char *keywords[] = {"flowLabel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &flowLabel)) {
        return NULL;
    }
    self->obj->SetFlowLabel(flowLabel);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetSac(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetSac();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetDstAddress(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetDstAddress();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetDstContextId(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetDstContextId();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetHopLimit(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetHopLimit();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetSrcContextId(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetSrcContextId();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetEcn(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetEcn();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetDac(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool dacField;
    PyObject *py_dacField;
    const char *keywords[] = {"dacField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_dacField)) {
        return NULL;
    }
    dacField = (bool) PyObject_IsTrue(py_dacField);
    self->obj->SetDac(dacField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetTf(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::TrafficClassFlowLabel_e retval;
    
    retval = self->obj->GetTf();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetHopLimit(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int hopLimit;
    const char *keywords[] = {"hopLimit", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &hopLimit)) {
        return NULL;
    }
    if (hopLimit > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHopLimit(hopLimit);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_Deserialize(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanIphc_SetEcn(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int ecn;
    const char *keywords[] = {"ecn", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &ecn)) {
        return NULL;
    }
    if (ecn > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetEcn(ecn);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetFlowLabel(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetFlowLabel();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetSrcAddress(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    PyNs3Ipv6Address *py_Ipv6Address;
    
    ns3::Ipv6Address retval = self->obj->GetSrcAddress();
    py_Ipv6Address = PyObject_New(PyNs3Ipv6Address, &PyNs3Ipv6Address_Type);
    py_Ipv6Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv6Address->obj = new ns3::Ipv6Address(retval);
    PyNs3Ipv6Address_wrapper_registry[(void *) py_Ipv6Address->obj] = (PyObject *) py_Ipv6Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv6Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetDam(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::HeaderCompression_e damField;
    const char *keywords[] = {"damField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &damField)) {
        return NULL;
    }
    self->obj->SetDam(damField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetDscp(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int dscp;
    const char *keywords[] = {"dscp", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &dscp)) {
        return NULL;
    }
    if (dscp > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDscp(dscp);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetNextHeader(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int nextHeader;
    const char *keywords[] = {"nextHeader", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &nextHeader)) {
        return NULL;
    }
    if (nextHeader > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetNextHeader(nextHeader);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetInstanceTypeId(PyNs3SixLowPanIphc *self)
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
_wrap_PyNs3SixLowPanIphc_GetSerializedSize(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetDstContextId(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int dstContextId;
    const char *keywords[] = {"dstContextId", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &dstContextId)) {
        return NULL;
    }
    if (dstContextId > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDstContextId(dstContextId);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetDam(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::HeaderCompression_e retval;
    
    retval = self->obj->GetDam();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetCid(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool cidField;
    PyObject *py_cidField;
    const char *keywords[] = {"cidField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_cidField)) {
        return NULL;
    }
    cidField = (bool) PyObject_IsTrue(py_cidField);
    self->obj->SetCid(cidField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_SetM(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool mField;
    PyObject *py_mField;
    const char *keywords[] = {"mField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_mField)) {
        return NULL;
    }
    mField = (bool) PyObject_IsTrue(py_mField);
    self->obj->SetM(mField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_Serialize(PyNs3SixLowPanIphc *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanIphc_GetNextHeader(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetNextHeader();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetDac(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetDac();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetDscp(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetDscp();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIphc_GetSam(PyNs3SixLowPanIphc *self)
{
    PyObject *py_retval;
    ns3::SixLowPanIphc::HeaderCompression_e retval;
    
    retval = self->obj->GetSam();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanIphc__copy__(PyNs3SixLowPanIphc *self)
{

    PyNs3SixLowPanIphc *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanIphc, &PyNs3SixLowPanIphc_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanIphc(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanIphc_methods[] = {
    {(char *) "SetSam", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetSam, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetNh", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetNh, METH_NOARGS, NULL },
    {(char *) "SetSac", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetSac, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetCid", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetCid, METH_NOARGS, NULL },
    {(char *) "GetHlim", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetHlim, METH_NOARGS, NULL },
    {(char *) "SetHlim", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetHlim, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDstAddress", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetDstAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSrcAddress", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetSrcAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSrcContextId", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetSrcContextId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetM", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetM, METH_NOARGS, NULL },
    {(char *) "SetNh", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetNh, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTf", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetTf, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFlowLabel", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetFlowLabel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSac", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetSac, METH_NOARGS, NULL },
    {(char *) "GetDstAddress", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetDstAddress, METH_NOARGS, NULL },
    {(char *) "GetDstContextId", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetDstContextId, METH_NOARGS, NULL },
    {(char *) "GetHopLimit", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetHopLimit, METH_NOARGS, NULL },
    {(char *) "GetSrcContextId", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetSrcContextId, METH_NOARGS, NULL },
    {(char *) "GetEcn", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetEcn, METH_NOARGS, NULL },
    {(char *) "SetDac", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetDac, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTf", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetTf, METH_NOARGS, NULL },
    {(char *) "SetHopLimit", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetHopLimit, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanIphc_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetEcn", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetEcn, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFlowLabel", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetFlowLabel, METH_NOARGS, NULL },
    {(char *) "GetSrcAddress", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetSrcAddress, METH_NOARGS, NULL },
    {(char *) "SetDam", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetDam, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDscp", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetDscp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetNextHeader", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetNextHeader, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetDstContextId", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetDstContextId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDam", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetDam, METH_NOARGS, NULL },
    {(char *) "SetCid", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetCid, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetM", (PyCFunction) _wrap_PyNs3SixLowPanIphc_SetM, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanIphc_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNextHeader", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetNextHeader, METH_NOARGS, NULL },
    {(char *) "GetDac", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetDac, METH_NOARGS, NULL },
    {(char *) "GetDscp", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetDscp, METH_NOARGS, NULL },
    {(char *) "GetSam", (PyCFunction) _wrap_PyNs3SixLowPanIphc_GetSam, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanIphc__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanIphc__tp_clear(PyNs3SixLowPanIphc *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanIphc *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanIphc__tp_traverse(PyNs3SixLowPanIphc *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanIphc__tp_dealloc(PyNs3SixLowPanIphc *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanIphc__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanIphc__tp_str(PyNs3SixLowPanIphc *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanIphc__tp_richcompare (PyNs3SixLowPanIphc *PYBINDGEN_UNUSED(self), PyNs3SixLowPanIphc *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanIphc_Type)) {
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

PyTypeObject PyNs3SixLowPanIphc_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanIphc",            /* tp_name */
    sizeof(PyNs3SixLowPanIphc),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanIphc__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanIphc__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanIphc__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanIphc__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanIphc__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanIphc_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanIphc, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanIphc__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanIpv6__tp_init__0(PyNs3SixLowPanIpv6 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanIpv6 *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanIpv6_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanIpv6(*((PyNs3SixLowPanIpv6 *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanIpv6__tp_init__1(PyNs3SixLowPanIpv6 *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanIpv6();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanIpv6__tp_init(PyNs3SixLowPanIpv6 *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanIpv6__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanIpv6__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanIpv6_GetSerializedSize(PyNs3SixLowPanIpv6 *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIpv6_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanIpv6::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanIpv6_Serialize(PyNs3SixLowPanIpv6 *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanIpv6_Deserialize(PyNs3SixLowPanIpv6 *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanIpv6_GetInstanceTypeId(PyNs3SixLowPanIpv6 *self)
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


static PyObject*
_wrap_PyNs3SixLowPanIpv6__copy__(PyNs3SixLowPanIpv6 *self)
{

    PyNs3SixLowPanIpv6 *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanIpv6, &PyNs3SixLowPanIpv6_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanIpv6(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanIpv6_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanIpv6_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanIpv6_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanIpv6_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanIpv6_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanIpv6_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanIpv6__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanIpv6__tp_clear(PyNs3SixLowPanIpv6 *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanIpv6 *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanIpv6__tp_traverse(PyNs3SixLowPanIpv6 *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanIpv6__tp_dealloc(PyNs3SixLowPanIpv6 *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanIpv6__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanIpv6__tp_str(PyNs3SixLowPanIpv6 *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanIpv6__tp_richcompare (PyNs3SixLowPanIpv6 *PYBINDGEN_UNUSED(self), PyNs3SixLowPanIpv6 *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanIpv6_Type)) {
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

PyTypeObject PyNs3SixLowPanIpv6_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanIpv6",            /* tp_name */
    sizeof(PyNs3SixLowPanIpv6),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanIpv6__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanIpv6__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanIpv6__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanIpv6__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanIpv6__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanIpv6_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanIpv6, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanIpv6__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanNhcExtension__tp_init__0(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanNhcExtension *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanNhcExtension_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanNhcExtension(*((PyNs3SixLowPanNhcExtension *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanNhcExtension__tp_init__1(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanNhcExtension();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanNhcExtension__tp_init(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanNhcExtension__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanNhcExtension__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanNhcExtension_SetNh(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool nhField;
    PyObject *py_nhField;
    const char *keywords[] = {"nhField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_nhField)) {
        return NULL;
    }
    nhField = (bool) PyObject_IsTrue(py_nhField);
    self->obj->SetNh(nhField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_Serialize(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNhcExtension_Deserialize(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNhcExtension_SetNextHeader(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int nextHeader;
    const char *keywords[] = {"nextHeader", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &nextHeader)) {
        return NULL;
    }
    if (nextHeader > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetNextHeader(nextHeader);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanNhcExtension::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_GetNh(PyNs3SixLowPanNhcExtension *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetNh();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_GetNextHeader(PyNs3SixLowPanNhcExtension *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetNextHeader();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_SetEid(PyNs3SixLowPanNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanNhcExtension::Eid_e extensionHeaderType;
    const char *keywords[] = {"extensionHeaderType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &extensionHeaderType)) {
        return NULL;
    }
    self->obj->SetEid(extensionHeaderType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_GetNhcDispatchType(PyNs3SixLowPanNhcExtension *self)
{
    PyObject *py_retval;
    ns3::SixLowPanDispatch::NhcDispatch_e retval;
    
    retval = self->obj->GetNhcDispatchType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_GetEid(PyNs3SixLowPanNhcExtension *self)
{
    PyObject *py_retval;
    ns3::SixLowPanNhcExtension::Eid_e retval;
    
    retval = self->obj->GetEid();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNhcExtension_GetInstanceTypeId(PyNs3SixLowPanNhcExtension *self)
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
_wrap_PyNs3SixLowPanNhcExtension_GetSerializedSize(PyNs3SixLowPanNhcExtension *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanNhcExtension__copy__(PyNs3SixLowPanNhcExtension *self)
{

    PyNs3SixLowPanNhcExtension *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanNhcExtension, &PyNs3SixLowPanNhcExtension_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanNhcExtension(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanNhcExtension_methods[] = {
    {(char *) "SetNh", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_SetNh, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetNextHeader", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_SetNextHeader, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetNh", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetNh, METH_NOARGS, NULL },
    {(char *) "GetNextHeader", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetNextHeader, METH_NOARGS, NULL },
    {(char *) "SetEid", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_SetEid, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNhcDispatchType", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetNhcDispatchType, METH_NOARGS, NULL },
    {(char *) "GetEid", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetEid, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanNhcExtension__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanNhcExtension__tp_clear(PyNs3SixLowPanNhcExtension *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanNhcExtension *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanNhcExtension__tp_traverse(PyNs3SixLowPanNhcExtension *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanNhcExtension__tp_dealloc(PyNs3SixLowPanNhcExtension *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanNhcExtension__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanNhcExtension__tp_str(PyNs3SixLowPanNhcExtension *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanNhcExtension__tp_richcompare (PyNs3SixLowPanNhcExtension *PYBINDGEN_UNUSED(self), PyNs3SixLowPanNhcExtension *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanNhcExtension_Type)) {
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

PyTypeObject PyNs3SixLowPanNhcExtension_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanNhcExtension",            /* tp_name */
    sizeof(PyNs3SixLowPanNhcExtension),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanNhcExtension__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanNhcExtension__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanNhcExtension__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanNhcExtension__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanNhcExtension__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanNhcExtension_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanNhcExtension, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanNhcExtension__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanUdpNhcExtension__tp_init__0(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SixLowPanUdpNhcExtension *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SixLowPanUdpNhcExtension_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::SixLowPanUdpNhcExtension(*((PyNs3SixLowPanUdpNhcExtension *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3SixLowPanUdpNhcExtension__tp_init__1(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::SixLowPanUdpNhcExtension();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3SixLowPanUdpNhcExtension__tp_init(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanUdpNhcExtension__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanUdpNhcExtension__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanUdpNhcExtension_SetSrcPort(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int port;
    const char *keywords[] = {"port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &port)) {
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetSrcPort(port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetDstPort(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetDstPort();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_Serialize(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanUdpNhcExtension_Deserialize(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanUdpNhcExtension_GetChecksum(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetChecksum();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_SetC(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool cField;
    PyObject *py_cField;
    const char *keywords[] = {"cField", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_cField)) {
        return NULL;
    }
    cField = (bool) PyObject_IsTrue(py_cField);
    self->obj->SetC(cField);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanUdpNhcExtension::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetC(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetC();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetPorts(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    ns3::SixLowPanUdpNhcExtension::Ports_e retval;
    
    retval = self->obj->GetPorts();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetSrcPort(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetSrcPort();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_SetPorts(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::SixLowPanUdpNhcExtension::Ports_e port;
    const char *keywords[] = {"port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &port)) {
        return NULL;
    }
    self->obj->SetPorts(port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetNhcDispatchType(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    ns3::SixLowPanDispatch::NhcDispatch_e retval;
    
    retval = self->obj->GetNhcDispatchType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_SetDstPort(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int port;
    const char *keywords[] = {"port", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &port)) {
        return NULL;
    }
    if (port > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetDstPort(port);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_GetInstanceTypeId(PyNs3SixLowPanUdpNhcExtension *self)
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
_wrap_PyNs3SixLowPanUdpNhcExtension_GetSerializedSize(PyNs3SixLowPanUdpNhcExtension *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension_SetChecksum(PyNs3SixLowPanUdpNhcExtension *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int checksum;
    const char *keywords[] = {"checksum", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &checksum)) {
        return NULL;
    }
    if (checksum > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetChecksum(checksum);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3SixLowPanUdpNhcExtension__copy__(PyNs3SixLowPanUdpNhcExtension *self)
{

    PyNs3SixLowPanUdpNhcExtension *py_copy;
    py_copy = PyObject_GC_New(PyNs3SixLowPanUdpNhcExtension, &PyNs3SixLowPanUdpNhcExtension_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::SixLowPanUdpNhcExtension(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SixLowPanUdpNhcExtension_methods[] = {
    {(char *) "SetSrcPort", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_SetSrcPort, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDstPort", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetDstPort, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetChecksum", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetChecksum, METH_NOARGS, NULL },
    {(char *) "SetC", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_SetC, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetC", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetC, METH_NOARGS, NULL },
    {(char *) "GetPorts", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetPorts, METH_NOARGS, NULL },
    {(char *) "GetSrcPort", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetSrcPort, METH_NOARGS, NULL },
    {(char *) "SetPorts", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_SetPorts, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNhcDispatchType", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetNhcDispatchType, METH_NOARGS, NULL },
    {(char *) "SetDstPort", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_SetDstPort, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetChecksum", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension_SetChecksum, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SixLowPanUdpNhcExtension__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanUdpNhcExtension__tp_clear(PyNs3SixLowPanUdpNhcExtension *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::SixLowPanUdpNhcExtension *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3SixLowPanUdpNhcExtension__tp_traverse(PyNs3SixLowPanUdpNhcExtension *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanUdpNhcExtension__tp_dealloc(PyNs3SixLowPanUdpNhcExtension *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanUdpNhcExtension__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3SixLowPanUdpNhcExtension__tp_str(PyNs3SixLowPanUdpNhcExtension *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3SixLowPanUdpNhcExtension__tp_richcompare (PyNs3SixLowPanUdpNhcExtension *PYBINDGEN_UNUSED(self), PyNs3SixLowPanUdpNhcExtension *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanUdpNhcExtension_Type)) {
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

PyTypeObject PyNs3SixLowPanUdpNhcExtension_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanUdpNhcExtension",            /* tp_name */
    sizeof(PyNs3SixLowPanUdpNhcExtension),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanUdpNhcExtension__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3SixLowPanUdpNhcExtension__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3SixLowPanUdpNhcExtension__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanUdpNhcExtension__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanUdpNhcExtension__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanUdpNhcExtension_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanUdpNhcExtension, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanUdpNhcExtension__tp_init,             /* tp_init */
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
_wrap_PyNs3SixLowPanNetDevice__tp_init(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    self->obj = new ns3::SixLowPanNetDevice();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}



PyObject *
_wrap_PyNs3SixLowPanNetDevice_GetMulticast__0(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
_wrap_PyNs3SixLowPanNetDevice_GetMulticast__1(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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

PyObject * _wrap_PyNs3SixLowPanNetDevice_GetMulticast(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SixLowPanNetDevice_GetMulticast__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SixLowPanNetDevice_GetMulticast__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SixLowPanNetDevice_IsPointToPoint(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsPointToPoint();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SixLowPanNetDevice::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_Send(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_GetIfIndex(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetIfIndex();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_NeedsArp(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->NeedsArp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_SetPromiscReceiveCallback(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_SendFrom(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_IsBroadcast(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBroadcast();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_GetMtu(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMtu();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_IsBridge(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsBridge();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_GetAddress(PyNs3SixLowPanNetDevice *self)
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
_wrap_PyNs3SixLowPanNetDevice_IsLinkUp(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsLinkUp();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_SetIfIndex(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_SetNetDevice(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NetDevice *device;
    ns3::NetDevice *device_ptr;
    const char *keywords[] = {"device", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NetDevice_Type, &device)) {
        return NULL;
    }
    device_ptr = (device ? device->obj : NULL);
    self->obj->SetNetDevice(ns3::Ptr< ns3::NetDevice  > (device_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_SetAddress(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_GetBroadcast(PyNs3SixLowPanNetDevice *self)
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
_wrap_PyNs3SixLowPanNetDevice_GetNetDevice(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::NetDevice > retval;
    PyNs3NetDevice *py_NetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetNetDevice();
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
_wrap_PyNs3SixLowPanNetDevice_SetReceiveCallback(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_IsMulticast(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsMulticast();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_SetMtu(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3SixLowPanNetDevice_SupportsSendFrom(PyNs3SixLowPanNetDevice *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->SupportsSendFrom();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3SixLowPanNetDevice_AssignStreams(PyNs3SixLowPanNetDevice *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef PyNs3SixLowPanNetDevice_methods[] = {
    {(char *) "GetMulticast", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetMulticast, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsPointToPoint", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_IsPointToPoint, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Send", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_Send, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetIfIndex", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetIfIndex, METH_NOARGS, NULL },
    {(char *) "NeedsArp", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_NeedsArp, METH_NOARGS, NULL },
    {(char *) "SetPromiscReceiveCallback", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SetPromiscReceiveCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SendFrom", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SendFrom, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsBroadcast", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_IsBroadcast, METH_NOARGS, NULL },
    {(char *) "GetMtu", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetMtu, METH_NOARGS, NULL },
    {(char *) "IsBridge", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_IsBridge, METH_NOARGS, NULL },
    {(char *) "GetAddress", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetAddress, METH_NOARGS, NULL },
    {(char *) "IsLinkUp", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_IsLinkUp, METH_NOARGS, NULL },
    {(char *) "SetIfIndex", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SetIfIndex, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetNetDevice", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SetNetDevice, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAddress", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SetAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBroadcast", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetBroadcast, METH_NOARGS, NULL },
    {(char *) "GetNetDevice", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_GetNetDevice, METH_NOARGS, NULL },
    {(char *) "SetReceiveCallback", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SetReceiveCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsMulticast", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_IsMulticast, METH_NOARGS, NULL },
    {(char *) "SetMtu", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SetMtu, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SupportsSendFrom", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_SupportsSendFrom, METH_NOARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3SixLowPanNetDevice_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SixLowPanNetDevice__tp_clear(PyNs3SixLowPanNetDevice *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::SixLowPanNetDevice *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3SixLowPanNetDevice__tp_traverse(PyNs3SixLowPanNetDevice *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3SixLowPanNetDevice__tp_dealloc(PyNs3SixLowPanNetDevice *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SixLowPanNetDevice__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SixLowPanNetDevice__tp_richcompare (PyNs3SixLowPanNetDevice *PYBINDGEN_UNUSED(self), PyNs3SixLowPanNetDevice *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SixLowPanNetDevice_Type)) {
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

PyTypeObject PyNs3SixLowPanNetDevice_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "sixlowpan.SixLowPanNetDevice",            /* tp_name */
    sizeof(PyNs3SixLowPanNetDevice),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SixLowPanNetDevice__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3SixLowPanNetDevice__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SixLowPanNetDevice__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SixLowPanNetDevice__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SixLowPanNetDevice_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SixLowPanNetDevice, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SixLowPanNetDevice__tp_init,             /* tp_init */
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
static struct PyModuleDef sixlowpan_moduledef = {
    PyModuleDef_HEAD_INIT,
    "sixlowpan",
    NULL,
    -1,
    sixlowpan_functions,
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


MOD_INIT(sixlowpan)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&sixlowpan_moduledef);
    #else
    m = Py_InitModule3((char *) "sixlowpan", sixlowpan_functions, NULL);
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
    /* Import the 'ns3::ConstantRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ConstantRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ConstantRandomVariable");
    
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
    PyModule_AddObject(m, (char *) "_PyNs3SixLowPanDispatch_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3SixLowPanDispatch_wrapper_registry, NULL));
    /* Register the 'ns3::SixLowPanDispatch' class */
    if (PyType_Ready(&PyNs3SixLowPanDispatch_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanDispatch", (PyObject *) &PyNs3SixLowPanDispatch_Type);
    PyModule_AddObject(m, (char *) "_PyNs3SixLowPanHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3SixLowPanHelper_wrapper_registry, NULL));
    /* Register the 'ns3::SixLowPanHelper' class */
    if (PyType_Ready(&PyNs3SixLowPanHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanHelper", (PyObject *) &PyNs3SixLowPanHelper_Type);
    /* Register the 'ns3::SixLowPanFrag1' class */
    PyNs3SixLowPanFrag1_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanFrag1_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanFrag1", (PyObject *) &PyNs3SixLowPanFrag1_Type);
    /* Register the 'ns3::SixLowPanFragN' class */
    PyNs3SixLowPanFragN_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanFragN_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanFragN", (PyObject *) &PyNs3SixLowPanFragN_Type);
    /* Register the 'ns3::SixLowPanHc1' class */
    PyNs3SixLowPanHc1_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanHc1_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanHc1", (PyObject *) &PyNs3SixLowPanHc1_Type);
    /* Register the 'ns3::SixLowPanIphc' class */
    PyNs3SixLowPanIphc_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanIphc_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanIphc", (PyObject *) &PyNs3SixLowPanIphc_Type);
    /* Register the 'ns3::SixLowPanIpv6' class */
    PyNs3SixLowPanIpv6_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanIpv6_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanIpv6", (PyObject *) &PyNs3SixLowPanIpv6_Type);
    /* Register the 'ns3::SixLowPanNhcExtension' class */
    PyNs3SixLowPanNhcExtension_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanNhcExtension_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanNhcExtension", (PyObject *) &PyNs3SixLowPanNhcExtension_Type);
    /* Register the 'ns3::SixLowPanUdpNhcExtension' class */
    PyNs3SixLowPanUdpNhcExtension_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3SixLowPanUdpNhcExtension_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanUdpNhcExtension", (PyObject *) &PyNs3SixLowPanUdpNhcExtension_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::SixLowPanNetDevice), &PyNs3SixLowPanNetDevice_Type);
    /* Register the 'ns3::SixLowPanNetDevice' class */
    PyNs3SixLowPanNetDevice_Type.tp_base = &PyNs3NetDevice_Type;
    if (PyType_Ready(&PyNs3SixLowPanNetDevice_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SixLowPanNetDevice", (PyObject *) &PyNs3SixLowPanNetDevice_Type);
    {
        PyObject *tmp_value;
         // ns3::SixLowPanDispatch::LOWPAN_NALP
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_NALP);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_NALP", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_NALP_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_NALP_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_NALP_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_IPv6
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_IPv6);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_IPv6", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_HC1
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_HC1);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_HC1", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_BC0
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_BC0);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_BC0", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_IPHC
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_IPHC);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_IPHC", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_IPHC_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_IPHC_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_IPHC_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_MESH
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_MESH);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_MESH", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_MESH_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_MESH_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_MESH_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_FRAG1
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_FRAG1);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_FRAG1", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_FRAG1_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_FRAG1_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_FRAG1_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_FRAGN
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_FRAGN);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_FRAGN", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_FRAGN_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_FRAGN_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_FRAGN_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_UNSUPPORTED
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_UNSUPPORTED);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_UNSUPPORTED", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanDispatch::LOWPAN_NHC
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_NHC);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_NHC", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_NHC_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_NHC_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_NHC_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_UDPNHC
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_UDPNHC);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_UDPNHC", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_UDPNHC_N
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_UDPNHC_N);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_UDPNHC_N", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanDispatch::LOWPAN_NHCUNSUPPORTED
        tmp_value = PyLong_FromLong(ns3::SixLowPanDispatch::LOWPAN_NHCUNSUPPORTED);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanDispatch_Type.tp_dict, "LOWPAN_NHCUNSUPPORTED", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanHc1::HC1_PIII
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_PIII);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_PIII", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanHc1::HC1_PIIC
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_PIIC);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_PIIC", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanHc1::HC1_PCII
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_PCII);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_PCII", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanHc1::HC1_PCIC
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_PCIC);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_PCIC", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanHc1::HC1_NC
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_NC);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_NC", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanHc1::HC1_UDP
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_UDP);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_UDP", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanHc1::HC1_ICMP
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_ICMP);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_ICMP", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanHc1::HC1_TCP
        tmp_value = PyLong_FromLong(ns3::SixLowPanHc1::HC1_TCP);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanHc1_Type.tp_dict, "HC1_TCP", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanIphc::TF_FULL
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::TF_FULL);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "TF_FULL", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::TF_DSCP_ELIDED
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::TF_DSCP_ELIDED);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "TF_DSCP_ELIDED", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::TF_FL_ELIDED
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::TF_FL_ELIDED);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "TF_FL_ELIDED", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::TF_ELIDED
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::TF_ELIDED);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "TF_ELIDED", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanIphc::HLIM_INLINE
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HLIM_INLINE);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HLIM_INLINE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::HLIM_COMPR_1
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HLIM_COMPR_1);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HLIM_COMPR_1", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::HLIM_COMPR_64
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HLIM_COMPR_64);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HLIM_COMPR_64", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::HLIM_COMPR_255
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HLIM_COMPR_255);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HLIM_COMPR_255", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanIphc::HC_INLINE
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HC_INLINE);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HC_INLINE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::HC_COMPR_64
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HC_COMPR_64);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HC_COMPR_64", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::HC_COMPR_16
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HC_COMPR_16);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HC_COMPR_16", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanIphc::HC_COMPR_0
        tmp_value = PyLong_FromLong(ns3::SixLowPanIphc::HC_COMPR_0);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanIphc_Type.tp_dict, "HC_COMPR_0", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanNhcExtension::EID_HOPBYHOP_OPTIONS_H
        tmp_value = PyLong_FromLong(ns3::SixLowPanNhcExtension::EID_HOPBYHOP_OPTIONS_H);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNhcExtension_Type.tp_dict, "EID_HOPBYHOP_OPTIONS_H", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNhcExtension::EID_ROUTING_H
        tmp_value = PyLong_FromLong(ns3::SixLowPanNhcExtension::EID_ROUTING_H);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNhcExtension_Type.tp_dict, "EID_ROUTING_H", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNhcExtension::EID_FRAGMENTATION_H
        tmp_value = PyLong_FromLong(ns3::SixLowPanNhcExtension::EID_FRAGMENTATION_H);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNhcExtension_Type.tp_dict, "EID_FRAGMENTATION_H", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNhcExtension::EID_DESTINATION_OPTIONS_H
        tmp_value = PyLong_FromLong(ns3::SixLowPanNhcExtension::EID_DESTINATION_OPTIONS_H);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNhcExtension_Type.tp_dict, "EID_DESTINATION_OPTIONS_H", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNhcExtension::EID_MOBILITY_H
        tmp_value = PyLong_FromLong(ns3::SixLowPanNhcExtension::EID_MOBILITY_H);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNhcExtension_Type.tp_dict, "EID_MOBILITY_H", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNhcExtension::EID_IPv6_H
        tmp_value = PyLong_FromLong(ns3::SixLowPanNhcExtension::EID_IPv6_H);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNhcExtension_Type.tp_dict, "EID_IPv6_H", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanUdpNhcExtension::PORTS_INLINE
        tmp_value = PyLong_FromLong(ns3::SixLowPanUdpNhcExtension::PORTS_INLINE);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanUdpNhcExtension_Type.tp_dict, "PORTS_INLINE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanUdpNhcExtension::PORTS_ALL_SRC_LAST_DST
        tmp_value = PyLong_FromLong(ns3::SixLowPanUdpNhcExtension::PORTS_ALL_SRC_LAST_DST);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanUdpNhcExtension_Type.tp_dict, "PORTS_ALL_SRC_LAST_DST", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanUdpNhcExtension::PORTS_LAST_SRC_ALL_DST
        tmp_value = PyLong_FromLong(ns3::SixLowPanUdpNhcExtension::PORTS_LAST_SRC_ALL_DST);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanUdpNhcExtension_Type.tp_dict, "PORTS_LAST_SRC_ALL_DST", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanUdpNhcExtension::PORTS_LAST_SRC_LAST_DST
        tmp_value = PyLong_FromLong(ns3::SixLowPanUdpNhcExtension::PORTS_LAST_SRC_LAST_DST);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanUdpNhcExtension_Type.tp_dict, "PORTS_LAST_SRC_LAST_DST", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::SixLowPanNetDevice::DROP_FRAGMENT_TIMEOUT
        tmp_value = PyLong_FromLong(ns3::SixLowPanNetDevice::DROP_FRAGMENT_TIMEOUT);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNetDevice_Type.tp_dict, "DROP_FRAGMENT_TIMEOUT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNetDevice::DROP_FRAGMENT_BUFFER_FULL
        tmp_value = PyLong_FromLong(ns3::SixLowPanNetDevice::DROP_FRAGMENT_BUFFER_FULL);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNetDevice_Type.tp_dict, "DROP_FRAGMENT_BUFFER_FULL", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::SixLowPanNetDevice::DROP_UNKNOWN_EXTENSION
        tmp_value = PyLong_FromLong(ns3::SixLowPanNetDevice::DROP_UNKNOWN_EXTENSION);
        PyDict_SetItemString((PyObject*) PyNs3SixLowPanNetDevice_Type.tp_dict, "DROP_UNKNOWN_EXTENSION", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initsixlowpan_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initsixlowpan_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initsixlowpan_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    return MOD_RETURN(m);
}
