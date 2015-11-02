#include "ns3module.h"
static PyMethodDef energy_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef energy_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy.FatalImpl",
    NULL,
    -1,
    energy_FatalImpl_functions,
};
#endif

static PyObject *
initenergy_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&energy_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "energy.FatalImpl", energy_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef energy_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef energy_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy.Hash.Function",
    NULL,
    -1,
    energy_Hash_Function_functions,
};
#endif

static PyObject *
initenergy_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&energy_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "energy.Hash.Function", energy_Hash_Function_functions, NULL);
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
static PyMethodDef energy_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef energy_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy.Hash",
    NULL,
    -1,
    energy_Hash_functions,
};
#endif

static PyObject *
initenergy_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&energy_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "energy.Hash", energy_Hash_functions, NULL);
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
    submodule = initenergy_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef energy_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef energy_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy.TracedValueCallback",
    NULL,
    -1,
    energy_TracedValueCallback_functions,
};
#endif

static PyObject *
initenergy_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&energy_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "energy.TracedValueCallback", energy_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef energy_internal_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef energy_internal_moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy.internal",
    NULL,
    -1,
    energy_internal_functions,
};
#endif

static PyObject *
initenergy_internal(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&energy_internal_moduledef);
    #else
    m = Py_InitModule3((char *) "energy.internal", energy_internal_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef energy_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3Address_Type;
std::map<void*, PyObject*> *_PyNs3Address_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionList_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionList_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionListItem_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionListItem_wrapper_registry;


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


PyTypeObject *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map;


PyTypeObject *_PyNs3TagBuffer_Type;
std::map<void*, PyObject*> *_PyNs3TagBuffer_wrapper_registry;


PyTypeObject *_PyNs3TimeWithUnit_Type;
std::map<void*, PyObject*> *_PyNs3TimeWithUnit_wrapper_registry;


PyTypeObject *_PyNs3TracedValue__Double_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Double_wrapper_registry;


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


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3Time_Type;
std::map<void*, PyObject*> *_PyNs3Time_wrapper_registry;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


PyTypeObject *_PyNs3TracedValue__Ns3Time_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Ns3Time_wrapper_registry;


PyTypeObject *_PyNs3TriangularRandomVariable_Type;


PyTypeObject *_PyNs3UniformRandomVariable_Type;


PyTypeObject *_PyNs3WeibullRandomVariable_Type;


PyTypeObject *_PyNs3ZetaRandomVariable_Type;


PyTypeObject *_PyNs3ZipfRandomVariable_Type;


PyTypeObject *_PyNs3AttributeAccessor_Type;


PyTypeObject *_PyNs3AttributeChecker_Type;


PyTypeObject *_PyNs3AttributeValue_Type;


PyTypeObject *_PyNs3BooleanChecker_Type;


PyTypeObject *_PyNs3BooleanValue_Type;


PyTypeObject *_PyNs3CallbackChecker_Type;


PyTypeObject *_PyNs3CallbackImplBase_Type;


PyTypeObject *_PyNs3CallbackValue_Type;


PyTypeObject *_PyNs3ConstantRandomVariable_Type;


PyTypeObject *_PyNs3DeterministicRandomVariable_Type;


PyTypeObject *_PyNs3DoubleValue_Type;


PyTypeObject *_PyNs3EmpiricalRandomVariable_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3EnumChecker_Type;


PyTypeObject *_PyNs3EnumValue_Type;


PyTypeObject *_PyNs3ErlangRandomVariable_Type;


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


PyTypeObject *_PyNs3LogNormalRandomVariable_Type;


PyTypeObject *_PyNs3NetDevice_Type;


PyTypeObject *_PyNs3Node_Type;


PyTypeObject *_PyNs3NormalRandomVariable_Type;


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3ParetoRandomVariable_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3UintegerValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


std::map<void*, PyObject*> PyNs3DeviceEnergyModelContainer_wrapper_registry;


static int
_wrap_PyNs3DeviceEnergyModelContainer__tp_init__0(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DeviceEnergyModelContainer *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DeviceEnergyModelContainer_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::DeviceEnergyModelContainer(*((PyNs3DeviceEnergyModelContainer *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3DeviceEnergyModelContainer__tp_init__1(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::DeviceEnergyModelContainer();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3DeviceEnergyModelContainer__tp_init__2(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DeviceEnergyModel *model;
    ns3::DeviceEnergyModel *model_ptr;
    const char *keywords[] = {"model", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DeviceEnergyModel_Type, &model)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    model_ptr = (model ? model->obj : NULL);
    self->obj = new ns3::DeviceEnergyModelContainer(ns3::Ptr< ns3::DeviceEnergyModel  > (model_ptr));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3DeviceEnergyModelContainer__tp_init__3(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *modelName;
    Py_ssize_t modelName_len;
    const char *keywords[] = {"modelName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &modelName, &modelName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::DeviceEnergyModelContainer(std::string(modelName, modelName_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3DeviceEnergyModelContainer__tp_init__4(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DeviceEnergyModelContainer *a;
    PyNs3DeviceEnergyModelContainer *b;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3DeviceEnergyModelContainer_Type, &a, &PyNs3DeviceEnergyModelContainer_Type, &b)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::DeviceEnergyModelContainer(*((PyNs3DeviceEnergyModelContainer *) a)->obj, *((PyNs3DeviceEnergyModelContainer *) b)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3DeviceEnergyModelContainer__tp_init(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3DeviceEnergyModelContainer__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelContainer__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelContainer__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelContainer__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelContainer__tp_init__4(self, args, kwargs, &exceptions[4]);
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
_wrap_PyNs3DeviceEnergyModelContainer_Add__0(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModelContainer *container;
    const char *keywords[] = {"container", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DeviceEnergyModelContainer_Type, &container)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(*((PyNs3DeviceEnergyModelContainer *) container)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DeviceEnergyModelContainer_Add__1(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModel *model;
    ns3::DeviceEnergyModel *model_ptr;
    const char *keywords[] = {"model", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DeviceEnergyModel_Type, &model)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    model_ptr = (model ? model->obj : NULL);
    self->obj->Add(ns3::Ptr< ns3::DeviceEnergyModel  > (model_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DeviceEnergyModelContainer_Add__2(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *modelName;
    Py_ssize_t modelName_len;
    const char *keywords[] = {"modelName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &modelName, &modelName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(std::string(modelName, modelName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3DeviceEnergyModelContainer_Add(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3DeviceEnergyModelContainer_Add__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelContainer_Add__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelContainer_Add__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3DeviceEnergyModelContainer_Clear(PyNs3DeviceEnergyModelContainer *self)
{
    PyObject *py_retval;
    
    self->obj->Clear();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModelContainer_GetN(PyNs3DeviceEnergyModelContainer *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetN();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModelContainer_Get(PyNs3DeviceEnergyModelContainer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::DeviceEnergyModel > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3DeviceEnergyModel *py_DeviceEnergyModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->Get(i);
    if (!(const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3DeviceEnergyModel__PythonHelper).name())
    {
        py_DeviceEnergyModel = reinterpret_cast< PyNs3DeviceEnergyModel* >(reinterpret_cast< PyNs3DeviceEnergyModel__PythonHelper* >(const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval)))->m_pyself);
        py_DeviceEnergyModel->obj = const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval));
        Py_INCREF(py_DeviceEnergyModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_DeviceEnergyModel = NULL;
        } else {
            py_DeviceEnergyModel = (PyNs3DeviceEnergyModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_DeviceEnergyModel);
        }
    
        if (py_DeviceEnergyModel == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval)))), &PyNs3DeviceEnergyModel_Type);
            py_DeviceEnergyModel = PyObject_GC_New(PyNs3DeviceEnergyModel, wrapper_type);
            py_DeviceEnergyModel->inst_dict = NULL;
    
            py_DeviceEnergyModel->inst_dict = NULL;
            py_DeviceEnergyModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval))->Ref();
            py_DeviceEnergyModel->obj = const_cast<ns3::DeviceEnergyModel *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_DeviceEnergyModel->obj] = (PyObject *) py_DeviceEnergyModel;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_DeviceEnergyModel);
    return py_retval;
}


static PyObject*
_wrap_PyNs3DeviceEnergyModelContainer__copy__(PyNs3DeviceEnergyModelContainer *self)
{

    PyNs3DeviceEnergyModelContainer *py_copy;
    py_copy = PyObject_New(PyNs3DeviceEnergyModelContainer, &PyNs3DeviceEnergyModelContainer_Type);
    py_copy->obj = new ns3::DeviceEnergyModelContainer(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3DeviceEnergyModelContainer_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3DeviceEnergyModelContainer_methods[] = {
    {(char *) "Add", (PyCFunction) _wrap_PyNs3DeviceEnergyModelContainer_Add, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Clear", (PyCFunction) _wrap_PyNs3DeviceEnergyModelContainer_Clear, METH_NOARGS, NULL },
    {(char *) "GetN", (PyCFunction) _wrap_PyNs3DeviceEnergyModelContainer_GetN, METH_NOARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3DeviceEnergyModelContainer_Get, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3DeviceEnergyModelContainer__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3DeviceEnergyModelContainer__tp_dealloc(PyNs3DeviceEnergyModelContainer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3DeviceEnergyModelContainer_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3DeviceEnergyModelContainer_wrapper_registry.end()) {
        PyNs3DeviceEnergyModelContainer_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::DeviceEnergyModelContainer *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DeviceEnergyModelContainer__tp_richcompare (PyNs3DeviceEnergyModelContainer *PYBINDGEN_UNUSED(self), PyNs3DeviceEnergyModelContainer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DeviceEnergyModelContainer_Type)) {
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

PyTypeObject PyNs3DeviceEnergyModelContainer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.DeviceEnergyModelContainer",            /* tp_name */
    sizeof(PyNs3DeviceEnergyModelContainer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DeviceEnergyModelContainer__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3DeviceEnergyModelContainer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DeviceEnergyModelContainer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DeviceEnergyModelContainer__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3DeviceEnergyModelHelper_wrapper_registry;

static int
_wrap_PyNs3DeviceEnergyModelHelper__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'DeviceEnergyModelHelper' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}


PyObject *
_wrap_PyNs3DeviceEnergyModelHelper_Set(PyNs3DeviceEnergyModelHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *v;
    const char *keywords[] = {"name", "v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &v)) {
        return NULL;
    }
    self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3DeviceEnergyModelHelper_Install__0(PyNs3DeviceEnergyModelHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NetDevice *device;
    ns3::NetDevice *device_ptr;
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    const char *keywords[] = {"device", "source", NULL};
    PyNs3DeviceEnergyModelContainer *py_DeviceEnergyModelContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3NetDevice_Type, &device, &PyNs3EnergySource_Type, &source)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    device_ptr = (device ? device->obj : NULL);
    source_ptr = (source ? source->obj : NULL);
    ns3::DeviceEnergyModelContainer retval = self->obj->Install(ns3::Ptr< ns3::NetDevice  > (device_ptr), ns3::Ptr< ns3::EnergySource  > (source_ptr));
    py_DeviceEnergyModelContainer = PyObject_New(PyNs3DeviceEnergyModelContainer, &PyNs3DeviceEnergyModelContainer_Type);
    py_DeviceEnergyModelContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DeviceEnergyModelContainer->obj = new ns3::DeviceEnergyModelContainer(retval);
    PyNs3DeviceEnergyModelContainer_wrapper_registry[(void *) py_DeviceEnergyModelContainer->obj] = (PyObject *) py_DeviceEnergyModelContainer;
    py_retval = Py_BuildValue((char *) "N", py_DeviceEnergyModelContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3DeviceEnergyModelHelper_Install__1(PyNs3DeviceEnergyModelHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NetDeviceContainer *deviceContainer;
    PyNs3EnergySourceContainer *sourceContainer;
    const char *keywords[] = {"deviceContainer", "sourceContainer", NULL};
    PyNs3DeviceEnergyModelContainer *py_DeviceEnergyModelContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3NetDeviceContainer_Type, &deviceContainer, &PyNs3EnergySourceContainer_Type, &sourceContainer)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::DeviceEnergyModelContainer retval = self->obj->Install(*((PyNs3NetDeviceContainer *) deviceContainer)->obj, *((PyNs3EnergySourceContainer *) sourceContainer)->obj);
    py_DeviceEnergyModelContainer = PyObject_New(PyNs3DeviceEnergyModelContainer, &PyNs3DeviceEnergyModelContainer_Type);
    py_DeviceEnergyModelContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DeviceEnergyModelContainer->obj = new ns3::DeviceEnergyModelContainer(retval);
    PyNs3DeviceEnergyModelContainer_wrapper_registry[(void *) py_DeviceEnergyModelContainer->obj] = (PyObject *) py_DeviceEnergyModelContainer;
    py_retval = Py_BuildValue((char *) "N", py_DeviceEnergyModelContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3DeviceEnergyModelHelper_Install(PyNs3DeviceEnergyModelHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3DeviceEnergyModelHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModelHelper_Install__1(self, args, kwargs, &exceptions[1]);
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

static PyMethodDef PyNs3DeviceEnergyModelHelper_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3DeviceEnergyModelHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3DeviceEnergyModelHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DeviceEnergyModelHelper__tp_clear(PyNs3DeviceEnergyModelHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::DeviceEnergyModelHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3DeviceEnergyModelHelper__tp_traverse(PyNs3DeviceEnergyModelHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3DeviceEnergyModelHelper__tp_dealloc(PyNs3DeviceEnergyModelHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3DeviceEnergyModelHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3DeviceEnergyModelHelper_wrapper_registry.end()) {
        PyNs3DeviceEnergyModelHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DeviceEnergyModelHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DeviceEnergyModelHelper__tp_richcompare (PyNs3DeviceEnergyModelHelper *PYBINDGEN_UNUSED(self), PyNs3DeviceEnergyModelHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DeviceEnergyModelHelper_Type)) {
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

PyTypeObject PyNs3DeviceEnergyModelHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.DeviceEnergyModelHelper",            /* tp_name */
    sizeof(PyNs3DeviceEnergyModelHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DeviceEnergyModelHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DeviceEnergyModelHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DeviceEnergyModelHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DeviceEnergyModelHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DeviceEnergyModelHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DeviceEnergyModelHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DeviceEnergyModelHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3EnergyHarvesterHelper_wrapper_registry;

static int
_wrap_PyNs3EnergyHarvesterHelper__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'EnergyHarvesterHelper' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}


PyObject *
_wrap_PyNs3EnergyHarvesterHelper_Set(PyNs3EnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *v;
    const char *keywords[] = {"name", "v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &v)) {
        return NULL;
    }
    self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3EnergyHarvesterHelper_Install__0(PyNs3EnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    const char *keywords[] = {"source", NULL};
    PyNs3EnergyHarvesterContainer *py_EnergyHarvesterContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &source)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    source_ptr = (source ? source->obj : NULL);
    ns3::EnergyHarvesterContainer retval = self->obj->Install(ns3::Ptr< ns3::EnergySource  > (source_ptr));
    py_EnergyHarvesterContainer = PyObject_GC_New(PyNs3EnergyHarvesterContainer, &PyNs3EnergyHarvesterContainer_Type);
    py_EnergyHarvesterContainer->inst_dict = NULL;
    
    py_EnergyHarvesterContainer->inst_dict = NULL;
    py_EnergyHarvesterContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergyHarvesterContainer->obj = new ns3::EnergyHarvesterContainer(retval);
    py_EnergyHarvesterContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergyHarvesterContainer->obj] = (PyObject *) py_EnergyHarvesterContainer;
    ns3::CompleteConstruct(py_EnergyHarvesterContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergyHarvesterContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergyHarvesterHelper_Install__1(PyNs3EnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3EnergySourceContainer *sourceContainer;
    const char *keywords[] = {"sourceContainer", NULL};
    PyNs3EnergyHarvesterContainer *py_EnergyHarvesterContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySourceContainer_Type, &sourceContainer)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::EnergyHarvesterContainer retval = self->obj->Install(*((PyNs3EnergySourceContainer *) sourceContainer)->obj);
    py_EnergyHarvesterContainer = PyObject_GC_New(PyNs3EnergyHarvesterContainer, &PyNs3EnergyHarvesterContainer_Type);
    py_EnergyHarvesterContainer->inst_dict = NULL;
    
    py_EnergyHarvesterContainer->inst_dict = NULL;
    py_EnergyHarvesterContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergyHarvesterContainer->obj = new ns3::EnergyHarvesterContainer(retval);
    py_EnergyHarvesterContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergyHarvesterContainer->obj] = (PyObject *) py_EnergyHarvesterContainer;
    ns3::CompleteConstruct(py_EnergyHarvesterContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergyHarvesterContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergyHarvesterHelper_Install__2(PyNs3EnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *sourceName;
    Py_ssize_t sourceName_len;
    const char *keywords[] = {"sourceName", NULL};
    PyNs3EnergyHarvesterContainer *py_EnergyHarvesterContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &sourceName, &sourceName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::EnergyHarvesterContainer retval = self->obj->Install(std::string(sourceName, sourceName_len));
    py_EnergyHarvesterContainer = PyObject_GC_New(PyNs3EnergyHarvesterContainer, &PyNs3EnergyHarvesterContainer_Type);
    py_EnergyHarvesterContainer->inst_dict = NULL;
    
    py_EnergyHarvesterContainer->inst_dict = NULL;
    py_EnergyHarvesterContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergyHarvesterContainer->obj = new ns3::EnergyHarvesterContainer(retval);
    py_EnergyHarvesterContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergyHarvesterContainer->obj] = (PyObject *) py_EnergyHarvesterContainer;
    ns3::CompleteConstruct(py_EnergyHarvesterContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergyHarvesterContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3EnergyHarvesterHelper_Install(PyNs3EnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3EnergyHarvesterHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterHelper_Install__2(self, args, kwargs, &exceptions[2]);
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

static PyMethodDef PyNs3EnergyHarvesterHelper_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3EnergyHarvesterHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3EnergyHarvesterHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3EnergyHarvesterHelper__tp_clear(PyNs3EnergyHarvesterHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::EnergyHarvesterHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3EnergyHarvesterHelper__tp_traverse(PyNs3EnergyHarvesterHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3EnergyHarvesterHelper__tp_dealloc(PyNs3EnergyHarvesterHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3EnergyHarvesterHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3EnergyHarvesterHelper_wrapper_registry.end()) {
        PyNs3EnergyHarvesterHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3EnergyHarvesterHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3EnergyHarvesterHelper__tp_richcompare (PyNs3EnergyHarvesterHelper *PYBINDGEN_UNUSED(self), PyNs3EnergyHarvesterHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3EnergyHarvesterHelper_Type)) {
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

PyTypeObject PyNs3EnergyHarvesterHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.EnergyHarvesterHelper",            /* tp_name */
    sizeof(PyNs3EnergyHarvesterHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3EnergyHarvesterHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3EnergyHarvesterHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3EnergyHarvesterHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3EnergyHarvesterHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3EnergyHarvesterHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3EnergyHarvesterHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3EnergyHarvesterHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3EnergySourceHelper_wrapper_registry;

static int
_wrap_PyNs3EnergySourceHelper__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'EnergySourceHelper' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}


PyObject *
_wrap_PyNs3EnergySourceHelper_InstallAll(PyNs3EnergySourceHelper *self)
{
    PyObject *py_retval;
    PyNs3EnergySourceContainer *py_EnergySourceContainer;
    
    ns3::EnergySourceContainer retval = self->obj->InstallAll();
    py_EnergySourceContainer = PyObject_GC_New(PyNs3EnergySourceContainer, &PyNs3EnergySourceContainer_Type);
    py_EnergySourceContainer->inst_dict = NULL;
    
    py_EnergySourceContainer->inst_dict = NULL;
    py_EnergySourceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergySourceContainer->obj = new ns3::EnergySourceContainer(retval);
    py_EnergySourceContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySourceContainer->obj] = (PyObject *) py_EnergySourceContainer;
    ns3::CompleteConstruct(py_EnergySourceContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergySourceContainer);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySourceHelper_Set(PyNs3EnergySourceHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *v;
    const char *keywords[] = {"name", "v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &v)) {
        return NULL;
    }
    self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3EnergySourceHelper_Install__0(PyNs3EnergySourceHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3EnergySourceContainer *py_EnergySourceContainer;
    
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
    ns3::EnergySourceContainer retval = self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    py_EnergySourceContainer = PyObject_GC_New(PyNs3EnergySourceContainer, &PyNs3EnergySourceContainer_Type);
    py_EnergySourceContainer->inst_dict = NULL;
    
    py_EnergySourceContainer->inst_dict = NULL;
    py_EnergySourceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergySourceContainer->obj = new ns3::EnergySourceContainer(retval);
    py_EnergySourceContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySourceContainer->obj] = (PyObject *) py_EnergySourceContainer;
    ns3::CompleteConstruct(py_EnergySourceContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergySourceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergySourceHelper_Install__1(PyNs3EnergySourceHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *c;
    const char *keywords[] = {"c", NULL};
    PyNs3EnergySourceContainer *py_EnergySourceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &c)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::EnergySourceContainer retval = self->obj->Install(*((PyNs3NodeContainer *) c)->obj);
    py_EnergySourceContainer = PyObject_GC_New(PyNs3EnergySourceContainer, &PyNs3EnergySourceContainer_Type);
    py_EnergySourceContainer->inst_dict = NULL;
    
    py_EnergySourceContainer->inst_dict = NULL;
    py_EnergySourceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergySourceContainer->obj = new ns3::EnergySourceContainer(retval);
    py_EnergySourceContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySourceContainer->obj] = (PyObject *) py_EnergySourceContainer;
    ns3::CompleteConstruct(py_EnergySourceContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergySourceContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergySourceHelper_Install__2(PyNs3EnergySourceHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    PyNs3EnergySourceContainer *py_EnergySourceContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::EnergySourceContainer retval = self->obj->Install(std::string(nodeName, nodeName_len));
    py_EnergySourceContainer = PyObject_GC_New(PyNs3EnergySourceContainer, &PyNs3EnergySourceContainer_Type);
    py_EnergySourceContainer->inst_dict = NULL;
    
    py_EnergySourceContainer->inst_dict = NULL;
    py_EnergySourceContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_EnergySourceContainer->obj = new ns3::EnergySourceContainer(retval);
    py_EnergySourceContainer->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySourceContainer->obj] = (PyObject *) py_EnergySourceContainer;
    ns3::CompleteConstruct(py_EnergySourceContainer->obj);
    py_retval = Py_BuildValue((char *) "N", py_EnergySourceContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3EnergySourceHelper_Install(PyNs3EnergySourceHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3EnergySourceHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceHelper_Install__2(self, args, kwargs, &exceptions[2]);
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

static PyMethodDef PyNs3EnergySourceHelper_methods[] = {
    {(char *) "InstallAll", (PyCFunction) _wrap_PyNs3EnergySourceHelper_InstallAll, METH_NOARGS, NULL },
    {(char *) "Set", (PyCFunction) _wrap_PyNs3EnergySourceHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3EnergySourceHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3EnergySourceHelper__tp_clear(PyNs3EnergySourceHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::EnergySourceHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3EnergySourceHelper__tp_traverse(PyNs3EnergySourceHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3EnergySourceHelper__tp_dealloc(PyNs3EnergySourceHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3EnergySourceHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3EnergySourceHelper_wrapper_registry.end()) {
        PyNs3EnergySourceHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3EnergySourceHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3EnergySourceHelper__tp_richcompare (PyNs3EnergySourceHelper *PYBINDGEN_UNUSED(self), PyNs3EnergySourceHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3EnergySourceHelper_Type)) {
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

PyTypeObject PyNs3EnergySourceHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.EnergySourceHelper",            /* tp_name */
    sizeof(PyNs3EnergySourceHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3EnergySourceHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3EnergySourceHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3EnergySourceHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3EnergySourceHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3EnergySourceHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3EnergySourceHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3EnergySourceHelper__tp_init,             /* tp_init */
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





ns3::Ptr< ns3::EnergySource >
PyNs3RvBatteryModelHelper__PythonHelper::DoInstall(ns3::Ptr< ns3::Node > node) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModelHelper *self_obj_before;
    PyObject *py_retval;
    ns3::Ptr< ns3::EnergySource > retval;
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3EnergySource *tmp_EnergySource;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInstall"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModelHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModelHelper* >(m_pyself)->obj = const_cast< ns3::RvBatteryModelHelper* >((const ns3::RvBatteryModelHelper*) this);
    if (typeid(*(const_cast<ns3::Node *> (ns3::PeekPointer (node)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = (PyNs3Node*) (((PyNs3Node__PythonHelper*) const_cast<ns3::Node *> (ns3::PeekPointer (node)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (node));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (node)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::Node *> (ns3::PeekPointer (node))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (node))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (node));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInstall", (char *) "N", py_Node);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModelHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3EnergySource_Type, &tmp_EnergySource)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModelHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    // dangerous!
    retval = ns3::Ptr< ns3::EnergySource  > (tmp_EnergySource->obj);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModelHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}


static int
_wrap_PyNs3RvBatteryModelHelper__tp_init__0(PyNs3RvBatteryModelHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RvBatteryModelHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RvBatteryModelHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RvBatteryModelHelper_Type)
    {
        self->obj = new PyNs3RvBatteryModelHelper__PythonHelper(*((PyNs3RvBatteryModelHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RvBatteryModelHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RvBatteryModelHelper(*((PyNs3RvBatteryModelHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3RvBatteryModelHelper__tp_init__1(PyNs3RvBatteryModelHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RvBatteryModelHelper_Type)
    {
        self->obj = new PyNs3RvBatteryModelHelper__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RvBatteryModelHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RvBatteryModelHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3RvBatteryModelHelper__tp_init(PyNs3RvBatteryModelHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RvBatteryModelHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RvBatteryModelHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RvBatteryModelHelper_Set(PyNs3RvBatteryModelHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *v;
    PyNs3RvBatteryModelHelper__PythonHelper *helper_class = dynamic_cast<PyNs3RvBatteryModelHelper__PythonHelper*> (self->obj);
    const char *keywords[] = {"name", "v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &v)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj)) : (self->obj->ns3::RvBatteryModelHelper::Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3RvBatteryModelHelper__copy__(PyNs3RvBatteryModelHelper *self)
{

    PyNs3RvBatteryModelHelper *py_copy;
    py_copy = PyObject_GC_New(PyNs3RvBatteryModelHelper, &PyNs3RvBatteryModelHelper_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::RvBatteryModelHelper(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3EnergySourceHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RvBatteryModelHelper_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3RvBatteryModelHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RvBatteryModelHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RvBatteryModelHelper__tp_clear(PyNs3RvBatteryModelHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::RvBatteryModelHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3RvBatteryModelHelper__tp_traverse(PyNs3RvBatteryModelHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RvBatteryModelHelper__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RvBatteryModelHelper__tp_dealloc(PyNs3RvBatteryModelHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3EnergySourceHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3EnergySourceHelper_wrapper_registry.end()) {
        PyNs3EnergySourceHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RvBatteryModelHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RvBatteryModelHelper__tp_richcompare (PyNs3RvBatteryModelHelper *PYBINDGEN_UNUSED(self), PyNs3RvBatteryModelHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RvBatteryModelHelper_Type)) {
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

PyTypeObject PyNs3RvBatteryModelHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.RvBatteryModelHelper",            /* tp_name */
    sizeof(PyNs3RvBatteryModelHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RvBatteryModelHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RvBatteryModelHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RvBatteryModelHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RvBatteryModelHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RvBatteryModelHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RvBatteryModelHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RvBatteryModelHelper__tp_init,             /* tp_init */
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





ns3::Ptr< ns3::EnergyHarvester >
PyNs3BasicEnergyHarvesterHelper__PythonHelper::DoInstall(ns3::Ptr< ns3::EnergySource > source) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergyHarvesterHelper *self_obj_before;
    PyObject *py_retval;
    ns3::Ptr< ns3::EnergyHarvester > retval;
    PyNs3EnergySource *py_EnergySource;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3EnergyHarvester *tmp_EnergyHarvester;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInstall"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergyHarvesterHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergyHarvesterHelper* >(m_pyself)->obj = const_cast< ns3::BasicEnergyHarvesterHelper* >((const ns3::BasicEnergyHarvesterHelper*) this);
    if (typeid(*(const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)))).name() == typeid(PyNs3EnergySource__PythonHelper).name())
    {
        py_EnergySource = (PyNs3EnergySource*) (((PyNs3EnergySource__PythonHelper*) const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)))->m_pyself);
        py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (source));
        Py_INCREF(py_EnergySource);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_EnergySource = NULL;
        } else {
            py_EnergySource = (PyNs3EnergySource *) wrapper_lookup_iter->second;
            Py_INCREF(py_EnergySource);
        }
    
        if (py_EnergySource == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::EnergySource *> (ns3::PeekPointer (source))), &PyNs3EnergySource_Type);
            py_EnergySource = PyObject_GC_New(PyNs3EnergySource, wrapper_type);
            py_EnergySource->inst_dict = NULL;
    
            py_EnergySource->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::EnergySource *> (ns3::PeekPointer (source))->Ref();
            py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (source));
            PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySource->obj] = (PyObject *) py_EnergySource;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInstall", (char *) "N", py_EnergySource);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergyHarvesterHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3EnergyHarvester_Type, &tmp_EnergyHarvester)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergyHarvesterHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    // dangerous!
    retval = ns3::Ptr< ns3::EnergyHarvester  > (tmp_EnergyHarvester->obj);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergyHarvesterHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}


static int
_wrap_PyNs3BasicEnergyHarvesterHelper__tp_init__0(PyNs3BasicEnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BasicEnergyHarvesterHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BasicEnergyHarvesterHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BasicEnergyHarvesterHelper_Type)
    {
        self->obj = new PyNs3BasicEnergyHarvesterHelper__PythonHelper(*((PyNs3BasicEnergyHarvesterHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergyHarvesterHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergyHarvesterHelper(*((PyNs3BasicEnergyHarvesterHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3BasicEnergyHarvesterHelper__tp_init__1(PyNs3BasicEnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3BasicEnergyHarvesterHelper_Type)
    {
        self->obj = new PyNs3BasicEnergyHarvesterHelper__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergyHarvesterHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergyHarvesterHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3BasicEnergyHarvesterHelper__tp_init(PyNs3BasicEnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3BasicEnergyHarvesterHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BasicEnergyHarvesterHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3BasicEnergyHarvesterHelper_Set(PyNs3BasicEnergyHarvesterHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *v;
    PyNs3BasicEnergyHarvesterHelper__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergyHarvesterHelper__PythonHelper*> (self->obj);
    const char *keywords[] = {"name", "v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &v)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj)) : (self->obj->ns3::BasicEnergyHarvesterHelper::Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3BasicEnergyHarvesterHelper__copy__(PyNs3BasicEnergyHarvesterHelper *self)
{

    PyNs3BasicEnergyHarvesterHelper *py_copy;
    py_copy = PyObject_GC_New(PyNs3BasicEnergyHarvesterHelper, &PyNs3BasicEnergyHarvesterHelper_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::BasicEnergyHarvesterHelper(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3EnergyHarvesterHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BasicEnergyHarvesterHelper_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3BasicEnergyHarvesterHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BasicEnergyHarvesterHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3BasicEnergyHarvesterHelper__tp_clear(PyNs3BasicEnergyHarvesterHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::BasicEnergyHarvesterHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3BasicEnergyHarvesterHelper__tp_traverse(PyNs3BasicEnergyHarvesterHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3BasicEnergyHarvesterHelper__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3BasicEnergyHarvesterHelper__tp_dealloc(PyNs3BasicEnergyHarvesterHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3EnergyHarvesterHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3EnergyHarvesterHelper_wrapper_registry.end()) {
        PyNs3EnergyHarvesterHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3BasicEnergyHarvesterHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BasicEnergyHarvesterHelper__tp_richcompare (PyNs3BasicEnergyHarvesterHelper *PYBINDGEN_UNUSED(self), PyNs3BasicEnergyHarvesterHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BasicEnergyHarvesterHelper_Type)) {
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

PyTypeObject PyNs3BasicEnergyHarvesterHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.BasicEnergyHarvesterHelper",            /* tp_name */
    sizeof(PyNs3BasicEnergyHarvesterHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BasicEnergyHarvesterHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3BasicEnergyHarvesterHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3BasicEnergyHarvesterHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BasicEnergyHarvesterHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BasicEnergyHarvesterHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3BasicEnergyHarvesterHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BasicEnergyHarvesterHelper__tp_init,             /* tp_init */
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





ns3::Ptr< ns3::EnergySource >
PyNs3BasicEnergySourceHelper__PythonHelper::DoInstall(ns3::Ptr< ns3::Node > node) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySourceHelper *self_obj_before;
    PyObject *py_retval;
    ns3::Ptr< ns3::EnergySource > retval;
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3EnergySource *tmp_EnergySource;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInstall"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySourceHelper* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySourceHelper* >(m_pyself)->obj = const_cast< ns3::BasicEnergySourceHelper* >((const ns3::BasicEnergySourceHelper*) this);
    if (typeid(*(const_cast<ns3::Node *> (ns3::PeekPointer (node)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = (PyNs3Node*) (((PyNs3Node__PythonHelper*) const_cast<ns3::Node *> (ns3::PeekPointer (node)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (node));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (node)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::Node *> (ns3::PeekPointer (node))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (node))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (node));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInstall", (char *) "N", py_Node);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySourceHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3EnergySource_Type, &tmp_EnergySource)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySourceHelper* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    // dangerous!
    retval = ns3::Ptr< ns3::EnergySource  > (tmp_EnergySource->obj);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySourceHelper* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}


static int
_wrap_PyNs3BasicEnergySourceHelper__tp_init__0(PyNs3BasicEnergySourceHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BasicEnergySourceHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BasicEnergySourceHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BasicEnergySourceHelper_Type)
    {
        self->obj = new PyNs3BasicEnergySourceHelper__PythonHelper(*((PyNs3BasicEnergySourceHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergySourceHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergySourceHelper(*((PyNs3BasicEnergySourceHelper *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3BasicEnergySourceHelper__tp_init__1(PyNs3BasicEnergySourceHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3BasicEnergySourceHelper_Type)
    {
        self->obj = new PyNs3BasicEnergySourceHelper__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergySourceHelper__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergySourceHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3BasicEnergySourceHelper__tp_init(PyNs3BasicEnergySourceHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3BasicEnergySourceHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BasicEnergySourceHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3BasicEnergySourceHelper_Set(PyNs3BasicEnergySourceHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *v;
    PyNs3BasicEnergySourceHelper__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergySourceHelper__PythonHelper*> (self->obj);
    const char *keywords[] = {"name", "v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &v)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj)) : (self->obj->ns3::BasicEnergySourceHelper::Set(std::string(name, name_len), *((PyNs3AttributeValue *) v)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3BasicEnergySourceHelper__copy__(PyNs3BasicEnergySourceHelper *self)
{

    PyNs3BasicEnergySourceHelper *py_copy;
    py_copy = PyObject_GC_New(PyNs3BasicEnergySourceHelper, &PyNs3BasicEnergySourceHelper_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::BasicEnergySourceHelper(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3EnergySourceHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BasicEnergySourceHelper_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3BasicEnergySourceHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BasicEnergySourceHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3BasicEnergySourceHelper__tp_clear(PyNs3BasicEnergySourceHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::BasicEnergySourceHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3BasicEnergySourceHelper__tp_traverse(PyNs3BasicEnergySourceHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3BasicEnergySourceHelper__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3BasicEnergySourceHelper__tp_dealloc(PyNs3BasicEnergySourceHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3EnergySourceHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3EnergySourceHelper_wrapper_registry.end()) {
        PyNs3EnergySourceHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3BasicEnergySourceHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BasicEnergySourceHelper__tp_richcompare (PyNs3BasicEnergySourceHelper *PYBINDGEN_UNUSED(self), PyNs3BasicEnergySourceHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BasicEnergySourceHelper_Type)) {
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

PyTypeObject PyNs3BasicEnergySourceHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.BasicEnergySourceHelper",            /* tp_name */
    sizeof(PyNs3BasicEnergySourceHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BasicEnergySourceHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3BasicEnergySourceHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3BasicEnergySourceHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BasicEnergySourceHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BasicEnergySourceHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3BasicEnergySourceHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BasicEnergySourceHelper__tp_init,             /* tp_init */
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
PyNs3DeviceEnergyModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3DeviceEnergyModel__PythonHelper* >(self->obj);
    
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
PyNs3DeviceEnergyModel__PythonHelper::_wrap_DoInitialize(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3DeviceEnergyModel__PythonHelper* >(self->obj);
    
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
PyNs3DeviceEnergyModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3DeviceEnergyModel__PythonHelper* >(self->obj);
    
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
PyNs3DeviceEnergyModel__PythonHelper::_wrap_DoDispose(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3DeviceEnergyModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3DeviceEnergyModel__PythonHelper::ChangeState(int newState)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ChangeState"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = (ns3::DeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ChangeState", (char *) "i", newState);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

double
PyNs3DeviceEnergyModel__PythonHelper::GetTotalEnergyConsumption() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetTotalEnergyConsumption"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = const_cast< ns3::DeviceEnergyModel* >((const ns3::DeviceEnergyModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetTotalEnergyConsumption", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3DeviceEnergyModel__PythonHelper::HandleEnergyDepletion()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "HandleEnergyDepletion"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = (ns3::DeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "HandleEnergyDepletion", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3DeviceEnergyModel__PythonHelper::HandleEnergyRecharged()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "HandleEnergyRecharged"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = (ns3::DeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "HandleEnergyRecharged", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3DeviceEnergyModel__PythonHelper::SetEnergySource(ns3::Ptr< ns3::EnergySource > source)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    PyNs3EnergySource *py_EnergySource;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "SetEnergySource"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = (ns3::DeviceEnergyModel*) this;
    if (typeid(*(const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)))).name() == typeid(PyNs3EnergySource__PythonHelper).name())
    {
        py_EnergySource = (PyNs3EnergySource*) (((PyNs3EnergySource__PythonHelper*) const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)))->m_pyself);
        py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (source));
        Py_INCREF(py_EnergySource);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_EnergySource = NULL;
        } else {
            py_EnergySource = (PyNs3EnergySource *) wrapper_lookup_iter->second;
            Py_INCREF(py_EnergySource);
        }
    
        if (py_EnergySource == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::EnergySource *> (ns3::PeekPointer (source))), &PyNs3EnergySource_Type);
            py_EnergySource = PyObject_GC_New(PyNs3EnergySource, wrapper_type);
            py_EnergySource->inst_dict = NULL;
    
            py_EnergySource->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::EnergySource *> (ns3::PeekPointer (source))->Ref();
            py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (source));
            PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySource->obj] = (PyObject *) py_EnergySource;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "SetEnergySource", (char *) "N", py_EnergySource);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

double
PyNs3DeviceEnergyModel__PythonHelper::DoGetCurrentA() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetCurrentA"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = const_cast< ns3::DeviceEnergyModel* >((const ns3::DeviceEnergyModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetCurrentA", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3DeviceEnergyModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3DeviceEnergyModel__PythonHelper::DoDispose()
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
PyNs3DeviceEnergyModel__PythonHelper::DoInitialize()
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
PyNs3DeviceEnergyModel__PythonHelper::NotifyNewAggregate()
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
PyNs3DeviceEnergyModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3DeviceEnergyModel__tp_init__0(PyNs3DeviceEnergyModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DeviceEnergyModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DeviceEnergyModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3DeviceEnergyModel_Type)
    {
        self->obj = new PyNs3DeviceEnergyModel__PythonHelper(*((PyNs3DeviceEnergyModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DeviceEnergyModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'DeviceEnergyModel' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3DeviceEnergyModel__tp_init__1(PyNs3DeviceEnergyModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3DeviceEnergyModel_Type)
    {
        self->obj = new PyNs3DeviceEnergyModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DeviceEnergyModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'DeviceEnergyModel' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3DeviceEnergyModel__tp_init(PyNs3DeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3DeviceEnergyModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DeviceEnergyModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3DeviceEnergyModel_HandleEnergyRecharged(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    
    self->obj->HandleEnergyRecharged();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModel_GetCurrentA(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetCurrentA();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModel_SetEnergySource(PyNs3DeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    const char *keywords[] = {"source", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &source)) {
        return NULL;
    }
    source_ptr = (source ? source->obj : NULL);
    self->obj->SetEnergySource(ns3::Ptr< ns3::EnergySource  > (source_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::DeviceEnergyModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModel_GetTotalEnergyConsumption(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetTotalEnergyConsumption();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModel_HandleEnergyDepletion(PyNs3DeviceEnergyModel *self)
{
    PyObject *py_retval;
    
    self->obj->HandleEnergyDepletion();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DeviceEnergyModel_ChangeState(PyNs3DeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int newState;
    const char *keywords[] = {"newState", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &newState)) {
        return NULL;
    }
    self->obj->ChangeState(newState);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3DeviceEnergyModel_methods[] = {
    {(char *) "HandleEnergyRecharged", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_HandleEnergyRecharged, METH_NOARGS, NULL },
    {(char *) "GetCurrentA", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_GetCurrentA, METH_NOARGS, NULL },
    {(char *) "SetEnergySource", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_SetEnergySource, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetTotalEnergyConsumption", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_GetTotalEnergyConsumption, METH_NOARGS, NULL },
    {(char *) "HandleEnergyDepletion", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_HandleEnergyDepletion, METH_NOARGS, NULL },
    {(char *) "ChangeState", (PyCFunction) _wrap_PyNs3DeviceEnergyModel_ChangeState, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3DeviceEnergyModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3DeviceEnergyModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3DeviceEnergyModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3DeviceEnergyModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DeviceEnergyModel__tp_clear(PyNs3DeviceEnergyModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::DeviceEnergyModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3DeviceEnergyModel__tp_traverse(PyNs3DeviceEnergyModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3DeviceEnergyModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3DeviceEnergyModel__tp_dealloc(PyNs3DeviceEnergyModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DeviceEnergyModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DeviceEnergyModel__tp_richcompare (PyNs3DeviceEnergyModel *PYBINDGEN_UNUSED(self), PyNs3DeviceEnergyModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DeviceEnergyModel_Type)) {
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

PyTypeObject PyNs3DeviceEnergyModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.DeviceEnergyModel",            /* tp_name */
    sizeof(PyNs3DeviceEnergyModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DeviceEnergyModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DeviceEnergyModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DeviceEnergyModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DeviceEnergyModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DeviceEnergyModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DeviceEnergyModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DeviceEnergyModel__tp_init,             /* tp_init */
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
PyNs3EnergyHarvester__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3EnergyHarvester *self)
{
    PyObject *py_retval;
    PyNs3EnergyHarvester__PythonHelper *helper = dynamic_cast< PyNs3EnergyHarvester__PythonHelper* >(self->obj);
    
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
PyNs3EnergyHarvester__PythonHelper::_wrap_DoInitialize(PyNs3EnergyHarvester *self)
{
    PyObject *py_retval;
    PyNs3EnergyHarvester__PythonHelper *helper = dynamic_cast< PyNs3EnergyHarvester__PythonHelper* >(self->obj);
    
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
PyNs3EnergyHarvester__PythonHelper::_wrap_NotifyNewAggregate(PyNs3EnergyHarvester *self)
{
    PyObject *py_retval;
    PyNs3EnergyHarvester__PythonHelper *helper = dynamic_cast< PyNs3EnergyHarvester__PythonHelper* >(self->obj);
    
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
PyNs3EnergyHarvester__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergyHarvester *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = (ns3::EnergyHarvester*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

double
PyNs3EnergyHarvester__PythonHelper::DoGetPower() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergyHarvester *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = const_cast< ns3::EnergyHarvester* >((const ns3::EnergyHarvester*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPower", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergyHarvester* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3EnergyHarvester__PythonHelper::GetInstanceTypeId() const
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
PyNs3EnergyHarvester__PythonHelper::DoInitialize()
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
PyNs3EnergyHarvester__PythonHelper::NotifyNewAggregate()
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
PyNs3EnergyHarvester__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3EnergyHarvester__tp_init__0(PyNs3EnergyHarvester *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergyHarvester *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergyHarvester_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergyHarvester_Type)
    {
        self->obj = new PyNs3EnergyHarvester__PythonHelper(*((PyNs3EnergyHarvester *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvester__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvester(*((PyNs3EnergyHarvester *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergyHarvester__tp_init__1(PyNs3EnergyHarvester *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3EnergyHarvester_Type)
    {
        self->obj = new PyNs3EnergyHarvester__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvester__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvester();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3EnergyHarvester__tp_init(PyNs3EnergyHarvester *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3EnergyHarvester__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvester__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3EnergyHarvester_SetNode(PyNs3EnergyHarvester *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3EnergyHarvester_SetEnergySource(PyNs3EnergyHarvester *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    const char *keywords[] = {"source", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &source)) {
        return NULL;
    }
    source_ptr = (source ? source->obj : NULL);
    self->obj->SetEnergySource(ns3::Ptr< ns3::EnergySource  > (source_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergyHarvester_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::EnergyHarvester::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergyHarvester_GetEnergySource(PyNs3EnergyHarvester *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::EnergySource > retval;
    PyNs3EnergySource *py_EnergySource;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetEnergySource();
    if (!(const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3EnergySource__PythonHelper).name())
    {
        py_EnergySource = reinterpret_cast< PyNs3EnergySource* >(reinterpret_cast< PyNs3EnergySource__PythonHelper* >(const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))->m_pyself);
        py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval));
        Py_INCREF(py_EnergySource);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_EnergySource = NULL;
        } else {
            py_EnergySource = (PyNs3EnergySource *) wrapper_lookup_iter->second;
            Py_INCREF(py_EnergySource);
        }
    
        if (py_EnergySource == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))), &PyNs3EnergySource_Type);
            py_EnergySource = PyObject_GC_New(PyNs3EnergySource, wrapper_type);
            py_EnergySource->inst_dict = NULL;
    
            py_EnergySource->inst_dict = NULL;
            py_EnergySource->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval))->Ref();
            py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySource->obj] = (PyObject *) py_EnergySource;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_EnergySource);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergyHarvester_GetNode(PyNs3EnergyHarvester *self)
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
_wrap_PyNs3EnergyHarvester_GetPower(PyNs3EnergyHarvester *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetPower();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3EnergyHarvester__copy__(PyNs3EnergyHarvester *self)
{

    PyNs3EnergyHarvester *py_copy;
    py_copy = PyObject_GC_New(PyNs3EnergyHarvester, &PyNs3EnergyHarvester_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::EnergyHarvester(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3EnergyHarvester_methods[] = {
    {(char *) "SetNode", (PyCFunction) _wrap_PyNs3EnergyHarvester_SetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetEnergySource", (PyCFunction) _wrap_PyNs3EnergyHarvester_SetEnergySource, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3EnergyHarvester_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetEnergySource", (PyCFunction) _wrap_PyNs3EnergyHarvester_GetEnergySource, METH_NOARGS, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3EnergyHarvester_GetNode, METH_NOARGS, NULL },
    {(char *) "GetPower", (PyCFunction) _wrap_PyNs3EnergyHarvester_GetPower, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3EnergyHarvester__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3EnergyHarvester__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3EnergyHarvester__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3EnergyHarvester__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3EnergyHarvester__tp_clear(PyNs3EnergyHarvester *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::EnergyHarvester *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3EnergyHarvester__tp_traverse(PyNs3EnergyHarvester *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3EnergyHarvester__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3EnergyHarvester__tp_dealloc(PyNs3EnergyHarvester *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3EnergyHarvester__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3EnergyHarvester__tp_richcompare (PyNs3EnergyHarvester *PYBINDGEN_UNUSED(self), PyNs3EnergyHarvester *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3EnergyHarvester_Type)) {
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

PyTypeObject PyNs3EnergyHarvester_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.EnergyHarvester",            /* tp_name */
    sizeof(PyNs3EnergyHarvester),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3EnergyHarvester__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3EnergyHarvester__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3EnergyHarvester__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3EnergyHarvester__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3EnergyHarvester_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3EnergyHarvester, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3EnergyHarvester__tp_init,             /* tp_init */
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
PyNs3EnergyHarvesterContainer__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3EnergyHarvesterContainer *self)
{
    PyObject *py_retval;
    PyNs3EnergyHarvesterContainer__PythonHelper *helper = dynamic_cast< PyNs3EnergyHarvesterContainer__PythonHelper* >(self->obj);
    
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
PyNs3EnergyHarvesterContainer__PythonHelper::_wrap_NotifyNewAggregate(PyNs3EnergyHarvesterContainer *self)
{
    PyObject *py_retval;
    PyNs3EnergyHarvesterContainer__PythonHelper *helper = dynamic_cast< PyNs3EnergyHarvesterContainer__PythonHelper* >(self->obj);
    
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
PyNs3EnergyHarvesterContainer__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergyHarvesterContainer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = (ns3::EnergyHarvesterContainer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3EnergyHarvesterContainer__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergyHarvesterContainer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = (ns3::EnergyHarvesterContainer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergyHarvesterContainer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3EnergyHarvesterContainer__PythonHelper::GetInstanceTypeId() const
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
PyNs3EnergyHarvesterContainer__PythonHelper::NotifyNewAggregate()
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
PyNs3EnergyHarvesterContainer__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3EnergyHarvesterContainer__tp_init__0(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergyHarvesterContainer *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergyHarvesterContainer_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergyHarvesterContainer_Type)
    {
        self->obj = new PyNs3EnergyHarvesterContainer__PythonHelper(*((PyNs3EnergyHarvesterContainer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvesterContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvesterContainer(*((PyNs3EnergyHarvesterContainer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergyHarvesterContainer__tp_init__1(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3EnergyHarvesterContainer_Type)
    {
        self->obj = new PyNs3EnergyHarvesterContainer__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvesterContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvesterContainer();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergyHarvesterContainer__tp_init__2(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergyHarvester *harvester;
    ns3::EnergyHarvester *harvester_ptr;
    const char *keywords[] = {"harvester", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergyHarvester_Type, &harvester)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    harvester_ptr = (harvester ? harvester->obj : NULL);
    if (Py_TYPE(self) != &PyNs3EnergyHarvesterContainer_Type)
    {
        self->obj = new PyNs3EnergyHarvesterContainer__PythonHelper(ns3::Ptr< ns3::EnergyHarvester  > (harvester_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvesterContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvesterContainer(ns3::Ptr< ns3::EnergyHarvester  > (harvester_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergyHarvesterContainer__tp_init__3(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *harvesterName;
    Py_ssize_t harvesterName_len;
    const char *keywords[] = {"harvesterName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &harvesterName, &harvesterName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergyHarvesterContainer_Type)
    {
        self->obj = new PyNs3EnergyHarvesterContainer__PythonHelper(std::string(harvesterName, harvesterName_len));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvesterContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvesterContainer(std::string(harvesterName, harvesterName_len));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergyHarvesterContainer__tp_init__4(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergyHarvesterContainer *a;
    PyNs3EnergyHarvesterContainer *b;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3EnergyHarvesterContainer_Type, &a, &PyNs3EnergyHarvesterContainer_Type, &b)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergyHarvesterContainer_Type)
    {
        self->obj = new PyNs3EnergyHarvesterContainer__PythonHelper(*((PyNs3EnergyHarvesterContainer *) a)->obj, *((PyNs3EnergyHarvesterContainer *) b)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergyHarvesterContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergyHarvesterContainer(*((PyNs3EnergyHarvesterContainer *) a)->obj, *((PyNs3EnergyHarvesterContainer *) b)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3EnergyHarvesterContainer__tp_init(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3EnergyHarvesterContainer__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterContainer__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterContainer__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterContainer__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterContainer__tp_init__4(self, args, kwargs, &exceptions[4]);
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
_wrap_PyNs3EnergyHarvesterContainer_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::EnergyHarvesterContainer::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}



PyObject *
_wrap_PyNs3EnergyHarvesterContainer_Add__0(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3EnergyHarvesterContainer *container;
    const char *keywords[] = {"container", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergyHarvesterContainer_Type, &container)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(*((PyNs3EnergyHarvesterContainer *) container)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergyHarvesterContainer_Add__1(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3EnergyHarvester *harvester;
    ns3::EnergyHarvester *harvester_ptr;
    const char *keywords[] = {"harvester", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergyHarvester_Type, &harvester)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    harvester_ptr = (harvester ? harvester->obj : NULL);
    self->obj->Add(ns3::Ptr< ns3::EnergyHarvester  > (harvester_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergyHarvesterContainer_Add__2(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *harvesterName;
    Py_ssize_t harvesterName_len;
    const char *keywords[] = {"harvesterName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &harvesterName, &harvesterName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(std::string(harvesterName, harvesterName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3EnergyHarvesterContainer_Add(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3EnergyHarvesterContainer_Add__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterContainer_Add__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3EnergyHarvesterContainer_Add__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3EnergyHarvesterContainer_Clear(PyNs3EnergyHarvesterContainer *self)
{
    PyObject *py_retval;
    
    self->obj->Clear();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergyHarvesterContainer_GetN(PyNs3EnergyHarvesterContainer *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetN();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergyHarvesterContainer_Get(PyNs3EnergyHarvesterContainer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::EnergyHarvester > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3EnergyHarvester *py_EnergyHarvester;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->Get(i);
    if (!(const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3EnergyHarvester__PythonHelper).name())
    {
        py_EnergyHarvester = reinterpret_cast< PyNs3EnergyHarvester* >(reinterpret_cast< PyNs3EnergyHarvester__PythonHelper* >(const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval)))->m_pyself);
        py_EnergyHarvester->obj = const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval));
        Py_INCREF(py_EnergyHarvester);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_EnergyHarvester = NULL;
        } else {
            py_EnergyHarvester = (PyNs3EnergyHarvester *) wrapper_lookup_iter->second;
            Py_INCREF(py_EnergyHarvester);
        }
    
        if (py_EnergyHarvester == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval)))), &PyNs3EnergyHarvester_Type);
            py_EnergyHarvester = PyObject_GC_New(PyNs3EnergyHarvester, wrapper_type);
            py_EnergyHarvester->inst_dict = NULL;
    
            py_EnergyHarvester->inst_dict = NULL;
            py_EnergyHarvester->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval))->Ref();
            py_EnergyHarvester->obj = const_cast<ns3::EnergyHarvester *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_EnergyHarvester->obj] = (PyObject *) py_EnergyHarvester;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_EnergyHarvester);
    return py_retval;
}


static PyObject*
_wrap_PyNs3EnergyHarvesterContainer__copy__(PyNs3EnergyHarvesterContainer *self)
{

    PyNs3EnergyHarvesterContainer *py_copy;
    py_copy = PyObject_GC_New(PyNs3EnergyHarvesterContainer, &PyNs3EnergyHarvesterContainer_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::EnergyHarvesterContainer(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3EnergyHarvesterContainer_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3EnergyHarvesterContainer_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Add", (PyCFunction) _wrap_PyNs3EnergyHarvesterContainer_Add, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Clear", (PyCFunction) _wrap_PyNs3EnergyHarvesterContainer_Clear, METH_NOARGS, NULL },
    {(char *) "GetN", (PyCFunction) _wrap_PyNs3EnergyHarvesterContainer_GetN, METH_NOARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3EnergyHarvesterContainer_Get, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3EnergyHarvesterContainer__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3EnergyHarvesterContainer__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3EnergyHarvesterContainer__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3EnergyHarvesterContainer__tp_clear(PyNs3EnergyHarvesterContainer *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::EnergyHarvesterContainer *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3EnergyHarvesterContainer__tp_traverse(PyNs3EnergyHarvesterContainer *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3EnergyHarvesterContainer__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3EnergyHarvesterContainer__tp_dealloc(PyNs3EnergyHarvesterContainer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3EnergyHarvesterContainer__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3EnergyHarvesterContainer__tp_richcompare (PyNs3EnergyHarvesterContainer *PYBINDGEN_UNUSED(self), PyNs3EnergyHarvesterContainer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3EnergyHarvesterContainer_Type)) {
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

PyTypeObject PyNs3EnergyHarvesterContainer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.EnergyHarvesterContainer",            /* tp_name */
    sizeof(PyNs3EnergyHarvesterContainer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3EnergyHarvesterContainer__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3EnergyHarvesterContainer__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3EnergyHarvesterContainer__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3EnergyHarvesterContainer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3EnergyHarvesterContainer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3EnergyHarvesterContainer, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3EnergyHarvesterContainer__tp_init,             /* tp_init */
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
PyNs3EnergySource__PythonHelper::_wrap_CalculateTotalCurrent(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method CalculateTotalCurrent of class EnergySource is protected and can only be called by a subclass");
        return NULL;
    }
    retval = helper->CalculateTotalCurrent__parent_caller();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}

PyObject *
PyNs3EnergySource__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
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
PyNs3EnergySource__PythonHelper::_wrap_DoInitialize(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
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
PyNs3EnergySource__PythonHelper::_wrap_NotifyNewAggregate(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
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
PyNs3EnergySource__PythonHelper::_wrap_BreakDeviceEnergyModelRefCycle(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method BreakDeviceEnergyModelRefCycle of class EnergySource is protected and can only be called by a subclass");
        return NULL;
    }
    helper->BreakDeviceEnergyModelRefCycle__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3EnergySource__PythonHelper::_wrap_NotifyEnergyDrained(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyEnergyDrained of class EnergySource is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyEnergyDrained__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3EnergySource__PythonHelper::_wrap_NotifyEnergyRecharged(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    PyNs3EnergySource__PythonHelper *helper = dynamic_cast< PyNs3EnergySource__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyEnergyRecharged of class EnergySource is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyEnergyRecharged__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3EnergySource__PythonHelper::GetEnergyFraction()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetEnergyFraction"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = (ns3::EnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetEnergyFraction", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3EnergySource__PythonHelper::GetInitialEnergy() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInitialEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = const_cast< ns3::EnergySource* >((const ns3::EnergySource*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInitialEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3EnergySource__PythonHelper::GetRemainingEnergy()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetRemainingEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = (ns3::EnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetRemainingEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3EnergySource__PythonHelper::GetSupplyVoltage() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetSupplyVoltage"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = const_cast< ns3::EnergySource* >((const ns3::EnergySource*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetSupplyVoltage", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3EnergySource__PythonHelper::UpdateEnergySource()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "UpdateEnergySource"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = (ns3::EnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "UpdateEnergySource", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3EnergySource__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = (ns3::EnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3EnergySource__PythonHelper::GetInstanceTypeId() const
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
PyNs3EnergySource__PythonHelper::DoInitialize()
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
PyNs3EnergySource__PythonHelper::NotifyNewAggregate()
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
PyNs3EnergySource__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3EnergySource__tp_init__0(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergySource *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergySource_Type)
    {
        self->obj = new PyNs3EnergySource__PythonHelper(*((PyNs3EnergySource *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySource__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'EnergySource' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3EnergySource__tp_init__1(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3EnergySource_Type)
    {
        self->obj = new PyNs3EnergySource__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySource__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'EnergySource' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3EnergySource__tp_init(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3EnergySource__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergySource__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3EnergySource_UpdateEnergySource(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    
    self->obj->UpdateEnergySource();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_SetNode(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3EnergySource_GetSupplyVoltage(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetSupplyVoltage();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_DisposeDeviceModels(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    
    self->obj->DisposeDeviceModels();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_AppendDeviceEnergyModel(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DeviceEnergyModel *deviceEnergyModelPtr;
    ns3::DeviceEnergyModel *deviceEnergyModelPtr_ptr;
    const char *keywords[] = {"deviceEnergyModelPtr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DeviceEnergyModel_Type, &deviceEnergyModelPtr)) {
        return NULL;
    }
    deviceEnergyModelPtr_ptr = (deviceEnergyModelPtr ? deviceEnergyModelPtr->obj : NULL);
    self->obj->AppendDeviceEnergyModel(ns3::Ptr< ns3::DeviceEnergyModel  > (deviceEnergyModelPtr_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_GetEnergyFraction(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetEnergyFraction();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_InitializeDeviceModels(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    
    self->obj->InitializeDeviceModels();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_ConnectEnergyHarvester(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3EnergyHarvester *energyHarvesterPtr;
    ns3::EnergyHarvester *energyHarvesterPtr_ptr;
    const char *keywords[] = {"energyHarvesterPtr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergyHarvester_Type, &energyHarvesterPtr)) {
        return NULL;
    }
    energyHarvesterPtr_ptr = (energyHarvesterPtr ? energyHarvesterPtr->obj : NULL);
    self->obj->ConnectEnergyHarvester(ns3::Ptr< ns3::EnergyHarvester  > (energyHarvesterPtr_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3EnergySource_FindDeviceEnergyModels__0(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3TypeId *tid;
    const char *keywords[] = {"tid", NULL};
    PyNs3DeviceEnergyModelContainer *py_DeviceEnergyModelContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TypeId_Type, &tid)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::DeviceEnergyModelContainer retval = self->obj->FindDeviceEnergyModels(*((PyNs3TypeId *) tid)->obj);
    py_DeviceEnergyModelContainer = PyObject_New(PyNs3DeviceEnergyModelContainer, &PyNs3DeviceEnergyModelContainer_Type);
    py_DeviceEnergyModelContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DeviceEnergyModelContainer->obj = new ns3::DeviceEnergyModelContainer(retval);
    PyNs3DeviceEnergyModelContainer_wrapper_registry[(void *) py_DeviceEnergyModelContainer->obj] = (PyObject *) py_DeviceEnergyModelContainer;
    py_retval = Py_BuildValue((char *) "N", py_DeviceEnergyModelContainer);
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergySource_FindDeviceEnergyModels__1(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    const char *keywords[] = {"name", NULL};
    PyNs3DeviceEnergyModelContainer *py_DeviceEnergyModelContainer;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &name, &name_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::DeviceEnergyModelContainer retval = self->obj->FindDeviceEnergyModels(std::string(name, name_len));
    py_DeviceEnergyModelContainer = PyObject_New(PyNs3DeviceEnergyModelContainer, &PyNs3DeviceEnergyModelContainer_Type);
    py_DeviceEnergyModelContainer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DeviceEnergyModelContainer->obj = new ns3::DeviceEnergyModelContainer(retval);
    PyNs3DeviceEnergyModelContainer_wrapper_registry[(void *) py_DeviceEnergyModelContainer->obj] = (PyObject *) py_DeviceEnergyModelContainer;
    py_retval = Py_BuildValue((char *) "N", py_DeviceEnergyModelContainer);
    return py_retval;
}

PyObject * _wrap_PyNs3EnergySource_FindDeviceEnergyModels(PyNs3EnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3EnergySource_FindDeviceEnergyModels__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergySource_FindDeviceEnergyModels__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3EnergySource_GetRemainingEnergy(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetRemainingEnergy();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_GetInitialEnergy(PyNs3EnergySource *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetInitialEnergy();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::EnergySource::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySource_GetNode(PyNs3EnergySource *self)
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

static PyMethodDef PyNs3EnergySource_methods[] = {
    {(char *) "UpdateEnergySource", (PyCFunction) _wrap_PyNs3EnergySource_UpdateEnergySource, METH_NOARGS, NULL },
    {(char *) "SetNode", (PyCFunction) _wrap_PyNs3EnergySource_SetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSupplyVoltage", (PyCFunction) _wrap_PyNs3EnergySource_GetSupplyVoltage, METH_NOARGS, NULL },
    {(char *) "DisposeDeviceModels", (PyCFunction) _wrap_PyNs3EnergySource_DisposeDeviceModels, METH_NOARGS, NULL },
    {(char *) "AppendDeviceEnergyModel", (PyCFunction) _wrap_PyNs3EnergySource_AppendDeviceEnergyModel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetEnergyFraction", (PyCFunction) _wrap_PyNs3EnergySource_GetEnergyFraction, METH_NOARGS, NULL },
    {(char *) "InitializeDeviceModels", (PyCFunction) _wrap_PyNs3EnergySource_InitializeDeviceModels, METH_NOARGS, NULL },
    {(char *) "ConnectEnergyHarvester", (PyCFunction) _wrap_PyNs3EnergySource_ConnectEnergyHarvester, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindDeviceEnergyModels", (PyCFunction) _wrap_PyNs3EnergySource_FindDeviceEnergyModels, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRemainingEnergy", (PyCFunction) _wrap_PyNs3EnergySource_GetRemainingEnergy, METH_NOARGS, NULL },
    {(char *) "GetInitialEnergy", (PyCFunction) _wrap_PyNs3EnergySource_GetInitialEnergy, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3EnergySource_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3EnergySource_GetNode, METH_NOARGS, NULL },
    {(char *) "CalculateTotalCurrent", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_CalculateTotalCurrent, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "BreakDeviceEnergyModelRefCycle", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_BreakDeviceEnergyModelRefCycle, METH_NOARGS, NULL },
    {(char *) "NotifyEnergyDrained", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_NotifyEnergyDrained, METH_NOARGS, NULL },
    {(char *) "NotifyEnergyRecharged", (PyCFunction) PyNs3EnergySource__PythonHelper::_wrap_NotifyEnergyRecharged, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3EnergySource__tp_clear(PyNs3EnergySource *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::EnergySource *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3EnergySource__tp_traverse(PyNs3EnergySource *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3EnergySource__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3EnergySource__tp_dealloc(PyNs3EnergySource *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3EnergySource__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3EnergySource__tp_richcompare (PyNs3EnergySource *PYBINDGEN_UNUSED(self), PyNs3EnergySource *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3EnergySource_Type)) {
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

PyTypeObject PyNs3EnergySource_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.EnergySource",            /* tp_name */
    sizeof(PyNs3EnergySource),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3EnergySource__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3EnergySource__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3EnergySource__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3EnergySource__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3EnergySource_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3EnergySource, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3EnergySource__tp_init,             /* tp_init */
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
PyNs3EnergySourceContainer__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3EnergySourceContainer *self)
{
    PyObject *py_retval;
    PyNs3EnergySourceContainer__PythonHelper *helper = dynamic_cast< PyNs3EnergySourceContainer__PythonHelper* >(self->obj);
    
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
PyNs3EnergySourceContainer__PythonHelper::_wrap_NotifyNewAggregate(PyNs3EnergySourceContainer *self)
{
    PyObject *py_retval;
    PyNs3EnergySourceContainer__PythonHelper *helper = dynamic_cast< PyNs3EnergySourceContainer__PythonHelper* >(self->obj);
    
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
PyNs3EnergySourceContainer__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySourceContainer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = (ns3::EnergySourceContainer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3EnergySourceContainer__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::EnergySourceContainer *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj;
    reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = (ns3::EnergySourceContainer*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3EnergySourceContainer* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3EnergySourceContainer__PythonHelper::GetInstanceTypeId() const
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
PyNs3EnergySourceContainer__PythonHelper::NotifyNewAggregate()
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
PyNs3EnergySourceContainer__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3EnergySourceContainer__tp_init__0(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergySourceContainer *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySourceContainer_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergySourceContainer_Type)
    {
        self->obj = new PyNs3EnergySourceContainer__PythonHelper(*((PyNs3EnergySourceContainer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySourceContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergySourceContainer(*((PyNs3EnergySourceContainer *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergySourceContainer__tp_init__1(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3EnergySourceContainer_Type)
    {
        self->obj = new PyNs3EnergySourceContainer__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySourceContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergySourceContainer();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergySourceContainer__tp_init__2(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    const char *keywords[] = {"source", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &source)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    source_ptr = (source ? source->obj : NULL);
    if (Py_TYPE(self) != &PyNs3EnergySourceContainer_Type)
    {
        self->obj = new PyNs3EnergySourceContainer__PythonHelper(ns3::Ptr< ns3::EnergySource  > (source_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySourceContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergySourceContainer(ns3::Ptr< ns3::EnergySource  > (source_ptr));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergySourceContainer__tp_init__3(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *sourceName;
    Py_ssize_t sourceName_len;
    const char *keywords[] = {"sourceName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &sourceName, &sourceName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergySourceContainer_Type)
    {
        self->obj = new PyNs3EnergySourceContainer__PythonHelper(std::string(sourceName, sourceName_len));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySourceContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergySourceContainer(std::string(sourceName, sourceName_len));
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3EnergySourceContainer__tp_init__4(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3EnergySourceContainer *a;
    PyNs3EnergySourceContainer *b;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3EnergySourceContainer_Type, &a, &PyNs3EnergySourceContainer_Type, &b)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3EnergySourceContainer_Type)
    {
        self->obj = new PyNs3EnergySourceContainer__PythonHelper(*((PyNs3EnergySourceContainer *) a)->obj, *((PyNs3EnergySourceContainer *) b)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3EnergySourceContainer__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::EnergySourceContainer(*((PyNs3EnergySourceContainer *) a)->obj, *((PyNs3EnergySourceContainer *) b)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3EnergySourceContainer__tp_init(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3EnergySourceContainer__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceContainer__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceContainer__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceContainer__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceContainer__tp_init__4(self, args, kwargs, &exceptions[4]);
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
_wrap_PyNs3EnergySourceContainer_Add__0(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3EnergySourceContainer *container;
    const char *keywords[] = {"container", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySourceContainer_Type, &container)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(*((PyNs3EnergySourceContainer *) container)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergySourceContainer_Add__1(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    const char *keywords[] = {"source", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &source)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    source_ptr = (source ? source->obj : NULL);
    self->obj->Add(ns3::Ptr< ns3::EnergySource  > (source_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3EnergySourceContainer_Add__2(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *sourceName;
    Py_ssize_t sourceName_len;
    const char *keywords[] = {"sourceName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &sourceName, &sourceName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(std::string(sourceName, sourceName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3EnergySourceContainer_Add(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3EnergySourceContainer_Add__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceContainer_Add__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3EnergySourceContainer_Add__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3EnergySourceContainer_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::EnergySourceContainer::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySourceContainer_GetN(PyNs3EnergySourceContainer *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetN();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3EnergySourceContainer_Get(PyNs3EnergySourceContainer *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::EnergySource > retval;
    unsigned int i;
    const char *keywords[] = {"i", NULL};
    PyNs3EnergySource *py_EnergySource;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &i)) {
        return NULL;
    }
    retval = self->obj->Get(i);
    if (!(const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3EnergySource__PythonHelper).name())
    {
        py_EnergySource = reinterpret_cast< PyNs3EnergySource* >(reinterpret_cast< PyNs3EnergySource__PythonHelper* >(const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))->m_pyself);
        py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval));
        Py_INCREF(py_EnergySource);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_EnergySource = NULL;
        } else {
            py_EnergySource = (PyNs3EnergySource *) wrapper_lookup_iter->second;
            Py_INCREF(py_EnergySource);
        }
    
        if (py_EnergySource == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval)))), &PyNs3EnergySource_Type);
            py_EnergySource = PyObject_GC_New(PyNs3EnergySource, wrapper_type);
            py_EnergySource->inst_dict = NULL;
    
            py_EnergySource->inst_dict = NULL;
            py_EnergySource->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval))->Ref();
            py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySource->obj] = (PyObject *) py_EnergySource;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_EnergySource);
    return py_retval;
}


static PyObject*
_wrap_PyNs3EnergySourceContainer__copy__(PyNs3EnergySourceContainer *self)
{

    PyNs3EnergySourceContainer *py_copy;
    py_copy = PyObject_GC_New(PyNs3EnergySourceContainer, &PyNs3EnergySourceContainer_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::EnergySourceContainer(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3EnergySourceContainer_methods[] = {
    {(char *) "Add", (PyCFunction) _wrap_PyNs3EnergySourceContainer_Add, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3EnergySourceContainer_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetN", (PyCFunction) _wrap_PyNs3EnergySourceContainer_GetN, METH_NOARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3EnergySourceContainer_Get, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3EnergySourceContainer__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3EnergySourceContainer__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3EnergySourceContainer__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3EnergySourceContainer__tp_clear(PyNs3EnergySourceContainer *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::EnergySourceContainer *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3EnergySourceContainer__tp_traverse(PyNs3EnergySourceContainer *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3EnergySourceContainer__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3EnergySourceContainer__tp_dealloc(PyNs3EnergySourceContainer *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3EnergySourceContainer__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3EnergySourceContainer__tp_richcompare (PyNs3EnergySourceContainer *PYBINDGEN_UNUSED(self), PyNs3EnergySourceContainer *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3EnergySourceContainer_Type)) {
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

PyTypeObject PyNs3EnergySourceContainer_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.EnergySourceContainer",            /* tp_name */
    sizeof(PyNs3EnergySourceContainer),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3EnergySourceContainer__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3EnergySourceContainer__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3EnergySourceContainer__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3EnergySourceContainer__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3EnergySourceContainer_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3EnergySourceContainer, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3EnergySourceContainer__tp_init,             /* tp_init */
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
PyNs3LiIonEnergySource__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    PyNs3LiIonEnergySource__PythonHelper *helper = dynamic_cast< PyNs3LiIonEnergySource__PythonHelper* >(self->obj);
    
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
PyNs3LiIonEnergySource__PythonHelper::_wrap_NotifyNewAggregate(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    PyNs3LiIonEnergySource__PythonHelper *helper = dynamic_cast< PyNs3LiIonEnergySource__PythonHelper* >(self->obj);
    
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
PyNs3LiIonEnergySource__PythonHelper::DecreaseRemainingEnergy(double energyJ)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DecreaseRemainingEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::LiIonEnergySource::DecreaseRemainingEnergy(energyJ);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DecreaseRemainingEnergy", (char *) "d", energyJ);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

double
PyNs3LiIonEnergySource__PythonHelper::GetEnergyFraction()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetEnergyFraction"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetEnergyFraction();
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetEnergyFraction", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetEnergyFraction();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetEnergyFraction();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3LiIonEnergySource__PythonHelper::GetInitialEnergy() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInitialEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetInitialEnergy();
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = const_cast< ns3::LiIonEnergySource* >((const ns3::LiIonEnergySource*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInitialEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetInitialEnergy();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetInitialEnergy();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3LiIonEnergySource__PythonHelper::GetRemainingEnergy()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetRemainingEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetRemainingEnergy();
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetRemainingEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetRemainingEnergy();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetRemainingEnergy();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3LiIonEnergySource__PythonHelper::GetSupplyVoltage() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetSupplyVoltage"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetSupplyVoltage();
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = const_cast< ns3::LiIonEnergySource* >((const ns3::LiIonEnergySource*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetSupplyVoltage", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetSupplyVoltage();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::LiIonEnergySource::GetSupplyVoltage();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3LiIonEnergySource__PythonHelper::IncreaseRemainingEnergy(double energyJ)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "IncreaseRemainingEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::LiIonEnergySource::IncreaseRemainingEnergy(energyJ);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "IncreaseRemainingEnergy", (char *) "d", energyJ);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3LiIonEnergySource__PythonHelper::UpdateEnergySource()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "UpdateEnergySource"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::LiIonEnergySource::UpdateEnergySource();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "UpdateEnergySource", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3LiIonEnergySource__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3LiIonEnergySource__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LiIonEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = (ns3::LiIonEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LiIonEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3LiIonEnergySource__PythonHelper::GetInstanceTypeId() const
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
PyNs3LiIonEnergySource__PythonHelper::NotifyNewAggregate()
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
PyNs3LiIonEnergySource__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3LiIonEnergySource__tp_init__0(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3LiIonEnergySource *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3LiIonEnergySource_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3LiIonEnergySource_Type)
    {
        self->obj = new PyNs3LiIonEnergySource__PythonHelper(*((PyNs3LiIonEnergySource *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LiIonEnergySource__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LiIonEnergySource(*((PyNs3LiIonEnergySource *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3LiIonEnergySource__tp_init__1(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3LiIonEnergySource_Type)
    {
        self->obj = new PyNs3LiIonEnergySource__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LiIonEnergySource__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LiIonEnergySource();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3LiIonEnergySource__tp_init(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3LiIonEnergySource__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3LiIonEnergySource__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3LiIonEnergySource_UpdateEnergySource(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->UpdateEnergySource()) : (self->obj->ns3::LiIonEnergySource::UpdateEnergySource());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_GetEnergyUpdateInterval(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetEnergyUpdateInterval();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_GetSupplyVoltage(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetSupplyVoltage()) : (self->obj->ns3::LiIonEnergySource::GetSupplyVoltage());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LiIonEnergySource::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_DecreaseRemainingEnergy(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double energyJ;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    const char *keywords[] = {"energyJ", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &energyJ)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->DecreaseRemainingEnergy(energyJ)) : (self->obj->ns3::LiIonEnergySource::DecreaseRemainingEnergy(energyJ));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_GetEnergyFraction(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetEnergyFraction()) : (self->obj->ns3::LiIonEnergySource::GetEnergyFraction());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_GetRemainingEnergy(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetRemainingEnergy()) : (self->obj->ns3::LiIonEnergySource::GetRemainingEnergy());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_SetInitialEnergy(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double initialEnergyJ;
    const char *keywords[] = {"initialEnergyJ", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &initialEnergyJ)) {
        return NULL;
    }
    self->obj->SetInitialEnergy(initialEnergyJ);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_SetInitialSupplyVoltage(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double supplyVoltageV;
    const char *keywords[] = {"supplyVoltageV", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &supplyVoltageV)) {
        return NULL;
    }
    self->obj->SetInitialSupplyVoltage(supplyVoltageV);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_SetEnergyUpdateInterval(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *interval;
    ns3::Time interval2;
    const char *keywords[] = {"interval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &interval)) {
        return NULL;
    }
    if (PyObject_IsInstance(interval, (PyObject*) &PyNs3Time_Type)) {
        interval2 = *((PyNs3Time *) interval)->obj;
    } else if (PyObject_IsInstance(interval, (PyObject*) &PyNs3TracedValue__Ns3Time_Type)) {
        interval2 = *((PyNs3TracedValue__Ns3Time *) interval)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, TracedValue), not %s", Py_TYPE(interval)->tp_name);
        return NULL;
    }
    self->obj->SetEnergyUpdateInterval(interval2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_GetInitialEnergy(PyNs3LiIonEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetInitialEnergy()) : (self->obj->ns3::LiIonEnergySource::GetInitialEnergy());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LiIonEnergySource_IncreaseRemainingEnergy(PyNs3LiIonEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double energyJ;
    PyNs3LiIonEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3LiIonEnergySource__PythonHelper*> (self->obj);
    const char *keywords[] = {"energyJ", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &energyJ)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->IncreaseRemainingEnergy(energyJ)) : (self->obj->ns3::LiIonEnergySource::IncreaseRemainingEnergy(energyJ));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3LiIonEnergySource__copy__(PyNs3LiIonEnergySource *self)
{

    PyNs3LiIonEnergySource *py_copy;
    py_copy = PyObject_GC_New(PyNs3LiIonEnergySource, &PyNs3LiIonEnergySource_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::LiIonEnergySource(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3LiIonEnergySource_methods[] = {
    {(char *) "UpdateEnergySource", (PyCFunction) _wrap_PyNs3LiIonEnergySource_UpdateEnergySource, METH_NOARGS, NULL },
    {(char *) "GetEnergyUpdateInterval", (PyCFunction) _wrap_PyNs3LiIonEnergySource_GetEnergyUpdateInterval, METH_NOARGS, NULL },
    {(char *) "GetSupplyVoltage", (PyCFunction) _wrap_PyNs3LiIonEnergySource_GetSupplyVoltage, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LiIonEnergySource_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "DecreaseRemainingEnergy", (PyCFunction) _wrap_PyNs3LiIonEnergySource_DecreaseRemainingEnergy, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetEnergyFraction", (PyCFunction) _wrap_PyNs3LiIonEnergySource_GetEnergyFraction, METH_NOARGS, NULL },
    {(char *) "GetRemainingEnergy", (PyCFunction) _wrap_PyNs3LiIonEnergySource_GetRemainingEnergy, METH_NOARGS, NULL },
    {(char *) "SetInitialEnergy", (PyCFunction) _wrap_PyNs3LiIonEnergySource_SetInitialEnergy, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetInitialSupplyVoltage", (PyCFunction) _wrap_PyNs3LiIonEnergySource_SetInitialSupplyVoltage, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetEnergyUpdateInterval", (PyCFunction) _wrap_PyNs3LiIonEnergySource_SetEnergyUpdateInterval, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInitialEnergy", (PyCFunction) _wrap_PyNs3LiIonEnergySource_GetInitialEnergy, METH_NOARGS, NULL },
    {(char *) "IncreaseRemainingEnergy", (PyCFunction) _wrap_PyNs3LiIonEnergySource_IncreaseRemainingEnergy, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3LiIonEnergySource__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3LiIonEnergySource__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3LiIonEnergySource__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LiIonEnergySource__tp_clear(PyNs3LiIonEnergySource *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LiIonEnergySource *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LiIonEnergySource__tp_traverse(PyNs3LiIonEnergySource *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3LiIonEnergySource__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3LiIonEnergySource__tp_dealloc(PyNs3LiIonEnergySource *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LiIonEnergySource__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LiIonEnergySource__tp_richcompare (PyNs3LiIonEnergySource *PYBINDGEN_UNUSED(self), PyNs3LiIonEnergySource *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LiIonEnergySource_Type)) {
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

PyTypeObject PyNs3LiIonEnergySource_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.LiIonEnergySource",            /* tp_name */
    sizeof(PyNs3LiIonEnergySource),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LiIonEnergySource__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LiIonEnergySource__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LiIonEnergySource__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LiIonEnergySource__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LiIonEnergySource_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LiIonEnergySource, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LiIonEnergySource__tp_init,             /* tp_init */
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
PyNs3RvBatteryModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    PyNs3RvBatteryModel__PythonHelper *helper = dynamic_cast< PyNs3RvBatteryModel__PythonHelper* >(self->obj);
    
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
PyNs3RvBatteryModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    PyNs3RvBatteryModel__PythonHelper *helper = dynamic_cast< PyNs3RvBatteryModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3RvBatteryModel__PythonHelper::GetEnergyFraction()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetEnergyFraction"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetEnergyFraction();
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = (ns3::RvBatteryModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetEnergyFraction", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetEnergyFraction();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetEnergyFraction();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3RvBatteryModel__PythonHelper::GetInitialEnergy() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInitialEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetInitialEnergy();
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = const_cast< ns3::RvBatteryModel* >((const ns3::RvBatteryModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInitialEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetInitialEnergy();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetInitialEnergy();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3RvBatteryModel__PythonHelper::GetRemainingEnergy()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetRemainingEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetRemainingEnergy();
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = (ns3::RvBatteryModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetRemainingEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetRemainingEnergy();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetRemainingEnergy();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3RvBatteryModel__PythonHelper::GetSupplyVoltage() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetSupplyVoltage"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetSupplyVoltage();
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = const_cast< ns3::RvBatteryModel* >((const ns3::RvBatteryModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetSupplyVoltage", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetSupplyVoltage();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RvBatteryModel::GetSupplyVoltage();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3RvBatteryModel__PythonHelper::UpdateEnergySource()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "UpdateEnergySource"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::RvBatteryModel::UpdateEnergySource();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = (ns3::RvBatteryModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "UpdateEnergySource", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3RvBatteryModel__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = (ns3::RvBatteryModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3RvBatteryModel__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RvBatteryModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = (ns3::RvBatteryModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RvBatteryModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3RvBatteryModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RvBatteryModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RvBatteryModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RvBatteryModel__tp_init__0(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RvBatteryModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RvBatteryModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RvBatteryModel_Type)
    {
        self->obj = new PyNs3RvBatteryModel__PythonHelper(*((PyNs3RvBatteryModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RvBatteryModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RvBatteryModel(*((PyNs3RvBatteryModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RvBatteryModel__tp_init__1(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RvBatteryModel_Type)
    {
        self->obj = new PyNs3RvBatteryModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RvBatteryModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RvBatteryModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RvBatteryModel__tp_init(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RvBatteryModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RvBatteryModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RvBatteryModel_UpdateEnergySource(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    PyNs3RvBatteryModel__PythonHelper *helper_class = dynamic_cast<PyNs3RvBatteryModel__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->UpdateEnergySource()) : (self->obj->ns3::RvBatteryModel::UpdateEnergySource());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetNumOfTerms(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    int retval;
    
    retval = self->obj->GetNumOfTerms();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_SetNumOfTerms(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int num;
    const char *keywords[] = {"num", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &num)) {
        return NULL;
    }
    self->obj->SetNumOfTerms(num);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_SetOpenCircuitVoltage(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double voltage;
    const char *keywords[] = {"voltage", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &voltage)) {
        return NULL;
    }
    self->obj->SetOpenCircuitVoltage(voltage);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetSupplyVoltage(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3RvBatteryModel__PythonHelper *helper_class = dynamic_cast<PyNs3RvBatteryModel__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetSupplyVoltage()) : (self->obj->ns3::RvBatteryModel::GetSupplyVoltage());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_SetBeta(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double beta;
    const char *keywords[] = {"beta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &beta)) {
        return NULL;
    }
    self->obj->SetBeta(beta);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RvBatteryModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetCutoffVoltage(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetCutoffVoltage();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetBeta(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetBeta();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetLifetime(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetLifetime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetEnergyFraction(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3RvBatteryModel__PythonHelper *helper_class = dynamic_cast<PyNs3RvBatteryModel__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetEnergyFraction()) : (self->obj->ns3::RvBatteryModel::GetEnergyFraction());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetOpenCircuitVoltage(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetOpenCircuitVoltage();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetBatteryLevel(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetBatteryLevel();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetRemainingEnergy(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3RvBatteryModel__PythonHelper *helper_class = dynamic_cast<PyNs3RvBatteryModel__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetRemainingEnergy()) : (self->obj->ns3::RvBatteryModel::GetRemainingEnergy());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetSamplingInterval(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetSamplingInterval();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetAlpha(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetAlpha();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_SetAlpha(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double alpha;
    const char *keywords[] = {"alpha", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &alpha)) {
        return NULL;
    }
    self->obj->SetAlpha(alpha);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_SetSamplingInterval(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *interval;
    ns3::Time interval2;
    const char *keywords[] = {"interval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &interval)) {
        return NULL;
    }
    if (PyObject_IsInstance(interval, (PyObject*) &PyNs3Time_Type)) {
        interval2 = *((PyNs3Time *) interval)->obj;
    } else if (PyObject_IsInstance(interval, (PyObject*) &PyNs3TracedValue__Ns3Time_Type)) {
        interval2 = *((PyNs3TracedValue__Ns3Time *) interval)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, TracedValue), not %s", Py_TYPE(interval)->tp_name);
        return NULL;
    }
    self->obj->SetSamplingInterval(interval2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_GetInitialEnergy(PyNs3RvBatteryModel *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3RvBatteryModel__PythonHelper *helper_class = dynamic_cast<PyNs3RvBatteryModel__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetInitialEnergy()) : (self->obj->ns3::RvBatteryModel::GetInitialEnergy());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RvBatteryModel_SetCutoffVoltage(PyNs3RvBatteryModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double voltage;
    const char *keywords[] = {"voltage", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &voltage)) {
        return NULL;
    }
    self->obj->SetCutoffVoltage(voltage);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3RvBatteryModel__copy__(PyNs3RvBatteryModel *self)
{

    PyNs3RvBatteryModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3RvBatteryModel, &PyNs3RvBatteryModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RvBatteryModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RvBatteryModel_methods[] = {
    {(char *) "UpdateEnergySource", (PyCFunction) _wrap_PyNs3RvBatteryModel_UpdateEnergySource, METH_NOARGS, NULL },
    {(char *) "GetNumOfTerms", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetNumOfTerms, METH_NOARGS, NULL },
    {(char *) "SetNumOfTerms", (PyCFunction) _wrap_PyNs3RvBatteryModel_SetNumOfTerms, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetOpenCircuitVoltage", (PyCFunction) _wrap_PyNs3RvBatteryModel_SetOpenCircuitVoltage, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSupplyVoltage", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetSupplyVoltage, METH_NOARGS, NULL },
    {(char *) "SetBeta", (PyCFunction) _wrap_PyNs3RvBatteryModel_SetBeta, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetCutoffVoltage", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetCutoffVoltage, METH_NOARGS, NULL },
    {(char *) "GetBeta", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetBeta, METH_NOARGS, NULL },
    {(char *) "GetLifetime", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetLifetime, METH_NOARGS, NULL },
    {(char *) "GetEnergyFraction", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetEnergyFraction, METH_NOARGS, NULL },
    {(char *) "GetOpenCircuitVoltage", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetOpenCircuitVoltage, METH_NOARGS, NULL },
    {(char *) "GetBatteryLevel", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetBatteryLevel, METH_NOARGS, NULL },
    {(char *) "GetRemainingEnergy", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetRemainingEnergy, METH_NOARGS, NULL },
    {(char *) "GetSamplingInterval", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetSamplingInterval, METH_NOARGS, NULL },
    {(char *) "GetAlpha", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetAlpha, METH_NOARGS, NULL },
    {(char *) "SetAlpha", (PyCFunction) _wrap_PyNs3RvBatteryModel_SetAlpha, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSamplingInterval", (PyCFunction) _wrap_PyNs3RvBatteryModel_SetSamplingInterval, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInitialEnergy", (PyCFunction) _wrap_PyNs3RvBatteryModel_GetInitialEnergy, METH_NOARGS, NULL },
    {(char *) "SetCutoffVoltage", (PyCFunction) _wrap_PyNs3RvBatteryModel_SetCutoffVoltage, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RvBatteryModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RvBatteryModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RvBatteryModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RvBatteryModel__tp_clear(PyNs3RvBatteryModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RvBatteryModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RvBatteryModel__tp_traverse(PyNs3RvBatteryModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RvBatteryModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RvBatteryModel__tp_dealloc(PyNs3RvBatteryModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RvBatteryModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RvBatteryModel__tp_richcompare (PyNs3RvBatteryModel *PYBINDGEN_UNUSED(self), PyNs3RvBatteryModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RvBatteryModel_Type)) {
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

PyTypeObject PyNs3RvBatteryModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.RvBatteryModel",            /* tp_name */
    sizeof(PyNs3RvBatteryModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RvBatteryModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RvBatteryModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RvBatteryModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RvBatteryModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RvBatteryModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RvBatteryModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RvBatteryModel__tp_init,             /* tp_init */
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3SimpleDeviceEnergyModel__PythonHelper* >(self->obj);
    
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::_wrap_DoInitialize(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3SimpleDeviceEnergyModel__PythonHelper* >(self->obj);
    
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper = dynamic_cast< PyNs3SimpleDeviceEnergyModel__PythonHelper* >(self->obj);
    
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::ChangeState(int newState)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ChangeState"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::SimpleDeviceEnergyModel::ChangeState(newState);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = (ns3::SimpleDeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ChangeState", (char *) "i", newState);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::Ptr< ns3::Node >
PyNs3SimpleDeviceEnergyModel__PythonHelper::GetNode() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    PyNs3Node *tmp_Node;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNode"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::SimpleDeviceEnergyModel::GetNode();
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = const_cast< ns3::SimpleDeviceEnergyModel* >((const ns3::SimpleDeviceEnergyModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNode", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::SimpleDeviceEnergyModel::GetNode();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Node_Type, &tmp_Node)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::SimpleDeviceEnergyModel::GetNode();
    }
    // dangerous!
    retval = ns3::Ptr< ns3::Node  > (tmp_Node->obj);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3SimpleDeviceEnergyModel__PythonHelper::GetTotalEnergyConsumption() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetTotalEnergyConsumption"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::SimpleDeviceEnergyModel::GetTotalEnergyConsumption();
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = const_cast< ns3::SimpleDeviceEnergyModel* >((const ns3::SimpleDeviceEnergyModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetTotalEnergyConsumption", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::SimpleDeviceEnergyModel::GetTotalEnergyConsumption();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::SimpleDeviceEnergyModel::GetTotalEnergyConsumption();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3SimpleDeviceEnergyModel__PythonHelper::HandleEnergyDepletion()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "HandleEnergyDepletion"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::SimpleDeviceEnergyModel::HandleEnergyDepletion();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = (ns3::SimpleDeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "HandleEnergyDepletion", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3SimpleDeviceEnergyModel__PythonHelper::HandleEnergyRecharged()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "HandleEnergyRecharged"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::SimpleDeviceEnergyModel::HandleEnergyRecharged();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = (ns3::SimpleDeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "HandleEnergyRecharged", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3SimpleDeviceEnergyModel__PythonHelper::SetEnergySource(ns3::Ptr< ns3::EnergySource > source)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    PyNs3EnergySource *py_EnergySource;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "SetEnergySource"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::SimpleDeviceEnergyModel::SetEnergySource(source);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = (ns3::SimpleDeviceEnergyModel*) this;
    if (typeid(*(const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)))).name() == typeid(PyNs3EnergySource__PythonHelper).name())
    {
        py_EnergySource = (PyNs3EnergySource*) (((PyNs3EnergySource__PythonHelper*) const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)))->m_pyself);
        py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (source));
        Py_INCREF(py_EnergySource);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::EnergySource *> (ns3::PeekPointer (source)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_EnergySource = NULL;
        } else {
            py_EnergySource = (PyNs3EnergySource *) wrapper_lookup_iter->second;
            Py_INCREF(py_EnergySource);
        }
    
        if (py_EnergySource == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::EnergySource *> (ns3::PeekPointer (source))), &PyNs3EnergySource_Type);
            py_EnergySource = PyObject_GC_New(PyNs3EnergySource, wrapper_type);
            py_EnergySource->inst_dict = NULL;
    
            py_EnergySource->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::EnergySource *> (ns3::PeekPointer (source))->Ref();
            py_EnergySource->obj = const_cast<ns3::EnergySource *> (ns3::PeekPointer (source));
            PyNs3ObjectBase_wrapper_registry[(void *) py_EnergySource->obj] = (PyObject *) py_EnergySource;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "SetEnergySource", (char *) "N", py_EnergySource);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3SimpleDeviceEnergyModel__PythonHelper::SetNode(ns3::Ptr< ns3::Node > node)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "SetNode"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::SimpleDeviceEnergyModel::SetNode(node);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = (ns3::SimpleDeviceEnergyModel*) this;
    if (typeid(*(const_cast<ns3::Node *> (ns3::PeekPointer (node)))).name() == typeid(PyNs3Node__PythonHelper).name())
    {
        py_Node = (PyNs3Node*) (((PyNs3Node__PythonHelper*) const_cast<ns3::Node *> (ns3::PeekPointer (node)))->m_pyself);
        py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (node));
        Py_INCREF(py_Node);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Node *> (ns3::PeekPointer (node)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Node = NULL;
        } else {
            py_Node = (PyNs3Node *) wrapper_lookup_iter->second;
            Py_INCREF(py_Node);
        }
    
        if (py_Node == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::Node *> (ns3::PeekPointer (node))), &PyNs3Node_Type);
            py_Node = PyObject_GC_New(PyNs3Node, wrapper_type);
            py_Node->inst_dict = NULL;
    
            py_Node->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Node *> (ns3::PeekPointer (node))->Ref();
            py_Node->obj = const_cast<ns3::Node *> (ns3::PeekPointer (node));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Node->obj] = (PyObject *) py_Node;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "SetNode", (char *) "N", py_Node);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3SimpleDeviceEnergyModel__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = (ns3::SimpleDeviceEnergyModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

double
PyNs3SimpleDeviceEnergyModel__PythonHelper::DoGetCurrentA() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SimpleDeviceEnergyModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetCurrentA"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = const_cast< ns3::SimpleDeviceEnergyModel* >((const ns3::SimpleDeviceEnergyModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetCurrentA", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SimpleDeviceEnergyModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3SimpleDeviceEnergyModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::DoInitialize()
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::NotifyNewAggregate()
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
PyNs3SimpleDeviceEnergyModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3SimpleDeviceEnergyModel__tp_init__0(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SimpleDeviceEnergyModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SimpleDeviceEnergyModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3SimpleDeviceEnergyModel_Type)
    {
        self->obj = new PyNs3SimpleDeviceEnergyModel__PythonHelper(*((PyNs3SimpleDeviceEnergyModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3SimpleDeviceEnergyModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::SimpleDeviceEnergyModel(*((PyNs3SimpleDeviceEnergyModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3SimpleDeviceEnergyModel__tp_init__1(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3SimpleDeviceEnergyModel_Type)
    {
        self->obj = new PyNs3SimpleDeviceEnergyModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3SimpleDeviceEnergyModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::SimpleDeviceEnergyModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3SimpleDeviceEnergyModel__tp_init(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SimpleDeviceEnergyModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SimpleDeviceEnergyModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SimpleDeviceEnergyModel_HandleEnergyRecharged(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->HandleEnergyRecharged()) : (self->obj->ns3::SimpleDeviceEnergyModel::HandleEnergyRecharged());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_HandleEnergyDepletion(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->HandleEnergyDepletion()) : (self->obj->ns3::SimpleDeviceEnergyModel::HandleEnergyDepletion());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_SetEnergySource(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3EnergySource *source;
    ns3::EnergySource *source_ptr;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"source", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3EnergySource_Type, &source)) {
        return NULL;
    }
    source_ptr = (source ? source->obj : NULL);
    (helper_class == NULL)? (self->obj->SetEnergySource(ns3::Ptr< ns3::EnergySource  > (source_ptr))) : (self->obj->ns3::SimpleDeviceEnergyModel::SetEnergySource(ns3::Ptr< ns3::EnergySource  > (source_ptr)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SimpleDeviceEnergyModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_SetCurrentA(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double current;
    const char *keywords[] = {"current", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &current)) {
        return NULL;
    }
    self->obj->SetCurrentA(current);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_GetTotalEnergyConsumption(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetTotalEnergyConsumption()) : (self->obj->ns3::SimpleDeviceEnergyModel::GetTotalEnergyConsumption());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_SetNode(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"node", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    (helper_class == NULL)? (self->obj->SetNode(ns3::Ptr< ns3::Node  > (node_ptr))) : (self->obj->ns3::SimpleDeviceEnergyModel::SetNode(ns3::Ptr< ns3::Node  > (node_ptr)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_ChangeState(PyNs3SimpleDeviceEnergyModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int newState;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"newState", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &newState)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ChangeState(newState)) : (self->obj->ns3::SimpleDeviceEnergyModel::ChangeState(newState));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3SimpleDeviceEnergyModel_GetNode(PyNs3SimpleDeviceEnergyModel *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Node > retval;
    PyNs3SimpleDeviceEnergyModel__PythonHelper *helper_class = dynamic_cast<PyNs3SimpleDeviceEnergyModel__PythonHelper*> (self->obj);
    PyNs3Node *py_Node;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = (helper_class == NULL)? (self->obj->GetNode()) : (self->obj->ns3::SimpleDeviceEnergyModel::GetNode());
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
_wrap_PyNs3SimpleDeviceEnergyModel__copy__(PyNs3SimpleDeviceEnergyModel *self)
{

    PyNs3SimpleDeviceEnergyModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3SimpleDeviceEnergyModel, &PyNs3SimpleDeviceEnergyModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::SimpleDeviceEnergyModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SimpleDeviceEnergyModel_methods[] = {
    {(char *) "HandleEnergyRecharged", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_HandleEnergyRecharged, METH_NOARGS, NULL },
    {(char *) "HandleEnergyDepletion", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_HandleEnergyDepletion, METH_NOARGS, NULL },
    {(char *) "SetEnergySource", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_SetEnergySource, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetCurrentA", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_SetCurrentA, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTotalEnergyConsumption", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_GetTotalEnergyConsumption, METH_NOARGS, NULL },
    {(char *) "SetNode", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_SetNode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ChangeState", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_ChangeState, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNode", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel_GetNode, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3SimpleDeviceEnergyModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3SimpleDeviceEnergyModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3SimpleDeviceEnergyModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SimpleDeviceEnergyModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SimpleDeviceEnergyModel__tp_clear(PyNs3SimpleDeviceEnergyModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::SimpleDeviceEnergyModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3SimpleDeviceEnergyModel__tp_traverse(PyNs3SimpleDeviceEnergyModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3SimpleDeviceEnergyModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3SimpleDeviceEnergyModel__tp_dealloc(PyNs3SimpleDeviceEnergyModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SimpleDeviceEnergyModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SimpleDeviceEnergyModel__tp_richcompare (PyNs3SimpleDeviceEnergyModel *PYBINDGEN_UNUSED(self), PyNs3SimpleDeviceEnergyModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SimpleDeviceEnergyModel_Type)) {
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

PyTypeObject PyNs3SimpleDeviceEnergyModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.SimpleDeviceEnergyModel",            /* tp_name */
    sizeof(PyNs3SimpleDeviceEnergyModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SimpleDeviceEnergyModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3SimpleDeviceEnergyModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SimpleDeviceEnergyModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SimpleDeviceEnergyModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SimpleDeviceEnergyModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SimpleDeviceEnergyModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SimpleDeviceEnergyModel__tp_init,             /* tp_init */
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
PyNs3BasicEnergyHarvester__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3BasicEnergyHarvester *self)
{
    PyObject *py_retval;
    PyNs3BasicEnergyHarvester__PythonHelper *helper = dynamic_cast< PyNs3BasicEnergyHarvester__PythonHelper* >(self->obj);
    
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
PyNs3BasicEnergyHarvester__PythonHelper::_wrap_NotifyNewAggregate(PyNs3BasicEnergyHarvester *self)
{
    PyObject *py_retval;
    PyNs3BasicEnergyHarvester__PythonHelper *helper = dynamic_cast< PyNs3BasicEnergyHarvester__PythonHelper* >(self->obj);
    
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
PyNs3BasicEnergyHarvester__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergyHarvester *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = (ns3::BasicEnergyHarvester*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

double
PyNs3BasicEnergyHarvester__PythonHelper::DoGetPower() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergyHarvester *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = const_cast< ns3::BasicEnergyHarvester* >((const ns3::BasicEnergyHarvester*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPower", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3BasicEnergyHarvester__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergyHarvester *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = (ns3::BasicEnergyHarvester*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergyHarvester* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3BasicEnergyHarvester__PythonHelper::GetInstanceTypeId() const
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
PyNs3BasicEnergyHarvester__PythonHelper::NotifyNewAggregate()
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
PyNs3BasicEnergyHarvester__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3BasicEnergyHarvester__tp_init__0(PyNs3BasicEnergyHarvester *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BasicEnergyHarvester *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BasicEnergyHarvester_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BasicEnergyHarvester_Type)
    {
        self->obj = new PyNs3BasicEnergyHarvester__PythonHelper(*((PyNs3BasicEnergyHarvester *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergyHarvester__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergyHarvester(*((PyNs3BasicEnergyHarvester *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3BasicEnergyHarvester__tp_init__1(PyNs3BasicEnergyHarvester *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3BasicEnergyHarvester_Type)
    {
        self->obj = new PyNs3BasicEnergyHarvester__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergyHarvester__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergyHarvester();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3BasicEnergyHarvester__tp_init__2(PyNs3BasicEnergyHarvester *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *updateInterval;
    ns3::Time updateInterval2;
    const char *keywords[] = {"updateInterval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &updateInterval)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (PyObject_IsInstance(updateInterval, (PyObject*) &PyNs3Time_Type)) {
        updateInterval2 = *((PyNs3Time *) updateInterval)->obj;
    } else if (PyObject_IsInstance(updateInterval, (PyObject*) &PyNs3TracedValue__Ns3Time_Type)) {
        updateInterval2 = *((PyNs3TracedValue__Ns3Time *) updateInterval)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, TracedValue), not %s", Py_TYPE(updateInterval)->tp_name);
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BasicEnergyHarvester_Type)
    {
        self->obj = new PyNs3BasicEnergyHarvester__PythonHelper(updateInterval2);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergyHarvester__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergyHarvester(updateInterval2);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3BasicEnergyHarvester__tp_init(PyNs3BasicEnergyHarvester *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3BasicEnergyHarvester__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BasicEnergyHarvester__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3BasicEnergyHarvester__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3BasicEnergyHarvester_GetHarvestedPowerUpdateInterval(PyNs3BasicEnergyHarvester *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetHarvestedPowerUpdateInterval();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergyHarvester_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::BasicEnergyHarvester::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergyHarvester_SetHarvestedPowerUpdateInterval(PyNs3BasicEnergyHarvester *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *updateInterval;
    ns3::Time updateInterval2;
    const char *keywords[] = {"updateInterval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &updateInterval)) {
        return NULL;
    }
    if (PyObject_IsInstance(updateInterval, (PyObject*) &PyNs3Time_Type)) {
        updateInterval2 = *((PyNs3Time *) updateInterval)->obj;
    } else if (PyObject_IsInstance(updateInterval, (PyObject*) &PyNs3TracedValue__Ns3Time_Type)) {
        updateInterval2 = *((PyNs3TracedValue__Ns3Time *) updateInterval)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, TracedValue), not %s", Py_TYPE(updateInterval)->tp_name);
        return NULL;
    }
    self->obj->SetHarvestedPowerUpdateInterval(updateInterval2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergyHarvester_AssignStreams(PyNs3BasicEnergyHarvester *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3BasicEnergyHarvester__copy__(PyNs3BasicEnergyHarvester *self)
{

    PyNs3BasicEnergyHarvester *py_copy;
    py_copy = PyObject_GC_New(PyNs3BasicEnergyHarvester, &PyNs3BasicEnergyHarvester_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::BasicEnergyHarvester(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BasicEnergyHarvester_methods[] = {
    {(char *) "GetHarvestedPowerUpdateInterval", (PyCFunction) _wrap_PyNs3BasicEnergyHarvester_GetHarvestedPowerUpdateInterval, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3BasicEnergyHarvester_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetHarvestedPowerUpdateInterval", (PyCFunction) _wrap_PyNs3BasicEnergyHarvester_SetHarvestedPowerUpdateInterval, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3BasicEnergyHarvester_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3BasicEnergyHarvester__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3BasicEnergyHarvester__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BasicEnergyHarvester__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3BasicEnergyHarvester__tp_clear(PyNs3BasicEnergyHarvester *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::BasicEnergyHarvester *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3BasicEnergyHarvester__tp_traverse(PyNs3BasicEnergyHarvester *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3BasicEnergyHarvester__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3BasicEnergyHarvester__tp_dealloc(PyNs3BasicEnergyHarvester *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3BasicEnergyHarvester__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BasicEnergyHarvester__tp_richcompare (PyNs3BasicEnergyHarvester *PYBINDGEN_UNUSED(self), PyNs3BasicEnergyHarvester *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BasicEnergyHarvester_Type)) {
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

PyTypeObject PyNs3BasicEnergyHarvester_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.BasicEnergyHarvester",            /* tp_name */
    sizeof(PyNs3BasicEnergyHarvester),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BasicEnergyHarvester__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3BasicEnergyHarvester__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3BasicEnergyHarvester__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BasicEnergyHarvester__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BasicEnergyHarvester_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3BasicEnergyHarvester, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BasicEnergyHarvester__tp_init,             /* tp_init */
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
PyNs3BasicEnergySource__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    PyNs3BasicEnergySource__PythonHelper *helper = dynamic_cast< PyNs3BasicEnergySource__PythonHelper* >(self->obj);
    
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
PyNs3BasicEnergySource__PythonHelper::_wrap_NotifyNewAggregate(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    PyNs3BasicEnergySource__PythonHelper *helper = dynamic_cast< PyNs3BasicEnergySource__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3BasicEnergySource__PythonHelper::GetEnergyFraction()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetEnergyFraction"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetEnergyFraction();
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = (ns3::BasicEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetEnergyFraction", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetEnergyFraction();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetEnergyFraction();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3BasicEnergySource__PythonHelper::GetInitialEnergy() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInitialEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetInitialEnergy();
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = const_cast< ns3::BasicEnergySource* >((const ns3::BasicEnergySource*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInitialEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetInitialEnergy();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetInitialEnergy();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3BasicEnergySource__PythonHelper::GetRemainingEnergy()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetRemainingEnergy"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetRemainingEnergy();
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = (ns3::BasicEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetRemainingEnergy", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetRemainingEnergy();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetRemainingEnergy();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3BasicEnergySource__PythonHelper::GetSupplyVoltage() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetSupplyVoltage"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetSupplyVoltage();
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = const_cast< ns3::BasicEnergySource* >((const ns3::BasicEnergySource*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetSupplyVoltage", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetSupplyVoltage();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BasicEnergySource::GetSupplyVoltage();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3BasicEnergySource__PythonHelper::UpdateEnergySource()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "UpdateEnergySource"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::BasicEnergySource::UpdateEnergySource();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = (ns3::BasicEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "UpdateEnergySource", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3BasicEnergySource__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = (ns3::BasicEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3BasicEnergySource__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BasicEnergySource *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = (ns3::BasicEnergySource*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BasicEnergySource* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3BasicEnergySource__PythonHelper::GetInstanceTypeId() const
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
PyNs3BasicEnergySource__PythonHelper::NotifyNewAggregate()
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
PyNs3BasicEnergySource__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3BasicEnergySource__tp_init__0(PyNs3BasicEnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BasicEnergySource *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BasicEnergySource_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BasicEnergySource_Type)
    {
        self->obj = new PyNs3BasicEnergySource__PythonHelper(*((PyNs3BasicEnergySource *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergySource__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergySource(*((PyNs3BasicEnergySource *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3BasicEnergySource__tp_init__1(PyNs3BasicEnergySource *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3BasicEnergySource_Type)
    {
        self->obj = new PyNs3BasicEnergySource__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BasicEnergySource__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BasicEnergySource();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3BasicEnergySource__tp_init(PyNs3BasicEnergySource *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3BasicEnergySource__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BasicEnergySource__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3BasicEnergySource_UpdateEnergySource(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    PyNs3BasicEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergySource__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->UpdateEnergySource()) : (self->obj->ns3::BasicEnergySource::UpdateEnergySource());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_GetEnergyUpdateInterval(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetEnergyUpdateInterval();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_GetSupplyVoltage(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3BasicEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetSupplyVoltage()) : (self->obj->ns3::BasicEnergySource::GetSupplyVoltage());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::BasicEnergySource::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_GetEnergyFraction(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3BasicEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetEnergyFraction()) : (self->obj->ns3::BasicEnergySource::GetEnergyFraction());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_GetRemainingEnergy(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3BasicEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetRemainingEnergy()) : (self->obj->ns3::BasicEnergySource::GetRemainingEnergy());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_SetInitialEnergy(PyNs3BasicEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double initialEnergyJ;
    const char *keywords[] = {"initialEnergyJ", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &initialEnergyJ)) {
        return NULL;
    }
    self->obj->SetInitialEnergy(initialEnergyJ);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_SetSupplyVoltage(PyNs3BasicEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double supplyVoltageV;
    const char *keywords[] = {"supplyVoltageV", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &supplyVoltageV)) {
        return NULL;
    }
    self->obj->SetSupplyVoltage(supplyVoltageV);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_SetEnergyUpdateInterval(PyNs3BasicEnergySource *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *interval;
    ns3::Time interval2;
    const char *keywords[] = {"interval", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &interval)) {
        return NULL;
    }
    if (PyObject_IsInstance(interval, (PyObject*) &PyNs3Time_Type)) {
        interval2 = *((PyNs3Time *) interval)->obj;
    } else if (PyObject_IsInstance(interval, (PyObject*) &PyNs3TracedValue__Ns3Time_Type)) {
        interval2 = *((PyNs3TracedValue__Ns3Time *) interval)->obj;
    } else {
    
        PyErr_Format(PyExc_TypeError, "parameter must an instance of one of the types (Time, TracedValue), not %s", Py_TYPE(interval)->tp_name);
        return NULL;
    }
    self->obj->SetEnergyUpdateInterval(interval2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BasicEnergySource_GetInitialEnergy(PyNs3BasicEnergySource *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3BasicEnergySource__PythonHelper *helper_class = dynamic_cast<PyNs3BasicEnergySource__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->GetInitialEnergy()) : (self->obj->ns3::BasicEnergySource::GetInitialEnergy());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3BasicEnergySource__copy__(PyNs3BasicEnergySource *self)
{

    PyNs3BasicEnergySource *py_copy;
    py_copy = PyObject_GC_New(PyNs3BasicEnergySource, &PyNs3BasicEnergySource_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::BasicEnergySource(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BasicEnergySource_methods[] = {
    {(char *) "UpdateEnergySource", (PyCFunction) _wrap_PyNs3BasicEnergySource_UpdateEnergySource, METH_NOARGS, NULL },
    {(char *) "GetEnergyUpdateInterval", (PyCFunction) _wrap_PyNs3BasicEnergySource_GetEnergyUpdateInterval, METH_NOARGS, NULL },
    {(char *) "GetSupplyVoltage", (PyCFunction) _wrap_PyNs3BasicEnergySource_GetSupplyVoltage, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3BasicEnergySource_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetEnergyFraction", (PyCFunction) _wrap_PyNs3BasicEnergySource_GetEnergyFraction, METH_NOARGS, NULL },
    {(char *) "GetRemainingEnergy", (PyCFunction) _wrap_PyNs3BasicEnergySource_GetRemainingEnergy, METH_NOARGS, NULL },
    {(char *) "SetInitialEnergy", (PyCFunction) _wrap_PyNs3BasicEnergySource_SetInitialEnergy, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSupplyVoltage", (PyCFunction) _wrap_PyNs3BasicEnergySource_SetSupplyVoltage, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetEnergyUpdateInterval", (PyCFunction) _wrap_PyNs3BasicEnergySource_SetEnergyUpdateInterval, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInitialEnergy", (PyCFunction) _wrap_PyNs3BasicEnergySource_GetInitialEnergy, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3BasicEnergySource__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3BasicEnergySource__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BasicEnergySource__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3BasicEnergySource__tp_clear(PyNs3BasicEnergySource *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::BasicEnergySource *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3BasicEnergySource__tp_traverse(PyNs3BasicEnergySource *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3BasicEnergySource__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3BasicEnergySource__tp_dealloc(PyNs3BasicEnergySource *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3BasicEnergySource__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BasicEnergySource__tp_richcompare (PyNs3BasicEnergySource *PYBINDGEN_UNUSED(self), PyNs3BasicEnergySource *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BasicEnergySource_Type)) {
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

PyTypeObject PyNs3BasicEnergySource_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "energy.BasicEnergySource",            /* tp_name */
    sizeof(PyNs3BasicEnergySource),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BasicEnergySource__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3BasicEnergySource__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3BasicEnergySource__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BasicEnergySource__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BasicEnergySource_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3BasicEnergySource, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BasicEnergySource__tp_init,             /* tp_init */
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
static struct PyModuleDef energy_moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy",
    NULL,
    -1,
    energy_functions,
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


MOD_INIT(energy)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&energy_moduledef);
    #else
    m = Py_InitModule3((char *) "energy", energy_functions, NULL);
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
    /* Import the 'ns3::TracedValue< double >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TracedValue__Double_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TracedValue__Double");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TracedValue__Double_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TracedValue__Double_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TracedValue__Double_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::TracedValue< ns3::Time >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TracedValue__Ns3Time_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TracedValue__Ns3Time");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TracedValue__Ns3Time_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TracedValue__Ns3Time_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TracedValue__Ns3Time_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
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
    /* Import the 'ns3::DoubleValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3DoubleValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "DoubleValue");
    
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
    /* Import the 'ns3::LogNormalRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3LogNormalRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "LogNormalRandomVariable");
    
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
    PyModule_AddObject(m, (char *) "_PyNs3DeviceEnergyModelContainer_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3DeviceEnergyModelContainer_wrapper_registry, NULL));
    /* Register the 'ns3::DeviceEnergyModelContainer' class */
    if (PyType_Ready(&PyNs3DeviceEnergyModelContainer_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DeviceEnergyModelContainer", (PyObject *) &PyNs3DeviceEnergyModelContainer_Type);
    PyModule_AddObject(m, (char *) "_PyNs3DeviceEnergyModelHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3DeviceEnergyModelHelper_wrapper_registry, NULL));
    /* Register the 'ns3::DeviceEnergyModelHelper' class */
    if (PyType_Ready(&PyNs3DeviceEnergyModelHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DeviceEnergyModelHelper", (PyObject *) &PyNs3DeviceEnergyModelHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3EnergyHarvesterHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3EnergyHarvesterHelper_wrapper_registry, NULL));
    /* Register the 'ns3::EnergyHarvesterHelper' class */
    if (PyType_Ready(&PyNs3EnergyHarvesterHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "EnergyHarvesterHelper", (PyObject *) &PyNs3EnergyHarvesterHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3EnergySourceHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3EnergySourceHelper_wrapper_registry, NULL));
    /* Register the 'ns3::EnergySourceHelper' class */
    if (PyType_Ready(&PyNs3EnergySourceHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "EnergySourceHelper", (PyObject *) &PyNs3EnergySourceHelper_Type);
    /* Register the 'ns3::RvBatteryModelHelper' class */
    PyNs3RvBatteryModelHelper_Type.tp_base = &PyNs3EnergySourceHelper_Type;
    if (PyType_Ready(&PyNs3RvBatteryModelHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RvBatteryModelHelper", (PyObject *) &PyNs3RvBatteryModelHelper_Type);
    /* Register the 'ns3::BasicEnergyHarvesterHelper' class */
    PyNs3BasicEnergyHarvesterHelper_Type.tp_base = &PyNs3EnergyHarvesterHelper_Type;
    if (PyType_Ready(&PyNs3BasicEnergyHarvesterHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BasicEnergyHarvesterHelper", (PyObject *) &PyNs3BasicEnergyHarvesterHelper_Type);
    /* Register the 'ns3::BasicEnergySourceHelper' class */
    PyNs3BasicEnergySourceHelper_Type.tp_base = &PyNs3EnergySourceHelper_Type;
    if (PyType_Ready(&PyNs3BasicEnergySourceHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BasicEnergySourceHelper", (PyObject *) &PyNs3BasicEnergySourceHelper_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::DeviceEnergyModel), &PyNs3DeviceEnergyModel_Type);
    /* Register the 'ns3::DeviceEnergyModel' class */
    PyNs3DeviceEnergyModel_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3DeviceEnergyModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DeviceEnergyModel", (PyObject *) &PyNs3DeviceEnergyModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::EnergyHarvester), &PyNs3EnergyHarvester_Type);
    /* Register the 'ns3::EnergyHarvester' class */
    PyNs3EnergyHarvester_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3EnergyHarvester_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "EnergyHarvester", (PyObject *) &PyNs3EnergyHarvester_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::EnergyHarvesterContainer), &PyNs3EnergyHarvesterContainer_Type);
    /* Register the 'ns3::EnergyHarvesterContainer' class */
    PyNs3EnergyHarvesterContainer_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3EnergyHarvesterContainer_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "EnergyHarvesterContainer", (PyObject *) &PyNs3EnergyHarvesterContainer_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::EnergySource), &PyNs3EnergySource_Type);
    /* Register the 'ns3::EnergySource' class */
    PyNs3EnergySource_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3EnergySource_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "EnergySource", (PyObject *) &PyNs3EnergySource_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::EnergySourceContainer), &PyNs3EnergySourceContainer_Type);
    /* Register the 'ns3::EnergySourceContainer' class */
    PyNs3EnergySourceContainer_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3EnergySourceContainer_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "EnergySourceContainer", (PyObject *) &PyNs3EnergySourceContainer_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LiIonEnergySource), &PyNs3LiIonEnergySource_Type);
    /* Register the 'ns3::LiIonEnergySource' class */
    PyNs3LiIonEnergySource_Type.tp_base = &PyNs3EnergySource_Type;
    if (PyType_Ready(&PyNs3LiIonEnergySource_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LiIonEnergySource", (PyObject *) &PyNs3LiIonEnergySource_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RvBatteryModel), &PyNs3RvBatteryModel_Type);
    /* Register the 'ns3::RvBatteryModel' class */
    PyNs3RvBatteryModel_Type.tp_base = &PyNs3EnergySource_Type;
    if (PyType_Ready(&PyNs3RvBatteryModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RvBatteryModel", (PyObject *) &PyNs3RvBatteryModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::SimpleDeviceEnergyModel), &PyNs3SimpleDeviceEnergyModel_Type);
    /* Register the 'ns3::SimpleDeviceEnergyModel' class */
    PyNs3SimpleDeviceEnergyModel_Type.tp_base = &PyNs3DeviceEnergyModel_Type;
    if (PyType_Ready(&PyNs3SimpleDeviceEnergyModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SimpleDeviceEnergyModel", (PyObject *) &PyNs3SimpleDeviceEnergyModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::BasicEnergyHarvester), &PyNs3BasicEnergyHarvester_Type);
    /* Register the 'ns3::BasicEnergyHarvester' class */
    PyNs3BasicEnergyHarvester_Type.tp_base = &PyNs3EnergyHarvester_Type;
    if (PyType_Ready(&PyNs3BasicEnergyHarvester_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BasicEnergyHarvester", (PyObject *) &PyNs3BasicEnergyHarvester_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::BasicEnergySource), &PyNs3BasicEnergySource_Type);
    /* Register the 'ns3::BasicEnergySource' class */
    PyNs3BasicEnergySource_Type.tp_base = &PyNs3EnergySource_Type;
    if (PyType_Ready(&PyNs3BasicEnergySource_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BasicEnergySource", (PyObject *) &PyNs3BasicEnergySource_Type);
    submodule = initenergy_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initenergy_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initenergy_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    submodule = initenergy_internal();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "internal", submodule);
    return MOD_RETURN(m);
}
