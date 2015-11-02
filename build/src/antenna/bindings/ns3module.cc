#include "ns3module.h"
static PyMethodDef antenna_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef antenna_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "antenna.FatalImpl",
    NULL,
    -1,
    antenna_FatalImpl_functions,
};
#endif

static PyObject *
initantenna_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&antenna_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "antenna.FatalImpl", antenna_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef antenna_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef antenna_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "antenna.Hash.Function",
    NULL,
    -1,
    antenna_Hash_Function_functions,
};
#endif

static PyObject *
initantenna_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&antenna_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "antenna.Hash.Function", antenna_Hash_Function_functions, NULL);
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
static PyMethodDef antenna_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef antenna_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "antenna.Hash",
    NULL,
    -1,
    antenna_Hash_functions,
};
#endif

static PyObject *
initantenna_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&antenna_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "antenna.Hash", antenna_Hash_functions, NULL);
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
    submodule = initantenna_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
/* --- module functions --- */


PyObject *
_wrap_antenna_DegreesToRadians(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    double degrees;
    const char *keywords[] = {"degrees", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &degrees)) {
        return NULL;
    }
    retval = ns3::DegreesToRadians(degrees);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}
PyObject * _wrap_antenna_DegreesToRadians(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);


PyObject *
_wrap_antenna_RadiansToDegrees(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    double radians;
    const char *keywords[] = {"radians", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &radians)) {
        return NULL;
    }
    retval = ns3::RadiansToDegrees(radians);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}
PyObject * _wrap_antenna_RadiansToDegrees(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);

