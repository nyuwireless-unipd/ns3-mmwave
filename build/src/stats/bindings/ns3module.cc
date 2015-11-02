#include "ns3module.h"
static PyMethodDef stats_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef stats_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "stats.FatalImpl",
    NULL,
    -1,
    stats_FatalImpl_functions,
};
#endif

static PyObject *
initstats_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&stats_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "stats.FatalImpl", stats_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef stats_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef stats_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "stats.Hash.Function",
    NULL,
    -1,
    stats_Hash_Function_functions,
};
#endif

static PyObject *
initstats_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&stats_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "stats.Hash.Function", stats_Hash_Function_functions, NULL);
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
static PyMethodDef stats_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef stats_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "stats.Hash",
    NULL,
    -1,
    stats_Hash_functions,
};
#endif

static PyObject *
initstats_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&stats_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "stats.Hash", stats_Hash_functions, NULL);
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
    submodule = initstats_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef stats_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef stats_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "stats.TracedValueCallback",
    NULL,
    -1,
    stats_TracedValueCallback_functions,
};
#endif

static PyObject *
initstats_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&stats_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "stats.TracedValueCallback", stats_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef stats_internal_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef stats_internal_moduledef = {
    PyModuleDef_HEAD_INIT,
    "stats.internal",
    NULL,
    -1,
    stats_internal_functions,
};
#endif

static PyObject *
initstats_internal(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&stats_internal_moduledef);
    #else
    m = Py_InitModule3((char *) "stats.internal", stats_internal_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
/* --- module functions --- */


PyObject *
_wrap_stats_isNaN(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    double x;
    const char *keywords[] = {"x", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &x)) {
        return NULL;
    }
    retval = ns3::isNaN(x);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}
PyObject * _wrap_stats_isNaN(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);


PyObject *
_wrap_stats_GetWildcardMatches(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    const char *configPath;
    Py_ssize_t configPath_len;
    std::string configPath_std;
    const char *matchedPath;
    Py_ssize_t matchedPath_len;
    std::string matchedPath_std;
    const char *wildcardSeparator;
    Py_ssize_t wildcardSeparator_len;
    std::string wildcardSeparator_std;
    const char *keywords[] = {"configPath", "matchedPath", "wildcardSeparator", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#", (char **) keywords, &configPath, &configPath_len, &matchedPath, &matchedPath_len, &wildcardSeparator, &wildcardSeparator_len)) {
        return NULL;
    }
    configPath_std = std::string(configPath, configPath_len);
    matchedPath_std = std::string(matchedPath, matchedPath_len);
    wildcardSeparator_std = std::string(wildcardSeparator, wildcardSeparator_len);
    retval = ns3::GetWildcardMatches(configPath_std, matchedPath_std, wildcardSeparator_std);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}
PyObject * _wrap_stats_GetWildcardMatches(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);

