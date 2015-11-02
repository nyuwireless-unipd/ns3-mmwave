#include "ns3module.h"
static PyMethodDef mobility_FatalImpl_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef mobility_FatalImpl_moduledef = {
    PyModuleDef_HEAD_INIT,
    "mobility.FatalImpl",
    NULL,
    -1,
    mobility_FatalImpl_functions,
};
#endif

static PyObject *
initmobility_FatalImpl(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&mobility_FatalImpl_moduledef);
    #else
    m = Py_InitModule3((char *) "mobility.FatalImpl", mobility_FatalImpl_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
static PyMethodDef mobility_Hash_Function_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashFunctionFnv1a_Type;


PyTypeObject *_PyNs3HashFunctionHash32_Type;


PyTypeObject *_PyNs3HashFunctionHash64_Type;


PyTypeObject *_PyNs3HashFunctionMurmur3_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef mobility_Hash_Function_moduledef = {
    PyModuleDef_HEAD_INIT,
    "mobility.Hash.Function",
    NULL,
    -1,
    mobility_Hash_Function_functions,
};
#endif

static PyObject *
initmobility_Hash_Function(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&mobility_Hash_Function_moduledef);
    #else
    m = Py_InitModule3((char *) "mobility.Hash.Function", mobility_Hash_Function_functions, NULL);
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
static PyMethodDef mobility_Hash_functions[] = {
    {NULL, NULL, 0, NULL}
};
/* --- classes --- */


PyTypeObject *_PyNs3HashImplementation_Type;

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef mobility_Hash_moduledef = {
    PyModuleDef_HEAD_INIT,
    "mobility.Hash",
    NULL,
    -1,
    mobility_Hash_functions,
};
#endif

static PyObject *
initmobility_Hash(void)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&mobility_Hash_moduledef);
    #else
    m = Py_InitModule3((char *) "mobility.Hash", mobility_Hash_functions, NULL);
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
    submodule = initmobility_Hash_Function();
    if (submodule == NULL) {
        return NULL;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Function", submodule);
    return m;
}
static PyMethodDef mobility_TracedValueCallback_functions[] = {
    {NULL, NULL, 0, NULL}
};
#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef mobility_TracedValueCallback_moduledef = {
    PyModuleDef_HEAD_INIT,
    "mobility.TracedValueCallback",
    NULL,
    -1,
    mobility_TracedValueCallback_functions,
};
#endif

static PyObject *
initmobility_TracedValueCallback(void)
{
    PyObject *m;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&mobility_TracedValueCallback_moduledef);
    #else
    m = Py_InitModule3((char *) "mobility.TracedValueCallback", mobility_TracedValueCallback_functions, NULL);
    #endif
    if (m == NULL) {
        return NULL;
    }
    return m;
}
/* --- module functions --- */


PyObject *
_wrap_mobility_MakeBoxChecker()
{
    PyObject *py_retval;
    ns3::Ptr< ns3::AttributeChecker const > retval;
    PyNs3AttributeChecker *py_AttributeChecker;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = ns3::MakeBoxChecker();
    if (!(const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_AttributeChecker = NULL;
    } else {
        py_AttributeChecker = (PyNs3AttributeChecker *) wrapper_lookup_iter->second;
        Py_INCREF(py_AttributeChecker);
    }
    
    if (py_AttributeChecker == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)))), &PyNs3AttributeChecker_Type);
        py_AttributeChecker = PyObject_New(PyNs3AttributeChecker, wrapper_type);
    
        py_AttributeChecker->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval))->Ref();
        py_AttributeChecker->obj = const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_AttributeChecker->obj] = (PyObject *) py_AttributeChecker;
    }
    py_retval = Py_BuildValue((char *) "N", py_AttributeChecker);
    return py_retval;
}
PyObject * _wrap_mobility_MakeBoxChecker();


PyObject *
_wrap_mobility_MakeRectangleChecker()
{
    PyObject *py_retval;
    ns3::Ptr< ns3::AttributeChecker const > retval;
    PyNs3AttributeChecker *py_AttributeChecker;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = ns3::MakeRectangleChecker();
    if (!(const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_AttributeChecker = NULL;
    } else {
        py_AttributeChecker = (PyNs3AttributeChecker *) wrapper_lookup_iter->second;
        Py_INCREF(py_AttributeChecker);
    }
    
    if (py_AttributeChecker == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)))), &PyNs3AttributeChecker_Type);
        py_AttributeChecker = PyObject_New(PyNs3AttributeChecker, wrapper_type);
    
        py_AttributeChecker->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval))->Ref();
        py_AttributeChecker->obj = const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_AttributeChecker->obj] = (PyObject *) py_AttributeChecker;
    }
    py_retval = Py_BuildValue((char *) "N", py_AttributeChecker);
    return py_retval;
}
PyObject * _wrap_mobility_MakeRectangleChecker();


PyObject *
_wrap_mobility_MakeWaypointChecker()
{
    PyObject *py_retval;
    ns3::Ptr< ns3::AttributeChecker const > retval;
    PyNs3AttributeChecker *py_AttributeChecker;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = ns3::MakeWaypointChecker();
    if (!(const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_AttributeChecker = NULL;
    } else {
        py_AttributeChecker = (PyNs3AttributeChecker *) wrapper_lookup_iter->second;
        Py_INCREF(py_AttributeChecker);
    }
    
    if (py_AttributeChecker == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval)))), &PyNs3AttributeChecker_Type);
        py_AttributeChecker = PyObject_New(PyNs3AttributeChecker, wrapper_type);
    
        py_AttributeChecker->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval))->Ref();
        py_AttributeChecker->obj = const_cast<ns3::AttributeChecker *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_AttributeChecker->obj] = (PyObject *) py_AttributeChecker;
    }
    py_retval = Py_BuildValue((char *) "N", py_AttributeChecker);
    return py_retval;
}
PyObject * _wrap_mobility_MakeWaypointChecker();

