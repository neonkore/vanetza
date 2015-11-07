#ifndef CERTIFICATE_HPP_LWBWIAVL
#define CERTIFICATE_HPP_LWBWIAVL

#include <vanetza/security/serialization.hpp>
#include <vanetza/security/signature.hpp>
#include <vanetza/security/signer_info.hpp>
#include <vanetza/security/subject_attribute.hpp>
#include <vanetza/security/subject_info.hpp>
#include <vanetza/security/validity_restriction.hpp>

namespace vanetza
{
namespace security
{

/*
* described in
* TS 103 097 v1.2.1 (2015-06) section 6.1
*/
struct Certificate
{
    SignerInfo signer_info;
    SubjectInfo subject_info;
    std::list<SubjectAttribute> subject_attributes;
    std::list<ValidityRestriction> validity_restriction;
    Signature signature;
    // certificate version is two, for conformance with the present standard
    uint8_t version() const { return 2; }
};

/**
 * Calculates size of an object
 * \param Object
 * \return size_t containing the number of octets needed to serialize the object
 */
size_t get_size(const Certificate&);

/**
 * Serializes an object into a binary archive
 * \param achive to serialize in
 * \param object to serialize
 */
void serialize(OutputArchive&, const Certificate&);

/**
 * Deserializes an object from a binary archive
 * \param archive with a serialized object at the beginning
 * \param object to deserialize
 * \return size of the deserialized object
 */
size_t deserialize(InputArchive&, Certificate&);

} // namespace security
} // namespace vanetza

#endif /* CERTIFICATE_HPP_LWBWIAVL */