static PyMethodDef stats_functions[] = {
    {(char *) "isNaN", (PyCFunction) _wrap_stats_isNaN, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetWildcardMatches", (PyCFunction) _wrap_stats_GetWildcardMatches, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


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


PyTypeObject *_PyNs3ObjectBase_Type;
std::map<void*, PyObject*> *_PyNs3ObjectBase_wrapper_registry;


PyTypeObject *_PyNs3ObjectDeleter_Type;
std::map<void*, PyObject*> *_PyNs3ObjectDeleter_wrapper_registry;


PyTypeObject *_PyNs3ObjectFactory_Type;
std::map<void*, PyObject*> *_PyNs3ObjectFactory_wrapper_registry;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map;


PyTypeObject *_PyNs3Simulator_Type;
std::map<void*, PyObject*> *_PyNs3Simulator_wrapper_registry;


PyTypeObject *_PyNs3TimeWithUnit_Type;
std::map<void*, PyObject*> *_PyNs3TimeWithUnit_wrapper_registry;


PyTypeObject *_PyNs3TracedValue__Bool_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Bool_wrapper_registry;


PyTypeObject *_PyNs3TracedValue__Double_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Double_wrapper_registry;


PyTypeObject *_PyNs3TracedValue__Unsigned_char_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Unsigned_char_wrapper_registry;


PyTypeObject *_PyNs3TracedValue__Unsigned_int_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Unsigned_int_wrapper_registry;


PyTypeObject *_PyNs3TracedValue__Unsigned_short_Type;
std::map<void*, PyObject*> *_PyNs3TracedValue__Unsigned_short_wrapper_registry;


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


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3UintegerValue_Type;


std::map<void*, PyObject*> PyNs3DataOutputCallback_wrapper_registry;

static int
_wrap_PyNs3DataOutputCallback__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'DataOutputCallback' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}


PyObject *
_wrap_PyNs3DataOutputCallback_OutputStatistic(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *variable;
    Py_ssize_t variable_len;
    PyNs3StatisticalSummary *statSum;
    ns3::StatisticalSummary *statSum_ptr;
    const char *keywords[] = {"key", "variable", "statSum", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#O!", (char **) keywords, &key, &key_len, &variable, &variable_len, &PyNs3StatisticalSummary_Type, &statSum)) {
        return NULL;
    }
    statSum_ptr = (statSum ? statSum->obj : NULL);
    self->obj->OutputStatistic(std::string(key, key_len), std::string(variable, variable_len), statSum_ptr);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3DataOutputCallback_OutputSingleton__0(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *variable;
    Py_ssize_t variable_len;
    int val;
    const char *keywords[] = {"key", "variable", "val", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#i", (char **) keywords, &key, &key_len, &variable, &variable_len, &val)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->OutputSingleton(std::string(key, key_len), std::string(variable, variable_len), val);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DataOutputCallback_OutputSingleton__1(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *variable;
    Py_ssize_t variable_len;
    unsigned int val;
    const char *keywords[] = {"key", "variable", "val", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#I", (char **) keywords, &key, &key_len, &variable, &variable_len, &val)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->OutputSingleton(std::string(key, key_len), std::string(variable, variable_len), val);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DataOutputCallback_OutputSingleton__2(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *variable;
    Py_ssize_t variable_len;
    double val;
    const char *keywords[] = {"key", "variable", "val", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#d", (char **) keywords, &key, &key_len, &variable, &variable_len, &val)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->OutputSingleton(std::string(key, key_len), std::string(variable, variable_len), val);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DataOutputCallback_OutputSingleton__3(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *variable;
    Py_ssize_t variable_len;
    const char *val;
    Py_ssize_t val_len;
    const char *keywords[] = {"key", "variable", "val", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#", (char **) keywords, &key, &key_len, &variable, &variable_len, &val, &val_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->OutputSingleton(std::string(key, key_len), std::string(variable, variable_len), std::string(val, val_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DataOutputCallback_OutputSingleton__4(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *variable;
    Py_ssize_t variable_len;
    PyNs3Time *val;
    const char *keywords[] = {"key", "variable", "val", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#O!", (char **) keywords, &key, &key_len, &variable, &variable_len, &PyNs3Time_Type, &val)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->OutputSingleton(std::string(key, key_len), std::string(variable, variable_len), *((PyNs3Time *) val)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3DataOutputCallback_OutputSingleton(PyNs3DataOutputCallback *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3DataOutputCallback_OutputSingleton__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DataOutputCallback_OutputSingleton__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3DataOutputCallback_OutputSingleton__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3DataOutputCallback_OutputSingleton__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3DataOutputCallback_OutputSingleton__4(self, args, kwargs, &exceptions[4]);
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

static PyMethodDef PyNs3DataOutputCallback_methods[] = {
    {(char *) "OutputStatistic", (PyCFunction) _wrap_PyNs3DataOutputCallback_OutputStatistic, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "OutputSingleton", (PyCFunction) _wrap_PyNs3DataOutputCallback_OutputSingleton, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DataOutputCallback__tp_clear(PyNs3DataOutputCallback *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::DataOutputCallback *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3DataOutputCallback__tp_traverse(PyNs3DataOutputCallback *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3DataOutputCallback__tp_dealloc(PyNs3DataOutputCallback *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3DataOutputCallback_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3DataOutputCallback_wrapper_registry.end()) {
        PyNs3DataOutputCallback_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DataOutputCallback__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DataOutputCallback__tp_richcompare (PyNs3DataOutputCallback *PYBINDGEN_UNUSED(self), PyNs3DataOutputCallback *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DataOutputCallback_Type)) {
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

PyTypeObject PyNs3DataOutputCallback_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.DataOutputCallback",            /* tp_name */
    sizeof(PyNs3DataOutputCallback),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DataOutputCallback__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DataOutputCallback__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DataOutputCallback__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DataOutputCallback__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DataOutputCallback_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DataOutputCallback, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DataOutputCallback__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3FileHelper_wrapper_registry;


static int
_wrap_PyNs3FileHelper__tp_init__0(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FileHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FileHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::FileHelper(*((PyNs3FileHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3FileHelper__tp_init__1(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::FileHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3FileHelper__tp_init__2(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *outputFileNameWithoutExtension;
    Py_ssize_t outputFileNameWithoutExtension_len;
    std::string outputFileNameWithoutExtension_std;
    ns3::FileAggregator::FileType fileType = ::ns3::FileAggregator::SPACE_SEPARATED;
    const char *keywords[] = {"outputFileNameWithoutExtension", "fileType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|i", (char **) keywords, &outputFileNameWithoutExtension, &outputFileNameWithoutExtension_len, &fileType)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    outputFileNameWithoutExtension_std = std::string(outputFileNameWithoutExtension, outputFileNameWithoutExtension_len);
    self->obj = new ns3::FileHelper(outputFileNameWithoutExtension_std, fileType);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3FileHelper__tp_init(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3FileHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FileHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3FileHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3FileHelper_Set6dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set6dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_AddAggregator(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *aggregatorName;
    Py_ssize_t aggregatorName_len;
    std::string aggregatorName_std;
    const char *outputFileName;
    Py_ssize_t outputFileName_len;
    std::string outputFileName_std;
    bool onlyOneAggregator;
    PyObject *py_onlyOneAggregator;
    const char *keywords[] = {"aggregatorName", "outputFileName", "onlyOneAggregator", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#O", (char **) keywords, &aggregatorName, &aggregatorName_len, &outputFileName, &outputFileName_len, &py_onlyOneAggregator)) {
        return NULL;
    }
    aggregatorName_std = std::string(aggregatorName, aggregatorName_len);
    outputFileName_std = std::string(outputFileName, outputFileName_len);
    onlyOneAggregator = (bool) PyObject_IsTrue(py_onlyOneAggregator);
    self->obj->AddAggregator(aggregatorName_std, outputFileName_std, onlyOneAggregator);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set10dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set10dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_ConfigureFile(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *outputFileNameWithoutExtension;
    Py_ssize_t outputFileNameWithoutExtension_len;
    std::string outputFileNameWithoutExtension_std;
    ns3::FileAggregator::FileType fileType = ::ns3::FileAggregator::SPACE_SEPARATED;
    const char *keywords[] = {"outputFileNameWithoutExtension", "fileType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|i", (char **) keywords, &outputFileNameWithoutExtension, &outputFileNameWithoutExtension_len, &fileType)) {
        return NULL;
    }
    outputFileNameWithoutExtension_std = std::string(outputFileNameWithoutExtension, outputFileNameWithoutExtension_len);
    self->obj->ConfigureFile(outputFileNameWithoutExtension_std, fileType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set1dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set1dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_GetAggregatorMultiple(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FileAggregator > retval;
    const char *aggregatorName;
    Py_ssize_t aggregatorName_len;
    std::string aggregatorName_std;
    const char *outputFileName;
    Py_ssize_t outputFileName_len;
    std::string outputFileName_std;
    const char *keywords[] = {"aggregatorName", "outputFileName", NULL};
    PyNs3FileAggregator *py_FileAggregator;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &aggregatorName, &aggregatorName_len, &outputFileName, &outputFileName_len)) {
        return NULL;
    }
    aggregatorName_std = std::string(aggregatorName, aggregatorName_len);
    outputFileName_std = std::string(outputFileName, outputFileName_len);
    retval = self->obj->GetAggregatorMultiple(aggregatorName_std, outputFileName_std);
    if (!(const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_FileAggregator = NULL;
    } else {
        py_FileAggregator = (PyNs3FileAggregator *) wrapper_lookup_iter->second;
        Py_INCREF(py_FileAggregator);
    }
    
    if (py_FileAggregator == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval)))), &PyNs3FileAggregator_Type);
        py_FileAggregator = PyObject_GC_New(PyNs3FileAggregator, wrapper_type);
        py_FileAggregator->inst_dict = NULL;
    
        py_FileAggregator->inst_dict = NULL;
        py_FileAggregator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval))->Ref();
        py_FileAggregator->obj = const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_FileAggregator->obj] = (PyObject *) py_FileAggregator;
    }
    py_retval = Py_BuildValue((char *) "N", py_FileAggregator);
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set7dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set7dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_GetAggregatorSingle(PyNs3FileHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::FileAggregator > retval;
    PyNs3FileAggregator *py_FileAggregator;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetAggregatorSingle();
    if (!(const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_FileAggregator = NULL;
    } else {
        py_FileAggregator = (PyNs3FileAggregator *) wrapper_lookup_iter->second;
        Py_INCREF(py_FileAggregator);
    }
    
    if (py_FileAggregator == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval)))), &PyNs3FileAggregator_Type);
        py_FileAggregator = PyObject_GC_New(PyNs3FileAggregator, wrapper_type);
        py_FileAggregator->inst_dict = NULL;
    
        py_FileAggregator->inst_dict = NULL;
        py_FileAggregator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval))->Ref();
        py_FileAggregator->obj = const_cast<ns3::FileAggregator *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_FileAggregator->obj] = (PyObject *) py_FileAggregator;
    }
    py_retval = Py_BuildValue((char *) "N", py_FileAggregator);
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set5dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set5dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_GetProbe(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Probe > retval;
    const char *probeName;
    Py_ssize_t probeName_len;
    const char *keywords[] = {"probeName", NULL};
    PyNs3Probe *py_Probe;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &probeName, &probeName_len)) {
        return NULL;
    }
    retval = self->obj->GetProbe(std::string(probeName, probeName_len));
    if (!(const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Probe__PythonHelper).name())
    {
        py_Probe = reinterpret_cast< PyNs3Probe* >(reinterpret_cast< PyNs3Probe__PythonHelper* >(const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Probe->obj = const_cast<ns3::Probe *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Probe);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Probe *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Probe = NULL;
        } else {
            py_Probe = (PyNs3Probe *) wrapper_lookup_iter->second;
            Py_INCREF(py_Probe);
        }
    
        if (py_Probe == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))), &PyNs3Probe_Type);
            py_Probe = PyObject_GC_New(PyNs3Probe, wrapper_type);
            py_Probe->inst_dict = NULL;
    
            py_Probe->inst_dict = NULL;
            py_Probe->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Probe *> (ns3::PeekPointer (retval))->Ref();
            py_Probe->obj = const_cast<ns3::Probe *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Probe->obj] = (PyObject *) py_Probe;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Probe);
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_WriteProbe(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *typeId;
    Py_ssize_t typeId_len;
    std::string typeId_std;
    const char *path;
    Py_ssize_t path_len;
    std::string path_std;
    const char *probeTraceSource;
    Py_ssize_t probeTraceSource_len;
    std::string probeTraceSource_std;
    const char *keywords[] = {"typeId", "path", "probeTraceSource", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#", (char **) keywords, &typeId, &typeId_len, &path, &path_len, &probeTraceSource, &probeTraceSource_len)) {
        return NULL;
    }
    typeId_std = std::string(typeId, typeId_len);
    path_std = std::string(path, path_len);
    probeTraceSource_std = std::string(probeTraceSource, probeTraceSource_len);
    self->obj->WriteProbe(typeId_std, path_std, probeTraceSource_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set9dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set9dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set8dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set8dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_SetHeading(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *heading;
    Py_ssize_t heading_len;
    std::string heading_std;
    const char *keywords[] = {"heading", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &heading, &heading_len)) {
        return NULL;
    }
    heading_std = std::string(heading, heading_len);
    self->obj->SetHeading(heading_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_AddTimeSeriesAdaptor(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *adaptorName;
    Py_ssize_t adaptorName_len;
    std::string adaptorName_std;
    const char *keywords[] = {"adaptorName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &adaptorName, &adaptorName_len)) {
        return NULL;
    }
    adaptorName_std = std::string(adaptorName, adaptorName_len);
    self->obj->AddTimeSeriesAdaptor(adaptorName_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set2dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set2dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set3dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set3dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileHelper_Set4dFormat(PyNs3FileHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set4dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3FileHelper__copy__(PyNs3FileHelper *self)
{

    PyNs3FileHelper *py_copy;
    py_copy = PyObject_New(PyNs3FileHelper, &PyNs3FileHelper_Type);
    py_copy->obj = new ns3::FileHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3FileHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3FileHelper_methods[] = {
    {(char *) "Set6dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set6dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddAggregator", (PyCFunction) _wrap_PyNs3FileHelper_AddAggregator, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set10dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set10dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConfigureFile", (PyCFunction) _wrap_PyNs3FileHelper_ConfigureFile, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set1dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set1dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAggregatorMultiple", (PyCFunction) _wrap_PyNs3FileHelper_GetAggregatorMultiple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set7dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set7dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAggregatorSingle", (PyCFunction) _wrap_PyNs3FileHelper_GetAggregatorSingle, METH_NOARGS, NULL },
    {(char *) "Set5dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set5dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetProbe", (PyCFunction) _wrap_PyNs3FileHelper_GetProbe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "WriteProbe", (PyCFunction) _wrap_PyNs3FileHelper_WriteProbe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set9dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set9dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set8dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set8dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHeading", (PyCFunction) _wrap_PyNs3FileHelper_SetHeading, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddTimeSeriesAdaptor", (PyCFunction) _wrap_PyNs3FileHelper_AddTimeSeriesAdaptor, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set2dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set2dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set3dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set3dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set4dFormat", (PyCFunction) _wrap_PyNs3FileHelper_Set4dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3FileHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3FileHelper__tp_dealloc(PyNs3FileHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FileHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FileHelper_wrapper_registry.end()) {
        PyNs3FileHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::FileHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FileHelper__tp_richcompare (PyNs3FileHelper *PYBINDGEN_UNUSED(self), PyNs3FileHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FileHelper_Type)) {
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

PyTypeObject PyNs3FileHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.FileHelper",            /* tp_name */
    sizeof(PyNs3FileHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FileHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3FileHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FileHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FileHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Gnuplot_wrapper_registry;


static int
_wrap_PyNs3Gnuplot__tp_init__0(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Gnuplot *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Gnuplot_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Gnuplot(*((PyNs3Gnuplot *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Gnuplot__tp_init__1(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *outputFilename;
    Py_ssize_t outputFilename_len;
    std::string outputFilename_std;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"outputFilename", "title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &outputFilename, &outputFilename_len, &title, &title_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    outputFilename_std = std::string(outputFilename, outputFilename_len);
    title_std = std::string(title, title_len);
    self->obj = new ns3::Gnuplot(outputFilename_std, title_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Gnuplot__tp_init(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Gnuplot__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Gnuplot_SetOutputFilename(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *outputFilename;
    Py_ssize_t outputFilename_len;
    std::string outputFilename_std;
    const char *keywords[] = {"outputFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &outputFilename, &outputFilename_len)) {
        return NULL;
    }
    outputFilename_std = std::string(outputFilename, outputFilename_len);
    self->obj->SetOutputFilename(outputFilename_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_AddDataset(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3GnuplotDataset *dataset;
    const char *keywords[] = {"dataset", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GnuplotDataset_Type, &dataset)) {
        return NULL;
    }
    self->obj->AddDataset(*((PyNs3GnuplotDataset *) dataset)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_SetExtra(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    self->obj->SetExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_DetectTerminal(PyNs3Gnuplot *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    const char *filename;
    Py_ssize_t filename_len;
    std::string filename_std;
    const char *keywords[] = {"filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &filename, &filename_len)) {
        return NULL;
    }
    filename_std = std::string(filename, filename_len);
    retval = ns3::Gnuplot::DetectTerminal(filename_std);
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_AppendExtra(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    self->obj->AppendExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_SetLegend(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *xLegend;
    Py_ssize_t xLegend_len;
    std::string xLegend_std;
    const char *yLegend;
    Py_ssize_t yLegend_len;
    std::string yLegend_std;
    const char *keywords[] = {"xLegend", "yLegend", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &xLegend, &xLegend_len, &yLegend, &yLegend_len)) {
        return NULL;
    }
    xLegend_std = std::string(xLegend, xLegend_len);
    yLegend_std = std::string(yLegend, yLegend_len);
    self->obj->SetLegend(xLegend_std, yLegend_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_SetTerminal(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *terminal;
    Py_ssize_t terminal_len;
    std::string terminal_std;
    const char *keywords[] = {"terminal", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &terminal, &terminal_len)) {
        return NULL;
    }
    terminal_std = std::string(terminal, terminal_len);
    self->obj->SetTerminal(terminal_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_SetDataFileDatasetIndex(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int index;
    const char *keywords[] = {"index", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &index)) {
        return NULL;
    }
    self->obj->SetDataFileDatasetIndex(index);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot_SetTitle(PyNs3Gnuplot *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &title, &title_len)) {
        return NULL;
    }
    title_std = std::string(title, title_len);
    self->obj->SetTitle(title_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Gnuplot__copy__(PyNs3Gnuplot *self)
{

    PyNs3Gnuplot *py_copy;
    py_copy = PyObject_New(PyNs3Gnuplot, &PyNs3Gnuplot_Type);
    py_copy->obj = new ns3::Gnuplot(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Gnuplot_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Gnuplot_methods[] = {
    {(char *) "SetOutputFilename", (PyCFunction) _wrap_PyNs3Gnuplot_SetOutputFilename, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddDataset", (PyCFunction) _wrap_PyNs3Gnuplot_AddDataset, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetExtra", (PyCFunction) _wrap_PyNs3Gnuplot_SetExtra, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DetectTerminal", (PyCFunction) _wrap_PyNs3Gnuplot_DetectTerminal, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "AppendExtra", (PyCFunction) _wrap_PyNs3Gnuplot_AppendExtra, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLegend", (PyCFunction) _wrap_PyNs3Gnuplot_SetLegend, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTerminal", (PyCFunction) _wrap_PyNs3Gnuplot_SetTerminal, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDataFileDatasetIndex", (PyCFunction) _wrap_PyNs3Gnuplot_SetDataFileDatasetIndex, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTitle", (PyCFunction) _wrap_PyNs3Gnuplot_SetTitle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Gnuplot__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Gnuplot__tp_dealloc(PyNs3Gnuplot *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Gnuplot_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Gnuplot_wrapper_registry.end()) {
        PyNs3Gnuplot_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Gnuplot *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Gnuplot__tp_richcompare (PyNs3Gnuplot *PYBINDGEN_UNUSED(self), PyNs3Gnuplot *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Gnuplot_Type)) {
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

PyTypeObject PyNs3Gnuplot_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Gnuplot",            /* tp_name */
    sizeof(PyNs3Gnuplot),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Gnuplot__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Gnuplot__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Gnuplot_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Gnuplot__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3GnuplotCollection_wrapper_registry;


static int
_wrap_PyNs3GnuplotCollection__tp_init__0(PyNs3GnuplotCollection *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GnuplotCollection *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GnuplotCollection_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GnuplotCollection(*((PyNs3GnuplotCollection *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3GnuplotCollection__tp_init__1(PyNs3GnuplotCollection *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *outputFilename;
    Py_ssize_t outputFilename_len;
    std::string outputFilename_std;
    const char *keywords[] = {"outputFilename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &outputFilename, &outputFilename_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    outputFilename_std = std::string(outputFilename, outputFilename_len);
    self->obj = new ns3::GnuplotCollection(outputFilename_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3GnuplotCollection__tp_init(PyNs3GnuplotCollection *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3GnuplotCollection__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GnuplotCollection__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3GnuplotCollection_SetTerminal(PyNs3GnuplotCollection *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *terminal;
    Py_ssize_t terminal_len;
    std::string terminal_std;
    const char *keywords[] = {"terminal", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &terminal, &terminal_len)) {
        return NULL;
    }
    terminal_std = std::string(terminal, terminal_len);
    self->obj->SetTerminal(terminal_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotCollection_AddPlot(PyNs3GnuplotCollection *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Gnuplot *plot;
    const char *keywords[] = {"plot", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Gnuplot_Type, &plot)) {
        return NULL;
    }
    self->obj->AddPlot(*((PyNs3Gnuplot *) plot)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotCollection_GetPlot(PyNs3GnuplotCollection *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int id;
    const char *keywords[] = {"id", NULL};
    PyNs3Gnuplot *py_Gnuplot;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &id)) {
        return NULL;
    }
    ns3::Gnuplot & retval = self->obj->GetPlot(id);
    py_Gnuplot = PyObject_New(PyNs3Gnuplot, &PyNs3Gnuplot_Type);
    py_Gnuplot->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Gnuplot->obj = new ns3::Gnuplot(retval);
    PyNs3Gnuplot_wrapper_registry[(void *) py_Gnuplot->obj] = (PyObject *) py_Gnuplot;
    py_retval = Py_BuildValue((char *) "N", py_Gnuplot);
    return py_retval;
}


static PyObject*
_wrap_PyNs3GnuplotCollection__copy__(PyNs3GnuplotCollection *self)
{

    PyNs3GnuplotCollection *py_copy;
    py_copy = PyObject_New(PyNs3GnuplotCollection, &PyNs3GnuplotCollection_Type);
    py_copy->obj = new ns3::GnuplotCollection(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotCollection_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GnuplotCollection_methods[] = {
    {(char *) "SetTerminal", (PyCFunction) _wrap_PyNs3GnuplotCollection_SetTerminal, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddPlot", (PyCFunction) _wrap_PyNs3GnuplotCollection_AddPlot, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPlot", (PyCFunction) _wrap_PyNs3GnuplotCollection_GetPlot, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GnuplotCollection__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GnuplotCollection__tp_dealloc(PyNs3GnuplotCollection *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotCollection_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotCollection_wrapper_registry.end()) {
        PyNs3GnuplotCollection_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GnuplotCollection *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GnuplotCollection__tp_richcompare (PyNs3GnuplotCollection *PYBINDGEN_UNUSED(self), PyNs3GnuplotCollection *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GnuplotCollection_Type)) {
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

PyTypeObject PyNs3GnuplotCollection_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.GnuplotCollection",            /* tp_name */
    sizeof(PyNs3GnuplotCollection),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GnuplotCollection__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3GnuplotCollection__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GnuplotCollection_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GnuplotCollection__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3GnuplotDataset_wrapper_registry;

static int
_wrap_PyNs3GnuplotDataset__tp_init(PyNs3GnuplotDataset *self, PyObject *args, PyObject *kwargs)
{
    PyNs3GnuplotDataset *original;
    const char *keywords[] = {"original", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GnuplotDataset_Type, &original)) {
        return -1;
    }
    self->obj = new ns3::GnuplotDataset(*((PyNs3GnuplotDataset *) original)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3GnuplotDataset_SetExtra(PyNs3GnuplotDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    self->obj->SetExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotDataset_SetDefaultExtra(PyNs3GnuplotDataset *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    ns3::GnuplotDataset::SetDefaultExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotDataset_SetTitle(PyNs3GnuplotDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &title, &title_len)) {
        return NULL;
    }
    title_std = std::string(title, title_len);
    self->obj->SetTitle(title_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3GnuplotDataset__copy__(PyNs3GnuplotDataset *self)
{

    PyNs3GnuplotDataset *py_copy;
    py_copy = PyObject_New(PyNs3GnuplotDataset, &PyNs3GnuplotDataset_Type);
    py_copy->obj = new ns3::GnuplotDataset(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotDataset_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GnuplotDataset_methods[] = {
    {(char *) "SetExtra", (PyCFunction) _wrap_PyNs3GnuplotDataset_SetExtra, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultExtra", (PyCFunction) _wrap_PyNs3GnuplotDataset_SetDefaultExtra, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetTitle", (PyCFunction) _wrap_PyNs3GnuplotDataset_SetTitle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GnuplotDataset__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GnuplotDataset__tp_dealloc(PyNs3GnuplotDataset *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotDataset_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotDataset_wrapper_registry.end()) {
        PyNs3GnuplotDataset_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GnuplotDataset *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GnuplotDataset__tp_richcompare (PyNs3GnuplotDataset *PYBINDGEN_UNUSED(self), PyNs3GnuplotDataset *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GnuplotDataset_Type)) {
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

PyTypeObject PyNs3GnuplotDataset_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.GnuplotDataset",            /* tp_name */
    sizeof(PyNs3GnuplotDataset),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GnuplotDataset__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3GnuplotDataset__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GnuplotDataset_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GnuplotDataset__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3GnuplotHelper_wrapper_registry;


static int
_wrap_PyNs3GnuplotHelper__tp_init__0(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GnuplotHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GnuplotHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GnuplotHelper(*((PyNs3GnuplotHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3GnuplotHelper__tp_init__1(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::GnuplotHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3GnuplotHelper__tp_init__2(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *outputFileNameWithoutExtension;
    Py_ssize_t outputFileNameWithoutExtension_len;
    std::string outputFileNameWithoutExtension_std;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *xLegend;
    Py_ssize_t xLegend_len;
    std::string xLegend_std;
    const char *yLegend;
    Py_ssize_t yLegend_len;
    std::string yLegend_std;
    const char *terminalType;
    Py_ssize_t terminalType_len;
    std::string terminalType_std;
    const char *keywords[] = {"outputFileNameWithoutExtension", "title", "xLegend", "yLegend", "terminalType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#s#", (char **) keywords, &outputFileNameWithoutExtension, &outputFileNameWithoutExtension_len, &title, &title_len, &xLegend, &xLegend_len, &yLegend, &yLegend_len, &terminalType, &terminalType_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    outputFileNameWithoutExtension_std = std::string(outputFileNameWithoutExtension, outputFileNameWithoutExtension_len);
    title_std = std::string(title, title_len);
    xLegend_std = std::string(xLegend, xLegend_len);
    yLegend_std = std::string(yLegend, yLegend_len);
    terminalType_std = std::string(terminalType, terminalType_len);
    self->obj = new ns3::GnuplotHelper(outputFileNameWithoutExtension_std, title_std, xLegend_std, yLegend_std, terminalType_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3GnuplotHelper__tp_init(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3GnuplotHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GnuplotHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3GnuplotHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3GnuplotHelper_PlotProbe(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *typeId;
    Py_ssize_t typeId_len;
    std::string typeId_std;
    const char *path;
    Py_ssize_t path_len;
    std::string path_std;
    const char *probeTraceSource;
    Py_ssize_t probeTraceSource_len;
    std::string probeTraceSource_std;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    ns3::GnuplotAggregator::KeyLocation keyLocation = ::ns3::GnuplotAggregator::KEY_INSIDE;
    const char *keywords[] = {"typeId", "path", "probeTraceSource", "title", "keyLocation", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#|i", (char **) keywords, &typeId, &typeId_len, &path, &path_len, &probeTraceSource, &probeTraceSource_len, &title, &title_len, &keyLocation)) {
        return NULL;
    }
    typeId_std = std::string(typeId, typeId_len);
    path_std = std::string(path, path_len);
    probeTraceSource_std = std::string(probeTraceSource, probeTraceSource_len);
    title_std = std::string(title, title_len);
    self->obj->PlotProbe(typeId_std, path_std, probeTraceSource_std, title_std, keyLocation);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotHelper_ConfigurePlot(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *outputFileNameWithoutExtension;
    Py_ssize_t outputFileNameWithoutExtension_len;
    std::string outputFileNameWithoutExtension_std;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *xLegend;
    Py_ssize_t xLegend_len;
    std::string xLegend_std;
    const char *yLegend;
    Py_ssize_t yLegend_len;
    std::string yLegend_std;
    const char *terminalType;
    Py_ssize_t terminalType_len;
    std::string terminalType_std;
    const char *keywords[] = {"outputFileNameWithoutExtension", "title", "xLegend", "yLegend", "terminalType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#s#", (char **) keywords, &outputFileNameWithoutExtension, &outputFileNameWithoutExtension_len, &title, &title_len, &xLegend, &xLegend_len, &yLegend, &yLegend_len, &terminalType, &terminalType_len)) {
        return NULL;
    }
    outputFileNameWithoutExtension_std = std::string(outputFileNameWithoutExtension, outputFileNameWithoutExtension_len);
    title_std = std::string(title, title_len);
    xLegend_std = std::string(xLegend, xLegend_len);
    yLegend_std = std::string(yLegend, yLegend_len);
    terminalType_std = std::string(terminalType, terminalType_len);
    self->obj->ConfigurePlot(outputFileNameWithoutExtension_std, title_std, xLegend_std, yLegend_std, terminalType_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotHelper_GetAggregator(PyNs3GnuplotHelper *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::GnuplotAggregator > retval;
    PyNs3GnuplotAggregator *py_GnuplotAggregator;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetAggregator();
    if (!(const_cast<ns3::GnuplotAggregator *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::GnuplotAggregator *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_GnuplotAggregator = NULL;
    } else {
        py_GnuplotAggregator = (PyNs3GnuplotAggregator *) wrapper_lookup_iter->second;
        Py_INCREF(py_GnuplotAggregator);
    }
    
    if (py_GnuplotAggregator == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::GnuplotAggregator *> (ns3::PeekPointer (retval)))), &PyNs3GnuplotAggregator_Type);
        py_GnuplotAggregator = PyObject_GC_New(PyNs3GnuplotAggregator, wrapper_type);
        py_GnuplotAggregator->inst_dict = NULL;
    
        py_GnuplotAggregator->inst_dict = NULL;
        py_GnuplotAggregator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::GnuplotAggregator *> (ns3::PeekPointer (retval))->Ref();
        py_GnuplotAggregator->obj = const_cast<ns3::GnuplotAggregator *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_GnuplotAggregator->obj] = (PyObject *) py_GnuplotAggregator;
    }
    py_retval = Py_BuildValue((char *) "N", py_GnuplotAggregator);
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotHelper_AddTimeSeriesAdaptor(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *adaptorName;
    Py_ssize_t adaptorName_len;
    std::string adaptorName_std;
    const char *keywords[] = {"adaptorName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &adaptorName, &adaptorName_len)) {
        return NULL;
    }
    adaptorName_std = std::string(adaptorName, adaptorName_len);
    self->obj->AddTimeSeriesAdaptor(adaptorName_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotHelper_GetProbe(PyNs3GnuplotHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Probe > retval;
    const char *probeName;
    Py_ssize_t probeName_len;
    const char *keywords[] = {"probeName", NULL};
    PyNs3Probe *py_Probe;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &probeName, &probeName_len)) {
        return NULL;
    }
    retval = self->obj->GetProbe(std::string(probeName, probeName_len));
    if (!(const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3Probe__PythonHelper).name())
    {
        py_Probe = reinterpret_cast< PyNs3Probe* >(reinterpret_cast< PyNs3Probe__PythonHelper* >(const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))->m_pyself);
        py_Probe->obj = const_cast<ns3::Probe *> (ns3::PeekPointer (retval));
        Py_INCREF(py_Probe);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Probe *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_Probe = NULL;
        } else {
            py_Probe = (PyNs3Probe *) wrapper_lookup_iter->second;
            Py_INCREF(py_Probe);
        }
    
        if (py_Probe == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Probe *> (ns3::PeekPointer (retval)))), &PyNs3Probe_Type);
            py_Probe = PyObject_GC_New(PyNs3Probe, wrapper_type);
            py_Probe->inst_dict = NULL;
    
            py_Probe->inst_dict = NULL;
            py_Probe->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::Probe *> (ns3::PeekPointer (retval))->Ref();
            py_Probe->obj = const_cast<ns3::Probe *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_Probe->obj] = (PyObject *) py_Probe;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_Probe);
    return py_retval;
}


static PyObject*
_wrap_PyNs3GnuplotHelper__copy__(PyNs3GnuplotHelper *self)
{

    PyNs3GnuplotHelper *py_copy;
    py_copy = PyObject_New(PyNs3GnuplotHelper, &PyNs3GnuplotHelper_Type);
    py_copy->obj = new ns3::GnuplotHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GnuplotHelper_methods[] = {
    {(char *) "PlotProbe", (PyCFunction) _wrap_PyNs3GnuplotHelper_PlotProbe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConfigurePlot", (PyCFunction) _wrap_PyNs3GnuplotHelper_ConfigurePlot, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAggregator", (PyCFunction) _wrap_PyNs3GnuplotHelper_GetAggregator, METH_NOARGS, NULL },
    {(char *) "AddTimeSeriesAdaptor", (PyCFunction) _wrap_PyNs3GnuplotHelper_AddTimeSeriesAdaptor, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetProbe", (PyCFunction) _wrap_PyNs3GnuplotHelper_GetProbe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GnuplotHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GnuplotHelper__tp_dealloc(PyNs3GnuplotHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotHelper_wrapper_registry.end()) {
        PyNs3GnuplotHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GnuplotHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GnuplotHelper__tp_richcompare (PyNs3GnuplotHelper *PYBINDGEN_UNUSED(self), PyNs3GnuplotHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GnuplotHelper_Type)) {
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

PyTypeObject PyNs3GnuplotHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.GnuplotHelper",            /* tp_name */
    sizeof(PyNs3GnuplotHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GnuplotHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3GnuplotHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GnuplotHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GnuplotHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3StatisticalSummary_wrapper_registry;

long int
PyNs3StatisticalSummary__PythonHelper::getCount() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    long int retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getCount"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getCount", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "l", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getMax() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getMax"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getMax", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getMean() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getMean"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getMean", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getMin() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getMin"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getMin", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getSqrSum() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getSqrSum"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getSqrSum", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getStddev() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getStddev"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getStddev", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getSum() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getSum"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getSum", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3StatisticalSummary__PythonHelper::getVariance() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::StatisticalSummary *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getVariance"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj;
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = const_cast< ns3::StatisticalSummary* >((const ns3::StatisticalSummary*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getVariance", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3StatisticalSummary* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}


static int
_wrap_PyNs3StatisticalSummary__tp_init__0(PyNs3StatisticalSummary *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3StatisticalSummary_Type)
    {
        self->obj = new PyNs3StatisticalSummary__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3StatisticalSummary__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'StatisticalSummary' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3StatisticalSummary__tp_init__1(PyNs3StatisticalSummary *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3StatisticalSummary *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3StatisticalSummary_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3StatisticalSummary_Type)
    {
        self->obj = new PyNs3StatisticalSummary__PythonHelper(*((PyNs3StatisticalSummary *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3StatisticalSummary__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'StatisticalSummary' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3StatisticalSummary__tp_init(PyNs3StatisticalSummary *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3StatisticalSummary__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3StatisticalSummary__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3StatisticalSummary_getMin(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getMin();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getVariance(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getVariance();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getMean(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getMean();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getSum(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getSum();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getStddev(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getStddev();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getSqrSum(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getSqrSum();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getMax(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->getMax();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3StatisticalSummary_getCount(PyNs3StatisticalSummary *self)
{
    PyObject *py_retval;
    long int retval;
    
    retval = self->obj->getCount();
    py_retval = Py_BuildValue((char *) "l", retval);
    return py_retval;
}

static PyMethodDef PyNs3StatisticalSummary_methods[] = {
    {(char *) "getMin", (PyCFunction) _wrap_PyNs3StatisticalSummary_getMin, METH_NOARGS, NULL },
    {(char *) "getVariance", (PyCFunction) _wrap_PyNs3StatisticalSummary_getVariance, METH_NOARGS, NULL },
    {(char *) "getMean", (PyCFunction) _wrap_PyNs3StatisticalSummary_getMean, METH_NOARGS, NULL },
    {(char *) "getSum", (PyCFunction) _wrap_PyNs3StatisticalSummary_getSum, METH_NOARGS, NULL },
    {(char *) "getStddev", (PyCFunction) _wrap_PyNs3StatisticalSummary_getStddev, METH_NOARGS, NULL },
    {(char *) "getSqrSum", (PyCFunction) _wrap_PyNs3StatisticalSummary_getSqrSum, METH_NOARGS, NULL },
    {(char *) "getMax", (PyCFunction) _wrap_PyNs3StatisticalSummary_getMax, METH_NOARGS, NULL },
    {(char *) "getCount", (PyCFunction) _wrap_PyNs3StatisticalSummary_getCount, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3StatisticalSummary__tp_clear(PyNs3StatisticalSummary *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::StatisticalSummary *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3StatisticalSummary__tp_traverse(PyNs3StatisticalSummary *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3StatisticalSummary__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3StatisticalSummary__tp_dealloc(PyNs3StatisticalSummary *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3StatisticalSummary_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3StatisticalSummary_wrapper_registry.end()) {
        PyNs3StatisticalSummary_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3StatisticalSummary__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3StatisticalSummary__tp_richcompare (PyNs3StatisticalSummary *PYBINDGEN_UNUSED(self), PyNs3StatisticalSummary *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3StatisticalSummary_Type)) {
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

PyTypeObject PyNs3StatisticalSummary_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.StatisticalSummary",            /* tp_name */
    sizeof(PyNs3StatisticalSummary),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3StatisticalSummary__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3StatisticalSummary__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3StatisticalSummary__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3StatisticalSummary__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3StatisticalSummary_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3StatisticalSummary, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3StatisticalSummary__tp_init,             /* tp_init */
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
_wrap_PyNs3Gnuplot2dDataset__tp_init__0(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Gnuplot2dDataset *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Gnuplot2dDataset_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Gnuplot2dDataset(*((PyNs3Gnuplot2dDataset *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Gnuplot2dDataset__tp_init__1(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &title, &title_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    title_std = std::string(title, title_len);
    self->obj = new ns3::Gnuplot2dDataset(title_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Gnuplot2dDataset__tp_init(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Gnuplot2dDataset__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot2dDataset__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Gnuplot2dDataset_AddEmptyLine(PyNs3Gnuplot2dDataset *self)
{
    PyObject *py_retval;
    
    self->obj->AddEmptyLine();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot2dDataset_SetDefaultErrorBars(PyNs3Gnuplot2dDataset *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Gnuplot2dDataset::ErrorBars errorBars;
    const char *keywords[] = {"errorBars", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &errorBars)) {
        return NULL;
    }
    ns3::Gnuplot2dDataset::SetDefaultErrorBars(errorBars);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot2dDataset_SetStyle(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Gnuplot2dDataset::Style style;
    const char *keywords[] = {"style", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &style)) {
        return NULL;
    }
    self->obj->SetStyle(style);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot2dDataset_SetErrorBars(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Gnuplot2dDataset::ErrorBars errorBars;
    const char *keywords[] = {"errorBars", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &errorBars)) {
        return NULL;
    }
    self->obj->SetErrorBars(errorBars);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3Gnuplot2dDataset_Add__0(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    double x;
    double y;
    const char *keywords[] = {"x", "y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dd", (char **) keywords, &x, &y)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(x, y);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Gnuplot2dDataset_Add__1(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    double x;
    double y;
    double errorDelta;
    const char *keywords[] = {"x", "y", "errorDelta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ddd", (char **) keywords, &x, &y, &errorDelta)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(x, y, errorDelta);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Gnuplot2dDataset_Add__2(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    double x;
    double y;
    double xErrorDelta;
    double yErrorDelta;
    const char *keywords[] = {"x", "y", "xErrorDelta", "yErrorDelta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddd", (char **) keywords, &x, &y, &xErrorDelta, &yErrorDelta)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Add(x, y, xErrorDelta, yErrorDelta);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Gnuplot2dDataset_Add(PyNs3Gnuplot2dDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Gnuplot2dDataset_Add__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot2dDataset_Add__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot2dDataset_Add__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Gnuplot2dDataset_SetDefaultStyle(PyNs3Gnuplot2dDataset *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Gnuplot2dDataset::Style style;
    const char *keywords[] = {"style", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &style)) {
        return NULL;
    }
    ns3::Gnuplot2dDataset::SetDefaultStyle(style);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Gnuplot2dDataset__copy__(PyNs3Gnuplot2dDataset *self)
{

    PyNs3Gnuplot2dDataset *py_copy;
    py_copy = PyObject_New(PyNs3Gnuplot2dDataset, &PyNs3Gnuplot2dDataset_Type);
    py_copy->obj = new ns3::Gnuplot2dDataset(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotDataset_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Gnuplot2dDataset_methods[] = {
    {(char *) "AddEmptyLine", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset_AddEmptyLine, METH_NOARGS, NULL },
    {(char *) "SetDefaultErrorBars", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset_SetDefaultErrorBars, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetStyle", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset_SetStyle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetErrorBars", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset_SetErrorBars, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Add", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset_Add, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDefaultStyle", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset_SetDefaultStyle, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Gnuplot2dDataset__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Gnuplot2dDataset__tp_dealloc(PyNs3Gnuplot2dDataset *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotDataset_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotDataset_wrapper_registry.end()) {
        PyNs3GnuplotDataset_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Gnuplot2dDataset *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Gnuplot2dDataset__tp_richcompare (PyNs3Gnuplot2dDataset *PYBINDGEN_UNUSED(self), PyNs3Gnuplot2dDataset *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Gnuplot2dDataset_Type)) {
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

PyTypeObject PyNs3Gnuplot2dDataset_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Gnuplot2dDataset",            /* tp_name */
    sizeof(PyNs3Gnuplot2dDataset),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Gnuplot2dDataset__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Gnuplot2dDataset__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Gnuplot2dDataset_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Gnuplot2dDataset__tp_init,             /* tp_init */
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
_wrap_PyNs3Gnuplot2dFunction__tp_init__0(PyNs3Gnuplot2dFunction *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Gnuplot2dFunction *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Gnuplot2dFunction_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Gnuplot2dFunction(*((PyNs3Gnuplot2dFunction *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Gnuplot2dFunction__tp_init__1(PyNs3Gnuplot2dFunction *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *function;
    Py_ssize_t function_len;
    std::string function_std;
    const char *keywords[] = {"title", "function", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &title, &title_len, &function, &function_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    title_std = std::string(title, title_len);
    function_std = std::string(function, function_len);
    self->obj = new ns3::Gnuplot2dFunction(title_std, function_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Gnuplot2dFunction__tp_init(PyNs3Gnuplot2dFunction *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Gnuplot2dFunction__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot2dFunction__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Gnuplot2dFunction_SetFunction(PyNs3Gnuplot2dFunction *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *function;
    Py_ssize_t function_len;
    std::string function_std;
    const char *keywords[] = {"function", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &function, &function_len)) {
        return NULL;
    }
    function_std = std::string(function, function_len);
    self->obj->SetFunction(function_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Gnuplot2dFunction__copy__(PyNs3Gnuplot2dFunction *self)
{

    PyNs3Gnuplot2dFunction *py_copy;
    py_copy = PyObject_New(PyNs3Gnuplot2dFunction, &PyNs3Gnuplot2dFunction_Type);
    py_copy->obj = new ns3::Gnuplot2dFunction(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotDataset_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Gnuplot2dFunction_methods[] = {
    {(char *) "SetFunction", (PyCFunction) _wrap_PyNs3Gnuplot2dFunction_SetFunction, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Gnuplot2dFunction__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Gnuplot2dFunction__tp_dealloc(PyNs3Gnuplot2dFunction *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotDataset_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotDataset_wrapper_registry.end()) {
        PyNs3GnuplotDataset_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Gnuplot2dFunction *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Gnuplot2dFunction__tp_richcompare (PyNs3Gnuplot2dFunction *PYBINDGEN_UNUSED(self), PyNs3Gnuplot2dFunction *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Gnuplot2dFunction_Type)) {
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

PyTypeObject PyNs3Gnuplot2dFunction_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Gnuplot2dFunction",            /* tp_name */
    sizeof(PyNs3Gnuplot2dFunction),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Gnuplot2dFunction__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Gnuplot2dFunction__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Gnuplot2dFunction_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Gnuplot2dFunction__tp_init,             /* tp_init */
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
_wrap_PyNs3Gnuplot3dDataset__tp_init__0(PyNs3Gnuplot3dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Gnuplot3dDataset *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Gnuplot3dDataset_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Gnuplot3dDataset(*((PyNs3Gnuplot3dDataset *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Gnuplot3dDataset__tp_init__1(PyNs3Gnuplot3dDataset *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &title, &title_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    title_std = std::string(title, title_len);
    self->obj = new ns3::Gnuplot3dDataset(title_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Gnuplot3dDataset__tp_init(PyNs3Gnuplot3dDataset *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Gnuplot3dDataset__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot3dDataset__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Gnuplot3dDataset_Add(PyNs3Gnuplot3dDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double x;
    double y;
    double z;
    const char *keywords[] = {"x", "y", "z", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ddd", (char **) keywords, &x, &y, &z)) {
        return NULL;
    }
    self->obj->Add(x, y, z);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot3dDataset_SetStyle(PyNs3Gnuplot3dDataset *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *style;
    Py_ssize_t style_len;
    std::string style_std;
    const char *keywords[] = {"style", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &style, &style_len)) {
        return NULL;
    }
    style_std = std::string(style, style_len);
    self->obj->SetStyle(style_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot3dDataset_AddEmptyLine(PyNs3Gnuplot3dDataset *self)
{
    PyObject *py_retval;
    
    self->obj->AddEmptyLine();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Gnuplot3dDataset_SetDefaultStyle(PyNs3Gnuplot3dDataset *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *style;
    Py_ssize_t style_len;
    std::string style_std;
    const char *keywords[] = {"style", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &style, &style_len)) {
        return NULL;
    }
    style_std = std::string(style, style_len);
    ns3::Gnuplot3dDataset::SetDefaultStyle(style_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Gnuplot3dDataset__copy__(PyNs3Gnuplot3dDataset *self)
{

    PyNs3Gnuplot3dDataset *py_copy;
    py_copy = PyObject_New(PyNs3Gnuplot3dDataset, &PyNs3Gnuplot3dDataset_Type);
    py_copy->obj = new ns3::Gnuplot3dDataset(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotDataset_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Gnuplot3dDataset_methods[] = {
    {(char *) "Add", (PyCFunction) _wrap_PyNs3Gnuplot3dDataset_Add, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetStyle", (PyCFunction) _wrap_PyNs3Gnuplot3dDataset_SetStyle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddEmptyLine", (PyCFunction) _wrap_PyNs3Gnuplot3dDataset_AddEmptyLine, METH_NOARGS, NULL },
    {(char *) "SetDefaultStyle", (PyCFunction) _wrap_PyNs3Gnuplot3dDataset_SetDefaultStyle, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Gnuplot3dDataset__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Gnuplot3dDataset__tp_dealloc(PyNs3Gnuplot3dDataset *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotDataset_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotDataset_wrapper_registry.end()) {
        PyNs3GnuplotDataset_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Gnuplot3dDataset *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Gnuplot3dDataset__tp_richcompare (PyNs3Gnuplot3dDataset *PYBINDGEN_UNUSED(self), PyNs3Gnuplot3dDataset *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Gnuplot3dDataset_Type)) {
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

PyTypeObject PyNs3Gnuplot3dDataset_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Gnuplot3dDataset",            /* tp_name */
    sizeof(PyNs3Gnuplot3dDataset),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Gnuplot3dDataset__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Gnuplot3dDataset__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Gnuplot3dDataset_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Gnuplot3dDataset__tp_init,             /* tp_init */
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
_wrap_PyNs3Gnuplot3dFunction__tp_init__0(PyNs3Gnuplot3dFunction *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Gnuplot3dFunction *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Gnuplot3dFunction_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Gnuplot3dFunction(*((PyNs3Gnuplot3dFunction *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Gnuplot3dFunction__tp_init__1(PyNs3Gnuplot3dFunction *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *function;
    Py_ssize_t function_len;
    std::string function_std;
    const char *keywords[] = {"title", "function", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &title, &title_len, &function, &function_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    title_std = std::string(title, title_len);
    function_std = std::string(function, function_len);
    self->obj = new ns3::Gnuplot3dFunction(title_std, function_std);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Gnuplot3dFunction__tp_init(PyNs3Gnuplot3dFunction *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Gnuplot3dFunction__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Gnuplot3dFunction__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Gnuplot3dFunction_SetFunction(PyNs3Gnuplot3dFunction *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *function;
    Py_ssize_t function_len;
    std::string function_std;
    const char *keywords[] = {"function", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &function, &function_len)) {
        return NULL;
    }
    function_std = std::string(function, function_len);
    self->obj->SetFunction(function_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Gnuplot3dFunction__copy__(PyNs3Gnuplot3dFunction *self)
{

    PyNs3Gnuplot3dFunction *py_copy;
    py_copy = PyObject_New(PyNs3Gnuplot3dFunction, &PyNs3Gnuplot3dFunction_Type);
    py_copy->obj = new ns3::Gnuplot3dFunction(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GnuplotDataset_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Gnuplot3dFunction_methods[] = {
    {(char *) "SetFunction", (PyCFunction) _wrap_PyNs3Gnuplot3dFunction_SetFunction, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Gnuplot3dFunction__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Gnuplot3dFunction__tp_dealloc(PyNs3Gnuplot3dFunction *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GnuplotDataset_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GnuplotDataset_wrapper_registry.end()) {
        PyNs3GnuplotDataset_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Gnuplot3dFunction *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Gnuplot3dFunction__tp_richcompare (PyNs3Gnuplot3dFunction *PYBINDGEN_UNUSED(self), PyNs3Gnuplot3dFunction *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Gnuplot3dFunction_Type)) {
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

PyTypeObject PyNs3Gnuplot3dFunction_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Gnuplot3dFunction",            /* tp_name */
    sizeof(PyNs3Gnuplot3dFunction),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Gnuplot3dFunction__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Gnuplot3dFunction__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Gnuplot3dFunction_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Gnuplot3dFunction__tp_init,             /* tp_init */
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
_wrap_PyNs3DataCalculator__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'DataCalculator' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}


PyObject *
_wrap_PyNs3DataCalculator_Enable(PyNs3DataCalculator *self)
{
    PyObject *py_retval;
    
    self->obj->Enable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::DataCalculator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_Stop(PyNs3DataCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *stopTime;
    const char *keywords[] = {"stopTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &stopTime)) {
        return NULL;
    }
    self->obj->Stop(*((PyNs3Time *) stopTime)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_GetKey(PyNs3DataCalculator *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetKey();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_Start(PyNs3DataCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *startTime;
    const char *keywords[] = {"startTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &startTime)) {
        return NULL;
    }
    self->obj->Start(*((PyNs3Time *) startTime)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_SetKey(PyNs3DataCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *keywords[] = {"key", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &key, &key_len)) {
        return NULL;
    }
    self->obj->SetKey(std::string(key, key_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_Disable(PyNs3DataCalculator *self)
{
    PyObject *py_retval;
    
    self->obj->Disable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_GetEnabled(PyNs3DataCalculator *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetEnabled();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_Output(PyNs3DataCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataOutputCallback *callback;
    const char *keywords[] = {"callback", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataOutputCallback_Type, &callback)) {
        return NULL;
    }
    self->obj->Output(*((PyNs3DataOutputCallback *) callback)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_GetContext(PyNs3DataCalculator *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetContext();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCalculator_SetContext(PyNs3DataCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    const char *keywords[] = {"context", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &context, &context_len)) {
        return NULL;
    }
    self->obj->SetContext(std::string(context, context_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3DataCalculator_methods[] = {
    {(char *) "Enable", (PyCFunction) _wrap_PyNs3DataCalculator_Enable, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3DataCalculator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Stop", (PyCFunction) _wrap_PyNs3DataCalculator_Stop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetKey", (PyCFunction) _wrap_PyNs3DataCalculator_GetKey, METH_NOARGS, NULL },
    {(char *) "Start", (PyCFunction) _wrap_PyNs3DataCalculator_Start, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetKey", (PyCFunction) _wrap_PyNs3DataCalculator_SetKey, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Disable", (PyCFunction) _wrap_PyNs3DataCalculator_Disable, METH_NOARGS, NULL },
    {(char *) "GetEnabled", (PyCFunction) _wrap_PyNs3DataCalculator_GetEnabled, METH_NOARGS, NULL },
    {(char *) "Output", (PyCFunction) _wrap_PyNs3DataCalculator_Output, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetContext", (PyCFunction) _wrap_PyNs3DataCalculator_GetContext, METH_NOARGS, NULL },
    {(char *) "SetContext", (PyCFunction) _wrap_PyNs3DataCalculator_SetContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DataCalculator__tp_clear(PyNs3DataCalculator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::DataCalculator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3DataCalculator__tp_traverse(PyNs3DataCalculator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3DataCalculator__tp_dealloc(PyNs3DataCalculator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DataCalculator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DataCalculator__tp_richcompare (PyNs3DataCalculator *PYBINDGEN_UNUSED(self), PyNs3DataCalculator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DataCalculator_Type)) {
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

PyTypeObject PyNs3DataCalculator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.DataCalculator",            /* tp_name */
    sizeof(PyNs3DataCalculator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DataCalculator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DataCalculator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DataCalculator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DataCalculator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DataCalculator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DataCalculator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DataCalculator__tp_init,             /* tp_init */
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
PyNs3DataCollectionObject__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    PyNs3DataCollectionObject__PythonHelper *helper = dynamic_cast< PyNs3DataCollectionObject__PythonHelper* >(self->obj);
    
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
PyNs3DataCollectionObject__PythonHelper::_wrap_DoInitialize(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    PyNs3DataCollectionObject__PythonHelper *helper = dynamic_cast< PyNs3DataCollectionObject__PythonHelper* >(self->obj);
    
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
PyNs3DataCollectionObject__PythonHelper::_wrap_NotifyNewAggregate(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    PyNs3DataCollectionObject__PythonHelper *helper = dynamic_cast< PyNs3DataCollectionObject__PythonHelper* >(self->obj);
    
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
PyNs3DataCollectionObject__PythonHelper::_wrap_DoDispose(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    PyNs3DataCollectionObject__PythonHelper *helper = dynamic_cast< PyNs3DataCollectionObject__PythonHelper* >(self->obj);
    
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
PyNs3DataCollectionObject__PythonHelper::IsEnabled() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataCollectionObject *self_obj_before;
    PyObject *py_retval;
    bool retval;
    PyObject *py_boolretval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "IsEnabled"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::DataCollectionObject::IsEnabled();
    }
    self_obj_before = reinterpret_cast< PyNs3DataCollectionObject* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataCollectionObject* >(m_pyself)->obj = const_cast< ns3::DataCollectionObject* >((const ns3::DataCollectionObject*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "IsEnabled", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataCollectionObject* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::DataCollectionObject::IsEnabled();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataCollectionObject* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::DataCollectionObject::IsEnabled();
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataCollectionObject* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3DataCollectionObject__PythonHelper::GetInstanceTypeId() const
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
PyNs3DataCollectionObject__PythonHelper::DoDispose()
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
PyNs3DataCollectionObject__PythonHelper::DoInitialize()
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
PyNs3DataCollectionObject__PythonHelper::NotifyNewAggregate()
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
PyNs3DataCollectionObject__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3DataCollectionObject__tp_init__0(PyNs3DataCollectionObject *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DataCollectionObject *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataCollectionObject_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3DataCollectionObject_Type)
    {
        self->obj = new PyNs3DataCollectionObject__PythonHelper(*((PyNs3DataCollectionObject *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DataCollectionObject__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::DataCollectionObject(*((PyNs3DataCollectionObject *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3DataCollectionObject__tp_init__1(PyNs3DataCollectionObject *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3DataCollectionObject_Type)
    {
        self->obj = new PyNs3DataCollectionObject__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DataCollectionObject__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::DataCollectionObject();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3DataCollectionObject__tp_init(PyNs3DataCollectionObject *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3DataCollectionObject__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DataCollectionObject__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3DataCollectionObject_Enable(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    
    self->obj->Enable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollectionObject_SetName(PyNs3DataCollectionObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    const char *keywords[] = {"name", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &name, &name_len)) {
        return NULL;
    }
    self->obj->SetName(std::string(name, name_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollectionObject_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::DataCollectionObject::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollectionObject_Disable(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    
    self->obj->Disable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollectionObject_IsEnabled(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    bool retval;
    PyNs3DataCollectionObject__PythonHelper *helper_class = dynamic_cast<PyNs3DataCollectionObject__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->IsEnabled()) : (self->obj->ns3::DataCollectionObject::IsEnabled());
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollectionObject_GetName(PyNs3DataCollectionObject *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetName();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


static PyObject*
_wrap_PyNs3DataCollectionObject__copy__(PyNs3DataCollectionObject *self)
{

    PyNs3DataCollectionObject *py_copy;
    py_copy = PyObject_GC_New(PyNs3DataCollectionObject, &PyNs3DataCollectionObject_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::DataCollectionObject(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3DataCollectionObject_methods[] = {
    {(char *) "Enable", (PyCFunction) _wrap_PyNs3DataCollectionObject_Enable, METH_NOARGS, NULL },
    {(char *) "SetName", (PyCFunction) _wrap_PyNs3DataCollectionObject_SetName, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3DataCollectionObject_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Disable", (PyCFunction) _wrap_PyNs3DataCollectionObject_Disable, METH_NOARGS, NULL },
    {(char *) "IsEnabled", (PyCFunction) _wrap_PyNs3DataCollectionObject_IsEnabled, METH_NOARGS, NULL },
    {(char *) "GetName", (PyCFunction) _wrap_PyNs3DataCollectionObject_GetName, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3DataCollectionObject__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3DataCollectionObject__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3DataCollectionObject__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3DataCollectionObject__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3DataCollectionObject__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DataCollectionObject__tp_clear(PyNs3DataCollectionObject *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::DataCollectionObject *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3DataCollectionObject__tp_traverse(PyNs3DataCollectionObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3DataCollectionObject__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3DataCollectionObject__tp_dealloc(PyNs3DataCollectionObject *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DataCollectionObject__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DataCollectionObject__tp_richcompare (PyNs3DataCollectionObject *PYBINDGEN_UNUSED(self), PyNs3DataCollectionObject *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DataCollectionObject_Type)) {
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

PyTypeObject PyNs3DataCollectionObject_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.DataCollectionObject",            /* tp_name */
    sizeof(PyNs3DataCollectionObject),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DataCollectionObject__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DataCollectionObject__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DataCollectionObject__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DataCollectionObject__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DataCollectionObject_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DataCollectionObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DataCollectionObject__tp_init,             /* tp_init */
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
PyNs3DataCollector__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    PyNs3DataCollector__PythonHelper *helper = dynamic_cast< PyNs3DataCollector__PythonHelper* >(self->obj);
    
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
PyNs3DataCollector__PythonHelper::_wrap_DoInitialize(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    PyNs3DataCollector__PythonHelper *helper = dynamic_cast< PyNs3DataCollector__PythonHelper* >(self->obj);
    
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
PyNs3DataCollector__PythonHelper::_wrap_NotifyNewAggregate(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    PyNs3DataCollector__PythonHelper *helper = dynamic_cast< PyNs3DataCollector__PythonHelper* >(self->obj);
    
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
PyNs3DataCollector__PythonHelper::_wrap_DoDispose(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    PyNs3DataCollector__PythonHelper *helper = dynamic_cast< PyNs3DataCollector__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class DataCollector is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3DataCollector__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataCollector *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DataCollector::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataCollector* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataCollector* >(m_pyself)->obj = (ns3::DataCollector*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataCollector* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataCollector* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataCollector* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3DataCollector__PythonHelper::GetInstanceTypeId() const
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
PyNs3DataCollector__PythonHelper::DoInitialize()
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
PyNs3DataCollector__PythonHelper::NotifyNewAggregate()
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
PyNs3DataCollector__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3DataCollector__tp_init__0(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DataCollector *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataCollector_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3DataCollector_Type)
    {
        self->obj = new PyNs3DataCollector__PythonHelper(*((PyNs3DataCollector *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DataCollector__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::DataCollector(*((PyNs3DataCollector *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3DataCollector__tp_init__1(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3DataCollector_Type)
    {
        self->obj = new PyNs3DataCollector__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DataCollector__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::DataCollector();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3DataCollector__tp_init(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3DataCollector__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DataCollector__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3DataCollector_GetRunLabel(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetRunLabel();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollector_GetStrategyLabel(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetStrategyLabel();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollector_GetExperimentLabel(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetExperimentLabel();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollector_DescribeRun(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *experiment;
    Py_ssize_t experiment_len;
    const char *strategy;
    Py_ssize_t strategy_len;
    const char *input;
    Py_ssize_t input_len;
    const char *runID;
    Py_ssize_t runID_len;
    const char *description = NULL;
    Py_ssize_t description_len;
    const char *keywords[] = {"experiment", "strategy", "input", "runID", "description", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#s#s#|s#", (char **) keywords, &experiment, &experiment_len, &strategy, &strategy_len, &input, &input_len, &runID, &runID_len, &description, &description_len)) {
        return NULL;
    }
    self->obj->DescribeRun(std::string(experiment, experiment_len), std::string(strategy, strategy_len), std::string(input, input_len), std::string(runID, runID_len), (description ? std::string(description, description_len) : ""));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollector_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::DataCollector::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollector_GetDescription(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetDescription();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3DataCollector_AddDataCalculator(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataCalculator *datac;
    ns3::DataCalculator *datac_ptr;
    const char *keywords[] = {"datac", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataCalculator_Type, &datac)) {
        return NULL;
    }
    datac_ptr = (datac ? datac->obj : NULL);
    self->obj->AddDataCalculator(ns3::Ptr< ns3::DataCalculator  > (datac_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3DataCollector_AddMetadata__0(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *value;
    Py_ssize_t value_len;
    const char *keywords[] = {"key", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &key, &key_len, &value, &value_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddMetadata(std::string(key, key_len), std::string(value, value_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DataCollector_AddMetadata__1(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    double value;
    const char *keywords[] = {"key", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#d", (char **) keywords, &key, &key_len, &value)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddMetadata(std::string(key, key_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3DataCollector_AddMetadata__2(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    unsigned int value;
    const char *keywords[] = {"key", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#I", (char **) keywords, &key, &key_len, &value)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->AddMetadata(std::string(key, key_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3DataCollector_AddMetadata(PyNs3DataCollector *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3DataCollector_AddMetadata__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DataCollector_AddMetadata__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3DataCollector_AddMetadata__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3DataCollector_GetInputLabel(PyNs3DataCollector *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetInputLabel();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


static PyObject*
_wrap_PyNs3DataCollector__copy__(PyNs3DataCollector *self)
{

    PyNs3DataCollector *py_copy;
    py_copy = PyObject_GC_New(PyNs3DataCollector, &PyNs3DataCollector_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::DataCollector(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3DataCollector_methods[] = {
    {(char *) "GetRunLabel", (PyCFunction) _wrap_PyNs3DataCollector_GetRunLabel, METH_NOARGS, NULL },
    {(char *) "GetStrategyLabel", (PyCFunction) _wrap_PyNs3DataCollector_GetStrategyLabel, METH_NOARGS, NULL },
    {(char *) "GetExperimentLabel", (PyCFunction) _wrap_PyNs3DataCollector_GetExperimentLabel, METH_NOARGS, NULL },
    {(char *) "DescribeRun", (PyCFunction) _wrap_PyNs3DataCollector_DescribeRun, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3DataCollector_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetDescription", (PyCFunction) _wrap_PyNs3DataCollector_GetDescription, METH_NOARGS, NULL },
    {(char *) "AddDataCalculator", (PyCFunction) _wrap_PyNs3DataCollector_AddDataCalculator, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddMetadata", (PyCFunction) _wrap_PyNs3DataCollector_AddMetadata, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInputLabel", (PyCFunction) _wrap_PyNs3DataCollector_GetInputLabel, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3DataCollector__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3DataCollector__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3DataCollector__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3DataCollector__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3DataCollector__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DataCollector__tp_clear(PyNs3DataCollector *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::DataCollector *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3DataCollector__tp_traverse(PyNs3DataCollector *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3DataCollector__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3DataCollector__tp_dealloc(PyNs3DataCollector *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DataCollector__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DataCollector__tp_richcompare (PyNs3DataCollector *PYBINDGEN_UNUSED(self), PyNs3DataCollector *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DataCollector_Type)) {
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

PyTypeObject PyNs3DataCollector_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.DataCollector",            /* tp_name */
    sizeof(PyNs3DataCollector),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DataCollector__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DataCollector__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DataCollector__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DataCollector__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DataCollector_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DataCollector, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DataCollector__tp_init,             /* tp_init */
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
PyNs3DataOutputInterface__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3DataOutputInterface *self)
{
    PyObject *py_retval;
    PyNs3DataOutputInterface__PythonHelper *helper = dynamic_cast< PyNs3DataOutputInterface__PythonHelper* >(self->obj);
    
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
PyNs3DataOutputInterface__PythonHelper::_wrap_DoInitialize(PyNs3DataOutputInterface *self)
{
    PyObject *py_retval;
    PyNs3DataOutputInterface__PythonHelper *helper = dynamic_cast< PyNs3DataOutputInterface__PythonHelper* >(self->obj);
    
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
PyNs3DataOutputInterface__PythonHelper::_wrap_NotifyNewAggregate(PyNs3DataOutputInterface *self)
{
    PyObject *py_retval;
    PyNs3DataOutputInterface__PythonHelper *helper = dynamic_cast< PyNs3DataOutputInterface__PythonHelper* >(self->obj);
    
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
PyNs3DataOutputInterface__PythonHelper::_wrap_DoDispose(PyNs3DataOutputInterface *self)
{
    PyObject *py_retval;
    PyNs3DataOutputInterface__PythonHelper *helper = dynamic_cast< PyNs3DataOutputInterface__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class DataOutputInterface is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3DataOutputInterface__PythonHelper::Output(ns3::DataCollector & dc)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataOutputInterface *self_obj_before;
    PyObject *py_retval;
    PyNs3DataCollector *py_DataCollector;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Output"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = (ns3::DataOutputInterface*) this;
    py_DataCollector = PyObject_GC_New(PyNs3DataCollector, &PyNs3DataCollector_Type);
    py_DataCollector->inst_dict = NULL;
    
    py_DataCollector->inst_dict = NULL;
    py_DataCollector->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DataCollector->obj = new ns3::DataCollector(dc);
    py_DataCollector->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_DataCollector->obj] = (PyObject *) py_DataCollector;
    ns3::CompleteConstruct(py_DataCollector->obj);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Output", (char *) "N", py_DataCollector);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3DataOutputInterface__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataOutputInterface *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DataOutputInterface::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = (ns3::DataOutputInterface*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataOutputInterface* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3DataOutputInterface__PythonHelper::GetInstanceTypeId() const
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
PyNs3DataOutputInterface__PythonHelper::DoInitialize()
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
PyNs3DataOutputInterface__PythonHelper::NotifyNewAggregate()
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
PyNs3DataOutputInterface__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3DataOutputInterface__tp_init__0(PyNs3DataOutputInterface *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DataOutputInterface *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataOutputInterface_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3DataOutputInterface_Type)
    {
        self->obj = new PyNs3DataOutputInterface__PythonHelper(*((PyNs3DataOutputInterface *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DataOutputInterface__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'DataOutputInterface' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3DataOutputInterface__tp_init__1(PyNs3DataOutputInterface *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3DataOutputInterface_Type)
    {
        self->obj = new PyNs3DataOutputInterface__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DataOutputInterface__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'DataOutputInterface' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3DataOutputInterface__tp_init(PyNs3DataOutputInterface *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3DataOutputInterface__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DataOutputInterface__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3DataOutputInterface_Output(PyNs3DataOutputInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataCollector *dc;
    const char *keywords[] = {"dc", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataCollector_Type, &dc)) {
        return NULL;
    }
    self->obj->Output(*((PyNs3DataCollector *) dc)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataOutputInterface_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::DataOutputInterface::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3DataOutputInterface_SetFilePrefix(PyNs3DataOutputInterface *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *prefix;
    Py_ssize_t prefix_len;
    const char *keywords[] = {"prefix", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &prefix, &prefix_len)) {
        return NULL;
    }
    self->obj->SetFilePrefix(std::string(prefix, prefix_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DataOutputInterface_GetFilePrefix(PyNs3DataOutputInterface *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetFilePrefix();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}

static PyMethodDef PyNs3DataOutputInterface_methods[] = {
    {(char *) "Output", (PyCFunction) _wrap_PyNs3DataOutputInterface_Output, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3DataOutputInterface_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetFilePrefix", (PyCFunction) _wrap_PyNs3DataOutputInterface_SetFilePrefix, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFilePrefix", (PyCFunction) _wrap_PyNs3DataOutputInterface_GetFilePrefix, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3DataOutputInterface__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3DataOutputInterface__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3DataOutputInterface__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3DataOutputInterface__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DataOutputInterface__tp_clear(PyNs3DataOutputInterface *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::DataOutputInterface *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3DataOutputInterface__tp_traverse(PyNs3DataOutputInterface *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3DataOutputInterface__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3DataOutputInterface__tp_dealloc(PyNs3DataOutputInterface *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DataOutputInterface__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DataOutputInterface__tp_richcompare (PyNs3DataOutputInterface *PYBINDGEN_UNUSED(self), PyNs3DataOutputInterface *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DataOutputInterface_Type)) {
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

PyTypeObject PyNs3DataOutputInterface_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.DataOutputInterface",            /* tp_name */
    sizeof(PyNs3DataOutputInterface),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DataOutputInterface__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DataOutputInterface__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DataOutputInterface__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DataOutputInterface__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DataOutputInterface_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DataOutputInterface, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DataOutputInterface__tp_init,             /* tp_init */
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
_wrap_PyNs3FileAggregator__tp_init(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    const char *outputFileName;
    Py_ssize_t outputFileName_len;
    std::string outputFileName_std;
    ns3::FileAggregator::FileType fileType = ::ns3::FileAggregator::SPACE_SEPARATED;
    const char *keywords[] = {"outputFileName", "fileType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|i", (char **) keywords, &outputFileName, &outputFileName_len, &fileType)) {
        return -1;
    }
    outputFileName_std = std::string(outputFileName, outputFileName_len);
    self->obj = new ns3::FileAggregator(outputFileName_std, fileType);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}


PyObject *
_wrap_PyNs3FileAggregator_Write3d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    const char *keywords[] = {"context", "v1", "v2", "v3", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#ddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3)) {
        return NULL;
    }
    self->obj->Write3d(std::string(context, context_len), v1, v2, v3);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write1d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    const char *keywords[] = {"context", "v1", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#d", (char **) keywords, &context, &context_len, &v1)) {
        return NULL;
    }
    self->obj->Write1d(std::string(context, context_len), v1);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::FileAggregator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set1dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set1dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set7dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set7dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set5dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set5dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set9dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set9dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set10dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set10dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_SetFileType(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::FileAggregator::FileType fileType;
    const char *keywords[] = {"fileType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &fileType)) {
        return NULL;
    }
    self->obj->SetFileType(fileType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write9d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    double v5;
    double v6;
    double v7;
    double v8;
    double v9;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#ddddddddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9)) {
        return NULL;
    }
    self->obj->Write9d(std::string(context, context_len), v1, v2, v3, v4, v5, v6, v7, v8, v9);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set4dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set4dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set8dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set8dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write7d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    double v5;
    double v6;
    double v7;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", "v5", "v6", "v7", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#ddddddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4, &v5, &v6, &v7)) {
        return NULL;
    }
    self->obj->Write7d(std::string(context, context_len), v1, v2, v3, v4, v5, v6, v7);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write5d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    double v5;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", "v5", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#ddddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4, &v5)) {
        return NULL;
    }
    self->obj->Write5d(std::string(context, context_len), v1, v2, v3, v4, v5);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write4d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4)) {
        return NULL;
    }
    self->obj->Write4d(std::string(context, context_len), v1, v2, v3, v4);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write2d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    const char *keywords[] = {"context", "v1", "v2", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dd", (char **) keywords, &context, &context_len, &v1, &v2)) {
        return NULL;
    }
    self->obj->Write2d(std::string(context, context_len), v1, v2);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set3dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set3dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set6dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set6dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Set2dFormat(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *format;
    Py_ssize_t format_len;
    std::string format_std;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &format, &format_len)) {
        return NULL;
    }
    format_std = std::string(format, format_len);
    self->obj->Set2dFormat(format_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write10d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    double v5;
    double v6;
    double v7;
    double v8;
    double v9;
    double v10;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dddddddddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8, &v9, &v10)) {
        return NULL;
    }
    self->obj->Write10d(std::string(context, context_len), v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_SetHeading(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *heading;
    Py_ssize_t heading_len;
    std::string heading_std;
    const char *keywords[] = {"heading", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &heading, &heading_len)) {
        return NULL;
    }
    heading_std = std::string(heading, heading_len);
    self->obj->SetHeading(heading_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write8d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    double v5;
    double v6;
    double v7;
    double v8;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dddddddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4, &v5, &v6, &v7, &v8)) {
        return NULL;
    }
    self->obj->Write8d(std::string(context, context_len), v1, v2, v3, v4, v5, v6, v7, v8);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileAggregator_Write6d(PyNs3FileAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double v1;
    double v2;
    double v3;
    double v4;
    double v5;
    double v6;
    const char *keywords[] = {"context", "v1", "v2", "v3", "v4", "v5", "v6", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dddddd", (char **) keywords, &context, &context_len, &v1, &v2, &v3, &v4, &v5, &v6)) {
        return NULL;
    }
    self->obj->Write6d(std::string(context, context_len), v1, v2, v3, v4, v5, v6);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3FileAggregator_methods[] = {
    {(char *) "Write3d", (PyCFunction) _wrap_PyNs3FileAggregator_Write3d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write1d", (PyCFunction) _wrap_PyNs3FileAggregator_Write1d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3FileAggregator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Set1dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set1dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set7dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set7dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set5dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set5dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set9dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set9dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set10dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set10dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFileType", (PyCFunction) _wrap_PyNs3FileAggregator_SetFileType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write9d", (PyCFunction) _wrap_PyNs3FileAggregator_Write9d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set4dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set4dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set8dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set8dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write7d", (PyCFunction) _wrap_PyNs3FileAggregator_Write7d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write5d", (PyCFunction) _wrap_PyNs3FileAggregator_Write5d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write4d", (PyCFunction) _wrap_PyNs3FileAggregator_Write4d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write2d", (PyCFunction) _wrap_PyNs3FileAggregator_Write2d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set3dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set3dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set6dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set6dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set2dFormat", (PyCFunction) _wrap_PyNs3FileAggregator_Set2dFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write10d", (PyCFunction) _wrap_PyNs3FileAggregator_Write10d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHeading", (PyCFunction) _wrap_PyNs3FileAggregator_SetHeading, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write8d", (PyCFunction) _wrap_PyNs3FileAggregator_Write8d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write6d", (PyCFunction) _wrap_PyNs3FileAggregator_Write6d, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FileAggregator__tp_clear(PyNs3FileAggregator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::FileAggregator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3FileAggregator__tp_traverse(PyNs3FileAggregator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3FileAggregator__tp_dealloc(PyNs3FileAggregator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FileAggregator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FileAggregator__tp_richcompare (PyNs3FileAggregator *PYBINDGEN_UNUSED(self), PyNs3FileAggregator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FileAggregator_Type)) {
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

PyTypeObject PyNs3FileAggregator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.FileAggregator",            /* tp_name */
    sizeof(PyNs3FileAggregator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FileAggregator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3FileAggregator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FileAggregator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FileAggregator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FileAggregator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FileAggregator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FileAggregator__tp_init,             /* tp_init */
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
_wrap_PyNs3GnuplotAggregator__tp_init__0(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GnuplotAggregator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GnuplotAggregator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GnuplotAggregator(*((PyNs3GnuplotAggregator *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3GnuplotAggregator__tp_init__1(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *outputFileNameWithoutExtension;
    Py_ssize_t outputFileNameWithoutExtension_len;
    std::string outputFileNameWithoutExtension_std;
    const char *keywords[] = {"outputFileNameWithoutExtension", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &outputFileNameWithoutExtension, &outputFileNameWithoutExtension_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    outputFileNameWithoutExtension_std = std::string(outputFileNameWithoutExtension, outputFileNameWithoutExtension_len);
    self->obj = new ns3::GnuplotAggregator(outputFileNameWithoutExtension_std);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3GnuplotAggregator__tp_init(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3GnuplotAggregator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GnuplotAggregator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3GnuplotAggregator_Write2dWithXYErrorDelta(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double x;
    double y;
    double xErrorDelta;
    double yErrorDelta;
    const char *keywords[] = {"context", "x", "y", "xErrorDelta", "yErrorDelta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dddd", (char **) keywords, &context, &context_len, &x, &y, &xErrorDelta, &yErrorDelta)) {
        return NULL;
    }
    self->obj->Write2dWithXYErrorDelta(std::string(context, context_len), x, y, xErrorDelta, yErrorDelta);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Write2dWithYErrorDelta(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double x;
    double y;
    double errorDelta;
    const char *keywords[] = {"context", "x", "y", "errorDelta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#ddd", (char **) keywords, &context, &context_len, &x, &y, &errorDelta)) {
        return NULL;
    }
    self->obj->Write2dWithYErrorDelta(std::string(context, context_len), x, y, errorDelta);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Write2dWithXErrorDelta(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double x;
    double y;
    double errorDelta;
    const char *keywords[] = {"context", "x", "y", "errorDelta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#ddd", (char **) keywords, &context, &context_len, &x, &y, &errorDelta)) {
        return NULL;
    }
    self->obj->Write2dWithXErrorDelta(std::string(context, context_len), x, y, errorDelta);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Write2d(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    double x;
    double y;
    const char *keywords[] = {"context", "x", "y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#dd", (char **) keywords, &context, &context_len, &x, &y)) {
        return NULL;
    }
    self->obj->Write2d(std::string(context, context_len), x, y);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_SetTitle(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &title, &title_len)) {
        return NULL;
    }
    title_std = std::string(title, title_len);
    self->obj->SetTitle(title_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::GnuplotAggregator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Set2dDatasetDefaultErrorBars(PyNs3GnuplotAggregator *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Gnuplot2dDataset::ErrorBars errorBars;
    const char *keywords[] = {"errorBars", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &errorBars)) {
        return NULL;
    }
    ns3::GnuplotAggregator::Set2dDatasetDefaultErrorBars(errorBars);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Set2dDatasetDefaultExtra(PyNs3GnuplotAggregator *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    ns3::GnuplotAggregator::Set2dDatasetDefaultExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_SetExtra(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    self->obj->SetExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Set2dDatasetExtra(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *dataset;
    Py_ssize_t dataset_len;
    std::string dataset_std;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"dataset", "extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &dataset, &dataset_len, &extra, &extra_len)) {
        return NULL;
    }
    dataset_std = std::string(dataset, dataset_len);
    extra_std = std::string(extra, extra_len);
    self->obj->Set2dDatasetExtra(dataset_std, extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Set2dDatasetStyle(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *dataset;
    Py_ssize_t dataset_len;
    std::string dataset_std;
    ns3::Gnuplot2dDataset::Style style;
    const char *keywords[] = {"dataset", "style", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#i", (char **) keywords, &dataset, &dataset_len, &style)) {
        return NULL;
    }
    dataset_std = std::string(dataset, dataset_len);
    self->obj->Set2dDatasetStyle(dataset_std, style);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_AppendExtra(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *extra;
    Py_ssize_t extra_len;
    std::string extra_std;
    const char *keywords[] = {"extra", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &extra, &extra_len)) {
        return NULL;
    }
    extra_std = std::string(extra, extra_len);
    self->obj->AppendExtra(extra_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_SetLegend(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *xLegend;
    Py_ssize_t xLegend_len;
    std::string xLegend_std;
    const char *yLegend;
    Py_ssize_t yLegend_len;
    std::string yLegend_std;
    const char *keywords[] = {"xLegend", "yLegend", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &xLegend, &xLegend_len, &yLegend, &yLegend_len)) {
        return NULL;
    }
    xLegend_std = std::string(xLegend, xLegend_len);
    yLegend_std = std::string(yLegend, yLegend_len);
    self->obj->SetLegend(xLegend_std, yLegend_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_SetTerminal(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *terminal;
    Py_ssize_t terminal_len;
    std::string terminal_std;
    const char *keywords[] = {"terminal", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &terminal, &terminal_len)) {
        return NULL;
    }
    terminal_std = std::string(terminal, terminal_len);
    self->obj->SetTerminal(terminal_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Set2dDatasetDefaultStyle(PyNs3GnuplotAggregator *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Gnuplot2dDataset::Style style;
    const char *keywords[] = {"style", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &style)) {
        return NULL;
    }
    ns3::GnuplotAggregator::Set2dDatasetDefaultStyle(style);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_SetKeyLocation(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::GnuplotAggregator::KeyLocation keyLocation;
    const char *keywords[] = {"keyLocation", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &keyLocation)) {
        return NULL;
    }
    self->obj->SetKeyLocation(keyLocation);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Set2dDatasetErrorBars(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *dataset;
    Py_ssize_t dataset_len;
    std::string dataset_std;
    ns3::Gnuplot2dDataset::ErrorBars errorBars;
    const char *keywords[] = {"dataset", "errorBars", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#i", (char **) keywords, &dataset, &dataset_len, &errorBars)) {
        return NULL;
    }
    dataset_std = std::string(dataset, dataset_len);
    self->obj->Set2dDatasetErrorBars(dataset_std, errorBars);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Add2dDataset(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *dataset;
    Py_ssize_t dataset_len;
    std::string dataset_std;
    const char *title;
    Py_ssize_t title_len;
    std::string title_std;
    const char *keywords[] = {"dataset", "title", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#", (char **) keywords, &dataset, &dataset_len, &title, &title_len)) {
        return NULL;
    }
    dataset_std = std::string(dataset, dataset_len);
    title_std = std::string(title, title_len);
    self->obj->Add2dDataset(dataset_std, title_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GnuplotAggregator_Write2dDatasetEmptyLine(PyNs3GnuplotAggregator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *dataset;
    Py_ssize_t dataset_len;
    std::string dataset_std;
    const char *keywords[] = {"dataset", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &dataset, &dataset_len)) {
        return NULL;
    }
    dataset_std = std::string(dataset, dataset_len);
    self->obj->Write2dDatasetEmptyLine(dataset_std);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3GnuplotAggregator__copy__(PyNs3GnuplotAggregator *self)
{

    PyNs3GnuplotAggregator *py_copy;
    py_copy = PyObject_GC_New(PyNs3GnuplotAggregator, &PyNs3GnuplotAggregator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::GnuplotAggregator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GnuplotAggregator_methods[] = {
    {(char *) "Write2dWithXYErrorDelta", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Write2dWithXYErrorDelta, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write2dWithYErrorDelta", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Write2dWithYErrorDelta, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write2dWithXErrorDelta", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Write2dWithXErrorDelta, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write2d", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Write2d, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTitle", (PyCFunction) _wrap_PyNs3GnuplotAggregator_SetTitle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3GnuplotAggregator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Set2dDatasetDefaultErrorBars", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Set2dDatasetDefaultErrorBars, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "Set2dDatasetDefaultExtra", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Set2dDatasetDefaultExtra, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetExtra", (PyCFunction) _wrap_PyNs3GnuplotAggregator_SetExtra, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set2dDatasetExtra", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Set2dDatasetExtra, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set2dDatasetStyle", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Set2dDatasetStyle, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AppendExtra", (PyCFunction) _wrap_PyNs3GnuplotAggregator_AppendExtra, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLegend", (PyCFunction) _wrap_PyNs3GnuplotAggregator_SetLegend, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTerminal", (PyCFunction) _wrap_PyNs3GnuplotAggregator_SetTerminal, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set2dDatasetDefaultStyle", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Set2dDatasetDefaultStyle, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetKeyLocation", (PyCFunction) _wrap_PyNs3GnuplotAggregator_SetKeyLocation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set2dDatasetErrorBars", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Set2dDatasetErrorBars, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Add2dDataset", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Add2dDataset, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Write2dDatasetEmptyLine", (PyCFunction) _wrap_PyNs3GnuplotAggregator_Write2dDatasetEmptyLine, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GnuplotAggregator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3GnuplotAggregator__tp_clear(PyNs3GnuplotAggregator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::GnuplotAggregator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3GnuplotAggregator__tp_traverse(PyNs3GnuplotAggregator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3GnuplotAggregator__tp_dealloc(PyNs3GnuplotAggregator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3GnuplotAggregator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GnuplotAggregator__tp_richcompare (PyNs3GnuplotAggregator *PYBINDGEN_UNUSED(self), PyNs3GnuplotAggregator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GnuplotAggregator_Type)) {
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

PyTypeObject PyNs3GnuplotAggregator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.GnuplotAggregator",            /* tp_name */
    sizeof(PyNs3GnuplotAggregator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GnuplotAggregator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3GnuplotAggregator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3GnuplotAggregator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3GnuplotAggregator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GnuplotAggregator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3GnuplotAggregator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GnuplotAggregator__tp_init,             /* tp_init */
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper = dynamic_cast< PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper* >(self->obj);
    
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_DoInitialize(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper = dynamic_cast< PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper* >(self->obj);
    
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_NotifyNewAggregate(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper = dynamic_cast< PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper* >(self->obj);
    
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_DoDispose(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper = dynamic_cast< PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class MinMaxAvgTotalCalculator is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


long int
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getCount() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    long int retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getCount"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getCount();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getCount", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getCount();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "l", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getCount();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getMax() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getMax"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMax();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getMax", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMax();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMax();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getMean() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getMean"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMean();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getMean", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMean();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMean();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getMin() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getMin"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMin();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getMin", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMin();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getMin();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getSqrSum() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getSqrSum"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getSqrSum();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getSqrSum", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getSqrSum();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getSqrSum();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getStddev() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getStddev"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getStddev();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getStddev", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getStddev();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getStddev();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getSum() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getSum"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getSum();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getSum", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getSum();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getSum();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

double
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::getVariance() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    double retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "getVariance"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getVariance();
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = const_cast< ns3::MinMaxAvgTotalCalculator< double >* >((const ns3::MinMaxAvgTotalCalculator< double >*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "getVariance", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getVariance();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::MinMaxAvgTotalCalculator< double >::getVariance();
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MinMaxAvgTotalCalculator< double > *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::MinMaxAvgTotalCalculator< double >::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = (ns3::MinMaxAvgTotalCalculator< double >*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MinMaxAvgTotalCalculator__Double* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::Stop(ns3::Time const & stopTime)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataCalculator *self_obj_before;
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Stop"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DataCalculator::Stop(stopTime);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = (ns3::DataCalculator*) this;
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(stopTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Stop", (char *) "N", py_Time);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::Start(ns3::Time const & startTime)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataCalculator *self_obj_before;
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Start"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DataCalculator::Start(startTime);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = (ns3::DataCalculator*) this;
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(startTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Start", (char *) "N", py_Time);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::GetInstanceTypeId() const
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::DoInitialize()
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::NotifyNewAggregate()
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
PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_init__0(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3MinMaxAvgTotalCalculator__Double *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MinMaxAvgTotalCalculator__Double_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3MinMaxAvgTotalCalculator__Double_Type)
    {
        self->obj = new PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper(*((PyNs3MinMaxAvgTotalCalculator__Double *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::MinMaxAvgTotalCalculator< double >(*((PyNs3MinMaxAvgTotalCalculator__Double *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_init__1(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3MinMaxAvgTotalCalculator__Double_Type)
    {
        self->obj = new PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::MinMaxAvgTotalCalculator< double >();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_init(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Reset(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    
    self->obj->Reset();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getSqrSum(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getSqrSum()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getSqrSum());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::MinMaxAvgTotalCalculator< double >::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getVariance(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getVariance()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getVariance());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Update(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &i)) {
        return NULL;
    }
    self->obj->Update(i);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getMean(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getMean()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getMean());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getSum(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getSum()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getSum());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getStddev(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getStddev()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getStddev());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getMin(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getMin()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getMin());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getCount(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    long int retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getCount()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getCount());
    py_retval = Py_BuildValue((char *) "l", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_getMax(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    double retval;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->getMax()) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::getMax());
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Output(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataOutputCallback *callback;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    const char *keywords[] = {"callback", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataOutputCallback_Type, &callback)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Output(*((PyNs3DataOutputCallback *) callback)->obj)) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::Output(*((PyNs3DataOutputCallback *) callback)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Dispose(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    
    self->obj->Dispose();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetKey(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetKey();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Start(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *startTime;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    const char *keywords[] = {"startTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &startTime)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Start(*((PyNs3Time *) startTime)->obj)) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::Start(*((PyNs3Time *) startTime)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Cleanup(void)
{
    PyObject *py_retval;
    
    ns3::MinMaxAvgTotalCalculator< double >::Cleanup();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetEnabled(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetEnabled();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Enable(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    
    self->obj->Enable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetAttribute(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->GetAttribute(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Stop(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *stopTime;
    PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper *helper_class = dynamic_cast<PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper*> (self->obj);
    const char *keywords[] = {"stopTime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &stopTime)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Stop(*((PyNs3Time *) stopTime)->obj)) : (self->obj->ns3::MinMaxAvgTotalCalculator< double >::Stop(*((PyNs3Time *) stopTime)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetContext(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetContext();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Disable(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    
    self->obj->Disable();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_Initialize(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    
    self->obj->Initialize();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceDisconnect(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *name;
    Py_ssize_t name_len;
    const char *context;
    Py_ssize_t context_len;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"name", "context", "cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#O!", (char **) keywords, &name, &name_len, &context, &context_len, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    retval = self->obj->TraceDisconnect(std::string(name, name_len), std::string(context, context_len), *((PyNs3CallbackBase *) cb)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetAttributeFailSafe(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    retval = self->obj->SetAttributeFailSafe(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_AggregateObject(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Object *other;
    ns3::Object *other_ptr;
    const char *keywords[] = {"other", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Object_Type, &other)) {
        return NULL;
    }
    other_ptr = (other ? other->obj : NULL);
    self->obj->AggregateObject(ns3::Ptr< ns3::Object  > (other_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetAttribute(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceConnect(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *name;
    Py_ssize_t name_len;
    const char *context;
    Py_ssize_t context_len;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"name", "context", "cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#s#O!", (char **) keywords, &name, &name_len, &context, &context_len, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    retval = self->obj->TraceConnect(std::string(name, name_len), std::string(context, context_len), *((PyNs3CallbackBase *) cb)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceDisconnectWithoutContext(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"name", "cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    retval = self->obj->TraceDisconnectWithoutContext(std::string(name, name_len), *((PyNs3CallbackBase *) cb)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetKey(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *key;
    Py_ssize_t key_len;
    const char *keywords[] = {"key", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &key, &key_len)) {
        return NULL;
    }
    self->obj->SetKey(std::string(key, key_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceConnectWithoutContext(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3CallbackBase *cb;
    const char *keywords[] = {"name", "cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3CallbackBase_Type, &cb)) {
        return NULL;
    }
    retval = self->obj->TraceConnectWithoutContext(std::string(name, name_len), *((PyNs3CallbackBase *) cb)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetAggregateIterator(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    PyObject *py_retval;
    PyNs3ObjectAggregateIterator *py_AggregateIterator;
    
    ns3::Object::AggregateIterator retval = self->obj->GetAggregateIterator();
    py_AggregateIterator = PyObject_New(PyNs3ObjectAggregateIterator, &PyNs3ObjectAggregateIterator_Type);
    py_AggregateIterator->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_AggregateIterator->obj = new ns3::Object::AggregateIterator(retval);
    PyNs3ObjectAggregateIterator_wrapper_registry[(void *) py_AggregateIterator->obj] = (PyObject *) py_AggregateIterator;
    py_retval = Py_BuildValue((char *) "N", py_AggregateIterator);
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetAttributeFailSafe(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    retval = self->obj->GetAttributeFailSafe(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}

PyObject *
_wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetContext(PyNs3MinMaxAvgTotalCalculator__Double *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *context;
    Py_ssize_t context_len;
    const char *keywords[] = {"context", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &context, &context_len)) {
        return NULL;
    }
    self->obj->SetContext(std::string(context, context_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3MinMaxAvgTotalCalculator__Double__copy__(PyNs3MinMaxAvgTotalCalculator__Double *self)
{

    PyNs3MinMaxAvgTotalCalculator__Double *py_copy;
    py_copy = PyObject_GC_New(PyNs3MinMaxAvgTotalCalculator__Double, &PyNs3MinMaxAvgTotalCalculator__Double_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::MinMaxAvgTotalCalculator< double >(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3MinMaxAvgTotalCalculator__Double_methods[] = {
    {(char *) "Reset", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Reset, METH_NOARGS, NULL },
    {(char *) "getSqrSum", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getSqrSum, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "getVariance", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getVariance, METH_NOARGS, NULL },
    {(char *) "Update", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Update, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "getMean", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getMean, METH_NOARGS, NULL },
    {(char *) "getSum", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getSum, METH_NOARGS, NULL },
    {(char *) "getStddev", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getStddev, METH_NOARGS, NULL },
    {(char *) "getMin", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getMin, METH_NOARGS, NULL },
    {(char *) "getCount", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getCount, METH_NOARGS, NULL },
    {(char *) "getMax", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_getMax, METH_NOARGS, NULL },
    {(char *) "Output", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Output, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "Dispose", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Dispose, METH_NOARGS, NULL },
    {(char *) "GetKey", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetKey, METH_NOARGS, NULL },
    {(char *) "Start", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Start, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Cleanup", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Cleanup, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetEnabled", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetEnabled, METH_NOARGS, NULL },
    {(char *) "Enable", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Enable, METH_NOARGS, NULL },
    {(char *) "GetAttribute", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Stop", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Stop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetContext", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetContext, METH_NOARGS, NULL },
    {(char *) "Disable", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Disable, METH_NOARGS, NULL },
    {(char *) "Initialize", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_Initialize, METH_NOARGS, NULL },
    {(char *) "TraceDisconnect", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceDisconnect, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAttributeFailSafe", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetAttributeFailSafe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AggregateObject", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_AggregateObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAttribute", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetAttribute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TraceConnect", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceConnect, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TraceDisconnectWithoutContext", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceDisconnectWithoutContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetKey", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetKey, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TraceConnectWithoutContext", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_TraceConnectWithoutContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAggregateIterator", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetAggregateIterator, METH_NOARGS, NULL },
    {(char *) "GetAttributeFailSafe", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_GetAttributeFailSafe, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetContext", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double_SetContext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3MinMaxAvgTotalCalculator__Double__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3MinMaxAvgTotalCalculator__Double__tp_clear(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::MinMaxAvgTotalCalculator< double > *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3MinMaxAvgTotalCalculator__Double__tp_traverse(PyNs3MinMaxAvgTotalCalculator__Double *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3MinMaxAvgTotalCalculator__Double__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_dealloc(PyNs3MinMaxAvgTotalCalculator__Double *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3MinMaxAvgTotalCalculator__Double__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_richcompare (PyNs3MinMaxAvgTotalCalculator__Double *PYBINDGEN_UNUSED(self), PyNs3MinMaxAvgTotalCalculator__Double *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3MinMaxAvgTotalCalculator__Double_Type)) {
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

PyTypeObject PyNs3MinMaxAvgTotalCalculator__Double_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.MinMaxAvgTotalCalculator__Double",            /* tp_name */
    sizeof(PyNs3MinMaxAvgTotalCalculator__Double),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3MinMaxAvgTotalCalculator__Double__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3MinMaxAvgTotalCalculator__Double__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3MinMaxAvgTotalCalculator__Double_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3MinMaxAvgTotalCalculator__Double, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3MinMaxAvgTotalCalculator__Double__tp_init,             /* tp_init */
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
PyNs3OmnetDataOutput__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3OmnetDataOutput *self)
{
    PyObject *py_retval;
    PyNs3OmnetDataOutput__PythonHelper *helper = dynamic_cast< PyNs3OmnetDataOutput__PythonHelper* >(self->obj);
    
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
PyNs3OmnetDataOutput__PythonHelper::_wrap_DoInitialize(PyNs3OmnetDataOutput *self)
{
    PyObject *py_retval;
    PyNs3OmnetDataOutput__PythonHelper *helper = dynamic_cast< PyNs3OmnetDataOutput__PythonHelper* >(self->obj);
    
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
PyNs3OmnetDataOutput__PythonHelper::_wrap_NotifyNewAggregate(PyNs3OmnetDataOutput *self)
{
    PyObject *py_retval;
    PyNs3OmnetDataOutput__PythonHelper *helper = dynamic_cast< PyNs3OmnetDataOutput__PythonHelper* >(self->obj);
    
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
PyNs3OmnetDataOutput__PythonHelper::_wrap_DoDispose(PyNs3OmnetDataOutput *self)
{
    PyObject *py_retval;
    PyNs3OmnetDataOutput__PythonHelper *helper = dynamic_cast< PyNs3OmnetDataOutput__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class OmnetDataOutput is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

void
PyNs3OmnetDataOutput__PythonHelper::Output(ns3::DataCollector & dc)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OmnetDataOutput *self_obj_before;
    PyObject *py_retval;
    PyNs3DataCollector *py_DataCollector;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Output"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::OmnetDataOutput::Output(dc);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = (ns3::OmnetDataOutput*) this;
    py_DataCollector = PyObject_GC_New(PyNs3DataCollector, &PyNs3DataCollector_Type);
    py_DataCollector->inst_dict = NULL;
    
    py_DataCollector->inst_dict = NULL;
    py_DataCollector->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_DataCollector->obj = new ns3::DataCollector(dc);
    py_DataCollector->obj->Ref ();
    PyNs3ObjectBase_wrapper_registry[(void *) py_DataCollector->obj] = (PyObject *) py_DataCollector;
    ns3::CompleteConstruct(py_DataCollector->obj);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Output", (char *) "N", py_DataCollector);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3OmnetDataOutput__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OmnetDataOutput *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::OmnetDataOutput::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = (ns3::OmnetDataOutput*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OmnetDataOutput* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3OmnetDataOutput__PythonHelper::GetInstanceTypeId() const
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
PyNs3OmnetDataOutput__PythonHelper::DoInitialize()
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
PyNs3OmnetDataOutput__PythonHelper::NotifyNewAggregate()
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
PyNs3OmnetDataOutput__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3OmnetDataOutput__tp_init__0(PyNs3OmnetDataOutput *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OmnetDataOutput *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OmnetDataOutput_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3OmnetDataOutput_Type)
    {
        self->obj = new PyNs3OmnetDataOutput__PythonHelper(*((PyNs3OmnetDataOutput *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3OmnetDataOutput__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::OmnetDataOutput(*((PyNs3OmnetDataOutput *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3OmnetDataOutput__tp_init__1(PyNs3OmnetDataOutput *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3OmnetDataOutput_Type)
    {
        self->obj = new PyNs3OmnetDataOutput__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3OmnetDataOutput__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::OmnetDataOutput();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3OmnetDataOutput__tp_init(PyNs3OmnetDataOutput *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OmnetDataOutput__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OmnetDataOutput__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OmnetDataOutput_Output(PyNs3OmnetDataOutput *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataCollector *dc;
    PyNs3OmnetDataOutput__PythonHelper *helper_class = dynamic_cast<PyNs3OmnetDataOutput__PythonHelper*> (self->obj);
    const char *keywords[] = {"dc", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataCollector_Type, &dc)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Output(*((PyNs3DataCollector *) dc)->obj)) : (self->obj->ns3::OmnetDataOutput::Output(*((PyNs3DataCollector *) dc)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OmnetDataOutput_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::OmnetDataOutput::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3OmnetDataOutput__copy__(PyNs3OmnetDataOutput *self)
{

    PyNs3OmnetDataOutput *py_copy;
    py_copy = PyObject_GC_New(PyNs3OmnetDataOutput, &PyNs3OmnetDataOutput_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::OmnetDataOutput(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OmnetDataOutput_methods[] = {
    {(char *) "Output", (PyCFunction) _wrap_PyNs3OmnetDataOutput_Output, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OmnetDataOutput_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3OmnetDataOutput__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3OmnetDataOutput__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3OmnetDataOutput__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3OmnetDataOutput__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OmnetDataOutput__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OmnetDataOutput__tp_clear(PyNs3OmnetDataOutput *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::OmnetDataOutput *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3OmnetDataOutput__tp_traverse(PyNs3OmnetDataOutput *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3OmnetDataOutput__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3OmnetDataOutput__tp_dealloc(PyNs3OmnetDataOutput *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OmnetDataOutput__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OmnetDataOutput__tp_richcompare (PyNs3OmnetDataOutput *PYBINDGEN_UNUSED(self), PyNs3OmnetDataOutput *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OmnetDataOutput_Type)) {
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

PyTypeObject PyNs3OmnetDataOutput_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.OmnetDataOutput",            /* tp_name */
    sizeof(PyNs3OmnetDataOutput),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OmnetDataOutput__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3OmnetDataOutput__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OmnetDataOutput__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OmnetDataOutput__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OmnetDataOutput_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OmnetDataOutput, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OmnetDataOutput__tp_init,             /* tp_init */
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
PyNs3Probe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Probe *self)
{
    PyObject *py_retval;
    PyNs3Probe__PythonHelper *helper = dynamic_cast< PyNs3Probe__PythonHelper* >(self->obj);
    
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
PyNs3Probe__PythonHelper::_wrap_DoInitialize(PyNs3Probe *self)
{
    PyObject *py_retval;
    PyNs3Probe__PythonHelper *helper = dynamic_cast< PyNs3Probe__PythonHelper* >(self->obj);
    
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
PyNs3Probe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Probe *self)
{
    PyObject *py_retval;
    PyNs3Probe__PythonHelper *helper = dynamic_cast< PyNs3Probe__PythonHelper* >(self->obj);
    
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
PyNs3Probe__PythonHelper::_wrap_DoDispose(PyNs3Probe *self)
{
    PyObject *py_retval;
    PyNs3Probe__PythonHelper *helper = dynamic_cast< PyNs3Probe__PythonHelper* >(self->obj);
    
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
PyNs3Probe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Probe *self_obj_before;
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
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = (ns3::Probe*) this;
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
        reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3Probe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Probe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = (ns3::Probe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3Probe__PythonHelper::IsEnabled() const
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
PyNs3Probe__PythonHelper::GetInstanceTypeId() const
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
PyNs3Probe__PythonHelper::DoDispose()
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
PyNs3Probe__PythonHelper::DoInitialize()
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
PyNs3Probe__PythonHelper::NotifyNewAggregate()
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
PyNs3Probe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Probe__tp_init__0(PyNs3Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Probe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Probe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Probe_Type)
    {
        self->obj = new PyNs3Probe__PythonHelper(*((PyNs3Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'Probe' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3Probe__tp_init__1(PyNs3Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3Probe_Type)
    {
        self->obj = new PyNs3Probe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'Probe' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3Probe__tp_init(PyNs3Probe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Probe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Probe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Probe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Probe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Probe_ConnectByObject(PyNs3Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Probe_IsEnabled(PyNs3Probe *self)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Probe__PythonHelper*> (self->obj);
    
    retval = (helper_class == NULL)? (self->obj->IsEnabled()) : (self->obj->ns3::Probe::IsEnabled());
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Probe_ConnectByPath(PyNs3Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    self->obj->ConnectByPath(std::string(path, path_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3Probe_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Probe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3Probe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsEnabled", (PyCFunction) _wrap_PyNs3Probe_IsEnabled, METH_NOARGS, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3Probe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Probe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Probe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Probe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Probe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Probe__tp_clear(PyNs3Probe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Probe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Probe__tp_traverse(PyNs3Probe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Probe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Probe__tp_dealloc(PyNs3Probe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Probe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Probe__tp_richcompare (PyNs3Probe *PYBINDGEN_UNUSED(self), PyNs3Probe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Probe_Type)) {
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

PyTypeObject PyNs3Probe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Probe",            /* tp_name */
    sizeof(PyNs3Probe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Probe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Probe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Probe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Probe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Probe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Probe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Probe__tp_init,             /* tp_init */
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3TimeMinMaxAvgTotalCalculator *self)
{
    PyObject *py_retval;
    PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper *helper = dynamic_cast< PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper* >(self->obj);
    
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_DoInitialize(PyNs3TimeMinMaxAvgTotalCalculator *self)
{
    PyObject *py_retval;
    PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper *helper = dynamic_cast< PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper* >(self->obj);
    
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3TimeMinMaxAvgTotalCalculator *self)
{
    PyObject *py_retval;
    PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper *helper = dynamic_cast< PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper* >(self->obj);
    
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_DoDispose(PyNs3TimeMinMaxAvgTotalCalculator *self)
{
    PyObject *py_retval;
    PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper *helper = dynamic_cast< PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class TimeMinMaxAvgTotalCalculator is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


void
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TimeMinMaxAvgTotalCalculator *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::TimeMinMaxAvgTotalCalculator::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TimeMinMaxAvgTotalCalculator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TimeMinMaxAvgTotalCalculator* >(m_pyself)->obj = (ns3::TimeMinMaxAvgTotalCalculator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TimeMinMaxAvgTotalCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TimeMinMaxAvgTotalCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TimeMinMaxAvgTotalCalculator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::Stop(ns3::Time const & stopTime)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataCalculator *self_obj_before;
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Stop"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DataCalculator::Stop(stopTime);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = (ns3::DataCalculator*) this;
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(stopTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Stop", (char *) "N", py_Time);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::Start(ns3::Time const & startTime)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DataCalculator *self_obj_before;
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Start"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DataCalculator::Start(startTime);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = (ns3::DataCalculator*) this;
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(startTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Start", (char *) "N", py_Time);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DataCalculator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::GetInstanceTypeId() const
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::DoInitialize()
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::NotifyNewAggregate()
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
PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_init__0(PyNs3TimeMinMaxAvgTotalCalculator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3TimeMinMaxAvgTotalCalculator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TimeMinMaxAvgTotalCalculator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3TimeMinMaxAvgTotalCalculator_Type)
    {
        self->obj = new PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper(*((PyNs3TimeMinMaxAvgTotalCalculator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::TimeMinMaxAvgTotalCalculator(*((PyNs3TimeMinMaxAvgTotalCalculator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_init__1(PyNs3TimeMinMaxAvgTotalCalculator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3TimeMinMaxAvgTotalCalculator_Type)
    {
        self->obj = new PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::TimeMinMaxAvgTotalCalculator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_init(PyNs3TimeMinMaxAvgTotalCalculator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3TimeMinMaxAvgTotalCalculator_Output(PyNs3TimeMinMaxAvgTotalCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3DataOutputCallback *callback;
    PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper *helper_class = dynamic_cast<PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper*> (self->obj);
    const char *keywords[] = {"callback", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DataOutputCallback_Type, &callback)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->Output(*((PyNs3DataOutputCallback *) callback)->obj)) : (self->obj->ns3::TimeMinMaxAvgTotalCalculator::Output(*((PyNs3DataOutputCallback *) callback)->obj));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeMinMaxAvgTotalCalculator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::TimeMinMaxAvgTotalCalculator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeMinMaxAvgTotalCalculator_Update(PyNs3TimeMinMaxAvgTotalCalculator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &i)) {
        return NULL;
    }
    self->obj->Update(*((PyNs3Time *) i)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3TimeMinMaxAvgTotalCalculator__copy__(PyNs3TimeMinMaxAvgTotalCalculator *self)
{

    PyNs3TimeMinMaxAvgTotalCalculator *py_copy;
    py_copy = PyObject_GC_New(PyNs3TimeMinMaxAvgTotalCalculator, &PyNs3TimeMinMaxAvgTotalCalculator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::TimeMinMaxAvgTotalCalculator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3TimeMinMaxAvgTotalCalculator_methods[] = {
    {(char *) "Output", (PyCFunction) _wrap_PyNs3TimeMinMaxAvgTotalCalculator_Output, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3TimeMinMaxAvgTotalCalculator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Update", (PyCFunction) _wrap_PyNs3TimeMinMaxAvgTotalCalculator_Update, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3TimeMinMaxAvgTotalCalculator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3TimeMinMaxAvgTotalCalculator__tp_clear(PyNs3TimeMinMaxAvgTotalCalculator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::TimeMinMaxAvgTotalCalculator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3TimeMinMaxAvgTotalCalculator__tp_traverse(PyNs3TimeMinMaxAvgTotalCalculator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3TimeMinMaxAvgTotalCalculator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_dealloc(PyNs3TimeMinMaxAvgTotalCalculator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3TimeMinMaxAvgTotalCalculator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_richcompare (PyNs3TimeMinMaxAvgTotalCalculator *PYBINDGEN_UNUSED(self), PyNs3TimeMinMaxAvgTotalCalculator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3TimeMinMaxAvgTotalCalculator_Type)) {
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

PyTypeObject PyNs3TimeMinMaxAvgTotalCalculator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.TimeMinMaxAvgTotalCalculator",            /* tp_name */
    sizeof(PyNs3TimeMinMaxAvgTotalCalculator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3TimeMinMaxAvgTotalCalculator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3TimeMinMaxAvgTotalCalculator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3TimeMinMaxAvgTotalCalculator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3TimeMinMaxAvgTotalCalculator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3TimeMinMaxAvgTotalCalculator__tp_init,             /* tp_init */
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
PyNs3TimeProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3TimeProbe *self)
{
    PyObject *py_retval;
    PyNs3TimeProbe__PythonHelper *helper = dynamic_cast< PyNs3TimeProbe__PythonHelper* >(self->obj);
    
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
PyNs3TimeProbe__PythonHelper::_wrap_DoInitialize(PyNs3TimeProbe *self)
{
    PyObject *py_retval;
    PyNs3TimeProbe__PythonHelper *helper = dynamic_cast< PyNs3TimeProbe__PythonHelper* >(self->obj);
    
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
PyNs3TimeProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3TimeProbe *self)
{
    PyObject *py_retval;
    PyNs3TimeProbe__PythonHelper *helper = dynamic_cast< PyNs3TimeProbe__PythonHelper* >(self->obj);
    
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
PyNs3TimeProbe__PythonHelper::_wrap_DoDispose(PyNs3TimeProbe *self)
{
    PyObject *py_retval;
    PyNs3TimeProbe__PythonHelper *helper = dynamic_cast< PyNs3TimeProbe__PythonHelper* >(self->obj);
    
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
PyNs3TimeProbe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TimeProbe *self_obj_before;
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
        return ns3::TimeProbe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = (ns3::TimeProbe*) this;
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
        reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::TimeProbe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::TimeProbe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3TimeProbe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TimeProbe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::TimeProbe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = (ns3::TimeProbe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TimeProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3TimeProbe__PythonHelper::IsEnabled() const
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
PyNs3TimeProbe__PythonHelper::GetInstanceTypeId() const
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
PyNs3TimeProbe__PythonHelper::DoDispose()
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
PyNs3TimeProbe__PythonHelper::DoInitialize()
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
PyNs3TimeProbe__PythonHelper::NotifyNewAggregate()
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
PyNs3TimeProbe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3TimeProbe__tp_init__0(PyNs3TimeProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3TimeProbe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TimeProbe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3TimeProbe_Type)
    {
        self->obj = new PyNs3TimeProbe__PythonHelper(*((PyNs3TimeProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3TimeProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::TimeProbe(*((PyNs3TimeProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3TimeProbe__tp_init__1(PyNs3TimeProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3TimeProbe_Type)
    {
        self->obj = new PyNs3TimeProbe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3TimeProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::TimeProbe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3TimeProbe__tp_init(PyNs3TimeProbe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3TimeProbe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3TimeProbe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3TimeProbe_SetValueByPath(PyNs3TimeProbe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3Time *value;
    const char *keywords[] = {"path", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &path, &path_len, &PyNs3Time_Type, &value)) {
        return NULL;
    }
    ns3::TimeProbe::SetValueByPath(std::string(path, path_len), *((PyNs3Time *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeProbe_ConnectByPath(PyNs3TimeProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3TimeProbe__PythonHelper *helper_class = dynamic_cast<PyNs3TimeProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::TimeProbe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::TimeProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeProbe_GetValue(PyNs3TimeProbe *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetValue();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeProbe_SetValue(PyNs3TimeProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &value)) {
        return NULL;
    }
    self->obj->SetValue(*((PyNs3Time *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeProbe_ConnectByObject(PyNs3TimeProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3TimeProbe__PythonHelper *helper_class = dynamic_cast<PyNs3TimeProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::TimeProbe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3TimeProbe__copy__(PyNs3TimeProbe *self)
{

    PyNs3TimeProbe *py_copy;
    py_copy = PyObject_GC_New(PyNs3TimeProbe, &PyNs3TimeProbe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::TimeProbe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3TimeProbe_methods[] = {
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3TimeProbe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3TimeProbe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3TimeProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetValue", (PyCFunction) _wrap_PyNs3TimeProbe_GetValue, METH_NOARGS, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3TimeProbe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3TimeProbe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3TimeProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3TimeProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3TimeProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3TimeProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3TimeProbe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3TimeProbe__tp_clear(PyNs3TimeProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::TimeProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3TimeProbe__tp_traverse(PyNs3TimeProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3TimeProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3TimeProbe__tp_dealloc(PyNs3TimeProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3TimeProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3TimeProbe__tp_richcompare (PyNs3TimeProbe *PYBINDGEN_UNUSED(self), PyNs3TimeProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3TimeProbe_Type)) {
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

PyTypeObject PyNs3TimeProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.TimeProbe",            /* tp_name */
    sizeof(PyNs3TimeProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3TimeProbe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3TimeProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3TimeProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3TimeProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3TimeProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3TimeProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3TimeProbe__tp_init,             /* tp_init */
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
_wrap_PyNs3TimeSeriesAdaptor__tp_init__0(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3TimeSeriesAdaptor *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3TimeSeriesAdaptor_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::TimeSeriesAdaptor(*((PyNs3TimeSeriesAdaptor *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3TimeSeriesAdaptor__tp_init__1(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::TimeSeriesAdaptor();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3TimeSeriesAdaptor__tp_init(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3TimeSeriesAdaptor__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3TimeSeriesAdaptor__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3TimeSeriesAdaptor_TraceSinkUinteger16(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int oldData;
    int newData;
    const char *keywords[] = {"oldData", "newData", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ii", (char **) keywords, &oldData, &newData)) {
        return NULL;
    }
    if (oldData > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    if (newData > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->TraceSinkUinteger16(oldData, newData);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeSeriesAdaptor_TraceSinkUinteger32(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int oldData;
    unsigned int newData;
    const char *keywords[] = {"oldData", "newData", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "II", (char **) keywords, &oldData, &newData)) {
        return NULL;
    }
    self->obj->TraceSinkUinteger32(oldData, newData);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeSeriesAdaptor_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::TimeSeriesAdaptor::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeSeriesAdaptor_TraceSinkBoolean(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool oldData;
    PyObject *py_oldData;
    bool newData;
    PyObject *py_newData;
    const char *keywords[] = {"oldData", "newData", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "OO", (char **) keywords, &py_oldData, &py_newData)) {
        return NULL;
    }
    oldData = (bool) PyObject_IsTrue(py_oldData);
    newData = (bool) PyObject_IsTrue(py_newData);
    self->obj->TraceSinkBoolean(oldData, newData);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeSeriesAdaptor_TraceSinkUinteger8(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int oldData;
    int newData;
    const char *keywords[] = {"oldData", "newData", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "ii", (char **) keywords, &oldData, &newData)) {
        return NULL;
    }
    if (oldData > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    if (newData > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->TraceSinkUinteger8(oldData, newData);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TimeSeriesAdaptor_TraceSinkDouble(PyNs3TimeSeriesAdaptor *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double oldData;
    double newData;
    const char *keywords[] = {"oldData", "newData", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dd", (char **) keywords, &oldData, &newData)) {
        return NULL;
    }
    self->obj->TraceSinkDouble(oldData, newData);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3TimeSeriesAdaptor__copy__(PyNs3TimeSeriesAdaptor *self)
{

    PyNs3TimeSeriesAdaptor *py_copy;
    py_copy = PyObject_GC_New(PyNs3TimeSeriesAdaptor, &PyNs3TimeSeriesAdaptor_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::TimeSeriesAdaptor(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3TimeSeriesAdaptor_methods[] = {
    {(char *) "TraceSinkUinteger16", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor_TraceSinkUinteger16, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TraceSinkUinteger32", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor_TraceSinkUinteger32, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "TraceSinkBoolean", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor_TraceSinkBoolean, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TraceSinkUinteger8", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor_TraceSinkUinteger8, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "TraceSinkDouble", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor_TraceSinkDouble, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3TimeSeriesAdaptor__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3TimeSeriesAdaptor__tp_clear(PyNs3TimeSeriesAdaptor *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::TimeSeriesAdaptor *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3TimeSeriesAdaptor__tp_traverse(PyNs3TimeSeriesAdaptor *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3TimeSeriesAdaptor__tp_dealloc(PyNs3TimeSeriesAdaptor *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3TimeSeriesAdaptor__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3TimeSeriesAdaptor__tp_richcompare (PyNs3TimeSeriesAdaptor *PYBINDGEN_UNUSED(self), PyNs3TimeSeriesAdaptor *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3TimeSeriesAdaptor_Type)) {
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

PyTypeObject PyNs3TimeSeriesAdaptor_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.TimeSeriesAdaptor",            /* tp_name */
    sizeof(PyNs3TimeSeriesAdaptor),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3TimeSeriesAdaptor__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3TimeSeriesAdaptor__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3TimeSeriesAdaptor__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3TimeSeriesAdaptor__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3TimeSeriesAdaptor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3TimeSeriesAdaptor, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3TimeSeriesAdaptor__tp_init,             /* tp_init */
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
PyNs3Uinteger16Probe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Uinteger16Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger16Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger16Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger16Probe__PythonHelper::_wrap_DoInitialize(PyNs3Uinteger16Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger16Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger16Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger16Probe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Uinteger16Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger16Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger16Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger16Probe__PythonHelper::_wrap_DoDispose(PyNs3Uinteger16Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger16Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger16Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger16Probe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Uinteger16Probe *self_obj_before;
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
        return ns3::Uinteger16Probe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = (ns3::Uinteger16Probe*) this;
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
        reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Uinteger16Probe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Uinteger16Probe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3Uinteger16Probe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Uinteger16Probe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Uinteger16Probe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = (ns3::Uinteger16Probe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Uinteger16Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3Uinteger16Probe__PythonHelper::IsEnabled() const
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
PyNs3Uinteger16Probe__PythonHelper::GetInstanceTypeId() const
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
PyNs3Uinteger16Probe__PythonHelper::DoDispose()
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
PyNs3Uinteger16Probe__PythonHelper::DoInitialize()
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
PyNs3Uinteger16Probe__PythonHelper::NotifyNewAggregate()
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
PyNs3Uinteger16Probe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Uinteger16Probe__tp_init__0(PyNs3Uinteger16Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Uinteger16Probe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Uinteger16Probe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Uinteger16Probe_Type)
    {
        self->obj = new PyNs3Uinteger16Probe__PythonHelper(*((PyNs3Uinteger16Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Uinteger16Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Uinteger16Probe(*((PyNs3Uinteger16Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3Uinteger16Probe__tp_init__1(PyNs3Uinteger16Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3Uinteger16Probe_Type)
    {
        self->obj = new PyNs3Uinteger16Probe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Uinteger16Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Uinteger16Probe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3Uinteger16Probe__tp_init(PyNs3Uinteger16Probe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Uinteger16Probe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Uinteger16Probe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Uinteger16Probe_SetValueByPath(PyNs3Uinteger16Probe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    int value;
    const char *keywords[] = {"path", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#i", (char **) keywords, &path, &path_len, &value)) {
        return NULL;
    }
    if (value > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    ns3::Uinteger16Probe::SetValueByPath(std::string(path, path_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger16Probe_ConnectByPath(PyNs3Uinteger16Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3Uinteger16Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Uinteger16Probe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::Uinteger16Probe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger16Probe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Uinteger16Probe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger16Probe_GetValue(PyNs3Uinteger16Probe *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetValue();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger16Probe_SetValue(PyNs3Uinteger16Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &value)) {
        return NULL;
    }
    if (value > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger16Probe_ConnectByObject(PyNs3Uinteger16Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3Uinteger16Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Uinteger16Probe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::Uinteger16Probe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3Uinteger16Probe__copy__(PyNs3Uinteger16Probe *self)
{

    PyNs3Uinteger16Probe *py_copy;
    py_copy = PyObject_GC_New(PyNs3Uinteger16Probe, &PyNs3Uinteger16Probe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::Uinteger16Probe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Uinteger16Probe_methods[] = {
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3Uinteger16Probe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3Uinteger16Probe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Uinteger16Probe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetValue", (PyCFunction) _wrap_PyNs3Uinteger16Probe_GetValue, METH_NOARGS, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3Uinteger16Probe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3Uinteger16Probe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Uinteger16Probe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Uinteger16Probe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Uinteger16Probe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Uinteger16Probe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Uinteger16Probe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Uinteger16Probe__tp_clear(PyNs3Uinteger16Probe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Uinteger16Probe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Uinteger16Probe__tp_traverse(PyNs3Uinteger16Probe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Uinteger16Probe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Uinteger16Probe__tp_dealloc(PyNs3Uinteger16Probe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Uinteger16Probe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Uinteger16Probe__tp_richcompare (PyNs3Uinteger16Probe *PYBINDGEN_UNUSED(self), PyNs3Uinteger16Probe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Uinteger16Probe_Type)) {
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

PyTypeObject PyNs3Uinteger16Probe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Uinteger16Probe",            /* tp_name */
    sizeof(PyNs3Uinteger16Probe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Uinteger16Probe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Uinteger16Probe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Uinteger16Probe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Uinteger16Probe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Uinteger16Probe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Uinteger16Probe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Uinteger16Probe__tp_init,             /* tp_init */
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
PyNs3Uinteger32Probe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Uinteger32Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger32Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger32Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger32Probe__PythonHelper::_wrap_DoInitialize(PyNs3Uinteger32Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger32Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger32Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger32Probe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Uinteger32Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger32Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger32Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger32Probe__PythonHelper::_wrap_DoDispose(PyNs3Uinteger32Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger32Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger32Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger32Probe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Uinteger32Probe *self_obj_before;
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
        return ns3::Uinteger32Probe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = (ns3::Uinteger32Probe*) this;
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
        reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Uinteger32Probe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Uinteger32Probe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3Uinteger32Probe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Uinteger32Probe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Uinteger32Probe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = (ns3::Uinteger32Probe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Uinteger32Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3Uinteger32Probe__PythonHelper::IsEnabled() const
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
PyNs3Uinteger32Probe__PythonHelper::GetInstanceTypeId() const
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
PyNs3Uinteger32Probe__PythonHelper::DoDispose()
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
PyNs3Uinteger32Probe__PythonHelper::DoInitialize()
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
PyNs3Uinteger32Probe__PythonHelper::NotifyNewAggregate()
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
PyNs3Uinteger32Probe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Uinteger32Probe__tp_init__0(PyNs3Uinteger32Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Uinteger32Probe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Uinteger32Probe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Uinteger32Probe_Type)
    {
        self->obj = new PyNs3Uinteger32Probe__PythonHelper(*((PyNs3Uinteger32Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Uinteger32Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Uinteger32Probe(*((PyNs3Uinteger32Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3Uinteger32Probe__tp_init__1(PyNs3Uinteger32Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3Uinteger32Probe_Type)
    {
        self->obj = new PyNs3Uinteger32Probe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Uinteger32Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Uinteger32Probe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3Uinteger32Probe__tp_init(PyNs3Uinteger32Probe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Uinteger32Probe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Uinteger32Probe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Uinteger32Probe_SetValueByPath(PyNs3Uinteger32Probe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    unsigned int value;
    const char *keywords[] = {"path", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#I", (char **) keywords, &path, &path_len, &value)) {
        return NULL;
    }
    ns3::Uinteger32Probe::SetValueByPath(std::string(path, path_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger32Probe_ConnectByPath(PyNs3Uinteger32Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3Uinteger32Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Uinteger32Probe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::Uinteger32Probe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger32Probe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Uinteger32Probe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger32Probe_GetValue(PyNs3Uinteger32Probe *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetValue();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger32Probe_SetValue(PyNs3Uinteger32Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &value)) {
        return NULL;
    }
    self->obj->SetValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger32Probe_ConnectByObject(PyNs3Uinteger32Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3Uinteger32Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Uinteger32Probe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::Uinteger32Probe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3Uinteger32Probe__copy__(PyNs3Uinteger32Probe *self)
{

    PyNs3Uinteger32Probe *py_copy;
    py_copy = PyObject_GC_New(PyNs3Uinteger32Probe, &PyNs3Uinteger32Probe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::Uinteger32Probe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Uinteger32Probe_methods[] = {
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3Uinteger32Probe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3Uinteger32Probe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Uinteger32Probe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetValue", (PyCFunction) _wrap_PyNs3Uinteger32Probe_GetValue, METH_NOARGS, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3Uinteger32Probe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3Uinteger32Probe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Uinteger32Probe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Uinteger32Probe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Uinteger32Probe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Uinteger32Probe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Uinteger32Probe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Uinteger32Probe__tp_clear(PyNs3Uinteger32Probe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Uinteger32Probe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Uinteger32Probe__tp_traverse(PyNs3Uinteger32Probe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Uinteger32Probe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Uinteger32Probe__tp_dealloc(PyNs3Uinteger32Probe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Uinteger32Probe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Uinteger32Probe__tp_richcompare (PyNs3Uinteger32Probe *PYBINDGEN_UNUSED(self), PyNs3Uinteger32Probe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Uinteger32Probe_Type)) {
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

PyTypeObject PyNs3Uinteger32Probe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Uinteger32Probe",            /* tp_name */
    sizeof(PyNs3Uinteger32Probe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Uinteger32Probe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Uinteger32Probe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Uinteger32Probe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Uinteger32Probe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Uinteger32Probe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Uinteger32Probe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Uinteger32Probe__tp_init,             /* tp_init */
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
PyNs3Uinteger8Probe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Uinteger8Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger8Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger8Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger8Probe__PythonHelper::_wrap_DoInitialize(PyNs3Uinteger8Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger8Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger8Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger8Probe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Uinteger8Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger8Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger8Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger8Probe__PythonHelper::_wrap_DoDispose(PyNs3Uinteger8Probe *self)
{
    PyObject *py_retval;
    PyNs3Uinteger8Probe__PythonHelper *helper = dynamic_cast< PyNs3Uinteger8Probe__PythonHelper* >(self->obj);
    
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
PyNs3Uinteger8Probe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Uinteger8Probe *self_obj_before;
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
        return ns3::Uinteger8Probe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = (ns3::Uinteger8Probe*) this;
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
        reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Uinteger8Probe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Uinteger8Probe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3Uinteger8Probe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Uinteger8Probe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::Uinteger8Probe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = (ns3::Uinteger8Probe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Uinteger8Probe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3Uinteger8Probe__PythonHelper::IsEnabled() const
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
PyNs3Uinteger8Probe__PythonHelper::GetInstanceTypeId() const
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
PyNs3Uinteger8Probe__PythonHelper::DoDispose()
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
PyNs3Uinteger8Probe__PythonHelper::DoInitialize()
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
PyNs3Uinteger8Probe__PythonHelper::NotifyNewAggregate()
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
PyNs3Uinteger8Probe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Uinteger8Probe__tp_init__0(PyNs3Uinteger8Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Uinteger8Probe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Uinteger8Probe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Uinteger8Probe_Type)
    {
        self->obj = new PyNs3Uinteger8Probe__PythonHelper(*((PyNs3Uinteger8Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Uinteger8Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Uinteger8Probe(*((PyNs3Uinteger8Probe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3Uinteger8Probe__tp_init__1(PyNs3Uinteger8Probe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3Uinteger8Probe_Type)
    {
        self->obj = new PyNs3Uinteger8Probe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Uinteger8Probe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Uinteger8Probe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3Uinteger8Probe__tp_init(PyNs3Uinteger8Probe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Uinteger8Probe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Uinteger8Probe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Uinteger8Probe_SetValueByPath(PyNs3Uinteger8Probe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    int value;
    const char *keywords[] = {"path", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#i", (char **) keywords, &path, &path_len, &value)) {
        return NULL;
    }
    if (value > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    ns3::Uinteger8Probe::SetValueByPath(std::string(path, path_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger8Probe_ConnectByPath(PyNs3Uinteger8Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3Uinteger8Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Uinteger8Probe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::Uinteger8Probe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger8Probe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Uinteger8Probe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger8Probe_GetValue(PyNs3Uinteger8Probe *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetValue();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger8Probe_SetValue(PyNs3Uinteger8Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &value)) {
        return NULL;
    }
    if (value > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Uinteger8Probe_ConnectByObject(PyNs3Uinteger8Probe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3Uinteger8Probe__PythonHelper *helper_class = dynamic_cast<PyNs3Uinteger8Probe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::Uinteger8Probe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3Uinteger8Probe__copy__(PyNs3Uinteger8Probe *self)
{

    PyNs3Uinteger8Probe *py_copy;
    py_copy = PyObject_GC_New(PyNs3Uinteger8Probe, &PyNs3Uinteger8Probe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::Uinteger8Probe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Uinteger8Probe_methods[] = {
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3Uinteger8Probe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3Uinteger8Probe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Uinteger8Probe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetValue", (PyCFunction) _wrap_PyNs3Uinteger8Probe_GetValue, METH_NOARGS, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3Uinteger8Probe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3Uinteger8Probe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Uinteger8Probe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Uinteger8Probe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Uinteger8Probe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Uinteger8Probe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Uinteger8Probe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Uinteger8Probe__tp_clear(PyNs3Uinteger8Probe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Uinteger8Probe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Uinteger8Probe__tp_traverse(PyNs3Uinteger8Probe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Uinteger8Probe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Uinteger8Probe__tp_dealloc(PyNs3Uinteger8Probe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Uinteger8Probe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Uinteger8Probe__tp_richcompare (PyNs3Uinteger8Probe *PYBINDGEN_UNUSED(self), PyNs3Uinteger8Probe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Uinteger8Probe_Type)) {
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

PyTypeObject PyNs3Uinteger8Probe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.Uinteger8Probe",            /* tp_name */
    sizeof(PyNs3Uinteger8Probe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Uinteger8Probe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Uinteger8Probe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Uinteger8Probe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Uinteger8Probe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Uinteger8Probe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Uinteger8Probe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Uinteger8Probe__tp_init,             /* tp_init */
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
PyNs3BooleanProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3BooleanProbe *self)
{
    PyObject *py_retval;
    PyNs3BooleanProbe__PythonHelper *helper = dynamic_cast< PyNs3BooleanProbe__PythonHelper* >(self->obj);
    
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
PyNs3BooleanProbe__PythonHelper::_wrap_DoInitialize(PyNs3BooleanProbe *self)
{
    PyObject *py_retval;
    PyNs3BooleanProbe__PythonHelper *helper = dynamic_cast< PyNs3BooleanProbe__PythonHelper* >(self->obj);
    
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
PyNs3BooleanProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3BooleanProbe *self)
{
    PyObject *py_retval;
    PyNs3BooleanProbe__PythonHelper *helper = dynamic_cast< PyNs3BooleanProbe__PythonHelper* >(self->obj);
    
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
PyNs3BooleanProbe__PythonHelper::_wrap_DoDispose(PyNs3BooleanProbe *self)
{
    PyObject *py_retval;
    PyNs3BooleanProbe__PythonHelper *helper = dynamic_cast< PyNs3BooleanProbe__PythonHelper* >(self->obj);
    
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
PyNs3BooleanProbe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BooleanProbe *self_obj_before;
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
        return ns3::BooleanProbe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = (ns3::BooleanProbe*) this;
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
        reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BooleanProbe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::BooleanProbe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3BooleanProbe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::BooleanProbe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::BooleanProbe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = (ns3::BooleanProbe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3BooleanProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3BooleanProbe__PythonHelper::IsEnabled() const
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
PyNs3BooleanProbe__PythonHelper::GetInstanceTypeId() const
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
PyNs3BooleanProbe__PythonHelper::DoDispose()
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
PyNs3BooleanProbe__PythonHelper::DoInitialize()
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
PyNs3BooleanProbe__PythonHelper::NotifyNewAggregate()
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
PyNs3BooleanProbe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3BooleanProbe__tp_init__0(PyNs3BooleanProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BooleanProbe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BooleanProbe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3BooleanProbe_Type)
    {
        self->obj = new PyNs3BooleanProbe__PythonHelper(*((PyNs3BooleanProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BooleanProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BooleanProbe(*((PyNs3BooleanProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3BooleanProbe__tp_init__1(PyNs3BooleanProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3BooleanProbe_Type)
    {
        self->obj = new PyNs3BooleanProbe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3BooleanProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::BooleanProbe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3BooleanProbe__tp_init(PyNs3BooleanProbe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3BooleanProbe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BooleanProbe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3BooleanProbe_SetValueByPath(PyNs3BooleanProbe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    bool value;
    PyObject *py_value;
    const char *keywords[] = {"path", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O", (char **) keywords, &path, &path_len, &py_value)) {
        return NULL;
    }
    value = (bool) PyObject_IsTrue(py_value);
    ns3::BooleanProbe::SetValueByPath(std::string(path, path_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BooleanProbe_ConnectByPath(PyNs3BooleanProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3BooleanProbe__PythonHelper *helper_class = dynamic_cast<PyNs3BooleanProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::BooleanProbe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BooleanProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::BooleanProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3BooleanProbe_GetValue(PyNs3BooleanProbe *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetValue();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3BooleanProbe_SetValue(PyNs3BooleanProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool value;
    PyObject *py_value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_value)) {
        return NULL;
    }
    value = (bool) PyObject_IsTrue(py_value);
    self->obj->SetValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BooleanProbe_ConnectByObject(PyNs3BooleanProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3BooleanProbe__PythonHelper *helper_class = dynamic_cast<PyNs3BooleanProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::BooleanProbe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3BooleanProbe__copy__(PyNs3BooleanProbe *self)
{

    PyNs3BooleanProbe *py_copy;
    py_copy = PyObject_GC_New(PyNs3BooleanProbe, &PyNs3BooleanProbe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::BooleanProbe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BooleanProbe_methods[] = {
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3BooleanProbe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3BooleanProbe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3BooleanProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetValue", (PyCFunction) _wrap_PyNs3BooleanProbe_GetValue, METH_NOARGS, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3BooleanProbe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3BooleanProbe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3BooleanProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3BooleanProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3BooleanProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3BooleanProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BooleanProbe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3BooleanProbe__tp_clear(PyNs3BooleanProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::BooleanProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3BooleanProbe__tp_traverse(PyNs3BooleanProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3BooleanProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3BooleanProbe__tp_dealloc(PyNs3BooleanProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3BooleanProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BooleanProbe__tp_richcompare (PyNs3BooleanProbe *PYBINDGEN_UNUSED(self), PyNs3BooleanProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BooleanProbe_Type)) {
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

PyTypeObject PyNs3BooleanProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.BooleanProbe",            /* tp_name */
    sizeof(PyNs3BooleanProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BooleanProbe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3BooleanProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3BooleanProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3BooleanProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BooleanProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3BooleanProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BooleanProbe__tp_init,             /* tp_init */
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
PyNs3DoubleProbe__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3DoubleProbe *self)
{
    PyObject *py_retval;
    PyNs3DoubleProbe__PythonHelper *helper = dynamic_cast< PyNs3DoubleProbe__PythonHelper* >(self->obj);
    
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
PyNs3DoubleProbe__PythonHelper::_wrap_DoInitialize(PyNs3DoubleProbe *self)
{
    PyObject *py_retval;
    PyNs3DoubleProbe__PythonHelper *helper = dynamic_cast< PyNs3DoubleProbe__PythonHelper* >(self->obj);
    
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
PyNs3DoubleProbe__PythonHelper::_wrap_NotifyNewAggregate(PyNs3DoubleProbe *self)
{
    PyObject *py_retval;
    PyNs3DoubleProbe__PythonHelper *helper = dynamic_cast< PyNs3DoubleProbe__PythonHelper* >(self->obj);
    
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
PyNs3DoubleProbe__PythonHelper::_wrap_DoDispose(PyNs3DoubleProbe *self)
{
    PyObject *py_retval;
    PyNs3DoubleProbe__PythonHelper *helper = dynamic_cast< PyNs3DoubleProbe__PythonHelper* >(self->obj);
    
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
PyNs3DoubleProbe__PythonHelper::ConnectByObject(std::string traceSource, ns3::Ptr< ns3::Object > obj)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DoubleProbe *self_obj_before;
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
        return ns3::DoubleProbe::ConnectByObject(traceSource, obj);
    }
    self_obj_before = reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = (ns3::DoubleProbe*) this;
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
        reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::DoubleProbe::ConnectByObject(traceSource, obj);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::DoubleProbe::ConnectByObject(traceSource, obj);
    }
    retval = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3DoubleProbe__PythonHelper::ConnectByPath(std::string path)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::DoubleProbe *self_obj_before;
    PyObject *py_retval;
    const char *path_ptr;
    Py_ssize_t path_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "ConnectByPath"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::DoubleProbe::ConnectByPath(path);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj;
    reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = (ns3::DoubleProbe*) this;
    path_ptr = (path).c_str();
    path_len = (path).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "ConnectByPath", (char *) "s#", path_ptr, path_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3DoubleProbe* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

bool
PyNs3DoubleProbe__PythonHelper::IsEnabled() const
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
PyNs3DoubleProbe__PythonHelper::GetInstanceTypeId() const
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
PyNs3DoubleProbe__PythonHelper::DoDispose()
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
PyNs3DoubleProbe__PythonHelper::DoInitialize()
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
PyNs3DoubleProbe__PythonHelper::NotifyNewAggregate()
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
PyNs3DoubleProbe__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3DoubleProbe__tp_init__0(PyNs3DoubleProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3DoubleProbe *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3DoubleProbe_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3DoubleProbe_Type)
    {
        self->obj = new PyNs3DoubleProbe__PythonHelper(*((PyNs3DoubleProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DoubleProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::DoubleProbe(*((PyNs3DoubleProbe *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3DoubleProbe__tp_init__1(PyNs3DoubleProbe *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3DoubleProbe_Type)
    {
        self->obj = new PyNs3DoubleProbe__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3DoubleProbe__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::DoubleProbe();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3DoubleProbe__tp_init(PyNs3DoubleProbe *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3DoubleProbe__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3DoubleProbe__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3DoubleProbe_SetValueByPath(PyNs3DoubleProbe *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    double value;
    const char *keywords[] = {"path", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#d", (char **) keywords, &path, &path_len, &value)) {
        return NULL;
    }
    ns3::DoubleProbe::SetValueByPath(std::string(path, path_len), value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DoubleProbe_ConnectByPath(PyNs3DoubleProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *path;
    Py_ssize_t path_len;
    PyNs3DoubleProbe__PythonHelper *helper_class = dynamic_cast<PyNs3DoubleProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"path", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &path, &path_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->ConnectByPath(std::string(path, path_len))) : (self->obj->ns3::DoubleProbe::ConnectByPath(std::string(path, path_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DoubleProbe_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::DoubleProbe::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3DoubleProbe_GetValue(PyNs3DoubleProbe *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetValue();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3DoubleProbe_SetValue(PyNs3DoubleProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &value)) {
        return NULL;
    }
    self->obj->SetValue(value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3DoubleProbe_ConnectByObject(PyNs3DoubleProbe *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *traceSource;
    Py_ssize_t traceSource_len;
    PyNs3Object *obj;
    ns3::Object *obj_ptr;
    PyNs3DoubleProbe__PythonHelper *helper_class = dynamic_cast<PyNs3DoubleProbe__PythonHelper*> (self->obj);
    const char *keywords[] = {"traceSource", "obj", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &traceSource, &traceSource_len, &PyNs3Object_Type, &obj)) {
        return NULL;
    }
    obj_ptr = (obj ? obj->obj : NULL);
    retval = (helper_class == NULL)? (self->obj->ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr))) : (self->obj->ns3::DoubleProbe::ConnectByObject(std::string(traceSource, traceSource_len), ns3::Ptr< ns3::Object  > (obj_ptr)));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3DoubleProbe__copy__(PyNs3DoubleProbe *self)
{

    PyNs3DoubleProbe *py_copy;
    py_copy = PyObject_GC_New(PyNs3DoubleProbe, &PyNs3DoubleProbe_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::DoubleProbe(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3DoubleProbe_methods[] = {
    {(char *) "SetValueByPath", (PyCFunction) _wrap_PyNs3DoubleProbe_SetValueByPath, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "ConnectByPath", (PyCFunction) _wrap_PyNs3DoubleProbe_ConnectByPath, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3DoubleProbe_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetValue", (PyCFunction) _wrap_PyNs3DoubleProbe_GetValue, METH_NOARGS, NULL },
    {(char *) "SetValue", (PyCFunction) _wrap_PyNs3DoubleProbe_SetValue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ConnectByObject", (PyCFunction) _wrap_PyNs3DoubleProbe_ConnectByObject, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3DoubleProbe__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3DoubleProbe__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3DoubleProbe__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3DoubleProbe__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3DoubleProbe__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3DoubleProbe__tp_clear(PyNs3DoubleProbe *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::DoubleProbe *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3DoubleProbe__tp_traverse(PyNs3DoubleProbe *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3DoubleProbe__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3DoubleProbe__tp_dealloc(PyNs3DoubleProbe *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3DoubleProbe__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3DoubleProbe__tp_richcompare (PyNs3DoubleProbe *PYBINDGEN_UNUSED(self), PyNs3DoubleProbe *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3DoubleProbe_Type)) {
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

PyTypeObject PyNs3DoubleProbe_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "stats.DoubleProbe",            /* tp_name */
    sizeof(PyNs3DoubleProbe),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3DoubleProbe__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3DoubleProbe__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3DoubleProbe__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3DoubleProbe__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3DoubleProbe_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3DoubleProbe, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3DoubleProbe__tp_init,             /* tp_init */
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
static struct PyModuleDef stats_moduledef = {
    PyModuleDef_HEAD_INIT,
    "stats",
    NULL,
    -1,
    stats_functions,
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


MOD_INIT(stats)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&stats_moduledef);
    #else
    m = Py_InitModule3((char *) "stats", stats_functions, NULL);
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
    /* Import the 'ns3::TracedValue< bool >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TracedValue__Bool_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TracedValue__Bool");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TracedValue__Bool_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TracedValue__Bool_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TracedValue__Bool_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::TracedValue< unsigned char >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TracedValue__Unsigned_char_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TracedValue__Unsigned_char");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TracedValue__Unsigned_char_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TracedValue__Unsigned_char_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TracedValue__Unsigned_char_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TracedValue< unsigned int >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TracedValue__Unsigned_int_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TracedValue__Unsigned_int");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TracedValue__Unsigned_int_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TracedValue__Unsigned_int_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TracedValue__Unsigned_int_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TracedValue< unsigned short >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TracedValue__Unsigned_short_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TracedValue__Unsigned_short");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TracedValue__Unsigned_short_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TracedValue__Unsigned_short_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TracedValue__Unsigned_short_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    PyModule_AddObject(m, (char *) "_PyNs3DataOutputCallback_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3DataOutputCallback_wrapper_registry, NULL));
    /* Register the 'ns3::DataOutputCallback' class */
    if (PyType_Ready(&PyNs3DataOutputCallback_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DataOutputCallback", (PyObject *) &PyNs3DataOutputCallback_Type);
    PyModule_AddObject(m, (char *) "_PyNs3FileHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3FileHelper_wrapper_registry, NULL));
    /* Register the 'ns3::FileHelper' class */
    if (PyType_Ready(&PyNs3FileHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FileHelper", (PyObject *) &PyNs3FileHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Gnuplot_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Gnuplot_wrapper_registry, NULL));
    /* Register the 'ns3::Gnuplot' class */
    if (PyType_Ready(&PyNs3Gnuplot_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Gnuplot", (PyObject *) &PyNs3Gnuplot_Type);
    PyModule_AddObject(m, (char *) "_PyNs3GnuplotCollection_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3GnuplotCollection_wrapper_registry, NULL));
    /* Register the 'ns3::GnuplotCollection' class */
    if (PyType_Ready(&PyNs3GnuplotCollection_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GnuplotCollection", (PyObject *) &PyNs3GnuplotCollection_Type);
    PyModule_AddObject(m, (char *) "_PyNs3GnuplotDataset_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3GnuplotDataset_wrapper_registry, NULL));
    /* Register the 'ns3::GnuplotDataset' class */
    if (PyType_Ready(&PyNs3GnuplotDataset_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GnuplotDataset", (PyObject *) &PyNs3GnuplotDataset_Type);
    PyModule_AddObject(m, (char *) "_PyNs3GnuplotHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3GnuplotHelper_wrapper_registry, NULL));
    /* Register the 'ns3::GnuplotHelper' class */
    if (PyType_Ready(&PyNs3GnuplotHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GnuplotHelper", (PyObject *) &PyNs3GnuplotHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3StatisticalSummary_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3StatisticalSummary_wrapper_registry, NULL));
    /* Register the 'ns3::StatisticalSummary' class */
    if (PyType_Ready(&PyNs3StatisticalSummary_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "StatisticalSummary", (PyObject *) &PyNs3StatisticalSummary_Type);
    /* Register the 'ns3::Gnuplot2dDataset' class */
    PyNs3Gnuplot2dDataset_Type.tp_base = &PyNs3GnuplotDataset_Type;
    if (PyType_Ready(&PyNs3Gnuplot2dDataset_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Gnuplot2dDataset", (PyObject *) &PyNs3Gnuplot2dDataset_Type);
    /* Register the 'ns3::Gnuplot2dFunction' class */
    PyNs3Gnuplot2dFunction_Type.tp_base = &PyNs3GnuplotDataset_Type;
    if (PyType_Ready(&PyNs3Gnuplot2dFunction_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Gnuplot2dFunction", (PyObject *) &PyNs3Gnuplot2dFunction_Type);
    /* Register the 'ns3::Gnuplot3dDataset' class */
    PyNs3Gnuplot3dDataset_Type.tp_base = &PyNs3GnuplotDataset_Type;
    if (PyType_Ready(&PyNs3Gnuplot3dDataset_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Gnuplot3dDataset", (PyObject *) &PyNs3Gnuplot3dDataset_Type);
    /* Register the 'ns3::Gnuplot3dFunction' class */
    PyNs3Gnuplot3dFunction_Type.tp_base = &PyNs3GnuplotDataset_Type;
    if (PyType_Ready(&PyNs3Gnuplot3dFunction_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Gnuplot3dFunction", (PyObject *) &PyNs3Gnuplot3dFunction_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::DataCalculator), &PyNs3DataCalculator_Type);
    /* Register the 'ns3::DataCalculator' class */
    PyNs3DataCalculator_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3DataCalculator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DataCalculator", (PyObject *) &PyNs3DataCalculator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::DataCollectionObject), &PyNs3DataCollectionObject_Type);
    /* Register the 'ns3::DataCollectionObject' class */
    PyNs3DataCollectionObject_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3DataCollectionObject_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DataCollectionObject", (PyObject *) &PyNs3DataCollectionObject_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::DataCollector), &PyNs3DataCollector_Type);
    /* Register the 'ns3::DataCollector' class */
    PyNs3DataCollector_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3DataCollector_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DataCollector", (PyObject *) &PyNs3DataCollector_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::DataOutputInterface), &PyNs3DataOutputInterface_Type);
    /* Register the 'ns3::DataOutputInterface' class */
    PyNs3DataOutputInterface_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3DataOutputInterface_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DataOutputInterface", (PyObject *) &PyNs3DataOutputInterface_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::FileAggregator), &PyNs3FileAggregator_Type);
    /* Register the 'ns3::FileAggregator' class */
    PyNs3FileAggregator_Type.tp_base = &PyNs3DataCollectionObject_Type;
    if (PyType_Ready(&PyNs3FileAggregator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FileAggregator", (PyObject *) &PyNs3FileAggregator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::GnuplotAggregator), &PyNs3GnuplotAggregator_Type);
    /* Register the 'ns3::GnuplotAggregator' class */
    PyNs3GnuplotAggregator_Type.tp_base = &PyNs3DataCollectionObject_Type;
    if (PyType_Ready(&PyNs3GnuplotAggregator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GnuplotAggregator", (PyObject *) &PyNs3GnuplotAggregator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::MinMaxAvgTotalCalculator< double >), &PyNs3MinMaxAvgTotalCalculator__Double_Type);
    /* Register the 'ns3::MinMaxAvgTotalCalculator< double >' class */
    PyNs3MinMaxAvgTotalCalculator__Double_Type.tp_base = &PyNs3DataCalculator_Type;
    PyNs3MinMaxAvgTotalCalculator__Double_Type.tp_bases = PyTuple_New(2);
        Py_INCREF((PyObject *) &PyNs3DataCalculator_Type);
        PyTuple_SET_ITEM(PyNs3MinMaxAvgTotalCalculator__Double_Type.tp_bases, 0, (PyObject *) &PyNs3DataCalculator_Type);
        Py_INCREF((PyObject *) &PyNs3StatisticalSummary_Type);
        PyTuple_SET_ITEM(PyNs3MinMaxAvgTotalCalculator__Double_Type.tp_bases, 1, (PyObject *) &PyNs3StatisticalSummary_Type);
    if (PyType_Ready(&PyNs3MinMaxAvgTotalCalculator__Double_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "MinMaxAvgTotalCalculator__Double", (PyObject *) &PyNs3MinMaxAvgTotalCalculator__Double_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::OmnetDataOutput), &PyNs3OmnetDataOutput_Type);
    /* Register the 'ns3::OmnetDataOutput' class */
    PyNs3OmnetDataOutput_Type.tp_base = &PyNs3DataOutputInterface_Type;
    if (PyType_Ready(&PyNs3OmnetDataOutput_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "OmnetDataOutput", (PyObject *) &PyNs3OmnetDataOutput_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Probe), &PyNs3Probe_Type);
    /* Register the 'ns3::Probe' class */
    PyNs3Probe_Type.tp_base = &PyNs3DataCollectionObject_Type;
    if (PyType_Ready(&PyNs3Probe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Probe", (PyObject *) &PyNs3Probe_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::TimeMinMaxAvgTotalCalculator), &PyNs3TimeMinMaxAvgTotalCalculator_Type);
    /* Register the 'ns3::TimeMinMaxAvgTotalCalculator' class */
    PyNs3TimeMinMaxAvgTotalCalculator_Type.tp_base = &PyNs3DataCalculator_Type;
    if (PyType_Ready(&PyNs3TimeMinMaxAvgTotalCalculator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "TimeMinMaxAvgTotalCalculator", (PyObject *) &PyNs3TimeMinMaxAvgTotalCalculator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::TimeProbe), &PyNs3TimeProbe_Type);
    /* Register the 'ns3::TimeProbe' class */
    PyNs3TimeProbe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3TimeProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "TimeProbe", (PyObject *) &PyNs3TimeProbe_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::TimeSeriesAdaptor), &PyNs3TimeSeriesAdaptor_Type);
    /* Register the 'ns3::TimeSeriesAdaptor' class */
    PyNs3TimeSeriesAdaptor_Type.tp_base = &PyNs3DataCollectionObject_Type;
    if (PyType_Ready(&PyNs3TimeSeriesAdaptor_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "TimeSeriesAdaptor", (PyObject *) &PyNs3TimeSeriesAdaptor_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Uinteger16Probe), &PyNs3Uinteger16Probe_Type);
    /* Register the 'ns3::Uinteger16Probe' class */
    PyNs3Uinteger16Probe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3Uinteger16Probe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Uinteger16Probe", (PyObject *) &PyNs3Uinteger16Probe_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Uinteger32Probe), &PyNs3Uinteger32Probe_Type);
    /* Register the 'ns3::Uinteger32Probe' class */
    PyNs3Uinteger32Probe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3Uinteger32Probe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Uinteger32Probe", (PyObject *) &PyNs3Uinteger32Probe_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Uinteger8Probe), &PyNs3Uinteger8Probe_Type);
    /* Register the 'ns3::Uinteger8Probe' class */
    PyNs3Uinteger8Probe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3Uinteger8Probe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Uinteger8Probe", (PyObject *) &PyNs3Uinteger8Probe_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::BooleanProbe), &PyNs3BooleanProbe_Type);
    /* Register the 'ns3::BooleanProbe' class */
    PyNs3BooleanProbe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3BooleanProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BooleanProbe", (PyObject *) &PyNs3BooleanProbe_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::DoubleProbe), &PyNs3DoubleProbe_Type);
    /* Register the 'ns3::DoubleProbe' class */
    PyNs3DoubleProbe_Type.tp_base = &PyNs3Probe_Type;
    if (PyType_Ready(&PyNs3DoubleProbe_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "DoubleProbe", (PyObject *) &PyNs3DoubleProbe_Type);
    {
        PyObject *tmp_value;
         // ns3::Gnuplot2dDataset::LINES
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::LINES);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "LINES", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::POINTS
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::POINTS);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "POINTS", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::LINES_POINTS
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::LINES_POINTS);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "LINES_POINTS", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::DOTS
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::DOTS);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "DOTS", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::IMPULSES
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::IMPULSES);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "IMPULSES", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::STEPS
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::STEPS);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "STEPS", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::FSTEPS
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::FSTEPS);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "FSTEPS", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::HISTEPS
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::HISTEPS);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "HISTEPS", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::Gnuplot2dDataset::NONE
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::NONE);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "NONE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::X
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::X);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "X", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::Y
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::Y);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "Y", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Gnuplot2dDataset::XY
        tmp_value = PyLong_FromLong(ns3::Gnuplot2dDataset::XY);
        PyDict_SetItemString((PyObject*) PyNs3Gnuplot2dDataset_Type.tp_dict, "XY", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::FileAggregator::FORMATTED
        tmp_value = PyLong_FromLong(ns3::FileAggregator::FORMATTED);
        PyDict_SetItemString((PyObject*) PyNs3FileAggregator_Type.tp_dict, "FORMATTED", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::FileAggregator::SPACE_SEPARATED
        tmp_value = PyLong_FromLong(ns3::FileAggregator::SPACE_SEPARATED);
        PyDict_SetItemString((PyObject*) PyNs3FileAggregator_Type.tp_dict, "SPACE_SEPARATED", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::FileAggregator::COMMA_SEPARATED
        tmp_value = PyLong_FromLong(ns3::FileAggregator::COMMA_SEPARATED);
        PyDict_SetItemString((PyObject*) PyNs3FileAggregator_Type.tp_dict, "COMMA_SEPARATED", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::FileAggregator::TAB_SEPARATED
        tmp_value = PyLong_FromLong(ns3::FileAggregator::TAB_SEPARATED);
        PyDict_SetItemString((PyObject*) PyNs3FileAggregator_Type.tp_dict, "TAB_SEPARATED", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::GnuplotAggregator::NO_KEY
        tmp_value = PyLong_FromLong(ns3::GnuplotAggregator::NO_KEY);
        PyDict_SetItemString((PyObject*) PyNs3GnuplotAggregator_Type.tp_dict, "NO_KEY", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::GnuplotAggregator::KEY_INSIDE
        tmp_value = PyLong_FromLong(ns3::GnuplotAggregator::KEY_INSIDE);
        PyDict_SetItemString((PyObject*) PyNs3GnuplotAggregator_Type.tp_dict, "KEY_INSIDE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::GnuplotAggregator::KEY_ABOVE
        tmp_value = PyLong_FromLong(ns3::GnuplotAggregator::KEY_ABOVE);
        PyDict_SetItemString((PyObject*) PyNs3GnuplotAggregator_Type.tp_dict, "KEY_ABOVE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::GnuplotAggregator::KEY_BELOW
        tmp_value = PyLong_FromLong(ns3::GnuplotAggregator::KEY_BELOW);
        PyDict_SetItemString((PyObject*) PyNs3GnuplotAggregator_Type.tp_dict, "KEY_BELOW", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initstats_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initstats_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initstats_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    submodule = initstats_internal();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "internal", submodule);
    return MOD_RETURN(m);
}