static PyMethodDef mobility_functions[] = {
    {(char *) "MakeBoxChecker", (PyCFunction) _wrap_mobility_MakeBoxChecker, METH_NOARGS, NULL },
    {(char *) "MakeRectangleChecker", (PyCFunction) _wrap_mobility_MakeRectangleChecker, METH_NOARGS, NULL },
    {(char *) "MakeWaypointChecker", (PyCFunction) _wrap_mobility_MakeWaypointChecker, METH_NOARGS, NULL },
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


PyTypeObject *_PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3EventImpl_Ns3Empty_Ns3DefaultDeleter__lt__ns3EventImpl__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3HashImplementation_Ns3Empty_Ns3DefaultDeleter__lt__ns3HashImplementation__gt____typeid_map;


PyTypeObject *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt___Type;
pybindgen::TypeMap *_PyNs3SimpleRefCount__Ns3OutputStreamWrapper_Ns3Empty_Ns3DefaultDeleter__lt__ns3OutputStreamWrapper__gt____typeid_map;


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


PyTypeObject *_PyNs3NetDevice_Type;


PyTypeObject *_PyNs3Node_Type;


PyTypeObject *_PyNs3NormalRandomVariable_Type;


PyTypeObject *_PyNs3ObjectFactoryChecker_Type;


PyTypeObject *_PyNs3ObjectFactoryValue_Type;


PyTypeObject *_PyNs3OutputStreamWrapper_Type;


PyTypeObject *_PyNs3ParetoRandomVariable_Type;


PyTypeObject *_PyNs3TimeValue_Type;


PyTypeObject *_PyNs3TypeIdChecker_Type;


PyTypeObject *_PyNs3TypeIdValue_Type;


PyTypeObject *_PyNs3Vector2DChecker_Type;


PyTypeObject *_PyNs3Vector2DValue_Type;


PyTypeObject *_PyNs3Vector3DChecker_Type;


PyTypeObject *_PyNs3Vector3DValue_Type;


PyTypeObject *_PyNs3AddressChecker_Type;


PyTypeObject *_PyNs3AddressValue_Type;


std::map<void*, PyObject*> PyNs3Box_wrapper_registry;
static PyObject* _wrap_PyNs3Box__get_xMax(PyNs3Box *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->xMax);
    return py_retval;
}
static int _wrap_PyNs3Box__set_xMax(PyNs3Box *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->xMax)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Box__get_xMin(PyNs3Box *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->xMin);
    return py_retval;
}
static int _wrap_PyNs3Box__set_xMin(PyNs3Box *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->xMin)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Box__get_yMax(PyNs3Box *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->yMax);
    return py_retval;
}
static int _wrap_PyNs3Box__set_yMax(PyNs3Box *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->yMax)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Box__get_yMin(PyNs3Box *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->yMin);
    return py_retval;
}
static int _wrap_PyNs3Box__set_yMin(PyNs3Box *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->yMin)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Box__get_zMax(PyNs3Box *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->zMax);
    return py_retval;
}
static int _wrap_PyNs3Box__set_zMax(PyNs3Box *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->zMax)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Box__get_zMin(PyNs3Box *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->zMin);
    return py_retval;
}
static int _wrap_PyNs3Box__set_zMin(PyNs3Box *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->zMin)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Box__getsets[] = {
    {
        (char*) "zMax", /* attribute name */
        (getter) _wrap_PyNs3Box__get_zMax, /* C function to get the attribute */
        (setter) _wrap_PyNs3Box__set_zMax, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "yMax", /* attribute name */
        (getter) _wrap_PyNs3Box__get_yMax, /* C function to get the attribute */
        (setter) _wrap_PyNs3Box__set_yMax, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "zMin", /* attribute name */
        (getter) _wrap_PyNs3Box__get_zMin, /* C function to get the attribute */
        (setter) _wrap_PyNs3Box__set_zMin, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "xMax", /* attribute name */
        (getter) _wrap_PyNs3Box__get_xMax, /* C function to get the attribute */
        (setter) _wrap_PyNs3Box__set_xMax, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "xMin", /* attribute name */
        (getter) _wrap_PyNs3Box__get_xMin, /* C function to get the attribute */
        (setter) _wrap_PyNs3Box__set_xMin, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "yMin", /* attribute name */
        (getter) _wrap_PyNs3Box__get_yMin, /* C function to get the attribute */
        (setter) _wrap_PyNs3Box__set_yMin, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Box__tp_init__0(PyNs3Box *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Box *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Box_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Box(*((PyNs3Box *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Box__tp_init__1(PyNs3Box *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    double _xMin;
    double _xMax;
    double _yMin;
    double _yMax;
    double _zMin;
    double _zMax;
    const char *keywords[] = {"_xMin", "_xMax", "_yMin", "_yMax", "_zMin", "_zMax", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddddd", (char **) keywords, &_xMin, &_xMax, &_yMin, &_yMax, &_zMin, &_zMax)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Box(_xMin, _xMax, _yMin, _yMax, _zMin, _zMax);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Box__tp_init__2(PyNs3Box *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Box();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Box__tp_init(PyNs3Box *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Box__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Box__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Box__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Box_GetClosestSide(PyNs3Box *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Box::Side retval;
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        return NULL;
    }
    retval = self->obj->GetClosestSide(*((PyNs3Vector3D *) position)->obj);
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Box_IsInside(PyNs3Box *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        return NULL;
    }
    retval = self->obj->IsInside(*((PyNs3Vector3D *) position)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Box_CalculateIntersection(PyNs3Box *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *current;
    PyNs3Vector3D *speed;
    const char *keywords[] = {"current", "speed", NULL};
    PyNs3Vector3D *py_Vector3D;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Vector3D_Type, &current, &PyNs3Vector3D_Type, &speed)) {
        return NULL;
    }
    ns3::Vector retval = self->obj->CalculateIntersection(*((PyNs3Vector3D *) current)->obj, *((PyNs3Vector3D *) speed)->obj);
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Box__copy__(PyNs3Box *self)
{

    PyNs3Box *py_copy;
    py_copy = PyObject_New(PyNs3Box, &PyNs3Box_Type);
    py_copy->obj = new ns3::Box(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Box_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Box_methods[] = {
    {(char *) "GetClosestSide", (PyCFunction) _wrap_PyNs3Box_GetClosestSide, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsInside", (PyCFunction) _wrap_PyNs3Box_IsInside, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "CalculateIntersection", (PyCFunction) _wrap_PyNs3Box_CalculateIntersection, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Box__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Box__tp_dealloc(PyNs3Box *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Box_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Box_wrapper_registry.end()) {
        PyNs3Box_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Box *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Box__tp_str(PyNs3Box *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Box__tp_richcompare (PyNs3Box *PYBINDGEN_UNUSED(self), PyNs3Box *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Box_Type)) {
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

PyTypeObject PyNs3Box_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.Box",            /* tp_name */
    sizeof(PyNs3Box),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Box__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Box__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Box__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Box_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Box__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Box__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3ConstantVelocityHelper_wrapper_registry;


static int
_wrap_PyNs3ConstantVelocityHelper__tp_init__0(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ConstantVelocityHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ConstantVelocityHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ConstantVelocityHelper(*((PyNs3ConstantVelocityHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3ConstantVelocityHelper__tp_init__1(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::ConstantVelocityHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3ConstantVelocityHelper__tp_init__2(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ConstantVelocityHelper(*((PyNs3Vector3D *) position)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3ConstantVelocityHelper__tp_init__3(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Vector3D *position;
    PyNs3Vector3D *vel;
    const char *keywords[] = {"position", "vel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Vector3D_Type, &position, &PyNs3Vector3D_Type, &vel)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::ConstantVelocityHelper(*((PyNs3Vector3D *) position)->obj, *((PyNs3Vector3D *) vel)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3ConstantVelocityHelper__tp_init(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[4] = {0,};
    retval = _wrap_PyNs3ConstantVelocityHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConstantVelocityHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3ConstantVelocityHelper__tp_init__2(self, args, kwargs, &exceptions[2]);
    if (!exceptions[2]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        return retval;
    }
    retval = _wrap_PyNs3ConstantVelocityHelper__tp_init__3(self, args, kwargs, &exceptions[3]);
    if (!exceptions[3]) {
        Py_DECREF(exceptions[0]);
        Py_DECREF(exceptions[1]);
        Py_DECREF(exceptions[2]);
        return retval;
    }
    error_list = PyList_New(4);
    PyList_SET_ITEM(error_list, 0, PyObject_Str(exceptions[0]));
    Py_DECREF(exceptions[0]);
    PyList_SET_ITEM(error_list, 1, PyObject_Str(exceptions[1]));
    Py_DECREF(exceptions[1]);
    PyList_SET_ITEM(error_list, 2, PyObject_Str(exceptions[2]));
    Py_DECREF(exceptions[2]);
    PyList_SET_ITEM(error_list, 3, PyObject_Str(exceptions[3]));
    Py_DECREF(exceptions[3]);
    PyErr_SetObject(PyExc_TypeError, error_list);
    Py_DECREF(error_list);
    return -1;
}


PyObject *
_wrap_PyNs3ConstantVelocityHelper_Pause(PyNs3ConstantVelocityHelper *self)
{
    PyObject *py_retval;
    
    self->obj->Pause();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantVelocityHelper_GetVelocity(PyNs3ConstantVelocityHelper *self)
{
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = self->obj->GetVelocity();
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantVelocityHelper_GetCurrentPosition(PyNs3ConstantVelocityHelper *self)
{
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = self->obj->GetCurrentPosition();
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantVelocityHelper_Update(PyNs3ConstantVelocityHelper *self)
{
    PyObject *py_retval;
    
    self->obj->Update();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}



PyObject *
_wrap_PyNs3ConstantVelocityHelper_UpdateWithBounds__0(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Rectangle *rectangle;
    const char *keywords[] = {"rectangle", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Rectangle_Type, &rectangle)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->UpdateWithBounds(*((PyNs3Rectangle *) rectangle)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3ConstantVelocityHelper_UpdateWithBounds__1(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Box *bounds;
    const char *keywords[] = {"bounds", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Box_Type, &bounds)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->UpdateWithBounds(*((PyNs3Box *) bounds)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3ConstantVelocityHelper_UpdateWithBounds(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ConstantVelocityHelper_UpdateWithBounds__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConstantVelocityHelper_UpdateWithBounds__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ConstantVelocityHelper_SetPosition(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        return NULL;
    }
    self->obj->SetPosition(*((PyNs3Vector3D *) position)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantVelocityHelper_SetVelocity(PyNs3ConstantVelocityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *vel;
    const char *keywords[] = {"vel", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &vel)) {
        return NULL;
    }
    self->obj->SetVelocity(*((PyNs3Vector3D *) vel)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantVelocityHelper_Unpause(PyNs3ConstantVelocityHelper *self)
{
    PyObject *py_retval;
    
    self->obj->Unpause();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3ConstantVelocityHelper__copy__(PyNs3ConstantVelocityHelper *self)
{

    PyNs3ConstantVelocityHelper *py_copy;
    py_copy = PyObject_New(PyNs3ConstantVelocityHelper, &PyNs3ConstantVelocityHelper_Type);
    py_copy->obj = new ns3::ConstantVelocityHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ConstantVelocityHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ConstantVelocityHelper_methods[] = {
    {(char *) "Pause", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_Pause, METH_NOARGS, NULL },
    {(char *) "GetVelocity", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_GetVelocity, METH_NOARGS, NULL },
    {(char *) "GetCurrentPosition", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_GetCurrentPosition, METH_NOARGS, NULL },
    {(char *) "Update", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_Update, METH_NOARGS, NULL },
    {(char *) "UpdateWithBounds", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_UpdateWithBounds, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPosition", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_SetPosition, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetVelocity", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_SetVelocity, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Unpause", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper_Unpause, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ConstantVelocityHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3ConstantVelocityHelper__tp_dealloc(PyNs3ConstantVelocityHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ConstantVelocityHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ConstantVelocityHelper_wrapper_registry.end()) {
        PyNs3ConstantVelocityHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::ConstantVelocityHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ConstantVelocityHelper__tp_richcompare (PyNs3ConstantVelocityHelper *PYBINDGEN_UNUSED(self), PyNs3ConstantVelocityHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ConstantVelocityHelper_Type)) {
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

PyTypeObject PyNs3ConstantVelocityHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.ConstantVelocityHelper",            /* tp_name */
    sizeof(PyNs3ConstantVelocityHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ConstantVelocityHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3ConstantVelocityHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ConstantVelocityHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ConstantVelocityHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3GeographicPositions_wrapper_registry;


static int
_wrap_PyNs3GeographicPositions__tp_init__0(PyNs3GeographicPositions *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::GeographicPositions();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3GeographicPositions__tp_init__1(PyNs3GeographicPositions *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GeographicPositions *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GeographicPositions_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::GeographicPositions(*((PyNs3GeographicPositions *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3GeographicPositions__tp_init(PyNs3GeographicPositions *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3GeographicPositions__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GeographicPositions__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3GeographicPositions_RandCartesianPointsAroundGeographicPoint(PyNs3GeographicPositions *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double originLatitude;
    double originLongitude;
    double maxAltitude;
    int numPoints;
    double maxDistFromOrigin;
    PyNs3UniformRandomVariable *uniRand;
    ns3::UniformRandomVariable *uniRand_ptr;
    const char *keywords[] = {"originLatitude", "originLongitude", "maxAltitude", "numPoints", "maxDistFromOrigin", "uniRand", NULL};
    std::list< ns3::Vector3D > retval;
    Pystd__list__lt___ns3__Vector3D___gt__ *py_std__list__lt___ns3__Vector3D___gt__;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddidO!", (char **) keywords, &originLatitude, &originLongitude, &maxAltitude, &numPoints, &maxDistFromOrigin, &PyNs3UniformRandomVariable_Type, &uniRand)) {
        return NULL;
    }
    uniRand_ptr = (uniRand ? uniRand->obj : NULL);
    retval = ns3::GeographicPositions::RandCartesianPointsAroundGeographicPoint(originLatitude, originLongitude, maxAltitude, numPoints, maxDistFromOrigin, ns3::Ptr< ns3::UniformRandomVariable  > (uniRand_ptr));
    py_std__list__lt___ns3__Vector3D___gt__ = PyObject_New(Pystd__list__lt___ns3__Vector3D___gt__, &Pystd__list__lt___ns3__Vector3D___gt___Type);
    py_std__list__lt___ns3__Vector3D___gt__->obj = new std::list< ns3::Vector3D >(retval);
    py_retval = Py_BuildValue((char *) "N", py_std__list__lt___ns3__Vector3D___gt__);
    return py_retval;
}


PyObject *
_wrap_PyNs3GeographicPositions_GeographicToCartesianCoordinates(PyNs3GeographicPositions *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double latitude;
    double longitude;
    double altitude;
    ns3::GeographicPositions::EarthSpheroidType sphType;
    const char *keywords[] = {"latitude", "longitude", "altitude", "sphType", NULL};
    PyNs3Vector3D *py_Vector3D;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddi", (char **) keywords, &latitude, &longitude, &altitude, &sphType)) {
        return NULL;
    }
    ns3::Vector retval = ns3::GeographicPositions::GeographicToCartesianCoordinates(latitude, longitude, altitude, sphType);
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


static PyObject*
_wrap_PyNs3GeographicPositions__copy__(PyNs3GeographicPositions *self)
{

    PyNs3GeographicPositions *py_copy;
    py_copy = PyObject_New(PyNs3GeographicPositions, &PyNs3GeographicPositions_Type);
    py_copy->obj = new ns3::GeographicPositions(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3GeographicPositions_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GeographicPositions_methods[] = {
    {(char *) "RandCartesianPointsAroundGeographicPoint", (PyCFunction) _wrap_PyNs3GeographicPositions_RandCartesianPointsAroundGeographicPoint, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "GeographicToCartesianCoordinates", (PyCFunction) _wrap_PyNs3GeographicPositions_GeographicToCartesianCoordinates, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GeographicPositions__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3GeographicPositions__tp_dealloc(PyNs3GeographicPositions *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3GeographicPositions_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3GeographicPositions_wrapper_registry.end()) {
        PyNs3GeographicPositions_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::GeographicPositions *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GeographicPositions__tp_richcompare (PyNs3GeographicPositions *PYBINDGEN_UNUSED(self), PyNs3GeographicPositions *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GeographicPositions_Type)) {
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

PyTypeObject PyNs3GeographicPositions_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.GeographicPositions",            /* tp_name */
    sizeof(PyNs3GeographicPositions),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GeographicPositions__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3GeographicPositions__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GeographicPositions_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GeographicPositions__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3MobilityHelper_wrapper_registry;


static int
_wrap_PyNs3MobilityHelper__tp_init__0(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3MobilityHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MobilityHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::MobilityHelper(*((PyNs3MobilityHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3MobilityHelper__tp_init__1(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::MobilityHelper();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3MobilityHelper__tp_init(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3MobilityHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MobilityHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3MobilityHelper_SetPositionAllocator__0(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3PositionAllocator *allocator;
    ns3::PositionAllocator *allocator_ptr;
    const char *keywords[] = {"allocator", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PositionAllocator_Type, &allocator)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    allocator_ptr = (allocator ? allocator->obj : NULL);
    self->obj->SetPositionAllocator(ns3::Ptr< ns3::PositionAllocator  > (allocator_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MobilityHelper_SetPositionAllocator__1(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    const char *n5 = NULL;
    Py_ssize_t n5_len;
    PyNs3AttributeValue *v5 = NULL;
    ns3::EmptyAttributeValue v5_default = ns3::EmptyAttributeValue();
    const char *n6 = NULL;
    Py_ssize_t n6_len;
    PyNs3AttributeValue *v6 = NULL;
    ns3::EmptyAttributeValue v6_default = ns3::EmptyAttributeValue();
    const char *n7 = NULL;
    Py_ssize_t n7_len;
    PyNs3AttributeValue *v7 = NULL;
    ns3::EmptyAttributeValue v7_default = ns3::EmptyAttributeValue();
    const char *n8 = NULL;
    Py_ssize_t n8_len;
    PyNs3AttributeValue *v8 = NULL;
    ns3::EmptyAttributeValue v8_default = ns3::EmptyAttributeValue();
    const char *n9 = NULL;
    Py_ssize_t n9_len;
    PyNs3AttributeValue *v9 = NULL;
    ns3::EmptyAttributeValue v9_default = ns3::EmptyAttributeValue();
    const char *keywords[] = {"type", "n1", "v1", "n2", "v2", "n3", "v3", "n4", "v4", "n5", "v5", "n6", "v6", "n7", "v7", "n8", "v8", "n9", "v9", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|s#O!s#O!s#O!s#O!s#O!s#O!s#O!s#O!s#O!", (char **) keywords, &type, &type_len, &n1, &n1_len, &PyNs3AttributeValue_Type, &v1, &n2, &n2_len, &PyNs3AttributeValue_Type, &v2, &n3, &n3_len, &PyNs3AttributeValue_Type, &v3, &n4, &n4_len, &PyNs3AttributeValue_Type, &v4, &n5, &n5_len, &PyNs3AttributeValue_Type, &v5, &n6, &n6_len, &PyNs3AttributeValue_Type, &v6, &n7, &n7_len, &PyNs3AttributeValue_Type, &v7, &n8, &n8_len, &PyNs3AttributeValue_Type, &v8, &n9, &n9_len, &PyNs3AttributeValue_Type, &v9)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->SetPositionAllocator(std::string(type, type_len), (n1 ? std::string(n1, n1_len) : ""), (v1 ? (*((PyNs3AttributeValue *) v1)->obj) : v1_default), (n2 ? std::string(n2, n2_len) : ""), (v2 ? (*((PyNs3AttributeValue *) v2)->obj) : v2_default), (n3 ? std::string(n3, n3_len) : ""), (v3 ? (*((PyNs3AttributeValue *) v3)->obj) : v3_default), (n4 ? std::string(n4, n4_len) : ""), (v4 ? (*((PyNs3AttributeValue *) v4)->obj) : v4_default), (n5 ? std::string(n5, n5_len) : ""), (v5 ? (*((PyNs3AttributeValue *) v5)->obj) : v5_default), (n6 ? std::string(n6, n6_len) : ""), (v6 ? (*((PyNs3AttributeValue *) v6)->obj) : v6_default), (n7 ? std::string(n7, n7_len) : ""), (v7 ? (*((PyNs3AttributeValue *) v7)->obj) : v7_default), (n8 ? std::string(n8, n8_len) : ""), (v8 ? (*((PyNs3AttributeValue *) v8)->obj) : v8_default), (n9 ? std::string(n9, n9_len) : ""), (v9 ? (*((PyNs3AttributeValue *) v9)->obj) : v9_default));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3MobilityHelper_SetPositionAllocator(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3MobilityHelper_SetPositionAllocator__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MobilityHelper_SetPositionAllocator__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3MobilityHelper_EnableAsciiAll(PyNs3MobilityHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream)) {
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    ns3::MobilityHelper::EnableAsciiAll(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityHelper_GetDistanceSquaredBetween(PyNs3MobilityHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3Node *n1;
    ns3::Node *n1_ptr;
    PyNs3Node *n2;
    ns3::Node *n2_ptr;
    const char *keywords[] = {"n1", "n2", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Node_Type, &n1, &PyNs3Node_Type, &n2)) {
        return NULL;
    }
    n1_ptr = (n1 ? n1->obj : NULL);
    n2_ptr = (n2 ? n2->obj : NULL);
    retval = ns3::MobilityHelper::GetDistanceSquaredBetween(ns3::Ptr< ns3::Node  > (n1_ptr), ns3::Ptr< ns3::Node  > (n2_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityHelper_SetMobilityModel(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
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
    const char *n5 = NULL;
    Py_ssize_t n5_len;
    PyNs3AttributeValue *v5 = NULL;
    ns3::EmptyAttributeValue v5_default = ns3::EmptyAttributeValue();
    const char *n6 = NULL;
    Py_ssize_t n6_len;
    PyNs3AttributeValue *v6 = NULL;
    ns3::EmptyAttributeValue v6_default = ns3::EmptyAttributeValue();
    const char *n7 = NULL;
    Py_ssize_t n7_len;
    PyNs3AttributeValue *v7 = NULL;
    ns3::EmptyAttributeValue v7_default = ns3::EmptyAttributeValue();
    const char *n8 = NULL;
    Py_ssize_t n8_len;
    PyNs3AttributeValue *v8 = NULL;
    ns3::EmptyAttributeValue v8_default = ns3::EmptyAttributeValue();
    const char *n9 = NULL;
    Py_ssize_t n9_len;
    PyNs3AttributeValue *v9 = NULL;
    ns3::EmptyAttributeValue v9_default = ns3::EmptyAttributeValue();
    const char *keywords[] = {"type", "n1", "v1", "n2", "v2", "n3", "v3", "n4", "v4", "n5", "v5", "n6", "v6", "n7", "v7", "n8", "v8", "n9", "v9", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#|s#O!s#O!s#O!s#O!s#O!s#O!s#O!s#O!s#O!", (char **) keywords, &type, &type_len, &n1, &n1_len, &PyNs3AttributeValue_Type, &v1, &n2, &n2_len, &PyNs3AttributeValue_Type, &v2, &n3, &n3_len, &PyNs3AttributeValue_Type, &v3, &n4, &n4_len, &PyNs3AttributeValue_Type, &v4, &n5, &n5_len, &PyNs3AttributeValue_Type, &v5, &n6, &n6_len, &PyNs3AttributeValue_Type, &v6, &n7, &n7_len, &PyNs3AttributeValue_Type, &v7, &n8, &n8_len, &PyNs3AttributeValue_Type, &v8, &n9, &n9_len, &PyNs3AttributeValue_Type, &v9)) {
        return NULL;
    }
    self->obj->SetMobilityModel(std::string(type, type_len), (n1 ? std::string(n1, n1_len) : ""), (v1 ? (*((PyNs3AttributeValue *) v1)->obj) : v1_default), (n2 ? std::string(n2, n2_len) : ""), (v2 ? (*((PyNs3AttributeValue *) v2)->obj) : v2_default), (n3 ? std::string(n3, n3_len) : ""), (v3 ? (*((PyNs3AttributeValue *) v3)->obj) : v3_default), (n4 ? std::string(n4, n4_len) : ""), (v4 ? (*((PyNs3AttributeValue *) v4)->obj) : v4_default), (n5 ? std::string(n5, n5_len) : ""), (v5 ? (*((PyNs3AttributeValue *) v5)->obj) : v5_default), (n6 ? std::string(n6, n6_len) : ""), (v6 ? (*((PyNs3AttributeValue *) v6)->obj) : v6_default), (n7 ? std::string(n7, n7_len) : ""), (v7 ? (*((PyNs3AttributeValue *) v7)->obj) : v7_default), (n8 ? std::string(n8, n8_len) : ""), (v8 ? (*((PyNs3AttributeValue *) v8)->obj) : v8_default), (n9 ? std::string(n9, n9_len) : ""), (v9 ? (*((PyNs3AttributeValue *) v9)->obj) : v9_default));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityHelper_InstallAll(PyNs3MobilityHelper *self)
{
    PyObject *py_retval;
    
    self->obj->InstallAll();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityHelper_PopReferenceMobilityModel(PyNs3MobilityHelper *self)
{
    PyObject *py_retval;
    
    self->obj->PopReferenceMobilityModel();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityHelper_GetMobilityModelType(PyNs3MobilityHelper *self)
{
    PyObject *py_retval;
    std::string retval;
    
    retval = self->obj->GetMobilityModelType();
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}



PyObject *
_wrap_PyNs3MobilityHelper_EnableAscii__0(PyNs3MobilityHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3OutputStreamWrapper *stream;
    ns3::OutputStreamWrapper *stream_ptr;
    unsigned int nodeid;
    const char *keywords[] = {"stream", "nodeid", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!I", (char **) keywords, &PyNs3OutputStreamWrapper_Type, &stream, &nodeid)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    stream_ptr = (stream ? stream->obj : NULL);
    ns3::MobilityHelper::EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), nodeid);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MobilityHelper_EnableAscii__1(PyNs3MobilityHelper *PYBINDGEN_UNUSED(dummy), PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    ns3::MobilityHelper::EnableAscii(ns3::Ptr< ns3::OutputStreamWrapper  > (stream_ptr), *((PyNs3NodeContainer *) n)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3MobilityHelper_EnableAscii(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3MobilityHelper_EnableAscii__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MobilityHelper_EnableAscii__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3MobilityHelper_Install__0(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Node *node;
    ns3::Node *node_ptr;
    const char *keywords[] = {"node", NULL};
    
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
    self->obj->Install(ns3::Ptr< ns3::Node  > (node_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MobilityHelper_Install__1(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *nodeName;
    Py_ssize_t nodeName_len;
    const char *keywords[] = {"nodeName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &nodeName, &nodeName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Install(std::string(nodeName, nodeName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MobilityHelper_Install__2(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3NodeContainer *container;
    const char *keywords[] = {"container", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3NodeContainer_Type, &container)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->Install(*((PyNs3NodeContainer *) container)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3MobilityHelper_Install(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3MobilityHelper_Install__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MobilityHelper_Install__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3MobilityHelper_Install__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3MobilityHelper_AssignStreams(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
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



PyObject *
_wrap_PyNs3MobilityHelper_PushReferenceMobilityModel__0(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    PyNs3Object *reference;
    ns3::Object *reference_ptr;
    const char *keywords[] = {"reference", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Object_Type, &reference)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    reference_ptr = (reference ? reference->obj : NULL);
    self->obj->PushReferenceMobilityModel(ns3::Ptr< ns3::Object  > (reference_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
_wrap_PyNs3MobilityHelper_PushReferenceMobilityModel__1(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyObject *py_retval;
    const char *referenceName;
    Py_ssize_t referenceName_len;
    const char *keywords[] = {"referenceName", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &referenceName, &referenceName_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return NULL;
    }
    self->obj->PushReferenceMobilityModel(std::string(referenceName, referenceName_len));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject * _wrap_PyNs3MobilityHelper_PushReferenceMobilityModel(PyNs3MobilityHelper *self, PyObject *args, PyObject *kwargs)
{
    PyObject * retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3MobilityHelper_PushReferenceMobilityModel__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MobilityHelper_PushReferenceMobilityModel__1(self, args, kwargs, &exceptions[1]);
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


static PyObject*
_wrap_PyNs3MobilityHelper__copy__(PyNs3MobilityHelper *self)
{

    PyNs3MobilityHelper *py_copy;
    py_copy = PyObject_New(PyNs3MobilityHelper, &PyNs3MobilityHelper_Type);
    py_copy->obj = new ns3::MobilityHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3MobilityHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3MobilityHelper_methods[] = {
    {(char *) "SetPositionAllocator", (PyCFunction) _wrap_PyNs3MobilityHelper_SetPositionAllocator, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "EnableAsciiAll", (PyCFunction) _wrap_PyNs3MobilityHelper_EnableAsciiAll, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "GetDistanceSquaredBetween", (PyCFunction) _wrap_PyNs3MobilityHelper_GetDistanceSquaredBetween, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "SetMobilityModel", (PyCFunction) _wrap_PyNs3MobilityHelper_SetMobilityModel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "InstallAll", (PyCFunction) _wrap_PyNs3MobilityHelper_InstallAll, METH_NOARGS, NULL },
    {(char *) "PopReferenceMobilityModel", (PyCFunction) _wrap_PyNs3MobilityHelper_PopReferenceMobilityModel, METH_NOARGS, NULL },
    {(char *) "GetMobilityModelType", (PyCFunction) _wrap_PyNs3MobilityHelper_GetMobilityModelType, METH_NOARGS, NULL },
    {(char *) "EnableAscii", (PyCFunction) _wrap_PyNs3MobilityHelper_EnableAscii, METH_KEYWORDS|METH_VARARGS|METH_STATIC, NULL },
    {(char *) "Install", (PyCFunction) _wrap_PyNs3MobilityHelper_Install, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3MobilityHelper_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "PushReferenceMobilityModel", (PyCFunction) _wrap_PyNs3MobilityHelper_PushReferenceMobilityModel, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3MobilityHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3MobilityHelper__tp_dealloc(PyNs3MobilityHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3MobilityHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3MobilityHelper_wrapper_registry.end()) {
        PyNs3MobilityHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::MobilityHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3MobilityHelper__tp_richcompare (PyNs3MobilityHelper *PYBINDGEN_UNUSED(self), PyNs3MobilityHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3MobilityHelper_Type)) {
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

PyTypeObject PyNs3MobilityHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.MobilityHelper",            /* tp_name */
    sizeof(PyNs3MobilityHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3MobilityHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3MobilityHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3MobilityHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3MobilityHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Ns2MobilityHelper_wrapper_registry;


static int
_wrap_PyNs3Ns2MobilityHelper__tp_init__0(PyNs3Ns2MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Ns2MobilityHelper *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Ns2MobilityHelper_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ns2MobilityHelper(*((PyNs3Ns2MobilityHelper *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Ns2MobilityHelper__tp_init__1(PyNs3Ns2MobilityHelper *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    const char *filename;
    Py_ssize_t filename_len;
    const char *keywords[] = {"filename", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#", (char **) keywords, &filename, &filename_len)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Ns2MobilityHelper(std::string(filename, filename_len));
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Ns2MobilityHelper__tp_init(PyNs3Ns2MobilityHelper *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3Ns2MobilityHelper__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Ns2MobilityHelper__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3Ns2MobilityHelper_Install(PyNs3Ns2MobilityHelper *self)
{
    PyObject *py_retval;
    
    self->obj->Install();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3Ns2MobilityHelper__copy__(PyNs3Ns2MobilityHelper *self)
{

    PyNs3Ns2MobilityHelper *py_copy;
    py_copy = PyObject_New(PyNs3Ns2MobilityHelper, &PyNs3Ns2MobilityHelper_Type);
    py_copy->obj = new ns3::Ns2MobilityHelper(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Ns2MobilityHelper_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Ns2MobilityHelper_methods[] = {
    {(char *) "Install", (PyCFunction) _wrap_PyNs3Ns2MobilityHelper_Install, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Ns2MobilityHelper__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Ns2MobilityHelper__tp_dealloc(PyNs3Ns2MobilityHelper *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Ns2MobilityHelper_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Ns2MobilityHelper_wrapper_registry.end()) {
        PyNs3Ns2MobilityHelper_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Ns2MobilityHelper *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3Ns2MobilityHelper__tp_richcompare (PyNs3Ns2MobilityHelper *PYBINDGEN_UNUSED(self), PyNs3Ns2MobilityHelper *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Ns2MobilityHelper_Type)) {
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

PyTypeObject PyNs3Ns2MobilityHelper_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.Ns2MobilityHelper",            /* tp_name */
    sizeof(PyNs3Ns2MobilityHelper),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Ns2MobilityHelper__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3Ns2MobilityHelper__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Ns2MobilityHelper_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Ns2MobilityHelper__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Rectangle_wrapper_registry;
static PyObject* _wrap_PyNs3Rectangle__get_xMax(PyNs3Rectangle *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->xMax);
    return py_retval;
}
static int _wrap_PyNs3Rectangle__set_xMax(PyNs3Rectangle *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->xMax)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Rectangle__get_xMin(PyNs3Rectangle *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->xMin);
    return py_retval;
}
static int _wrap_PyNs3Rectangle__set_xMin(PyNs3Rectangle *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->xMin)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Rectangle__get_yMax(PyNs3Rectangle *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->yMax);
    return py_retval;
}
static int _wrap_PyNs3Rectangle__set_yMax(PyNs3Rectangle *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->yMax)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Rectangle__get_yMin(PyNs3Rectangle *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "d", self->obj->yMin);
    return py_retval;
}
static int _wrap_PyNs3Rectangle__set_yMin(PyNs3Rectangle *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "d", &self->obj->yMin)) {
        Py_DECREF(py_retval);
        return -1;
    }
    Py_DECREF(py_retval);
    return 0;
}
static PyGetSetDef PyNs3Rectangle__getsets[] = {
    {
        (char*) "xMin", /* attribute name */
        (getter) _wrap_PyNs3Rectangle__get_xMin, /* C function to get the attribute */
        (setter) _wrap_PyNs3Rectangle__set_xMin, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "yMin", /* attribute name */
        (getter) _wrap_PyNs3Rectangle__get_yMin, /* C function to get the attribute */
        (setter) _wrap_PyNs3Rectangle__set_yMin, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "yMax", /* attribute name */
        (getter) _wrap_PyNs3Rectangle__get_yMax, /* C function to get the attribute */
        (setter) _wrap_PyNs3Rectangle__set_yMax, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "xMax", /* attribute name */
        (getter) _wrap_PyNs3Rectangle__get_xMax, /* C function to get the attribute */
        (setter) _wrap_PyNs3Rectangle__set_xMax, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Rectangle__tp_init__0(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Rectangle *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Rectangle_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Rectangle(*((PyNs3Rectangle *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Rectangle__tp_init__1(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    double _xMin;
    double _xMax;
    double _yMin;
    double _yMax;
    const char *keywords[] = {"_xMin", "_xMax", "_yMin", "_yMax", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "dddd", (char **) keywords, &_xMin, &_xMax, &_yMin, &_yMax)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Rectangle(_xMin, _xMax, _yMin, _yMax);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Rectangle__tp_init__2(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Rectangle();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Rectangle__tp_init(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Rectangle__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Rectangle__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Rectangle__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3Rectangle_GetClosestSide(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::Rectangle::Side retval;
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        return NULL;
    }
    retval = self->obj->GetClosestSide(*((PyNs3Vector3D *) position)->obj);
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3Rectangle_IsInside(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        return NULL;
    }
    retval = self->obj->IsInside(*((PyNs3Vector3D *) position)->obj);
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3Rectangle_CalculateIntersection(PyNs3Rectangle *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *current;
    PyNs3Vector3D *speed;
    const char *keywords[] = {"current", "speed", NULL};
    PyNs3Vector3D *py_Vector3D;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Vector3D_Type, &current, &PyNs3Vector3D_Type, &speed)) {
        return NULL;
    }
    ns3::Vector retval = self->obj->CalculateIntersection(*((PyNs3Vector3D *) current)->obj, *((PyNs3Vector3D *) speed)->obj);
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


static PyObject*
_wrap_PyNs3Rectangle__copy__(PyNs3Rectangle *self)
{

    PyNs3Rectangle *py_copy;
    py_copy = PyObject_New(PyNs3Rectangle, &PyNs3Rectangle_Type);
    py_copy->obj = new ns3::Rectangle(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Rectangle_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Rectangle_methods[] = {
    {(char *) "GetClosestSide", (PyCFunction) _wrap_PyNs3Rectangle_GetClosestSide, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "IsInside", (PyCFunction) _wrap_PyNs3Rectangle_IsInside, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "CalculateIntersection", (PyCFunction) _wrap_PyNs3Rectangle_CalculateIntersection, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Rectangle__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Rectangle__tp_dealloc(PyNs3Rectangle *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Rectangle_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Rectangle_wrapper_registry.end()) {
        PyNs3Rectangle_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Rectangle *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Rectangle__tp_str(PyNs3Rectangle *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Rectangle__tp_richcompare (PyNs3Rectangle *PYBINDGEN_UNUSED(self), PyNs3Rectangle *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Rectangle_Type)) {
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

PyTypeObject PyNs3Rectangle_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.Rectangle",            /* tp_name */
    sizeof(PyNs3Rectangle),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Rectangle__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Rectangle__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Rectangle__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Rectangle_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Rectangle__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Rectangle__tp_init,             /* tp_init */
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



std::map<void*, PyObject*> PyNs3Waypoint_wrapper_registry;
static PyObject* _wrap_PyNs3Waypoint__get_position(PyNs3Waypoint *self, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(self->obj->position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}
static int _wrap_PyNs3Waypoint__set_position(PyNs3Waypoint *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
{
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        Py_DECREF(py_retval);
        return -1;
    }
    self->obj->position = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    return 0;
}
static PyObject* _wrap_PyNs3Waypoint__get_time(PyNs3Waypoint *self, void * PYBINDGEN_UNUSED(closure))
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
static int _wrap_PyNs3Waypoint__set_time(PyNs3Waypoint *self, PyObject *value, void * PYBINDGEN_UNUSED(closure))
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
static PyGetSetDef PyNs3Waypoint__getsets[] = {
    {
        (char*) "position", /* attribute name */
        (getter) _wrap_PyNs3Waypoint__get_position, /* C function to get the attribute */
        (setter) _wrap_PyNs3Waypoint__set_position, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    {
        (char*) "time", /* attribute name */
        (getter) _wrap_PyNs3Waypoint__get_time, /* C function to get the attribute */
        (setter) _wrap_PyNs3Waypoint__set_time, /* C function to set the attribute */
        NULL, /* optional doc string */
        NULL /* optional additional data for getter and setter */
    },
    { NULL, NULL, NULL, NULL, NULL }
};


static int
_wrap_PyNs3Waypoint__tp_init__0(PyNs3Waypoint *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Waypoint *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Waypoint_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Waypoint(*((PyNs3Waypoint *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Waypoint__tp_init__1(PyNs3Waypoint *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Time *waypointTime;
    PyNs3Vector3D *waypointPosition;
    const char *keywords[] = {"waypointTime", "waypointPosition", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Time_Type, &waypointTime, &PyNs3Vector3D_Type, &waypointPosition)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::Waypoint(*((PyNs3Time *) waypointTime)->obj, *((PyNs3Vector3D *) waypointPosition)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3Waypoint__tp_init__2(PyNs3Waypoint *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::Waypoint();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3Waypoint__tp_init(PyNs3Waypoint *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3Waypoint__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3Waypoint__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3Waypoint__tp_init__2(self, args, kwargs, &exceptions[2]);
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


static PyObject*
_wrap_PyNs3Waypoint__copy__(PyNs3Waypoint *self)
{

    PyNs3Waypoint *py_copy;
    py_copy = PyObject_New(PyNs3Waypoint, &PyNs3Waypoint_Type);
    py_copy->obj = new ns3::Waypoint(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Waypoint_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3Waypoint_methods[] = {
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3Waypoint__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3Waypoint__tp_dealloc(PyNs3Waypoint *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Waypoint_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Waypoint_wrapper_registry.end()) {
        PyNs3Waypoint_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
        ns3::Waypoint *tmp = self->obj;
        self->obj = NULL;
        if (!(self->flags&PYBINDGEN_WRAPPER_FLAG_OBJECT_NOT_OWNED)) {
            delete tmp;
        }
    Py_TYPE(self)->tp_free((PyObject*)self);
}



static PyObject *
_wrap_PyNs3Waypoint__tp_str(PyNs3Waypoint *self)
{
    std::ostringstream oss;
    oss << *self->obj;
    return PyUnicode_FromString(oss.str ().c_str ());
}


static PyObject*
_wrap_PyNs3Waypoint__tp_richcompare (PyNs3Waypoint *PYBINDGEN_UNUSED(self), PyNs3Waypoint *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3Waypoint_Type)) {
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

PyTypeObject PyNs3Waypoint_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.Waypoint",            /* tp_name */
    sizeof(PyNs3Waypoint),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3Waypoint__tp_dealloc,        /* tp_dealloc */
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
    (reprfunc)_wrap_PyNs3Waypoint__tp_str,              /* tp_str */
    (getattrofunc)NULL,     /* tp_getattro */
    (setattrofunc)NULL,     /* tp_setattro */
    (PyBufferProcs*)NULL,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)NULL,     /* tp_traverse */
    (inquiry)NULL,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3Waypoint__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3Waypoint_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    PyNs3Waypoint__getsets,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3Waypoint__tp_init,             /* tp_init */
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
PyNs3PositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3PositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3PositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3PositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3PositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3PositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3PositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3PositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3PositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3PositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3PositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3PositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3PositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3PositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3PositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3PositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3PositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    self_obj_before = reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = (ns3::PositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3PositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::PositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = const_cast< ns3::PositionAllocator* >((const ns3::PositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3PositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3PositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3PositionAllocator__PythonHelper::DoDispose()
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
PyNs3PositionAllocator__PythonHelper::DoInitialize()
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
PyNs3PositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3PositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3PositionAllocator__tp_init__0(PyNs3PositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3PositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3PositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3PositionAllocator_Type)
    {
        self->obj = new PyNs3PositionAllocator__PythonHelper(*((PyNs3PositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'PositionAllocator' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3PositionAllocator__tp_init__1(PyNs3PositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3PositionAllocator_Type)
    {
        self->obj = new PyNs3PositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3PositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'PositionAllocator' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3PositionAllocator__tp_init(PyNs3PositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3PositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3PositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3PositionAllocator_GetNext(PyNs3PositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = self->obj->GetNext();
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3PositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::PositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3PositionAllocator_AssignStreams(PyNs3PositionAllocator *self, PyObject *args, PyObject *kwargs)
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

static PyMethodDef PyNs3PositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3PositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3PositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3PositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3PositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3PositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3PositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3PositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3PositionAllocator__tp_clear(PyNs3PositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::PositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3PositionAllocator__tp_traverse(PyNs3PositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3PositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3PositionAllocator__tp_dealloc(PyNs3PositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3PositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3PositionAllocator__tp_richcompare (PyNs3PositionAllocator *PYBINDGEN_UNUSED(self), PyNs3PositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3PositionAllocator_Type)) {
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

PyTypeObject PyNs3PositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.PositionAllocator",            /* tp_name */
    sizeof(PyNs3PositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3PositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3PositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3PositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3PositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3PositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3PositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3PositionAllocator__tp_init,             /* tp_init */
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
PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomBoxPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomBoxPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomBoxPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3RandomBoxPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomBoxPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomBoxPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomBoxPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomBoxPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomBoxPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3RandomBoxPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomBoxPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomBoxPositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3RandomBoxPositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomBoxPositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomBoxPositionAllocator::AssignStreams(stream);
    }
    self_obj_before = reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = (ns3::RandomBoxPositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomBoxPositionAllocator::AssignStreams(stream);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomBoxPositionAllocator::AssignStreams(stream);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomBoxPositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomBoxPositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomBoxPositionAllocator::GetNext();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = const_cast< ns3::RandomBoxPositionAllocator* >((const ns3::RandomBoxPositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomBoxPositionAllocator::GetNext();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomBoxPositionAllocator::GetNext();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomBoxPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3RandomBoxPositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomBoxPositionAllocator__PythonHelper::DoDispose()
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
PyNs3RandomBoxPositionAllocator__PythonHelper::DoInitialize()
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
PyNs3RandomBoxPositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomBoxPositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomBoxPositionAllocator__tp_init__0(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomBoxPositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomBoxPositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomBoxPositionAllocator_Type)
    {
        self->obj = new PyNs3RandomBoxPositionAllocator__PythonHelper(*((PyNs3RandomBoxPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomBoxPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomBoxPositionAllocator(*((PyNs3RandomBoxPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomBoxPositionAllocator__tp_init__1(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomBoxPositionAllocator_Type)
    {
        self->obj = new PyNs3RandomBoxPositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomBoxPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomBoxPositionAllocator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomBoxPositionAllocator__tp_init(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomBoxPositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomBoxPositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomBoxPositionAllocator_GetNext(PyNs3RandomBoxPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomBoxPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3RandomBoxPositionAllocator__PythonHelper*> (self->obj);
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = (helper_class == NULL)? (self->obj->GetNext()) : (self->obj->ns3::RandomBoxPositionAllocator::GetNext());
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomBoxPositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomBoxPositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomBoxPositionAllocator_AssignStreams(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    PyNs3RandomBoxPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3RandomBoxPositionAllocator__PythonHelper*> (self->obj);
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->AssignStreams(stream)) : (self->obj->ns3::RandomBoxPositionAllocator::AssignStreams(stream));
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomBoxPositionAllocator_SetX(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *x;
    ns3::RandomVariableStream *x_ptr;
    const char *keywords[] = {"x", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &x)) {
        return NULL;
    }
    x_ptr = (x ? x->obj : NULL);
    self->obj->SetX(ns3::Ptr< ns3::RandomVariableStream  > (x_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomBoxPositionAllocator_SetY(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *y;
    ns3::RandomVariableStream *y_ptr;
    const char *keywords[] = {"y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &y)) {
        return NULL;
    }
    y_ptr = (y ? y->obj : NULL);
    self->obj->SetY(ns3::Ptr< ns3::RandomVariableStream  > (y_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomBoxPositionAllocator_SetZ(PyNs3RandomBoxPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *z;
    ns3::RandomVariableStream *z_ptr;
    const char *keywords[] = {"z", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &z)) {
        return NULL;
    }
    z_ptr = (z ? z->obj : NULL);
    self->obj->SetZ(ns3::Ptr< ns3::RandomVariableStream  > (z_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomBoxPositionAllocator__copy__(PyNs3RandomBoxPositionAllocator *self)
{

    PyNs3RandomBoxPositionAllocator *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomBoxPositionAllocator, &PyNs3RandomBoxPositionAllocator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomBoxPositionAllocator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomBoxPositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetX", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator_SetX, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetY", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator_SetY, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetZ", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator_SetZ, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RandomBoxPositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomBoxPositionAllocator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomBoxPositionAllocator__tp_clear(PyNs3RandomBoxPositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomBoxPositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomBoxPositionAllocator__tp_traverse(PyNs3RandomBoxPositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomBoxPositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomBoxPositionAllocator__tp_dealloc(PyNs3RandomBoxPositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomBoxPositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomBoxPositionAllocator__tp_richcompare (PyNs3RandomBoxPositionAllocator *PYBINDGEN_UNUSED(self), PyNs3RandomBoxPositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomBoxPositionAllocator_Type)) {
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

PyTypeObject PyNs3RandomBoxPositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RandomBoxPositionAllocator",            /* tp_name */
    sizeof(PyNs3RandomBoxPositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomBoxPositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomBoxPositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomBoxPositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomBoxPositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomBoxPositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomBoxPositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomBoxPositionAllocator__tp_init,             /* tp_init */
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
PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomDiscPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3RandomDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomDiscPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomDiscPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3RandomDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomDiscPositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3RandomDiscPositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDiscPositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomDiscPositionAllocator::AssignStreams(stream);
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = (ns3::RandomDiscPositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomDiscPositionAllocator::AssignStreams(stream);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomDiscPositionAllocator::AssignStreams(stream);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomDiscPositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDiscPositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomDiscPositionAllocator::GetNext();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = const_cast< ns3::RandomDiscPositionAllocator* >((const ns3::RandomDiscPositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomDiscPositionAllocator::GetNext();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomDiscPositionAllocator::GetNext();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3RandomDiscPositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomDiscPositionAllocator__PythonHelper::DoDispose()
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
PyNs3RandomDiscPositionAllocator__PythonHelper::DoInitialize()
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
PyNs3RandomDiscPositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomDiscPositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomDiscPositionAllocator__tp_init__0(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomDiscPositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomDiscPositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomDiscPositionAllocator_Type)
    {
        self->obj = new PyNs3RandomDiscPositionAllocator__PythonHelper(*((PyNs3RandomDiscPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomDiscPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomDiscPositionAllocator(*((PyNs3RandomDiscPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomDiscPositionAllocator__tp_init__1(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomDiscPositionAllocator_Type)
    {
        self->obj = new PyNs3RandomDiscPositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomDiscPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomDiscPositionAllocator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomDiscPositionAllocator__tp_init(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomDiscPositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomDiscPositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomDiscPositionAllocator_GetNext(PyNs3RandomDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomDiscPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3RandomDiscPositionAllocator__PythonHelper*> (self->obj);
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = (helper_class == NULL)? (self->obj->GetNext()) : (self->obj->ns3::RandomDiscPositionAllocator::GetNext());
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomDiscPositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomDiscPositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomDiscPositionAllocator_SetRho(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *rho;
    ns3::RandomVariableStream *rho_ptr;
    const char *keywords[] = {"rho", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &rho)) {
        return NULL;
    }
    rho_ptr = (rho ? rho->obj : NULL);
    self->obj->SetRho(ns3::Ptr< ns3::RandomVariableStream  > (rho_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomDiscPositionAllocator_SetTheta(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *theta;
    ns3::RandomVariableStream *theta_ptr;
    const char *keywords[] = {"theta", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &theta)) {
        return NULL;
    }
    theta_ptr = (theta ? theta->obj : NULL);
    self->obj->SetTheta(ns3::Ptr< ns3::RandomVariableStream  > (theta_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomDiscPositionAllocator_AssignStreams(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    PyNs3RandomDiscPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3RandomDiscPositionAllocator__PythonHelper*> (self->obj);
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->AssignStreams(stream)) : (self->obj->ns3::RandomDiscPositionAllocator::AssignStreams(stream));
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomDiscPositionAllocator_SetX(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double x;
    const char *keywords[] = {"x", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &x)) {
        return NULL;
    }
    self->obj->SetX(x);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomDiscPositionAllocator_SetY(PyNs3RandomDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double y;
    const char *keywords[] = {"y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &y)) {
        return NULL;
    }
    self->obj->SetY(y);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomDiscPositionAllocator__copy__(PyNs3RandomDiscPositionAllocator *self)
{

    PyNs3RandomDiscPositionAllocator *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomDiscPositionAllocator, &PyNs3RandomDiscPositionAllocator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomDiscPositionAllocator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomDiscPositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRho", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_SetRho, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetTheta", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_SetTheta, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetX", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_SetX, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetY", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator_SetY, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RandomDiscPositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomDiscPositionAllocator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomDiscPositionAllocator__tp_clear(PyNs3RandomDiscPositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomDiscPositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomDiscPositionAllocator__tp_traverse(PyNs3RandomDiscPositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomDiscPositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomDiscPositionAllocator__tp_dealloc(PyNs3RandomDiscPositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomDiscPositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomDiscPositionAllocator__tp_richcompare (PyNs3RandomDiscPositionAllocator *PYBINDGEN_UNUSED(self), PyNs3RandomDiscPositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomDiscPositionAllocator_Type)) {
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

PyTypeObject PyNs3RandomDiscPositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RandomDiscPositionAllocator",            /* tp_name */
    sizeof(PyNs3RandomDiscPositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomDiscPositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomDiscPositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomDiscPositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomDiscPositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomDiscPositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomDiscPositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomDiscPositionAllocator__tp_init,             /* tp_init */
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomRectanglePositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomRectanglePositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomRectanglePositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3RandomRectanglePositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomRectanglePositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomRectanglePositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomRectanglePositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomRectanglePositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomRectanglePositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3RandomRectanglePositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomRectanglePositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3RandomRectanglePositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3RandomRectanglePositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomRectanglePositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomRectanglePositionAllocator::AssignStreams(stream);
    }
    self_obj_before = reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = (ns3::RandomRectanglePositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomRectanglePositionAllocator::AssignStreams(stream);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomRectanglePositionAllocator::AssignStreams(stream);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomRectanglePositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomRectanglePositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomRectanglePositionAllocator::GetNext();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = const_cast< ns3::RandomRectanglePositionAllocator* >((const ns3::RandomRectanglePositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomRectanglePositionAllocator::GetNext();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::RandomRectanglePositionAllocator::GetNext();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomRectanglePositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3RandomRectanglePositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::DoDispose()
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::DoInitialize()
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomRectanglePositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomRectanglePositionAllocator__tp_init__0(PyNs3RandomRectanglePositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomRectanglePositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomRectanglePositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomRectanglePositionAllocator_Type)
    {
        self->obj = new PyNs3RandomRectanglePositionAllocator__PythonHelper(*((PyNs3RandomRectanglePositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomRectanglePositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomRectanglePositionAllocator(*((PyNs3RandomRectanglePositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomRectanglePositionAllocator__tp_init__1(PyNs3RandomRectanglePositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomRectanglePositionAllocator_Type)
    {
        self->obj = new PyNs3RandomRectanglePositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomRectanglePositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomRectanglePositionAllocator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomRectanglePositionAllocator__tp_init(PyNs3RandomRectanglePositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomRectanglePositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomRectanglePositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomRectanglePositionAllocator_GetNext(PyNs3RandomRectanglePositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3RandomRectanglePositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3RandomRectanglePositionAllocator__PythonHelper*> (self->obj);
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = (helper_class == NULL)? (self->obj->GetNext()) : (self->obj->ns3::RandomRectanglePositionAllocator::GetNext());
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomRectanglePositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomRectanglePositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomRectanglePositionAllocator_SetX(PyNs3RandomRectanglePositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *x;
    ns3::RandomVariableStream *x_ptr;
    const char *keywords[] = {"x", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &x)) {
        return NULL;
    }
    x_ptr = (x ? x->obj : NULL);
    self->obj->SetX(ns3::Ptr< ns3::RandomVariableStream  > (x_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomRectanglePositionAllocator_SetY(PyNs3RandomRectanglePositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3RandomVariableStream *y;
    ns3::RandomVariableStream *y_ptr;
    const char *keywords[] = {"y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomVariableStream_Type, &y)) {
        return NULL;
    }
    y_ptr = (y ? y->obj : NULL);
    self->obj->SetY(ns3::Ptr< ns3::RandomVariableStream  > (y_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RandomRectanglePositionAllocator_AssignStreams(PyNs3RandomRectanglePositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    PyNs3RandomRectanglePositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3RandomRectanglePositionAllocator__PythonHelper*> (self->obj);
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->AssignStreams(stream)) : (self->obj->ns3::RandomRectanglePositionAllocator::AssignStreams(stream));
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomRectanglePositionAllocator__copy__(PyNs3RandomRectanglePositionAllocator *self)
{

    PyNs3RandomRectanglePositionAllocator *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomRectanglePositionAllocator, &PyNs3RandomRectanglePositionAllocator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomRectanglePositionAllocator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomRectanglePositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3RandomRectanglePositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomRectanglePositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetX", (PyCFunction) _wrap_PyNs3RandomRectanglePositionAllocator_SetX, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetY", (PyCFunction) _wrap_PyNs3RandomRectanglePositionAllocator_SetY, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3RandomRectanglePositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RandomRectanglePositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomRectanglePositionAllocator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomRectanglePositionAllocator__tp_clear(PyNs3RandomRectanglePositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomRectanglePositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomRectanglePositionAllocator__tp_traverse(PyNs3RandomRectanglePositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomRectanglePositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomRectanglePositionAllocator__tp_dealloc(PyNs3RandomRectanglePositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomRectanglePositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomRectanglePositionAllocator__tp_richcompare (PyNs3RandomRectanglePositionAllocator *PYBINDGEN_UNUSED(self), PyNs3RandomRectanglePositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomRectanglePositionAllocator_Type)) {
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

PyTypeObject PyNs3RandomRectanglePositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RandomRectanglePositionAllocator",            /* tp_name */
    sizeof(PyNs3RandomRectanglePositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomRectanglePositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomRectanglePositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomRectanglePositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomRectanglePositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomRectanglePositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomRectanglePositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomRectanglePositionAllocator__tp_init,             /* tp_init */
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
PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3UniformDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3UniformDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3UniformDiscPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3UniformDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3UniformDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3UniformDiscPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3UniformDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3UniformDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3UniformDiscPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3UniformDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3UniformDiscPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3UniformDiscPositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3UniformDiscPositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UniformDiscPositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::UniformDiscPositionAllocator::AssignStreams(stream);
    }
    self_obj_before = reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = (ns3::UniformDiscPositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::UniformDiscPositionAllocator::AssignStreams(stream);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::UniformDiscPositionAllocator::AssignStreams(stream);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3UniformDiscPositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::UniformDiscPositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::UniformDiscPositionAllocator::GetNext();
    }
    self_obj_before = reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = const_cast< ns3::UniformDiscPositionAllocator* >((const ns3::UniformDiscPositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::UniformDiscPositionAllocator::GetNext();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::UniformDiscPositionAllocator::GetNext();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3UniformDiscPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3UniformDiscPositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3UniformDiscPositionAllocator__PythonHelper::DoDispose()
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
PyNs3UniformDiscPositionAllocator__PythonHelper::DoInitialize()
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
PyNs3UniformDiscPositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3UniformDiscPositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3UniformDiscPositionAllocator__tp_init__0(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3UniformDiscPositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3UniformDiscPositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3UniformDiscPositionAllocator_Type)
    {
        self->obj = new PyNs3UniformDiscPositionAllocator__PythonHelper(*((PyNs3UniformDiscPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UniformDiscPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UniformDiscPositionAllocator(*((PyNs3UniformDiscPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3UniformDiscPositionAllocator__tp_init__1(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3UniformDiscPositionAllocator_Type)
    {
        self->obj = new PyNs3UniformDiscPositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3UniformDiscPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::UniformDiscPositionAllocator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3UniformDiscPositionAllocator__tp_init(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3UniformDiscPositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3UniformDiscPositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3UniformDiscPositionAllocator_GetNext(PyNs3UniformDiscPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3UniformDiscPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3UniformDiscPositionAllocator__PythonHelper*> (self->obj);
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = (helper_class == NULL)? (self->obj->GetNext()) : (self->obj->ns3::UniformDiscPositionAllocator::GetNext());
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3UniformDiscPositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::UniformDiscPositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3UniformDiscPositionAllocator_SetRho(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double rho;
    const char *keywords[] = {"rho", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &rho)) {
        return NULL;
    }
    self->obj->SetRho(rho);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UniformDiscPositionAllocator_AssignStreams(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    PyNs3UniformDiscPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3UniformDiscPositionAllocator__PythonHelper*> (self->obj);
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->AssignStreams(stream)) : (self->obj->ns3::UniformDiscPositionAllocator::AssignStreams(stream));
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3UniformDiscPositionAllocator_SetX(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double x;
    const char *keywords[] = {"x", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &x)) {
        return NULL;
    }
    self->obj->SetX(x);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3UniformDiscPositionAllocator_SetY(PyNs3UniformDiscPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double y;
    const char *keywords[] = {"y", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &y)) {
        return NULL;
    }
    self->obj->SetY(y);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3UniformDiscPositionAllocator__copy__(PyNs3UniformDiscPositionAllocator *self)
{

    PyNs3UniformDiscPositionAllocator *py_copy;
    py_copy = PyObject_GC_New(PyNs3UniformDiscPositionAllocator, &PyNs3UniformDiscPositionAllocator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::UniformDiscPositionAllocator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3UniformDiscPositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetRho", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator_SetRho, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetX", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator_SetX, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetY", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator_SetY, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3UniformDiscPositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3UniformDiscPositionAllocator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3UniformDiscPositionAllocator__tp_clear(PyNs3UniformDiscPositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::UniformDiscPositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3UniformDiscPositionAllocator__tp_traverse(PyNs3UniformDiscPositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3UniformDiscPositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3UniformDiscPositionAllocator__tp_dealloc(PyNs3UniformDiscPositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3UniformDiscPositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3UniformDiscPositionAllocator__tp_richcompare (PyNs3UniformDiscPositionAllocator *PYBINDGEN_UNUSED(self), PyNs3UniformDiscPositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3UniformDiscPositionAllocator_Type)) {
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

PyTypeObject PyNs3UniformDiscPositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.UniformDiscPositionAllocator",            /* tp_name */
    sizeof(PyNs3UniformDiscPositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3UniformDiscPositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3UniformDiscPositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3UniformDiscPositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3UniformDiscPositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3UniformDiscPositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3UniformDiscPositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3UniformDiscPositionAllocator__tp_init,             /* tp_init */
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
_wrap_PyNs3BoxChecker__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'BoxChecker' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}

static PyMethodDef PyNs3BoxChecker_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3BoxChecker__tp_dealloc(PyNs3BoxChecker *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::BoxChecker *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BoxChecker__tp_richcompare (PyNs3BoxChecker *PYBINDGEN_UNUSED(self), PyNs3BoxChecker *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BoxChecker_Type)) {
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

PyTypeObject PyNs3BoxChecker_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.BoxChecker",            /* tp_name */
    sizeof(PyNs3BoxChecker),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BoxChecker__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3BoxChecker__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BoxChecker_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BoxChecker__tp_init,             /* tp_init */
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
_wrap_PyNs3BoxValue__tp_init__0(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::BoxValue();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3BoxValue__tp_init__1(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3BoxValue *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3BoxValue_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::BoxValue(*((PyNs3BoxValue *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3BoxValue__tp_init__2(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Box *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Box_Type, &value)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::BoxValue(*((PyNs3Box *) value)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3BoxValue__tp_init(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3BoxValue__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3BoxValue__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3BoxValue__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3BoxValue_Set(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Box *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Box_Type, &value)) {
        return NULL;
    }
    self->obj->Set(*((PyNs3Box *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3BoxValue_Get(PyNs3BoxValue *self)
{
    PyObject *py_retval;
    PyNs3Box *py_Box;
    
    ns3::Box retval = self->obj->Get();
    py_Box = PyObject_New(PyNs3Box, &PyNs3Box_Type);
    py_Box->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Box->obj = new ns3::Box(retval);
    PyNs3Box_wrapper_registry[(void *) py_Box->obj] = (PyObject *) py_Box;
    py_retval = Py_BuildValue((char *) "N", py_Box);
    return py_retval;
}


PyObject *
_wrap_PyNs3BoxValue_Copy(PyNs3BoxValue *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::AttributeValue > retval;
    PyNs3AttributeValue *py_AttributeValue;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->Copy();
    if (!(const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_AttributeValue = NULL;
    } else {
        py_AttributeValue = (PyNs3AttributeValue *) wrapper_lookup_iter->second;
        Py_INCREF(py_AttributeValue);
    }
    
    if (py_AttributeValue == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)))), &PyNs3AttributeValue_Type);
        py_AttributeValue = PyObject_New(PyNs3AttributeValue, wrapper_type);
    
        py_AttributeValue->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval))->Ref();
        py_AttributeValue->obj = const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_AttributeValue->obj] = (PyObject *) py_AttributeValue;
    }
    py_retval = Py_BuildValue((char *) "N", py_AttributeValue);
    return py_retval;
}


PyObject *
_wrap_PyNs3BoxValue_SerializeToString(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    PyNs3AttributeChecker *checker;
    ns3::AttributeChecker *checker_ptr;
    const char *keywords[] = {"checker", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AttributeChecker_Type, &checker)) {
        return NULL;
    }
    checker_ptr = (checker ? checker->obj : NULL);
    retval = self->obj->SerializeToString(ns3::Ptr< ns3::AttributeChecker  > (checker_ptr));
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3BoxValue_DeserializeFromString(PyNs3BoxValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *value;
    Py_ssize_t value_len;
    PyNs3AttributeChecker *checker;
    ns3::AttributeChecker *checker_ptr;
    const char *keywords[] = {"value", "checker", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &value, &value_len, &PyNs3AttributeChecker_Type, &checker)) {
        return NULL;
    }
    checker_ptr = (checker ? checker->obj : NULL);
    retval = self->obj->DeserializeFromString(std::string(value, value_len), ns3::Ptr< ns3::AttributeChecker  > (checker_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3BoxValue__copy__(PyNs3BoxValue *self)
{

    PyNs3BoxValue *py_copy;
    py_copy = PyObject_New(PyNs3BoxValue, &PyNs3BoxValue_Type);
    
    py_copy->obj = new ns3::BoxValue(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3BoxValue_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3BoxValue_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3BoxValue_Get, METH_NOARGS, NULL },
    {(char *) "Copy", (PyCFunction) _wrap_PyNs3BoxValue_Copy, METH_NOARGS, NULL },
    {(char *) "SerializeToString", (PyCFunction) _wrap_PyNs3BoxValue_SerializeToString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeserializeFromString", (PyCFunction) _wrap_PyNs3BoxValue_DeserializeFromString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3BoxValue__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3BoxValue__tp_dealloc(PyNs3BoxValue *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::BoxValue *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3BoxValue__tp_richcompare (PyNs3BoxValue *PYBINDGEN_UNUSED(self), PyNs3BoxValue *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3BoxValue_Type)) {
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

PyTypeObject PyNs3BoxValue_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.BoxValue",            /* tp_name */
    sizeof(PyNs3BoxValue),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3BoxValue__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3BoxValue__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3BoxValue_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3BoxValue__tp_init,             /* tp_init */
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
PyNs3GridPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3GridPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3GridPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3GridPositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3GridPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3GridPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3GridPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3GridPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3GridPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3GridPositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3GridPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3GridPositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3GridPositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GridPositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::GridPositionAllocator::AssignStreams(stream);
    }
    self_obj_before = reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = (ns3::GridPositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::GridPositionAllocator::AssignStreams(stream);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::GridPositionAllocator::AssignStreams(stream);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3GridPositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GridPositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::GridPositionAllocator::GetNext();
    }
    self_obj_before = reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = const_cast< ns3::GridPositionAllocator* >((const ns3::GridPositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::GridPositionAllocator::GetNext();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::GridPositionAllocator::GetNext();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GridPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3GridPositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3GridPositionAllocator__PythonHelper::DoDispose()
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
PyNs3GridPositionAllocator__PythonHelper::DoInitialize()
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
PyNs3GridPositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3GridPositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3GridPositionAllocator__tp_init__0(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GridPositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GridPositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3GridPositionAllocator_Type)
    {
        self->obj = new PyNs3GridPositionAllocator__PythonHelper(*((PyNs3GridPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3GridPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::GridPositionAllocator(*((PyNs3GridPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3GridPositionAllocator__tp_init__1(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3GridPositionAllocator_Type)
    {
        self->obj = new PyNs3GridPositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3GridPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::GridPositionAllocator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3GridPositionAllocator__tp_init(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3GridPositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GridPositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3GridPositionAllocator_GetNext(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3GridPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3GridPositionAllocator__PythonHelper*> (self->obj);
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = (helper_class == NULL)? (self->obj->GetNext()) : (self->obj->ns3::GridPositionAllocator::GetNext());
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_SetDeltaY(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double deltaY;
    const char *keywords[] = {"deltaY", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &deltaY)) {
        return NULL;
    }
    self->obj->SetDeltaY(deltaY);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetN(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->GetN();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_SetDeltaX(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double deltaX;
    const char *keywords[] = {"deltaX", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &deltaX)) {
        return NULL;
    }
    self->obj->SetDeltaX(deltaX);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::GridPositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetLayoutType(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    ns3::GridPositionAllocator::LayoutType retval;
    
    retval = self->obj->GetLayoutType();
    py_retval = Py_BuildValue((char *) "i", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetMinY(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetMinY();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetMinX(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetMinX();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_SetMinY(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double yMin;
    const char *keywords[] = {"yMin", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &yMin)) {
        return NULL;
    }
    self->obj->SetMinY(yMin);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_SetMinX(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double xMin;
    const char *keywords[] = {"xMin", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "d", (char **) keywords, &xMin)) {
        return NULL;
    }
    self->obj->SetMinX(xMin);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_AssignStreams(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    PyNs3GridPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3GridPositionAllocator__PythonHelper*> (self->obj);
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->AssignStreams(stream)) : (self->obj->ns3::GridPositionAllocator::AssignStreams(stream));
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetDeltaY(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetDeltaY();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_GetDeltaX(PyNs3GridPositionAllocator *self)
{
    PyObject *py_retval;
    double retval;
    
    retval = self->obj->GetDeltaX();
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_SetN(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    unsigned int n;
    const char *keywords[] = {"n", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "I", (char **) keywords, &n)) {
        return NULL;
    }
    self->obj->SetN(n);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3GridPositionAllocator_SetLayoutType(PyNs3GridPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    ns3::GridPositionAllocator::LayoutType layoutType;
    const char *keywords[] = {"layoutType", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "i", (char **) keywords, &layoutType)) {
        return NULL;
    }
    self->obj->SetLayoutType(layoutType);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3GridPositionAllocator__copy__(PyNs3GridPositionAllocator *self)
{

    PyNs3GridPositionAllocator *py_copy;
    py_copy = PyObject_GC_New(PyNs3GridPositionAllocator, &PyNs3GridPositionAllocator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::GridPositionAllocator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GridPositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "SetDeltaY", (PyCFunction) _wrap_PyNs3GridPositionAllocator_SetDeltaY, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetN", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetN, METH_NOARGS, NULL },
    {(char *) "SetDeltaX", (PyCFunction) _wrap_PyNs3GridPositionAllocator_SetDeltaX, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetLayoutType", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetLayoutType, METH_NOARGS, NULL },
    {(char *) "GetMinY", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetMinY, METH_NOARGS, NULL },
    {(char *) "GetMinX", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetMinX, METH_NOARGS, NULL },
    {(char *) "SetMinY", (PyCFunction) _wrap_PyNs3GridPositionAllocator_SetMinY, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetMinX", (PyCFunction) _wrap_PyNs3GridPositionAllocator_SetMinX, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3GridPositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetDeltaY", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetDeltaY, METH_NOARGS, NULL },
    {(char *) "GetDeltaX", (PyCFunction) _wrap_PyNs3GridPositionAllocator_GetDeltaX, METH_NOARGS, NULL },
    {(char *) "SetN", (PyCFunction) _wrap_PyNs3GridPositionAllocator_SetN, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetLayoutType", (PyCFunction) _wrap_PyNs3GridPositionAllocator_SetLayoutType, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3GridPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3GridPositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3GridPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3GridPositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GridPositionAllocator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3GridPositionAllocator__tp_clear(PyNs3GridPositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::GridPositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3GridPositionAllocator__tp_traverse(PyNs3GridPositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3GridPositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3GridPositionAllocator__tp_dealloc(PyNs3GridPositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3GridPositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GridPositionAllocator__tp_richcompare (PyNs3GridPositionAllocator *PYBINDGEN_UNUSED(self), PyNs3GridPositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GridPositionAllocator_Type)) {
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

PyTypeObject PyNs3GridPositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.GridPositionAllocator",            /* tp_name */
    sizeof(PyNs3GridPositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GridPositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3GridPositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3GridPositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3GridPositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GridPositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3GridPositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GridPositionAllocator__tp_init,             /* tp_init */
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
PyNs3ListPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ListPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3ListPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3ListPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3ListPositionAllocator__PythonHelper::_wrap_DoInitialize(PyNs3ListPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3ListPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3ListPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3ListPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ListPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3ListPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3ListPositionAllocator__PythonHelper* >(self->obj);
    
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
PyNs3ListPositionAllocator__PythonHelper::_wrap_DoDispose(PyNs3ListPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3ListPositionAllocator__PythonHelper *helper = dynamic_cast< PyNs3ListPositionAllocator__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3ListPositionAllocator__PythonHelper::AssignStreams(int64_t stream)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ListPositionAllocator *self_obj_before;
    PyObject *py_retval;
    int64_t retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "AssignStreams"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ListPositionAllocator::AssignStreams(stream);
    }
    self_obj_before = reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = (ns3::ListPositionAllocator*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "AssignStreams", (char *) "L", stream);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ListPositionAllocator::AssignStreams(stream);
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "L", &retval)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ListPositionAllocator::AssignStreams(stream);
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3ListPositionAllocator__PythonHelper::GetNext() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ListPositionAllocator *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "GetNext"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ListPositionAllocator::GetNext();
    }
    self_obj_before = reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = const_cast< ns3::ListPositionAllocator* >((const ns3::ListPositionAllocator*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "GetNext", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ListPositionAllocator::GetNext();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::ListPositionAllocator::GetNext();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ListPositionAllocator* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ListPositionAllocator__PythonHelper::GetInstanceTypeId() const
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
PyNs3ListPositionAllocator__PythonHelper::DoDispose()
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
PyNs3ListPositionAllocator__PythonHelper::DoInitialize()
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
PyNs3ListPositionAllocator__PythonHelper::NotifyNewAggregate()
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
PyNs3ListPositionAllocator__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ListPositionAllocator__tp_init__0(PyNs3ListPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ListPositionAllocator *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ListPositionAllocator_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ListPositionAllocator_Type)
    {
        self->obj = new PyNs3ListPositionAllocator__PythonHelper(*((PyNs3ListPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ListPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ListPositionAllocator(*((PyNs3ListPositionAllocator *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ListPositionAllocator__tp_init__1(PyNs3ListPositionAllocator *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ListPositionAllocator_Type)
    {
        self->obj = new PyNs3ListPositionAllocator__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ListPositionAllocator__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ListPositionAllocator();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ListPositionAllocator__tp_init(PyNs3ListPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ListPositionAllocator__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ListPositionAllocator__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ListPositionAllocator_GetNext(PyNs3ListPositionAllocator *self)
{
    PyObject *py_retval;
    PyNs3ListPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3ListPositionAllocator__PythonHelper*> (self->obj);
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = (helper_class == NULL)? (self->obj->GetNext()) : (self->obj->ns3::ListPositionAllocator::GetNext());
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3ListPositionAllocator_Add(PyNs3ListPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *v;
    const char *keywords[] = {"v", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &v)) {
        return NULL;
    }
    self->obj->Add(*((PyNs3Vector3D *) v)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3ListPositionAllocator_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ListPositionAllocator::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ListPositionAllocator_AssignStreams(PyNs3ListPositionAllocator *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    int64_t retval;
    int64_t stream;
    PyNs3ListPositionAllocator__PythonHelper *helper_class = dynamic_cast<PyNs3ListPositionAllocator__PythonHelper*> (self->obj);
    const char *keywords[] = {"stream", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "L", (char **) keywords, &stream)) {
        return NULL;
    }
    retval = (helper_class == NULL)? (self->obj->AssignStreams(stream)) : (self->obj->ns3::ListPositionAllocator::AssignStreams(stream));
    py_retval = Py_BuildValue((char *) "L", retval);
    return py_retval;
}


static PyObject*
_wrap_PyNs3ListPositionAllocator__copy__(PyNs3ListPositionAllocator *self)
{

    PyNs3ListPositionAllocator *py_copy;
    py_copy = PyObject_GC_New(PyNs3ListPositionAllocator, &PyNs3ListPositionAllocator_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ListPositionAllocator(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ListPositionAllocator_methods[] = {
    {(char *) "GetNext", (PyCFunction) _wrap_PyNs3ListPositionAllocator_GetNext, METH_NOARGS, NULL },
    {(char *) "Add", (PyCFunction) _wrap_PyNs3ListPositionAllocator_Add, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ListPositionAllocator_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3ListPositionAllocator_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ListPositionAllocator__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ListPositionAllocator__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ListPositionAllocator__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ListPositionAllocator__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ListPositionAllocator__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ListPositionAllocator__tp_clear(PyNs3ListPositionAllocator *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ListPositionAllocator *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ListPositionAllocator__tp_traverse(PyNs3ListPositionAllocator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ListPositionAllocator__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ListPositionAllocator__tp_dealloc(PyNs3ListPositionAllocator *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ListPositionAllocator__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ListPositionAllocator__tp_richcompare (PyNs3ListPositionAllocator *PYBINDGEN_UNUSED(self), PyNs3ListPositionAllocator *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ListPositionAllocator_Type)) {
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

PyTypeObject PyNs3ListPositionAllocator_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.ListPositionAllocator",            /* tp_name */
    sizeof(PyNs3ListPositionAllocator),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ListPositionAllocator__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ListPositionAllocator__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ListPositionAllocator__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ListPositionAllocator__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ListPositionAllocator_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ListPositionAllocator, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ListPositionAllocator__tp_init,             /* tp_init */
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
PyNs3MobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3MobilityModel__PythonHelper *helper = dynamic_cast< PyNs3MobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3MobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3MobilityModel__PythonHelper *helper = dynamic_cast< PyNs3MobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3MobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3MobilityModel__PythonHelper *helper = dynamic_cast< PyNs3MobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3MobilityModel__PythonHelper::_wrap_NotifyCourseChange(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3MobilityModel__PythonHelper *helper = dynamic_cast< PyNs3MobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyCourseChange of class MobilityModel is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyCourseChange__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3MobilityModel__PythonHelper::_wrap_DoDispose(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3MobilityModel__PythonHelper *helper = dynamic_cast< PyNs3MobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3MobilityModel__PythonHelper::DoAssignStreams(int64_t start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", start);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3MobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = const_cast< ns3::MobilityModel* >((const ns3::MobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3MobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = const_cast< ns3::MobilityModel* >((const ns3::MobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3MobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3MobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3MobilityModel__PythonHelper::DoDispose()
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
PyNs3MobilityModel__PythonHelper::DoInitialize()
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
PyNs3MobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3MobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3MobilityModel__tp_init__0(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3MobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3MobilityModel_Type)
    {
        self->obj = new PyNs3MobilityModel__PythonHelper(*((PyNs3MobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3MobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'MobilityModel' cannot be constructed");
        return -1;
    }
    return 0;
}

static int
_wrap_PyNs3MobilityModel__tp_init__1(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3MobilityModel_Type)
    {
        self->obj = new PyNs3MobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3MobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        PyErr_SetString(PyExc_TypeError, "class 'MobilityModel' cannot be constructed");
        return -1;
    }
    return 0;
}

int _wrap_PyNs3MobilityModel__tp_init(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3MobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3MobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3MobilityModel_GetDistanceFrom(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *position;
    ns3::MobilityModel *position_ptr;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MobilityModel_Type, &position)) {
        return NULL;
    }
    position_ptr = (position ? position->obj : NULL);
    retval = self->obj->GetDistanceFrom(ns3::Ptr< ns3::MobilityModel  > (position_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityModel_GetVelocity(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = self->obj->GetVelocity();
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::MobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityModel_GetRelativeSpeed(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    double retval;
    PyNs3MobilityModel *other;
    ns3::MobilityModel *other_ptr;
    const char *keywords[] = {"other", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MobilityModel_Type, &other)) {
        return NULL;
    }
    other_ptr = (other ? other->obj : NULL);
    retval = self->obj->GetRelativeSpeed(ns3::Ptr< ns3::MobilityModel  > (other_ptr));
    py_retval = Py_BuildValue((char *) "d", retval);
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityModel_AssignStreams(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs)
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
_wrap_PyNs3MobilityModel_SetPosition(PyNs3MobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *position;
    const char *keywords[] = {"position", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &position)) {
        return NULL;
    }
    self->obj->SetPosition(*((PyNs3Vector3D *) position)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3MobilityModel_GetPosition(PyNs3MobilityModel *self)
{
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    ns3::Vector retval = self->obj->GetPosition();
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(retval);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}

static PyMethodDef PyNs3MobilityModel_methods[] = {
    {(char *) "GetDistanceFrom", (PyCFunction) _wrap_PyNs3MobilityModel_GetDistanceFrom, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetVelocity", (PyCFunction) _wrap_PyNs3MobilityModel_GetVelocity, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3MobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetRelativeSpeed", (PyCFunction) _wrap_PyNs3MobilityModel_GetRelativeSpeed, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "AssignStreams", (PyCFunction) _wrap_PyNs3MobilityModel_AssignStreams, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetPosition", (PyCFunction) _wrap_PyNs3MobilityModel_SetPosition, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetPosition", (PyCFunction) _wrap_PyNs3MobilityModel_GetPosition, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3MobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3MobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3MobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "NotifyCourseChange", (PyCFunction) PyNs3MobilityModel__PythonHelper::_wrap_NotifyCourseChange, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3MobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static void
PyNs3MobilityModel__tp_clear(PyNs3MobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::MobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3MobilityModel__tp_traverse(PyNs3MobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3MobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3MobilityModel__tp_dealloc(PyNs3MobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3MobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3MobilityModel__tp_richcompare (PyNs3MobilityModel *PYBINDGEN_UNUSED(self), PyNs3MobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3MobilityModel_Type)) {
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

PyTypeObject PyNs3MobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.MobilityModel",            /* tp_name */
    sizeof(PyNs3MobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3MobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3MobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3MobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3MobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3MobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3MobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3MobilityModel__tp_init,             /* tp_init */
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
PyNs3RandomDirection2dMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomDirection2dMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomDirection2dMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomDirection2dMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomDirection2dMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomDirection2dMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomDirection2dMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomDirection2dMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3RandomDirection2dMobilityModel__PythonHelper::DoAssignStreams(int64_t arg0)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDirection2dMobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = (ns3::RandomDirection2dMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", arg0);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3RandomDirection2dMobilityModel__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDirection2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = (ns3::RandomDirection2dMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::Vector
PyNs3RandomDirection2dMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDirection2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = const_cast< ns3::RandomDirection2dMobilityModel* >((const ns3::RandomDirection2dMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomDirection2dMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDirection2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = const_cast< ns3::RandomDirection2dMobilityModel* >((const ns3::RandomDirection2dMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3RandomDirection2dMobilityModel__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDirection2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = (ns3::RandomDirection2dMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3RandomDirection2dMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomDirection2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = (ns3::RandomDirection2dMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomDirection2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3RandomDirection2dMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomDirection2dMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomDirection2dMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomDirection2dMobilityModel__tp_init__0(PyNs3RandomDirection2dMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomDirection2dMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomDirection2dMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomDirection2dMobilityModel_Type)
    {
        self->obj = new PyNs3RandomDirection2dMobilityModel__PythonHelper(*((PyNs3RandomDirection2dMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomDirection2dMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomDirection2dMobilityModel(*((PyNs3RandomDirection2dMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomDirection2dMobilityModel__tp_init__1(PyNs3RandomDirection2dMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomDirection2dMobilityModel_Type)
    {
        self->obj = new PyNs3RandomDirection2dMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomDirection2dMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomDirection2dMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomDirection2dMobilityModel__tp_init(PyNs3RandomDirection2dMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomDirection2dMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomDirection2dMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomDirection2dMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomDirection2dMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomDirection2dMobilityModel__copy__(PyNs3RandomDirection2dMobilityModel *self)
{

    PyNs3RandomDirection2dMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomDirection2dMobilityModel, &PyNs3RandomDirection2dMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomDirection2dMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomDirection2dMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomDirection2dMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomDirection2dMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomDirection2dMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomDirection2dMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomDirection2dMobilityModel__tp_clear(PyNs3RandomDirection2dMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomDirection2dMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomDirection2dMobilityModel__tp_traverse(PyNs3RandomDirection2dMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomDirection2dMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomDirection2dMobilityModel__tp_dealloc(PyNs3RandomDirection2dMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomDirection2dMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomDirection2dMobilityModel__tp_richcompare (PyNs3RandomDirection2dMobilityModel *PYBINDGEN_UNUSED(self), PyNs3RandomDirection2dMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomDirection2dMobilityModel_Type)) {
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

PyTypeObject PyNs3RandomDirection2dMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RandomDirection2dMobilityModel",            /* tp_name */
    sizeof(PyNs3RandomDirection2dMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomDirection2dMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomDirection2dMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomDirection2dMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomDirection2dMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomDirection2dMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomDirection2dMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomDirection2dMobilityModel__tp_init,             /* tp_init */
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
PyNs3RandomWalk2dMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomWalk2dMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomWalk2dMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomWalk2dMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomWalk2dMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomWalk2dMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomWalk2dMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomWalk2dMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3RandomWalk2dMobilityModel__PythonHelper::DoAssignStreams(int64_t arg0)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWalk2dMobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = (ns3::RandomWalk2dMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", arg0);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3RandomWalk2dMobilityModel__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWalk2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = (ns3::RandomWalk2dMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::Vector
PyNs3RandomWalk2dMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWalk2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = const_cast< ns3::RandomWalk2dMobilityModel* >((const ns3::RandomWalk2dMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomWalk2dMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWalk2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = const_cast< ns3::RandomWalk2dMobilityModel* >((const ns3::RandomWalk2dMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3RandomWalk2dMobilityModel__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWalk2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = (ns3::RandomWalk2dMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

void
PyNs3RandomWalk2dMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWalk2dMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = (ns3::RandomWalk2dMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWalk2dMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3RandomWalk2dMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomWalk2dMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomWalk2dMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomWalk2dMobilityModel__tp_init__0(PyNs3RandomWalk2dMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomWalk2dMobilityModel_Type)
    {
        self->obj = new PyNs3RandomWalk2dMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomWalk2dMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomWalk2dMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomWalk2dMobilityModel__tp_init__1(PyNs3RandomWalk2dMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomWalk2dMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomWalk2dMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomWalk2dMobilityModel_Type)
    {
        self->obj = new PyNs3RandomWalk2dMobilityModel__PythonHelper(*((PyNs3RandomWalk2dMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomWalk2dMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomWalk2dMobilityModel(*((PyNs3RandomWalk2dMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomWalk2dMobilityModel__tp_init(PyNs3RandomWalk2dMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomWalk2dMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomWalk2dMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomWalk2dMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomWalk2dMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomWalk2dMobilityModel__copy__(PyNs3RandomWalk2dMobilityModel *self)
{

    PyNs3RandomWalk2dMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomWalk2dMobilityModel, &PyNs3RandomWalk2dMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomWalk2dMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomWalk2dMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomWalk2dMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomWalk2dMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomWalk2dMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomWalk2dMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomWalk2dMobilityModel__tp_clear(PyNs3RandomWalk2dMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomWalk2dMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomWalk2dMobilityModel__tp_traverse(PyNs3RandomWalk2dMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomWalk2dMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomWalk2dMobilityModel__tp_dealloc(PyNs3RandomWalk2dMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomWalk2dMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomWalk2dMobilityModel__tp_richcompare (PyNs3RandomWalk2dMobilityModel *PYBINDGEN_UNUSED(self), PyNs3RandomWalk2dMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomWalk2dMobilityModel_Type)) {
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

PyTypeObject PyNs3RandomWalk2dMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RandomWalk2dMobilityModel",            /* tp_name */
    sizeof(PyNs3RandomWalk2dMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomWalk2dMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomWalk2dMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomWalk2dMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomWalk2dMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomWalk2dMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomWalk2dMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomWalk2dMobilityModel__tp_init,             /* tp_init */
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
PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3RandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3RandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class RandomWaypointMobilityModel is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3RandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_DoDispose(PyNs3RandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3RandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3RandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3RandomWaypointMobilityModel__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::RandomWaypointMobilityModel::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = (ns3::RandomWaypointMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3RandomWaypointMobilityModel__PythonHelper::DoAssignStreams(int64_t arg0)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWaypointMobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = (ns3::RandomWaypointMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", arg0);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomWaypointMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = const_cast< ns3::RandomWaypointMobilityModel* >((const ns3::RandomWaypointMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3RandomWaypointMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = const_cast< ns3::RandomWaypointMobilityModel* >((const ns3::RandomWaypointMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3RandomWaypointMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::RandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = (ns3::RandomWaypointMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3RandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3RandomWaypointMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3RandomWaypointMobilityModel__PythonHelper::DoDispose()
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
PyNs3RandomWaypointMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3RandomWaypointMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3RandomWaypointMobilityModel__tp_init__0(PyNs3RandomWaypointMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3RandomWaypointMobilityModel_Type)
    {
        self->obj = new PyNs3RandomWaypointMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomWaypointMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomWaypointMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3RandomWaypointMobilityModel__tp_init__1(PyNs3RandomWaypointMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RandomWaypointMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RandomWaypointMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3RandomWaypointMobilityModel_Type)
    {
        self->obj = new PyNs3RandomWaypointMobilityModel__PythonHelper(*((PyNs3RandomWaypointMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3RandomWaypointMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::RandomWaypointMobilityModel(*((PyNs3RandomWaypointMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3RandomWaypointMobilityModel__tp_init(PyNs3RandomWaypointMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3RandomWaypointMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RandomWaypointMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3RandomWaypointMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::RandomWaypointMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3RandomWaypointMobilityModel__copy__(PyNs3RandomWaypointMobilityModel *self)
{

    PyNs3RandomWaypointMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3RandomWaypointMobilityModel, &PyNs3RandomWaypointMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::RandomWaypointMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RandomWaypointMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3RandomWaypointMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3RandomWaypointMobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RandomWaypointMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3RandomWaypointMobilityModel__tp_clear(PyNs3RandomWaypointMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::RandomWaypointMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3RandomWaypointMobilityModel__tp_traverse(PyNs3RandomWaypointMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3RandomWaypointMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3RandomWaypointMobilityModel__tp_dealloc(PyNs3RandomWaypointMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3RandomWaypointMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RandomWaypointMobilityModel__tp_richcompare (PyNs3RandomWaypointMobilityModel *PYBINDGEN_UNUSED(self), PyNs3RandomWaypointMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RandomWaypointMobilityModel_Type)) {
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

PyTypeObject PyNs3RandomWaypointMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RandomWaypointMobilityModel",            /* tp_name */
    sizeof(PyNs3RandomWaypointMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RandomWaypointMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3RandomWaypointMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3RandomWaypointMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3RandomWaypointMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RandomWaypointMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3RandomWaypointMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RandomWaypointMobilityModel__tp_init,             /* tp_init */
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
_wrap_PyNs3RectangleChecker__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'RectangleChecker' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}

static PyMethodDef PyNs3RectangleChecker_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3RectangleChecker__tp_dealloc(PyNs3RectangleChecker *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::RectangleChecker *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RectangleChecker__tp_richcompare (PyNs3RectangleChecker *PYBINDGEN_UNUSED(self), PyNs3RectangleChecker *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RectangleChecker_Type)) {
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

PyTypeObject PyNs3RectangleChecker_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RectangleChecker",            /* tp_name */
    sizeof(PyNs3RectangleChecker),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RectangleChecker__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3RectangleChecker__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RectangleChecker_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RectangleChecker__tp_init,             /* tp_init */
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
_wrap_PyNs3RectangleValue__tp_init__0(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::RectangleValue();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3RectangleValue__tp_init__1(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3RectangleValue *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3RectangleValue_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RectangleValue(*((PyNs3RectangleValue *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3RectangleValue__tp_init__2(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Rectangle *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Rectangle_Type, &value)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::RectangleValue(*((PyNs3Rectangle *) value)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3RectangleValue__tp_init(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3RectangleValue__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3RectangleValue__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3RectangleValue__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3RectangleValue_Set(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Rectangle *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Rectangle_Type, &value)) {
        return NULL;
    }
    self->obj->Set(*((PyNs3Rectangle *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3RectangleValue_Get(PyNs3RectangleValue *self)
{
    PyObject *py_retval;
    PyNs3Rectangle *py_Rectangle;
    
    ns3::Rectangle retval = self->obj->Get();
    py_Rectangle = PyObject_New(PyNs3Rectangle, &PyNs3Rectangle_Type);
    py_Rectangle->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Rectangle->obj = new ns3::Rectangle(retval);
    PyNs3Rectangle_wrapper_registry[(void *) py_Rectangle->obj] = (PyObject *) py_Rectangle;
    py_retval = Py_BuildValue((char *) "N", py_Rectangle);
    return py_retval;
}


PyObject *
_wrap_PyNs3RectangleValue_Copy(PyNs3RectangleValue *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::AttributeValue > retval;
    PyNs3AttributeValue *py_AttributeValue;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->Copy();
    if (!(const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_AttributeValue = NULL;
    } else {
        py_AttributeValue = (PyNs3AttributeValue *) wrapper_lookup_iter->second;
        Py_INCREF(py_AttributeValue);
    }
    
    if (py_AttributeValue == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)))), &PyNs3AttributeValue_Type);
        py_AttributeValue = PyObject_New(PyNs3AttributeValue, wrapper_type);
    
        py_AttributeValue->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval))->Ref();
        py_AttributeValue->obj = const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_AttributeValue->obj] = (PyObject *) py_AttributeValue;
    }
    py_retval = Py_BuildValue((char *) "N", py_AttributeValue);
    return py_retval;
}


PyObject *
_wrap_PyNs3RectangleValue_SerializeToString(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    PyNs3AttributeChecker *checker;
    ns3::AttributeChecker *checker_ptr;
    const char *keywords[] = {"checker", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AttributeChecker_Type, &checker)) {
        return NULL;
    }
    checker_ptr = (checker ? checker->obj : NULL);
    retval = self->obj->SerializeToString(ns3::Ptr< ns3::AttributeChecker  > (checker_ptr));
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3RectangleValue_DeserializeFromString(PyNs3RectangleValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *value;
    Py_ssize_t value_len;
    PyNs3AttributeChecker *checker;
    ns3::AttributeChecker *checker_ptr;
    const char *keywords[] = {"value", "checker", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &value, &value_len, &PyNs3AttributeChecker_Type, &checker)) {
        return NULL;
    }
    checker_ptr = (checker ? checker->obj : NULL);
    retval = self->obj->DeserializeFromString(std::string(value, value_len), ns3::Ptr< ns3::AttributeChecker  > (checker_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3RectangleValue__copy__(PyNs3RectangleValue *self)
{

    PyNs3RectangleValue *py_copy;
    py_copy = PyObject_New(PyNs3RectangleValue, &PyNs3RectangleValue_Type);
    
    py_copy->obj = new ns3::RectangleValue(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3RectangleValue_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3RectangleValue_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3RectangleValue_Get, METH_NOARGS, NULL },
    {(char *) "Copy", (PyCFunction) _wrap_PyNs3RectangleValue_Copy, METH_NOARGS, NULL },
    {(char *) "SerializeToString", (PyCFunction) _wrap_PyNs3RectangleValue_SerializeToString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeserializeFromString", (PyCFunction) _wrap_PyNs3RectangleValue_DeserializeFromString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3RectangleValue__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3RectangleValue__tp_dealloc(PyNs3RectangleValue *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::RectangleValue *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3RectangleValue__tp_richcompare (PyNs3RectangleValue *PYBINDGEN_UNUSED(self), PyNs3RectangleValue *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3RectangleValue_Type)) {
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

PyTypeObject PyNs3RectangleValue_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.RectangleValue",            /* tp_name */
    sizeof(PyNs3RectangleValue),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3RectangleValue__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3RectangleValue__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3RectangleValue_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3RectangleValue__tp_init,             /* tp_init */
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoInitialize of class SteadyStateRandomWaypointMobilityModel is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoInitialize__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

PyObject *
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_DoDispose(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::DoInitialize()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SteadyStateRandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoInitialize"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        ns3::SteadyStateRandomWaypointMobilityModel::DoInitialize();
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = (ns3::SteadyStateRandomWaypointMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoInitialize", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::DoAssignStreams(int64_t arg0)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SteadyStateRandomWaypointMobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = (ns3::SteadyStateRandomWaypointMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", arg0);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SteadyStateRandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = const_cast< ns3::SteadyStateRandomWaypointMobilityModel* >((const ns3::SteadyStateRandomWaypointMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SteadyStateRandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = const_cast< ns3::SteadyStateRandomWaypointMobilityModel* >((const ns3::SteadyStateRandomWaypointMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::SteadyStateRandomWaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = (ns3::SteadyStateRandomWaypointMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3SteadyStateRandomWaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::DoDispose()
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_init__0(PyNs3SteadyStateRandomWaypointMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3SteadyStateRandomWaypointMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3SteadyStateRandomWaypointMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3SteadyStateRandomWaypointMobilityModel_Type)
    {
        self->obj = new PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper(*((PyNs3SteadyStateRandomWaypointMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::SteadyStateRandomWaypointMobilityModel(*((PyNs3SteadyStateRandomWaypointMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_init__1(PyNs3SteadyStateRandomWaypointMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3SteadyStateRandomWaypointMobilityModel_Type)
    {
        self->obj = new PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::SteadyStateRandomWaypointMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_init(PyNs3SteadyStateRandomWaypointMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3SteadyStateRandomWaypointMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::SteadyStateRandomWaypointMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__copy__(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{

    PyNs3SteadyStateRandomWaypointMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3SteadyStateRandomWaypointMobilityModel, &PyNs3SteadyStateRandomWaypointMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::SteadyStateRandomWaypointMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3SteadyStateRandomWaypointMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3SteadyStateRandomWaypointMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3SteadyStateRandomWaypointMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3SteadyStateRandomWaypointMobilityModel__tp_clear(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::SteadyStateRandomWaypointMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3SteadyStateRandomWaypointMobilityModel__tp_traverse(PyNs3SteadyStateRandomWaypointMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3SteadyStateRandomWaypointMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_dealloc(PyNs3SteadyStateRandomWaypointMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3SteadyStateRandomWaypointMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_richcompare (PyNs3SteadyStateRandomWaypointMobilityModel *PYBINDGEN_UNUSED(self), PyNs3SteadyStateRandomWaypointMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3SteadyStateRandomWaypointMobilityModel_Type)) {
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

PyTypeObject PyNs3SteadyStateRandomWaypointMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.SteadyStateRandomWaypointMobilityModel",            /* tp_name */
    sizeof(PyNs3SteadyStateRandomWaypointMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3SteadyStateRandomWaypointMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3SteadyStateRandomWaypointMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3SteadyStateRandomWaypointMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3SteadyStateRandomWaypointMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3SteadyStateRandomWaypointMobilityModel__tp_init,             /* tp_init */
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
_wrap_PyNs3WaypointChecker__tp_init(void)
{
    PyErr_SetString(PyExc_TypeError, "class 'WaypointChecker' cannot be constructed (have pure virtual methods but no helper class)");
    return -1;
}

static PyMethodDef PyNs3WaypointChecker_methods[] = {
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3WaypointChecker__tp_dealloc(PyNs3WaypointChecker *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::WaypointChecker *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3WaypointChecker__tp_richcompare (PyNs3WaypointChecker *PYBINDGEN_UNUSED(self), PyNs3WaypointChecker *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3WaypointChecker_Type)) {
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

PyTypeObject PyNs3WaypointChecker_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.WaypointChecker",            /* tp_name */
    sizeof(PyNs3WaypointChecker),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3WaypointChecker__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3WaypointChecker__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3WaypointChecker_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3WaypointChecker__tp_init,             /* tp_init */
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
PyNs3WaypointMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3WaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3WaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3WaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3WaypointMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3WaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3WaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3WaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3WaypointMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3WaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3WaypointMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3WaypointMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3WaypointMobilityModel__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::WaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = (ns3::WaypointMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::Vector
PyNs3WaypointMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::WaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = const_cast< ns3::WaypointMobilityModel* >((const ns3::WaypointMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3WaypointMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::WaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = const_cast< ns3::WaypointMobilityModel* >((const ns3::WaypointMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3WaypointMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::WaypointMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = (ns3::WaypointMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3WaypointMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3WaypointMobilityModel__PythonHelper::DoAssignStreams(int64_t start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", start);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3WaypointMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3WaypointMobilityModel__PythonHelper::DoInitialize()
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
PyNs3WaypointMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3WaypointMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3WaypointMobilityModel__tp_init__0(PyNs3WaypointMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3WaypointMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3WaypointMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3WaypointMobilityModel_Type)
    {
        self->obj = new PyNs3WaypointMobilityModel__PythonHelper(*((PyNs3WaypointMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3WaypointMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::WaypointMobilityModel(*((PyNs3WaypointMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3WaypointMobilityModel__tp_init__1(PyNs3WaypointMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3WaypointMobilityModel_Type)
    {
        self->obj = new PyNs3WaypointMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3WaypointMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::WaypointMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3WaypointMobilityModel__tp_init(PyNs3WaypointMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3WaypointMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3WaypointMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3WaypointMobilityModel_GetNextWaypoint(PyNs3WaypointMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3Waypoint *py_Waypoint;
    
    ns3::Waypoint retval = self->obj->GetNextWaypoint();
    py_Waypoint = PyObject_New(PyNs3Waypoint, &PyNs3Waypoint_Type);
    py_Waypoint->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Waypoint->obj = new ns3::Waypoint(retval);
    PyNs3Waypoint_wrapper_registry[(void *) py_Waypoint->obj] = (PyObject *) py_Waypoint;
    py_retval = Py_BuildValue((char *) "N", py_Waypoint);
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::WaypointMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointMobilityModel_EndMobility(PyNs3WaypointMobilityModel *self)
{
    PyObject *py_retval;
    
    self->obj->EndMobility();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointMobilityModel_WaypointsLeft(PyNs3WaypointMobilityModel *self)
{
    PyObject *py_retval;
    uint32_t retval;
    
    retval = self->obj->WaypointsLeft();
    py_retval = Py_BuildValue((char *) "N", PyLong_FromUnsignedLong(retval));
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointMobilityModel_AddWaypoint(PyNs3WaypointMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Waypoint *waypoint;
    const char *keywords[] = {"waypoint", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Waypoint_Type, &waypoint)) {
        return NULL;
    }
    self->obj->AddWaypoint(*((PyNs3Waypoint *) waypoint)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3WaypointMobilityModel__copy__(PyNs3WaypointMobilityModel *self)
{

    PyNs3WaypointMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3WaypointMobilityModel, &PyNs3WaypointMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::WaypointMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3WaypointMobilityModel_methods[] = {
    {(char *) "GetNextWaypoint", (PyCFunction) _wrap_PyNs3WaypointMobilityModel_GetNextWaypoint, METH_NOARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3WaypointMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "EndMobility", (PyCFunction) _wrap_PyNs3WaypointMobilityModel_EndMobility, METH_NOARGS, NULL },
    {(char *) "WaypointsLeft", (PyCFunction) _wrap_PyNs3WaypointMobilityModel_WaypointsLeft, METH_NOARGS, NULL },
    {(char *) "AddWaypoint", (PyCFunction) _wrap_PyNs3WaypointMobilityModel_AddWaypoint, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3WaypointMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3WaypointMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3WaypointMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3WaypointMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3WaypointMobilityModel__tp_clear(PyNs3WaypointMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::WaypointMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3WaypointMobilityModel__tp_traverse(PyNs3WaypointMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3WaypointMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3WaypointMobilityModel__tp_dealloc(PyNs3WaypointMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3WaypointMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3WaypointMobilityModel__tp_richcompare (PyNs3WaypointMobilityModel *PYBINDGEN_UNUSED(self), PyNs3WaypointMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3WaypointMobilityModel_Type)) {
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

PyTypeObject PyNs3WaypointMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.WaypointMobilityModel",            /* tp_name */
    sizeof(PyNs3WaypointMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3WaypointMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3WaypointMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3WaypointMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3WaypointMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3WaypointMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3WaypointMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3WaypointMobilityModel__tp_init,             /* tp_init */
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
_wrap_PyNs3WaypointValue__tp_init__0(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    self->obj = new ns3::WaypointValue();
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3WaypointValue__tp_init__1(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3WaypointValue *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3WaypointValue_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::WaypointValue(*((PyNs3WaypointValue *) arg0)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

static int
_wrap_PyNs3WaypointValue__tp_init__2(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3Waypoint *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Waypoint_Type, &value)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    self->obj = new ns3::WaypointValue(*((PyNs3Waypoint *) value)->obj);
    self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    return 0;
}

int _wrap_PyNs3WaypointValue__tp_init(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[3] = {0,};
    retval = _wrap_PyNs3WaypointValue__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3WaypointValue__tp_init__1(self, args, kwargs, &exceptions[1]);
    if (!exceptions[1]) {
        Py_DECREF(exceptions[0]);
        return retval;
    }
    retval = _wrap_PyNs3WaypointValue__tp_init__2(self, args, kwargs, &exceptions[2]);
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
_wrap_PyNs3WaypointValue_Set(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Waypoint *value;
    const char *keywords[] = {"value", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Waypoint_Type, &value)) {
        return NULL;
    }
    self->obj->Set(*((PyNs3Waypoint *) value)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointValue_Get(PyNs3WaypointValue *self)
{
    PyObject *py_retval;
    PyNs3Waypoint *py_Waypoint;
    
    ns3::Waypoint retval = self->obj->Get();
    py_Waypoint = PyObject_New(PyNs3Waypoint, &PyNs3Waypoint_Type);
    py_Waypoint->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Waypoint->obj = new ns3::Waypoint(retval);
    PyNs3Waypoint_wrapper_registry[(void *) py_Waypoint->obj] = (PyObject *) py_Waypoint;
    py_retval = Py_BuildValue((char *) "N", py_Waypoint);
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointValue_Copy(PyNs3WaypointValue *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::AttributeValue > retval;
    PyNs3AttributeValue *py_AttributeValue;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->Copy();
    if (!(const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)));
    if (wrapper_lookup_iter == PyNs3Empty_wrapper_registry.end()) {
        py_AttributeValue = NULL;
    } else {
        py_AttributeValue = (PyNs3AttributeValue *) wrapper_lookup_iter->second;
        Py_INCREF(py_AttributeValue);
    }
    
    if (py_AttributeValue == NULL) {
        wrapper_type = PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map.lookup_wrapper(typeid((*const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval)))), &PyNs3AttributeValue_Type);
        py_AttributeValue = PyObject_New(PyNs3AttributeValue, wrapper_type);
    
        py_AttributeValue->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval))->Ref();
        py_AttributeValue->obj = const_cast<ns3::AttributeValue *> (ns3::PeekPointer (retval));
        PyNs3Empty_wrapper_registry[(void *) py_AttributeValue->obj] = (PyObject *) py_AttributeValue;
    }
    py_retval = Py_BuildValue((char *) "N", py_AttributeValue);
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointValue_SerializeToString(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    std::string retval;
    PyNs3AttributeChecker *checker;
    ns3::AttributeChecker *checker_ptr;
    const char *keywords[] = {"checker", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3AttributeChecker_Type, &checker)) {
        return NULL;
    }
    checker_ptr = (checker ? checker->obj : NULL);
    retval = self->obj->SerializeToString(ns3::Ptr< ns3::AttributeChecker  > (checker_ptr));
    py_retval = Py_BuildValue((char *) "s#", (retval).c_str(), (retval).size());
    return py_retval;
}


PyObject *
_wrap_PyNs3WaypointValue_DeserializeFromString(PyNs3WaypointValue *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    bool retval;
    const char *value;
    Py_ssize_t value_len;
    PyNs3AttributeChecker *checker;
    ns3::AttributeChecker *checker_ptr;
    const char *keywords[] = {"value", "checker", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "s#O!", (char **) keywords, &value, &value_len, &PyNs3AttributeChecker_Type, &checker)) {
        return NULL;
    }
    checker_ptr = (checker ? checker->obj : NULL);
    retval = self->obj->DeserializeFromString(std::string(value, value_len), ns3::Ptr< ns3::AttributeChecker  > (checker_ptr));
    py_retval = Py_BuildValue((char *) "N", PyBool_FromLong(retval));
    return py_retval;
}


static PyObject*
_wrap_PyNs3WaypointValue__copy__(PyNs3WaypointValue *self)
{

    PyNs3WaypointValue *py_copy;
    py_copy = PyObject_New(PyNs3WaypointValue, &PyNs3WaypointValue_Type);
    
    py_copy->obj = new ns3::WaypointValue(*self->obj);
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3Empty_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3WaypointValue_methods[] = {
    {(char *) "Set", (PyCFunction) _wrap_PyNs3WaypointValue_Set, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "Get", (PyCFunction) _wrap_PyNs3WaypointValue_Get, METH_NOARGS, NULL },
    {(char *) "Copy", (PyCFunction) _wrap_PyNs3WaypointValue_Copy, METH_NOARGS, NULL },
    {(char *) "SerializeToString", (PyCFunction) _wrap_PyNs3WaypointValue_SerializeToString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "DeserializeFromString", (PyCFunction) _wrap_PyNs3WaypointValue_DeserializeFromString, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3WaypointValue__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
_wrap_PyNs3WaypointValue__tp_dealloc(PyNs3WaypointValue *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3Empty_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3Empty_wrapper_registry.end()) {
        PyNs3Empty_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    if (self->obj) {
        ns3::WaypointValue *tmp = self->obj;
        self->obj = NULL;
        tmp->Unref();
    }
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3WaypointValue__tp_richcompare (PyNs3WaypointValue *PYBINDGEN_UNUSED(self), PyNs3WaypointValue *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3WaypointValue_Type)) {
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

PyTypeObject PyNs3WaypointValue_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.WaypointValue",            /* tp_name */
    sizeof(PyNs3WaypointValue),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3WaypointValue__tp_dealloc,        /* tp_dealloc */
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
    (richcmpfunc)_wrap_PyNs3WaypointValue__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3WaypointValue_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3WaypointValue__tp_init,             /* tp_init */
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ConstantAccelerationMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantAccelerationMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantAccelerationMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3ConstantAccelerationMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantAccelerationMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantAccelerationMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ConstantAccelerationMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantAccelerationMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantAccelerationMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_DoDispose(PyNs3ConstantAccelerationMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantAccelerationMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantAccelerationMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Vector
PyNs3ConstantAccelerationMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantAccelerationMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = const_cast< ns3::ConstantAccelerationMobilityModel* >((const ns3::ConstantAccelerationMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3ConstantAccelerationMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantAccelerationMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = const_cast< ns3::ConstantAccelerationMobilityModel* >((const ns3::ConstantAccelerationMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3ConstantAccelerationMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantAccelerationMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = (ns3::ConstantAccelerationMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantAccelerationMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3ConstantAccelerationMobilityModel__PythonHelper::DoAssignStreams(int64_t start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", start);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ConstantAccelerationMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::DoDispose()
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::DoInitialize()
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ConstantAccelerationMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ConstantAccelerationMobilityModel__tp_init__0(PyNs3ConstantAccelerationMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ConstantAccelerationMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ConstantAccelerationMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ConstantAccelerationMobilityModel_Type)
    {
        self->obj = new PyNs3ConstantAccelerationMobilityModel__PythonHelper(*((PyNs3ConstantAccelerationMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantAccelerationMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantAccelerationMobilityModel(*((PyNs3ConstantAccelerationMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ConstantAccelerationMobilityModel__tp_init__1(PyNs3ConstantAccelerationMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ConstantAccelerationMobilityModel_Type)
    {
        self->obj = new PyNs3ConstantAccelerationMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantAccelerationMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantAccelerationMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ConstantAccelerationMobilityModel__tp_init(PyNs3ConstantAccelerationMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ConstantAccelerationMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConstantAccelerationMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ConstantAccelerationMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ConstantAccelerationMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantAccelerationMobilityModel_SetVelocityAndAcceleration(PyNs3ConstantAccelerationMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *velocity;
    PyNs3Vector3D *acceleration;
    const char *keywords[] = {"velocity", "acceleration", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!O!", (char **) keywords, &PyNs3Vector3D_Type, &velocity, &PyNs3Vector3D_Type, &acceleration)) {
        return NULL;
    }
    self->obj->SetVelocityAndAcceleration(*((PyNs3Vector3D *) velocity)->obj, *((PyNs3Vector3D *) acceleration)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3ConstantAccelerationMobilityModel__copy__(PyNs3ConstantAccelerationMobilityModel *self)
{

    PyNs3ConstantAccelerationMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3ConstantAccelerationMobilityModel, &PyNs3ConstantAccelerationMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ConstantAccelerationMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ConstantAccelerationMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ConstantAccelerationMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetVelocityAndAcceleration", (PyCFunction) _wrap_PyNs3ConstantAccelerationMobilityModel_SetVelocityAndAcceleration, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ConstantAccelerationMobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ConstantAccelerationMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ConstantAccelerationMobilityModel__tp_clear(PyNs3ConstantAccelerationMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ConstantAccelerationMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ConstantAccelerationMobilityModel__tp_traverse(PyNs3ConstantAccelerationMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ConstantAccelerationMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ConstantAccelerationMobilityModel__tp_dealloc(PyNs3ConstantAccelerationMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ConstantAccelerationMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ConstantAccelerationMobilityModel__tp_richcompare (PyNs3ConstantAccelerationMobilityModel *PYBINDGEN_UNUSED(self), PyNs3ConstantAccelerationMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ConstantAccelerationMobilityModel_Type)) {
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

PyTypeObject PyNs3ConstantAccelerationMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.ConstantAccelerationMobilityModel",            /* tp_name */
    sizeof(PyNs3ConstantAccelerationMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ConstantAccelerationMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ConstantAccelerationMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ConstantAccelerationMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ConstantAccelerationMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ConstantAccelerationMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ConstantAccelerationMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ConstantAccelerationMobilityModel__tp_init,             /* tp_init */
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
PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ConstantPositionMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantPositionMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantPositionMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3ConstantPositionMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantPositionMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantPositionMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ConstantPositionMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantPositionMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantPositionMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_DoDispose(PyNs3ConstantPositionMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantPositionMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantPositionMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Vector
PyNs3ConstantPositionMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantPositionMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = const_cast< ns3::ConstantPositionMobilityModel* >((const ns3::ConstantPositionMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3ConstantPositionMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantPositionMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = const_cast< ns3::ConstantPositionMobilityModel* >((const ns3::ConstantPositionMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3ConstantPositionMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantPositionMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = (ns3::ConstantPositionMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantPositionMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3ConstantPositionMobilityModel__PythonHelper::DoAssignStreams(int64_t start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", start);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ConstantPositionMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ConstantPositionMobilityModel__PythonHelper::DoDispose()
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
PyNs3ConstantPositionMobilityModel__PythonHelper::DoInitialize()
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
PyNs3ConstantPositionMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ConstantPositionMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ConstantPositionMobilityModel__tp_init__0(PyNs3ConstantPositionMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ConstantPositionMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ConstantPositionMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ConstantPositionMobilityModel_Type)
    {
        self->obj = new PyNs3ConstantPositionMobilityModel__PythonHelper(*((PyNs3ConstantPositionMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantPositionMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantPositionMobilityModel(*((PyNs3ConstantPositionMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ConstantPositionMobilityModel__tp_init__1(PyNs3ConstantPositionMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ConstantPositionMobilityModel_Type)
    {
        self->obj = new PyNs3ConstantPositionMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantPositionMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantPositionMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ConstantPositionMobilityModel__tp_init(PyNs3ConstantPositionMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ConstantPositionMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConstantPositionMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ConstantPositionMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ConstantPositionMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3ConstantPositionMobilityModel__copy__(PyNs3ConstantPositionMobilityModel *self)
{

    PyNs3ConstantPositionMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3ConstantPositionMobilityModel, &PyNs3ConstantPositionMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ConstantPositionMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ConstantPositionMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ConstantPositionMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ConstantPositionMobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ConstantPositionMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ConstantPositionMobilityModel__tp_clear(PyNs3ConstantPositionMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ConstantPositionMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ConstantPositionMobilityModel__tp_traverse(PyNs3ConstantPositionMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ConstantPositionMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ConstantPositionMobilityModel__tp_dealloc(PyNs3ConstantPositionMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ConstantPositionMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ConstantPositionMobilityModel__tp_richcompare (PyNs3ConstantPositionMobilityModel *PYBINDGEN_UNUSED(self), PyNs3ConstantPositionMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ConstantPositionMobilityModel_Type)) {
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

PyTypeObject PyNs3ConstantPositionMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.ConstantPositionMobilityModel",            /* tp_name */
    sizeof(PyNs3ConstantPositionMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ConstantPositionMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ConstantPositionMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ConstantPositionMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ConstantPositionMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ConstantPositionMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ConstantPositionMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ConstantPositionMobilityModel__tp_init,             /* tp_init */
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3ConstantVelocityMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantVelocityMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantVelocityMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3ConstantVelocityMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantVelocityMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantVelocityMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3ConstantVelocityMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantVelocityMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantVelocityMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_DoDispose(PyNs3ConstantVelocityMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3ConstantVelocityMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3ConstantVelocityMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Vector
PyNs3ConstantVelocityMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantVelocityMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = const_cast< ns3::ConstantVelocityMobilityModel* >((const ns3::ConstantVelocityMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3ConstantVelocityMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantVelocityMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = const_cast< ns3::ConstantVelocityMobilityModel* >((const ns3::ConstantVelocityMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3ConstantVelocityMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::ConstantVelocityMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = (ns3::ConstantVelocityMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3ConstantVelocityMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3ConstantVelocityMobilityModel__PythonHelper::DoAssignStreams(int64_t start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", start);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3ConstantVelocityMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::DoDispose()
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::DoInitialize()
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3ConstantVelocityMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3ConstantVelocityMobilityModel__tp_init__0(PyNs3ConstantVelocityMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3ConstantVelocityMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3ConstantVelocityMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3ConstantVelocityMobilityModel_Type)
    {
        self->obj = new PyNs3ConstantVelocityMobilityModel__PythonHelper(*((PyNs3ConstantVelocityMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantVelocityMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantVelocityMobilityModel(*((PyNs3ConstantVelocityMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3ConstantVelocityMobilityModel__tp_init__1(PyNs3ConstantVelocityMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3ConstantVelocityMobilityModel_Type)
    {
        self->obj = new PyNs3ConstantVelocityMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3ConstantVelocityMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::ConstantVelocityMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3ConstantVelocityMobilityModel__tp_init(PyNs3ConstantVelocityMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3ConstantVelocityMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3ConstantVelocityMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3ConstantVelocityMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::ConstantVelocityMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3ConstantVelocityMobilityModel_SetVelocity(PyNs3ConstantVelocityMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3Vector3D *speed;
    const char *keywords[] = {"speed", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3Vector3D_Type, &speed)) {
        return NULL;
    }
    self->obj->SetVelocity(*((PyNs3Vector3D *) speed)->obj);
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


static PyObject*
_wrap_PyNs3ConstantVelocityMobilityModel__copy__(PyNs3ConstantVelocityMobilityModel *self)
{

    PyNs3ConstantVelocityMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3ConstantVelocityMobilityModel, &PyNs3ConstantVelocityMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::ConstantVelocityMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3ConstantVelocityMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3ConstantVelocityMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "SetVelocity", (PyCFunction) _wrap_PyNs3ConstantVelocityMobilityModel_SetVelocity, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3ConstantVelocityMobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3ConstantVelocityMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3ConstantVelocityMobilityModel__tp_clear(PyNs3ConstantVelocityMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::ConstantVelocityMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3ConstantVelocityMobilityModel__tp_traverse(PyNs3ConstantVelocityMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3ConstantVelocityMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3ConstantVelocityMobilityModel__tp_dealloc(PyNs3ConstantVelocityMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3ConstantVelocityMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3ConstantVelocityMobilityModel__tp_richcompare (PyNs3ConstantVelocityMobilityModel *PYBINDGEN_UNUSED(self), PyNs3ConstantVelocityMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3ConstantVelocityMobilityModel_Type)) {
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

PyTypeObject PyNs3ConstantVelocityMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.ConstantVelocityMobilityModel",            /* tp_name */
    sizeof(PyNs3ConstantVelocityMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3ConstantVelocityMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3ConstantVelocityMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3ConstantVelocityMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3ConstantVelocityMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3ConstantVelocityMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3ConstantVelocityMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3ConstantVelocityMobilityModel__tp_init,             /* tp_init */
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
PyNs3GaussMarkovMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3GaussMarkovMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3GaussMarkovMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3GaussMarkovMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3GaussMarkovMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3GaussMarkovMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3GaussMarkovMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3GaussMarkovMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3GaussMarkovMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3GaussMarkovMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3GaussMarkovMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3GaussMarkovMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method NotifyNewAggregate of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->NotifyNewAggregate__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

int64_t
PyNs3GaussMarkovMobilityModel__PythonHelper::DoAssignStreams(int64_t arg0)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GaussMarkovMobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = (ns3::GaussMarkovMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", arg0);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3GaussMarkovMobilityModel__PythonHelper::DoDispose()
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GaussMarkovMobilityModel *self_obj_before;
    PyObject *py_retval;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoDispose"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = (ns3::GaussMarkovMobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoDispose", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::Vector
PyNs3GaussMarkovMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GaussMarkovMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = const_cast< ns3::GaussMarkovMobilityModel* >((const ns3::GaussMarkovMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3GaussMarkovMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GaussMarkovMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = const_cast< ns3::GaussMarkovMobilityModel* >((const ns3::GaussMarkovMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3GaussMarkovMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::GaussMarkovMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = (ns3::GaussMarkovMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3GaussMarkovMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

ns3::TypeId
PyNs3GaussMarkovMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3GaussMarkovMobilityModel__PythonHelper::DoInitialize()
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
PyNs3GaussMarkovMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3GaussMarkovMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3GaussMarkovMobilityModel__tp_init__0(PyNs3GaussMarkovMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3GaussMarkovMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3GaussMarkovMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3GaussMarkovMobilityModel_Type)
    {
        self->obj = new PyNs3GaussMarkovMobilityModel__PythonHelper(*((PyNs3GaussMarkovMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3GaussMarkovMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::GaussMarkovMobilityModel(*((PyNs3GaussMarkovMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3GaussMarkovMobilityModel__tp_init__1(PyNs3GaussMarkovMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3GaussMarkovMobilityModel_Type)
    {
        self->obj = new PyNs3GaussMarkovMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3GaussMarkovMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::GaussMarkovMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3GaussMarkovMobilityModel__tp_init(PyNs3GaussMarkovMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3GaussMarkovMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3GaussMarkovMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3GaussMarkovMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::GaussMarkovMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


static PyObject*
_wrap_PyNs3GaussMarkovMobilityModel__copy__(PyNs3GaussMarkovMobilityModel *self)
{

    PyNs3GaussMarkovMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3GaussMarkovMobilityModel, &PyNs3GaussMarkovMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::GaussMarkovMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3GaussMarkovMobilityModel_methods[] = {
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3GaussMarkovMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3GaussMarkovMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3GaussMarkovMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3GaussMarkovMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3GaussMarkovMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3GaussMarkovMobilityModel__tp_clear(PyNs3GaussMarkovMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::GaussMarkovMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3GaussMarkovMobilityModel__tp_traverse(PyNs3GaussMarkovMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3GaussMarkovMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3GaussMarkovMobilityModel__tp_dealloc(PyNs3GaussMarkovMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3GaussMarkovMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3GaussMarkovMobilityModel__tp_richcompare (PyNs3GaussMarkovMobilityModel *PYBINDGEN_UNUSED(self), PyNs3GaussMarkovMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3GaussMarkovMobilityModel_Type)) {
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

PyTypeObject PyNs3GaussMarkovMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.GaussMarkovMobilityModel",            /* tp_name */
    sizeof(PyNs3GaussMarkovMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3GaussMarkovMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3GaussMarkovMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3GaussMarkovMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3GaussMarkovMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3GaussMarkovMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3GaussMarkovMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3GaussMarkovMobilityModel__tp_init,             /* tp_init */
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
PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted(PyNs3HierarchicalMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3HierarchicalMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3HierarchicalMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_DoInitialize(PyNs3HierarchicalMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3HierarchicalMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3HierarchicalMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_NotifyNewAggregate(PyNs3HierarchicalMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3HierarchicalMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3HierarchicalMobilityModel__PythonHelper* >(self->obj);
    
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
PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_DoDispose(PyNs3HierarchicalMobilityModel *self)
{
    PyObject *py_retval;
    PyNs3HierarchicalMobilityModel__PythonHelper *helper = dynamic_cast< PyNs3HierarchicalMobilityModel__PythonHelper* >(self->obj);
    
    if (helper == NULL) {
        PyErr_SetString(PyExc_TypeError, "Method DoDispose of class Object is protected and can only be called by a subclass");
        return NULL;
    }
    helper->DoDispose__parent_caller();
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}

ns3::Vector
PyNs3HierarchicalMobilityModel__PythonHelper::DoGetPosition() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::HierarchicalMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = const_cast< ns3::HierarchicalMobilityModel* >((const ns3::HierarchicalMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetPosition", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::Vector
PyNs3HierarchicalMobilityModel__PythonHelper::DoGetVelocity() const
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::HierarchicalMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoGetVelocity"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    self_obj_before = reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = const_cast< ns3::HierarchicalMobilityModel* >((const ns3::HierarchicalMobilityModel*) this);
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoGetVelocity", (char *) "");
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    py_retval = Py_BuildValue((char*) "(N)", py_retval);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        PyErr_Print();
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return ns3::Vector3D();
    }
    ns3::Vector3D retval = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

void
PyNs3HierarchicalMobilityModel__PythonHelper::DoSetPosition(ns3::Vector const & position)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::HierarchicalMobilityModel *self_obj_before;
    PyObject *py_retval;
    PyNs3Vector3D *py_Vector3D;
    
    __py_gil_state = (PyEval_ThreadsInitialized() ? PyGILState_Ensure() : (PyGILState_STATE) 0);
    py_method = PyObject_GetAttrString(m_pyself, (char *) "DoSetPosition"); PyErr_Clear();
    if (py_method == NULL || Py_TYPE(py_method) == &PyCFunction_Type) {
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    self_obj_before = reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = (ns3::HierarchicalMobilityModel*) this;
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D(position);
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoSetPosition", (char *) "N", py_Vector3D);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    if (py_retval != Py_None) {
        PyErr_SetString(PyExc_TypeError, "function/method should return None");
        Py_DECREF(py_retval);
        reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
        return;
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3HierarchicalMobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return;
}

int64_t
PyNs3HierarchicalMobilityModel__PythonHelper::DoAssignStreams(int64_t start)
{
    PyGILState_STATE __py_gil_state;
    PyObject *py_method;
    ns3::MobilityModel *self_obj_before;
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
    self_obj_before = reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj;
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = (ns3::MobilityModel*) this;
    py_retval = PyObject_CallMethod(m_pyself, (char *) "DoAssignStreams", (char *) "L", start);
    if (py_retval == NULL) {
        PyErr_Print();
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
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
        reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
        Py_XDECREF(py_method);
        if (PyEval_ThreadsInitialized())
            PyGILState_Release(__py_gil_state);
    
        PyErr_Print();
        Py_FatalError("Error detected, but parent virtual is pure virtual or private virtual, "
                      "and return is a class without trival constructor");
    }
    Py_DECREF(py_retval);
    reinterpret_cast< PyNs3MobilityModel* >(m_pyself)->obj = self_obj_before;
    Py_XDECREF(py_method);
    if (PyEval_ThreadsInitialized())
        PyGILState_Release(__py_gil_state);
    return retval;
}

ns3::TypeId
PyNs3HierarchicalMobilityModel__PythonHelper::GetInstanceTypeId() const
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
PyNs3HierarchicalMobilityModel__PythonHelper::DoDispose()
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
PyNs3HierarchicalMobilityModel__PythonHelper::DoInitialize()
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
PyNs3HierarchicalMobilityModel__PythonHelper::NotifyNewAggregate()
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
PyNs3HierarchicalMobilityModel__PythonHelper::NotifyConstructionCompleted()
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
_wrap_PyNs3HierarchicalMobilityModel__tp_init__0(PyNs3HierarchicalMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
{
    PyNs3HierarchicalMobilityModel *arg0;
    const char *keywords[] = {"arg0", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3HierarchicalMobilityModel_Type, &arg0)) {
        {
            PyObject *exc_type, *traceback;
            PyErr_Fetch(&exc_type, return_exception, &traceback);
            Py_XDECREF(exc_type);
            Py_XDECREF(traceback);
        }
        return -1;
    }
    if (Py_TYPE(self) != &PyNs3HierarchicalMobilityModel_Type)
    {
        self->obj = new PyNs3HierarchicalMobilityModel__PythonHelper(*((PyNs3HierarchicalMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3HierarchicalMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::HierarchicalMobilityModel(*((PyNs3HierarchicalMobilityModel *) arg0)->obj);
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

static int
_wrap_PyNs3HierarchicalMobilityModel__tp_init__1(PyNs3HierarchicalMobilityModel *self, PyObject *args, PyObject *kwargs, PyObject **return_exception)
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
    if (Py_TYPE(self) != &PyNs3HierarchicalMobilityModel_Type)
    {
        self->obj = new PyNs3HierarchicalMobilityModel__PythonHelper();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ((PyNs3HierarchicalMobilityModel__PythonHelper*) self->obj)->set_pyobj((PyObject *)self);
        ns3::CompleteConstruct(self->obj);
    } else {
        // visibility: 'public'
        self->obj = new ns3::HierarchicalMobilityModel();
        self->obj->Ref ();
        self->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
        ns3::CompleteConstruct(self->obj);
    }
    return 0;
}

int _wrap_PyNs3HierarchicalMobilityModel__tp_init(PyNs3HierarchicalMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    int retval;
    PyObject *error_list;
    PyObject *exceptions[2] = {0,};
    retval = _wrap_PyNs3HierarchicalMobilityModel__tp_init__0(self, args, kwargs, &exceptions[0]);
    if (!exceptions[0]) {
        return retval;
    }
    retval = _wrap_PyNs3HierarchicalMobilityModel__tp_init__1(self, args, kwargs, &exceptions[1]);
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
_wrap_PyNs3HierarchicalMobilityModel_SetChild(PyNs3HierarchicalMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3MobilityModel *model;
    ns3::MobilityModel *model_ptr;
    const char *keywords[] = {"model", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MobilityModel_Type, &model)) {
        return NULL;
    }
    model_ptr = (model ? model->obj : NULL);
    self->obj->SetChild(ns3::Ptr< ns3::MobilityModel  > (model_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3HierarchicalMobilityModel_SetParent(PyNs3HierarchicalMobilityModel *self, PyObject *args, PyObject *kwargs)
{
    PyObject *py_retval;
    PyNs3MobilityModel *model;
    ns3::MobilityModel *model_ptr;
    const char *keywords[] = {"model", NULL};
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "O!", (char **) keywords, &PyNs3MobilityModel_Type, &model)) {
        return NULL;
    }
    model_ptr = (model ? model->obj : NULL);
    self->obj->SetParent(ns3::Ptr< ns3::MobilityModel  > (model_ptr));
    Py_INCREF(Py_None);
    py_retval = Py_None;
    return py_retval;
}


PyObject *
_wrap_PyNs3HierarchicalMobilityModel_GetTypeId(void)
{
    PyObject *py_retval;
    PyNs3TypeId *py_TypeId;
    
    ns3::TypeId retval = ns3::HierarchicalMobilityModel::GetTypeId();
    py_TypeId = PyObject_New(PyNs3TypeId, &PyNs3TypeId_Type);
    py_TypeId->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_TypeId->obj = new ns3::TypeId(retval);
    PyNs3TypeId_wrapper_registry[(void *) py_TypeId->obj] = (PyObject *) py_TypeId;
    py_retval = Py_BuildValue((char *) "N", py_TypeId);
    return py_retval;
}


PyObject *
_wrap_PyNs3HierarchicalMobilityModel_GetParent(PyNs3HierarchicalMobilityModel *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::MobilityModel > retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetParent();
    if (!(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = reinterpret_cast< PyNs3MobilityModel* >(reinterpret_cast< PyNs3MobilityModel__PythonHelper* >(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->inst_dict = NULL;
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_MobilityModel);
    return py_retval;
}


PyObject *
_wrap_PyNs3HierarchicalMobilityModel_GetChild(PyNs3HierarchicalMobilityModel *self)
{
    PyObject *py_retval;
    ns3::Ptr< ns3::MobilityModel > retval;
    PyNs3MobilityModel *py_MobilityModel;
    std::map<void*, PyObject*>::const_iterator wrapper_lookup_iter;
    PyTypeObject *wrapper_type = 0;
    
    retval = self->obj->GetChild();
    if (!(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))) {
        Py_INCREF(Py_None);
        return Py_None;
    }
    if (typeid((*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))).name() == typeid(PyNs3MobilityModel__PythonHelper).name())
    {
        py_MobilityModel = reinterpret_cast< PyNs3MobilityModel* >(reinterpret_cast< PyNs3MobilityModel__PythonHelper* >(const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))->m_pyself);
        py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval));
        Py_INCREF(py_MobilityModel);
    } else {
        wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)));
        if (wrapper_lookup_iter == PyNs3ObjectBase_wrapper_registry.end()) {
            py_MobilityModel = NULL;
        } else {
            py_MobilityModel = (PyNs3MobilityModel *) wrapper_lookup_iter->second;
            Py_INCREF(py_MobilityModel);
        }
    
        if (py_MobilityModel == NULL) {
            wrapper_type = PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.lookup_wrapper(typeid((*const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval)))), &PyNs3MobilityModel_Type);
            py_MobilityModel = PyObject_GC_New(PyNs3MobilityModel, wrapper_type);
            py_MobilityModel->inst_dict = NULL;
    
            py_MobilityModel->inst_dict = NULL;
            py_MobilityModel->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
            const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval))->Ref();
            py_MobilityModel->obj = const_cast<ns3::MobilityModel *> (ns3::PeekPointer (retval));
            PyNs3ObjectBase_wrapper_registry[(void *) py_MobilityModel->obj] = (PyObject *) py_MobilityModel;
        }
    }
    py_retval = Py_BuildValue((char *) "N", py_MobilityModel);
    return py_retval;
}


static PyObject*
_wrap_PyNs3HierarchicalMobilityModel__copy__(PyNs3HierarchicalMobilityModel *self)
{

    PyNs3HierarchicalMobilityModel *py_copy;
    py_copy = PyObject_GC_New(PyNs3HierarchicalMobilityModel, &PyNs3HierarchicalMobilityModel_Type);
    py_copy->inst_dict = NULL;
    
    py_copy->obj = new ns3::HierarchicalMobilityModel(*self->obj);
    py_copy->inst_dict = NULL;
    py_copy->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    PyNs3ObjectBase_wrapper_registry[(void *) py_copy->obj] = (PyObject *) py_copy;
    return (PyObject*) py_copy;
}

static PyMethodDef PyNs3HierarchicalMobilityModel_methods[] = {
    {(char *) "SetChild", (PyCFunction) _wrap_PyNs3HierarchicalMobilityModel_SetChild, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "SetParent", (PyCFunction) _wrap_PyNs3HierarchicalMobilityModel_SetParent, METH_KEYWORDS|METH_VARARGS, NULL },
    {(char *) "GetTypeId", (PyCFunction) _wrap_PyNs3HierarchicalMobilityModel_GetTypeId, METH_NOARGS|METH_STATIC, NULL },
    {(char *) "GetParent", (PyCFunction) _wrap_PyNs3HierarchicalMobilityModel_GetParent, METH_NOARGS, NULL },
    {(char *) "GetChild", (PyCFunction) _wrap_PyNs3HierarchicalMobilityModel_GetChild, METH_NOARGS, NULL },
    {(char *) "NotifyConstructionCompleted", (PyCFunction) PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_NotifyConstructionCompleted, METH_NOARGS, NULL },
    {(char *) "DoInitialize", (PyCFunction) PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_DoInitialize, METH_NOARGS, NULL },
    {(char *) "NotifyNewAggregate", (PyCFunction) PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_NotifyNewAggregate, METH_NOARGS, NULL },
    {(char *) "DoDispose", (PyCFunction) PyNs3HierarchicalMobilityModel__PythonHelper::_wrap_DoDispose, METH_NOARGS, NULL },
    {(char *) "__copy__", (PyCFunction) _wrap_PyNs3HierarchicalMobilityModel__copy__, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL}
};

static void
PyNs3HierarchicalMobilityModel__tp_clear(PyNs3HierarchicalMobilityModel *self)
{
    Py_CLEAR(self->inst_dict);
    if (self->obj) {
    ns3::HierarchicalMobilityModel *tmp = self->obj;
    self->obj = NULL;
    tmp->Unref();
}
}


static int
PyNs3HierarchicalMobilityModel__tp_traverse(PyNs3HierarchicalMobilityModel *self, visitproc visit, void *arg)
{
    Py_VISIT(self->inst_dict);
    
    if (self->obj && typeid(*self->obj).name() == typeid(PyNs3HierarchicalMobilityModel__PythonHelper).name()  && self->obj->GetReferenceCount() == 1)
        Py_VISIT((PyObject *) self);

    return 0;
}


static void
_wrap_PyNs3HierarchicalMobilityModel__tp_dealloc(PyNs3HierarchicalMobilityModel *self)
{
    std::map<void*, PyObject*>::iterator wrapper_lookup_iter;
    wrapper_lookup_iter = PyNs3ObjectBase_wrapper_registry.find((void *) self->obj);
    if (wrapper_lookup_iter != PyNs3ObjectBase_wrapper_registry.end()) {
        PyNs3ObjectBase_wrapper_registry.erase(wrapper_lookup_iter);
    }
    
    PyNs3HierarchicalMobilityModel__tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject*
_wrap_PyNs3HierarchicalMobilityModel__tp_richcompare (PyNs3HierarchicalMobilityModel *PYBINDGEN_UNUSED(self), PyNs3HierarchicalMobilityModel *other, int opid)
{
    
    if (!PyObject_IsInstance((PyObject*) other, (PyObject*) &PyNs3HierarchicalMobilityModel_Type)) {
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

PyTypeObject PyNs3HierarchicalMobilityModel_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.HierarchicalMobilityModel",            /* tp_name */
    sizeof(PyNs3HierarchicalMobilityModel),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_PyNs3HierarchicalMobilityModel__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)PyNs3HierarchicalMobilityModel__tp_traverse,     /* tp_traverse */
    (inquiry)PyNs3HierarchicalMobilityModel__tp_clear,             /* tp_clear */
    (richcmpfunc)_wrap_PyNs3HierarchicalMobilityModel__tp_richcompare,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)NULL,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)PyNs3HierarchicalMobilityModel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    0,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    offsetof(PyNs3HierarchicalMobilityModel, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_PyNs3HierarchicalMobilityModel__tp_init,             /* tp_init */
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
Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_clear(Pystd__list__lt___ns3__Vector3D___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

}


static int
Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_traverse(Pystd__list__lt___ns3__Vector3D___gt__Iter *self, visitproc visit, void *arg)
{
    Py_VISIT((PyObject *) self->container);
    return 0;
}


static void
_wrap_Pystd__list__lt___ns3__Vector3D___gt____tp_dealloc(Pystd__list__lt___ns3__Vector3D___gt__ *self)
{
    delete self->obj;
    self->obj = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static void
_wrap_Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_dealloc(Pystd__list__lt___ns3__Vector3D___gt__Iter *self)
{
    Py_CLEAR(self->container);
    delete self->iterator;
    self->iterator = NULL;

    Py_TYPE(self)->tp_free((PyObject*)self);
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Vector3D___gt____tp_iter(Pystd__list__lt___ns3__Vector3D___gt__ *self)
{
    Pystd__list__lt___ns3__Vector3D___gt__Iter *iter = PyObject_GC_New(Pystd__list__lt___ns3__Vector3D___gt__Iter, &Pystd__list__lt___ns3__Vector3D___gt__Iter_Type);
    Py_INCREF(self);
    iter->container = self;
    iter->iterator = new std::list< ns3::Vector3D >::iterator(self->obj->begin());
    return (PyObject*) iter;
}


static PyObject*
_wrap_Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_iter(Pystd__list__lt___ns3__Vector3D___gt__Iter *self)
{
    Py_INCREF(self);
    return (PyObject*) self;
}

static PyObject* _wrap_Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_iternext(Pystd__list__lt___ns3__Vector3D___gt__Iter *self)
{
    PyObject *py_retval;
    std::list< ns3::Vector3D >::iterator iter;
    PyNs3Vector3D *py_Vector3D;
    
    iter = *self->iterator;
    if (iter == self->container->obj->end()) {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    ++(*self->iterator);
    py_Vector3D = PyObject_New(PyNs3Vector3D, &PyNs3Vector3D_Type);
    py_Vector3D->flags = PYBINDGEN_WRAPPER_FLAG_NONE;
    py_Vector3D->obj = new ns3::Vector3D((*iter));
    PyNs3Vector3D_wrapper_registry[(void *) py_Vector3D->obj] = (PyObject *) py_Vector3D;
    py_retval = Py_BuildValue((char *) "N", py_Vector3D);
    return py_retval;
}

int _wrap_convert_py2c__ns3__Vector3D(PyObject *value, ns3::Vector3D *address)
{
    PyObject *py_retval;
    PyNs3Vector3D *tmp_Vector3D;
    
    py_retval = Py_BuildValue((char *) "(O)", value);
    if (!PyArg_ParseTuple(py_retval, (char *) "O!", &PyNs3Vector3D_Type, &tmp_Vector3D)) {
        Py_DECREF(py_retval);
        return 0;
    }
    *address = *tmp_Vector3D->obj;
    Py_DECREF(py_retval);
    return 1;
}


int _wrap_convert_py2c__std__list__lt___ns3__Vector3D___gt__(PyObject *arg, std::list< ns3::Vector3D > *container)
{
    if (PyObject_IsInstance(arg, (PyObject*) &Pystd__list__lt___ns3__Vector3D___gt___Type)) {
        *container = *((Pystd__list__lt___ns3__Vector3D___gt__*)arg)->obj;
    } else if (PyList_Check(arg)) {
        container->clear();
        Py_ssize_t size = PyList_Size(arg);
        for (Py_ssize_t i = 0; i < size; i++) {
            ns3::Vector3D item;
            if (!_wrap_convert_py2c__ns3__Vector3D(PyList_GET_ITEM(arg, i), &item)) {
                return 0;
            }
            container->push_back(item);
        }
    } else {
        PyErr_SetString(PyExc_TypeError, "parameter must be None, a Std__list__lt___ns3__Vector3D___gt__ instance, or a list of ns3::Vector3D");
        return 0;
    }
    return 1;
}


static int
_wrap_Pystd__list__lt___ns3__Vector3D___gt____tp_init(Pystd__list__lt___ns3__Vector3D___gt__ *self, PyObject *args, PyObject *kwargs)
{
    const char *keywords[] = {"arg", NULL};
    PyObject *arg = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, (char *) "|O", (char **) keywords, &arg)) {
        return -1;
    }

    self->obj = new std::list< ns3::Vector3D >;

    if (arg == NULL)
        return 0;

    if (!_wrap_convert_py2c__std__list__lt___ns3__Vector3D___gt__(arg, self->obj)) {
        delete self->obj;
        self->obj = NULL;
        return -1;
    }
    return 0;
}

PyTypeObject Pystd__list__lt___ns3__Vector3D___gt___Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.Std__list__lt___ns3__Vector3D___gt__",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Vector3D___gt__),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Vector3D___gt____tp_dealloc,        /* tp_dealloc */
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
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Vector3D___gt____tp_iter,          /* tp_iter */
    (iternextfunc)NULL,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    NULL,                     /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)NULL,    /* tp_descr_get */
    (descrsetfunc)NULL,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_Pystd__list__lt___ns3__Vector3D___gt____tp_init,             /* tp_init */
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

PyTypeObject Pystd__list__lt___ns3__Vector3D___gt__Iter_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    (char *) "mobility.Std__list__lt___ns3__Vector3D___gt__Iter",            /* tp_name */
    sizeof(Pystd__list__lt___ns3__Vector3D___gt__Iter),                  /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)_wrap_Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_dealloc,        /* tp_dealloc */
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
    (traverseproc)Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_traverse,     /* tp_traverse */
    (inquiry)Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_clear,             /* tp_clear */
    (richcmpfunc)NULL,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)_wrap_Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_iter,          /* tp_iter */
    (iternextfunc)_wrap_Pystd__list__lt___ns3__Vector3D___gt__Iter__tp_iternext,     /* tp_iternext */
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
static struct PyModuleDef mobility_moduledef = {
    PyModuleDef_HEAD_INIT,
    "mobility",
    NULL,
    -1,
    mobility_functions,
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


MOD_INIT(mobility)
{
    PyObject *m;
    PyObject *submodule;
    #if PY_VERSION_HEX >= 0x03000000
    m = PyModule_Create(&mobility_moduledef);
    #else
    m = Py_InitModule3((char *) "mobility", mobility_functions, NULL);
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
    /* Import the 'ns3::OutputStreamWrapper' class from module 'ns.network' */
    {
        PyObject *module = PyImport_ImportModule((char*) "ns.network");
        if (module == NULL) {
            return MOD_ERROR;
        }
        _PyNs3OutputStreamWrapper_Type = (PyTypeObject*) PyObject_GetAttrString(module, (char*) "OutputStreamWrapper");
    
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
    PyModule_AddObject(m, (char *) "_PyNs3Box_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Box_wrapper_registry, NULL));
    /* Register the 'ns3::Box' class */
    if (PyType_Ready(&PyNs3Box_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Box", (PyObject *) &PyNs3Box_Type);
    PyModule_AddObject(m, (char *) "_PyNs3ConstantVelocityHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3ConstantVelocityHelper_wrapper_registry, NULL));
    /* Register the 'ns3::ConstantVelocityHelper' class */
    if (PyType_Ready(&PyNs3ConstantVelocityHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ConstantVelocityHelper", (PyObject *) &PyNs3ConstantVelocityHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3GeographicPositions_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3GeographicPositions_wrapper_registry, NULL));
    /* Register the 'ns3::GeographicPositions' class */
    if (PyType_Ready(&PyNs3GeographicPositions_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GeographicPositions", (PyObject *) &PyNs3GeographicPositions_Type);
    PyModule_AddObject(m, (char *) "_PyNs3MobilityHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3MobilityHelper_wrapper_registry, NULL));
    /* Register the 'ns3::MobilityHelper' class */
    if (PyType_Ready(&PyNs3MobilityHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "MobilityHelper", (PyObject *) &PyNs3MobilityHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Ns2MobilityHelper_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Ns2MobilityHelper_wrapper_registry, NULL));
    /* Register the 'ns3::Ns2MobilityHelper' class */
    if (PyType_Ready(&PyNs3Ns2MobilityHelper_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Ns2MobilityHelper", (PyObject *) &PyNs3Ns2MobilityHelper_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Rectangle_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Rectangle_wrapper_registry, NULL));
    /* Register the 'ns3::Rectangle' class */
    if (PyType_Ready(&PyNs3Rectangle_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Rectangle", (PyObject *) &PyNs3Rectangle_Type);
    PyModule_AddObject(m, (char *) "_PyNs3Waypoint_wrapper_registry", PyCObject_FromVoidPtr(&PyNs3Waypoint_wrapper_registry, NULL));
    /* Register the 'ns3::Waypoint' class */
    if (PyType_Ready(&PyNs3Waypoint_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Waypoint", (PyObject *) &PyNs3Waypoint_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::PositionAllocator), &PyNs3PositionAllocator_Type);
    /* Register the 'ns3::PositionAllocator' class */
    PyNs3PositionAllocator_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3PositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "PositionAllocator", (PyObject *) &PyNs3PositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomBoxPositionAllocator), &PyNs3RandomBoxPositionAllocator_Type);
    /* Register the 'ns3::RandomBoxPositionAllocator' class */
    PyNs3RandomBoxPositionAllocator_Type.tp_base = &PyNs3PositionAllocator_Type;
    if (PyType_Ready(&PyNs3RandomBoxPositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomBoxPositionAllocator", (PyObject *) &PyNs3RandomBoxPositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomDiscPositionAllocator), &PyNs3RandomDiscPositionAllocator_Type);
    /* Register the 'ns3::RandomDiscPositionAllocator' class */
    PyNs3RandomDiscPositionAllocator_Type.tp_base = &PyNs3PositionAllocator_Type;
    if (PyType_Ready(&PyNs3RandomDiscPositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomDiscPositionAllocator", (PyObject *) &PyNs3RandomDiscPositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomRectanglePositionAllocator), &PyNs3RandomRectanglePositionAllocator_Type);
    /* Register the 'ns3::RandomRectanglePositionAllocator' class */
    PyNs3RandomRectanglePositionAllocator_Type.tp_base = &PyNs3PositionAllocator_Type;
    if (PyType_Ready(&PyNs3RandomRectanglePositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomRectanglePositionAllocator", (PyObject *) &PyNs3RandomRectanglePositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::UniformDiscPositionAllocator), &PyNs3UniformDiscPositionAllocator_Type);
    /* Register the 'ns3::UniformDiscPositionAllocator' class */
    PyNs3UniformDiscPositionAllocator_Type.tp_base = &PyNs3PositionAllocator_Type;
    if (PyType_Ready(&PyNs3UniformDiscPositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "UniformDiscPositionAllocator", (PyObject *) &PyNs3UniformDiscPositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map.register_wrapper(typeid(ns3::BoxChecker), &PyNs3BoxChecker_Type);
    /* Register the 'ns3::BoxChecker' class */
    PyNs3BoxChecker_Type.tp_base = &PyNs3AttributeChecker_Type;
    if (PyType_Ready(&PyNs3BoxChecker_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BoxChecker", (PyObject *) &PyNs3BoxChecker_Type);
    PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map.register_wrapper(typeid(ns3::BoxValue), &PyNs3BoxValue_Type);
    /* Register the 'ns3::BoxValue' class */
    PyNs3BoxValue_Type.tp_base = &PyNs3AttributeValue_Type;
    if (PyType_Ready(&PyNs3BoxValue_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "BoxValue", (PyObject *) &PyNs3BoxValue_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::GridPositionAllocator), &PyNs3GridPositionAllocator_Type);
    /* Register the 'ns3::GridPositionAllocator' class */
    PyNs3GridPositionAllocator_Type.tp_base = &PyNs3PositionAllocator_Type;
    if (PyType_Ready(&PyNs3GridPositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GridPositionAllocator", (PyObject *) &PyNs3GridPositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ListPositionAllocator), &PyNs3ListPositionAllocator_Type);
    /* Register the 'ns3::ListPositionAllocator' class */
    PyNs3ListPositionAllocator_Type.tp_base = &PyNs3PositionAllocator_Type;
    if (PyType_Ready(&PyNs3ListPositionAllocator_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ListPositionAllocator", (PyObject *) &PyNs3ListPositionAllocator_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::MobilityModel), &PyNs3MobilityModel_Type);
    /* Register the 'ns3::MobilityModel' class */
    PyNs3MobilityModel_Type.tp_base = &PyNs3Object_Type;
    if (PyType_Ready(&PyNs3MobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "MobilityModel", (PyObject *) &PyNs3MobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomDirection2dMobilityModel), &PyNs3RandomDirection2dMobilityModel_Type);
    /* Register the 'ns3::RandomDirection2dMobilityModel' class */
    PyNs3RandomDirection2dMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3RandomDirection2dMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomDirection2dMobilityModel", (PyObject *) &PyNs3RandomDirection2dMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomWalk2dMobilityModel), &PyNs3RandomWalk2dMobilityModel_Type);
    /* Register the 'ns3::RandomWalk2dMobilityModel' class */
    PyNs3RandomWalk2dMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3RandomWalk2dMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomWalk2dMobilityModel", (PyObject *) &PyNs3RandomWalk2dMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::RandomWaypointMobilityModel), &PyNs3RandomWaypointMobilityModel_Type);
    /* Register the 'ns3::RandomWaypointMobilityModel' class */
    PyNs3RandomWaypointMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3RandomWaypointMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RandomWaypointMobilityModel", (PyObject *) &PyNs3RandomWaypointMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map.register_wrapper(typeid(ns3::RectangleChecker), &PyNs3RectangleChecker_Type);
    /* Register the 'ns3::RectangleChecker' class */
    PyNs3RectangleChecker_Type.tp_base = &PyNs3AttributeChecker_Type;
    if (PyType_Ready(&PyNs3RectangleChecker_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RectangleChecker", (PyObject *) &PyNs3RectangleChecker_Type);
    PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map.register_wrapper(typeid(ns3::RectangleValue), &PyNs3RectangleValue_Type);
    /* Register the 'ns3::RectangleValue' class */
    PyNs3RectangleValue_Type.tp_base = &PyNs3AttributeValue_Type;
    if (PyType_Ready(&PyNs3RectangleValue_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "RectangleValue", (PyObject *) &PyNs3RectangleValue_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::SteadyStateRandomWaypointMobilityModel), &PyNs3SteadyStateRandomWaypointMobilityModel_Type);
    /* Register the 'ns3::SteadyStateRandomWaypointMobilityModel' class */
    PyNs3SteadyStateRandomWaypointMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3SteadyStateRandomWaypointMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "SteadyStateRandomWaypointMobilityModel", (PyObject *) &PyNs3SteadyStateRandomWaypointMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3AttributeChecker_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeChecker__gt____typeid_map.register_wrapper(typeid(ns3::WaypointChecker), &PyNs3WaypointChecker_Type);
    /* Register the 'ns3::WaypointChecker' class */
    PyNs3WaypointChecker_Type.tp_base = &PyNs3AttributeChecker_Type;
    if (PyType_Ready(&PyNs3WaypointChecker_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "WaypointChecker", (PyObject *) &PyNs3WaypointChecker_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::WaypointMobilityModel), &PyNs3WaypointMobilityModel_Type);
    /* Register the 'ns3::WaypointMobilityModel' class */
    PyNs3WaypointMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3WaypointMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "WaypointMobilityModel", (PyObject *) &PyNs3WaypointMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3AttributeValue_Ns3Empty_Ns3DefaultDeleter__lt__ns3AttributeValue__gt____typeid_map.register_wrapper(typeid(ns3::WaypointValue), &PyNs3WaypointValue_Type);
    /* Register the 'ns3::WaypointValue' class */
    PyNs3WaypointValue_Type.tp_base = &PyNs3AttributeValue_Type;
    if (PyType_Ready(&PyNs3WaypointValue_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "WaypointValue", (PyObject *) &PyNs3WaypointValue_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ConstantAccelerationMobilityModel), &PyNs3ConstantAccelerationMobilityModel_Type);
    /* Register the 'ns3::ConstantAccelerationMobilityModel' class */
    PyNs3ConstantAccelerationMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3ConstantAccelerationMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ConstantAccelerationMobilityModel", (PyObject *) &PyNs3ConstantAccelerationMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ConstantPositionMobilityModel), &PyNs3ConstantPositionMobilityModel_Type);
    /* Register the 'ns3::ConstantPositionMobilityModel' class */
    PyNs3ConstantPositionMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3ConstantPositionMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ConstantPositionMobilityModel", (PyObject *) &PyNs3ConstantPositionMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::ConstantVelocityMobilityModel), &PyNs3ConstantVelocityMobilityModel_Type);
    /* Register the 'ns3::ConstantVelocityMobilityModel' class */
    PyNs3ConstantVelocityMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3ConstantVelocityMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "ConstantVelocityMobilityModel", (PyObject *) &PyNs3ConstantVelocityMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::GaussMarkovMobilityModel), &PyNs3GaussMarkovMobilityModel_Type);
    /* Register the 'ns3::GaussMarkovMobilityModel' class */
    PyNs3GaussMarkovMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3GaussMarkovMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "GaussMarkovMobilityModel", (PyObject *) &PyNs3GaussMarkovMobilityModel_Type);
    PyNs3SimpleRefCount__Ns3Object_Ns3ObjectBase_Ns3ObjectDeleter__typeid_map.register_wrapper(typeid(ns3::HierarchicalMobilityModel), &PyNs3HierarchicalMobilityModel_Type);
    /* Register the 'ns3::HierarchicalMobilityModel' class */
    PyNs3HierarchicalMobilityModel_Type.tp_base = &PyNs3MobilityModel_Type;
    if (PyType_Ready(&PyNs3HierarchicalMobilityModel_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "HierarchicalMobilityModel", (PyObject *) &PyNs3HierarchicalMobilityModel_Type);
    /* Register the 'std::list< ns3::Vector3D >' class */
    if (PyType_Ready(&Pystd__list__lt___ns3__Vector3D___gt___Type)) {
        return MOD_ERROR;
    }
    if (PyType_Ready(&Pystd__list__lt___ns3__Vector3D___gt__Iter_Type)) {
        return MOD_ERROR;
    }
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Vector3D___gt__", (PyObject *) &Pystd__list__lt___ns3__Vector3D___gt___Type);
    PyModule_AddObject(m, (char *) "Std__list__lt___ns3__Vector3D___gt__Iter", (PyObject *) &Pystd__list__lt___ns3__Vector3D___gt__Iter_Type);
    PyModule_AddObject(m, (char *) "Vector", (PyObject *) &PyNs3Vector3D_Type);
    PyModule_AddObject(m, (char *) "VectorValue", (PyObject *) &PyNs3Vector3DValue_Type);
    PyModule_AddObject(m, (char *) "VectorChecker", (PyObject *) &PyNs3Vector3DChecker_Type);
    {
        PyObject *tmp_value;
         // ns3::Box::RIGHT
        tmp_value = PyLong_FromLong(ns3::Box::RIGHT);
        PyDict_SetItemString((PyObject*) PyNs3Box_Type.tp_dict, "RIGHT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Box::LEFT
        tmp_value = PyLong_FromLong(ns3::Box::LEFT);
        PyDict_SetItemString((PyObject*) PyNs3Box_Type.tp_dict, "LEFT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Box::TOP
        tmp_value = PyLong_FromLong(ns3::Box::TOP);
        PyDict_SetItemString((PyObject*) PyNs3Box_Type.tp_dict, "TOP", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Box::BOTTOM
        tmp_value = PyLong_FromLong(ns3::Box::BOTTOM);
        PyDict_SetItemString((PyObject*) PyNs3Box_Type.tp_dict, "BOTTOM", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Box::UP
        tmp_value = PyLong_FromLong(ns3::Box::UP);
        PyDict_SetItemString((PyObject*) PyNs3Box_Type.tp_dict, "UP", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Box::DOWN
        tmp_value = PyLong_FromLong(ns3::Box::DOWN);
        PyDict_SetItemString((PyObject*) PyNs3Box_Type.tp_dict, "DOWN", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::GeographicPositions::SPHERE
        tmp_value = PyLong_FromLong(ns3::GeographicPositions::SPHERE);
        PyDict_SetItemString((PyObject*) PyNs3GeographicPositions_Type.tp_dict, "SPHERE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::GeographicPositions::GRS80
        tmp_value = PyLong_FromLong(ns3::GeographicPositions::GRS80);
        PyDict_SetItemString((PyObject*) PyNs3GeographicPositions_Type.tp_dict, "GRS80", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::GeographicPositions::WGS84
        tmp_value = PyLong_FromLong(ns3::GeographicPositions::WGS84);
        PyDict_SetItemString((PyObject*) PyNs3GeographicPositions_Type.tp_dict, "WGS84", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::Rectangle::RIGHT
        tmp_value = PyLong_FromLong(ns3::Rectangle::RIGHT);
        PyDict_SetItemString((PyObject*) PyNs3Rectangle_Type.tp_dict, "RIGHT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Rectangle::LEFT
        tmp_value = PyLong_FromLong(ns3::Rectangle::LEFT);
        PyDict_SetItemString((PyObject*) PyNs3Rectangle_Type.tp_dict, "LEFT", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Rectangle::TOP
        tmp_value = PyLong_FromLong(ns3::Rectangle::TOP);
        PyDict_SetItemString((PyObject*) PyNs3Rectangle_Type.tp_dict, "TOP", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::Rectangle::BOTTOM
        tmp_value = PyLong_FromLong(ns3::Rectangle::BOTTOM);
        PyDict_SetItemString((PyObject*) PyNs3Rectangle_Type.tp_dict, "BOTTOM", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::GridPositionAllocator::ROW_FIRST
        tmp_value = PyLong_FromLong(ns3::GridPositionAllocator::ROW_FIRST);
        PyDict_SetItemString((PyObject*) PyNs3GridPositionAllocator_Type.tp_dict, "ROW_FIRST", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::GridPositionAllocator::COLUMN_FIRST
        tmp_value = PyLong_FromLong(ns3::GridPositionAllocator::COLUMN_FIRST);
        PyDict_SetItemString((PyObject*) PyNs3GridPositionAllocator_Type.tp_dict, "COLUMN_FIRST", tmp_value);
        Py_DECREF(tmp_value);
    }
    {
        PyObject *tmp_value;
         // ns3::RandomWalk2dMobilityModel::MODE_DISTANCE
        tmp_value = PyLong_FromLong(ns3::RandomWalk2dMobilityModel::MODE_DISTANCE);
        PyDict_SetItemString((PyObject*) PyNs3RandomWalk2dMobilityModel_Type.tp_dict, "MODE_DISTANCE", tmp_value);
        Py_DECREF(tmp_value);
         // ns3::RandomWalk2dMobilityModel::MODE_TIME
        tmp_value = PyLong_FromLong(ns3::RandomWalk2dMobilityModel::MODE_TIME);
        PyDict_SetItemString((PyObject*) PyNs3RandomWalk2dMobilityModel_Type.tp_dict, "MODE_TIME", tmp_value);
        Py_DECREF(tmp_value);
    }
    submodule = initmobility_FatalImpl();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "FatalImpl", submodule);
    submodule = initmobility_Hash();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "Hash", submodule);
    submodule = initmobility_TracedValueCallback();
    if (submodule == NULL) {
        return MOD_ERROR;
    }
    Py_INCREF(submodule);
    PyModule_AddObject(m, (char *) "TracedValueCallback", submodule);
    return MOD_RETURN(m);
}
