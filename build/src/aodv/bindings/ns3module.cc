#include "ns3module.h"
static PyMethodDef aodv_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef aodv_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "aodv.FatalImpl",
    NULL,
    -1,
    aodv_FatalImpl_functions,
};
#endif

static PyObject *
initaodv_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&aodv_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "aodv.FatalImpl", aodv_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef aodv_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef aodv_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "aodv.Hash.Function",
    NULL,
    -1,
    aodv_Hash_Function_functions,
};
#endif

static PyObject *
initaodv_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&aodv_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "aodv.Hash.Function", aodv_Hash_Function_functions, NULL);
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
static PyMethodDef aodv_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef aodv_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "aodv.Hash",
    NULL,
    -1,
    aodv_Hash_functions,
};
#endif

static PyObject *
initaodv_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&aodv_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "aodv.Hash", aodv_Hash_functions, NULL);
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
    submodule = initaodv_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef aodv_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef aodv_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "aodv.TracedValueCallback",
    NULL,
    -1,
    aodv_TracedValueCallback_functions,
};
#endif

static PyObject *
initaodv_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&aodv_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "aodv.TracedValueCallback", aodv_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef aodv_aodv_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3AodvDuplicatePacketDetection_wrapper_registry;


static int
_wrap_PyNs3AodvDuplicatePacketDetection__tp_init__0(PyNs3AodvDuplicatePacketDetection *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvDuplicatePacketDetection *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvDuplicatePacketDetection_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::DuplicatePacketDetection(*((PyNs3AodvDuplicatePacketDetection *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvDuplicatePacketDetection__tp_init__1(PyNs3AodvDuplicatePacketDetection *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Time *lifetime;
    const char *keywords[] = {"lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &lifetime)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::DuplicatePacketDetection(*((PyNs3Time *) lifetime)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvDuplicatePacketDetection__tp_init(PyNs3AodvDuplicatePacketDetection *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvDuplicatePacketDetection__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvDuplicatePacketDetection__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvDuplicatePacketDetection_IsDuplicate(PyNs3AodvDuplicatePacketDetection *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    PyNs3Ipv4Header *header;
    const char *keywords[] = {"p", "header", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Packet_Type, &p, &PyNs3Ipv4Header_Type, &header)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    retval = self->obj->IsDuplicate(ns3::Ptr< ns3::Packet  > (p_ptr), *((PyNs3Ipv4Header *) header)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvDuplicatePacketDetection_SetLifetime(PyNs3AodvDuplicatePacketDetection *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *lifetime;
    const char *keywords[] = {"lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &lifetime)) {
        return NULL;
    }
    self->obj->SetLifetime(*((PyNs3Time *) lifetime)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvDuplicatePacketDetection_GetLifetime(PyNs3AodvDuplicatePacketDetection *self)
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


static PyObject*
_wrap_PyNs3AodvDuplicatePacketDetection__copy__(PyNs3AodvDuplicatePacketDetection *self)
{

    PyNs3AodvDuplicatePacketDetection *py_copy;
    py_copy = PyObject_New(PyNs3AodvDuplicatePacketDetection, &PyNs3AodvDuplicatePacketDetection_Type);
    py_copy->obj = new ns3::aodv::DuplicatePacketDetection(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvDuplicatePacketDetection_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvDuplicatePacketDetection_methods[] = {
    {(char *) "IsDuplicate", (PyCFunction) _wrap_PyNs3AodvDuplicatePacketDetection_IsDuplicate, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLifetime", (PyCFunction) _wrap_PyNs3AodvDuplicatePacketDetection_SetLifetime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLifetime", (PyCFunction) _wrap_PyNs3AodvDuplicatePacketDetection_GetLifetime, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvDuplicatePacketDetection__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvDuplicatePacketDetection__tp_dealloc(PyNs3AodvDuplicatePacketDetection *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvDuplicatePacketDetection_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvDuplicatePacketDetection_wrapper_registry.end()) {
        PyNs3AodvDuplicatePacketDetection_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::DuplicatePacketDetection *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvDuplicatePacketDetection__tp_richcompare (PyNs3AodvDuplicatePacketDetection *PYBINDGEN_UNUSED(self), PyNs3AodvDuplicatePacketDetection *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvDuplicatePacketDetection_Type)) {
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

PyTypeObject PyNs3AodvDuplicatePacketDetection_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.DuplicatePacketDetection",            /* tp_name */
    sizeof(PyNs3AodvDuplicatePacketDetection),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvDuplicatePacketDetection__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvDuplicatePacketDetection__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvDuplicatePacketDetection_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvDuplicatePacketDetection__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvIdCache_wrapper_registry;


static int
_wrap_PyNs3AodvIdCache__tp_init__0(PyNs3AodvIdCache *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvIdCache *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvIdCache_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::IdCache(*((PyNs3AodvIdCache *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvIdCache__tp_init__1(PyNs3AodvIdCache *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Time *lifetime;
    const char *keywords[] = {"lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &lifetime)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::IdCache(*((PyNs3Time *) lifetime)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvIdCache__tp_init(PyNs3AodvIdCache *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvIdCache__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvIdCache__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvIdCache_GetSize(PyNs3AodvIdCache *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvIdCache_IsDuplicate(PyNs3AodvIdCache *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *addr;
    unsigned int id;
    const char *keywords[] = {"addr", "id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &addr, &id)) {
        return NULL;
    }
    retval = self->obj->IsDuplicate(*((PyNs3Ipv4Address *) addr)->obj, id);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvIdCache_Purge(PyNs3AodvIdCache *self)
{
    PyObject *py_retval;
    
    self->obj->Purge();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvIdCache_SetLifetime(PyNs3AodvIdCache *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *lifetime;
    const char *keywords[] = {"lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &lifetime)) {
        return NULL;
    }
    self->obj->SetLifetime(*((PyNs3Time *) lifetime)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvIdCache_GetLifeTime(PyNs3AodvIdCache *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetLifeTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvIdCache__copy__(PyNs3AodvIdCache *self)
{

    PyNs3AodvIdCache *py_copy;
    py_copy = PyObject_New(PyNs3AodvIdCache, &PyNs3AodvIdCache_Type);
    py_copy->obj = new ns3::aodv::IdCache(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvIdCache_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvIdCache_methods[] = {
    {(char *) "GetSize", (PyCFunction) _wrap_PyNs3AodvIdCache_GetSize, METH_NOARGS, NULL },
    {(char *) "IsDuplicate", (PyCFunction) _wrap_PyNs3AodvIdCache_IsDuplicate, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Purge", (PyCFunction) _wrap_PyNs3AodvIdCache_Purge, METH_NOARGS, NULL },
    {(char *) "SetLifetime", (PyCFunction) _wrap_PyNs3AodvIdCache_SetLifetime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLifeTime", (PyCFunction) _wrap_PyNs3AodvIdCache_GetLifeTime, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvIdCache__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvIdCache__tp_dealloc(PyNs3AodvIdCache *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvIdCache_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvIdCache_wrapper_registry.end()) {
        PyNs3AodvIdCache_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::IdCache *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvIdCache__tp_richcompare (PyNs3AodvIdCache *PYBINDGEN_UNUSED(self), PyNs3AodvIdCache *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvIdCache_Type)) {
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

PyTypeObject PyNs3AodvIdCache_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.IdCache",            /* tp_name */
    sizeof(PyNs3AodvIdCache),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvIdCache__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvIdCache__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvIdCache_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvIdCache__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvNeighbors_wrapper_registry;


static int
_wrap_PyNs3AodvNeighbors__tp_init__0(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvNeighbors *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvNeighbors_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::Neighbors(*((PyNs3AodvNeighbors *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvNeighbors__tp_init__1(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Time *delay;
    const char *keywords[] = {"delay", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &delay)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::Neighbors(*((PyNs3Time *) delay)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvNeighbors__tp_init(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvNeighbors__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvNeighbors__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvNeighbors_AddArpCache(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3ArpCache *arg0;
    ns3::ArpCache *arg0_ptr;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ArpCache_Type, &arg0)) {
        return NULL;
    }
    arg0_ptr = (arg0 ? arg0->obj : NULL);
    self->obj->AddArpCache(ns3::Ptr< ns3::ArpCache  > (arg0_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_Clear(PyNs3AodvNeighbors *self)
{
    PyObject *py_retval;
    
    self->obj->Clear();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_IsNeighbor(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *addr;
    const char *keywords[] = {"addr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr)) {
        return NULL;
    }
    retval = self->obj->IsNeighbor(*((PyNs3Ipv4Address *) addr)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_Update(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *addr;
    PyNs3Time *expire;
    const char *keywords[] = {"addr", "expire", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr, &PyNs3Time_Type, &expire)) {
        return NULL;
    }
    self->obj->Update(*((PyNs3Ipv4Address *) addr)->obj, *((PyNs3Time *) expire)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_DelArpCache(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3ArpCache *arg0;
    ns3::ArpCache *arg0_ptr;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ArpCache_Type, &arg0)) {
        return NULL;
    }
    arg0_ptr = (arg0 ? arg0->obj : NULL);
    self->obj->DelArpCache(ns3::Ptr< ns3::ArpCache  > (arg0_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_Purge(PyNs3AodvNeighbors *self)
{
    PyObject *py_retval;
    
    self->obj->Purge();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_SetCallback(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *cb;
    ns3::Ptr<PythonCallbackImpl3> cb_cb_impl;
    const char *keywords[] = {"cb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &cb)) {
        return NULL;
    }
    if (!PyCallable_Check(cb)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'cb' must be callbale");
        return NULL;
    }
    cb_cb_impl = ns3::Create<PythonCallbackImpl3> (cb);
    self->obj->SetCallback(ns3::Callback<void, ns3::Ipv4Address, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (cb_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_ScheduleTimer(PyNs3AodvNeighbors *self)
{
    PyObject *py_retval;
    
    self->obj->ScheduleTimer();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvNeighbors_GetExpireTime(PyNs3AodvNeighbors *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *addr;
    const char *keywords[] = {"addr", NULL};
    PyNs3Time *py_Time;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &addr)) {
        return NULL;
    }
    ns3::Time retval = self->obj->GetExpireTime(*((PyNs3Ipv4Address *) addr)->obj);
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvNeighbors__copy__(PyNs3AodvNeighbors *self)
{

    PyNs3AodvNeighbors *py_copy;
    py_copy = PyObject_New(PyNs3AodvNeighbors, &PyNs3AodvNeighbors_Type);
    py_copy->obj = new ns3::aodv::Neighbors(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvNeighbors_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvNeighbors_methods[] = {
    {(char *) "AddArpCache", (PyCFunction) _wrap_PyNs3AodvNeighbors_AddArpCache, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Clear", (PyCFunction) _wrap_PyNs3AodvNeighbors_Clear, METH_NOARGS, NULL },
    {(char *) "IsNeighbor", (PyCFunction) _wrap_PyNs3AodvNeighbors_IsNeighbor, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Update", (PyCFunction) _wrap_PyNs3AodvNeighbors_Update, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DelArpCache", (PyCFunction) _wrap_PyNs3AodvNeighbors_DelArpCache, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Purge", (PyCFunction) _wrap_PyNs3AodvNeighbors_Purge, METH_NOARGS, NULL },
    {(char *) "SetCallback", (PyCFunction) _wrap_PyNs3AodvNeighbors_SetCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ScheduleTimer", (PyCFunction) _wrap_PyNs3AodvNeighbors_ScheduleTimer, METH_NOARGS, NULL },
    {(char *) "GetExpireTime", (PyCFunction) _wrap_PyNs3AodvNeighbors_GetExpireTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvNeighbors__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvNeighbors__tp_dealloc(PyNs3AodvNeighbors *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvNeighbors_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvNeighbors_wrapper_registry.end()) {
        PyNs3AodvNeighbors_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::Neighbors *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvNeighbors__tp_richcompare (PyNs3AodvNeighbors *PYBINDGEN_UNUSED(self), PyNs3AodvNeighbors *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvNeighbors_Type)) {
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

PyTypeObject PyNs3AodvNeighbors_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.Neighbors",            /* tp_name */
    sizeof(PyNs3AodvNeighbors),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvNeighbors__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvNeighbors__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvNeighbors_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvNeighbors__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvNeighborsNeighbor_wrapper_registry;
static PyObject* _wrap_PyNs3AodvNeighborsNeighbor__get_close(PyNs3AodvNeighborsNeighbor *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(self->obj->close));
    return py_retval;
}
static int _wrap_PyNs3AodvNeighborsNeighbor__set_close(PyNs3AodvNeighborsNeighbor *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->close = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3AodvNeighborsNeighbor__get_m_expireTime(PyNs3AodvNeighborsNeighbor *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->m_expireTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3AodvNeighborsNeighbor__set_m_expireTime(PyNs3AodvNeighborsNeighbor *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_expireTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3AodvNeighborsNeighbor__get_m_hardwareAddress(PyNs3AodvNeighborsNeighbor *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac48Address *py_Mac48Address;
    
    py_Mac48Address = PyObject_New(PyNs3Mac48Address, &PyNs3Mac48Address_Type);
    py_Mac48Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mac48Address->obj = new ns3::Mac48Address(self->obj->m_hardwareAddress);
    PyNs3Mac48Address_wrapper_registry[(void *) py_Mac48Address->obj] = (PyObject *) py_Mac48Address;
    py_retval = Py_BuildValue((char *) "N", py_Mac48Address);
    return py_retval;
}
static int _wrap_PyNs3AodvNeighborsNeighbor__set_m_hardwareAddress(PyNs3AodvNeighborsNeighbor *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Mac48Address *tmp_Mac48Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Mac48Address_Type, &tmp_Mac48Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_hardwareAddress = *tmp_Mac48Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3AodvNeighborsNeighbor__get_m_neighborAddress(PyNs3AodvNeighborsNeighbor *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->m_neighborAddress);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3AodvNeighborsNeighbor__set_m_neighborAddress(PyNs3AodvNeighborsNeighbor *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_neighborAddress = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3AodvNeighborsNeighbor__getsets[] = {
    {
        (char*) "close", /* attribute name */
        (getter) _wrap_PyNs3AodvNeighborsNeighbor__get_close, /* C function to get the attribute */
        (setter) _wrap_PyNs3AodvNeighborsNeighbor__set_close, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_neighborAddress", /* attribute name */
        (getter) _wrap_PyNs3AodvNeighborsNeighbor__get_m_neighborAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3AodvNeighborsNeighbor__set_m_neighborAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_expireTime", /* attribute name */
        (getter) _wrap_PyNs3AodvNeighborsNeighbor__get_m_expireTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3AodvNeighborsNeighbor__set_m_expireTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "m_hardwareAddress", /* attribute name */
        (getter) _wrap_PyNs3AodvNeighborsNeighbor__get_m_hardwareAddress, /* C function to get the attribute */
        (setter) _wrap_PyNs3AodvNeighborsNeighbor__set_m_hardwareAddress, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3AodvNeighborsNeighbor__tp_init__0(PyNs3AodvNeighborsNeighbor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvNeighborsNeighbor *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvNeighborsNeighbor_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::Neighbors::Neighbor(*((PyNs3AodvNeighborsNeighbor *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvNeighborsNeighbor__tp_init__1(PyNs3AodvNeighborsNeighbor *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ipv4Address *ip;
    PyNs3Mac48Address *mac;
    PyNs3Time *t;
    const char *keywords[] = {"ip", "mac", "t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &ip, &PyNs3Mac48Address_Type, &mac, &PyNs3Time_Type, &t)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::Neighbors::Neighbor(*((PyNs3Ipv4Address *) ip)->obj, *((PyNs3Mac48Address *) mac)->obj, *((PyNs3Time *) t)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvNeighborsNeighbor__tp_init(PyNs3AodvNeighborsNeighbor *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvNeighborsNeighbor__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvNeighborsNeighbor__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvNeighborsNeighbor__copy__(PyNs3AodvNeighborsNeighbor *self)
{

    PyNs3AodvNeighborsNeighbor *py_copy;
    py_copy = PyObject_New(PyNs3AodvNeighborsNeighbor, &PyNs3AodvNeighborsNeighbor_Type);
    py_copy->obj = new ns3::aodv::Neighbors::Neighbor(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvNeighborsNeighbor_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvNeighborsNeighbor_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvNeighborsNeighbor__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvNeighborsNeighbor__tp_dealloc(PyNs3AodvNeighborsNeighbor *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvNeighborsNeighbor_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvNeighborsNeighbor_wrapper_registry.end()) {
        PyNs3AodvNeighborsNeighbor_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::Neighbors::Neighbor *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvNeighborsNeighbor__tp_richcompare (PyNs3AodvNeighborsNeighbor *PYBINDGEN_UNUSED(self), PyNs3AodvNeighborsNeighbor *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvNeighborsNeighbor_Type)) {
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

PyTypeObject PyNs3AodvNeighborsNeighbor_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.Neighbors.Neighbor",            /* tp_name */
    sizeof(PyNs3AodvNeighborsNeighbor),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvNeighborsNeighbor__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvNeighborsNeighbor__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvNeighborsNeighbor_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3AodvNeighborsNeighbor__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvNeighborsNeighbor__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvQueueEntry_wrapper_registry;


static int
_wrap_PyNs3AodvQueueEntry__tp_init__0(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvQueueEntry *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvQueueEntry_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::QueueEntry(*((PyNs3AodvQueueEntry *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvQueueEntry__tp_init__1(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Packet *pa = NULL;
    ns3::Packet *pa_ptr;
    PyNs3Ipv4Header *h = NULL;
    PyObject *ucb = NULL;
    ns3::Callback<void, ns3::Ptr<ns3::Ipv4Route>, ns3::Ptr<ns3::Packet const>, ns3::Ipv4Header const&, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> ucb_value = ns3::Callback<void, ns3::Ptr<ns3::Ipv4Route>, ns3::Ptr<const ns3::Packet>, const ns3::Ipv4Header&, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty>();
    PyObject *ecb = NULL;
    ns3::Callback<void, ns3::Ptr<ns3::Packet const>, ns3::Ipv4Header const&, ns3::Socket::SocketErrno, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> ecb_value = ns3::Callback<void, ns3::Ptr<const ns3::Packet>, const ns3::Ipv4Header&, ns3::Socket::SocketErrno, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty>();
    PyNs3Time *exp = NULL;
    const char *keywords[] = {"pa", "h", "ucb", "ecb", "exp", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O!O!OOO!", (char **) keywords, &PyNs3Packet_Type, &pa, &PyNs3Ipv4Header_Type, &h, &ucb, &ecb, &PyNs3Time_Type, &exp)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    pa_ptr = (pa ? pa->obj : NULL);
    if (ucb) {
        if (!PyCallable_Check(ucb)) {
            PyErr_SetString(PyExc_TypeError, "parameter 'ucb' must be callbale");
            {
                PyObject *exc_type, *traceback;
                PyErr_Fetch(&exc_type, return_exception, &traceback);
                Py_XDECREF(exc_type);
                Py_XDECREF(traceback);
            }
            return -1;
        }
        ucb_value = ns3::Callback<void, ns3::Ptr<ns3::Ipv4Route>, ns3::Ptr<ns3::Packet const>, ns3::Ipv4Header const&, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (ns3::Create<PythonCallbackImpl1> (ucb));
    }
    if (ecb) {
        if (!PyCallable_Check(ecb)) {
            PyErr_SetString(PyExc_TypeError, "parameter 'ecb' must be callbale");
            {
                PyObject *exc_type, *traceback;
                PyErr_Fetch(&exc_type, return_exception, &traceback);
                Py_XDECREF(exc_type);
                Py_XDECREF(traceback);
            }
            return -1;
        }
        ecb_value = ns3::Callback<void, ns3::Ptr<ns3::Packet const>, ns3::Ipv4Header const&, ns3::Socket::SocketErrno, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (ns3::Create<PythonCallbackImpl0> (ecb));
    }
    self->obj = new ns3::aodv::QueueEntry(ns3::Ptr< ns3::Packet  > (pa_ptr), (h ? (*((PyNs3Ipv4Header *) h)->obj) : ns3::Ipv4Header()), ucb_value, ecb_value, (exp ? (*((PyNs3Time *) exp)->obj) : ns3::Simulator::Now( )));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvQueueEntry__tp_init(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvQueueEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvQueueEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvQueueEntry_SetPacket(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    const char *keywords[] = {"p", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Packet_Type, &p)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    self->obj->SetPacket(ns3::Ptr< ns3::Packet  > (p_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_SetErrorCallback(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *ecb;
    ns3::Ptr<PythonCallbackImpl0> ecb_cb_impl;
    const char *keywords[] = {"ecb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &ecb)) {
        return NULL;
    }
    if (!PyCallable_Check(ecb)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'ecb' must be callbale");
        return NULL;
    }
    ecb_cb_impl = ns3::Create<PythonCallbackImpl0> (ecb);
    self->obj->SetErrorCallback(ns3::Callback<void, ns3::Ptr<ns3::Packet const>, ns3::Ipv4Header const&, ns3::Socket::SocketErrno, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (ecb_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_SetIpv4Header(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Header *h;
    const char *keywords[] = {"h", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Header_Type, &h)) {
        return NULL;
    }
    self->obj->SetIpv4Header(*((PyNs3Ipv4Header *) h)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_GetIpv4Header(PyNs3AodvQueueEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Header *py_Ipv4Header;
    
    ns3::Ipv4Header retval = self->obj->GetIpv4Header();
    py_Ipv4Header = PyObject_GC_New(PyNs3Ipv4Header, &PyNs3Ipv4Header_Type);
    py_Ipv4Header->inst_dict = NULL;
    py_Ipv4Header->inst_dict = NULL;
    py_Ipv4Header->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Header->obj = new ns3::Ipv4Header(retval);
    PyNs3ObjectBase_wrapper_registry[(void *) py_Ipv4Header->obj] = (PyObject *) py_Ipv4Header;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Header);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_GetPacket(PyNs3AodvQueueEntry *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Packet const > retval;
    PyNs3Packet *py_Packet;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetPacket();
    if (!(const_cast<ns3::Packet *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Packet *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Packet = NULL;
    } else {
        py_Packet = (PyNs3Packet *) wrapper_lookup_iter->second;
        Py_INCREF(py_Packet);
    }
    
    if (py_Packet == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Packet *> (ns3::PeekPointer (retval)))), &PyNs3Packet_Type);
        py_Packet = PyObject_New(PyNs3Packet, wrapper_type);
    
        py_Packet->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Packet *> (ns3::PeekPointer (retval))->Ref();
        py_Packet->obj = const_cast<ns3::Packet *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_Packet->obj] = (PyObject *) py_Packet;
    }
    py_retval = Py_BuildValue((char *) "N", py_Packet);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_SetUnicastForwardCallback(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyObject *ucb;
    ns3::Ptr<PythonCallbackImpl1> ucb_cb_impl;
    const char *keywords[] = {"ucb", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &ucb)) {
        return NULL;
    }
    if (!PyCallable_Check(ucb)) {
        PyErr_SetString(PyExc_TypeError, "parameter 'ucb' must be callbale");
        return NULL;
    }
    ucb_cb_impl = ns3::Create<PythonCallbackImpl1> (ucb);
    self->obj->SetUnicastForwardCallback(ns3::Callback<void, ns3::Ptr<ns3::Ipv4Route>, ns3::Ptr<ns3::Packet const>, ns3::Ipv4Header const&, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty, ns3::empty> (ucb_cb_impl));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_SetExpireTime(PyNs3AodvQueueEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *exp;
    const char *keywords[] = {"exp", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &exp)) {
        return NULL;
    }
    self->obj->SetExpireTime(*((PyNs3Time *) exp)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvQueueEntry_GetExpireTime(PyNs3AodvQueueEntry *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetExpireTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvQueueEntry__copy__(PyNs3AodvQueueEntry *self)
{

    PyNs3AodvQueueEntry *py_copy;
    py_copy = PyObject_New(PyNs3AodvQueueEntry, &PyNs3AodvQueueEntry_Type);
    py_copy->obj = new ns3::aodv::QueueEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvQueueEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvQueueEntry_methods[] = {
    {(char *) "SetPacket", (PyCFunction) _wrap_PyNs3AodvQueueEntry_SetPacket, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetErrorCallback", (PyCFunction) _wrap_PyNs3AodvQueueEntry_SetErrorCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv4Header", (PyCFunction) _wrap_PyNs3AodvQueueEntry_SetIpv4Header, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetIpv4Header", (PyCFunction) _wrap_PyNs3AodvQueueEntry_GetIpv4Header, METH_NOARGS, NULL },
    {(char *) "GetPacket", (PyCFunction) _wrap_PyNs3AodvQueueEntry_GetPacket, METH_NOARGS, NULL },
    {(char *) "SetUnicastForwardCallback", (PyCFunction) _wrap_PyNs3AodvQueueEntry_SetUnicastForwardCallback, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetExpireTime", (PyCFunction) _wrap_PyNs3AodvQueueEntry_SetExpireTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetExpireTime", (PyCFunction) _wrap_PyNs3AodvQueueEntry_GetExpireTime, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvQueueEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvQueueEntry__tp_dealloc(PyNs3AodvQueueEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvQueueEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvQueueEntry_wrapper_registry.end()) {
        PyNs3AodvQueueEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::QueueEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvQueueEntry__tp_richcompare (PyNs3AodvQueueEntry *PYBINDGEN_UNUSED(self), PyNs3AodvQueueEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvQueueEntry_Type)) {
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

PyTypeObject PyNs3AodvQueueEntry_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.QueueEntry",            /* tp_name */
    sizeof(PyNs3AodvQueueEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvQueueEntry__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvQueueEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvQueueEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvQueueEntry__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvRequestQueue_wrapper_registry;


static int
_wrap_PyNs3AodvRequestQueue__tp_init__0(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRequestQueue *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRequestQueue_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RequestQueue(*((PyNs3AodvRequestQueue *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRequestQueue__tp_init__1(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    unsigned int maxLen;
    PyNs3Time *routeToQueueTimeout;
    const char *keywords[] = {"maxLen", "routeToQueueTimeout", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &maxLen, &PyNs3Time_Type, &routeToQueueTimeout)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RequestQueue(maxLen, *((PyNs3Time *) routeToQueueTimeout)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRequestQueue__tp_init(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRequestQueue__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRequestQueue__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRequestQueue_GetMaxQueueLen(PyNs3AodvRequestQueue *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetMaxQueueLen();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_Dequeue(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    PyNs3AodvQueueEntry *entry;
    const char *keywords[] = {"dst", "entry", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &dst, &PyNs3AodvQueueEntry_Type, &entry)) {
        return NULL;
    }
    retval = self->obj->Dequeue(*((PyNs3Ipv4Address *) dst)->obj, *((PyNs3AodvQueueEntry *) entry)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_SetMaxQueueLen(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int len;
    const char *keywords[] = {"len", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &len)) {
        return NULL;
    }
    self->obj->SetMaxQueueLen(len);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_DropPacketWithDst(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *dst;
    const char *keywords[] = {"dst", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &dst)) {
        return NULL;
    }
    self->obj->DropPacketWithDst(*((PyNs3Ipv4Address *) dst)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_GetSize(PyNs3AodvRequestQueue *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_Enqueue(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3AodvQueueEntry *entry;
    const char *keywords[] = {"entry", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvQueueEntry_Type, &entry)) {
        return NULL;
    }
    retval = self->obj->Enqueue(*((PyNs3AodvQueueEntry *) entry)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_GetQueueTimeout(PyNs3AodvRequestQueue *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetQueueTimeout();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_SetQueueTimeout(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        return NULL;
    }
    self->obj->SetQueueTimeout(*((PyNs3Time *) t)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRequestQueue_Find(PyNs3AodvRequestQueue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    const char *keywords[] = {"dst", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &dst)) {
        return NULL;
    }
    retval = self->obj->Find(*((PyNs3Ipv4Address *) dst)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRequestQueue__copy__(PyNs3AodvRequestQueue *self)
{

    PyNs3AodvRequestQueue *py_copy;
    py_copy = PyObject_New(PyNs3AodvRequestQueue, &PyNs3AodvRequestQueue_Type);
    py_copy->obj = new ns3::aodv::RequestQueue(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvRequestQueue_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRequestQueue_methods[] = {
    {(char *) "GetMaxQueueLen", (PyCFunction) _wrap_PyNs3AodvRequestQueue_GetMaxQueueLen, METH_NOARGS, NULL },
    {(char *) "Dequeue", (PyCFunction) _wrap_PyNs3AodvRequestQueue_Dequeue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMaxQueueLen", (PyCFunction) _wrap_PyNs3AodvRequestQueue_SetMaxQueueLen, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DropPacketWithDst", (PyCFunction) _wrap_PyNs3AodvRequestQueue_DropPacketWithDst, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetSize", (PyCFunction) _wrap_PyNs3AodvRequestQueue_GetSize, METH_NOARGS, NULL },
    {(char *) "Enqueue", (PyCFunction) _wrap_PyNs3AodvRequestQueue_Enqueue, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetQueueTimeout", (PyCFunction) _wrap_PyNs3AodvRequestQueue_GetQueueTimeout, METH_NOARGS, NULL },
    {(char *) "SetQueueTimeout", (PyCFunction) _wrap_PyNs3AodvRequestQueue_SetQueueTimeout, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Find", (PyCFunction) _wrap_PyNs3AodvRequestQueue_Find, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRequestQueue__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvRequestQueue__tp_dealloc(PyNs3AodvRequestQueue *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvRequestQueue_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvRequestQueue_wrapper_registry.end()) {
        PyNs3AodvRequestQueue_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::RequestQueue *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvRequestQueue__tp_richcompare (PyNs3AodvRequestQueue *PYBINDGEN_UNUSED(self), PyNs3AodvRequestQueue *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRequestQueue_Type)) {
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

PyTypeObject PyNs3AodvRequestQueue_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RequestQueue",            /* tp_name */
    sizeof(PyNs3AodvRequestQueue),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRequestQueue__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvRequestQueue__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRequestQueue_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRequestQueue__tp_init,             /* tp_init */
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
_wrap_PyNs3AodvRerrHeader__tp_init__0(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRerrHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRerrHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RerrHeader(*((PyNs3AodvRerrHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRerrHeader__tp_init__1(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::aodv::RerrHeader();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRerrHeader__tp_init(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRerrHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRerrHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRerrHeader_GetDestCount(PyNs3AodvRerrHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetDestCount();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_GetNoDelete(PyNs3AodvRerrHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetNoDelete();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_Deserialize(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRerrHeader_Clear(PyNs3AodvRerrHeader *self)
{
    PyObject *py_retval;
    
    self->obj->Clear();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_Serialize(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3BufferIterator *i;
    const char *keywords[] = {"i", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BufferIterator_Type, &i)) {
        return NULL;
    }
    self->obj->Serialize(*((PyNs3BufferIterator *) i)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_GetInstanceTypeId(PyNs3AodvRerrHeader *self)
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
_wrap_PyNs3AodvRerrHeader_GetSerializedSize(PyNs3AodvRerrHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_AddUnDestination(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    unsigned int seqNo;
    const char *keywords[] = {"dst", "seqNo", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Ipv4Address_Type, &dst, &seqNo)) {
        return NULL;
    }
    retval = self->obj->AddUnDestination(*((PyNs3Ipv4Address *) dst)->obj, seqNo);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::aodv::RerrHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRerrHeader_SetNoDelete(PyNs3AodvRerrHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetNoDelete(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRerrHeader__copy__(PyNs3AodvRerrHeader *self)
{

    PyNs3AodvRerrHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvRerrHeader, &PyNs3AodvRerrHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::aodv::RerrHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRerrHeader_methods[] = {
    {(char *) "GetDestCount", (PyCFunction) _wrap_PyNs3AodvRerrHeader_GetDestCount, METH_NOARGS, NULL },
    {(char *) "GetNoDelete", (PyCFunction) _wrap_PyNs3AodvRerrHeader_GetNoDelete, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3AodvRerrHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Clear", (PyCFunction) _wrap_PyNs3AodvRerrHeader_Clear, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3AodvRerrHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3AodvRerrHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3AodvRerrHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "AddUnDestination", (PyCFunction) _wrap_PyNs3AodvRerrHeader_AddUnDestination, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AodvRerrHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetNoDelete", (PyCFunction) _wrap_PyNs3AodvRerrHeader_SetNoDelete, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRerrHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvRerrHeader__tp_clear(PyNs3AodvRerrHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::aodv::RerrHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3AodvRerrHeader__tp_traverse(PyNs3AodvRerrHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvRerrHeader__tp_dealloc(PyNs3AodvRerrHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvRerrHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3AodvRerrHeader__tp_str(PyNs3AodvRerrHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3AodvRerrHeader__tp_richcompare (PyNs3AodvRerrHeader *PYBINDGEN_UNUSED(self), PyNs3AodvRerrHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRerrHeader_Type)) {
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

PyTypeObject PyNs3AodvRerrHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RerrHeader",            /* tp_name */
    sizeof(PyNs3AodvRerrHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRerrHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3AodvRerrHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3AodvRerrHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvRerrHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvRerrHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRerrHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvRerrHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRerrHeader__tp_init,             /* tp_init */
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



static PyObject* _wrap_PyNs3AodvRoutingProtocol__get_AODV_PORT(PyObject * PYBINDGEN_UNUSED(obj), void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(ns3::aodv::RoutingProtocol::AODV_PORT));
    return py_retval;
}
static PyGetSetDef Ns3AodvRoutingProtocolMeta__getsets[] = {
    {
        (char*) "AODV_PORT", /* attribute name */
        (getter) _wrap_PyNs3AodvRoutingProtocol__get_AODV_PORT, /* C function to get the attribute */
        (setter) NULL, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject PyNs3AodvRoutingProtocolMeta_Type = {
        PyVarObject_HEAD_INIT(NULL, 0)
	(char *) "Ns3AodvRoutingProtocolMeta",		        /* tp_name */
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
	Ns3AodvRoutingProtocolMeta__getsets,				/* tp_getset */
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
_wrap_PyNs3AodvRoutingProtocol__tp_init__0(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRoutingProtocol *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRoutingProtocol_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RoutingProtocol(*((PyNs3AodvRoutingProtocol *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRoutingProtocol__tp_init__1(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::aodv::RoutingProtocol();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRoutingProtocol__tp_init(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRoutingProtocol__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRoutingProtocol__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRoutingProtocol_NotifyAddAddress(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv4InterfaceAddress *address;
    const char *keywords[] = {"interface", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &interface, &PyNs3Ipv4InterfaceAddress_Type, &address)) {
        return NULL;
    }
    self->obj->NotifyAddAddress(interface, *((PyNs3Ipv4InterfaceAddress *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::aodv::RoutingProtocol::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetDesinationOnlyFlag(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetDesinationOnlyFlag(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetHelloEnable(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetHelloEnable(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_NotifyInterfaceDown(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->NotifyInterfaceDown(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetIpv4(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4 *ipv4;
    ns3::Ipv4 *ipv4_ptr;
    const char *keywords[] = {"ipv4", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4_Type, &ipv4)) {
        return NULL;
    }
    ipv4_ptr = (ipv4 ? ipv4->obj : NULL);
    self->obj->SetIpv4(ns3::Ptr< ns3::Ipv4  > (ipv4_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_DoDispose(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    
    self->obj->DoDispose();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetMaxQueueTime(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        return NULL;
    }
    self->obj->SetMaxQueueTime(*((PyNs3Time *) t)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_NotifyInterfaceUp(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->NotifyInterfaceUp(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_GetMaxQueueLen(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetMaxQueueLen();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_GetHelloEnable(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetHelloEnable();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_GetDesinationOnlyFlag(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetDesinationOnlyFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_PrintRoutingTable(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream)) {
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->PrintRoutingTable(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_NotifyRemoveAddress(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    PyNs3Ipv4InterfaceAddress *address;
    const char *keywords[] = {"interface", "address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "IO!", (char **) keywords, &interface, &PyNs3Ipv4InterfaceAddress_Type, &address)) {
        return NULL;
    }
    self->obj->NotifyRemoveAddress(interface, *((PyNs3Ipv4InterfaceAddress *) address)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_GetGratuitousReplyFlag(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetGratuitousReplyFlag();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetMaxQueueLen(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int len;
    const char *keywords[] = {"len", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &len)) {
        return NULL;
    }
    self->obj->SetMaxQueueLen(len);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_RouteOutput(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4Route > retval;
    PyNs3Packet *p;
    ns3::Packet *p_ptr;
    PyNs3Ipv4Header *header;
    PyNs3NetDevice *oif;
    ns3::NetDevice *oif_ptr;
    ns3::Socket::SocketErrno  sockerr;
    const char *keywords[] = {"p", "header", "oif", "sockerr", NULL};
    PyNs3Ipv4Route *py_Ipv4Route;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!O!i", (char **) keywords, &PyNs3Packet_Type, &p, &PyNs3Ipv4Header_Type, &header, &PyNs3NetDevice_Type, &oif, &sockerr)) {
        return NULL;
    }
    p_ptr = (p ? p->obj : NULL);
    oif_ptr = (oif ? oif->obj : NULL);
    retval = self->obj->RouteOutput(ns3::Ptr< ns3::Packet  > (p_ptr), *((PyNs3Ipv4Header *) header)->obj, ns3::Ptr< ns3::NetDevice  > (oif_ptr), sockerr);
    if (!(const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Ipv4Route = NULL;
    } else {
        py_Ipv4Route = (PyNs3Ipv4Route *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4Route);
    }
    
    if (py_Ipv4Route == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4Route_Type);
        py_Ipv4Route = PyObject_New(PyNs3Ipv4Route, wrapper_type);
    
        py_Ipv4Route->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4Route->obj = const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_Ipv4Route->obj] = (PyObject *) py_Ipv4Route;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Route);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_GetBroadcastEnable(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetBroadcastEnable();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_AssignStreams(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRoutingProtocol_GetMaxQueueTime(PyNs3AodvRoutingProtocol *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetMaxQueueTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetBroadcastEnable(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetBroadcastEnable(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingProtocol_SetGratuitousReplyFlag(PyNs3AodvRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetGratuitousReplyFlag(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRoutingProtocol__copy__(PyNs3AodvRoutingProtocol *self)
{

    PyNs3AodvRoutingProtocol *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvRoutingProtocol, &PyNs3AodvRoutingProtocol_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::aodv::RoutingProtocol(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRoutingProtocol_methods[] = {
    {(char *) "NotifyAddAddress", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_NotifyAddAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetDesinationOnlyFlag", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetDesinationOnlyFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHelloEnable", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetHelloEnable, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceDown", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_NotifyInterfaceDown, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetIpv4", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetIpv4, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_DoDispose, METH_NOARGS, NULL },
    {(char *) "SetMaxQueueTime", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetMaxQueueTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyInterfaceUp", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_NotifyInterfaceUp, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMaxQueueLen", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetMaxQueueLen, METH_NOARGS, NULL },
    {(char *) "GetHelloEnable", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetHelloEnable, METH_NOARGS, NULL },
    {(char *) "GetDesinationOnlyFlag", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetDesinationOnlyFlag, METH_NOARGS, NULL },
    {(char *) "PrintRoutingTable", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_PrintRoutingTable, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyRemoveAddress", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_NotifyRemoveAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetGratuitousReplyFlag", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetGratuitousReplyFlag, METH_NOARGS, NULL },
    {(char *) "SetMaxQueueLen", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetMaxQueueLen, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "RouteOutput", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_RouteOutput, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBroadcastEnable", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetBroadcastEnable, METH_NOARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMaxQueueTime", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_GetMaxQueueTime, METH_NOARGS, NULL },
    {(char *) "SetBroadcastEnable", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetBroadcastEnable, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetGratuitousReplyFlag", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol_SetGratuitousReplyFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRoutingProtocol__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvRoutingProtocol__tp_clear(PyNs3AodvRoutingProtocol *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::aodv::RoutingProtocol *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3AodvRoutingProtocol__tp_traverse(PyNs3AodvRoutingProtocol *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvRoutingProtocol__tp_dealloc(PyNs3AodvRoutingProtocol *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvRoutingProtocol__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvRoutingProtocol__tp_richcompare (PyNs3AodvRoutingProtocol *PYBINDGEN_UNUSED(self), PyNs3AodvRoutingProtocol *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRoutingProtocol_Type)) {
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

PyTypeObject PyNs3AodvRoutingProtocol_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RoutingProtocol",            /* tp_name */
    sizeof(PyNs3AodvRoutingProtocol),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRoutingProtocol__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3AodvRoutingProtocol__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvRoutingProtocol__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvRoutingProtocol__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRoutingProtocol_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvRoutingProtocol, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRoutingProtocol__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvRoutingTable_wrapper_registry;


static int
_wrap_PyNs3AodvRoutingTable__tp_init__0(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRoutingTable *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRoutingTable_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RoutingTable(*((PyNs3AodvRoutingTable *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRoutingTable__tp_init__1(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RoutingTable(*((PyNs3Time *) t)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRoutingTable__tp_init(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRoutingTable__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRoutingTable__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRoutingTable_GetListOfDestinationWithNextHop(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *nextHop;
    std::map< ns3::Ipv4Address, unsigned int > unreachable_value;
    const char *keywords[] = {"nextHop", "unreachable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O&", (char **) keywords, &PyNs3Ipv4Address_Type, &nextHop, _wrap_convert_py2c__std__map__lt___ns3__Ipv4Address__unsigned_int___gt__, &unreachable_value)) {
        return NULL;
    }
    self->obj->GetListOfDestinationWithNextHop(*((PyNs3Ipv4Address *) nextHop)->obj, unreachable_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_DeleteAllRoutesFromInterface(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4InterfaceAddress *iface;
    const char *keywords[] = {"iface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4InterfaceAddress_Type, &iface)) {
        return NULL;
    }
    self->obj->DeleteAllRoutesFromInterface(*((PyNs3Ipv4InterfaceAddress *) iface)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_LookupValidRoute(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    PyNs3AodvRoutingTableEntry *rt;
    const char *keywords[] = {"dst", "rt", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &dst, &PyNs3AodvRoutingTableEntry_Type, &rt)) {
        return NULL;
    }
    retval = self->obj->LookupValidRoute(*((PyNs3Ipv4Address *) dst)->obj, *((PyNs3AodvRoutingTableEntry *) rt)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_Print(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream)) {
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->Print(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_Clear(PyNs3AodvRoutingTable *self)
{
    PyObject *py_retval;
    
    self->obj->Clear();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_Update(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3AodvRoutingTableEntry *rt;
    const char *keywords[] = {"rt", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRoutingTableEntry_Type, &rt)) {
        return NULL;
    }
    retval = self->obj->Update(*((PyNs3AodvRoutingTableEntry *) rt)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_LookupRoute(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    PyNs3AodvRoutingTableEntry *rt;
    const char *keywords[] = {"dst", "rt", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &dst, &PyNs3AodvRoutingTableEntry_Type, &rt)) {
        return NULL;
    }
    retval = self->obj->LookupRoute(*((PyNs3Ipv4Address *) dst)->obj, *((PyNs3AodvRoutingTableEntry *) rt)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_Purge(PyNs3AodvRoutingTable *self)
{
    PyObject *py_retval;
    
    self->obj->Purge();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_MarkLinkAsUnidirectional(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *neighbor;
    PyNs3Time *blacklistTimeout;
    const char *keywords[] = {"neighbor", "blacklistTimeout", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighbor, &PyNs3Time_Type, &blacklistTimeout)) {
        return NULL;
    }
    retval = self->obj->MarkLinkAsUnidirectional(*((PyNs3Ipv4Address *) neighbor)->obj, *((PyNs3Time *) blacklistTimeout)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_DeleteRoute(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    const char *keywords[] = {"dst", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &dst)) {
        return NULL;
    }
    retval = self->obj->DeleteRoute(*((PyNs3Ipv4Address *) dst)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_SetBadLinkLifetime(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        return NULL;
    }
    self->obj->SetBadLinkLifetime(*((PyNs3Time *) t)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_AddRoute(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3AodvRoutingTableEntry *r;
    const char *keywords[] = {"r", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRoutingTableEntry_Type, &r)) {
        return NULL;
    }
    retval = self->obj->AddRoute(*((PyNs3AodvRoutingTableEntry *) r)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_InvalidateRoutesWithDst(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::map< ns3::Ipv4Address, unsigned int > unreachable_value;
    const char *keywords[] = {"unreachable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__std__map__lt___ns3__Ipv4Address__unsigned_int___gt__, &unreachable_value)) {
        return NULL;
    }
    self->obj->InvalidateRoutesWithDst(unreachable_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_GetBadLinkLifetime(PyNs3AodvRoutingTable *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetBadLinkLifetime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTable_SetEntryState(PyNs3AodvRoutingTable *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *dst;
    ns3::aodv::RouteFlags state;
    const char *keywords[] = {"dst", "state", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &dst, &state)) {
        return NULL;
    }
    retval = self->obj->SetEntryState(*((PyNs3Ipv4Address *) dst)->obj, state);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRoutingTable__copy__(PyNs3AodvRoutingTable *self)
{

    PyNs3AodvRoutingTable *py_copy;
    py_copy = PyObject_New(PyNs3AodvRoutingTable, &PyNs3AodvRoutingTable_Type);
    py_copy->obj = new ns3::aodv::RoutingTable(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvRoutingTable_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRoutingTable_methods[] = {
    {(char *) "GetListOfDestinationWithNextHop", (PyCFunction) _wrap_PyNs3AodvRoutingTable_GetListOfDestinationWithNextHop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeleteAllRoutesFromInterface", (PyCFunction) _wrap_PyNs3AodvRoutingTable_DeleteAllRoutesFromInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "LookupValidRoute", (PyCFunction) _wrap_PyNs3AodvRoutingTable_LookupValidRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3AodvRoutingTable_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Clear", (PyCFunction) _wrap_PyNs3AodvRoutingTable_Clear, METH_NOARGS, NULL },
    {(char *) "Update", (PyCFunction) _wrap_PyNs3AodvRoutingTable_Update, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "LookupRoute", (PyCFunction) _wrap_PyNs3AodvRoutingTable_LookupRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Purge", (PyCFunction) _wrap_PyNs3AodvRoutingTable_Purge, METH_NOARGS, NULL },
    {(char *) "MarkLinkAsUnidirectional", (PyCFunction) _wrap_PyNs3AodvRoutingTable_MarkLinkAsUnidirectional, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeleteRoute", (PyCFunction) _wrap_PyNs3AodvRoutingTable_DeleteRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetBadLinkLifetime", (PyCFunction) _wrap_PyNs3AodvRoutingTable_SetBadLinkLifetime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AddRoute", (PyCFunction) _wrap_PyNs3AodvRoutingTable_AddRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InvalidateRoutesWithDst", (PyCFunction) _wrap_PyNs3AodvRoutingTable_InvalidateRoutesWithDst, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetBadLinkLifetime", (PyCFunction) _wrap_PyNs3AodvRoutingTable_GetBadLinkLifetime, METH_NOARGS, NULL },
    {(char *) "SetEntryState", (PyCFunction) _wrap_PyNs3AodvRoutingTable_SetEntryState, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRoutingTable__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvRoutingTable__tp_dealloc(PyNs3AodvRoutingTable *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvRoutingTable_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvRoutingTable_wrapper_registry.end()) {
        PyNs3AodvRoutingTable_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::RoutingTable *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvRoutingTable__tp_richcompare (PyNs3AodvRoutingTable *PYBINDGEN_UNUSED(self), PyNs3AodvRoutingTable *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRoutingTable_Type)) {
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

PyTypeObject PyNs3AodvRoutingTable_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RoutingTable",            /* tp_name */
    sizeof(PyNs3AodvRoutingTable),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRoutingTable__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvRoutingTable__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRoutingTable_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRoutingTable__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3AodvRoutingTableEntry_wrapper_registry;
static PyObject* _wrap_PyNs3AodvRoutingTableEntry__get_m_ackTimer(PyNs3AodvRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Timer *py_Timer;
    
    py_Timer = PyObject_New(PyNs3Timer, &PyNs3Timer_Type);
    py_Timer->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Timer->obj = new ns3::Timer(self->obj->m_ackTimer);
    PyNs3Timer_wrapper_registry[(void *) py_Timer->obj] = (PyObject *) py_Timer;
    py_retval = Py_BuildValue((char *) "N", py_Timer);
    return py_retval;
}
static int _wrap_PyNs3AodvRoutingTableEntry__set_m_ackTimer(PyNs3AodvRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Timer *tmp_Timer;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Timer_Type, &tmp_Timer)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->m_ackTimer = *tmp_Timer->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3AodvRoutingTableEntry__getsets[] = {
    {
        (char*) "m_ackTimer", /* attribute name */
        (getter) _wrap_PyNs3AodvRoutingTableEntry__get_m_ackTimer, /* C function to get the attribute */
        (setter) _wrap_PyNs3AodvRoutingTableEntry__set_m_ackTimer, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3AodvRoutingTableEntry__tp_init__0(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRoutingTableEntry *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRoutingTableEntry_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RoutingTableEntry(*((PyNs3AodvRoutingTableEntry *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRoutingTableEntry__tp_init__1(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3NetDevice *dev = NULL;
    ns3::NetDevice *dev_ptr;
    PyNs3Ipv4Address *dst = NULL;
    bool vSeqNo;
    PyObject *py_vSeqNo = NULL;
    unsigned int m_seqNo = 0;
    PyNs3Ipv4InterfaceAddress *iface = NULL;
    int hops = 0;
    PyNs3Ipv4Address *nextHop = NULL;
    PyNs3Time *lifetime = NULL;
    const char *keywords[] = {"dev", "dst", "vSeqNo", "m_seqNo", "iface", "hops", "nextHop", "lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O!O!OIO!iO!O!", (char **) keywords, &PyNs3NetDevice_Type, &dev, &PyNs3Ipv4Address_Type, &dst, &py_vSeqNo, &m_seqNo, &PyNs3Ipv4InterfaceAddress_Type, &iface, &hops, &PyNs3Ipv4Address_Type, &nextHop, &PyNs3Time_Type, &lifetime)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    dev_ptr = (dev ? dev->obj : NULL);
    vSeqNo = py_vSeqNo? (bool) PyObject_IsTrue(py_vSeqNo) : false;
    if (hops > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RoutingTableEntry(ns3::Ptr< ns3::NetDevice  > (dev_ptr), (dst ? (*((PyNs3Ipv4Address *) dst)->obj) : ns3::Ipv4Address()), vSeqNo, m_seqNo, (iface ? (*((PyNs3Ipv4InterfaceAddress *) iface)->obj) : ns3::Ipv4InterfaceAddress()), hops, (nextHop ? (*((PyNs3Ipv4Address *) nextHop)->obj) : ns3::Ipv4Address()), (lifetime ? (*((PyNs3Time *) lifetime)->obj) : ns3::Simulator::Now( )));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRoutingTableEntry__tp_init(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRoutingTableEntry_IsPrecursorListEmpty(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsPrecursorListEmpty();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetValidSeqNo(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool s;
    PyObject *py_s;
    const char *keywords[] = {"s", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_s)) {
        return NULL;
    }
    s = (bool) PyObject_IsTrue(py_s);
    self->obj->SetValidSeqNo(s);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetPrecursors(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > prec_value;
    const char *keywords[] = {"prec", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &prec_value)) {
        return NULL;
    }
    self->obj->GetPrecursors(prec_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetValidSeqNo(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetValidSeqNo();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_Print(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream)) {
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    self->obj->Print(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_DeletePrecursor(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *id;
    const char *keywords[] = {"id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &id)) {
        return NULL;
    }
    retval = self->obj->DeletePrecursor(*((PyNs3Ipv4Address *) id)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetSeqNo(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int sn;
    const char *keywords[] = {"sn", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &sn)) {
        return NULL;
    }
    self->obj->SetSeqNo(sn);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetFlag(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    ns3::aodv::RouteFlags retval;
    
    retval = self->obj->GetFlag();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetRreqCnt(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetRreqCnt();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetBalcklistTimeout(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        return NULL;
    }
    self->obj->SetBalcklistTimeout(*((PyNs3Time *) t)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetLifeTime(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetLifeTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetBlacklistTimeout(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetBlacklistTimeout();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetHop(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int hop;
    const char *keywords[] = {"hop", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &hop)) {
        return NULL;
    }
    if (hop > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHop(hop);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetHop(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetHop();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_LookupPrecursor(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *id;
    const char *keywords[] = {"id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &id)) {
        return NULL;
    }
    retval = self->obj->LookupPrecursor(*((PyNs3Ipv4Address *) id)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_IsUnidirectional(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsUnidirectional();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetSeqNo(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSeqNo();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetFlag(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::aodv::RouteFlags flag;
    const char *keywords[] = {"flag", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &flag)) {
        return NULL;
    }
    self->obj->SetFlag(flag);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetOutputDevice(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3NetDevice *dev;
    ns3::NetDevice *dev_ptr;
    const char *keywords[] = {"dev", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NetDevice_Type, &dev)) {
        return NULL;
    }
    dev_ptr = (dev ? dev->obj : NULL);
    self->obj->SetOutputDevice(ns3::Ptr< ns3::NetDevice  > (dev_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetDestination(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetDestination();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetInterface(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4InterfaceAddress *iface;
    const char *keywords[] = {"iface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4InterfaceAddress_Type, &iface)) {
        return NULL;
    }
    self->obj->SetInterface(*((PyNs3Ipv4InterfaceAddress *) iface)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_Invalidate(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *badLinkLifetime;
    const char *keywords[] = {"badLinkLifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &badLinkLifetime)) {
        return NULL;
    }
    self->obj->Invalidate(*((PyNs3Time *) badLinkLifetime)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_InsertPrecursor(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *id;
    const char *keywords[] = {"id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &id)) {
        return NULL;
    }
    retval = self->obj->InsertPrecursor(*((PyNs3Ipv4Address *) id)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetNextHop(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *nextHop;
    const char *keywords[] = {"nextHop", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &nextHop)) {
        return NULL;
    }
    self->obj->SetNextHop(*((PyNs3Ipv4Address *) nextHop)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_DeleteAllPrecursors(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    
    self->obj->DeleteAllPrecursors();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_IncrementRreqCnt(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    
    self->obj->IncrementRreqCnt();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetRoute(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Route *r;
    ns3::Ipv4Route *r_ptr;
    const char *keywords[] = {"r", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Route_Type, &r)) {
        return NULL;
    }
    r_ptr = (r ? r->obj : NULL);
    self->obj->SetRoute(ns3::Ptr< ns3::Ipv4Route  > (r_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetOutputDevice(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::NetDevice > retval;
    PyNs3NetDevice *py_NetDevice;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetOutputDevice();
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
_wrap_PyNs3AodvRoutingTableEntry_SetUnidirectional(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool u;
    PyObject *py_u;
    const char *keywords[] = {"u", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_u)) {
        return NULL;
    }
    u = (bool) PyObject_IsTrue(py_u);
    self->obj->SetUnidirectional(u);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetNextHop(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetNextHop();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetRoute(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4Route > retval;
    PyNs3Ipv4Route *py_Ipv4Route;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetRoute();
    if (!(const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Ipv4Route = NULL;
    } else {
        py_Ipv4Route = (PyNs3Ipv4Route *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4Route);
    }
    
    if (py_Ipv4Route == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Ipv4Route_Ns3Empty_Ns3DefaultDeleter__lt__ns3Ipv4Route__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4Route_Type);
        py_Ipv4Route = PyObject_New(PyNs3Ipv4Route, wrapper_type);
    
        py_Ipv4Route->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4Route->obj = const_cast<ns3::Ipv4Route *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_Ipv4Route->obj] = (PyObject *) py_Ipv4Route;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Route);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetRreqCnt(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int n;
    const char *keywords[] = {"n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &n)) {
        return NULL;
    }
    if (n > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetRreqCnt(n);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_GetInterface(PyNs3AodvRoutingTableEntry *self)
{
    PyObject *py_retval;
    PyNs3Ipv4InterfaceAddress *py_Ipv4InterfaceAddress;
    
    ns3::Ipv4InterfaceAddress retval = self->obj->GetInterface();
    py_Ipv4InterfaceAddress = PyObject_New(PyNs3Ipv4InterfaceAddress, &PyNs3Ipv4InterfaceAddress_Type);
    py_Ipv4InterfaceAddress->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4InterfaceAddress->obj = new ns3::Ipv4InterfaceAddress(retval);
    PyNs3Ipv4InterfaceAddress_wrapper_registry[(void *) py_Ipv4InterfaceAddress->obj] = (PyObject *) py_Ipv4InterfaceAddress;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4InterfaceAddress);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRoutingTableEntry_SetLifeTime(PyNs3AodvRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *lt;
    const char *keywords[] = {"lt", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &lt)) {
        return NULL;
    }
    self->obj->SetLifeTime(*((PyNs3Time *) lt)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRoutingTableEntry__copy__(PyNs3AodvRoutingTableEntry *self)
{

    PyNs3AodvRoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3AodvRoutingTableEntry, &PyNs3AodvRoutingTableEntry_Type);
    py_copy->obj = new ns3::aodv::RoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3AodvRoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRoutingTableEntry_methods[] = {
    {(char *) "IsPrecursorListEmpty", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_IsPrecursorListEmpty, METH_NOARGS, NULL },
    {(char *) "SetValidSeqNo", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetValidSeqNo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPrecursors", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetPrecursors, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetValidSeqNo", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetValidSeqNo, METH_NOARGS, NULL },
    {(char *) "Print", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_Print, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeletePrecursor", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_DeletePrecursor, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetSeqNo", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetSeqNo, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetFlag", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetFlag, METH_NOARGS, NULL },
    {(char *) "GetRreqCnt", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetRreqCnt, METH_NOARGS, NULL },
    {(char *) "SetBalcklistTimeout", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetBalcklistTimeout, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetLifeTime", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetLifeTime, METH_NOARGS, NULL },
    {(char *) "GetBlacklistTimeout", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetBlacklistTimeout, METH_NOARGS, NULL },
    {(char *) "SetHop", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetHop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHop", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetHop, METH_NOARGS, NULL },
    {(char *) "LookupPrecursor", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_LookupPrecursor, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsUnidirectional", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_IsUnidirectional, METH_NOARGS, NULL },
    {(char *) "GetSeqNo", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetSeqNo, METH_NOARGS, NULL },
    {(char *) "SetFlag", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetFlag, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetOutputDevice", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetOutputDevice, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDestination", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetDestination, METH_NOARGS, NULL },
    {(char *) "SetInterface", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Invalidate", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_Invalidate, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertPrecursor", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_InsertPrecursor, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetNextHop", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetNextHop, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeleteAllPrecursors", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_DeleteAllPrecursors, METH_NOARGS, NULL },
    {(char *) "IncrementRreqCnt", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_IncrementRreqCnt, METH_NOARGS, NULL },
    {(char *) "SetRoute", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetRoute, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetOutputDevice", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetOutputDevice, METH_NOARGS, NULL },
    {(char *) "SetUnidirectional", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetUnidirectional, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetNextHop", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetNextHop, METH_NOARGS, NULL },
    {(char *) "GetRoute", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetRoute, METH_NOARGS, NULL },
    {(char *) "SetRreqCnt", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetRreqCnt, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInterface", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_GetInterface, METH_NOARGS, NULL },
    {(char *) "SetLifeTime", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry_SetLifeTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3AodvRoutingTableEntry__tp_dealloc(PyNs3AodvRoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3AodvRoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3AodvRoutingTableEntry_wrapper_registry.end()) {
        PyNs3AodvRoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::aodv::RoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvRoutingTableEntry__tp_richcompare (PyNs3AodvRoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3AodvRoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRoutingTableEntry_Type)) {
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

PyTypeObject PyNs3AodvRoutingTableEntry_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RoutingTableEntry",            /* tp_name */
    sizeof(PyNs3AodvRoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3AodvRoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3AodvRoutingTableEntry__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRoutingTableEntry__tp_init,             /* tp_init */
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
_wrap_PyNs3AodvRrepAckHeader__tp_init__0(PyNs3AodvRrepAckHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRrepAckHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRrepAckHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RrepAckHeader(*((PyNs3AodvRrepAckHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRrepAckHeader__tp_init__1(PyNs3AodvRrepAckHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::aodv::RrepAckHeader();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRrepAckHeader__tp_init(PyNs3AodvRrepAckHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRrepAckHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRrepAckHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRrepAckHeader_GetSerializedSize(PyNs3AodvRrepAckHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepAckHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::aodv::RrepAckHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepAckHeader_Serialize(PyNs3AodvRrepAckHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRrepAckHeader_Deserialize(PyNs3AodvRrepAckHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRrepAckHeader_GetInstanceTypeId(PyNs3AodvRrepAckHeader *self)
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
_wrap_PyNs3AodvRrepAckHeader__copy__(PyNs3AodvRrepAckHeader *self)
{

    PyNs3AodvRrepAckHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvRrepAckHeader, &PyNs3AodvRrepAckHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::aodv::RrepAckHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRrepAckHeader_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3AodvRrepAckHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AodvRrepAckHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3AodvRrepAckHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3AodvRrepAckHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3AodvRrepAckHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRrepAckHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvRrepAckHeader__tp_clear(PyNs3AodvRrepAckHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::aodv::RrepAckHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3AodvRrepAckHeader__tp_traverse(PyNs3AodvRrepAckHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvRrepAckHeader__tp_dealloc(PyNs3AodvRrepAckHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvRrepAckHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3AodvRrepAckHeader__tp_str(PyNs3AodvRrepAckHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3AodvRrepAckHeader__tp_richcompare (PyNs3AodvRrepAckHeader *PYBINDGEN_UNUSED(self), PyNs3AodvRrepAckHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRrepAckHeader_Type)) {
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

PyTypeObject PyNs3AodvRrepAckHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RrepAckHeader",            /* tp_name */
    sizeof(PyNs3AodvRrepAckHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRrepAckHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3AodvRrepAckHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3AodvRrepAckHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvRrepAckHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvRrepAckHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRrepAckHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvRrepAckHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRrepAckHeader__tp_init,             /* tp_init */
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
_wrap_PyNs3AodvRrepHeader__tp_init__0(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRrepHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRrepHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RrepHeader(*((PyNs3AodvRrepHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRrepHeader__tp_init__1(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int prefixSize = 0;
    int hopCount = 0;
    PyNs3Ipv4Address *dst = NULL;
    unsigned int dstSeqNo = 0;
    PyNs3Ipv4Address *origin = NULL;
    PyNs3Time *lifetime = NULL;
    const char *keywords[] = {"prefixSize", "hopCount", "dst", "dstSeqNo", "origin", "lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|iiO!IO!O!", (char **) keywords, &prefixSize, &hopCount, &PyNs3Ipv4Address_Type, &dst, &dstSeqNo, &PyNs3Ipv4Address_Type, &origin, &PyNs3Time_Type, &lifetime)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (prefixSize > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (hopCount > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RrepHeader(prefixSize, hopCount, (dst ? (*((PyNs3Ipv4Address *) dst)->obj) : ns3::Ipv4Address()), dstSeqNo, (origin ? (*((PyNs3Ipv4Address *) origin)->obj) : ns3::Ipv4Address()), (lifetime ? (*((PyNs3Time *) lifetime)->obj) : ns3::MilliSeconds(0)));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRrepHeader__tp_init(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRrepHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRrepHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRrepHeader_SetHello(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *src;
    unsigned int srcSeqNo;
    PyNs3Time *lifetime;
    const char *keywords[] = {"src", "srcSeqNo", "lifetime", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!IO!", (char **) keywords, &PyNs3Ipv4Address_Type, &src, &srcSeqNo, &PyNs3Time_Type, &lifetime)) {
        return NULL;
    }
    self->obj->SetHello(*((PyNs3Ipv4Address *) src)->obj, srcSeqNo, *((PyNs3Time *) lifetime)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_Serialize(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRrepHeader_GetHopCount(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetHopCount();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_Deserialize(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRrepHeader_SetPrefixSize(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int sz;
    const char *keywords[] = {"sz", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &sz)) {
        return NULL;
    }
    if (sz > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPrefixSize(sz);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::aodv::RrepHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetOrigin(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetOrigin();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetDstSeqno(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetDstSeqno();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetLifeTime(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetLifeTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_SetDst(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *a;
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &a)) {
        return NULL;
    }
    self->obj->SetDst(*((PyNs3Ipv4Address *) a)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_SetDstSeqno(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int s;
    const char *keywords[] = {"s", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &s)) {
        return NULL;
    }
    self->obj->SetDstSeqno(s);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetDst(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetDst();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetPrefixSize(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetPrefixSize();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetInstanceTypeId(PyNs3AodvRrepHeader *self)
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
_wrap_PyNs3AodvRrepHeader_GetSerializedSize(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_SetHopCount(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int count;
    const char *keywords[] = {"count", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &count)) {
        return NULL;
    }
    if (count > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHopCount(count);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_SetAckRequired(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetAckRequired(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_SetOrigin(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *a;
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &a)) {
        return NULL;
    }
    self->obj->SetOrigin(*((PyNs3Ipv4Address *) a)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_SetLifeTime(PyNs3AodvRrepHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *t;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &t)) {
        return NULL;
    }
    self->obj->SetLifeTime(*((PyNs3Time *) t)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRrepHeader_GetAckRequired(PyNs3AodvRrepHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetAckRequired();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRrepHeader__copy__(PyNs3AodvRrepHeader *self)
{

    PyNs3AodvRrepHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvRrepHeader, &PyNs3AodvRrepHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::aodv::RrepHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRrepHeader_methods[] = {
    {(char *) "SetHello", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetHello, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3AodvRrepHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHopCount", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetHopCount, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3AodvRrepHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPrefixSize", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetPrefixSize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetOrigin", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetOrigin, METH_NOARGS, NULL },
    {(char *) "GetDstSeqno", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetDstSeqno, METH_NOARGS, NULL },
    {(char *) "GetLifeTime", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetLifeTime, METH_NOARGS, NULL },
    {(char *) "SetDst", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetDst, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDstSeqno", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetDstSeqno, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDst", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetDst, METH_NOARGS, NULL },
    {(char *) "GetPrefixSize", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetPrefixSize, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetHopCount", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetHopCount, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetAckRequired", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetAckRequired, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetOrigin", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetOrigin, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLifeTime", (PyCFunction) _wrap_PyNs3AodvRrepHeader_SetLifeTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetAckRequired", (PyCFunction) _wrap_PyNs3AodvRrepHeader_GetAckRequired, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRrepHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvRrepHeader__tp_clear(PyNs3AodvRrepHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::aodv::RrepHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3AodvRrepHeader__tp_traverse(PyNs3AodvRrepHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvRrepHeader__tp_dealloc(PyNs3AodvRrepHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvRrepHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3AodvRrepHeader__tp_str(PyNs3AodvRrepHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3AodvRrepHeader__tp_richcompare (PyNs3AodvRrepHeader *PYBINDGEN_UNUSED(self), PyNs3AodvRrepHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRrepHeader_Type)) {
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

PyTypeObject PyNs3AodvRrepHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RrepHeader",            /* tp_name */
    sizeof(PyNs3AodvRrepHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRrepHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3AodvRrepHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3AodvRrepHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvRrepHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvRrepHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRrepHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvRrepHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRrepHeader__tp_init,             /* tp_init */
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
_wrap_PyNs3AodvRreqHeader__tp_init__0(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvRreqHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvRreqHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RreqHeader(*((PyNs3AodvRreqHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvRreqHeader__tp_init__1(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    int flags = 0;
    int reserved = 0;
    int hopCount = 0;
    unsigned int requestID = 0;
    PyNs3Ipv4Address *dst = NULL;
    unsigned int dstSeqNo = 0;
    PyNs3Ipv4Address *origin = NULL;
    unsigned int originSeqNo = 0;
    const char *keywords[] = {"flags", "reserved", "hopCount", "requestID", "dst", "dstSeqNo", "origin", "originSeqNo", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|iiiIO!IO!I", (char **) keywords, &flags, &reserved, &hopCount, &requestID, &PyNs3Ipv4Address_Type, &dst, &dstSeqNo, &PyNs3Ipv4Address_Type, &origin, &originSeqNo)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (flags > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (reserved > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (hopCount > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::RreqHeader(flags, reserved, hopCount, requestID, (dst ? (*((PyNs3Ipv4Address *) dst)->obj) : ns3::Ipv4Address()), dstSeqNo, (origin ? (*((PyNs3Ipv4Address *) origin)->obj) : ns3::Ipv4Address()), originSeqNo);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvRreqHeader__tp_init(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvRreqHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvRreqHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvRreqHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::aodv::RreqHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetOrigin(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *a;
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &a)) {
        return NULL;
    }
    self->obj->SetOrigin(*((PyNs3Ipv4Address *) a)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetDst(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetDst();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetOriginSeqno(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int s;
    const char *keywords[] = {"s", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &s)) {
        return NULL;
    }
    self->obj->SetOriginSeqno(s);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetId(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int id;
    const char *keywords[] = {"id", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &id)) {
        return NULL;
    }
    self->obj->SetId(id);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetDstSeqno(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int s;
    const char *keywords[] = {"s", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &s)) {
        return NULL;
    }
    self->obj->SetDstSeqno(s);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetOrigin(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetOrigin();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetDst(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *a;
    const char *keywords[] = {"a", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &a)) {
        return NULL;
    }
    self->obj->SetDst(*((PyNs3Ipv4Address *) a)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetDestinationOnly(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetDestinationOnly();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetOriginSeqno(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetOriginSeqno();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetUnknownSeqno(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetUnknownSeqno(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetUnknownSeqno(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetUnknownSeqno();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetHopCount(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetHopCount();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_Deserialize(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRreqHeader_GetId(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetId();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetInstanceTypeId(PyNs3AodvRreqHeader *self)
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
_wrap_PyNs3AodvRreqHeader_GetSerializedSize(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetHopCount(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int count;
    const char *keywords[] = {"count", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &count)) {
        return NULL;
    }
    if (count > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHopCount(count);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetDestinationOnly(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetDestinationOnly(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_GetGratiousRrep(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->GetGratiousRrep();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_Serialize(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvRreqHeader_GetDstSeqno(PyNs3AodvRreqHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetDstSeqno();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvRreqHeader_SetGratiousRrep(PyNs3AodvRreqHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool f;
    PyObject *py_f;
    const char *keywords[] = {"f", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O", (char **) keywords, &py_f)) {
        return NULL;
    }
    f = (bool) PyObject_IsTrue(py_f);
    self->obj->SetGratiousRrep(f);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvRreqHeader__copy__(PyNs3AodvRreqHeader *self)
{

    PyNs3AodvRreqHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvRreqHeader, &PyNs3AodvRreqHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::aodv::RreqHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvRreqHeader_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetOrigin", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetOrigin, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDst", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetDst, METH_NOARGS, NULL },
    {(char *) "SetOriginSeqno", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetOriginSeqno, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetId", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetId, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDstSeqno", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetDstSeqno, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetOrigin", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetOrigin, METH_NOARGS, NULL },
    {(char *) "SetDst", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetDst, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDestinationOnly", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetDestinationOnly, METH_NOARGS, NULL },
    {(char *) "GetOriginSeqno", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetOriginSeqno, METH_NOARGS, NULL },
    {(char *) "SetUnknownSeqno", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetUnknownSeqno, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetUnknownSeqno", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetUnknownSeqno, METH_NOARGS, NULL },
    {(char *) "GetHopCount", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetHopCount, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3AodvRreqHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetId", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetId, METH_NOARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetHopCount", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetHopCount, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetDestinationOnly", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetDestinationOnly, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetGratiousRrep", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetGratiousRrep, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3AodvRreqHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDstSeqno", (PyCFunction) _wrap_PyNs3AodvRreqHeader_GetDstSeqno, METH_NOARGS, NULL },
    {(char *) "SetGratiousRrep", (PyCFunction) _wrap_PyNs3AodvRreqHeader_SetGratiousRrep, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvRreqHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvRreqHeader__tp_clear(PyNs3AodvRreqHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::aodv::RreqHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3AodvRreqHeader__tp_traverse(PyNs3AodvRreqHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvRreqHeader__tp_dealloc(PyNs3AodvRreqHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvRreqHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3AodvRreqHeader__tp_str(PyNs3AodvRreqHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3AodvRreqHeader__tp_richcompare (PyNs3AodvRreqHeader *PYBINDGEN_UNUSED(self), PyNs3AodvRreqHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvRreqHeader_Type)) {
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

PyTypeObject PyNs3AodvRreqHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.RreqHeader",            /* tp_name */
    sizeof(PyNs3AodvRreqHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvRreqHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3AodvRreqHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3AodvRreqHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvRreqHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvRreqHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvRreqHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvRreqHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvRreqHeader__tp_init,             /* tp_init */
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
_wrap_PyNs3AodvTypeHeader__tp_init__0(PyNs3AodvTypeHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvTypeHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvTypeHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::TypeHeader(*((PyNs3AodvTypeHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvTypeHeader__tp_init__1(PyNs3AodvTypeHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    ns3::aodv::MessageType t = ::ns3::aodv::AODVTYPE_RREQ;
    const char *keywords[] = {"t", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|i", (char **) keywords, &t)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::aodv::TypeHeader(t);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvTypeHeader__tp_init(PyNs3AodvTypeHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvTypeHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvTypeHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvTypeHeader_Deserialize(PyNs3AodvTypeHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvTypeHeader_Get(PyNs3AodvTypeHeader *self)
{
    PyObject *py_retval;
    ns3::aodv::MessageType retval;
    
    retval = self->obj->Get();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvTypeHeader_IsValid(PyNs3AodvTypeHeader *self)
{
    PyObject *py_retval;
    bool retval;
    
    retval = self->obj->IsValid();
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvTypeHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::aodv::TypeHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvTypeHeader_Serialize(PyNs3AodvTypeHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3AodvTypeHeader_GetInstanceTypeId(PyNs3AodvTypeHeader *self)
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
_wrap_PyNs3AodvTypeHeader_GetSerializedSize(PyNs3AodvTypeHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvTypeHeader__copy__(PyNs3AodvTypeHeader *self)
{

    PyNs3AodvTypeHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvTypeHeader, &PyNs3AodvTypeHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::aodv::TypeHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvTypeHeader_methods[] = {
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3AodvTypeHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3AodvTypeHeader_Get, METH_NOARGS, NULL },
    {(char *) "IsValid", (PyCFunction) _wrap_PyNs3AodvTypeHeader_IsValid, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3AodvTypeHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3AodvTypeHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3AodvTypeHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3AodvTypeHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvTypeHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvTypeHeader__tp_clear(PyNs3AodvTypeHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::aodv::TypeHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3AodvTypeHeader__tp_traverse(PyNs3AodvTypeHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvTypeHeader__tp_dealloc(PyNs3AodvTypeHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvTypeHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3AodvTypeHeader__tp_str(PyNs3AodvTypeHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3AodvTypeHeader__tp_richcompare (PyNs3AodvTypeHeader *PYBINDGEN_UNUSED(self), PyNs3AodvTypeHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvTypeHeader_Type)) {
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

PyTypeObject PyNs3AodvTypeHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.TypeHeader",            /* tp_name */
    sizeof(PyNs3AodvTypeHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvTypeHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3AodvTypeHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3AodvTypeHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvTypeHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvTypeHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvTypeHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvTypeHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvTypeHeader__tp_init,             /* tp_init */
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
Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_clear(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_traverse(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt____tp_dealloc(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_dealloc(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt____tp_iter(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__ *self)
{
    Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter *iter = PyObject_GC_New(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter, &Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::map< ns3::Ipv4Address, unsigned int >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_iter(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_iternext(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter *self)
{
    PyObject *py_retval;
    std::map< ns3::Ipv4Address, unsigned int >::iterator iter;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(iter->first);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "NN", py_Ipv4Address, PyLong_FromUnsignedLong(iter->second));
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


int _wrap_convert_py2c__ns3__Ipv4Address(PyObject *value, ns3::Ipv4Address *address)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__map__lt___ns3__Ipv4Address__unsigned_int___gt__(PyObject *arg, std::map< ns3::Ipv4Address, unsigned int > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt___Type)) {
        *container = *((Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            PyObject *tup = PyList_GET_ITEM(arg, i);
            if (!PyTuple_Check(tup) || PyTuple_Size(tup) != 2) {
                PyErr_SetString(PyExc_TypeError, "items must be tuples with two elements");
                return 0;
            }
            std::pair< ns3::Ipv4Address, unsigned int > item;
            if (!_wrap_convert_py2c__ns3__Ipv4Address(PyTuple_GET_ITEM(tup, 0), &item.first)) {
                return 0;
            }
            if (!_wrap_convert_py2c__unsigned_int(PyTuple_GET_ITEM(tup, 1), &item.second)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__map__lt___ns3__Ipv4Address__unsigned_int___gt__ instance, or a list of unsigned int");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt____tp_init(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::map< ns3::Ipv4Address, unsigned int >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__map__lt___ns3__Ipv4Address__unsigned_int___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.Std__map__lt___ns3__Ipv4Address__unsigned_int___gt__",            /* tp_name */
    sizeof(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.Std__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter",            /* tp_name */
    sizeof(Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_clear(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt____tp_dealloc(Pystd__vector__lt___ns3__Ipv4Address___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt____tp_iter(Pystd__vector__lt___ns3__Ipv4Address___gt__ *self)
{
    Pystd__vector__lt___ns3__Ipv4Address___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter, &Pystd__vector__lt___ns3__Ipv4Address___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::Ipv4Address >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_iter(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address >::iterator iter;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address((*iter));
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}

int _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__(PyObject *arg, std::vector< ns3::Ipv4Address > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__Ipv4Address___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__Ipv4Address___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ipv4Address item;
            if (!_wrap_convert_py2c__ns3__Ipv4Address(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__Ipv4Address___gt__ instance, or a list of ns3::Ipv4Address");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt____tp_init(Pystd__vector__lt___ns3__Ipv4Address___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::Ipv4Address >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__Ipv4Address___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.Std__vector__lt___ns3__Ipv4Address___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__Ipv4Address___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__Ipv4Address___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.aodv.Std__vector__lt___ns3__Ipv4Address___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__Ipv4Address___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__Ipv4Address___gt__Iter__tp_iternext,     /* tp_iternext */
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
static struct PyModuleDef aodv_aodv_moduledef = {
    PyModuleDef_HEAD_INIT,
    "aodv.aodv",
    NULL,
    -1,
    aodv_aodv_functions,
};
#endif

static PyObject *
initaodv_aodv(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&aodv_aodv_moduledef);
    #else
    m = Py_InitModule3((char *) "aodv.aodv", aodv_aodv_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3AodvDuplicatePacketDetection_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvDuplicatePacketDetection_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::DuplicatePacketDetection' class */
    if (PyType_Ready(&PyNs3AodvDuplicatePacketDetection_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "DuplicatePacketDetection", (PyObject *) &PyNs3AodvDuplicatePacketDetection_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvIdCache_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvIdCache_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::IdCache' class */
    if (PyType_Ready(&PyNs3AodvIdCache_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "IdCache", (PyObject *) &PyNs3AodvIdCache_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvNeighbors_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvNeighbors_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::Neighbors' class */
    if (PyType_Ready(&PyNs3AodvNeighbors_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Neighbors", (PyObject *) &PyNs3AodvNeighbors_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvNeighborsNeighbor_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvNeighborsNeighbor_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::Neighbors::Neighbor' class */
    if (PyType_Ready(&PyNs3AodvNeighborsNeighbor_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3AodvNeighbors_Type.tp_dict, (char *) "Neighbor", (PyObject *) &PyNs3AodvNeighborsNeighbor_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvQueueEntry_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvQueueEntry_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::QueueEntry' class */
    if (PyType_Ready(&PyNs3AodvQueueEntry_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "QueueEntry", (PyObject *) &PyNs3AodvQueueEntry_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvRequestQueue_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvRequestQueue_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::RequestQueue' class */
    if (PyType_Ready(&PyNs3AodvRequestQueue_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RequestQueue", (PyObject *) &PyNs3AodvRequestQueue_Type);
    /* Register the 'ns3::aodv::RerrHeader' class */
    PyNs3AodvRerrHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3AodvRerrHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RerrHeader", (PyObject *) &PyNs3AodvRerrHeader_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::aodv::RoutingProtocol), &PyNs3AodvRoutingProtocol_Type);
    /* Register the 'ns3::aodv::RoutingProtocol' class */
    
    PyNs3AodvRoutingProtocolMeta_Type.tp_base = Py_TYPE(&PyNs3Ipv4RoutingProtocol_Type);
    /* Some fields need to be manually inheritted from the parent metaclass */
    PyNs3AodvRoutingProtocolMeta_Type.tp_traverse = Py_TYPE(&PyNs3Ipv4RoutingProtocol_Type)->tp_traverse;
    PyNs3AodvRoutingProtocolMeta_Type.tp_clear = Py_TYPE(&PyNs3Ipv4RoutingProtocol_Type)->tp_clear;
    PyNs3AodvRoutingProtocolMeta_Type.tp_is_gc = Py_TYPE(&PyNs3Ipv4RoutingProtocol_Type)->tp_is_gc;
    /* PyType tp_setattro is too restrictive */
    PyNs3AodvRoutingProtocolMeta_Type.tp_setattro = PyObject_GenericSetAttr;
    PyType_Ready(&PyNs3AodvRoutingProtocolMeta_Type);
    
    PyNs3AodvRoutingProtocol_Type.tp_base = &PyNs3Ipv4RoutingProtocol_Type;
    Py_TYPE(&PyNs3AodvRoutingProtocol_Type) = &PyNs3AodvRoutingProtocolMeta_Type;
    if (PyType_Ready(&PyNs3AodvRoutingProtocol_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RoutingProtocol", (PyObject *) &PyNs3AodvRoutingProtocol_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvRoutingTable_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvRoutingTable_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::RoutingTable' class */
    if (PyType_Ready(&PyNs3AodvRoutingTable_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RoutingTable", (PyObject *) &PyNs3AodvRoutingTable_Type);
    PyModule_AddObject(m, (char *) "_PyNs3AodvRoutingTableEntry_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3AodvRoutingTableEntry_wrapper_registry, NULL));
    /* Register the 'ns3::aodv::RoutingTableEntry' class */
    if (PyType_Ready(&PyNs3AodvRoutingTableEntry_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RoutingTableEntry", (PyObject *) &PyNs3AodvRoutingTableEntry_Type);
    /* Register the 'ns3::aodv::RrepAckHeader' class */
    PyNs3AodvRrepAckHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3AodvRrepAckHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RrepAckHeader", (PyObject *) &PyNs3AodvRrepAckHeader_Type);
    /* Register the 'ns3::aodv::RrepHeader' class */
    PyNs3AodvRrepHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3AodvRrepHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RrepHeader", (PyObject *) &PyNs3AodvRrepHeader_Type);
    /* Register the 'ns3::aodv::RreqHeader' class */
    PyNs3AodvRreqHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3AodvRreqHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RreqHeader", (PyObject *) &PyNs3AodvRreqHeader_Type);
    /* Register the 'ns3::aodv::TypeHeader' class */
    PyNs3AodvTypeHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3AodvTypeHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "TypeHeader", (PyObject *) &PyNs3AodvTypeHeader_Type);
    /* Register the 'std::map< ns3::Ipv4Address, unsigned int >' class */
    if (PyType_Ready(&Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___ns3__Ipv4Address__unsigned_int___gt__", (PyObject *) &Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter", (PyObject *) &Pystd__map__lt___ns3__Ipv4Address__unsigned_int___gt__Iter_Type);
    /* Register the 'std::vector< ns3::Ipv4Address >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ipv4Address___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ipv4Address___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ipv4Address___gt__", (PyObject *) &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ipv4Address___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__Ipv4Address___gt__Iter_Type);
    PyModule_AddIntConstant(m, (char *) "AODVTYPE_RREQ", ns3::aodv::AODVTYPE_RREQ);
    PyModule_AddIntConstant(m, (char *) "AODVTYPE_RREP", ns3::aodv::AODVTYPE_RREP);
    PyModule_AddIntConstant(m, (char *) "AODVTYPE_RERR", ns3::aodv::AODVTYPE_RERR);
    PyModule_AddIntConstant(m, (char *) "AODVTYPE_RREP_ACK", ns3::aodv::AODVTYPE_RREP_ACK);
    PyModule_AddIntConstant(m, (char *) "VALID", ns3::aodv::VALID);
    PyModule_AddIntConstant(m, (char *) "INVALID", ns3::aodv::INVALID);
    PyModule_AddIntConstant(m, (char *) "IN_SEARCH", ns3::aodv::IN_SEARCH);
    return m;
}
static PyMethodDef aodv_functions[] = {
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


PyTypeObject *_PyNs3IntToType__0_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__0_wrapper_registry;


PyTypeObject *_PyNs3IntToType__1_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__1_wrapper_registry;


PyTypeObject *_PyNs3IntToType__2_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__2_wrapper_registry;


PyTypeObject *_PyNs3IntToType__3_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__3_wrapper_registry;


PyTypeObject *_PyNs3IntToType__4_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__4_wrapper_registry;


PyTypeObject *_PyNs3IntToType__5_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__5_wrapper_registry;


PyTypeObject *_PyNs3IntToType__6_Type;
std::map<void*, PyObject*> *_PyNs3IntToType__6_wrapper_registry;


PyTypeObject *_PyNs3Ipv4Address_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4Address_wrapper_registry;


PyTypeObject *_PyNs3Ipv4InterfaceAddress_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4InterfaceAddress_wrapper_registry;


PyTypeObject *_PyNs3Ipv4Mask_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4Mask_wrapper_registry;


PyTypeObject *_PyNs3Ipv4RoutingHelper_Type;
std::map<void*, PyObject*> *_PyNs3Ipv4RoutingHelper_wrapper_registry;


PyTypeObject *_PyNs3Ipv6Address_Type;
std::map<void*, PyObject*> *_PyNs3Ipv6Address_wrapper_registry;


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


PyTypeObject *_PyNs3Timer_Type;
std::map<void*, PyObject*> *_PyNs3Timer_wrapper_registry;


PyTypeObject *_PyNs3TimerImpl_Type;
std::map<void*, PyObject*> *_PyNs3TimerImpl_wrapper_registry;


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


PyTypeObject *_PyNs3TriangularRandomVariable_Type;


PyTypeObject *_PyNs3UniformRandomVariable_Type;


PyTypeObject *_PyNs3WeibullRandomVariable_Type;


PyTypeObject *_PyNs3WifiMacHeader_Type;


PyTypeObject *_PyNs3ZetaRandomVariable_Type;


PyTypeObject *_PyNs3ZipfRandomVariable_Type;


PyTypeObject *_PyNs3ArpCache_Type;


PyTypeObject *_PyNs3ArpCacheEntry_Type;
std::map<void*, PyObject*> *_PyNs3ArpCacheEntry_wrapper_registry;


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


PyTypeObject *_PyNs3EnumChecker_Type;


PyTypeObject *_PyNs3EnumValue_Type;


PyTypeObject *_PyNs3ErlangRandomVariable_Type;


PyTypeObject *_PyNs3EventImpl_Type;


PyTypeObject *_PyNs3ExponentialRandomVariable_Type;


PyTypeObject *_PyNs3GammaRandomVariable_Type;


PyTypeObject *_PyNs3Ipv4_Type;


PyTypeObject *_PyNs3Ipv4AddressChecker_Type;


PyTypeObject *_PyNs3Ipv4AddressValue_Type;


PyTypeObject *_PyNs3Ipv4Interface_Type;


PyTypeObject *_PyNs3Ipv4L3Protocol_Type;


PyTypeObject *_PyNs3Ipv4MaskChecker_Type;


PyTypeObject *_PyNs3Ipv4MaskValue_Type;


PyTypeObject *_PyNs3Ipv4MulticastRoute_Type;


PyTypeObject *_PyNs3Ipv4Route_Type;


PyTypeObject *_PyNs3Ipv4RoutingProtocol_Type;


PyTypeObject *_PyNs3Ipv6AddressChecker_Type;


PyTypeObject *_PyNs3Ipv6AddressValue_Type;


PyTypeObject *_PyNs3Ipv6PrefixChecker_Type;


PyTypeObject *_PyNs3Ipv6PrefixValue_Type;


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


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


PyTypeObject *_PyNs3Ipv4ListRouting_Type;




static int
_wrap_PyNs3AodvHelper__tp_init__0(PyNs3AodvHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3AodvHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AodvHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::AodvHelper(*((PyNs3AodvHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3AodvHelper__tp_init__1(PyNs3AodvHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::AodvHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3AodvHelper__tp_init(PyNs3AodvHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3AodvHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3AodvHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3AodvHelper_Create(PyNs3AodvHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4RoutingProtocol > retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    PyNs3Ipv4RoutingProtocol *py_Ipv4RoutingProtocol;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Node_Type, &node)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    retval = self->obj->Create(ns3::Ptr< ns3::Node  > (node_ptr));
    if (!(const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_Ipv4RoutingProtocol = NULL;
    } else {
        py_Ipv4RoutingProtocol = (PyNs3Ipv4RoutingProtocol *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4RoutingProtocol);
    }
    
    if (py_Ipv4RoutingProtocol == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4RoutingProtocol_Type);
        py_Ipv4RoutingProtocol = PyObject_GC_New(PyNs3Ipv4RoutingProtocol, wrapper_type);
        py_Ipv4RoutingProtocol->inst_dict = NULL;
    
        py_Ipv4RoutingProtocol->inst_dict = NULL;
        py_Ipv4RoutingProtocol->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4RoutingProtocol->obj = const_cast<ns3::Ipv4RoutingProtocol *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_Ipv4RoutingProtocol->obj] = (PyObject *) py_Ipv4RoutingProtocol;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4RoutingProtocol);
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvHelper_Set(PyNs3AodvHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    const char *name;
    Py_ssize_t name_len;
    PyNs3AttributeValue *value;
    const char *keywords[] = {"name", "value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &name, &name_len, &PyNs3AttributeValue_Type, &value)) {
        return NULL;
    }
    self->obj->Set(std::string(name, name_len), *((PyNs3AttributeValue *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3AodvHelper_AssignStreams(PyNs3AodvHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    PyNs3NodeContainer *c;
    int64_t stream;
    const char *keywords[] = {"c", "stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!L", (char **) keywords, &PyNs3NodeContainer_Type, &c, &stream)) {
        return NULL;
    }
    retval = self->obj->AssignStreams(*((PyNs3NodeContainer *) c)->obj, stream);
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3AodvHelper__copy__(PyNs3AodvHelper *self)
{

    PyNs3AodvHelper *py_copy;
    py_copy = PyObject_GC_New(PyNs3AodvHelper, &PyNs3AodvHelper_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::AodvHelper(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv4RoutingHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3AodvHelper_methods[] = {
    {(char *) "Create", (PyCFunction) _wrap_PyNs3AodvHelper_Create, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Set", (PyCFunction) _wrap_PyNs3AodvHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3AodvHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3AodvHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3AodvHelper__tp_clear(PyNs3AodvHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::AodvHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3AodvHelper__tp_traverse(PyNs3AodvHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3AodvHelper__tp_dealloc(PyNs3AodvHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv4RoutingHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv4RoutingHelper_wrapper_registry.end()) {
        PyNs3Ipv4RoutingHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3AodvHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3AodvHelper__tp_richcompare (PyNs3AodvHelper *PYBINDGEN_UNUSED(self), PyNs3AodvHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3AodvHelper_Type)) {
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

PyTypeObject PyNs3AodvHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.AodvHelper",            /* tp_name */
    sizeof(PyNs3AodvHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3AodvHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3AodvHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3AodvHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3AodvHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3AodvHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3AodvHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3AodvHelper__tp_init,             /* tp_init */
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
Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_clear(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_traverse(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_dealloc(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ *self)
{
    Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *iter = PyObject_GC_New(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter, &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::list< ns3::Ptr< ns3::Packet > >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iter(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iternext(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter *self)
{
    PyObject *py_retval;
    std::list< ns3::Ptr< ns3::Packet > >::iterator iter;
    PyNs3Packet *py_Packet;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    if (!(const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter))))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter))));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_Packet = NULL;
    } else {
        py_Packet = (PyNs3Packet *) wrapper_lookup_iter->second;
        Py_INCREF(py_Packet);
    }
    
    if (py_Packet == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Packet_Ns3Empty_Ns3DefaultDeleter__lt__ns3Packet__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter))))), &PyNs3Packet_Type);
        py_Packet = PyObject_New(PyNs3Packet, wrapper_type);
    
        py_Packet->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter)))->Ref();
        py_Packet->obj = const_cast<ns3::Packet *> (ns3::PeekPointer ((*iter)));
        PyNs3Empty_wrapper_registry[(void *) py_Packet->obj] = (PyObject *) py_Packet;
    }
    py_retval = Py_BuildValue((char *) "N", py_Packet);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Ptr__lt___ns3__Packet___gt__(PyObject *value, ns3::Ptr< ns3::Packet > *address)
{
    PyObject *py_retval;
    PyNs3Packet *tmp_Packet;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Packet_Type, &tmp_Packet)) {
        Py_DECREF(py_retval);
        return 0;
    }
    // dangerous!
    *address = ns3::Ptr< ns3::Packet  > (tmp_Packet->obj);
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__(PyObject *arg, std::list< ns3::Ptr< ns3::Packet > > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type)) {
        *container = *((Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ptr< ns3::Packet > item;
            if (!_wrap_convert_py2c__ns3__Ptr__lt___ns3__Packet___gt__(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ instance, or a list of ns3::Ptr< ns3::Packet >");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_init(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::list< ns3::Ptr< ns3::Packet > >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "aodv.Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter__tp_iternext,     /* tp_iternext */
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
    (char *) "aodv.Std__map__lt___unsigned_int__unsigned_int___gt__",            /* tp_name */
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
    (char *) "aodv.Std__map__lt___unsigned_int__unsigned_int___gt__Iter",            /* tp_name */
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
static struct PyModuleDef aodv_moduledef = {
    PyModuleDef_HEAD_INIT,
    "aodv",
    NULL,
    -1,
    aodv_functions,
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


MOD_INIT(aodv)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&aodv_moduledef);
    #else
    m = Py_InitModule3((char *) "aodv", aodv_functions, NULL);
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
    /* Import the 'ns3::IntToType< 0 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__0_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__0");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__0_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__0_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__0_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::IntToType< 1 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__1_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__1");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__1_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__1_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__1_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::IntToType< 2 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__2_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__2");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__2_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__2_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__2_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::IntToType< 3 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__3_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__3");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__3_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__3_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__3_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::IntToType< 4 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__4_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__4");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__4_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__4_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__4_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::IntToType< 5 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__5_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__5");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__5_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__5_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__5_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::IntToType< 6 >' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3IntToType__6_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "IntToType__6");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3IntToType__6_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3IntToType__6_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3IntToType__6_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::Ipv4RoutingHelper' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4RoutingHelper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4RoutingHelper");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Ipv4RoutingHelper_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Ipv4RoutingHelper_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Ipv4RoutingHelper_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::Timer' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Timer_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Timer");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3Timer_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3Timer_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3Timer_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
    }
    /* Import the 'ns3::TimerImpl' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3TimerImpl_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "TimerImpl");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3TimerImpl_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3TimerImpl_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3TimerImpl_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::WifiMacHeader' class from module 'ns.wifi' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.wifi");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3WifiMacHeader_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "WifiMacHeader");
    
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
    /* Import the 'ns3::ArpCache' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ArpCache_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "ArpCache");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Import the 'ns3::ArpCache::Entry' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3ArpCacheEntry_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Entry");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3ArpCacheEntry_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3ArpCacheEntry_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3ArpCacheEntry_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
            Py_DECREF(_cobj);
        }
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
    /* Import the 'ns3::Ipv4Interface' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4Interface_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4Interface");
    
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
    /* Import the 'ns3::Ipv4ListRouting' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4ListRouting_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4ListRouting");
    
        if (PyErr_Occurred()) PyErr_Clear();
    }
    /* Register the 'ns3::AodvHelper' class */
    PyNs3AodvHelper_Type.tp_base = &PyNs3Ipv4RoutingHelper_Type;
    if (PyType_Ready(&PyNs3AodvHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "AodvHelper", (PyObject *) &PyNs3AodvHelper_Type);
    /* Register the 'std::list< ns3::Ptr< ns3::Packet > >' class */
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter", (PyObject *) &Pystd__list__lt___ns3__Ptr__lt___ns3__Packet___gt_____gt__Iter_Type);
    /* Register the 'std::map< unsigned int, unsigned int >' class */
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__Iter", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type);
    submodule = initaodv_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initaodv_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initaodv_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    submodule = initaodv_aodv();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "aodv", submodule);
    return MOD_RETURN(m);
}
