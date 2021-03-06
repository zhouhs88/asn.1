// Licensed under the MIT License <http://opensource.org/licenses/MIT>
// Author: Andrew Stalin <andrew.stalin@gmail.com>
//
// THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
// IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
// FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
// AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _ASN1_SUBJECT_PUBLIC_KEY_INFO_H_
#define _ASN1_SUBJECT_PUBLIC_KEY_INFO_H_

#include "asn1/basic_types/bit_string.h"
#include "asn1/basic_types/sequence.h"
#include "asn1/pkix/primitive/algorithm_identifier.h"

namespace asn1
{
	namespace pkix
	{
		/*
			SubjectPublicKeyInfo ::= SEQUENCE 
			{
				algorithm         AlgorithmIdentifier,
				subjectPublicKey  BIT STRING
			}
		*/
		
		struct SubjectPublicKeyInfo : Asn1Value
		{
			pkix::AlgorithmIdentifier algorithm;
			BitString subject_public_key;

			SubjectPublicKeyInfo()
				: SubjectPublicKeyInfo(SEQUENCE_TAG)
			{}

			SubjectPublicKeyInfo(const Tag& tag)
				: Asn1Value(tag)
			{}

			length_type encode(const IEncoder& encoder, io::IAsn1Writer& writer) const override
			{
				return encoder.encode_collection(writer, tag,
				{
					EncodedValue(&algorithm),
					EncodedValue(&subject_public_key)
				});
			}
		};

		class SubjectPublicKeyInfoDecoder : public details::SequenceBasedTypeDecoder<SubjectPublicKeyInfo>
		{
		private:
			AlgorithmIdentifierDecoder algorithm_decoder_;
			BitStringDecoder subject_public_key_decoder_;

		public:
			explicit SubjectPublicKeyInfoDecoder(IValueEventHandler* const event_handler)
				: SubjectPublicKeyInfoDecoder(SEQUENCE_TAG, event_handler)
			{}

			SubjectPublicKeyInfoDecoder(const Tag& tag, IValueEventHandler* const event_handler);

		protected:
			void on_decode_element(Asn1Value&& val) override;
			void on_decode_element(const Tag&, Asn1Value&&) override {}
		};
	}
}

#endif