static PyMethodDef antenna_functions[] = {
    {(char *) "DegreesToRadians", (PyCFunction) _wrap_antenna_DegreesToRadians, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RadiansToDegrees", (PyCFunction) _wrap_antenna_RadiansToDegrees, METH_KEYWORDS|METH_VARARGS, NULL },
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


PyTypeObject *_PyNs3Vector2DChecker_Type;


PyTypeObject *_PyNs3Vector2DValue_Type;


PyTypeObject *_PyNs3Vector3DChecker_Type;


PyTypeObject *_PyNs3Vector3DValue_Type;


std::map<void*, PyObject*> PyNs3Angles_wrapper_registry;
static PyObject* _wrap_PyNs3Angles__get_phi(PyNs3Angles *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->phi);
    return py_retval;
}
static int _wrap_PyNs3Angles__set_phi(PyNs3Angles *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->phi)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Angles__get_theta(PyNs3Angles *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->theta);
    return py_retval;
}
static int _wrap_PyNs3Angles__set_theta(PyNs3Angles *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->theta)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Angles__getsets[] = {
    {
        (char*) "theta", /* attribute name */
        (getter) _wrap_PyNs3Angles__get_theta, /* C function to get the attribute */
        (setter) _wrap_PyNs3Angles__set_theta, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "phi", /* attribute name */
        (getter) _wrap_PyNs3Angles__get_phi, /* C function to get the attribute */
        (setter) _wrap_PyNs3Angles__set_phi, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Angles__tp_init__0(PyNs3Angles *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Angles *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Angles_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Angles(*((PyNs3Angles *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Angles__tp_init__1(PyNs3Angles *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Angles();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Angles__tp_init__2(PyNs3Angles *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    double phi;
    double theta;
    const char *keywords[] = {"phi", "theta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dd", (char **) keywords, &phi, &theta)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Angles(phi, theta);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Angles__tp_init__3(PyNs3Angles *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Vector3D *v;
    const char *keywords[] = {"v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &v)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Angles(*((PyNs3Vector3D *) v)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Angles__tp_init__4(PyNs3Angles *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Vector3D *v;
    PyNs3Vector3D *o;
    const char *keywords[] = {"v", "o", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Vector3D_Type, &v, &PyNs3Vector3D_Type, &o)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Angles(*((PyNs3Vector3D *) v)->obj, *((PyNs3Vector3D *) o)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Angles__tp_init(PyNs3Angles *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[5] = {0,};
    retval = _wrap_PyNs3Angles__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Angles__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Angles__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3Angles__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    retval = _wrap_PyNs3Angles__tp_init__4(self, args, kwargs, &exceptions[4]);
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


static PyObject*
_wrap_PyNs3Angles__copy__(PyNs3Angles *self)
{

    PyNs3Angles *py_copy;
    py_copy = PyObject_New(PyNs3Angles, &PyNs3Angles_Type);
    py_copy->obj = new ns3::Angles(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Angles_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Angles_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Angles__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Angles__tp_dealloc(PyNs3Angles *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Angles_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Angles_wrapper_registry.end()) {
        PyNs3Angles_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Angles *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Angles__tp_str(PyNs3Angles *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Angles__tp_richcompare (PyNs3Angles *PYBINDGEN_UNUSED(self), PyNs3Angles *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Angles_Type)) {
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

PyTypeObject PyNs3Angles_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "antenna.Angles",            /* tp_name */
    sizeof(PyNs3Angles),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Angles__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Angles__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Angles__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Angles_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Angles__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Angles__tp_init,             /* tp_init */
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
PyNs3AntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3AntennaModel *self)
{
    PyObject *py_retval;
    PyNs3AntennaModel__PythonHelper *helper = dynamic_cast< PyNs3AntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3AntennaModel__PythonHelper::_wrap_DoInitialize(PyNs3AntennaModel *self)
{
    PyObject *py_retval;
    PyNs3AntennaModel__PythonHelper *helper = dynamic_cast< PyNs3AntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3AntennaModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3AntennaModel *self)
{
    PyObject *py_retval;
    PyNs3AntennaModel__PythonHelper *helper = dynamic_cast< PyNs3AntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3AntennaModel__PythonHelper::_wrap_DoDispose(PyNs3AntennaModel *self)
{
    PyObject *py_retval;
    PyNs3AntennaModel__PythonHelper *helper = dynamic_cast< PyNs3AntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3AntennaModel__PythonHelper::GetGainDb(ns3::Angles a)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::AntennaModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3Angles *py_Angles;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetGainDb"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3AntennaModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3AntennaModel* >(m_pyself)->obj = (ns3::AntennaModel*) this;
    py_Angles = PyObject_New(PyNs3Angles, &PyNs3Angles_Type);
    py_Angles->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Angles->obj = new ns3::Angles(a);
    PyNs3Angles_wrapper_registry[(void *) py_Angles->obj] = (PyObject *) py_Angles;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetGainDb", (char *) "N", py_Angles);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3AntennaModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3AntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3AntennaModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3AntennaModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3AntennaModel__PythonHelper::DoDispose()
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
PyNs3AntennaModel__PythonHelper::DoInitialize()
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
PyNs3AntennaModel__PythonHelper::NotifyNewAggregate()
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
PyNs3AntennaModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3AntennaModel__tp_init__0(PyNs3AntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AntennaModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AntennaModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3AntennaModel_Type)
    {
        self->obj = new PyNs3AntennaModel__PythonHelper(*((PyNs3AntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3AntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'AntennaModel' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3AntennaModel__tp_init__1(PyNs3AntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3AntennaModel_Type)
    {
        self->obj = new PyNs3AntennaModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3AntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'AntennaModel' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3AntennaModel__tp_init(PyNs3AntennaModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AntennaModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AntennaModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AntennaModel_GetGainDb(PyNs3AntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3Angles *a;
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Angles_Type, &a)) {
        return NULL;
    }
    retval = self->obj->GetGainDb(*((PyNs3Angles *) a)->obj);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AntennaModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::AntennaModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}

static PyMethodDef PyNs3AntennaModel_methods[] = {
    {(char *) "GetGainDb", (PyCFunction) _wrap_PyNs3AntennaModel_GetGainDb, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AntennaModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3AntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3AntennaModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3AntennaModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3AntennaModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AntennaModel__tp_clear(PyNs3AntennaModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::AntennaModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3AntennaModel__tp_traverse(PyNs3AntennaModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3AntennaModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3AntennaModel__tp_dealloc(PyNs3AntennaModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AntennaModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AntennaModel__tp_richcompare (PyNs3AntennaModel *PYBINDGEN_UNUSED(self), PyNs3AntennaModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AntennaModel_Type)) {
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

PyTypeObject PyNs3AntennaModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "antenna.AntennaModel",            /* tp_name */
    sizeof(PyNs3AntennaModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AntennaModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3AntennaModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AntennaModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AntennaModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AntennaModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AntennaModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AntennaModel__tp_init,             /* tp_init */
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
PyNs3CosineAntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3CosineAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3CosineAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3CosineAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3CosineAntennaModel__PythonHelper::_wrap_DoInitialize(PyNs3CosineAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3CosineAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3CosineAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3CosineAntennaModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3CosineAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3CosineAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3CosineAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3CosineAntennaModel__PythonHelper::_wrap_DoDispose(PyNs3CosineAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3CosineAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3CosineAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3CosineAntennaModel__PythonHelper::GetGainDb(ns3::Angles a)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::CosineAntennaModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3Angles *py_Angles;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetGainDb"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CosineAntennaModel::GetGainDb(a);
    }
    self_obj_before = reinterpret_cast< PyNs3CosineAntennaModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3CosineAntennaModel* >(m_pyself)->obj = (ns3::CosineAntennaModel*) this;
    py_Angles = PyObject_New(PyNs3Angles, &PyNs3Angles_Type);
    py_Angles->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Angles->obj = new ns3::Angles(a);
    PyNs3Angles_wrapper_registry[(void *) py_Angles->obj] = (PyObject *) py_Angles;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetGainDb", (char *) "N", py_Angles);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3CosineAntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CosineAntennaModel::GetGainDb(a);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3CosineAntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::CosineAntennaModel::GetGainDb(a);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3CosineAntennaModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3CosineAntennaModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3CosineAntennaModel__PythonHelper::DoDispose()
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
PyNs3CosineAntennaModel__PythonHelper::DoInitialize()
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
PyNs3CosineAntennaModel__PythonHelper::NotifyNewAggregate()
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
PyNs3CosineAntennaModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3CosineAntennaModel__tp_init__0(PyNs3CosineAntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3CosineAntennaModel_Type)
    {
        self->obj = new PyNs3CosineAntennaModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3CosineAntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::CosineAntennaModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3CosineAntennaModel__tp_init__1(PyNs3CosineAntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3CosineAntennaModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3CosineAntennaModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3CosineAntennaModel_Type)
    {
        self->obj = new PyNs3CosineAntennaModel__PythonHelper(*((PyNs3CosineAntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3CosineAntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::CosineAntennaModel(*((PyNs3CosineAntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3CosineAntennaModel__tp_init(PyNs3CosineAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3CosineAntennaModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3CosineAntennaModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3CosineAntennaModel_SetOrientation(PyNs3CosineAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double orientationDegrees;
    const char *keywords[] = {"orientationDegrees", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &orientationDegrees)) {
        return NULL;
    }
    self->obj->SetOrientation(orientationDegrees);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CosineAntennaModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::CosineAntennaModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3CosineAntennaModel_GetOrientation(PyNs3CosineAntennaModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetOrientation();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CosineAntennaModel_GetBeamwidth(PyNs3CosineAntennaModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetBeamwidth();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3CosineAntennaModel_SetBeamwidth(PyNs3CosineAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double beamwidthDegrees;
    const char *keywords[] = {"beamwidthDegrees", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &beamwidthDegrees)) {
        return NULL;
    }
    self->obj->SetBeamwidth(beamwidthDegrees);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3CosineAntennaModel_GetGainDb(PyNs3CosineAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3Angles *a;
    PyNs3CosineAntennaModel__PythonHelper *helper_class = dynamic_cast<PyNs3CosineAntennaModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Angles_Type, &a)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->GetGainDb(*((PyNs3Angles *) a)->obj)) : (self->obj->ns3::CosineAntennaModel::GetGainDb(*((PyNs3Angles *) a)->obj));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3CosineAntennaModel__copy__(PyNs3CosineAntennaModel *self)
{

    PyNs3CosineAntennaModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3CosineAntennaModel, &PyNs3CosineAntennaModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::CosineAntennaModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3CosineAntennaModel_methods[] = {
    {(char *) "SetOrientation", (PyCFunction) _wrap_PyNs3CosineAntennaModel_SetOrientation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3CosineAntennaModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetOrientation", (PyCFunction) _wrap_PyNs3CosineAntennaModel_GetOrientation, METH_NOARGS, NULL },
    {(char *) "GetBeamwidth", (PyCFunction) _wrap_PyNs3CosineAntennaModel_GetBeamwidth, METH_NOARGS, NULL },
    {(char *) "SetBeamwidth", (PyCFunction) _wrap_PyNs3CosineAntennaModel_SetBeamwidth, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetGainDb", (PyCFunction) _wrap_PyNs3CosineAntennaModel_GetGainDb, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3CosineAntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3CosineAntennaModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3CosineAntennaModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3CosineAntennaModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3CosineAntennaModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3CosineAntennaModel__tp_clear(PyNs3CosineAntennaModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::CosineAntennaModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3CosineAntennaModel__tp_traverse(PyNs3CosineAntennaModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3CosineAntennaModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3CosineAntennaModel__tp_dealloc(PyNs3CosineAntennaModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3CosineAntennaModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3CosineAntennaModel__tp_richcompare (PyNs3CosineAntennaModel *PYBINDGEN_UNUSED(self), PyNs3CosineAntennaModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3CosineAntennaModel_Type)) {
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

PyTypeObject PyNs3CosineAntennaModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "antenna.CosineAntennaModel",            /* tp_name */
    sizeof(PyNs3CosineAntennaModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3CosineAntennaModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3CosineAntennaModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3CosineAntennaModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3CosineAntennaModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3CosineAntennaModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3CosineAntennaModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3CosineAntennaModel__tp_init,             /* tp_init */
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
PyNs3IsotropicAntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3IsotropicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3IsotropicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3IsotropicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3IsotropicAntennaModel__PythonHelper::_wrap_DoInitialize(PyNs3IsotropicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3IsotropicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3IsotropicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3IsotropicAntennaModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3IsotropicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3IsotropicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3IsotropicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3IsotropicAntennaModel__PythonHelper::_wrap_DoDispose(PyNs3IsotropicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3IsotropicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3IsotropicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3IsotropicAntennaModel__PythonHelper::GetGainDb(ns3::Angles a)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::IsotropicAntennaModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3Angles *py_Angles;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetGainDb"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::IsotropicAntennaModel::GetGainDb(a);
    }
    self_obj_before = reinterpret_cast< PyNs3IsotropicAntennaModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3IsotropicAntennaModel* >(m_pyself)->obj = (ns3::IsotropicAntennaModel*) this;
    py_Angles = PyObject_New(PyNs3Angles, &PyNs3Angles_Type);
    py_Angles->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Angles->obj = new ns3::Angles(a);
    PyNs3Angles_wrapper_registry[(void *) py_Angles->obj] = (PyObject *) py_Angles;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetGainDb", (char *) "N", py_Angles);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3IsotropicAntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::IsotropicAntennaModel::GetGainDb(a);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3IsotropicAntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::IsotropicAntennaModel::GetGainDb(a);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3IsotropicAntennaModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3IsotropicAntennaModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3IsotropicAntennaModel__PythonHelper::DoDispose()
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
PyNs3IsotropicAntennaModel__PythonHelper::DoInitialize()
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
PyNs3IsotropicAntennaModel__PythonHelper::NotifyNewAggregate()
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
PyNs3IsotropicAntennaModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3IsotropicAntennaModel__tp_init__0(PyNs3IsotropicAntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3IsotropicAntennaModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3IsotropicAntennaModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3IsotropicAntennaModel_Type)
    {
        self->obj = new PyNs3IsotropicAntennaModel__PythonHelper(*((PyNs3IsotropicAntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3IsotropicAntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::IsotropicAntennaModel(*((PyNs3IsotropicAntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3IsotropicAntennaModel__tp_init__1(PyNs3IsotropicAntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3IsotropicAntennaModel_Type)
    {
        self->obj = new PyNs3IsotropicAntennaModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3IsotropicAntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::IsotropicAntennaModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3IsotropicAntennaModel__tp_init(PyNs3IsotropicAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3IsotropicAntennaModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3IsotropicAntennaModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3IsotropicAntennaModel_GetGainDb(PyNs3IsotropicAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3Angles *a;
    PyNs3IsotropicAntennaModel__PythonHelper *helper_class = dynamic_cast<PyNs3IsotropicAntennaModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Angles_Type, &a)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->GetGainDb(*((PyNs3Angles *) a)->obj)) : (self->obj->ns3::IsotropicAntennaModel::GetGainDb(*((PyNs3Angles *) a)->obj));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3IsotropicAntennaModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::IsotropicAntennaModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3IsotropicAntennaModel__copy__(PyNs3IsotropicAntennaModel *self)
{

    PyNs3IsotropicAntennaModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3IsotropicAntennaModel, &PyNs3IsotropicAntennaModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::IsotropicAntennaModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3IsotropicAntennaModel_methods[] = {
    {(char *) "GetGainDb", (PyCFunction) _wrap_PyNs3IsotropicAntennaModel_GetGainDb, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3IsotropicAntennaModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3IsotropicAntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3IsotropicAntennaModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3IsotropicAntennaModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3IsotropicAntennaModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3IsotropicAntennaModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3IsotropicAntennaModel__tp_clear(PyNs3IsotropicAntennaModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::IsotropicAntennaModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3IsotropicAntennaModel__tp_traverse(PyNs3IsotropicAntennaModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3IsotropicAntennaModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3IsotropicAntennaModel__tp_dealloc(PyNs3IsotropicAntennaModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3IsotropicAntennaModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3IsotropicAntennaModel__tp_richcompare (PyNs3IsotropicAntennaModel *PYBINDGEN_UNUSED(self), PyNs3IsotropicAntennaModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3IsotropicAntennaModel_Type)) {
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

PyTypeObject PyNs3IsotropicAntennaModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "antenna.IsotropicAntennaModel",            /* tp_name */
    sizeof(PyNs3IsotropicAntennaModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3IsotropicAntennaModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3IsotropicAntennaModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3IsotropicAntennaModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3IsotropicAntennaModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3IsotropicAntennaModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3IsotropicAntennaModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3IsotropicAntennaModel__tp_init,             /* tp_init */
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
PyNs3ParabolicAntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ParabolicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3ParabolicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3ParabolicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3ParabolicAntennaModel__PythonHelper::_wrap_DoInitialize(PyNs3ParabolicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3ParabolicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3ParabolicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3ParabolicAntennaModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ParabolicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3ParabolicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3ParabolicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3ParabolicAntennaModel__PythonHelper::_wrap_DoDispose(PyNs3ParabolicAntennaModel *self)
{
    PyObject *py_retval;
    PyNs3ParabolicAntennaModel__PythonHelper *helper = dynamic_cast< PyNs3ParabolicAntennaModel__PythonHelper* >(self->obj);
    
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
PyNs3ParabolicAntennaModel__PythonHelper::GetGainDb(ns3::Angles a)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ParabolicAntennaModel *self_obj_before;
    PyObject *py_retval;
    double retval;
    PyNs3Angles *py_Angles;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetGainDb"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ParabolicAntennaModel::GetGainDb(a);
    }
    self_obj_before = reinterpret_cast< PyNs3ParabolicAntennaModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ParabolicAntennaModel* >(m_pyself)->obj = (ns3::ParabolicAntennaModel*) this;
    py_Angles = PyObject_New(PyNs3Angles, &PyNs3Angles_Type);
    py_Angles->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Angles->obj = new ns3::Angles(a);
    PyNs3Angles_wrapper_registry[(void *) py_Angles->obj] = (PyObject *) py_Angles;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetGainDb", (char *) "N", py_Angles);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ParabolicAntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ParabolicAntennaModel::GetGainDb(a);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ParabolicAntennaModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ParabolicAntennaModel::GetGainDb(a);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ParabolicAntennaModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ParabolicAntennaModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ParabolicAntennaModel__PythonHelper::DoDispose()
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
PyNs3ParabolicAntennaModel__PythonHelper::DoInitialize()
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
PyNs3ParabolicAntennaModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ParabolicAntennaModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ParabolicAntennaModel__tp_init__0(PyNs3ParabolicAntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ParabolicAntennaModel_Type)
    {
        self->obj = new PyNs3ParabolicAntennaModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ParabolicAntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ParabolicAntennaModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ParabolicAntennaModel__tp_init__1(PyNs3ParabolicAntennaModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ParabolicAntennaModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ParabolicAntennaModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ParabolicAntennaModel_Type)
    {
        self->obj = new PyNs3ParabolicAntennaModel__PythonHelper(*((PyNs3ParabolicAntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ParabolicAntennaModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ParabolicAntennaModel(*((PyNs3ParabolicAntennaModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ParabolicAntennaModel__tp_init(PyNs3ParabolicAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ParabolicAntennaModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ParabolicAntennaModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ParabolicAntennaModel_SetOrientation(PyNs3ParabolicAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double orientationDegrees;
    const char *keywords[] = {"orientationDegrees", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &orientationDegrees)) {
        return NULL;
    }
    self->obj->SetOrientation(orientationDegrees);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ParabolicAntennaModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ParabolicAntennaModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ParabolicAntennaModel_GetOrientation(PyNs3ParabolicAntennaModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetOrientation();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3ParabolicAntennaModel_GetBeamwidth(PyNs3ParabolicAntennaModel *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetBeamwidth();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3ParabolicAntennaModel_SetBeamwidth(PyNs3ParabolicAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double beamwidthDegrees;
    const char *keywords[] = {"beamwidthDegrees", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &beamwidthDegrees)) {
        return NULL;
    }
    self->obj->SetBeamwidth(beamwidthDegrees);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ParabolicAntennaModel_GetGainDb(PyNs3ParabolicAntennaModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3Angles *a;
    PyNs3ParabolicAntennaModel__PythonHelper *helper_class = dynamic_cast<PyNs3ParabolicAntennaModel__PythonHelper*> (self->obj);
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Angles_Type, &a)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->GetGainDb(*((PyNs3Angles *) a)->obj)) : (self->obj->ns3::ParabolicAntennaModel::GetGainDb(*((PyNs3Angles *) a)->obj));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3ParabolicAntennaModel__copy__(PyNs3ParabolicAntennaModel *self)
{

    PyNs3ParabolicAntennaModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3ParabolicAntennaModel, &PyNs3ParabolicAntennaModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ParabolicAntennaModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ParabolicAntennaModel_methods[] = {
    {(char *) "SetOrientation", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel_SetOrientation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetOrientation", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel_GetOrientation, METH_NOARGS, NULL },
    {(char *) "GetBeamwidth", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel_GetBeamwidth, METH_NOARGS, NULL },
    {(char *) "SetBeamwidth", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel_SetBeamwidth, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetGainDb", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel_GetGainDb, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ParabolicAntennaModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ParabolicAntennaModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ParabolicAntennaModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ParabolicAntennaModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ParabolicAntennaModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ParabolicAntennaModel__tp_clear(PyNs3ParabolicAntennaModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ParabolicAntennaModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ParabolicAntennaModel__tp_traverse(PyNs3ParabolicAntennaModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ParabolicAntennaModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ParabolicAntennaModel__tp_dealloc(PyNs3ParabolicAntennaModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ParabolicAntennaModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ParabolicAntennaModel__tp_richcompare (PyNs3ParabolicAntennaModel *PYBINDGEN_UNUSED(self), PyNs3ParabolicAntennaModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ParabolicAntennaModel_Type)) {
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

PyTypeObject PyNs3ParabolicAntennaModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "antenna.ParabolicAntennaModel",            /* tp_name */
    sizeof(PyNs3ParabolicAntennaModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ParabolicAntennaModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ParabolicAntennaModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ParabolicAntennaModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ParabolicAntennaModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ParabolicAntennaModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ParabolicAntennaModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ParabolicAntennaModel__tp_init,             /* tp_init */
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
static struct PyModuleDef antenna_moduledef = {
    PyModuleDef_HEAD_INIT,
    "antenna",
    NULL,
    -1,
    antenna_functions,
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


MOD_INIT(antenna)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&antenna_moduledef);
    #else
    m = Py_InitModule3((char *) "antenna", antenna_functions, NULL);
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
    PyModule_AddObject(m, (char *) "_PyNs3Angles_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Angles_wrapper_registry, NULL));
    /* Register the 'ns3::Angles' class */
    if (PyType_Ready(&PyNs3Angles_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Angles", (PyObject *) &PyNs3Angles_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::AntennaModel), &PyNs3AntennaModel_Type);
    /* Register the 'ns3::AntennaModel' class */
    PyNs3AntennaModel_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3AntennaModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "AntennaModel", (PyObject *) &PyNs3AntennaModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::CosineAntennaModel), &PyNs3CosineAntennaModel_Type);
    /* Register the 'ns3::CosineAntennaModel' class */
    PyNs3CosineAntennaModel_Type.tp_base = &PyNs3AntennaModel_Type;
    if (PyType_Ready(&PyNs3CosineAntennaModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "CosineAntennaModel", (PyObject *) &PyNs3CosineAntennaModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::IsotropicAntennaModel), &PyNs3IsotropicAntennaModel_Type);
    /* Register the 'ns3::IsotropicAntennaModel' class */
    PyNs3IsotropicAntennaModel_Type.tp_base = &PyNs3AntennaModel_Type;
    if (PyType_Ready(&PyNs3IsotropicAntennaModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "IsotropicAntennaModel", (PyObject *) &PyNs3IsotropicAntennaModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ParabolicAntennaModel), &PyNs3ParabolicAntennaModel_Type);
    /* Register the 'ns3::ParabolicAntennaModel' class */
    PyNs3ParabolicAntennaModel_Type.tp_base = &PyNs3AntennaModel_Type;
    if (PyType_Ready(&PyNs3ParabolicAntennaModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ParabolicAntennaModel", (PyObject *) &PyNs3ParabolicAntennaModel_Type);
    PyModule_AddObject(m, (char *) "Vector", (PyObject *) &PyNs3Vector3D_Type);
    PyModule_AddObject(m, (char *) "VectorValue", (PyObject *) &PyNs3Vector3DValue_Type);
    PyModule_AddObject(m, (char *) "VectorChecker", (PyObject *) &PyNs3Vector3DChecker_Type);
    submodule = initantenna_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initantenna_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    return MOD_RETURN(m);
}
