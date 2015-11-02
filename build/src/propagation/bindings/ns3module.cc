#include "ns3module.h"
static PyMethodDef propagation_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef propagation_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "propagation.FatalImpl",
    NULL,
    -1,
    propagation_FatalImpl_functions,
};
#endif

static PyObject *
initpropagation_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&propagation_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "propagation.FatalImpl", propagation_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef propagation_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef propagation_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "propagation.Hash.Function",
    NULL,
    -1,
    propagation_Hash_Function_functions,
};
#endif

static PyObject *
initpropagation_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&propagation_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "propagation.Hash.Function", propagation_Hash_Function_functions, NULL);
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
static PyMethodDef propagation_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef propagation_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "propagation.Hash",
    NULL,
    -1,
    propagation_Hash_functions,
};
#endif

static PyObject *
initpropagation_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&propagation_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "propagation.Hash", propagation_Hash_functions, NULL);
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
    submodule = initpropagation_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef propagation_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef propagation_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "propagation.TracedValueCallback",
    NULL,
    -1,
    propagation_TracedValueCallback_functions,
};
#endif

static PyObject *
initpropagation_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&propagation_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "propagation.TracedValueCallback", propagation_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef propagation_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3AttributeConstructionList_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionList_wrapper_registry;


PyTypeObject *_PyNs3AttributeConstructionListItem_Type;
std::map<void*, PyObject*> *_PyNs3AttributeConstructionListItem_wrapper_registry;


PyTypeObject *_PyNs3CallbackBase_Type;
std::map<void*, PyObject*> *_PyNs3CallbackBase_wrapper_registry;


PyTypeObject *_PyNs3Hasher_Type;
std::map<void*, PyObject*> *_PyNs3Hasher_wrapper_registry;


PyTypeObject *_PyNs3ObjectBase_Type;
std::map<void*, PyObject*> *_PyNs3ObjectBase_wrapper_registry;


PyTypeObject *_PyNs3ObjectDeleter_Type;
std::map<void*, PyObject*> *_PyNs3ObjectDeleter_wrapper_registry;


PyTypeObject *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter_Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map;


PyTypeObject *_PyNs3TimeWithUnit_Type;
std::map<void*, PyObject*> *_PyNs3TimeWithUnit_wrapper_registry;


PyTypeObject *_PyNs3TypeId_Type;
std::map<void*, PyObject*> *_PyNs3TypeId_wrapper_registry;


PyTypeObject *_PyNs3TypeIdAttributeInformation_Type;
std::map<void*, PyObject*> *_PyNs3TypeIdAttributeInformation_wrapper_registry;


PyTypeObject *_PyNs3TypeIdTraceSourceInformation_Type;
std::map<void*, PyObject*> *_PyNs3TypeIdTraceSourceInformation_wrapper_registry;


PyTypeObject *_PyNs3Vector2D_Type;
std::map<void*, PyObject*> *_PyNs3Vector2D_wrapper_registry;


PyTypeObject *_PyNs3Vector3D_Type;
std::map<void*, PyObject*> *_PyNs3Vector3D_wrapper_registry;


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


PyTypeObject *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3TraceSourceAccessor_Ns3Empty_Ns3DefaultDeleter__lt__ns3TraceSourceAccessor__gt____typeid_map;


PyTypeObject *_PyNs3Time_Type;
std::map<void*, PyObject*> *_PyNs3Time_wrapper_registry;


PyTypeObject *_PyNs3TraceSourceAccessor_Type;


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


PyTypeObject *_PyNs3ExponentialRandomVariable_Type;


PyTypeObject *_PyNs3GammaRandomVariable_Type;


PyTypeObject *_PyNs3LogNormalRandomVariable_Type;


PyTypeObject *_PyNs3MobilityModel_Type;


PyTypeObject *_PyNs3NormalRandomVariable_Type;


PyTypeObject *_PyNs3ParetoRandomVariable_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3Vector2DChecker_Type;


PyTypeObject *_PyNs3Vector2DValue_Type;


PyTypeObject *_PyNs3Vector3DChecker_Type;


PyTypeObject *_PyNs3Vector3DValue_Type;


std::map<void*, PyObject*> PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry;


