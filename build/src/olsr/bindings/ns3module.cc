#include "ns3module.h"
static PyMethodDef olsr_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef olsr_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "olsr.FatalImpl",
    NULL,
    -1,
    olsr_FatalImpl_functions,
};
#endif

static PyObject *
initolsr_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&olsr_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "olsr.FatalImpl", olsr_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef olsr_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef olsr_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "olsr.Hash.Function",
    NULL,
    -1,
    olsr_Hash_Function_functions,
};
#endif

static PyObject *
initolsr_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&olsr_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "olsr.Hash.Function", olsr_Hash_Function_functions, NULL);
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
static PyMethodDef olsr_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef olsr_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "olsr.Hash",
    NULL,
    -1,
    olsr_Hash_functions,
};
#endif

static PyObject *
initolsr_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&olsr_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "olsr.Hash", olsr_Hash_functions, NULL);
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
    submodule = initolsr_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef olsr_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef olsr_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "olsr.TracedValueCallback",
    NULL,
    -1,
    olsr_TracedValueCallback_functions,
};
#endif

static PyObject *
initolsr_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&olsr_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "olsr.TracedValueCallback", olsr_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
/* --- module functions --- */


PyObject *
_wrap_olsr_olsr_SecondsToEmf(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint8_t retval;
    double seconds;
    const char *keywords[] = {"seconds", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &seconds)) {
        return NULL;
    }
    retval = ns3::olsr::SecondsToEmf(seconds);
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}
PyObject * _wrap_olsr_olsr_SecondsToEmf(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);


PyObject *
_wrap_olsr_olsr_EmfToSeconds(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    int emf;
    const char *keywords[] = {"emf", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &emf)) {
        return NULL;
    }
    if (emf > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    retval = ns3::olsr::EmfToSeconds(emf);
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}
PyObject * _wrap_olsr_olsr_EmfToSeconds(PyObject * PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs);

