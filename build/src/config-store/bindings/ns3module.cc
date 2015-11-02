#include "ns3module.h"
static PyMethodDef config_store_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef config_store_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "config_store.FatalImpl",
    NULL,
    -1,
    config_store_FatalImpl_functions,
};
#endif

static PyObject *
initconfig_store_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&config_store_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "config_store.FatalImpl", config_store_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef config_store_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef config_store_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "config_store.Hash.Function",
    NULL,
    -1,
    config_store_Hash_Function_functions,
};
#endif

static PyObject *
initconfig_store_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&config_store_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "config_store.Hash.Function", config_store_Hash_Function_functions, NULL);
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
static PyMethodDef config_store_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef config_store_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "config_store.Hash",
    NULL,
    -1,
    config_store_Hash_functions,
};
#endif

static PyObject *
initconfig_store_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&config_store_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "config_store.Hash", config_store_Hash_functions, NULL);
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
    submodule = initconfig_store_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef config_store_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3CallbackBase_Type;
std::map<void*, PyObject*> *_PyNs3CallbackBase_wrapper_registry;


PyTypeObject *_PyNs3Hasher_Type;
std::map<void*, PyObject*> *_PyNs3Hasher_wrapper_registry;


PyTypeObject *_PyNs3ObjectBase_Type;
std::map<void*, PyObject*> *_PyNs3ObjectBase_wrapper_registry;


PyTypeObject *_PyNs3TypeId_Type;
std::map<void*, PyObject*> *_PyNs3TypeId_wrapper_registry;


PyTypeObject *_PyNs3TypeIdAttributeInformation_Type;
std::map<void*, PyObject*> *_PyNs3TypeIdAttributeInformation_wrapper_registry;


PyTypeObject *_PyNs3TypeIdTraceSourceInformation_Type;
std::map<void*, PyObject*> *_PyNs3TypeIdTraceSourceInformation_wrapper_registry;


PyTypeObject *_PyNs3Empty_Type;
std::map<void*, PyObject*> *_PyNs3Empty_wrapper_registry;


PyTypeObject *_PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3AttributeAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeAccessor__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3CallbackImplBase_Ns3Empty_Ns3DefaultDeleter__lt__ns3CallbackImplBase__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


PyTypeObject *_PyNs3AttributeAccessor_Type;


PyTypeObject *_PyNs3AttributeChecker_Type;


PyTypeObject *_PyNs3AttributeValue_Type;


PyTypeObject *_PyNs3CallbackChecker_Type;


PyTypeObject *_PyNs3CallbackImplBase_Type;


PyTypeObject *_PyNs3CallbackValue_Type;


PyTypeObject *_PyNs3EmptyAttributeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


std::map<void*, PyObject*> PyNs3FileConfig_wrapper_registry;