static int
_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_init__0(PyNs3PropagationCache__Ns3JakesProcess *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PropagationCache__Ns3JakesProcess *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PropagationCache__Ns3JakesProcess_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::PropagationCache< ns3::JakesProcess >(*((PyNs3PropagationCache__Ns3JakesProcess *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_init__1(PyNs3PropagationCache__Ns3JakesProcess *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::PropagationCache< ns3::JakesProcess >();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_init(PyNs3PropagationCache__Ns3JakesProcess *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PropagationCache__Ns3JakesProcess_GetPathData(PyNs3PropagationCache__Ns3JakesProcess *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::JakesProcess > retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    unsigned int modelUid;
    const char *keywords[] = {"a", "b", "modelUid", NULL};
    PyNs3JakesProcess *py_JakesProcess;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!I", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b, &modelUid)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->GetPathData(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr), modelUid);
    if (!(const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3JakesProcess__PythonHelper).name())
    {
        py_JakesProcess = reinterpret_cast< PyNs3JakesProcess* >(reinterpret_cast< PyNs3JakesProcess__PythonHelper* >(const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval)))->m_pyself);
        py_JakesProcess->obj = const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval));
        Py_INCREF(py_JakesProcess);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_JakesProcess = NULL;
        } else {
            py_JakesProcess = (PyNs3JakesProcess *) wrapper_lookup_iter->second;
            Py_INCREF(py_JakesProcess);
        }
    
        if (py_JakesProcess == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval)))), &PyNs3JakesProcess_Type);
            py_JakesProcess = PyObject_GC_New(PyNs3JakesProcess, wrapper_type);
            py_JakesProcess->inst_dict = NULL;
    
            py_JakesProcess->inst_dict = NULL;
            py_JakesProcess->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval))->Ref();
            py_JakesProcess->obj = const_cast<ns3::JakesProcess *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_JakesProcess->obj] = (PyObject *) py_JakesProcess;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_JakesProcess);
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationCache__Ns3JakesProcess_AddPathData(PyNs3PropagationCache__Ns3JakesProcess *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3JakesProcess *data;
    ns3::JakesProcess *data_ptr;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    unsigned int modelUid;
    const char *keywords[] = {"data", "a", "b", "modelUid", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!I", (char **) keywords, &PyNs3JakesProcess_Type, &data, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b, &modelUid)) {
        return NULL;
    }
    data_ptr = (data ? data->obj : NULL);
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    self->obj->AddPathData(ns3::Ptr< ns3::JakesProcess  > (data_ptr), ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr), modelUid);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3PropagationCache__Ns3JakesProcess__copy__(PyNs3PropagationCache__Ns3JakesProcess *self)
{

    PyNs3PropagationCache__Ns3JakesProcess *py_copy;
    py_copy = PyObject_New(PyNs3PropagationCache__Ns3JakesProcess, &PyNs3PropagationCache__Ns3JakesProcess_Type);
    py_copy->obj = new ns3::PropagationCache< ns3::JakesProcess >(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3PropagationCache__Ns3JakesProcess_methods[] = {
    {(char *) "GetPathData", (PyCFunction) _wrap_PyNs3PropagationCache__Ns3JakesProcess_GetPathData, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddPathData", (PyCFunction) _wrap_PyNs3PropagationCache__Ns3JakesProcess_AddPathData, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3PropagationCache__Ns3JakesProcess__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_dealloc(PyNs3PropagationCache__Ns3JakesProcess *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry.end()) {
        PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::PropagationCache< ns3::JakesProcess > *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_richcompare (PyNs3PropagationCache__Ns3JakesProcess *PYBINDGEN_UNUSED(self), PyNs3PropagationCache__Ns3JakesProcess *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PropagationCache__Ns3JakesProcess_Type)) {
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

PyTypeObject PyNs3PropagationCache__Ns3JakesProcess_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.PropagationCache__Ns3JakesProcess",            /* tp_name */
    sizeof(PyNs3PropagationCache__Ns3JakesProcess),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PropagationCache__Ns3JakesProcess_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PropagationCache__Ns3JakesProcess__tp_init,             /* tp_init */
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
PyNs3PropagationDelayModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3PropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3PropagationDelayModel__PythonHelper::_wrap_DoInitialize(PyNs3PropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3PropagationDelayModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3PropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3PropagationDelayModel__PythonHelper::_wrap_DoDispose(PyNs3PropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationDelayModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Time
PyNs3PropagationDelayModel__PythonHelper::GetDelay(ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PropagationDelayModel *self_obj_before;
    PyObject *py_retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    PyNs3Time *tmp_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetDelay"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Time();
    }
    self_obj_before = reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = const_cast< ns3::PropagationDelayModel* >((const ns3::PropagationDelayModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetDelay", (char *) "NN", py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Time();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Time();
    }
    ns3::Time retval = *tmp_Time->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3PropagationDelayModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PropagationDelayModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = (ns3::PropagationDelayModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PropagationDelayModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3PropagationDelayModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3PropagationDelayModel__PythonHelper::DoDispose()
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
PyNs3PropagationDelayModel__PythonHelper::DoInitialize()
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
PyNs3PropagationDelayModel__PythonHelper::NotifyNewAggregate()
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
PyNs3PropagationDelayModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3PropagationDelayModel__tp_init__0(PyNs3PropagationDelayModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3PropagationDelayModel_Type)
    {
        self->obj = new PyNs3PropagationDelayModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PropagationDelayModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'PropagationDelayModel' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3PropagationDelayModel__tp_init__1(PyNs3PropagationDelayModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PropagationDelayModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PropagationDelayModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3PropagationDelayModel_Type)
    {
        self->obj = new PyNs3PropagationDelayModel__PythonHelper(*((PyNs3PropagationDelayModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PropagationDelayModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'PropagationDelayModel' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3PropagationDelayModel__tp_init(PyNs3PropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PropagationDelayModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PropagationDelayModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PropagationDelayModel_GetDelay(PyNs3PropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"a", "b", NULL};
    PyNs3Time *py_Time;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    ns3::Time retval = self->obj->GetDelay(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationDelayModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::PropagationDelayModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationDelayModel_AssignStreams(PyNs3PropagationDelayModel *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef PyNs3PropagationDelayModel_methods[] = {
    {(char *) "GetDelay", (PyCFunction) _wrap_PyNs3PropagationDelayModel_GetDelay, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3PropagationDelayModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3PropagationDelayModel_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3PropagationDelayModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3PropagationDelayModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3PropagationDelayModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3PropagationDelayModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3PropagationDelayModel__tp_clear(PyNs3PropagationDelayModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::PropagationDelayModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3PropagationDelayModel__tp_traverse(PyNs3PropagationDelayModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3PropagationDelayModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3PropagationDelayModel__tp_dealloc(PyNs3PropagationDelayModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3PropagationDelayModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PropagationDelayModel__tp_richcompare (PyNs3PropagationDelayModel *PYBINDGEN_UNUSED(self), PyNs3PropagationDelayModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PropagationDelayModel_Type)) {
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

PyTypeObject PyNs3PropagationDelayModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.PropagationDelayModel",            /* tp_name */
    sizeof(PyNs3PropagationDelayModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PropagationDelayModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3PropagationDelayModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3PropagationDelayModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3PropagationDelayModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PropagationDelayModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3PropagationDelayModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PropagationDelayModel__tp_init,             /* tp_init */
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
PyNs3PropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3PropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3PropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3PropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3PropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3PropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = const_cast< ns3::PropagationLossModel* >((const ns3::PropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3PropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = (ns3::PropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3PropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3PropagationLossModel__PythonHelper::DoDispose()
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
PyNs3PropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3PropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3PropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3PropagationLossModel__tp_init(PyNs3PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3PropagationLossModel_Type)
    {
        self->obj = new PyNs3PropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'PropagationLossModel' cannot be constructed");
        return -1;
    }
    return 0;
}


PyObject *
_wrap_PyNs3PropagationLossModel_GetNext(PyNs3PropagationLossModel *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::PropagationLossModel > retval;
    PyNs3PropagationLossModel *py_PropagationLossModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetNext();
    if (!(const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3PropagationLossModel__PythonHelper).name())
    {
        py_PropagationLossModel = reinterpret_cast< PyNs3PropagationLossModel* >(reinterpret_cast< PyNs3PropagationLossModel__PythonHelper* >(const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval)))->m_pyself);
        py_PropagationLossModel->obj = const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval));
        Py_INCREF(py_PropagationLossModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_PropagationLossModel = NULL;
        } else {
            py_PropagationLossModel = (PyNs3PropagationLossModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_PropagationLossModel);
        }
    
        if (py_PropagationLossModel == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval)))), &PyNs3PropagationLossModel_Type);
            py_PropagationLossModel = PyObject_GC_New(PyNs3PropagationLossModel, wrapper_type);
            py_PropagationLossModel->inst_dict = NULL;
    
            py_PropagationLossModel->inst_dict = NULL;
            py_PropagationLossModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval))->Ref();
            py_PropagationLossModel->obj = const_cast<ns3::PropagationLossModel *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_PropagationLossModel->obj] = (PyObject *) py_PropagationLossModel;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_PropagationLossModel);
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::PropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationLossModel_CalcRxPower(PyNs3PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    double txPowerDbm;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"txPowerDbm", "a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dO!O!", (char **) keywords, &txPowerDbm, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->CalcRxPower(txPowerDbm, ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationLossModel_SetNext(PyNs3PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3PropagationLossModel *next;
    ns3::PropagationLossModel *next_ptr;
    const char *keywords[] = {"next", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PropagationLossModel_Type, &next)) {
        return NULL;
    }
    next_ptr = (next ? next->obj : NULL);
    self->obj->SetNext(ns3::Ptr< ns3::PropagationLossModel  > (next_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3PropagationLossModel_AssignStreams(PyNs3PropagationLossModel *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef PyNs3PropagationLossModel_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3PropagationLossModel_GetNext, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3PropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "CalcRxPower", (PyCFunction) _wrap_PyNs3PropagationLossModel_CalcRxPower, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetNext", (PyCFunction) _wrap_PyNs3PropagationLossModel_SetNext, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3PropagationLossModel_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3PropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3PropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3PropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3PropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3PropagationLossModel__tp_clear(PyNs3PropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::PropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3PropagationLossModel__tp_traverse(PyNs3PropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3PropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3PropagationLossModel__tp_dealloc(PyNs3PropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3PropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PropagationLossModel__tp_richcompare (PyNs3PropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3PropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PropagationLossModel_Type)) {
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

PyTypeObject PyNs3PropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.PropagationLossModel",            /* tp_name */
    sizeof(PyNs3PropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3PropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3PropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3PropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3PropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PropagationLossModel__tp_init,             /* tp_init */
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
PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_DoInitialize(PyNs3RandomPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_DoDispose(PyNs3RandomPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationDelayModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Time
PyNs3RandomPropagationDelayModel__PythonHelper::GetDelay(ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomPropagationDelayModel *self_obj_before;
    PyObject *py_retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    PyNs3Time *tmp_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetDelay"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomPropagationDelayModel::GetDelay(a, b);
    }
    self_obj_before = reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = const_cast< ns3::RandomPropagationDelayModel* >((const ns3::RandomPropagationDelayModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetDelay", (char *) "NN", py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomPropagationDelayModel::GetDelay(a, b);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomPropagationDelayModel::GetDelay(a, b);
    }
    ns3::Time retval = *tmp_Time->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3RandomPropagationDelayModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomPropagationDelayModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = (ns3::RandomPropagationDelayModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3RandomPropagationDelayModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomPropagationDelayModel__PythonHelper::DoDispose()
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
PyNs3RandomPropagationDelayModel__PythonHelper::DoInitialize()
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
PyNs3RandomPropagationDelayModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomPropagationDelayModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomPropagationDelayModel__tp_init__0(PyNs3RandomPropagationDelayModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomPropagationDelayModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomPropagationDelayModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomPropagationDelayModel_Type)
    {
        self->obj = new PyNs3RandomPropagationDelayModel__PythonHelper(*((PyNs3RandomPropagationDelayModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomPropagationDelayModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomPropagationDelayModel(*((PyNs3RandomPropagationDelayModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomPropagationDelayModel__tp_init__1(PyNs3RandomPropagationDelayModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomPropagationDelayModel_Type)
    {
        self->obj = new PyNs3RandomPropagationDelayModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomPropagationDelayModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomPropagationDelayModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomPropagationDelayModel__tp_init(PyNs3RandomPropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomPropagationDelayModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomPropagationDelayModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomPropagationDelayModel_GetDelay(PyNs3RandomPropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    PyNs3RandomPropagationDelayModel__PythonHelper *helper_class = dynamic_cast<PyNs3RandomPropagationDelayModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"a", "b", NULL};
    PyNs3Time *py_Time;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    ns3::Time retval = (helper_class == NULL)? (self->obj->GetDelay(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr))) : (self->obj->ns3::RandomPropagationDelayModel::GetDelay(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr)));
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomPropagationDelayModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomPropagationDelayModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomPropagationDelayModel__copy__(PyNs3RandomPropagationDelayModel *self)
{

    PyNs3RandomPropagationDelayModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomPropagationDelayModel, &PyNs3RandomPropagationDelayModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomPropagationDelayModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomPropagationDelayModel_methods[] = {
    {(char *) "GetDelay", (PyCFunction) _wrap_PyNs3RandomPropagationDelayModel_GetDelay, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomPropagationDelayModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RandomPropagationDelayModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomPropagationDelayModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomPropagationDelayModel__tp_clear(PyNs3RandomPropagationDelayModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomPropagationDelayModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomPropagationDelayModel__tp_traverse(PyNs3RandomPropagationDelayModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomPropagationDelayModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomPropagationDelayModel__tp_dealloc(PyNs3RandomPropagationDelayModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomPropagationDelayModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomPropagationDelayModel__tp_richcompare (PyNs3RandomPropagationDelayModel *PYBINDGEN_UNUSED(self), PyNs3RandomPropagationDelayModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomPropagationDelayModel_Type)) {
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

PyTypeObject PyNs3RandomPropagationDelayModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.RandomPropagationDelayModel",            /* tp_name */
    sizeof(PyNs3RandomPropagationDelayModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomPropagationDelayModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomPropagationDelayModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomPropagationDelayModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomPropagationDelayModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomPropagationDelayModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomPropagationDelayModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomPropagationDelayModel__tp_init,             /* tp_init */
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
PyNs3RandomPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3RandomPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3RandomPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RandomPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RandomPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3RandomPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::RandomPropagationLossModel* >((const ns3::RandomPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3RandomPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = (ns3::RandomPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3RandomPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3RandomPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3RandomPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomPropagationLossModel__tp_init(PyNs3RandomPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomPropagationLossModel_Type)
    {
        self->obj = new PyNs3RandomPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3RandomPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3RandomPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RandomPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RandomPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomPropagationLossModel__tp_clear(PyNs3RandomPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomPropagationLossModel__tp_traverse(PyNs3RandomPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomPropagationLossModel__tp_dealloc(PyNs3RandomPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomPropagationLossModel__tp_richcompare (PyNs3RandomPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3RandomPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomPropagationLossModel_Type)) {
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

PyTypeObject PyNs3RandomPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.RandomPropagationLossModel",            /* tp_name */
    sizeof(PyNs3RandomPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3RangePropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RangePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RangePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RangePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3RangePropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3RangePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RangePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RangePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3RangePropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RangePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RangePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RangePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3RangePropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3RangePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3RangePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3RangePropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3RangePropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RangePropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = const_cast< ns3::RangePropagationLossModel* >((const ns3::RangePropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3RangePropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RangePropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = (ns3::RangePropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RangePropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3RangePropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RangePropagationLossModel__PythonHelper::DoDispose()
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
PyNs3RangePropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3RangePropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RangePropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RangePropagationLossModel__tp_init(PyNs3RangePropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RangePropagationLossModel_Type)
    {
        self->obj = new PyNs3RangePropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RangePropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RangePropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3RangePropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RangePropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3RangePropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RangePropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RangePropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RangePropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RangePropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RangePropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RangePropagationLossModel__tp_clear(PyNs3RangePropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RangePropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RangePropagationLossModel__tp_traverse(PyNs3RangePropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RangePropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RangePropagationLossModel__tp_dealloc(PyNs3RangePropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RangePropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RangePropagationLossModel__tp_richcompare (PyNs3RangePropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3RangePropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RangePropagationLossModel_Type)) {
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

PyTypeObject PyNs3RangePropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.RangePropagationLossModel",            /* tp_name */
    sizeof(PyNs3RangePropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RangePropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RangePropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RangePropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RangePropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RangePropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RangePropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RangePropagationLossModel__tp_init,             /* tp_init */
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ThreeLogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ThreeLogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ThreeLogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3ThreeLogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ThreeLogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ThreeLogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ThreeLogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ThreeLogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ThreeLogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3ThreeLogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ThreeLogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ThreeLogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ThreeLogDistancePropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = const_cast< ns3::ThreeLogDistancePropagationLossModel* >((const ns3::ThreeLogDistancePropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ThreeLogDistancePropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = (ns3::ThreeLogDistancePropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ThreeLogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::DoDispose()
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ThreeLogDistancePropagationLossModel__tp_init(PyNs3ThreeLogDistancePropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ThreeLogDistancePropagationLossModel_Type)
    {
        self->obj = new PyNs3ThreeLogDistancePropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ThreeLogDistancePropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ThreeLogDistancePropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3ThreeLogDistancePropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ThreeLogDistancePropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3ThreeLogDistancePropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ThreeLogDistancePropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ThreeLogDistancePropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ThreeLogDistancePropagationLossModel__tp_clear(PyNs3ThreeLogDistancePropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ThreeLogDistancePropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ThreeLogDistancePropagationLossModel__tp_traverse(PyNs3ThreeLogDistancePropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ThreeLogDistancePropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ThreeLogDistancePropagationLossModel__tp_dealloc(PyNs3ThreeLogDistancePropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ThreeLogDistancePropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ThreeLogDistancePropagationLossModel__tp_richcompare (PyNs3ThreeLogDistancePropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3ThreeLogDistancePropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ThreeLogDistancePropagationLossModel_Type)) {
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

PyTypeObject PyNs3ThreeLogDistancePropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.ThreeLogDistancePropagationLossModel",            /* tp_name */
    sizeof(PyNs3ThreeLogDistancePropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ThreeLogDistancePropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ThreeLogDistancePropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ThreeLogDistancePropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ThreeLogDistancePropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ThreeLogDistancePropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ThreeLogDistancePropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ThreeLogDistancePropagationLossModel__tp_init,             /* tp_init */
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3TwoRayGroundPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3TwoRayGroundPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3TwoRayGroundPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3TwoRayGroundPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3TwoRayGroundPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3TwoRayGroundPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3TwoRayGroundPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3TwoRayGroundPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TwoRayGroundPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::TwoRayGroundPropagationLossModel* >((const ns3::TwoRayGroundPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::TwoRayGroundPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = (ns3::TwoRayGroundPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3TwoRayGroundPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3TwoRayGroundPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3TwoRayGroundPropagationLossModel__tp_init(PyNs3TwoRayGroundPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3TwoRayGroundPropagationLossModel_Type)
    {
        self->obj = new PyNs3TwoRayGroundPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3TwoRayGroundPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::TwoRayGroundPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_GetFrequency(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetFrequency();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_GetSystemLoss(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetSystemLoss();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::TwoRayGroundPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_SetMinDistance(PyNs3TwoRayGroundPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double minDistance;
    const char *keywords[] = {"minDistance", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &minDistance)) {
        return NULL;
    }
    self->obj->SetMinDistance(minDistance);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_SetHeightAboveZ(PyNs3TwoRayGroundPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double heightAboveZ;
    const char *keywords[] = {"heightAboveZ", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &heightAboveZ)) {
        return NULL;
    }
    self->obj->SetHeightAboveZ(heightAboveZ);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_SetFrequency(PyNs3TwoRayGroundPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double frequency;
    const char *keywords[] = {"frequency", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &frequency)) {
        return NULL;
    }
    self->obj->SetFrequency(frequency);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_GetMinDistance(PyNs3TwoRayGroundPropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetMinDistance();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3TwoRayGroundPropagationLossModel_SetSystemLoss(PyNs3TwoRayGroundPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double systemLoss;
    const char *keywords[] = {"systemLoss", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &systemLoss)) {
        return NULL;
    }
    self->obj->SetSystemLoss(systemLoss);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3TwoRayGroundPropagationLossModel_methods[] = {
    {(char *) "GetFrequency", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_GetFrequency, METH_NOARGS, NULL },
    {(char *) "GetSystemLoss", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_GetSystemLoss, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetMinDistance", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_SetMinDistance, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHeightAboveZ", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_SetHeightAboveZ, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFrequency", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_SetFrequency, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMinDistance", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_GetMinDistance, METH_NOARGS, NULL },
    {(char *) "SetSystemLoss", (PyCFunction) _wrap_PyNs3TwoRayGroundPropagationLossModel_SetSystemLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3TwoRayGroundPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3TwoRayGroundPropagationLossModel__tp_clear(PyNs3TwoRayGroundPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::TwoRayGroundPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3TwoRayGroundPropagationLossModel__tp_traverse(PyNs3TwoRayGroundPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3TwoRayGroundPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3TwoRayGroundPropagationLossModel__tp_dealloc(PyNs3TwoRayGroundPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3TwoRayGroundPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3TwoRayGroundPropagationLossModel__tp_richcompare (PyNs3TwoRayGroundPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3TwoRayGroundPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3TwoRayGroundPropagationLossModel_Type)) {
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

PyTypeObject PyNs3TwoRayGroundPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.TwoRayGroundPropagationLossModel",            /* tp_name */
    sizeof(PyNs3TwoRayGroundPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3TwoRayGroundPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3TwoRayGroundPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3TwoRayGroundPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3TwoRayGroundPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3TwoRayGroundPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3TwoRayGroundPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3TwoRayGroundPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantSpeedPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantSpeedPropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_DoInitialize(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantSpeedPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantSpeedPropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantSpeedPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantSpeedPropagationDelayModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_DoDispose(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantSpeedPropagationDelayModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantSpeedPropagationDelayModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Time
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::GetDelay(ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantSpeedPropagationDelayModel *self_obj_before;
    PyObject *py_retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    PyNs3Time *tmp_Time;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetDelay"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ConstantSpeedPropagationDelayModel::GetDelay(a, b);
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = const_cast< ns3::ConstantSpeedPropagationDelayModel* >((const ns3::ConstantSpeedPropagationDelayModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetDelay", (char *) "NN", py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ConstantSpeedPropagationDelayModel::GetDelay(a, b);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ConstantSpeedPropagationDelayModel::GetDelay(a, b);
    }
    ns3::Time retval = *tmp_Time->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantSpeedPropagationDelayModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = (ns3::ConstantSpeedPropagationDelayModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantSpeedPropagationDelayModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::DoDispose()
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::DoInitialize()
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_init__0(PyNs3ConstantSpeedPropagationDelayModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ConstantSpeedPropagationDelayModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ConstantSpeedPropagationDelayModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ConstantSpeedPropagationDelayModel_Type)
    {
        self->obj = new PyNs3ConstantSpeedPropagationDelayModel__PythonHelper(*((PyNs3ConstantSpeedPropagationDelayModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantSpeedPropagationDelayModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantSpeedPropagationDelayModel(*((PyNs3ConstantSpeedPropagationDelayModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_init__1(PyNs3ConstantSpeedPropagationDelayModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ConstantSpeedPropagationDelayModel_Type)
    {
        self->obj = new PyNs3ConstantSpeedPropagationDelayModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantSpeedPropagationDelayModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantSpeedPropagationDelayModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_init(PyNs3ConstantSpeedPropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ConstantSpeedPropagationDelayModel_GetDelay(PyNs3ConstantSpeedPropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    PyNs3ConstantSpeedPropagationDelayModel__PythonHelper *helper_class = dynamic_cast<PyNs3ConstantSpeedPropagationDelayModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"a", "b", NULL};
    PyNs3Time *py_Time;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    ns3::Time retval = (helper_class == NULL)? (self->obj->GetDelay(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr))) : (self->obj->ns3::ConstantSpeedPropagationDelayModel::GetDelay(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr)));
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantSpeedPropagationDelayModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ConstantSpeedPropagationDelayModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantSpeedPropagationDelayModel_GetSpeed(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetSpeed();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantSpeedPropagationDelayModel_SetSpeed(PyNs3ConstantSpeedPropagationDelayModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double speed;
    const char *keywords[] = {"speed", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &speed)) {
        return NULL;
    }
    self->obj->SetSpeed(speed);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3ConstantSpeedPropagationDelayModel__copy__(PyNs3ConstantSpeedPropagationDelayModel *self)
{

    PyNs3ConstantSpeedPropagationDelayModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3ConstantSpeedPropagationDelayModel, &PyNs3ConstantSpeedPropagationDelayModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ConstantSpeedPropagationDelayModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ConstantSpeedPropagationDelayModel_methods[] = {
    {(char *) "GetDelay", (PyCFunction) _wrap_PyNs3ConstantSpeedPropagationDelayModel_GetDelay, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ConstantSpeedPropagationDelayModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetSpeed", (PyCFunction) _wrap_PyNs3ConstantSpeedPropagationDelayModel_GetSpeed, METH_NOARGS, NULL },
    {(char *) "SetSpeed", (PyCFunction) _wrap_PyNs3ConstantSpeedPropagationDelayModel_SetSpeed, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ConstantSpeedPropagationDelayModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ConstantSpeedPropagationDelayModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ConstantSpeedPropagationDelayModel__tp_clear(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ConstantSpeedPropagationDelayModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ConstantSpeedPropagationDelayModel__tp_traverse(PyNs3ConstantSpeedPropagationDelayModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ConstantSpeedPropagationDelayModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_dealloc(PyNs3ConstantSpeedPropagationDelayModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ConstantSpeedPropagationDelayModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_richcompare (PyNs3ConstantSpeedPropagationDelayModel *PYBINDGEN_UNUSED(self), PyNs3ConstantSpeedPropagationDelayModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ConstantSpeedPropagationDelayModel_Type)) {
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

PyTypeObject PyNs3ConstantSpeedPropagationDelayModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.ConstantSpeedPropagationDelayModel",            /* tp_name */
    sizeof(PyNs3ConstantSpeedPropagationDelayModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ConstantSpeedPropagationDelayModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ConstantSpeedPropagationDelayModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ConstantSpeedPropagationDelayModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ConstantSpeedPropagationDelayModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ConstantSpeedPropagationDelayModel__tp_init,             /* tp_init */
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
PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Cost231PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Cost231PropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Cost231PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Cost231PropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Cost231PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Cost231PropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Cost231PropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Cost231PropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3Cost231PropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Cost231PropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = const_cast< ns3::Cost231PropagationLossModel* >((const ns3::Cost231PropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3Cost231PropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Cost231PropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = (ns3::Cost231PropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Cost231PropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3Cost231PropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3Cost231PropagationLossModel__PythonHelper::DoDispose()
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
PyNs3Cost231PropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3Cost231PropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3Cost231PropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Cost231PropagationLossModel__tp_init(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Cost231PropagationLossModel_Type)
    {
        self->obj = new PyNs3Cost231PropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Cost231PropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Cost231PropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_SetShadowing(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double shadowing;
    const char *keywords[] = {"shadowing", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &shadowing)) {
        return NULL;
    }
    self->obj->SetShadowing(shadowing);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetShadowing(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetShadowing();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Cost231PropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetBSAntennaHeight(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetBSAntennaHeight();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetLoss(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->GetLoss(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}



PyObject *
_wrap_PyNs3Cost231PropagationLossModel_SetLambda__0(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    double lambda;
    const char *keywords[] = {"lambda", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &lambda)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetLambda(lambda);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3Cost231PropagationLossModel_SetLambda__1(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    double frequency;
    double speed;
    const char *keywords[] = {"frequency", "speed", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dd", (char **) keywords, &frequency, &speed)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetLambda(frequency, speed);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3Cost231PropagationLossModel_SetLambda(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Cost231PropagationLossModel_SetLambda__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Cost231PropagationLossModel_SetLambda__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Cost231PropagationLossModel_SetBSAntennaHeight(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double height;
    const char *keywords[] = {"height", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &height)) {
        return NULL;
    }
    self->obj->SetBSAntennaHeight(height);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_SetMinDistance(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double minDistance;
    const char *keywords[] = {"minDistance", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &minDistance)) {
        return NULL;
    }
    self->obj->SetMinDistance(minDistance);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetSSAntennaHeight(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetSSAntennaHeight();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetMinDistance(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetMinDistance();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_SetSSAntennaHeight(PyNs3Cost231PropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double height;
    const char *keywords[] = {"height", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &height)) {
        return NULL;
    }
    self->obj->SetSSAntennaHeight(height);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3Cost231PropagationLossModel_GetLambda(PyNs3Cost231PropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetLambda();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}

static PyMethodDef PyNs3Cost231PropagationLossModel_methods[] = {
    {(char *) "SetShadowing", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_SetShadowing, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetShadowing", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetShadowing, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetBSAntennaHeight", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetBSAntennaHeight, METH_NOARGS, NULL },
    {(char *) "GetLoss", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLambda", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_SetLambda, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetBSAntennaHeight", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_SetBSAntennaHeight, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMinDistance", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_SetMinDistance, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSSAntennaHeight", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetSSAntennaHeight, METH_NOARGS, NULL },
    {(char *) "GetMinDistance", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetMinDistance, METH_NOARGS, NULL },
    {(char *) "SetSSAntennaHeight", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_SetSSAntennaHeight, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLambda", (PyCFunction) _wrap_PyNs3Cost231PropagationLossModel_GetLambda, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Cost231PropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Cost231PropagationLossModel__tp_clear(PyNs3Cost231PropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Cost231PropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Cost231PropagationLossModel__tp_traverse(PyNs3Cost231PropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Cost231PropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Cost231PropagationLossModel__tp_dealloc(PyNs3Cost231PropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Cost231PropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Cost231PropagationLossModel__tp_richcompare (PyNs3Cost231PropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3Cost231PropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Cost231PropagationLossModel_Type)) {
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

PyTypeObject PyNs3Cost231PropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.Cost231PropagationLossModel",            /* tp_name */
    sizeof(PyNs3Cost231PropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Cost231PropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Cost231PropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Cost231PropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Cost231PropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Cost231PropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Cost231PropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Cost231PropagationLossModel__tp_init,             /* tp_init */
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
PyNs3FixedRssLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3FixedRssLossModel *self)
{
    PyObject *py_retval;
    PyNs3FixedRssLossModel__PythonHelper *helper = dynamic_cast< PyNs3FixedRssLossModel__PythonHelper* >(self->obj);
    
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
PyNs3FixedRssLossModel__PythonHelper::_wrap_DoInitialize(PyNs3FixedRssLossModel *self)
{
    PyObject *py_retval;
    PyNs3FixedRssLossModel__PythonHelper *helper = dynamic_cast< PyNs3FixedRssLossModel__PythonHelper* >(self->obj);
    
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
PyNs3FixedRssLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3FixedRssLossModel *self)
{
    PyObject *py_retval;
    PyNs3FixedRssLossModel__PythonHelper *helper = dynamic_cast< PyNs3FixedRssLossModel__PythonHelper* >(self->obj);
    
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
PyNs3FixedRssLossModel__PythonHelper::_wrap_DoDispose(PyNs3FixedRssLossModel *self)
{
    PyObject *py_retval;
    PyNs3FixedRssLossModel__PythonHelper *helper = dynamic_cast< PyNs3FixedRssLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3FixedRssLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FixedRssLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = const_cast< ns3::FixedRssLossModel* >((const ns3::FixedRssLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3FixedRssLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FixedRssLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = (ns3::FixedRssLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FixedRssLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3FixedRssLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3FixedRssLossModel__PythonHelper::DoDispose()
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
PyNs3FixedRssLossModel__PythonHelper::DoInitialize()
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
PyNs3FixedRssLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3FixedRssLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3FixedRssLossModel__tp_init(PyNs3FixedRssLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3FixedRssLossModel_Type)
    {
        self->obj = new PyNs3FixedRssLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FixedRssLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::FixedRssLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3FixedRssLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::FixedRssLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FixedRssLossModel_SetRss(PyNs3FixedRssLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double rss;
    const char *keywords[] = {"rss", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &rss)) {
        return NULL;
    }
    self->obj->SetRss(rss);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3FixedRssLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3FixedRssLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRss", (PyCFunction) _wrap_PyNs3FixedRssLossModel_SetRss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3FixedRssLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3FixedRssLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3FixedRssLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3FixedRssLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FixedRssLossModel__tp_clear(PyNs3FixedRssLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::FixedRssLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3FixedRssLossModel__tp_traverse(PyNs3FixedRssLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3FixedRssLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3FixedRssLossModel__tp_dealloc(PyNs3FixedRssLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FixedRssLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FixedRssLossModel__tp_richcompare (PyNs3FixedRssLossModel *PYBINDGEN_UNUSED(self), PyNs3FixedRssLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FixedRssLossModel_Type)) {
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

PyTypeObject PyNs3FixedRssLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.FixedRssLossModel",            /* tp_name */
    sizeof(PyNs3FixedRssLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FixedRssLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3FixedRssLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FixedRssLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FixedRssLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FixedRssLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FixedRssLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FixedRssLossModel__tp_init,             /* tp_init */
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
PyNs3FriisPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3FriisPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3FriisPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3FriisPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3FriisPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3FriisPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3FriisPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3FriisPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3FriisPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3FriisPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3FriisPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3FriisPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3FriisPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FriisPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::FriisPropagationLossModel* >((const ns3::FriisPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3FriisPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::FriisPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = (ns3::FriisPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3FriisPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3FriisPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3FriisPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3FriisPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3FriisPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3FriisPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3FriisPropagationLossModel__tp_init(PyNs3FriisPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3FriisPropagationLossModel_Type)
    {
        self->obj = new PyNs3FriisPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3FriisPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::FriisPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_GetFrequency(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetFrequency();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_SetMinLoss(PyNs3FriisPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double minLoss;
    const char *keywords[] = {"minLoss", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &minLoss)) {
        return NULL;
    }
    self->obj->SetMinLoss(minLoss);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::FriisPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_GetSystemLoss(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetSystemLoss();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_SetFrequency(PyNs3FriisPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double frequency;
    const char *keywords[] = {"frequency", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &frequency)) {
        return NULL;
    }
    self->obj->SetFrequency(frequency);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_SetSystemLoss(PyNs3FriisPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double systemLoss;
    const char *keywords[] = {"systemLoss", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &systemLoss)) {
        return NULL;
    }
    self->obj->SetSystemLoss(systemLoss);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3FriisPropagationLossModel_GetMinLoss(PyNs3FriisPropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetMinLoss();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}

static PyMethodDef PyNs3FriisPropagationLossModel_methods[] = {
    {(char *) "GetFrequency", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_GetFrequency, METH_NOARGS, NULL },
    {(char *) "SetMinLoss", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_SetMinLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetSystemLoss", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_GetSystemLoss, METH_NOARGS, NULL },
    {(char *) "SetFrequency", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_SetFrequency, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSystemLoss", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_SetSystemLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMinLoss", (PyCFunction) _wrap_PyNs3FriisPropagationLossModel_GetMinLoss, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3FriisPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3FriisPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3FriisPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3FriisPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3FriisPropagationLossModel__tp_clear(PyNs3FriisPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::FriisPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3FriisPropagationLossModel__tp_traverse(PyNs3FriisPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3FriisPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3FriisPropagationLossModel__tp_dealloc(PyNs3FriisPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3FriisPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3FriisPropagationLossModel__tp_richcompare (PyNs3FriisPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3FriisPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3FriisPropagationLossModel_Type)) {
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

PyTypeObject PyNs3FriisPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.FriisPropagationLossModel",            /* tp_name */
    sizeof(PyNs3FriisPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3FriisPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3FriisPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3FriisPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3FriisPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3FriisPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3FriisPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3FriisPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ItuR1411LosPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411LosPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411LosPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3ItuR1411LosPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411LosPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411LosPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ItuR1411LosPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411LosPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411LosPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3ItuR1411LosPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411LosPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411LosPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ItuR1411LosPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::ItuR1411LosPropagationLossModel* >((const ns3::ItuR1411LosPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ItuR1411LosPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = (ns3::ItuR1411LosPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ItuR1411LosPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ItuR1411LosPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ItuR1411LosPropagationLossModel__tp_init(PyNs3ItuR1411LosPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ItuR1411LosPropagationLossModel_Type)
    {
        self->obj = new PyNs3ItuR1411LosPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ItuR1411LosPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ItuR1411LosPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3ItuR1411LosPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ItuR1411LosPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ItuR1411LosPropagationLossModel_GetLoss(PyNs3ItuR1411LosPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->GetLoss(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3ItuR1411LosPropagationLossModel_SetFrequency(PyNs3ItuR1411LosPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double freq;
    const char *keywords[] = {"freq", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &freq)) {
        return NULL;
    }
    self->obj->SetFrequency(freq);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3ItuR1411LosPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ItuR1411LosPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetLoss", (PyCFunction) _wrap_PyNs3ItuR1411LosPropagationLossModel_GetLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFrequency", (PyCFunction) _wrap_PyNs3ItuR1411LosPropagationLossModel_SetFrequency, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ItuR1411LosPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ItuR1411LosPropagationLossModel__tp_clear(PyNs3ItuR1411LosPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ItuR1411LosPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ItuR1411LosPropagationLossModel__tp_traverse(PyNs3ItuR1411LosPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ItuR1411LosPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ItuR1411LosPropagationLossModel__tp_dealloc(PyNs3ItuR1411LosPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ItuR1411LosPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ItuR1411LosPropagationLossModel__tp_richcompare (PyNs3ItuR1411LosPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3ItuR1411LosPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ItuR1411LosPropagationLossModel_Type)) {
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

PyTypeObject PyNs3ItuR1411LosPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.ItuR1411LosPropagationLossModel",            /* tp_name */
    sizeof(PyNs3ItuR1411LosPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ItuR1411LosPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ItuR1411LosPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ItuR1411LosPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ItuR1411LosPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ItuR1411LosPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ItuR1411LosPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ItuR1411LosPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ItuR1411NlosOverRooftopPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::ItuR1411NlosOverRooftopPropagationLossModel* >((const ns3::ItuR1411NlosOverRooftopPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ItuR1411NlosOverRooftopPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = (ns3::ItuR1411NlosOverRooftopPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ItuR1411NlosOverRooftopPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_init(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type)
    {
        self->obj = new PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ItuR1411NlosOverRooftopPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ItuR1411NlosOverRooftopPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel_GetLoss(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->GetLoss(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel_SetFrequency(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double freq;
    const char *keywords[] = {"freq", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &freq)) {
        return NULL;
    }
    self->obj->SetFrequency(freq);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3ItuR1411NlosOverRooftopPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetLoss", (PyCFunction) _wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel_GetLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetFrequency", (PyCFunction) _wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel_SetFrequency, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_clear(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ItuR1411NlosOverRooftopPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_traverse(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ItuR1411NlosOverRooftopPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_dealloc(PyNs3ItuR1411NlosOverRooftopPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_richcompare (PyNs3ItuR1411NlosOverRooftopPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3ItuR1411NlosOverRooftopPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type)) {
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

PyTypeObject PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.ItuR1411NlosOverRooftopPropagationLossModel",            /* tp_name */
    sizeof(PyNs3ItuR1411NlosOverRooftopPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ItuR1411NlosOverRooftopPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ItuR1411NlosOverRooftopPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ItuR1411NlosOverRooftopPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3JakesProcess__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3JakesProcess *self)
{
    PyObject *py_retval;
    PyNs3JakesProcess__PythonHelper *helper = dynamic_cast< PyNs3JakesProcess__PythonHelper* >(self->obj);
    
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
PyNs3JakesProcess__PythonHelper::_wrap_DoInitialize(PyNs3JakesProcess *self)
{
    PyObject *py_retval;
    PyNs3JakesProcess__PythonHelper *helper = dynamic_cast< PyNs3JakesProcess__PythonHelper* >(self->obj);
    
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
PyNs3JakesProcess__PythonHelper::_wrap_NotifyNewAggregate(PyNs3JakesProcess *self)
{
    PyObject *py_retval;
    PyNs3JakesProcess__PythonHelper *helper = dynamic_cast< PyNs3JakesProcess__PythonHelper* >(self->obj);
    
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
PyNs3JakesProcess__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::JakesProcess *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::JakesProcess::DoDispose();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3JakesProcess* >(m_pyself)->obj;
    reinterpret_cast< PyNs3JakesProcess* >(m_pyself)->obj = (ns3::JakesProcess*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3JakesProcess* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3JakesProcess* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3JakesProcess* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3JakesProcess__PythonHelper::GetInstanceTypeId() const
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
PyNs3JakesProcess__PythonHelper::DoInitialize()
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
PyNs3JakesProcess__PythonHelper::NotifyNewAggregate()
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
PyNs3JakesProcess__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3JakesProcess__tp_init__0(PyNs3JakesProcess *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3JakesProcess *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3JakesProcess_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3JakesProcess_Type)
    {
        self->obj = new PyNs3JakesProcess__PythonHelper(*((PyNs3JakesProcess *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3JakesProcess__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::JakesProcess(*((PyNs3JakesProcess *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3JakesProcess__tp_init__1(PyNs3JakesProcess *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3JakesProcess_Type)
    {
        self->obj = new PyNs3JakesProcess__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3JakesProcess__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::JakesProcess();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3JakesProcess__tp_init(PyNs3JakesProcess *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3JakesProcess__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3JakesProcess__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3JakesProcess_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::JakesProcess::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3JakesProcess_SetPropagationLossModel(PyNs3JakesProcess *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3PropagationLossModel *model;
    ns3::PropagationLossModel *model_ptr;
    const char *keywords[] = {"model", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PropagationLossModel_Type, &model)) {
        return NULL;
    }
    model_ptr = (model ? model->obj : NULL);
    self->obj->SetPropagationLossModel(ns3::Ptr< ns3::PropagationLossModel  > (model_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3JakesProcess_GetChannelGainDb(PyNs3JakesProcess *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetChannelGainDb();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3JakesProcess_DoDispose(PyNs3JakesProcess *self)
{
    PyObject *py_retval;
    PyNs3JakesProcess__PythonHelper *helper_class = dynamic_cast<PyNs3JakesProcess__PythonHelper*> (self->obj);
    
    (helper_class == NULL)? (self->obj->DoDispose()) : (self->obj->ns3::JakesProcess::DoDispose());
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3JakesProcess__copy__(PyNs3JakesProcess *self)
{

    PyNs3JakesProcess *py_copy;
    py_copy = PyObject_GC_New(PyNs3JakesProcess, &PyNs3JakesProcess_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::JakesProcess(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3JakesProcess_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3JakesProcess_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetPropagationLossModel", (PyCFunction) _wrap_PyNs3JakesProcess_SetPropagationLossModel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetChannelGainDb", (PyCFunction) _wrap_PyNs3JakesProcess_GetChannelGainDb, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) _wrap_PyNs3JakesProcess_DoDispose, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3JakesProcess__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3JakesProcess__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3JakesProcess__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3JakesProcess__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3JakesProcess__tp_clear(PyNs3JakesProcess *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::JakesProcess *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3JakesProcess__tp_traverse(PyNs3JakesProcess *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3JakesProcess__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3JakesProcess__tp_dealloc(PyNs3JakesProcess *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3JakesProcess__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3JakesProcess__tp_richcompare (PyNs3JakesProcess *PYBINDGEN_UNUSED(self), PyNs3JakesProcess *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3JakesProcess_Type)) {
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

PyTypeObject PyNs3JakesProcess_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.JakesProcess",            /* tp_name */
    sizeof(PyNs3JakesProcess),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3JakesProcess__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3JakesProcess__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3JakesProcess__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3JakesProcess__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3JakesProcess_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3JakesProcess, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3JakesProcess__tp_init,             /* tp_init */
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
PyNs3JakesPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3JakesPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3JakesPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3JakesPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3JakesPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3JakesPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3JakesPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3JakesPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3JakesPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3JakesPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3JakesPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3JakesPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3JakesPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3JakesPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3JakesPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3JakesPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3JakesPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::JakesPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::JakesPropagationLossModel* >((const ns3::JakesPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3JakesPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::JakesPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = (ns3::JakesPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3JakesPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3JakesPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3JakesPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3JakesPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3JakesPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3JakesPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3JakesPropagationLossModel__tp_init(PyNs3JakesPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3JakesPropagationLossModel_Type)
    {
        self->obj = new PyNs3JakesPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3JakesPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::JakesPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3JakesPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::JakesPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3JakesPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3JakesPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3JakesPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3JakesPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3JakesPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3JakesPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3JakesPropagationLossModel__tp_clear(PyNs3JakesPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::JakesPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3JakesPropagationLossModel__tp_traverse(PyNs3JakesPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3JakesPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3JakesPropagationLossModel__tp_dealloc(PyNs3JakesPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3JakesPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3JakesPropagationLossModel__tp_richcompare (PyNs3JakesPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3JakesPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3JakesPropagationLossModel_Type)) {
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

PyTypeObject PyNs3JakesPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.JakesPropagationLossModel",            /* tp_name */
    sizeof(PyNs3JakesPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3JakesPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3JakesPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3JakesPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3JakesPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3JakesPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3JakesPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3JakesPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3Kun2600MhzPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Kun2600MhzPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Kun2600MhzPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3Kun2600MhzPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Kun2600MhzPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Kun2600MhzPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3Kun2600MhzPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Kun2600MhzPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Kun2600MhzPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3Kun2600MhzPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3Kun2600MhzPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3Kun2600MhzPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Kun2600MhzPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::Kun2600MhzPropagationLossModel* >((const ns3::Kun2600MhzPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::Kun2600MhzPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = (ns3::Kun2600MhzPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3Kun2600MhzPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3Kun2600MhzPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3Kun2600MhzPropagationLossModel__tp_init(PyNs3Kun2600MhzPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3Kun2600MhzPropagationLossModel_Type)
    {
        self->obj = new PyNs3Kun2600MhzPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3Kun2600MhzPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::Kun2600MhzPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3Kun2600MhzPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::Kun2600MhzPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3Kun2600MhzPropagationLossModel_GetLoss(PyNs3Kun2600MhzPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->GetLoss(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}

static PyMethodDef PyNs3Kun2600MhzPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3Kun2600MhzPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetLoss", (PyCFunction) _wrap_PyNs3Kun2600MhzPropagationLossModel_GetLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3Kun2600MhzPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3Kun2600MhzPropagationLossModel__tp_clear(PyNs3Kun2600MhzPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::Kun2600MhzPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3Kun2600MhzPropagationLossModel__tp_traverse(PyNs3Kun2600MhzPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3Kun2600MhzPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3Kun2600MhzPropagationLossModel__tp_dealloc(PyNs3Kun2600MhzPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3Kun2600MhzPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Kun2600MhzPropagationLossModel__tp_richcompare (PyNs3Kun2600MhzPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3Kun2600MhzPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Kun2600MhzPropagationLossModel_Type)) {
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

PyTypeObject PyNs3Kun2600MhzPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.Kun2600MhzPropagationLossModel",            /* tp_name */
    sizeof(PyNs3Kun2600MhzPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Kun2600MhzPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3Kun2600MhzPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3Kun2600MhzPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Kun2600MhzPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Kun2600MhzPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3Kun2600MhzPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Kun2600MhzPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3LogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3LogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3LogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3LogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3LogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3LogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3LogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3LogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3LogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3LogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3LogDistancePropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3LogDistancePropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3LogDistancePropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LogDistancePropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = const_cast< ns3::LogDistancePropagationLossModel* >((const ns3::LogDistancePropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3LogDistancePropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::LogDistancePropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = (ns3::LogDistancePropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3LogDistancePropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3LogDistancePropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3LogDistancePropagationLossModel__PythonHelper::DoDispose()
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
PyNs3LogDistancePropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3LogDistancePropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3LogDistancePropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3LogDistancePropagationLossModel__tp_init(PyNs3LogDistancePropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3LogDistancePropagationLossModel_Type)
    {
        self->obj = new PyNs3LogDistancePropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3LogDistancePropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::LogDistancePropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3LogDistancePropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::LogDistancePropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3LogDistancePropagationLossModel_SetReference(PyNs3LogDistancePropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double referenceDistance;
    double referenceLoss;
    const char *keywords[] = {"referenceDistance", "referenceLoss", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dd", (char **) keywords, &referenceDistance, &referenceLoss)) {
        return NULL;
    }
    self->obj->SetReference(referenceDistance, referenceLoss);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3LogDistancePropagationLossModel_GetPathLossExponent(PyNs3LogDistancePropagationLossModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetPathLossExponent();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3LogDistancePropagationLossModel_SetPathLossExponent(PyNs3LogDistancePropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double n;
    const char *keywords[] = {"n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &n)) {
        return NULL;
    }
    self->obj->SetPathLossExponent(n);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3LogDistancePropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3LogDistancePropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetReference", (PyCFunction) _wrap_PyNs3LogDistancePropagationLossModel_SetReference, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPathLossExponent", (PyCFunction) _wrap_PyNs3LogDistancePropagationLossModel_GetPathLossExponent, METH_NOARGS, NULL },
    {(char *) "SetPathLossExponent", (PyCFunction) _wrap_PyNs3LogDistancePropagationLossModel_SetPathLossExponent, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3LogDistancePropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3LogDistancePropagationLossModel__tp_clear(PyNs3LogDistancePropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::LogDistancePropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3LogDistancePropagationLossModel__tp_traverse(PyNs3LogDistancePropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3LogDistancePropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3LogDistancePropagationLossModel__tp_dealloc(PyNs3LogDistancePropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3LogDistancePropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3LogDistancePropagationLossModel__tp_richcompare (PyNs3LogDistancePropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3LogDistancePropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3LogDistancePropagationLossModel_Type)) {
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

PyTypeObject PyNs3LogDistancePropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.LogDistancePropagationLossModel",            /* tp_name */
    sizeof(PyNs3LogDistancePropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3LogDistancePropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3LogDistancePropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3LogDistancePropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3LogDistancePropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3LogDistancePropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3LogDistancePropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3LogDistancePropagationLossModel__tp_init,             /* tp_init */
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
PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3MatrixPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3MatrixPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3MatrixPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3MatrixPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3MatrixPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3MatrixPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3MatrixPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3MatrixPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3MatrixPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3MatrixPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3MatrixPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3MatrixPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3MatrixPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MatrixPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::MatrixPropagationLossModel* >((const ns3::MatrixPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3MatrixPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MatrixPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = (ns3::MatrixPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MatrixPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3MatrixPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3MatrixPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3MatrixPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3MatrixPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3MatrixPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3MatrixPropagationLossModel__tp_init(PyNs3MatrixPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3MatrixPropagationLossModel_Type)
    {
        self->obj = new PyNs3MatrixPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3MatrixPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::MatrixPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3MatrixPropagationLossModel_SetDefaultLoss(PyNs3MatrixPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double defaultLoss;
    const char *keywords[] = {"defaultLoss", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &defaultLoss)) {
        return NULL;
    }
    self->obj->SetDefaultLoss(defaultLoss);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MatrixPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::MatrixPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3MatrixPropagationLossModel_SetLoss(PyNs3MatrixPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    double loss;
    bool symmetric;
    PyObject *py_symmetric = NULL;
    const char *keywords[] = {"a", "b", "loss", "symmetric", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!d|O", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b, &loss, &py_symmetric)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    symmetric = py_symmetric? (bool) PyObject_IsTrue(py_symmetric) : true;
    self->obj->SetLoss(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr), loss, symmetric);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

static PyMethodDef PyNs3MatrixPropagationLossModel_methods[] = {
    {(char *) "SetDefaultLoss", (PyCFunction) _wrap_PyNs3MatrixPropagationLossModel_SetDefaultLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3MatrixPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetLoss", (PyCFunction) _wrap_PyNs3MatrixPropagationLossModel_SetLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3MatrixPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3MatrixPropagationLossModel__tp_clear(PyNs3MatrixPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::MatrixPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3MatrixPropagationLossModel__tp_traverse(PyNs3MatrixPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3MatrixPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3MatrixPropagationLossModel__tp_dealloc(PyNs3MatrixPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3MatrixPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3MatrixPropagationLossModel__tp_richcompare (PyNs3MatrixPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3MatrixPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3MatrixPropagationLossModel_Type)) {
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

PyTypeObject PyNs3MatrixPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.MatrixPropagationLossModel",            /* tp_name */
    sizeof(PyNs3MatrixPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3MatrixPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3MatrixPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3MatrixPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3MatrixPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3MatrixPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3MatrixPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3MatrixPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3NakagamiPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3NakagamiPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3NakagamiPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3NakagamiPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3NakagamiPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3NakagamiPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3NakagamiPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3NakagamiPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3NakagamiPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3NakagamiPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3NakagamiPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3NakagamiPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3NakagamiPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::NakagamiPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::NakagamiPropagationLossModel* >((const ns3::NakagamiPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3NakagamiPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::NakagamiPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = (ns3::NakagamiPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3NakagamiPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3NakagamiPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3NakagamiPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3NakagamiPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3NakagamiPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3NakagamiPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3NakagamiPropagationLossModel__tp_init(PyNs3NakagamiPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3NakagamiPropagationLossModel_Type)
    {
        self->obj = new PyNs3NakagamiPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3NakagamiPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::NakagamiPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3NakagamiPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::NakagamiPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3NakagamiPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3NakagamiPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3NakagamiPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3NakagamiPropagationLossModel__tp_clear(PyNs3NakagamiPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::NakagamiPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3NakagamiPropagationLossModel__tp_traverse(PyNs3NakagamiPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3NakagamiPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3NakagamiPropagationLossModel__tp_dealloc(PyNs3NakagamiPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3NakagamiPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3NakagamiPropagationLossModel__tp_richcompare (PyNs3NakagamiPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3NakagamiPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3NakagamiPropagationLossModel_Type)) {
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

PyTypeObject PyNs3NakagamiPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.NakagamiPropagationLossModel",            /* tp_name */
    sizeof(PyNs3NakagamiPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3NakagamiPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3NakagamiPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3NakagamiPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3NakagamiPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3NakagamiPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3NakagamiPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3NakagamiPropagationLossModel__tp_init,             /* tp_init */
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3OkumuraHataPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3OkumuraHataPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3OkumuraHataPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_DoInitialize(PyNs3OkumuraHataPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3OkumuraHataPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3OkumuraHataPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3OkumuraHataPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3OkumuraHataPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3OkumuraHataPropagationLossModel__PythonHelper* >(self->obj);
    
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_DoDispose(PyNs3OkumuraHataPropagationLossModel *self)
{
    PyObject *py_retval;
    PyNs3OkumuraHataPropagationLossModel__PythonHelper *helper = dynamic_cast< PyNs3OkumuraHataPropagationLossModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

double
PyNs3OkumuraHataPropagationLossModel__PythonHelper::DoCalcRxPower(double txPowerDbm, ns3::Ptr< ns3::MobilityModel > a, ns3::Ptr< ns3::MobilityModel > b) const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OkumuraHataPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    PyNs3MobilityModel *py_MobilityModel2;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter2;
    PyTypeObject *wrapper_type2 = 0;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoCalcRxPower"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = const_cast< ns3::OkumuraHataPropagationLossModel* >((const ns3::OkumuraHataPropagationLossModel*) this);
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL)
        {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (a));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    if (typeid(*(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel2 = (PyNs3MobilityModel*) (((PyNs3MobilityModel__PythonHelper*) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)))->m_pyself);
        py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
        Py_INCREF(py_MobilityModel2);
    } else {
        wrapper_lookup_iter2 = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b)));
        if (wrapper_lookup_iter2 == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel2 = NULL;
        } else {
            py_MobilityModel2 = (PyNs3MobilityModel *) wrapper_lookup_iter2->second;
            Py_INCREF(py_MobilityModel2);
        }
    
        if (py_MobilityModel2 == NULL)
        {
            wrapper_type2 = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid(*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))), &PyNs3MobilityModel_Type);
            py_MobilityModel2 = PyObject_GC_New(PyNs3MobilityModel, wrapper_type2);
            py_MobilityModel2->inst_dict = NULL;
    
            py_MobilityModel2->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b))->Ref();
            py_MobilityModel2->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (b));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel2->obj] = (PyObject *) py_MobilityModel2;
        }
    }
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoCalcRxPower", (char *) "dNN", txPowerDbm, py_MobilityModel, py_MobilityModel2);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

int64_t
PyNs3OkumuraHataPropagationLossModel__PythonHelper::DoAssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::OkumuraHataPropagationLossModel *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoAssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = (ns3::OkumuraHataPropagationLossModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3OkumuraHataPropagationLossModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3OkumuraHataPropagationLossModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::DoDispose()
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::DoInitialize()
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::NotifyNewAggregate()
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
PyNs3OkumuraHataPropagationLossModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3OkumuraHataPropagationLossModel__tp_init(PyNs3OkumuraHataPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3OkumuraHataPropagationLossModel_Type)
    {
        self->obj = new PyNs3OkumuraHataPropagationLossModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3OkumuraHataPropagationLossModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::OkumuraHataPropagationLossModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}


PyObject *
_wrap_PyNs3OkumuraHataPropagationLossModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::OkumuraHataPropagationLossModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OkumuraHataPropagationLossModel_GetLoss(PyNs3OkumuraHataPropagationLossModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *a;
    ns3::MobilityModel *a_ptr;
    PyNs3MobilityModel *b;
    ns3::MobilityModel *b_ptr;
    const char *keywords[] = {"a", "b", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3MobilityModel_Type, &a, &PyNs3MobilityModel_Type, &b)) {
        return NULL;
    }
    a_ptr = (a ? a->obj : NULL);
    b_ptr = (b ? b->obj : NULL);
    retval = self->obj->GetLoss(ns3::Ptr< ns3::MobilityModel  > (a_ptr), ns3::Ptr< ns3::MobilityModel  > (b_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}

static PyMethodDef PyNs3OkumuraHataPropagationLossModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OkumuraHataPropagationLossModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetLoss", (PyCFunction) _wrap_PyNs3OkumuraHataPropagationLossModel_GetLoss, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3OkumuraHataPropagationLossModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OkumuraHataPropagationLossModel__tp_clear(PyNs3OkumuraHataPropagationLossModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::OkumuraHataPropagationLossModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3OkumuraHataPropagationLossModel__tp_traverse(PyNs3OkumuraHataPropagationLossModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3OkumuraHataPropagationLossModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3OkumuraHataPropagationLossModel__tp_dealloc(PyNs3OkumuraHataPropagationLossModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OkumuraHataPropagationLossModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OkumuraHataPropagationLossModel__tp_richcompare (PyNs3OkumuraHataPropagationLossModel *PYBINDGEN_UNUSED(self), PyNs3OkumuraHataPropagationLossModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OkumuraHataPropagationLossModel_Type)) {
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

PyTypeObject PyNs3OkumuraHataPropagationLossModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "propagation.OkumuraHataPropagationLossModel",            /* tp_name */
    sizeof(PyNs3OkumuraHataPropagationLossModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OkumuraHataPropagationLossModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3OkumuraHataPropagationLossModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OkumuraHataPropagationLossModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OkumuraHataPropagationLossModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OkumuraHataPropagationLossModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OkumuraHataPropagationLossModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OkumuraHataPropagationLossModel__tp_init,             /* tp_init */
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
static struct PyModuleDef propagation_moduledef = {
    PyModuleDef_HEAD_INIT,
    "propagation",
    NULL,
    -1,
    propagation_functions,
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


MOD_INIT(propagation)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&propagation_moduledef);
    #else
    m = Py_InitModule3((char *) "propagation", propagation_functions, NULL);
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
    /* Import the 'ns3::Vector2D' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Vector2D_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Vector2D");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Vector2D_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Vector2D_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Vector2D_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::Vector3D' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Vector3D_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Vector3D");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Vector3D_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Vector3D_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Vector3D_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::LogNormalRandomVariable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3LogNormalRandomVariable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "LogNormalRandomVariable");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::MobilityModel' class from module 'ns.mobility' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.mobility");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3MobilityModel_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "MobilityModel");
    
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
    /* Import the 'ns3::Vector2DChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Vector2DChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Vector2DChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Vector2DValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Vector2DValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Vector2DValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Vector3DChecker' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Vector3DChecker_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Vector3DChecker");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::Vector3DValue' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Vector3DValue_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Vector3DValue");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    PyModule_AddObject(m, (char *) "_PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3PropagationCache__Ns3JakesProcess_wrapper_registry, NULL));
    /* Register the 'ns3::PropagationCache< ns3::JakesProcess >' class */
    if (PyType_Ready(&PyNs3PropagationCache__Ns3JakesProcess_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PropagationCache__Ns3JakesProcess", (PyObject *) &PyNs3PropagationCache__Ns3JakesProcess_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::PropagationDelayModel), &PyNs3PropagationDelayModel_Type);
    /* Register the 'ns3::PropagationDelayModel' class */
    PyNs3PropagationDelayModel_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3PropagationDelayModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PropagationDelayModel", (PyObject *) &PyNs3PropagationDelayModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::PropagationLossModel), &PyNs3PropagationLossModel_Type);
    /* Register the 'ns3::PropagationLossModel' class */
    PyNs3PropagationLossModel_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3PropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PropagationLossModel", (PyObject *) &PyNs3PropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomPropagationDelayModel), &PyNs3RandomPropagationDelayModel_Type);
    /* Register the 'ns3::RandomPropagationDelayModel' class */
    PyNs3RandomPropagationDelayModel_Type.tp_base = &PyNs3PropagationDelayModel_Type;
    if (PyType_Ready(&PyNs3RandomPropagationDelayModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomPropagationDelayModel", (PyObject *) &PyNs3RandomPropagationDelayModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomPropagationLossModel), &PyNs3RandomPropagationLossModel_Type);
    /* Register the 'ns3::RandomPropagationLossModel' class */
    PyNs3RandomPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3RandomPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomPropagationLossModel", (PyObject *) &PyNs3RandomPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RangePropagationLossModel), &PyNs3RangePropagationLossModel_Type);
    /* Register the 'ns3::RangePropagationLossModel' class */
    PyNs3RangePropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3RangePropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RangePropagationLossModel", (PyObject *) &PyNs3RangePropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ThreeLogDistancePropagationLossModel), &PyNs3ThreeLogDistancePropagationLossModel_Type);
    /* Register the 'ns3::ThreeLogDistancePropagationLossModel' class */
    PyNs3ThreeLogDistancePropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3ThreeLogDistancePropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ThreeLogDistancePropagationLossModel", (PyObject *) &PyNs3ThreeLogDistancePropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::TwoRayGroundPropagationLossModel), &PyNs3TwoRayGroundPropagationLossModel_Type);
    /* Register the 'ns3::TwoRayGroundPropagationLossModel' class */
    PyNs3TwoRayGroundPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3TwoRayGroundPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "TwoRayGroundPropagationLossModel", (PyObject *) &PyNs3TwoRayGroundPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ConstantSpeedPropagationDelayModel), &PyNs3ConstantSpeedPropagationDelayModel_Type);
    /* Register the 'ns3::ConstantSpeedPropagationDelayModel' class */
    PyNs3ConstantSpeedPropagationDelayModel_Type.tp_base = &PyNs3PropagationDelayModel_Type;
    if (PyType_Ready(&PyNs3ConstantSpeedPropagationDelayModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ConstantSpeedPropagationDelayModel", (PyObject *) &PyNs3ConstantSpeedPropagationDelayModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Cost231PropagationLossModel), &PyNs3Cost231PropagationLossModel_Type);
    /* Register the 'ns3::Cost231PropagationLossModel' class */
    PyNs3Cost231PropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3Cost231PropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Cost231PropagationLossModel", (PyObject *) &PyNs3Cost231PropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::FixedRssLossModel), &PyNs3FixedRssLossModel_Type);
    /* Register the 'ns3::FixedRssLossModel' class */
    PyNs3FixedRssLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3FixedRssLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FixedRssLossModel", (PyObject *) &PyNs3FixedRssLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::FriisPropagationLossModel), &PyNs3FriisPropagationLossModel_Type);
    /* Register the 'ns3::FriisPropagationLossModel' class */
    PyNs3FriisPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3FriisPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "FriisPropagationLossModel", (PyObject *) &PyNs3FriisPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ItuR1411LosPropagationLossModel), &PyNs3ItuR1411LosPropagationLossModel_Type);
    /* Register the 'ns3::ItuR1411LosPropagationLossModel' class */
    PyNs3ItuR1411LosPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3ItuR1411LosPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ItuR1411LosPropagationLossModel", (PyObject *) &PyNs3ItuR1411LosPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ItuR1411NlosOverRooftopPropagationLossModel), &PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type);
    /* Register the 'ns3::ItuR1411NlosOverRooftopPropagationLossModel' class */
    PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ItuR1411NlosOverRooftopPropagationLossModel", (PyObject *) &PyNs3ItuR1411NlosOverRooftopPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::JakesProcess), &PyNs3JakesProcess_Type);
    /* Register the 'ns3::JakesProcess' class */
    PyNs3JakesProcess_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3JakesProcess_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "JakesProcess", (PyObject *) &PyNs3JakesProcess_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::JakesPropagationLossModel), &PyNs3JakesPropagationLossModel_Type);
    /* Register the 'ns3::JakesPropagationLossModel' class */
    PyNs3JakesPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3JakesPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "JakesPropagationLossModel", (PyObject *) &PyNs3JakesPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::Kun2600MhzPropagationLossModel), &PyNs3Kun2600MhzPropagationLossModel_Type);
    /* Register the 'ns3::Kun2600MhzPropagationLossModel' class */
    PyNs3Kun2600MhzPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3Kun2600MhzPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Kun2600MhzPropagationLossModel", (PyObject *) &PyNs3Kun2600MhzPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::LogDistancePropagationLossModel), &PyNs3LogDistancePropagationLossModel_Type);
    /* Register the 'ns3::LogDistancePropagationLossModel' class */
    PyNs3LogDistancePropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3LogDistancePropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "LogDistancePropagationLossModel", (PyObject *) &PyNs3LogDistancePropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::MatrixPropagationLossModel), &PyNs3MatrixPropagationLossModel_Type);
    /* Register the 'ns3::MatrixPropagationLossModel' class */
    PyNs3MatrixPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3MatrixPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "MatrixPropagationLossModel", (PyObject *) &PyNs3MatrixPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::NakagamiPropagationLossModel), &PyNs3NakagamiPropagationLossModel_Type);
    /* Register the 'ns3::NakagamiPropagationLossModel' class */
    PyNs3NakagamiPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3NakagamiPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "NakagamiPropagationLossModel", (PyObject *) &PyNs3NakagamiPropagationLossModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::OkumuraHataPropagationLossModel), &PyNs3OkumuraHataPropagationLossModel_Type);
    /* Register the 'ns3::OkumuraHataPropagationLossModel' class */
    PyNs3OkumuraHataPropagationLossModel_Type.tp_base = &PyNs3PropagationLossModel_Type;
    if (PyType_Ready(&PyNs3OkumuraHataPropagationLossModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "OkumuraHataPropagationLossModel", (PyObject *) &PyNs3OkumuraHataPropagationLossModel_Type);
    PyModule_AddObject(m, (char *) "Vector", (PyObject *) &PyNs3Vector3D_Type);
    PyModule_AddObject(m, (char *) "VectorValue", (PyObject *) &PyNs3Vector3DValue_Type);
    PyModule_AddObject(m, (char *) "VectorChecker", (PyObject *) &PyNs3Vector3DChecker_Type);
    PyModule_AddIntConstant(m, (char *) "SmallCity", ns3::SmallCity);
    PyModule_AddIntConstant(m, (char *) "MediumCity", ns3::MediumCity);
    PyModule_AddIntConstant(m, (char *) "LargeCity", ns3::LargeCity);
    PyModule_AddIntConstant(m, (char *) "UrbanEnvironment", ns3::UrbanEnvironment);
    PyModule_AddIntConstant(m, (char *) "SubUrbanEnvironment", ns3::SubUrbanEnvironment);
    PyModule_AddIntConstant(m, (char *) "OpenAreasEnvironment", ns3::OpenAreasEnvironment);
    submodule = initpropagation_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initpropagation_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initpropagation_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    return MOD_RETURN(m);
}
