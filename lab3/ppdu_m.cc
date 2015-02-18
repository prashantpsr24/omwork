//
// Generated file, do not edit! Created by nedtool 4.6 from ppdu.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ppdu_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(Ppdu);

Ppdu::Ppdu(const char *name, int kind) : ::cPacket(name,kind)
{
    this->src_var = 0;
    this->dest_var = 0;
    this->type_var = 0;
}

Ppdu::Ppdu(const Ppdu& other) : ::cPacket(other)
{
    copy(other);
}

Ppdu::~Ppdu()
{
}

Ppdu& Ppdu::operator=(const Ppdu& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Ppdu::copy(const Ppdu& other)
{
    this->src_var = other.src_var;
    this->dest_var = other.dest_var;
    this->type_var = other.type_var;
}

void Ppdu::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->src_var);
    doPacking(b,this->dest_var);
    doPacking(b,this->type_var);
}

void Ppdu::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->type_var);
}

int Ppdu::getSrc() const
{
    return src_var;
}

void Ppdu::setSrc(int src)
{
    this->src_var = src;
}

int Ppdu::getDest() const
{
    return dest_var;
}

void Ppdu::setDest(int dest)
{
    this->dest_var = dest;
}

bool Ppdu::getType() const
{
    return type_var;
}

void Ppdu::setType(bool type)
{
    this->type_var = type;
}

class PpduDescriptor : public cClassDescriptor
{
  public:
    PpduDescriptor();
    virtual ~PpduDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(PpduDescriptor);

PpduDescriptor::PpduDescriptor() : cClassDescriptor("Ppdu", "cPacket")
{
}

PpduDescriptor::~PpduDescriptor()
{
}

bool PpduDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Ppdu *>(obj)!=NULL;
}

const char *PpduDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PpduDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PpduDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PpduDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "src",
        "dest",
        "type",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PpduDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PpduDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PpduDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int PpduDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Ppdu *pp = (Ppdu *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PpduDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Ppdu *pp = (Ppdu *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrc());
        case 1: return long2string(pp->getDest());
        case 2: return bool2string(pp->getType());
        default: return "";
    }
}

bool PpduDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Ppdu *pp = (Ppdu *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrc(string2long(value)); return true;
        case 1: pp->setDest(string2long(value)); return true;
        case 2: pp->setType(string2bool(value)); return true;
        default: return false;
    }
}

const char *PpduDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *PpduDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Ppdu *pp = (Ppdu *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


