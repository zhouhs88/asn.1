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

#include "structured_type_test.h"
#include "file.h"
#include "asn1/pkcs10/certification_request.h"
#include "gtest/gtest.h"

using namespace asn1;

TEST(certification_request_info_case, decode_encode_test)
{
	test::StructeredTypeTest<pkcs10::CertificationRequestInfoDecoder>(test::load_file("data/certification_request_info")).execute();
}

TEST(certification_request_case, decode_encode_test)
{
	test::StructeredTypeTest<pkcs10::CertificationRequestDecoder>(test::load_file("data/certification_request")).execute();
}