void
PyNs3FileConfig__PythonHelper::Attributes()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FileConfig *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Attributes"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = (ns3::FileConfig*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Attributes", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FileConfig__PythonHelper::Default()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FileConfig *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Default"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = (ns3::FileConfig*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Default", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FileConfig__PythonHelper::Global()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FileConfig *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Global"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = (ns3::FileConfig*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Global", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3FileConfig__PythonHelper::SetFilename(std::string filename)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FileConfig *self_obj_before;
    PyObject *py_retval;
    const char *filename_ptr;
    Py_ssize_t filename_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "SetFilename"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = (ns3::FileConfig*) this;
    filename_ptr = (filename).c_str();
    filename_len = (filename).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "SetFilename", (char *) "s#", filename_ptr, filename_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3FileConfig__tp_init__0(PyNs3FileConfig *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3FileConfig_Type)
    {
        self->obj = new PyNs3FileConfig__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FileConfig__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'FileConfig' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3FileConfig__tp_init__1(PyNs3FileConfig *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3FileConfig *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3FileConfig_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3FileConfig_Type)
    {
        self->obj = new PyNs3FileConfig__PythonHelper(*((PyNs3FileConfig *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FileConfig__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'FileConfig' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3FileConfig__tp_init(PyNs3FileConfig *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3FileConfig__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3FileConfig__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3FileConfig_Default(PyNs3FileConfig *self)
{
    PyObject *py_retval;
    
    self->obj->Default();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileConfig_Attributes(PyNs3FileConfig *self)
{
    PyObject *py_retval;
    
    self->obj->Attributes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileConfig_Global(PyNs3FileConfig *self)
{
    PyObject *py_retval;
    
    self->obj->Global();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FileConfig_SetFilename(PyNs3FileConfig *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &filename, &filename_len)) {
        return NULL;
    }
    self->obj->SetFilename(std::string(filename, filename_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3FileConfig_methods[] = {
    {(char *) "Default", (PyCFunction) _wrap_PyNs3FileConfig_Default, METH_NOARGS, NULL },
    {(char *) "Attributes", (PyCFunction) _wrap_PyNs3FileConfig_Attributes, METH_NOARGS, NULL },
    {(char *) "Global", (PyCFunction) _wrap_PyNs3FileConfig_Global, METH_NOARGS, NULL },
    {(char *) "SetFilename", (PyCFunction) _wrap_PyNs3FileConfig_SetFilename, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FileConfig__tp_clear(PyNs3FileConfig *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::FileConfig *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3FileConfig__tp_traverse(PyNs3FileConfig *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3FileConfig__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3FileConfig__tp_dealloc(PyNs3FileConfig *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FileConfig_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FileConfig_wrapper_registry.end()) {
        PyNs3FileConfig_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FileConfig__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FileConfig__tp_richcompare (PyNs3FileConfig *PYBINDGEN_UNUSED(self), PyNs3FileConfig *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FileConfig_Type)) {
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

PyTypeObject PyNs3FileConfig_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "config_store.FileConfig",            /* tp_name */
    sizeof(PyNs3FileConfig),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FileConfig__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3FileConfig__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FileConfig__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FileConfig__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FileConfig_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FileConfig, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FileConfig__tp_init,             /* tp_init */
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
PyNs3NoneFileConfig__PythonHelper::Attributes()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::NoneFileConfig *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Attributes"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::NoneFileConfig::Attributes();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = (ns3::NoneFileConfig*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Attributes", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3NoneFileConfig__PythonHelper::Default()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::NoneFileConfig *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Default"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::NoneFileConfig::Default();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = (ns3::NoneFileConfig*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Default", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3NoneFileConfig__PythonHelper::Global()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::NoneFileConfig *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "Global"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::NoneFileConfig::Global();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = (ns3::NoneFileConfig*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "Global", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3NoneFileConfig__PythonHelper::SetFilename(std::string filename)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::NoneFileConfig *self_obj_before;
    PyObject *py_retval;
    const char *filename_ptr;
    Py_ssize_t filename_len;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "SetFilename"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::NoneFileConfig::SetFilename(filename);
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj;
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = (ns3::NoneFileConfig*) this;
    filename_ptr = (filename).c_str();
    filename_len = (filename).size();
    py_retval = PyObject_CallMethod(m_pyself, (char *) "SetFilename", (char *) "s#", filename_ptr, filename_len);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3NoneFileConfig* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}


static int
_wrap_PyNs3NoneFileConfig__tp_init__0(PyNs3NoneFileConfig *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3NoneFileConfig *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NoneFileConfig_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3NoneFileConfig_Type)
    {
        self->obj = new PyNs3NoneFileConfig__PythonHelper(*((PyNs3NoneFileConfig *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3NoneFileConfig__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::NoneFileConfig(*((PyNs3NoneFileConfig *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3NoneFileConfig__tp_init__1(PyNs3NoneFileConfig *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3NoneFileConfig_Type)
    {
        self->obj = new PyNs3NoneFileConfig__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3NoneFileConfig__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::NoneFileConfig();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3NoneFileConfig__tp_init(PyNs3NoneFileConfig *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3NoneFileConfig__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3NoneFileConfig__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3NoneFileConfig_Default(PyNs3NoneFileConfig *self)
{
    PyObject *py_retval;
    PyNs3NoneFileConfig__PythonHelper *helper_class = dynamic_cast<PyNs3NoneFileConfig__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->Default()) : (self->obj->ns3::NoneFileConfig::Default());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NoneFileConfig_Attributes(PyNs3NoneFileConfig *self)
{
    PyObject *py_retval;
    PyNs3NoneFileConfig__PythonHelper *helper_class = dynamic_cast<PyNs3NoneFileConfig__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->Attributes()) : (self->obj->ns3::NoneFileConfig::Attributes());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NoneFileConfig_Global(PyNs3NoneFileConfig *self)
{
    PyObject *py_retval;
    PyNs3NoneFileConfig__PythonHelper *helper_class = dynamic_cast<PyNs3NoneFileConfig__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->Global()) : (self->obj->ns3::NoneFileConfig::Global());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3NoneFileConfig_SetFilename(PyNs3NoneFileConfig *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *filename;
    Py_ssize_t filename_len;
    PyNs3NoneFileConfig__PythonHelper *helper_class = dynamic_cast<PyNs3NoneFileConfig__PythonHelper*> (self->obj);
    const char *keywords[] = {"filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &filename, &filename_len)) {
        return NULL;
    }
    (helper_class == NULL)? (self->obj->SetFilename(std::string(filename, filename_len))) : (self->obj->ns3::NoneFileConfig::SetFilename(std::string(filename, filename_len)));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3NoneFileConfig__copy__(PyNs3NoneFileConfig *self)
{

    PyNs3NoneFileConfig *py_copy;
    py_copy = PyObject_GC_New(PyNs3NoneFileConfig, &PyNs3NoneFileConfig_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::NoneFileConfig(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3FileConfig_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3NoneFileConfig_methods[] = {
    {(char *) "Default", (PyCFunction) _wrap_PyNs3NoneFileConfig_Default, METH_NOARGS, NULL },
    {(char *) "Attributes", (PyCFunction) _wrap_PyNs3NoneFileConfig_Attributes, METH_NOARGS, NULL },
    {(char *) "Global", (PyCFunction) _wrap_PyNs3NoneFileConfig_Global, METH_NOARGS, NULL },
    {(char *) "SetFilename", (PyCFunction) _wrap_PyNs3NoneFileConfig_SetFilename, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3NoneFileConfig__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3NoneFileConfig__tp_clear(PyNs3NoneFileConfig *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::NoneFileConfig *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3NoneFileConfig__tp_traverse(PyNs3NoneFileConfig *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3NoneFileConfig__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3NoneFileConfig__tp_dealloc(PyNs3NoneFileConfig *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3FileConfig_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3FileConfig_wrapper_registry.end()) {
        PyNs3FileConfig_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3NoneFileConfig__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NoneFileConfig__tp_richcompare (PyNs3NoneFileConfig *PYBINDGEN_UNUSED(self), PyNs3NoneFileConfig *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NoneFileConfig_Type)) {
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

PyTypeObject PyNs3NoneFileConfig_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "config_store.NoneFileConfig",            /* tp_name */
    sizeof(PyNs3NoneFileConfig),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NoneFileConfig__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3NoneFileConfig__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NoneFileConfig__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NoneFileConfig__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NoneFileConfig_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3NoneFileConfig, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NoneFileConfig__tp_init,             /* tp_init */
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
PyNs3ConfigStore__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ConfigStore *self)
{
    PyObject *py_retval;
    PyNs3ConfigStore__PythonHelper *helper = dynamic_cast< PyNs3ConfigStore__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyConstructionCompleted of class ObjectBase is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyConstructionCompleted__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::TypeId
PyNs3ConfigStore__PythonHelper::GetInstanceTypeId() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConfigStore *self_obj_before;
    PyObject *py_retval;
    PyNs3TypeId *tmp_TypeId;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetInstanceTypeId"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ConfigStore::GetInstanceTypeId();
    }
    self_obj_before = reinterpret_cast< PyNs3ConfigStore* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConfigStore* >(m_pyself)->obj = const_cast< ns3::ConfigStore* >((const ns3::ConfigStore*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetInstanceTypeId", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConfigStore* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ConfigStore::GetInstanceTypeId();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3TypeId_Type, &tmp_TypeId)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConfigStore* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ConfigStore::GetInstanceTypeId();
    }
    ns3::TypeId retval = *tmp_TypeId->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConfigStore* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3ConfigStore__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ConfigStore__tp_init__0(PyNs3ConfigStore *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ConfigStore *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ConfigStore_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ConfigStore_Type)
    {
        self->obj = new PyNs3ConfigStore__PythonHelper(*((PyNs3ConfigStore *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConfigStore__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConfigStore(*((PyNs3ConfigStore *) arg0)->obj);
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

static int
_wrap_PyNs3ConfigStore__tp_init__1(PyNs3ConfigStore *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ConfigStore_Type)
    {
        self->obj = new PyNs3ConfigStore__PythonHelper();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConfigStore__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConfigStore();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    }
    return 0;
}

int _wrap_PyNs3ConfigStore__tp_init(PyNs3ConfigStore *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ConfigStore__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConfigStore__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ConfigStore_ConfigureAttributes(PyNs3ConfigStore *self)
{
    PyObject *py_retval;
    
    self->obj->ConfigureAttributes();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConfigStore_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ConfigStore::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConfigStore_ConfigureDefaults(PyNs3ConfigStore *self)
{
    PyObject *py_retval;
    
    self->obj->ConfigureDefaults();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConfigStore_SetFilename(PyNs3ConfigStore *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &filename, &filename_len)) {
        return NULL;
    }
    self->obj->SetFilename(std::string(filename, filename_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConfigStore_SetMode(PyNs3ConfigStore *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::ConfigStore::Mode mode;
    const char *keywords[] = {"mode", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &mode)) {
        return NULL;
    }
    self->obj->SetMode(mode);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConfigStore_GetInstanceTypeId(PyNs3ConfigStore *self)
{
    PyObject *py_retval;
    PyNs3ConfigStore__PythonHelper *helper_class = dynamic_cast<PyNs3ConfigStore__PythonHelper*> (self->obj);
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = (helper_class == NULL)? (self->obj->GetInstanceTypeId()) : (self->obj->ns3::ConfigStore::GetInstanceTypeId());
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConfigStore_SetFileFormat(PyNs3ConfigStore *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::ConfigStore::FileFormat format;
    const char *keywords[] = {"format", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &format)) {
        return NULL;
    }
    self->obj->SetFileFormat(format);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3ConfigStore__copy__(PyNs3ConfigStore *self)
{

    PyNs3ConfigStore *py_copy;
    py_copy = PyObject_GC_New(PyNs3ConfigStore, &PyNs3ConfigStore_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::ConfigStore(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ConfigStore_methods[] = {
    {(char *) "ConfigureAttributes", (PyCFunction) _wrap_PyNs3ConfigStore_ConfigureAttributes, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ConfigStore_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "ConfigureDefaults", (PyCFunction) _wrap_PyNs3ConfigStore_ConfigureDefaults, METH_NOARGS, NULL },
    {(char *) "SetFilename", (PyCFunction) _wrap_PyNs3ConfigStore_SetFilename, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMode", (PyCFunction) _wrap_PyNs3ConfigStore_SetMode, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3ConfigStore_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "SetFileFormat", (PyCFunction) _wrap_PyNs3ConfigStore_SetFileFormat, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ConfigStore__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ConfigStore__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ConfigStore__tp_clear(PyNs3ConfigStore *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::ConfigStore *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3ConfigStore__tp_traverse(PyNs3ConfigStore *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ConfigStore__PythonHelper).name() )
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ConfigStore__tp_dealloc(PyNs3ConfigStore *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ConfigStore__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ConfigStore__tp_richcompare (PyNs3ConfigStore *PYBINDGEN_UNUSED(self), PyNs3ConfigStore *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ConfigStore_Type)) {
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

PyTypeObject PyNs3ConfigStore_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "config_store.ConfigStore",            /* tp_name */
    sizeof(PyNs3ConfigStore),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ConfigStore__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ConfigStore__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ConfigStore__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ConfigStore__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ConfigStore_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ConfigStore, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ConfigStore__tp_init,             /* tp_init */
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
static struct PyModuleDef config_store_moduledef = {
    PyModuleDef_HEAD_INIT,
    "config_store",
    NULL,
    -1,
    config_store_functions,
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


MOD_INIT(config_store)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&config_store_moduledef);
    #else
    m = Py_InitModule3((char *) "config_store", config_store_functions, NULL);
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
    PyModule_AddObject(m, (char *) "_PyNs3FileConfig_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3FileConfig_wrapper_registry, NULL));
    /* Register the 'ns3::FileConfig' class */
    if (PyType_Ready(&PyNs3FileConfig_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FileConfig", (PyObject *) &PyNs3FileConfig_Type);
    /* Register the 'ns3::NoneFileConfig' class */
    PyNs3NoneFileConfig_Type.tp_base = &PyNs3FileConfig_Type;
    if (PyType_Ready(&PyNs3NoneFileConfig_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "NoneFileConfig", (PyObject *) &PyNs3NoneFileConfig_Type);
    /* Register the 'ns3::ConfigStore' class */
    PyNs3ConfigStore_Type.tp_base = &PyNs3ObjectBase_Type;
    if (PyType_Ready(&PyNs3ConfigStore_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ConfigStore", (PyObject *) &PyNs3ConfigStore_Type);
    {
        PyObject *tmp_value;
         // ns3::ConfigStore::LOAD
        tmp_value = PyLong_FromLong(ns3::ConfigStore::LOAD);
        PyDict_SetItemString((PyObject*) PyNs3ConfigStore_Type.tp_dict, "LOAD", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::ConfigStore::SAVE
        tmp_value = PyLong_FromLong(ns3::ConfigStore::SAVE);
        PyDict_SetItemString((PyObject*) PyNs3ConfigStore_Type.tp_dict, "SAVE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::ConfigStore::NONE
        tmp_value = PyLong_FromLong(ns3::ConfigStore::NONE);
        PyDict_SetItemString((PyObject*) PyNs3ConfigStore_Type.tp_dict, "NONE", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::ConfigStore::XML
        tmp_value = PyLong_FromLong(ns3::ConfigStore::XML);
        PyDict_SetItemString((PyObject*) PyNs3ConfigStore_Type.tp_dict, "XML", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::ConfigStore::RAW_TEXT
        tmp_value = PyLong_FromLong(ns3::ConfigStore::RAW_TEXT);
        PyDict_SetItemString((PyObject*) PyNs3ConfigStore_Type.tp_dict, "RAW_TEXT", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initconfig_store_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initconfig_store_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    return MOD_RETURN(m);
}