static PyMethodDef olsr_olsr_functions[] = {
    {(char *) "SecondsToEmf", (PyCFunction) _wrap_olsr_olsr_SecondsToEmf, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EmfToSeconds", (PyCFunction) _wrap_olsr_olsr_EmfToSeconds, METH_KEYWORDS|METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


std::map<void*, PyObject*> PyNs3OlsrAssociation_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrAssociation__get_netmask(PyNs3OlsrAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(self->obj->netmask);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociation__set_netmask(PyNs3OlsrAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *tmp_Ipv4Mask;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Mask_Type, &tmp_Ipv4Mask)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->netmask = *tmp_Ipv4Mask->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociation__get_networkAddr(PyNs3OlsrAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->networkAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociation__set_networkAddr(PyNs3OlsrAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->networkAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrAssociation__getsets[] = {
    {
        (char*) "netmask", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociation__get_netmask, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociation__set_netmask, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "networkAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociation__get_networkAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociation__set_networkAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrAssociation__tp_init__0(PyNs3OlsrAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::Association();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrAssociation__tp_init__1(PyNs3OlsrAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrAssociation *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociation_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::Association(*((PyNs3OlsrAssociation *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrAssociation__tp_init(PyNs3OlsrAssociation *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrAssociation__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrAssociation__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrAssociation__copy__(PyNs3OlsrAssociation *self)
{

    PyNs3OlsrAssociation *py_copy;
    py_copy = PyObject_New(PyNs3OlsrAssociation, &PyNs3OlsrAssociation_Type);
    py_copy->obj = new ns3::olsr::Association(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrAssociation_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrAssociation_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrAssociation__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrAssociation__tp_dealloc(PyNs3OlsrAssociation *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrAssociation_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrAssociation_wrapper_registry.end()) {
        PyNs3OlsrAssociation_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::Association *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrAssociation__tp_str(PyNs3OlsrAssociation *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrAssociation__tp_richcompare (PyNs3OlsrAssociation *PYBINDGEN_UNUSED(self), PyNs3OlsrAssociation *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrAssociation_Type)) {
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

PyTypeObject PyNs3OlsrAssociation_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Association",            /* tp_name */
    sizeof(PyNs3OlsrAssociation),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrAssociation__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrAssociation__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrAssociation__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrAssociation_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrAssociation__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrAssociation__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrAssociationTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_expirationTime(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_expirationTime(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_gatewayAddr(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->gatewayAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_gatewayAddr(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->gatewayAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_netmask(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(self->obj->netmask);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_netmask(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *tmp_Ipv4Mask;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Mask_Type, &tmp_Ipv4Mask)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->netmask = *tmp_Ipv4Mask->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrAssociationTuple__get_networkAddr(PyNs3OlsrAssociationTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->networkAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrAssociationTuple__set_networkAddr(PyNs3OlsrAssociationTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->networkAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrAssociationTuple__getsets[] = {
    {
        (char*) "networkAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_networkAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_networkAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "gatewayAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_gatewayAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_gatewayAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "netmask", /* attribute name */
        (getter) _wrap_PyNs3OlsrAssociationTuple__get_netmask, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrAssociationTuple__set_netmask, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrAssociationTuple__tp_init__0(PyNs3OlsrAssociationTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::AssociationTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrAssociationTuple__tp_init__1(PyNs3OlsrAssociationTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrAssociationTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociationTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::AssociationTuple(*((PyNs3OlsrAssociationTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrAssociationTuple__tp_init(PyNs3OlsrAssociationTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrAssociationTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrAssociationTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrAssociationTuple__copy__(PyNs3OlsrAssociationTuple *self)
{

    PyNs3OlsrAssociationTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrAssociationTuple, &PyNs3OlsrAssociationTuple_Type);
    py_copy->obj = new ns3::olsr::AssociationTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrAssociationTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrAssociationTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrAssociationTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrAssociationTuple__tp_dealloc(PyNs3OlsrAssociationTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrAssociationTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrAssociationTuple_wrapper_registry.end()) {
        PyNs3OlsrAssociationTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::AssociationTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrAssociationTuple__tp_str(PyNs3OlsrAssociationTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrAssociationTuple__tp_richcompare (PyNs3OlsrAssociationTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrAssociationTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrAssociationTuple_Type)) {
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

PyTypeObject PyNs3OlsrAssociationTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.AssociationTuple",            /* tp_name */
    sizeof(PyNs3OlsrAssociationTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrAssociationTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrAssociationTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrAssociationTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrAssociationTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrAssociationTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrAssociationTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrDuplicateTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_address(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->address);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_address(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->address = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_expirationTime(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_expirationTime(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_ifaceList(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->ifaceList);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_ifaceList(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->ifaceList)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_retransmitted(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(self->obj->retransmitted));
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_retransmitted(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyObject *py_boolretval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O", &py_boolretval)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->retransmitted = PyObject_IsTrue(py_boolretval);
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrDuplicateTuple__get_sequenceNumber(PyNs3OlsrDuplicateTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sequenceNumber);
    return py_retval;
}
static int _wrap_PyNs3OlsrDuplicateTuple__set_sequenceNumber(PyNs3OlsrDuplicateTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->sequenceNumber = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrDuplicateTuple__getsets[] = {
    {
        (char*) "retransmitted", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_retransmitted, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_retransmitted, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "ifaceList", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_ifaceList, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_ifaceList, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sequenceNumber", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_sequenceNumber, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_sequenceNumber, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "address", /* attribute name */
        (getter) _wrap_PyNs3OlsrDuplicateTuple__get_address, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrDuplicateTuple__set_address, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrDuplicateTuple__tp_init__0(PyNs3OlsrDuplicateTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::DuplicateTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrDuplicateTuple__tp_init__1(PyNs3OlsrDuplicateTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrDuplicateTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrDuplicateTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::DuplicateTuple(*((PyNs3OlsrDuplicateTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrDuplicateTuple__tp_init(PyNs3OlsrDuplicateTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrDuplicateTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrDuplicateTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrDuplicateTuple__copy__(PyNs3OlsrDuplicateTuple *self)
{

    PyNs3OlsrDuplicateTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrDuplicateTuple, &PyNs3OlsrDuplicateTuple_Type);
    py_copy->obj = new ns3::olsr::DuplicateTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrDuplicateTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrDuplicateTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrDuplicateTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrDuplicateTuple__tp_dealloc(PyNs3OlsrDuplicateTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrDuplicateTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrDuplicateTuple_wrapper_registry.end()) {
        PyNs3OlsrDuplicateTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::DuplicateTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrDuplicateTuple__tp_richcompare (PyNs3OlsrDuplicateTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrDuplicateTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrDuplicateTuple_Type)) {
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

PyTypeObject PyNs3OlsrDuplicateTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.DuplicateTuple",            /* tp_name */
    sizeof(PyNs3OlsrDuplicateTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrDuplicateTuple__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrDuplicateTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrDuplicateTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrDuplicateTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrDuplicateTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrIfaceAssocTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrIfaceAssocTuple__get_ifaceAddr(PyNs3OlsrIfaceAssocTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->ifaceAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrIfaceAssocTuple__set_ifaceAddr(PyNs3OlsrIfaceAssocTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->ifaceAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrIfaceAssocTuple__get_mainAddr(PyNs3OlsrIfaceAssocTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->mainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrIfaceAssocTuple__set_mainAddr(PyNs3OlsrIfaceAssocTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->mainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrIfaceAssocTuple__get_time(PyNs3OlsrIfaceAssocTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->time);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrIfaceAssocTuple__set_time(PyNs3OlsrIfaceAssocTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->time = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrIfaceAssocTuple__getsets[] = {
    {
        (char*) "ifaceAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrIfaceAssocTuple__get_ifaceAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrIfaceAssocTuple__set_ifaceAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "mainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrIfaceAssocTuple__get_mainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrIfaceAssocTuple__set_mainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "time", /* attribute name */
        (getter) _wrap_PyNs3OlsrIfaceAssocTuple__get_time, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrIfaceAssocTuple__set_time, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrIfaceAssocTuple__tp_init__0(PyNs3OlsrIfaceAssocTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::IfaceAssocTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrIfaceAssocTuple__tp_init__1(PyNs3OlsrIfaceAssocTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrIfaceAssocTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrIfaceAssocTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::IfaceAssocTuple(*((PyNs3OlsrIfaceAssocTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrIfaceAssocTuple__tp_init(PyNs3OlsrIfaceAssocTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrIfaceAssocTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrIfaceAssocTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrIfaceAssocTuple__copy__(PyNs3OlsrIfaceAssocTuple *self)
{

    PyNs3OlsrIfaceAssocTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrIfaceAssocTuple, &PyNs3OlsrIfaceAssocTuple_Type);
    py_copy->obj = new ns3::olsr::IfaceAssocTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrIfaceAssocTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrIfaceAssocTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrIfaceAssocTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrIfaceAssocTuple__tp_dealloc(PyNs3OlsrIfaceAssocTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrIfaceAssocTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrIfaceAssocTuple_wrapper_registry.end()) {
        PyNs3OlsrIfaceAssocTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::IfaceAssocTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrIfaceAssocTuple__tp_str(PyNs3OlsrIfaceAssocTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrIfaceAssocTuple__tp_richcompare (PyNs3OlsrIfaceAssocTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrIfaceAssocTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrIfaceAssocTuple_Type)) {
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

PyTypeObject PyNs3OlsrIfaceAssocTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.IfaceAssocTuple",            /* tp_name */
    sizeof(PyNs3OlsrIfaceAssocTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrIfaceAssocTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrIfaceAssocTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrIfaceAssocTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrIfaceAssocTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrIfaceAssocTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrIfaceAssocTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrLinkTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_asymTime(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->asymTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_asymTime(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->asymTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_localIfaceAddr(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->localIfaceAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_localIfaceAddr(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->localIfaceAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_neighborIfaceAddr(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->neighborIfaceAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_neighborIfaceAddr(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->neighborIfaceAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_symTime(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->symTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_symTime(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->symTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrLinkTuple__get_time(PyNs3OlsrLinkTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->time);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrLinkTuple__set_time(PyNs3OlsrLinkTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->time = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrLinkTuple__getsets[] = {
    {
        (char*) "neighborIfaceAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_neighborIfaceAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_neighborIfaceAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "asymTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_asymTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_asymTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "symTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_symTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_symTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "localIfaceAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_localIfaceAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_localIfaceAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "time", /* attribute name */
        (getter) _wrap_PyNs3OlsrLinkTuple__get_time, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrLinkTuple__set_time, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrLinkTuple__tp_init__0(PyNs3OlsrLinkTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::LinkTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrLinkTuple__tp_init__1(PyNs3OlsrLinkTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrLinkTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrLinkTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::LinkTuple(*((PyNs3OlsrLinkTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrLinkTuple__tp_init(PyNs3OlsrLinkTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrLinkTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrLinkTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrLinkTuple__copy__(PyNs3OlsrLinkTuple *self)
{

    PyNs3OlsrLinkTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrLinkTuple, &PyNs3OlsrLinkTuple_Type);
    py_copy->obj = new ns3::olsr::LinkTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrLinkTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrLinkTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrLinkTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrLinkTuple__tp_dealloc(PyNs3OlsrLinkTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrLinkTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrLinkTuple_wrapper_registry.end()) {
        PyNs3OlsrLinkTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::LinkTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrLinkTuple__tp_str(PyNs3OlsrLinkTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrLinkTuple__tp_richcompare (PyNs3OlsrLinkTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrLinkTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrLinkTuple_Type)) {
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

PyTypeObject PyNs3OlsrLinkTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.LinkTuple",            /* tp_name */
    sizeof(PyNs3OlsrLinkTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrLinkTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrLinkTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrLinkTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrLinkTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrLinkTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrLinkTuple__tp_init,             /* tp_init */
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
_wrap_PyNs3OlsrMessageHeader__tp_init__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader(*((PyNs3OlsrMessageHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeader__tp_init__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeader__tp_init(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetVTime(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetVTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHna__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHna *py_Hna;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hna & retval = self->obj->GetHna();
    py_Hna = PyObject_New(PyNs3OlsrMessageHeaderHna, &PyNs3OlsrMessageHeaderHna_Type);
    py_Hna->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hna->obj = new ns3::olsr::MessageHeader::Hna(retval);
    PyNs3OlsrMessageHeaderHna_wrapper_registry[(void *) py_Hna->obj] = (PyObject *) py_Hna;
    py_retval = Py_BuildValue((char *) "N", py_Hna);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHna__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHna *py_Hna;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hna const & retval = self->obj->GetHna();
    py_Hna = PyObject_New(PyNs3OlsrMessageHeaderHna, &PyNs3OlsrMessageHeaderHna_Type);
    py_Hna->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hna->obj = new ns3::olsr::MessageHeader::Hna(retval);
    PyNs3OlsrMessageHeaderHna_wrapper_registry[(void *) py_Hna->obj] = (PyObject *) py_Hna;
    py_retval = Py_BuildValue((char *) "N", py_Hna);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetHna(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetHna__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetHna__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_SetMessageType(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::MessageHeader::MessageType messageType;
    const char *keywords[] = {"messageType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &messageType)) {
        return NULL;
    }
    self->obj->SetMessageType(messageType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMessageSequenceNumber(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetMessageSequenceNumber();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_Deserialize(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrMessageHeader_GetMid__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderMid *py_Mid;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Mid & retval = self->obj->GetMid();
    py_Mid = PyObject_New(PyNs3OlsrMessageHeaderMid, &PyNs3OlsrMessageHeaderMid_Type);
    py_Mid->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mid->obj = new ns3::olsr::MessageHeader::Mid(retval);
    PyNs3OlsrMessageHeaderMid_wrapper_registry[(void *) py_Mid->obj] = (PyObject *) py_Mid;
    py_retval = Py_BuildValue((char *) "N", py_Mid);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMid__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderMid *py_Mid;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Mid const & retval = self->obj->GetMid();
    py_Mid = PyObject_New(PyNs3OlsrMessageHeaderMid, &PyNs3OlsrMessageHeaderMid_Type);
    py_Mid->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Mid->obj = new ns3::olsr::MessageHeader::Mid(retval);
    PyNs3OlsrMessageHeaderMid_wrapper_registry[(void *) py_Mid->obj] = (PyObject *) py_Mid;
    py_retval = Py_BuildValue((char *) "N", py_Mid);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetMid(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetMid__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetMid__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetOriginatorAddress(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    ns3::Ipv4Address retval = self->obj->GetOriginatorAddress();
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(retval);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_Serialize(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrMessageHeader_GetTc__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderTc *py_Tc;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Tc & retval = self->obj->GetTc();
    py_Tc = PyObject_New(PyNs3OlsrMessageHeaderTc, &PyNs3OlsrMessageHeaderTc_Type);
    py_Tc->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Tc->obj = new ns3::olsr::MessageHeader::Tc(retval);
    PyNs3OlsrMessageHeaderTc_wrapper_registry[(void *) py_Tc->obj] = (PyObject *) py_Tc;
    py_retval = Py_BuildValue((char *) "N", py_Tc);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetTc__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderTc *py_Tc;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Tc const & retval = self->obj->GetTc();
    py_Tc = PyObject_New(PyNs3OlsrMessageHeaderTc, &PyNs3OlsrMessageHeaderTc_Type);
    py_Tc->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Tc->obj = new ns3::olsr::MessageHeader::Tc(retval);
    PyNs3OlsrMessageHeaderTc_wrapper_registry[(void *) py_Tc->obj] = (PyObject *) py_Tc;
    py_retval = Py_BuildValue((char *) "N", py_Tc);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetTc(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetTc__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetTc__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetTimeToLive(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetTimeToLive();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetVTime(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *time;
    const char *keywords[] = {"time", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &time)) {
        return NULL;
    }
    self->obj->SetVTime(*((PyNs3Time *) time)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetMessageSequenceNumber(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int messageSequenceNumber;
    const char *keywords[] = {"messageSequenceNumber", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &messageSequenceNumber)) {
        return NULL;
    }
    if (messageSequenceNumber > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetMessageSequenceNumber(messageSequenceNumber);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetTimeToLive(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int timeToLive;
    const char *keywords[] = {"timeToLive", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &timeToLive)) {
        return NULL;
    }
    if (timeToLive > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetTimeToLive(timeToLive);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetOriginatorAddress(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *originatorAddress;
    const char *keywords[] = {"originatorAddress", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &originatorAddress)) {
        return NULL;
    }
    self->obj->SetOriginatorAddress(*((PyNs3Ipv4Address *) originatorAddress)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetInstanceTypeId(PyNs3OlsrMessageHeader *self)
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
_wrap_PyNs3OlsrMessageHeader_GetSerializedSize(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_SetHopCount(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int hopCount;
    const char *keywords[] = {"hopCount", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &hopCount)) {
        return NULL;
    }
    if (hopCount > 0xff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetHopCount(hopCount);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetMessageType(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    ns3::olsr::MessageHeader::MessageType retval;
    
    retval = self->obj->GetMessageType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHello__0(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHello *py_Hello;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hello & retval = self->obj->GetHello();
    py_Hello = PyObject_New(PyNs3OlsrMessageHeaderHello, &PyNs3OlsrMessageHeaderHello_Type);
    py_Hello->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hello->obj = new ns3::olsr::MessageHeader::Hello(retval);
    PyNs3OlsrMessageHeaderHello_wrapper_registry[(void *) py_Hello->obj] = (PyObject *) py_Hello;
    py_retval = Py_BuildValue((char *) "N", py_Hello);
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHello__1(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *keywords[] = {NULL};
    PyNs3OlsrMessageHeaderHello *py_Hello;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "", (char **) keywords)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    ns3::olsr::MessageHeader::Hello const & retval = self->obj->GetHello();
    py_Hello = PyObject_New(PyNs3OlsrMessageHeaderHello, &PyNs3OlsrMessageHeaderHello_Type);
    py_Hello->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Hello->obj = new ns3::olsr::MessageHeader::Hello(retval);
    PyNs3OlsrMessageHeaderHello_wrapper_registry[(void *) py_Hello->obj] = (PyObject *) py_Hello;
    py_retval = Py_BuildValue((char *) "N", py_Hello);
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrMessageHeader_GetHello(PyNs3OlsrMessageHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeader_GetHello__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeader_GetHello__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::olsr::MessageHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeader_GetHopCount(PyNs3OlsrMessageHeader *self)
{
    PyObject *py_retval;
    uint8_t retval;
    
    retval = self->obj->GetHopCount();
    py_retval = Py_BuildValue((char *) "i", (int)retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeader__copy__(PyNs3OlsrMessageHeader *self)
{

    PyNs3OlsrMessageHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrMessageHeader, &PyNs3OlsrMessageHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::olsr::MessageHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeader_methods[] = {
    {(char *) "GetVTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetVTime, METH_NOARGS, NULL },
    {(char *) "GetHna", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetHna, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMessageType", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetMessageType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMessageSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetMessageSequenceNumber, METH_NOARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMid", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetMid, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetOriginatorAddress", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetOriginatorAddress, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTc", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetTc, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTimeToLive", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetTimeToLive, METH_NOARGS, NULL },
    {(char *) "SetVTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetVTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMessageSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetMessageSequenceNumber, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTimeToLive", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetTimeToLive, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetOriginatorAddress", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetOriginatorAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "SetHopCount", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_SetHopCount, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMessageType", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetMessageType, METH_NOARGS, NULL },
    {(char *) "GetHello", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetHello, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetHopCount", (PyCFunction) _wrap_PyNs3OlsrMessageHeader_GetHopCount, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrMessageHeader__tp_clear(PyNs3OlsrMessageHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::olsr::MessageHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3OlsrMessageHeader__tp_traverse(PyNs3OlsrMessageHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3OlsrMessageHeader__tp_dealloc(PyNs3OlsrMessageHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrMessageHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrMessageHeader__tp_str(PyNs3OlsrMessageHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrMessageHeader__tp_richcompare (PyNs3OlsrMessageHeader *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeader_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrMessageHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3OlsrMessageHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrMessageHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrMessageHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeader__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHello_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHello__get_hTime(PyNs3OlsrMessageHeaderHello *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->hTime);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHello__set_hTime(PyNs3OlsrMessageHeaderHello *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->hTime = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHello__get_linkMessages(PyNs3OlsrMessageHeaderHello *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage > retval;
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__;
    
    py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ = PyObject_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type);
    py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__->obj = new std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >(self->obj->linkMessages);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHello__set_linkMessages(PyNs3OlsrMessageHeaderHello *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__, &self->obj->linkMessages)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHello__get_willingness(PyNs3OlsrMessageHeaderHello *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->willingness);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHello__set_willingness(PyNs3OlsrMessageHeaderHello *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->willingness = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHello__getsets[] = {
    {
        (char*) "linkMessages", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHello__get_linkMessages, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHello__set_linkMessages, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "willingness", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHello__get_willingness, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHello__set_willingness, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "hTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHello__get_hTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHello__set_hTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHello__tp_init__0(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hello();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHello__tp_init__1(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHello *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHello_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hello(*((PyNs3OlsrMessageHeaderHello *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHello__tp_init(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHello__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHello__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHello_GetSerializedSize(PyNs3OlsrMessageHeaderHello *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_Serialize(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrMessageHeaderHello_SetHTime(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Time *time;
    const char *keywords[] = {"time", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Time_Type, &time)) {
        return NULL;
    }
    self->obj->SetHTime(*((PyNs3Time *) time)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_Deserialize(PyNs3OlsrMessageHeaderHello *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHello_GetHTime(PyNs3OlsrMessageHeaderHello *self)
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    ns3::Time retval = self->obj->GetHTime();
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(retval);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderHello__copy__(PyNs3OlsrMessageHeaderHello *self)
{

    PyNs3OlsrMessageHeaderHello *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHello, &PyNs3OlsrMessageHeaderHello_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hello(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHello_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHello_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetHTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_SetHTime, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetHTime", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello_GetHTime, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHello__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHello__tp_dealloc(PyNs3OlsrMessageHeaderHello *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHello_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHello_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHello_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hello *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHello__tp_richcompare (PyNs3OlsrMessageHeaderHello *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHello *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHello_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHello_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader.Hello",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHello),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHello__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHello__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHello_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHello__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHello__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_linkCode(PyNs3OlsrMessageHeaderHelloLinkMessage *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->linkCode);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_linkCode(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->linkCode = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_neighborInterfaceAddresses(PyNs3OlsrMessageHeaderHelloLinkMessage *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->neighborInterfaceAddresses);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_neighborInterfaceAddresses(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->neighborInterfaceAddresses)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHelloLinkMessage__getsets[] = {
    {
        (char*) "neighborInterfaceAddresses", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_neighborInterfaceAddresses, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_neighborInterfaceAddresses, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "linkCode", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__get_linkCode, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__set_linkCode, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__0(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__1(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHelloLinkMessage *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHelloLinkMessage_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage(*((PyNs3OlsrMessageHeaderHelloLinkMessage *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init(PyNs3OlsrMessageHeaderHelloLinkMessage *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__copy__(PyNs3OlsrMessageHeaderHelloLinkMessage *self)
{

    PyNs3OlsrMessageHeaderHelloLinkMessage *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHelloLinkMessage, &PyNs3OlsrMessageHeaderHelloLinkMessage_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHelloLinkMessage_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_dealloc(PyNs3OlsrMessageHeaderHelloLinkMessage *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hello::LinkMessage *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_richcompare (PyNs3OlsrMessageHeaderHelloLinkMessage *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHelloLinkMessage *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHelloLinkMessage_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHelloLinkMessage_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader.Hello.LinkMessage",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHelloLinkMessage),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHelloLinkMessage_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHelloLinkMessage__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHelloLinkMessage__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHna_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHna__get_associations(PyNs3OlsrMessageHeaderHna *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hna::Association > retval;
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__;
    
    py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ = PyObject_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type);
    py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__->obj = new std::vector< ns3::olsr::MessageHeader::Hna::Association >(self->obj->associations);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHna__set_associations(PyNs3OlsrMessageHeaderHna *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hna::Association > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__, &self->obj->associations)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHna__getsets[] = {
    {
        (char*) "associations", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHna__get_associations, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHna__set_associations, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHna__tp_init__0(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hna();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHna__tp_init__1(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHna *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHna_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hna(*((PyNs3OlsrMessageHeaderHna *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHna__tp_init(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHna__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHna__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHna_GetSerializedSize(PyNs3OlsrMessageHeaderHna *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderHna_Serialize(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrMessageHeaderHna_Deserialize(PyNs3OlsrMessageHeaderHna *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderHna__copy__(PyNs3OlsrMessageHeaderHna *self)
{

    PyNs3OlsrMessageHeaderHna *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHna, &PyNs3OlsrMessageHeaderHna_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hna(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHna_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHna_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHna__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHna__tp_dealloc(PyNs3OlsrMessageHeaderHna *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHna_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHna_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHna_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hna *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHna__tp_richcompare (PyNs3OlsrMessageHeaderHna *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHna *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHna_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHna_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader.Hna",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHna),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHna__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHna__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHna_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHna__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHna__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_address(PyNs3OlsrMessageHeaderHnaAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->address);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_address(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->address = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_mask(PyNs3OlsrMessageHeaderHnaAssociation *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *py_Ipv4Mask;
    
    py_Ipv4Mask = PyObject_New(PyNs3Ipv4Mask, &PyNs3Ipv4Mask_Type);
    py_Ipv4Mask->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Mask->obj = new ns3::Ipv4Mask(self->obj->mask);
    PyNs3Ipv4Mask_wrapper_registry[(void *) py_Ipv4Mask->obj] = (PyObject *) py_Ipv4Mask;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Mask);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_mask(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Mask *tmp_Ipv4Mask;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Mask_Type, &tmp_Ipv4Mask)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->mask = *tmp_Ipv4Mask->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderHnaAssociation__getsets[] = {
    {
        (char*) "mask", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_mask, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_mask, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "address", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__get_address, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__set_address, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__0(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Hna::Association();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__1(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderHnaAssociation *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderHnaAssociation_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Hna::Association(*((PyNs3OlsrMessageHeaderHnaAssociation *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init(PyNs3OlsrMessageHeaderHnaAssociation *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__copy__(PyNs3OlsrMessageHeaderHnaAssociation *self)
{

    PyNs3OlsrMessageHeaderHnaAssociation *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderHnaAssociation, &PyNs3OlsrMessageHeaderHnaAssociation_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Hna::Association(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderHnaAssociation_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderHnaAssociation__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_dealloc(PyNs3OlsrMessageHeaderHnaAssociation *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Hna::Association *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_richcompare (PyNs3OlsrMessageHeaderHnaAssociation *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderHnaAssociation *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderHnaAssociation_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderHnaAssociation_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader.Hna.Association",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderHnaAssociation),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderHnaAssociation_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderHnaAssociation__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderHnaAssociation__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderMid_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderMid__get_interfaceAddresses(PyNs3OlsrMessageHeaderMid *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->interfaceAddresses);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderMid__set_interfaceAddresses(PyNs3OlsrMessageHeaderMid *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->interfaceAddresses)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderMid__getsets[] = {
    {
        (char*) "interfaceAddresses", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderMid__get_interfaceAddresses, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderMid__set_interfaceAddresses, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderMid__tp_init__0(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Mid();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderMid__tp_init__1(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderMid *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderMid_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Mid(*((PyNs3OlsrMessageHeaderMid *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderMid__tp_init(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderMid__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderMid__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderMid_GetSerializedSize(PyNs3OlsrMessageHeaderMid *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderMid_Serialize(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrMessageHeaderMid_Deserialize(PyNs3OlsrMessageHeaderMid *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderMid__copy__(PyNs3OlsrMessageHeaderMid *self)
{

    PyNs3OlsrMessageHeaderMid *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderMid, &PyNs3OlsrMessageHeaderMid_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Mid(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderMid_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderMid_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderMid__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderMid__tp_dealloc(PyNs3OlsrMessageHeaderMid *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderMid_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderMid_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderMid_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Mid *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderMid__tp_richcompare (PyNs3OlsrMessageHeaderMid *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderMid *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderMid_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderMid_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader.Mid",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderMid),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderMid__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderMid__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderMid_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderMid__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderMid__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMessageHeaderTc_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMessageHeaderTc__get_ansn(PyNs3OlsrMessageHeaderTc *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->ansn);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderTc__set_ansn(PyNs3OlsrMessageHeaderTc *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->ansn = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMessageHeaderTc__get_neighborAddresses(PyNs3OlsrMessageHeaderTc *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(self->obj->neighborAddresses);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}
static int _wrap_PyNs3OlsrMessageHeaderTc__set_neighborAddresses(PyNs3OlsrMessageHeaderTc *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    std::vector< ns3::Ipv4Address > retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O&", _wrap_convert_py2c__std__vector__lt___ns3__Ipv4Address___gt__, &self->obj->neighborAddresses)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMessageHeaderTc__getsets[] = {
    {
        (char*) "ansn", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderTc__get_ansn, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderTc__set_ansn, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "neighborAddresses", /* attribute name */
        (getter) _wrap_PyNs3OlsrMessageHeaderTc__get_neighborAddresses, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMessageHeaderTc__set_neighborAddresses, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMessageHeaderTc__tp_init__0(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MessageHeader::Tc();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMessageHeaderTc__tp_init__1(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMessageHeaderTc *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMessageHeaderTc_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MessageHeader::Tc(*((PyNs3OlsrMessageHeaderTc *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMessageHeaderTc__tp_init(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMessageHeaderTc__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMessageHeaderTc__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMessageHeaderTc_GetSerializedSize(PyNs3OlsrMessageHeaderTc *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrMessageHeaderTc_Serialize(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrMessageHeaderTc_Deserialize(PyNs3OlsrMessageHeaderTc *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    uint32_t retval;
    PyNs3BufferIterator *start;
    unsigned int messageSize;
    const char *keywords[] = {"start", "messageSize", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3BufferIterator_Type, &start, &messageSize)) {
        return NULL;
    }
    retval = self->obj->Deserialize(*((PyNs3BufferIterator *) start)->obj, messageSize);
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrMessageHeaderTc__copy__(PyNs3OlsrMessageHeaderTc *self)
{

    PyNs3OlsrMessageHeaderTc *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMessageHeaderTc, &PyNs3OlsrMessageHeaderTc_Type);
    py_copy->obj = new ns3::olsr::MessageHeader::Tc(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMessageHeaderTc_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMessageHeaderTc_methods[] = {
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMessageHeaderTc__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMessageHeaderTc__tp_dealloc(PyNs3OlsrMessageHeaderTc *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMessageHeaderTc_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMessageHeaderTc_wrapper_registry.end()) {
        PyNs3OlsrMessageHeaderTc_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MessageHeader::Tc *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMessageHeaderTc__tp_richcompare (PyNs3OlsrMessageHeaderTc *PYBINDGEN_UNUSED(self), PyNs3OlsrMessageHeaderTc *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMessageHeaderTc_Type)) {
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

PyTypeObject PyNs3OlsrMessageHeaderTc_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MessageHeader.Tc",            /* tp_name */
    sizeof(PyNs3OlsrMessageHeaderTc),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMessageHeaderTc__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMessageHeaderTc__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMessageHeaderTc_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMessageHeaderTc__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMessageHeaderTc__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrMprSelectorTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrMprSelectorTuple__get_expirationTime(PyNs3OlsrMprSelectorTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrMprSelectorTuple__set_expirationTime(PyNs3OlsrMprSelectorTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrMprSelectorTuple__get_mainAddr(PyNs3OlsrMprSelectorTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->mainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrMprSelectorTuple__set_mainAddr(PyNs3OlsrMprSelectorTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->mainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrMprSelectorTuple__getsets[] = {
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrMprSelectorTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMprSelectorTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "mainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrMprSelectorTuple__get_mainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrMprSelectorTuple__set_mainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrMprSelectorTuple__tp_init__0(PyNs3OlsrMprSelectorTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::MprSelectorTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrMprSelectorTuple__tp_init__1(PyNs3OlsrMprSelectorTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrMprSelectorTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMprSelectorTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::MprSelectorTuple(*((PyNs3OlsrMprSelectorTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrMprSelectorTuple__tp_init(PyNs3OlsrMprSelectorTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrMprSelectorTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrMprSelectorTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrMprSelectorTuple__copy__(PyNs3OlsrMprSelectorTuple *self)
{

    PyNs3OlsrMprSelectorTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrMprSelectorTuple, &PyNs3OlsrMprSelectorTuple_Type);
    py_copy->obj = new ns3::olsr::MprSelectorTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrMprSelectorTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrMprSelectorTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrMprSelectorTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrMprSelectorTuple__tp_dealloc(PyNs3OlsrMprSelectorTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrMprSelectorTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrMprSelectorTuple_wrapper_registry.end()) {
        PyNs3OlsrMprSelectorTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::MprSelectorTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrMprSelectorTuple__tp_richcompare (PyNs3OlsrMprSelectorTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrMprSelectorTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrMprSelectorTuple_Type)) {
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

PyTypeObject PyNs3OlsrMprSelectorTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.MprSelectorTuple",            /* tp_name */
    sizeof(PyNs3OlsrMprSelectorTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrMprSelectorTuple__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrMprSelectorTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrMprSelectorTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrMprSelectorTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrMprSelectorTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrNeighborTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrNeighborTuple__get_neighborMainAddr(PyNs3OlsrNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->neighborMainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrNeighborTuple__set_neighborMainAddr(PyNs3OlsrNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->neighborMainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrNeighborTuple__get_status(PyNs3OlsrNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->status);
    return py_retval;
}
static int _wrap_PyNs3OlsrNeighborTuple__set_status(PyNs3OlsrNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "i", &self->obj->status)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrNeighborTuple__get_willingness(PyNs3OlsrNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", (int)self->obj->willingness);
    return py_retval;
}
static int _wrap_PyNs3OlsrNeighborTuple__set_willingness(PyNs3OlsrNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->willingness = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrNeighborTuple__getsets[] = {
    {
        (char*) "status", /* attribute name */
        (getter) _wrap_PyNs3OlsrNeighborTuple__get_status, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrNeighborTuple__set_status, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "neighborMainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrNeighborTuple__get_neighborMainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrNeighborTuple__set_neighborMainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "willingness", /* attribute name */
        (getter) _wrap_PyNs3OlsrNeighborTuple__get_willingness, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrNeighborTuple__set_willingness, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrNeighborTuple__tp_init__0(PyNs3OlsrNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::NeighborTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrNeighborTuple__tp_init__1(PyNs3OlsrNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrNeighborTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrNeighborTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::NeighborTuple(*((PyNs3OlsrNeighborTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrNeighborTuple__tp_init(PyNs3OlsrNeighborTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrNeighborTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrNeighborTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrNeighborTuple__copy__(PyNs3OlsrNeighborTuple *self)
{

    PyNs3OlsrNeighborTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrNeighborTuple, &PyNs3OlsrNeighborTuple_Type);
    py_copy->obj = new ns3::olsr::NeighborTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrNeighborTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrNeighborTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrNeighborTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrNeighborTuple__tp_dealloc(PyNs3OlsrNeighborTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrNeighborTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrNeighborTuple_wrapper_registry.end()) {
        PyNs3OlsrNeighborTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::NeighborTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrNeighborTuple__tp_str(PyNs3OlsrNeighborTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrNeighborTuple__tp_richcompare (PyNs3OlsrNeighborTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrNeighborTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrNeighborTuple_Type)) {
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

PyTypeObject PyNs3OlsrNeighborTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.NeighborTuple",            /* tp_name */
    sizeof(PyNs3OlsrNeighborTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrNeighborTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrNeighborTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrNeighborTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrNeighborTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrNeighborTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrNeighborTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrOlsrState_wrapper_registry;


static int
_wrap_PyNs3OlsrOlsrState__tp_init__0(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrOlsrState *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrOlsrState_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::OlsrState(*((PyNs3OlsrOlsrState *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrOlsrState__tp_init__1(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::OlsrState();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrOlsrState__tp_init(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrOlsrState__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrOlsrState__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrOlsrState_InsertDuplicateTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrDuplicateTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrDuplicateTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertDuplicateTuple(*((PyNs3OlsrDuplicateTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseOlderTopologyTuples(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *lastAddr;
    int ansn;
    const char *keywords[] = {"lastAddr", "ansn", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!i", (char **) keywords, &PyNs3Ipv4Address_Type, &lastAddr, &ansn)) {
        return NULL;
    }
    if (ansn > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->EraseOlderTopologyTuples(*((PyNs3Ipv4Address *) lastAddr)->obj, ansn);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseLinkTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrLinkTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrLinkTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseLinkTuple(*((PyNs3OlsrLinkTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertLinkTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrLinkTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    PyNs3OlsrLinkTuple *py_LinkTuple;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrLinkTuple_Type, &tuple)) {
        return NULL;
    }
    ns3::olsr::LinkTuple & retval = self->obj->InsertLinkTuple(*((PyNs3OlsrLinkTuple *) tuple)->obj);
    py_LinkTuple = PyObject_New(PyNs3OlsrLinkTuple, &PyNs3OlsrLinkTuple_Type);
    py_LinkTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_LinkTuple->obj = new ns3::olsr::LinkTuple(retval);
    PyNs3OlsrLinkTuple_wrapper_registry[(void *) py_LinkTuple->obj] = (PyObject *) py_LinkTuple;
    py_retval = Py_BuildValue((char *) "N", py_LinkTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseMprSelectorTuples(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *mainAddr;
    const char *keywords[] = {"mainAddr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &mainAddr)) {
        return NULL;
    }
    self->obj->EraseMprSelectorTuples(*((PyNs3Ipv4Address *) mainAddr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_FindSymNeighborTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::NeighborTuple const *retval;
    PyNs3Ipv4Address *mainAddr;
    const char *keywords[] = {"mainAddr", NULL};
    PyNs3OlsrNeighborTuple *py_NeighborTuple;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &mainAddr)) {
        return NULL;
    }
    retval = self->obj->FindSymNeighborTuple(*((PyNs3Ipv4Address *) mainAddr)->obj);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3OlsrNeighborTuple_wrapper_registry.find((void *) retval);
    if (wrapper_lookup_iter == PyNs3OlsrNeighborTuple_wrapper_registry.end()) {
        py_NeighborTuple = NULL;
    } else {
        py_NeighborTuple = (PyNs3OlsrNeighborTuple *) wrapper_lookup_iter->second;
        Py_INCREF(py_NeighborTuple);
    }
    
    if (py_NeighborTuple == NULL) {
        py_NeighborTuple = PyObject_New(PyNs3OlsrNeighborTuple, &PyNs3OlsrNeighborTuple_Type);
        py_NeighborTuple->obj = new ns3::olsr::NeighborTuple((*retval));
        py_NeighborTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3OlsrNeighborTuple_wrapper_registry[(void *) py_NeighborTuple->obj] = (PyObject *) py_NeighborTuple;
    }
    py_retval = Py_BuildValue((char *) "N", py_NeighborTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_FindMprAddress(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Ipv4Address *address;
    const char *keywords[] = {"address", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &address)) {
        return NULL;
    }
    retval = self->obj->FindMprAddress(*((PyNs3Ipv4Address *) address)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertIfaceAssocTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrIfaceAssocTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrIfaceAssocTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertIfaceAssocTuple(*((PyNs3OlsrIfaceAssocTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_GetMprSet(PyNs3OlsrOlsrState *self)
{
    PyObject *py_retval;
    ns3::olsr::MprSet retval;
    Pyns3__olsr__MprSet *py_ns3__olsr__MprSet;
    
    retval = self->obj->GetMprSet();
    py_ns3__olsr__MprSet = PyObject_New(Pyns3__olsr__MprSet, &Pyns3__olsr__MprSet_Type);
    py_ns3__olsr__MprSet->obj = new ns3::olsr::MprSet(retval);
    py_retval = Py_BuildValue((char *) "N", py_ns3__olsr__MprSet);
    return py_retval;
}



PyObject *
_wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuples__0(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *neighbor;
    const char *keywords[] = {"neighbor", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighbor)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseTwoHopNeighborTuples(*((PyNs3Ipv4Address *) neighbor)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuples__1(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *neighbor;
    PyNs3Ipv4Address *twoHopNeighbor;
    const char *keywords[] = {"neighbor", "twoHopNeighbor", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighbor, &PyNs3Ipv4Address_Type, &twoHopNeighbor)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseTwoHopNeighborTuples(*((PyNs3Ipv4Address *) neighbor)->obj, *((PyNs3Ipv4Address *) twoHopNeighbor)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuples(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuples__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuples__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrOlsrState_EraseNeighborTuple__0(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OlsrNeighborTuple *neighborTuple;
    const char *keywords[] = {"neighborTuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrNeighborTuple_Type, &neighborTuple)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseNeighborTuple(*((PyNs3OlsrNeighborTuple *) neighborTuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3OlsrOlsrState_EraseNeighborTuple__1(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *mainAddr;
    const char *keywords[] = {"mainAddr", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &mainAddr)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->EraseNeighborTuple(*((PyNs3Ipv4Address *) mainAddr)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3OlsrOlsrState_EraseNeighborTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrOlsrState_EraseNeighborTuple__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrOlsrState_EraseNeighborTuple__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrOlsrState_EraseAssociationTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociationTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociationTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseAssociationTuple(*((PyNs3OlsrAssociationTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertAssociation(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociation *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociation_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertAssociation(*((PyNs3OlsrAssociation *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTwoHopNeighborTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTwoHopNeighborTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseTwoHopNeighborTuple(*((PyNs3OlsrTwoHopNeighborTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertAssociationTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociationTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociationTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertAssociationTuple(*((PyNs3OlsrAssociationTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_PrintMprSelectorSet(PyNs3OlsrOlsrState *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->PrintMprSelectorSet();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseMprSelectorTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrMprSelectorTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMprSelectorTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseMprSelectorTuple(*((PyNs3OlsrMprSelectorTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseAssociation(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrAssociation *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrAssociation_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseAssociation(*((PyNs3OlsrAssociation *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_SetMprSet(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::MprSet mprSet_value;
    const char *keywords[] = {"mprSet", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__ns3__olsr__MprSet, &mprSet_value)) {
        return NULL;
    }
    self->obj->SetMprSet(mprSet_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_FindIfaceAssocTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::olsr::IfaceAssocTuple const *retval;
    PyNs3Ipv4Address *ifaceAddr;
    const char *keywords[] = {"ifaceAddr", NULL};
    PyNs3OlsrIfaceAssocTuple *py_IfaceAssocTuple;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &ifaceAddr)) {
        return NULL;
    }
    retval = self->obj->FindIfaceAssocTuple(*((PyNs3Ipv4Address *) ifaceAddr)->obj);
    if (!(retval)) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3OlsrIfaceAssocTuple_wrapper_registry.find((void *) retval);
    if (wrapper_lookup_iter == PyNs3OlsrIfaceAssocTuple_wrapper_registry.end()) {
        py_IfaceAssocTuple = NULL;
    } else {
        py_IfaceAssocTuple = (PyNs3OlsrIfaceAssocTuple *) wrapper_lookup_iter->second;
        Py_INCREF(py_IfaceAssocTuple);
    }
    
    if (py_IfaceAssocTuple == NULL) {
        py_IfaceAssocTuple = PyObject_New(PyNs3OlsrIfaceAssocTuple, &PyNs3OlsrIfaceAssocTuple_Type);
        py_IfaceAssocTuple->obj = new ns3::olsr::IfaceAssocTuple((*retval));
        py_IfaceAssocTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        PyNs3OlsrIfaceAssocTuple_wrapper_registry[(void *) py_IfaceAssocTuple->obj] = (PyObject *) py_IfaceAssocTuple;
    }
    py_retval = Py_BuildValue((char *) "N", py_IfaceAssocTuple);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseDuplicateTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrDuplicateTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrDuplicateTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseDuplicateTuple(*((PyNs3OlsrDuplicateTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_FindNeighborInterfaces(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *neighborMainAddr;
    const char *keywords[] = {"neighborMainAddr", NULL};
    std::vector< ns3::Ipv4Address > retval;
    Pystd__vector__lt___ns3__Ipv4Address___gt__ *py_std__vector__lt___ns3__Ipv4Address___gt__;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4Address_Type, &neighborMainAddr)) {
        return NULL;
    }
    retval = self->obj->FindNeighborInterfaces(*((PyNs3Ipv4Address *) neighborMainAddr)->obj);
    py_std__vector__lt___ns3__Ipv4Address___gt__ = PyObject_New(Pystd__vector__lt___ns3__Ipv4Address___gt__, &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    py_std__vector__lt___ns3__Ipv4Address___gt__->obj = new std::vector< ns3::Ipv4Address >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__Ipv4Address___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertNeighborTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrNeighborTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrNeighborTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertNeighborTuple(*((PyNs3OlsrNeighborTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseIfaceAssocTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrIfaceAssocTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrIfaceAssocTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseIfaceAssocTuple(*((PyNs3OlsrIfaceAssocTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertTwoHopNeighborTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTwoHopNeighborTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTwoHopNeighborTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertTwoHopNeighborTuple(*((PyNs3OlsrTwoHopNeighborTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertMprSelectorTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrMprSelectorTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrMprSelectorTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertMprSelectorTuple(*((PyNs3OlsrMprSelectorTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_EraseTopologyTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTopologyTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTopologyTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->EraseTopologyTuple(*((PyNs3OlsrTopologyTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrOlsrState_InsertTopologyTuple(PyNs3OlsrOlsrState *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OlsrTopologyTuple *tuple;
    const char *keywords[] = {"tuple", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTopologyTuple_Type, &tuple)) {
        return NULL;
    }
    self->obj->InsertTopologyTuple(*((PyNs3OlsrTopologyTuple *) tuple)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrOlsrState__copy__(PyNs3OlsrOlsrState *self)
{

    PyNs3OlsrOlsrState *py_copy;
    py_copy = PyObject_New(PyNs3OlsrOlsrState, &PyNs3OlsrOlsrState_Type);
    py_copy->obj = new ns3::olsr::OlsrState(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrOlsrState_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrOlsrState_methods[] = {
    {(char *) "InsertDuplicateTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertDuplicateTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseOlderTopologyTuples", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseOlderTopologyTuples, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseLinkTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseLinkTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertLinkTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertLinkTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseMprSelectorTuples", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseMprSelectorTuples, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindSymNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_FindSymNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindMprAddress", (PyCFunction) _wrap_PyNs3OlsrOlsrState_FindMprAddress, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertIfaceAssocTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertIfaceAssocTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetMprSet", (PyCFunction) _wrap_PyNs3OlsrOlsrState_GetMprSet, METH_NOARGS, NULL },
    {(char *) "EraseTwoHopNeighborTuples", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuples, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseAssociationTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseAssociationTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertAssociation", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseTwoHopNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseTwoHopNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertAssociationTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertAssociationTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PrintMprSelectorSet", (PyCFunction) _wrap_PyNs3OlsrOlsrState_PrintMprSelectorSet, METH_NOARGS, NULL },
    {(char *) "EraseMprSelectorTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseMprSelectorTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseAssociation", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMprSet", (PyCFunction) _wrap_PyNs3OlsrOlsrState_SetMprSet, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindIfaceAssocTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_FindIfaceAssocTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseDuplicateTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseDuplicateTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "FindNeighborInterfaces", (PyCFunction) _wrap_PyNs3OlsrOlsrState_FindNeighborInterfaces, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseIfaceAssocTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseIfaceAssocTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertTwoHopNeighborTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertTwoHopNeighborTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertMprSelectorTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertMprSelectorTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EraseTopologyTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_EraseTopologyTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InsertTopologyTuple", (PyCFunction) _wrap_PyNs3OlsrOlsrState_InsertTopologyTuple, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrOlsrState__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrOlsrState__tp_dealloc(PyNs3OlsrOlsrState *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrOlsrState_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrOlsrState_wrapper_registry.end()) {
        PyNs3OlsrOlsrState_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::OlsrState *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrOlsrState__tp_richcompare (PyNs3OlsrOlsrState *PYBINDGEN_UNUSED(self), PyNs3OlsrOlsrState *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrOlsrState_Type)) {
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

PyTypeObject PyNs3OlsrOlsrState_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.OlsrState",            /* tp_name */
    sizeof(PyNs3OlsrOlsrState),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrOlsrState__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrOlsrState__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrOlsrState_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrOlsrState__tp_init,             /* tp_init */
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
_wrap_PyNs3OlsrPacketHeader__tp_init__0(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrPacketHeader *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrPacketHeader_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::PacketHeader(*((PyNs3OlsrPacketHeader *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrPacketHeader__tp_init__1(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::PacketHeader();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrPacketHeader__tp_init(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrPacketHeader__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrPacketHeader__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrPacketHeader_Serialize(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrPacketHeader_Deserialize(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrPacketHeader_GetPacketLength(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetPacketLength();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::olsr::PacketHeader::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetPacketSequenceNumber(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    uint16_t retval;
    
    retval = self->obj->GetPacketSequenceNumber();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_SetPacketSequenceNumber(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int seqnum;
    const char *keywords[] = {"seqnum", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &seqnum)) {
        return NULL;
    }
    if (seqnum > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPacketSequenceNumber(seqnum);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_SetPacketLength(PyNs3OlsrPacketHeader *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int length;
    const char *keywords[] = {"length", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &length)) {
        return NULL;
    }
    if (length > 0xffff) {
        PyErr_SetString(PyExc_ValueError, "Out of range");
        return NULL;
    }
    self->obj->SetPacketLength(length);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrPacketHeader_GetInstanceTypeId(PyNs3OlsrPacketHeader *self)
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
_wrap_PyNs3OlsrPacketHeader_GetSerializedSize(PyNs3OlsrPacketHeader *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetSerializedSize();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrPacketHeader__copy__(PyNs3OlsrPacketHeader *self)
{

    PyNs3OlsrPacketHeader *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrPacketHeader, &PyNs3OlsrPacketHeader_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::olsr::PacketHeader(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrPacketHeader_methods[] = {
    {(char *) "Serialize", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_Serialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Deserialize", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_Deserialize, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPacketLength", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetPacketLength, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetPacketSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetPacketSequenceNumber, METH_NOARGS, NULL },
    {(char *) "SetPacketSequenceNumber", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_SetPacketSequenceNumber, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPacketLength", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_SetPacketLength, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInstanceTypeId", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetInstanceTypeId, METH_NOARGS, NULL },
    {(char *) "GetSerializedSize", (PyCFunction) _wrap_PyNs3OlsrPacketHeader_GetSerializedSize, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrPacketHeader__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrPacketHeader__tp_clear(PyNs3OlsrPacketHeader *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::olsr::PacketHeader *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3OlsrPacketHeader__tp_traverse(PyNs3OlsrPacketHeader *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3OlsrPacketHeader__tp_dealloc(PyNs3OlsrPacketHeader *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrPacketHeader__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrPacketHeader__tp_str(PyNs3OlsrPacketHeader *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrPacketHeader__tp_richcompare (PyNs3OlsrPacketHeader *PYBINDGEN_UNUSED(self), PyNs3OlsrPacketHeader *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrPacketHeader_Type)) {
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

PyTypeObject PyNs3OlsrPacketHeader_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.PacketHeader",            /* tp_name */
    sizeof(PyNs3OlsrPacketHeader),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrPacketHeader__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrPacketHeader__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_BASETYPE|Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_GC,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)PyNs3OlsrPacketHeader__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrPacketHeader__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrPacketHeader__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrPacketHeader_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrPacketHeader, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrPacketHeader__tp_init,             /* tp_init */
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
_wrap_PyNs3OlsrRoutingProtocol__tp_init__0(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrRoutingProtocol *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrRoutingProtocol_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::RoutingProtocol(*((PyNs3OlsrRoutingProtocol *) arg0)->obj);
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrRoutingProtocol__tp_init__1(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::RoutingProtocol();
    self->obj->Ref ();
    ns3::CompleteConstruct(self->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrRoutingProtocol__tp_init(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrRoutingProtocol__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrRoutingProtocol__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrRoutingProtocol_GetRoutingTableAssociation(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::Ipv4StaticRouting const > retval;
    PyNs3Ipv4StaticRouting *py_Ipv4StaticRouting;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetRoutingTableAssociation();
    if (!(const_cast<ns3::Ipv4StaticRouting *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::Ipv4StaticRouting *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
        py_Ipv4StaticRouting = NULL;
    } else {
        py_Ipv4StaticRouting = (PyNs3Ipv4StaticRouting *) wrapper_lookup_iter->second;
        Py_INCREF(py_Ipv4StaticRouting);
    }
    
    if (py_Ipv4StaticRouting == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::Ipv4StaticRouting *> (ns3::PeekPointer (retval)))), &PyNs3Ipv4StaticRouting_Type);
        py_Ipv4StaticRouting = PyObject_GC_New(PyNs3Ipv4StaticRouting, wrapper_type);
        py_Ipv4StaticRouting->inst_dict = NULL;
    
        py_Ipv4StaticRouting->inst_dict = NULL;
        py_Ipv4StaticRouting->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::Ipv4StaticRouting *> (ns3::PeekPointer (retval))->Ref();
        py_Ipv4StaticRouting->obj = const_cast<ns3::Ipv4StaticRouting *> (ns3::PeekPointer (retval));
        PyNs3ObjectBase_wrapper_registry[(void *) py_Ipv4StaticRouting->obj] = (PyObject *) py_Ipv4StaticRouting;
    }
    py_retval = Py_BuildValue((char *) "N", py_Ipv4StaticRouting);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_AddHostNetworkAssociation(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *networkAddr;
    PyNs3Ipv4Mask *netmask;
    const char *keywords[] = {"networkAddr", "netmask", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &networkAddr, &PyNs3Ipv4Mask_Type, &netmask)) {
        return NULL;
    }
    self->obj->AddHostNetworkAssociation(*((PyNs3Ipv4Address *) networkAddr)->obj, *((PyNs3Ipv4Mask *) netmask)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_Dump(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    
    self->obj->Dump();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_RemoveHostNetworkAssociation(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4Address *networkAddr;
    PyNs3Ipv4Mask *netmask;
    const char *keywords[] = {"networkAddr", "netmask", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Ipv4Address_Type, &networkAddr, &PyNs3Ipv4Mask_Type, &netmask)) {
        return NULL;
    }
    self->obj->RemoveHostNetworkAssociation(*((PyNs3Ipv4Address *) networkAddr)->obj, *((PyNs3Ipv4Mask *) netmask)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::olsr::RoutingProtocol::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_SetInterfaceExclusions(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::set< unsigned int > exceptions_value;
    const char *keywords[] = {"exceptions", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O&", (char **) keywords, _wrap_convert_py2c__std__set__lt___unsigned_int___gt__, &exceptions_value)) {
        return NULL;
    }
    self->obj->SetInterfaceExclusions(exceptions_value);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_GetRoutingTableEntries(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::RoutingTableEntry > retval;
    Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__;
    
    retval = self->obj->GetRoutingTableEntries();
    py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__ = PyObject_New(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__, &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type);
    py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__->obj = new std::vector< ns3::olsr::RoutingTableEntry >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__vector__lt___ns3__olsr__RoutingTableEntry___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_AssignStreams(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrRoutingProtocol_SetMainInterface(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int interface;
    const char *keywords[] = {"interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &interface)) {
        return NULL;
    }
    self->obj->SetMainInterface(interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_GetInterfaceExclusions(PyNs3OlsrRoutingProtocol *self)
{
    PyObject *py_retval;
    std::set< unsigned int > retval;
    Pystd__set__lt___unsigned_int___gt__ *py_std__set__lt___unsigned_int___gt__;
    
    retval = self->obj->GetInterfaceExclusions();
    py_std__set__lt___unsigned_int___gt__ = PyObject_New(Pystd__set__lt___unsigned_int___gt__, &Pystd__set__lt___unsigned_int___gt___Type);
    py_std__set__lt___unsigned_int___gt__->obj = new std::set< unsigned int >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__set__lt___unsigned_int___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrRoutingProtocol_SetRoutingTableAssociation(PyNs3OlsrRoutingProtocol *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Ipv4StaticRouting *routingTable;
    ns3::Ipv4StaticRouting *routingTable_ptr;
    const char *keywords[] = {"routingTable", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ipv4StaticRouting_Type, &routingTable)) {
        return NULL;
    }
    routingTable_ptr = (routingTable ? routingTable->obj : NULL);
    self->obj->SetRoutingTableAssociation(ns3::Ptr< ns3::Ipv4StaticRouting  > (routingTable_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3OlsrRoutingProtocol__copy__(PyNs3OlsrRoutingProtocol *self)
{

    PyNs3OlsrRoutingProtocol *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrRoutingProtocol, &PyNs3OlsrRoutingProtocol_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::olsr::RoutingProtocol(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrRoutingProtocol_methods[] = {
    {(char *) "GetRoutingTableAssociation", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetRoutingTableAssociation, METH_NOARGS, NULL },
    {(char *) "AddHostNetworkAssociation", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_AddHostNetworkAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Dump", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_Dump, METH_NOARGS, NULL },
    {(char *) "RemoveHostNetworkAssociation", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_RemoveHostNetworkAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetInterfaceExclusions", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_SetInterfaceExclusions, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetRoutingTableEntries", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetRoutingTableEntries, METH_NOARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMainInterface", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_SetMainInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetInterfaceExclusions", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_GetInterfaceExclusions, METH_NOARGS, NULL },
    {(char *) "SetRoutingTableAssociation", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol_SetRoutingTableAssociation, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrRoutingProtocol__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrRoutingProtocol__tp_clear(PyNs3OlsrRoutingProtocol *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::olsr::RoutingProtocol *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3OlsrRoutingProtocol__tp_traverse(PyNs3OlsrRoutingProtocol *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3OlsrRoutingProtocol__tp_dealloc(PyNs3OlsrRoutingProtocol *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrRoutingProtocol__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrRoutingProtocol__tp_richcompare (PyNs3OlsrRoutingProtocol *PYBINDGEN_UNUSED(self), PyNs3OlsrRoutingProtocol *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrRoutingProtocol_Type)) {
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

PyTypeObject PyNs3OlsrRoutingProtocol_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.RoutingProtocol",            /* tp_name */
    sizeof(PyNs3OlsrRoutingProtocol),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrRoutingProtocol__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3OlsrRoutingProtocol__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrRoutingProtocol__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrRoutingProtocol__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrRoutingProtocol_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrRoutingProtocol, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrRoutingProtocol__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrRoutingTableEntry_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_destAddr(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->destAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_destAddr(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_distance(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->distance));
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_distance(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->distance)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_interface(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(self->obj->interface));
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_interface(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "I", &self->obj->interface)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrRoutingTableEntry__get_nextAddr(PyNs3OlsrRoutingTableEntry *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->nextAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrRoutingTableEntry__set_nextAddr(PyNs3OlsrRoutingTableEntry *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->nextAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrRoutingTableEntry__getsets[] = {
    {
        (char*) "interface", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_interface, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_interface, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "distance", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_distance, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_distance, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "nextAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_nextAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_nextAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrRoutingTableEntry__get_destAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrRoutingTableEntry__set_destAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrRoutingTableEntry__tp_init__0(PyNs3OlsrRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrRoutingTableEntry *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrRoutingTableEntry_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::RoutingTableEntry(*((PyNs3OlsrRoutingTableEntry *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrRoutingTableEntry__tp_init__1(PyNs3OlsrRoutingTableEntry *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::RoutingTableEntry();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrRoutingTableEntry__tp_init(PyNs3OlsrRoutingTableEntry *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrRoutingTableEntry__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrRoutingTableEntry__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrRoutingTableEntry__copy__(PyNs3OlsrRoutingTableEntry *self)
{

    PyNs3OlsrRoutingTableEntry *py_copy;
    py_copy = PyObject_New(PyNs3OlsrRoutingTableEntry, &PyNs3OlsrRoutingTableEntry_Type);
    py_copy->obj = new ns3::olsr::RoutingTableEntry(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrRoutingTableEntry_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrRoutingTableEntry_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrRoutingTableEntry__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrRoutingTableEntry__tp_dealloc(PyNs3OlsrRoutingTableEntry *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrRoutingTableEntry_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrRoutingTableEntry_wrapper_registry.end()) {
        PyNs3OlsrRoutingTableEntry_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::RoutingTableEntry *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrRoutingTableEntry__tp_richcompare (PyNs3OlsrRoutingTableEntry *PYBINDGEN_UNUSED(self), PyNs3OlsrRoutingTableEntry *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrRoutingTableEntry_Type)) {
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

PyTypeObject PyNs3OlsrRoutingTableEntry_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.RoutingTableEntry",            /* tp_name */
    sizeof(PyNs3OlsrRoutingTableEntry),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrRoutingTableEntry__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3OlsrRoutingTableEntry__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrRoutingTableEntry_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrRoutingTableEntry__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrRoutingTableEntry__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrTopologyTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_destAddr(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->destAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_destAddr(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->destAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_expirationTime(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_expirationTime(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_lastAddr(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->lastAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_lastAddr(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->lastAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTopologyTuple__get_sequenceNumber(PyNs3OlsrTopologyTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "i", self->obj->sequenceNumber);
    return py_retval;
}
static int _wrap_PyNs3OlsrTopologyTuple__set_sequenceNumber(PyNs3OlsrTopologyTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
    self->obj->sequenceNumber = tmp;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrTopologyTuple__getsets[] = {
    {
        (char*) "lastAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_lastAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_lastAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "destAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_destAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_destAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "sequenceNumber", /* attribute name */
        (getter) _wrap_PyNs3OlsrTopologyTuple__get_sequenceNumber, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTopologyTuple__set_sequenceNumber, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrTopologyTuple__tp_init__0(PyNs3OlsrTopologyTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::TopologyTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrTopologyTuple__tp_init__1(PyNs3OlsrTopologyTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrTopologyTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTopologyTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::TopologyTuple(*((PyNs3OlsrTopologyTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrTopologyTuple__tp_init(PyNs3OlsrTopologyTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrTopologyTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrTopologyTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrTopologyTuple__copy__(PyNs3OlsrTopologyTuple *self)
{

    PyNs3OlsrTopologyTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrTopologyTuple, &PyNs3OlsrTopologyTuple_Type);
    py_copy->obj = new ns3::olsr::TopologyTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrTopologyTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrTopologyTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrTopologyTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrTopologyTuple__tp_dealloc(PyNs3OlsrTopologyTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrTopologyTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrTopologyTuple_wrapper_registry.end()) {
        PyNs3OlsrTopologyTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::TopologyTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrTopologyTuple__tp_str(PyNs3OlsrTopologyTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrTopologyTuple__tp_richcompare (PyNs3OlsrTopologyTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrTopologyTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrTopologyTuple_Type)) {
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

PyTypeObject PyNs3OlsrTopologyTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.TopologyTuple",            /* tp_name */
    sizeof(PyNs3OlsrTopologyTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrTopologyTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrTopologyTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrTopologyTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrTopologyTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrTopologyTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrTopologyTuple__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3OlsrTwoHopNeighborTuple_wrapper_registry;
static PyObject* _wrap_PyNs3OlsrTwoHopNeighborTuple__get_expirationTime(PyNs3OlsrTwoHopNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *py_Time;
    
    py_Time = PyObject_New(PyNs3Time, &PyNs3Time_Type);
    py_Time->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Time->obj = new ns3::Time(self->obj->expirationTime);
    PyNs3Time_wrapper_registry[(void *) py_Time->obj] = (PyObject *) py_Time;
    py_retval = Py_BuildValue((char *) "N", py_Time);
    return py_retval;
}
static int _wrap_PyNs3OlsrTwoHopNeighborTuple__set_expirationTime(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Time *tmp_Time;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Time_Type, &tmp_Time)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->expirationTime = *tmp_Time->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTwoHopNeighborTuple__get_neighborMainAddr(PyNs3OlsrTwoHopNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->neighborMainAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTwoHopNeighborTuple__set_neighborMainAddr(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->neighborMainAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3OlsrTwoHopNeighborTuple__get_twoHopNeighborAddr(PyNs3OlsrTwoHopNeighborTuple *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *py_Ipv4Address;
    
    py_Ipv4Address = PyObject_New(PyNs3Ipv4Address, &PyNs3Ipv4Address_Type);
    py_Ipv4Address->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Ipv4Address->obj = new ns3::Ipv4Address(self->obj->twoHopNeighborAddr);
    PyNs3Ipv4Address_wrapper_registry[(void *) py_Ipv4Address->obj] = (PyObject *) py_Ipv4Address;
    py_retval = Py_BuildValue((char *) "N", py_Ipv4Address);
    return py_retval;
}
static int _wrap_PyNs3OlsrTwoHopNeighborTuple__set_twoHopNeighborAddr(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Ipv4Address *tmp_Ipv4Address;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Ipv4Address_Type, &tmp_Ipv4Address)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->twoHopNeighborAddr = *tmp_Ipv4Address->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3OlsrTwoHopNeighborTuple__getsets[] = {
    {
        (char*) "expirationTime", /* attribute name */
        (getter) _wrap_PyNs3OlsrTwoHopNeighborTuple__get_expirationTime, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTwoHopNeighborTuple__set_expirationTime, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "neighborMainAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTwoHopNeighborTuple__get_neighborMainAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTwoHopNeighborTuple__set_neighborMainAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "twoHopNeighborAddr", /* attribute name */
        (getter) _wrap_PyNs3OlsrTwoHopNeighborTuple__get_twoHopNeighborAddr, /* C function to get the attribute */
        (setter) _wrap_PyNs3OlsrTwoHopNeighborTuple__set_twoHopNeighborAddr, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__0(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::olsr::TwoHopNeighborTuple();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__1(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrTwoHopNeighborTuple *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrTwoHopNeighborTuple_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::olsr::TwoHopNeighborTuple(*((PyNs3OlsrTwoHopNeighborTuple *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init(PyNs3OlsrTwoHopNeighborTuple *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrTwoHopNeighborTuple__copy__(PyNs3OlsrTwoHopNeighborTuple *self)
{

    PyNs3OlsrTwoHopNeighborTuple *py_copy;
    py_copy = PyObject_New(PyNs3OlsrTwoHopNeighborTuple, &PyNs3OlsrTwoHopNeighborTuple_Type);
    py_copy->obj = new ns3::olsr::TwoHopNeighborTuple(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3OlsrTwoHopNeighborTuple_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrTwoHopNeighborTuple_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrTwoHopNeighborTuple__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_dealloc(PyNs3OlsrTwoHopNeighborTuple *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3OlsrTwoHopNeighborTuple_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3OlsrTwoHopNeighborTuple_wrapper_registry.end()) {
        PyNs3OlsrTwoHopNeighborTuple_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::olsr::TwoHopNeighborTuple *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_str(PyNs3OlsrTwoHopNeighborTuple *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_richcompare (PyNs3OlsrTwoHopNeighborTuple *PYBINDGEN_UNUSED(self), PyNs3OlsrTwoHopNeighborTuple *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrTwoHopNeighborTuple_Type)) {
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

PyTypeObject PyNs3OlsrTwoHopNeighborTuple_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.TwoHopNeighborTuple",            /* tp_name */
    sizeof(PyNs3OlsrTwoHopNeighborTuple),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrTwoHopNeighborTuple_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3OlsrTwoHopNeighborTuple__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrTwoHopNeighborTuple__tp_init,             /* tp_init */
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
    (char *) "olsr.olsr.Std__vector__lt___ns3__Ipv4Address___gt__",            /* tp_name */
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
    (char *) "olsr.olsr.Std__vector__lt___ns3__Ipv4Address___gt__Iter",            /* tp_name */
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




static void
Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >::iterator iter;
    PyNs3OlsrMessageHeaderHelloLinkMessage *py_LinkMessage;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_LinkMessage = PyObject_New(PyNs3OlsrMessageHeaderHelloLinkMessage, &PyNs3OlsrMessageHeaderHelloLinkMessage_Type);
    py_LinkMessage->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_LinkMessage->obj = new ns3::olsr::MessageHeader::Hello::LinkMessage((*iter));
    PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry[(void *) py_LinkMessage->obj] = (PyObject *) py_LinkMessage;
    py_retval = Py_BuildValue((char *) "N", py_LinkMessage);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__MessageHeader__Hello__LinkMessage(PyObject *value, ns3::olsr::MessageHeader::Hello::LinkMessage *address)
{
    PyObject *py_retval;
    PyNs3OlsrMessageHeaderHelloLinkMessage *tmp_LinkMessage;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrMessageHeaderHelloLinkMessage_Type, &tmp_LinkMessage)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_LinkMessage->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__(PyObject *arg, std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::MessageHeader::Hello::LinkMessage item;
            if (!_wrap_convert_py2c__ns3__olsr__MessageHeader__Hello__LinkMessage(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ instance, or a list of ns3::olsr::MessageHeader::Hello::LinkMessage");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_init(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter, &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::MessageHeader::Hna::Association >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MessageHeader::Hna::Association >::iterator iter;
    PyNs3OlsrMessageHeaderHnaAssociation *py_Association;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Association = PyObject_New(PyNs3OlsrMessageHeaderHnaAssociation, &PyNs3OlsrMessageHeaderHnaAssociation_Type);
    py_Association->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Association->obj = new ns3::olsr::MessageHeader::Hna::Association((*iter));
    PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry[(void *) py_Association->obj] = (PyObject *) py_Association;
    py_retval = Py_BuildValue((char *) "N", py_Association);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__MessageHeader__Hna__Association(PyObject *value, ns3::olsr::MessageHeader::Hna::Association *address)
{
    PyObject *py_retval;
    PyNs3OlsrMessageHeaderHnaAssociation *tmp_Association;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrMessageHeaderHnaAssociation_Type, &tmp_Association)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_Association->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__(PyObject *arg, std::vector< ns3::olsr::MessageHeader::Hna::Association > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::MessageHeader::Hna::Association item;
            if (!_wrap_convert_py2c__ns3__olsr__MessageHeader__Hna__Association(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ instance, or a list of ns3::olsr::MessageHeader::Hna::Association");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_init(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::MessageHeader::Hna::Association >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::MprSelectorTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::MprSelectorTuple >::iterator iter;
    PyNs3OlsrMprSelectorTuple *py_MprSelectorTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_MprSelectorTuple = PyObject_New(PyNs3OlsrMprSelectorTuple, &PyNs3OlsrMprSelectorTuple_Type);
    py_MprSelectorTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_MprSelectorTuple->obj = new ns3::olsr::MprSelectorTuple((*iter));
    PyNs3OlsrMprSelectorTuple_wrapper_registry[(void *) py_MprSelectorTuple->obj] = (PyObject *) py_MprSelectorTuple;
    py_retval = Py_BuildValue((char *) "N", py_MprSelectorTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__MprSelectorTuple(PyObject *value, ns3::olsr::MprSelectorTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrMprSelectorTuple *tmp_MprSelectorTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrMprSelectorTuple_Type, &tmp_MprSelectorTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_MprSelectorTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__MprSelectorTuple___gt__(PyObject *arg, std::vector< ns3::olsr::MprSelectorTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::MprSelectorTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__MprSelectorTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__MprSelectorTuple___gt__ instance, or a list of ns3::olsr::MprSelectorTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::MprSelectorTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__MprSelectorTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__MprSelectorTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::NeighborTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::NeighborTuple >::iterator iter;
    PyNs3OlsrNeighborTuple *py_NeighborTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_NeighborTuple = PyObject_New(PyNs3OlsrNeighborTuple, &PyNs3OlsrNeighborTuple_Type);
    py_NeighborTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_NeighborTuple->obj = new ns3::olsr::NeighborTuple((*iter));
    PyNs3OlsrNeighborTuple_wrapper_registry[(void *) py_NeighborTuple->obj] = (PyObject *) py_NeighborTuple;
    py_retval = Py_BuildValue((char *) "N", py_NeighborTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__NeighborTuple(PyObject *value, ns3::olsr::NeighborTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrNeighborTuple *tmp_NeighborTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrNeighborTuple_Type, &tmp_NeighborTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_NeighborTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__NeighborTuple___gt__(PyObject *arg, std::vector< ns3::olsr::NeighborTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__NeighborTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::NeighborTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__NeighborTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__NeighborTuple___gt__ instance, or a list of ns3::olsr::NeighborTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::NeighborTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__NeighborTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__NeighborTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__NeighborTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__NeighborTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::TwoHopNeighborTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::TwoHopNeighborTuple >::iterator iter;
    PyNs3OlsrTwoHopNeighborTuple *py_TwoHopNeighborTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_TwoHopNeighborTuple = PyObject_New(PyNs3OlsrTwoHopNeighborTuple, &PyNs3OlsrTwoHopNeighborTuple_Type);
    py_TwoHopNeighborTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TwoHopNeighborTuple->obj = new ns3::olsr::TwoHopNeighborTuple((*iter));
    PyNs3OlsrTwoHopNeighborTuple_wrapper_registry[(void *) py_TwoHopNeighborTuple->obj] = (PyObject *) py_TwoHopNeighborTuple;
    py_retval = Py_BuildValue((char *) "N", py_TwoHopNeighborTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__TwoHopNeighborTuple(PyObject *value, ns3::olsr::TwoHopNeighborTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrTwoHopNeighborTuple *tmp_TwoHopNeighborTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrTwoHopNeighborTuple_Type, &tmp_TwoHopNeighborTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_TwoHopNeighborTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__(PyObject *arg, std::vector< ns3::olsr::TwoHopNeighborTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::TwoHopNeighborTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__TwoHopNeighborTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__ instance, or a list of ns3::olsr::TwoHopNeighborTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::TwoHopNeighborTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pyns3__olsr__MprSetIter__tp_clear(Pyns3__olsr__MprSetIter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pyns3__olsr__MprSetIter__tp_traverse(Pyns3__olsr__MprSetIter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pyns3__olsr__MprSet__tp_dealloc(Pyns3__olsr__MprSet *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pyns3__olsr__MprSetIter__tp_dealloc(Pyns3__olsr__MprSetIter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pyns3__olsr__MprSet__tp_iter(Pyns3__olsr__MprSet *self)
{
    Pyns3__olsr__MprSetIter *iter = PyObject_GC_New(Pyns3__olsr__MprSetIter, &Pyns3__olsr__MprSetIter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new ns3::olsr::MprSet::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pyns3__olsr__MprSetIter__tp_iter(Pyns3__olsr__MprSetIter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pyns3__olsr__MprSetIter__tp_iternext(Pyns3__olsr__MprSetIter *self)
{
    PyObject *py_retval;
    ns3::olsr::MprSet::iterator iter;
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

int _wrap_convert_py2c__ns3__olsr__MprSet(PyObject *arg, ns3::olsr::MprSet *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pyns3__olsr__MprSet_Type)) {
        *container = *((Pyns3__olsr__MprSet*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Ipv4Address item;
            if (!_wrap_convert_py2c__ns3__Ipv4Address(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Ns3__olsr__MprSet instance, or a list of ns3::Ipv4Address");
        return 0;
    }
    return 1;
}


static int
_wrap_Pyns3__olsr__MprSet__tp_init(Pyns3__olsr__MprSet *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new ns3::olsr::MprSet;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__ns3__olsr__MprSet(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pyns3__olsr__MprSet_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Ns3__olsr__MprSet",            /* tp_name */
    sizeof(Pyns3__olsr__MprSet),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pyns3__olsr__MprSet__tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pyns3__olsr__MprSet__tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pyns3__olsr__MprSet__tp_init,             /* tp_init */
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

PyTypeObject Pyns3__olsr__MprSetIter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Ns3__olsr__MprSetIter",            /* tp_name */
    sizeof(Pyns3__olsr__MprSetIter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pyns3__olsr__MprSetIter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pyns3__olsr__MprSetIter__tp_traverse,     /* tp_traverse */
    (inquiry)Pyns3__olsr__MprSetIter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pyns3__olsr__MprSetIter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pyns3__olsr__MprSetIter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::LinkTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::LinkTuple >::iterator iter;
    PyNs3OlsrLinkTuple *py_LinkTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_LinkTuple = PyObject_New(PyNs3OlsrLinkTuple, &PyNs3OlsrLinkTuple_Type);
    py_LinkTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_LinkTuple->obj = new ns3::olsr::LinkTuple((*iter));
    PyNs3OlsrLinkTuple_wrapper_registry[(void *) py_LinkTuple->obj] = (PyObject *) py_LinkTuple;
    py_retval = Py_BuildValue((char *) "N", py_LinkTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__LinkTuple(PyObject *value, ns3::olsr::LinkTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrLinkTuple *tmp_LinkTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrLinkTuple_Type, &tmp_LinkTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_LinkTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__LinkTuple___gt__(PyObject *arg, std::vector< ns3::olsr::LinkTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__LinkTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__LinkTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::LinkTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__LinkTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__LinkTuple___gt__ instance, or a list of ns3::olsr::LinkTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::LinkTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__LinkTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__LinkTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__LinkTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__LinkTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::TopologyTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::TopologyTuple >::iterator iter;
    PyNs3OlsrTopologyTuple *py_TopologyTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_TopologyTuple = PyObject_New(PyNs3OlsrTopologyTuple, &PyNs3OlsrTopologyTuple_Type);
    py_TopologyTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TopologyTuple->obj = new ns3::olsr::TopologyTuple((*iter));
    PyNs3OlsrTopologyTuple_wrapper_registry[(void *) py_TopologyTuple->obj] = (PyObject *) py_TopologyTuple;
    py_retval = Py_BuildValue((char *) "N", py_TopologyTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__TopologyTuple(PyObject *value, ns3::olsr::TopologyTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrTopologyTuple *tmp_TopologyTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrTopologyTuple_Type, &tmp_TopologyTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_TopologyTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__TopologyTuple___gt__(PyObject *arg, std::vector< ns3::olsr::TopologyTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__TopologyTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::TopologyTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__TopologyTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__TopologyTuple___gt__ instance, or a list of ns3::olsr::TopologyTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::TopologyTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__TopologyTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__TopologyTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__TopologyTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__TopologyTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::IfaceAssocTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::IfaceAssocTuple >::iterator iter;
    PyNs3OlsrIfaceAssocTuple *py_IfaceAssocTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_IfaceAssocTuple = PyObject_New(PyNs3OlsrIfaceAssocTuple, &PyNs3OlsrIfaceAssocTuple_Type);
    py_IfaceAssocTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_IfaceAssocTuple->obj = new ns3::olsr::IfaceAssocTuple((*iter));
    PyNs3OlsrIfaceAssocTuple_wrapper_registry[(void *) py_IfaceAssocTuple->obj] = (PyObject *) py_IfaceAssocTuple;
    py_retval = Py_BuildValue((char *) "N", py_IfaceAssocTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__IfaceAssocTuple(PyObject *value, ns3::olsr::IfaceAssocTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrIfaceAssocTuple *tmp_IfaceAssocTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrIfaceAssocTuple_Type, &tmp_IfaceAssocTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_IfaceAssocTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__(PyObject *arg, std::vector< ns3::olsr::IfaceAssocTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::IfaceAssocTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__IfaceAssocTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__ instance, or a list of ns3::olsr::IfaceAssocTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::IfaceAssocTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt____tp_iter(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter, &Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::AssociationTuple >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::AssociationTuple >::iterator iter;
    PyNs3OlsrAssociationTuple *py_AssociationTuple;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_AssociationTuple = PyObject_New(PyNs3OlsrAssociationTuple, &PyNs3OlsrAssociationTuple_Type);
    py_AssociationTuple->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_AssociationTuple->obj = new ns3::olsr::AssociationTuple((*iter));
    PyNs3OlsrAssociationTuple_wrapper_registry[(void *) py_AssociationTuple->obj] = (PyObject *) py_AssociationTuple;
    py_retval = Py_BuildValue((char *) "N", py_AssociationTuple);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__AssociationTuple(PyObject *value, ns3::olsr::AssociationTuple *address)
{
    PyObject *py_retval;
    PyNs3OlsrAssociationTuple *tmp_AssociationTuple;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrAssociationTuple_Type, &tmp_AssociationTuple)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_AssociationTuple->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__AssociationTuple___gt__(PyObject *arg, std::vector< ns3::olsr::AssociationTuple > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__AssociationTuple___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::AssociationTuple item;
            if (!_wrap_convert_py2c__ns3__olsr__AssociationTuple(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__AssociationTuple___gt__ instance, or a list of ns3::olsr::AssociationTuple");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt____tp_init(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::AssociationTuple >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__AssociationTuple___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__AssociationTuple___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__AssociationTuple___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__AssociationTuple___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__Association___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__Association___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__Association___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__Association___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__Association___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__Association___gt____tp_iter(Pystd__vector__lt___ns3__olsr__Association___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__Association___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__Association___gt__Iter, &Pystd__vector__lt___ns3__olsr__Association___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::Association >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__Association___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__Association___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::Association >::iterator iter;
    PyNs3OlsrAssociation *py_Association;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Association = PyObject_New(PyNs3OlsrAssociation, &PyNs3OlsrAssociation_Type);
    py_Association->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Association->obj = new ns3::olsr::Association((*iter));
    PyNs3OlsrAssociation_wrapper_registry[(void *) py_Association->obj] = (PyObject *) py_Association;
    py_retval = Py_BuildValue((char *) "N", py_Association);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__Association(PyObject *value, ns3::olsr::Association *address)
{
    PyObject *py_retval;
    PyNs3OlsrAssociation *tmp_Association;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrAssociation_Type, &tmp_Association)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_Association->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__Association___gt__(PyObject *arg, std::vector< ns3::olsr::Association > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__Association___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__Association___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::Association item;
            if (!_wrap_convert_py2c__ns3__olsr__Association(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__Association___gt__ instance, or a list of ns3::olsr::Association");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__Association___gt____tp_init(Pystd__vector__lt___ns3__olsr__Association___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::Association >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__Association___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__Association___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__Association___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__Association___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__Association___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__Association___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__Association___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__Association___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__Association___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__Association___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__Association___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_clear(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_traverse(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_dealloc(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_dealloc(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_iter(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *self)
{
    Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *iter = PyObject_GC_New(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter, &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::vector< ns3::olsr::RoutingTableEntry >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iter(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iternext(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter *self)
{
    PyObject *py_retval;
    std::vector< ns3::olsr::RoutingTableEntry >::iterator iter;
    PyNs3OlsrRoutingTableEntry *py_RoutingTableEntry;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_RoutingTableEntry = PyObject_New(PyNs3OlsrRoutingTableEntry, &PyNs3OlsrRoutingTableEntry_Type);
    py_RoutingTableEntry->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_RoutingTableEntry->obj = new ns3::olsr::RoutingTableEntry((*iter));
    PyNs3OlsrRoutingTableEntry_wrapper_registry[(void *) py_RoutingTableEntry->obj] = (PyObject *) py_RoutingTableEntry;
    py_retval = Py_BuildValue((char *) "N", py_RoutingTableEntry);
    return py_retval;
}

int _wrap_convert_py2c__ns3__olsr__RoutingTableEntry(PyObject *value, ns3::olsr::RoutingTableEntry *address)
{
    PyObject *py_retval;
    PyNs3OlsrRoutingTableEntry *tmp_RoutingTableEntry;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3OlsrRoutingTableEntry_Type, &tmp_RoutingTableEntry)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_RoutingTableEntry->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__vector__lt___ns3__olsr__RoutingTableEntry___gt__(PyObject *arg, std::vector< ns3::olsr::RoutingTableEntry > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type)) {
        *container = *((Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::olsr::RoutingTableEntry item;
            if (!_wrap_convert_py2c__ns3__olsr__RoutingTableEntry(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__ instance, or a list of ns3::olsr::RoutingTableEntry");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_init(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::vector< ns3::olsr::RoutingTableEntry >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__vector__lt___ns3__olsr__RoutingTableEntry___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter",            /* tp_name */
    sizeof(Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter__tp_iternext,     /* tp_iternext */
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
Pystd__set__lt___unsigned_int___gt__Iter__tp_clear(Pystd__set__lt___unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__set__lt___unsigned_int___gt__Iter__tp_traverse(Pystd__set__lt___unsigned_int___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__set__lt___unsigned_int___gt____tp_dealloc(Pystd__set__lt___unsigned_int___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__set__lt___unsigned_int___gt__Iter__tp_dealloc(Pystd__set__lt___unsigned_int___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__set__lt___unsigned_int___gt____tp_iter(Pystd__set__lt___unsigned_int___gt__ *self)
{
    Pystd__set__lt___unsigned_int___gt__Iter *iter = PyObject_GC_New(Pystd__set__lt___unsigned_int___gt__Iter, &Pystd__set__lt___unsigned_int___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::set< unsigned int >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__set__lt___unsigned_int___gt__Iter__tp_iter(Pystd__set__lt___unsigned_int___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__set__lt___unsigned_int___gt__Iter__tp_iternext(Pystd__set__lt___unsigned_int___gt__Iter *self)
{
    PyObject *py_retval;
    std::set< unsigned int >::iterator iter;
    
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


int _wrap_convert_py2c__std__set__lt___unsigned_int___gt__(PyObject *arg, std::set< unsigned int > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__set__lt___unsigned_int___gt___Type)) {
        *container = *((Pystd__set__lt___unsigned_int___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            unsigned int item;
            if (!_wrap_convert_py2c__unsigned_int(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->insert(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__set__lt___unsigned_int___gt__ instance, or a list of unsigned int");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__set__lt___unsigned_int___gt____tp_init(Pystd__set__lt___unsigned_int___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::set< unsigned int >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__set__lt___unsigned_int___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__set__lt___unsigned_int___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__set__lt___unsigned_int___gt__",            /* tp_name */
    sizeof(Pystd__set__lt___unsigned_int___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__set__lt___unsigned_int___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__set__lt___unsigned_int___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__set__lt___unsigned_int___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__set__lt___unsigned_int___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.olsr.Std__set__lt___unsigned_int___gt__Iter",            /* tp_name */
    sizeof(Pystd__set__lt___unsigned_int___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__set__lt___unsigned_int___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__set__lt___unsigned_int___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__set__lt___unsigned_int___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__set__lt___unsigned_int___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__set__lt___unsigned_int___gt__Iter__tp_iternext,     /* tp_iternext */
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
static struct PyModuleDef olsr_olsr_moduledef = {
    PyModuleDef_HEAD_INIT,
    "olsr.olsr",
    NULL,
    -1,
    olsr_olsr_functions,
};
#endif

static PyObject *
initolsr_olsr(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&olsr_olsr_moduledef);
    #else
    m = Py_InitModule3((char *) "olsr.olsr", olsr_olsr_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "_PyNs3OlsrAssociation_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrAssociation_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::Association' class */
    if (PyType_Ready(&PyNs3OlsrAssociation_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Association", (PyObject *) &PyNs3OlsrAssociation_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrAssociationTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrAssociationTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::AssociationTuple' class */
    if (PyType_Ready(&PyNs3OlsrAssociationTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "AssociationTuple", (PyObject *) &PyNs3OlsrAssociationTuple_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrDuplicateTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrDuplicateTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::DuplicateTuple' class */
    if (PyType_Ready(&PyNs3OlsrDuplicateTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "DuplicateTuple", (PyObject *) &PyNs3OlsrDuplicateTuple_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrIfaceAssocTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrIfaceAssocTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::IfaceAssocTuple' class */
    if (PyType_Ready(&PyNs3OlsrIfaceAssocTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "IfaceAssocTuple", (PyObject *) &PyNs3OlsrIfaceAssocTuple_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrLinkTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrLinkTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::LinkTuple' class */
    if (PyType_Ready(&PyNs3OlsrLinkTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "LinkTuple", (PyObject *) &PyNs3OlsrLinkTuple_Type);
    /* Register the 'ns3::olsr::MessageHeader' class */
    PyNs3OlsrMessageHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3OlsrMessageHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "MessageHeader", (PyObject *) &PyNs3OlsrMessageHeader_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMessageHeaderHello_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMessageHeaderHello_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MessageHeader::Hello' class */
    if (PyType_Ready(&PyNs3OlsrMessageHeaderHello_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, (char *) "Hello", (PyObject *) &PyNs3OlsrMessageHeaderHello_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMessageHeaderHelloLinkMessage_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MessageHeader::Hello::LinkMessage' class */
    if (PyType_Ready(&PyNs3OlsrMessageHeaderHelloLinkMessage_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeaderHello_Type.tp_dict, (char *) "LinkMessage", (PyObject *) &PyNs3OlsrMessageHeaderHelloLinkMessage_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMessageHeaderHna_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMessageHeaderHna_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MessageHeader::Hna' class */
    if (PyType_Ready(&PyNs3OlsrMessageHeaderHna_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, (char *) "Hna", (PyObject *) &PyNs3OlsrMessageHeaderHna_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMessageHeaderHnaAssociation_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MessageHeader::Hna::Association' class */
    if (PyType_Ready(&PyNs3OlsrMessageHeaderHnaAssociation_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeaderHna_Type.tp_dict, (char *) "Association", (PyObject *) &PyNs3OlsrMessageHeaderHnaAssociation_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMessageHeaderMid_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMessageHeaderMid_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MessageHeader::Mid' class */
    if (PyType_Ready(&PyNs3OlsrMessageHeaderMid_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, (char *) "Mid", (PyObject *) &PyNs3OlsrMessageHeaderMid_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMessageHeaderTc_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMessageHeaderTc_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MessageHeader::Tc' class */
    if (PyType_Ready(&PyNs3OlsrMessageHeaderTc_Type)) {
        return NULL;
    }
    PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, (char *) "Tc", (PyObject *) &PyNs3OlsrMessageHeaderTc_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrMprSelectorTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrMprSelectorTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::MprSelectorTuple' class */
    if (PyType_Ready(&PyNs3OlsrMprSelectorTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "MprSelectorTuple", (PyObject *) &PyNs3OlsrMprSelectorTuple_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrNeighborTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrNeighborTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::NeighborTuple' class */
    if (PyType_Ready(&PyNs3OlsrNeighborTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "NeighborTuple", (PyObject *) &PyNs3OlsrNeighborTuple_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrOlsrState_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrOlsrState_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::OlsrState' class */
    if (PyType_Ready(&PyNs3OlsrOlsrState_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "OlsrState", (PyObject *) &PyNs3OlsrOlsrState_Type);
    /* Register the 'ns3::olsr::PacketHeader' class */
    PyNs3OlsrPacketHeader_Type.tp_base = &PyNs3Header_Type;
    if (PyType_Ready(&PyNs3OlsrPacketHeader_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "PacketHeader", (PyObject *) &PyNs3OlsrPacketHeader_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::olsr::RoutingProtocol), &PyNs3OlsrRoutingProtocol_Type);
    /* Register the 'ns3::olsr::RoutingProtocol' class */
    PyNs3OlsrRoutingProtocol_Type.tp_base = &PyNs3Ipv4RoutingProtocol_Type;
    if (PyType_Ready(&PyNs3OlsrRoutingProtocol_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RoutingProtocol", (PyObject *) &PyNs3OlsrRoutingProtocol_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrRoutingTableEntry_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrRoutingTableEntry_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::RoutingTableEntry' class */
    if (PyType_Ready(&PyNs3OlsrRoutingTableEntry_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "RoutingTableEntry", (PyObject *) &PyNs3OlsrRoutingTableEntry_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrTopologyTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrTopologyTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::TopologyTuple' class */
    if (PyType_Ready(&PyNs3OlsrTopologyTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "TopologyTuple", (PyObject *) &PyNs3OlsrTopologyTuple_Type);
    PyModule_AddObject(m, (char *) "_PyNs3OlsrTwoHopNeighborTuple_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3OlsrTwoHopNeighborTuple_wrapper_registry, NULL));
    /* Register the 'ns3::olsr::TwoHopNeighborTuple' class */
    if (PyType_Ready(&PyNs3OlsrTwoHopNeighborTuple_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "TwoHopNeighborTuple", (PyObject *) &PyNs3OlsrTwoHopNeighborTuple_Type);
    /* Register the 'std::vector< ns3::Ipv4Address >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ipv4Address___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__Ipv4Address___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ipv4Address___gt__", (PyObject *) &Pystd__vector__lt___ns3__Ipv4Address___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__Ipv4Address___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__Ipv4Address___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::MessageHeader::Hello::LinkMessage >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hello__LinkMessage___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::MessageHeader::Hna::Association >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__MessageHeader__Hna__Association___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::MprSelectorTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__MprSelectorTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__MprSelectorTuple___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::NeighborTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__NeighborTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__NeighborTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__NeighborTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__NeighborTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__NeighborTuple___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::TwoHopNeighborTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__TwoHopNeighborTuple___gt__Iter_Type);
    /* Register the 'ns3::olsr::MprSet' class */
    if (PyType_Ready(&Pyns3__olsr__MprSet_Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pyns3__olsr__MprSetIter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Ns3__olsr__MprSet", (PyObject *) &Pyns3__olsr__MprSet_Type);
    PyModule_AddObject(m, (char *) "Ns3__olsr__MprSetIter", (PyObject *) &Pyns3__olsr__MprSetIter_Type);
    /* Register the 'std::vector< ns3::olsr::LinkTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__LinkTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__LinkTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__LinkTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__LinkTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__LinkTuple___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::TopologyTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__TopologyTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__TopologyTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__TopologyTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__TopologyTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__TopologyTuple___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::IfaceAssocTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__IfaceAssocTuple___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::AssociationTuple >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__AssociationTuple___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__AssociationTuple___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__AssociationTuple___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__AssociationTuple___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__AssociationTuple___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::Association >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__Association___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__Association___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__Association___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__Association___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__Association___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__Association___gt__Iter_Type);
    /* Register the 'std::vector< ns3::olsr::RoutingTableEntry >' class */
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__", (PyObject *) &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter", (PyObject *) &Pystd__vector__lt___ns3__olsr__RoutingTableEntry___gt__Iter_Type);
    /* Register the 'std::set< unsigned int >' class */
    if (PyType_Ready(&Pystd__set__lt___unsigned_int___gt___Type)) {
        return NULL;
    }
    if (PyType_Ready(&Pystd__set__lt___unsigned_int___gt__Iter_Type)) {
        return NULL;
    }
    PyModule_AddObject(m, (char *) "Std__set__lt___unsigned_int___gt__", (PyObject *) &Pystd__set__lt___unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__set__lt___unsigned_int___gt__Iter", (PyObject *) &Pystd__set__lt___unsigned_int___gt__Iter_Type);
    {
        PyObject *tmp_value;
         // ns3::olsr::MessageHeader::HELLO_MESSAGE
        tmp_value = PyLong_FromLong(ns3::olsr::MessageHeader::HELLO_MESSAGE);
        PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, "HELLO_MESSAGE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::olsr::MessageHeader::TC_MESSAGE
        tmp_value = PyLong_FromLong(ns3::olsr::MessageHeader::TC_MESSAGE);
        PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, "TC_MESSAGE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::olsr::MessageHeader::MID_MESSAGE
        tmp_value = PyLong_FromLong(ns3::olsr::MessageHeader::MID_MESSAGE);
        PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, "MID_MESSAGE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::olsr::MessageHeader::HNA_MESSAGE
        tmp_value = PyLong_FromLong(ns3::olsr::MessageHeader::HNA_MESSAGE);
        PyDict_SetItemString((PyObject*) PyNs3OlsrMessageHeader_Type.tp_dict, "HNA_MESSAGE", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::olsr::NeighborTuple::STATUS_NOT_SYM
        tmp_value = PyLong_FromLong(ns3::olsr::NeighborTuple::STATUS_NOT_SYM);
        PyDict_SetItemString((PyObject*) PyNs3OlsrNeighborTuple_Type.tp_dict, "STATUS_NOT_SYM", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::olsr::NeighborTuple::STATUS_SYM
        tmp_value = PyLong_FromLong(ns3::olsr::NeighborTuple::STATUS_SYM);
        PyDict_SetItemString((PyObject*) PyNs3OlsrNeighborTuple_Type.tp_dict, "STATUS_SYM", tmp_value);
        Py_DECREF(tmp_value);
    }
    return m;
}
static PyMethodDef olsr_functions[] = {
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


PyTypeObject *_PyNs3EventGarbageCollector_Type;
std::map<void*, PyObject*> *_PyNs3EventGarbageCollector_wrapper_registry;


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


PyTypeObject *_PyNs3NonCopyable_Type;
std::map<void*, PyObject*> *_PyNs3NonCopyable_wrapper_registry;


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


PyTypeObject *_PyNs3SystemWallClockMs_Type;
std::map<void*, PyObject*> *_PyNs3SystemWallClockMs_wrapper_registry;


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


PyTypeObject *_PyNs3Ipv4_Type;


PyTypeObject *_PyNs3Ipv4AddressChecker_Type;


PyTypeObject *_PyNs3Ipv4AddressValue_Type;


PyTypeObject *_PyNs3Ipv4MaskChecker_Type;


PyTypeObject *_PyNs3Ipv4MaskValue_Type;


PyTypeObject *_PyNs3Ipv4MulticastRoute_Type;


PyTypeObject *_PyNs3Ipv4Route_Type;


PyTypeObject *_PyNs3Ipv4RoutingProtocol_Type;


PyTypeObject *_PyNs3Ipv4StaticRouting_Type;


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
_wrap_PyNs3OlsrHelper__tp_init__0(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::OlsrHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3OlsrHelper__tp_init__1(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3OlsrHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OlsrHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::OlsrHelper(*((PyNs3OlsrHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3OlsrHelper__tp_init(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3OlsrHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3OlsrHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3OlsrHelper_Set(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrHelper_Create(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrHelper_ExcludeInterface(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    unsigned int interface;
    const char *keywords[] = {"node", "interface", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3Node_Type, &node, &interface)) {
        return NULL;
    }
    node_ptr = (node ? node->obj : NULL);
    self->obj->ExcludeInterface(ns3::Ptr< ns3::Node  > (node_ptr), interface);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3OlsrHelper_AssignStreams(PyNs3OlsrHelper *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3OlsrHelper__copy__(PyNs3OlsrHelper *self)
{

    PyNs3OlsrHelper *py_copy;
    py_copy = PyObject_GC_New(PyNs3OlsrHelper, &PyNs3OlsrHelper_Type);
    py_copy->inst_dict = NULL;
    py_copy->obj = new ns3::OlsrHelper(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ipv4RoutingHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3OlsrHelper_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3OlsrHelper_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Create", (PyCFunction) _wrap_PyNs3OlsrHelper_Create, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "ExcludeInterface", (PyCFunction) _wrap_PyNs3OlsrHelper_ExcludeInterface, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3OlsrHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3OlsrHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3OlsrHelper__tp_clear(PyNs3OlsrHelper *self)
{
    Py_CLEAR(self->inst_dict);
        ns3::OlsrHelper *tmp = self->obj;
    self->obj = NULL;
    if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
        delete tmp;
    }
}


static int
PyNs3OlsrHelper__tp_traverse(PyNs3OlsrHelper *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    return 0;
}


static void
_wrap_PyNs3OlsrHelper__tp_dealloc(PyNs3OlsrHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ipv4RoutingHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ipv4RoutingHelper_wrapper_registry.end()) {
        PyNs3Ipv4RoutingHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3OlsrHelper__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3OlsrHelper__tp_richcompare (PyNs3OlsrHelper *PYBINDGEN_UNUSED(self), PyNs3OlsrHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3OlsrHelper_Type)) {
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

PyTypeObject PyNs3OlsrHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "olsr.OlsrHelper",            /* tp_name */
    sizeof(PyNs3OlsrHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3OlsrHelper__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3OlsrHelper__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3OlsrHelper__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3OlsrHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3OlsrHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3OlsrHelper, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3OlsrHelper__tp_init,             /* tp_init */
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
    (char *) "olsr.Std__map__lt___unsigned_int__unsigned_int___gt__",            /* tp_name */
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
    (char *) "olsr.Std__map__lt___unsigned_int__unsigned_int___gt__Iter",            /* tp_name */
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
    (char *) "olsr.Std__vector__lt___unsigned_int___gt__",            /* tp_name */
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
    (char *) "olsr.Std__vector__lt___unsigned_int___gt__Iter",            /* tp_name */
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


/* --- enumerations --- */











































#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef olsr_moduledef = {
    PyModuleDef_HEAD_INIT,
    "olsr",
    NULL,
    -1,
    olsr_functions,
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


MOD_INIT(olsr)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&olsr_moduledef);
    #else
    m = Py_InitModule3((char *) "olsr", olsr_functions, NULL);
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
    /* Import the 'ns3::EventGarbageCollector' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3EventGarbageCollector_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "EventGarbageCollector");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3EventGarbageCollector_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3EventGarbageCollector_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3EventGarbageCollector_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::NonCopyable' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3NonCopyable_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "NonCopyable");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3NonCopyable_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3NonCopyable_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3NonCopyable_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::SystemWallClockMs' class from module 'ns.core' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.core");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3SystemWallClockMs_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "SystemWallClockMs");
    
        if (PyErr_Occurred()) PyErr_Clear();
        PyObject *_cobj = PyObject_GetAttrString(module, (char*) "_PyNs3SystemWallClockMs_wrapper_registry");
        if (_cobj == NULL) {
            _PyNs3SystemWallClockMs_wrapper_registry = NULL;
            PyErr_Clear();
        } else {
            _PyNs3SystemWallClockMs_wrapper_registry = reinterpret_cast< std::map<void*, PyObject*> *> (PyCObject_AsVoidPtr (_cobj));
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
    /* Import the 'ns3::Ipv4StaticRouting' class from module 'ns.internet' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.internet");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3Ipv4StaticRouting_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "Ipv4StaticRouting");
    
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
    /* Register the 'ns3::OlsrHelper' class */
    PyNs3OlsrHelper_Type.tp_base = &PyNs3Ipv4RoutingHelper_Type;
    if (PyType_Ready(&PyNs3OlsrHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "OlsrHelper", (PyObject *) &PyNs3OlsrHelper_Type);
    /* Register the 'std::map< unsigned int, unsigned int >' class */
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__map__lt___unsigned_int__unsigned_int___gt__Iter", (PyObject *) &Pystd__map__lt___unsigned_int__unsigned_int___gt__Iter_Type);
    /* Register the 'std::vector< unsigned int >' class */
    if (PyType_Ready(&Pystd__vector__lt___unsigned_int___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__vector__lt___unsigned_int___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__vector__lt___unsigned_int___gt__", (PyObject *) &Pystd__vector__lt___unsigned_int___gt___Type);
    PyModule_AddObject(m, (char *) "Std__vector__lt___unsigned_int___gt__Iter", (PyObject *) &Pystd__vector__lt___unsigned_int___gt__Iter_Type);
    submodule = initolsr_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initolsr_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initolsr_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    submodule = initolsr_olsr();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "olsr", submodule);
    return MOD_RETURN(m);
}
