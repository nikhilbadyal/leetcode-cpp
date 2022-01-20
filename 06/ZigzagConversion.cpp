//
// Created by Nikhil on 01-05-2021.
//

#include "ZigzagConversion.h"
#include <vector>
#include <string>

std::string ZigzagConversion::convert(const std::string &s, int numRows) {
    /*std::vector<std::vector<char>> nums(3, std::vector<char>(6));

    int i = 1;
    int j = 0;
    int str_pos = 1;
    nums[0][0] = s[0];
    bool inc_row = true;
    bool same_col = true;
    std::string ans;


    while (str_pos != s.length()) {
        nums[i][j] = s[str_pos];
        str_pos++;
        if (i == numRows - 1) {
            inc_row = false;
            same_col = false;
        } else if (i == 0) {
            inc_row = true;
            same_col = true;
        }
        if (inc_row) {
            i++;
        } else {
            i--;
        }

        if (same_col) {
        } else {
            j++;
        }

    }
    for (const auto &item: nums) {
        for (auto x : item) {
            if (isalpha(x)) {
                ans += x;

            }
        }
    }
*/
    if (numRows == 1) {
        return s;
    }
    std::string ans;
    std::vector<std::string> pattern(numRows, "");
    int currRow = 0;
    int step = 1;
    for (char c: s) {
        pattern[currRow].push_back(c);
        if (currRow == 0) {
            step = 1;
        } else if (currRow == numRows - 1) {
            step = -1;
        } else {/*Automatically handled*/}
        currRow += step;
    }
    for (const auto &x: pattern) {
        ans += x;
    }
    return ans;
}

/*
 * int main() {
    int no_of_times_to_run = 100;
    int i = 0;
    bool verbrose = false;
    while (i != no_of_times_to_run) {
        auto start = std::chrono::high_resolution_clock::now();
        cout << '"' << getPureRandomString(100) << '"' << endl;
        cout << getRandomNumber(1, 40) << endl;
        std::cout << ZigzagConversion::convert("Nikhilbadyal", 3)<<endl;
if (verbrose) {
auto stop = std::chrono::high_resolution_clock::now();
auto duration = duration_cast<nanoseconds>(stop - start);
std::cout << "Time taken by function: "
<< duration.count() << " nanosecond\n" << endl;
}
i++;
}
std::cout << "Done";
return 0;
}
 * Test cases
 * "zdBsQmgzwrrlkKEEprxDLTgGrkBqyRdrdLAqHdOenNvWkWZUtwIMkYlYOHvpeSzZDNYMUXpnuELHXZeEqLChKsUOMXOQAPeyKrDW"
23
"eKkvTvWxAneazCBqdYdrVNOcAUEqgBZcQrYhNrsUVtTvcKoCYaXwTVfLHpjDUdZAQOjNOYebSiIKQgiyxWGvktnanvrtAyJoecTq"
35
"ZlJABxDuIMOxXXpoEnqmdNtuYvpjpBVVjoNuKylCJgLQnOKqKddUGVbusWKaMHZctiwATMNRSycMCICjEnixUmdvWncGAjFdSPbv"
19
"NIuVRyvGwHtpNqcrXXwxRLXeVdRXkFouSFljawonlrZWfyPZfAKHuhnMIqXGvIKzYMJNdKOXbTYoCblAgcIbRhukSwnOMFSjmwHe"
28
"dxzqpIFPGzXPFjlCWAUtdebxlfuqDdDiwxJaTRYhmqsthCftnZbYMCUvveURiVkkhWyyjLuBkTtOTorhIEnfNjrlLfzMBJHdBrEu"
7
"OIbNqPQRpyHLNCLtdXJlZbVmuOYhwaSarjkdgEKmSIPvvoiWgDDQzwZjVcgswHqfhMGXECUsJqGnozjhBhwHQvFLSClUAXhjwGrx"
8
"aVQSeuKfRNyYnpwPhUYaUPaobIXjSJEQSyArxDOvfnAzSMptwEifQUncSCkpPqjHsfKmLbxTJoyGyAWPFVBUsAiLyINiwUhEYwYC"
35
"iardaAJqPtksiUSlQPGrjMCDBFmImMLjHRadAPvsdEDnDUgspErvAEjLifnTmIezVfNTrIXcxMKltlIMkkfjQCdECtrtMUysWAah"
29
"nBRpWzRcRUmxhfcbiyArGaMwGLlDpBVHLFHHToJDKnOdxhaoEFSSUkqYZEpyATdaHlKpxYLPSliHMoHqMyoufaYiiJJHfaaFArZS"
3
"jSFMEBzbetpifClNbrUnPIsVXQtFfNRjWFmiIBtffPuqaUazEHRVfEfphysTyWIkzNewpxqlAkcMNqyPPMrrXHlLqIOoMYIcfBdp"
32
"ykPEodIfKWyPVXZFsshkTLQKFwhidgrFzQhbmkDTGSWdcEZVpedOeerwhtcQhpKjBBWJMRsCntkzAeEIwXxDMWtztVIluYoerRne"
33
"EZQEfhAyXTzqnfCLgHiHoaJWastPZvzJyBxAirNYCNJBYCwJtFJsOtzkYBeLVjzGcgFdxsCUHHEKRiTozRZfeZozxYuGCxmeqjRE"
8
"dXVOdkXOQyBGaFnmNOByQdoGzeiyNSoQZYOMTyXURMzSCBLsFQksICRgofWbLDMOuogqXHSrOAOcWpYRVdKvdznKGuPrhCYGfujH"
26
"RopAeFFBkcqBtdSngNTtxDHWIoTqmZQFbbDJQGPWxuTGRrPsRjgopwXEYXNKgqhtBSMCKEYJFCqJYqGwBZxENTIBWLBHRRwroRDq"
2
"xdOtPDqvzmmVWRjYYBSNluoKybWkxVTwtFFhXnJzSBUiojzEWfTawBxZIzVuotnUnqRXcKBSCZecmeKfTLyZbYVIArzcoZLgmpGF"
1
"gzxiFglIrXAHmxmcfQKTYObvRZmzpPCXsMvUyLmoEPZcesPaRoyycHFtzgSJFMMNmLKatGzTOhvGUXrkNwAuGmCfxXndkBQxCBQj"
12
"UVfZEsoEEHGZEAnuMJZKHUXbbDIDSWnLcnbqHBfFTtZTzEmeaBgeYezeEWeEZiFyySVyvayCGWQchXuACWETCpcJvVdVhbvKsjbW"
40
"ZPfbkMiZtSKTIoflxjaJMdpkVEenaKRxxOcvNgqNLqOaKNuxbOEhGtZnoHwxZbMmGumnZPcLuecfkGQgILqHFsseCsDAalpjViay"
33
"mjnQsOVnCYNJFeyzyjzuVdOogHtcyOhSkZUfymsTgkquuaiVwqLtPBAaeDuuXkOAJmKxTuNoqGjODjUbPeORrbVmZgIUMxtdsqVF"
36
"aFClMaxUhlAouQEbMxpRelwhfExxMCdWiSijQZhwnMlZbmRtDxLQlUmYoHoLyECauEUpZRDZoHOBmXHxMvtVeQRMWGnFSlNHfkKS"
1
"IuxoTIoxbWyVsfYcXnSRlKEqGzPKghzqCrhuipdODlFnegMOQyKFwBZXRcUbmnQrDnTAmIfluBonVuOLXUUfLNnWFKZDlDJigVhR"
35
"SBdPLLSGClkHqyTQaWeymKzQclQpSCIjTcFcnQSxLRDOqXMwMmVDrmNIgpNvOPHUbTECtfSJCjxNGQvrPFexNMFErWPuVmETCCOk"
16
"IIluHAqsgkXuLPOWlrSZzkTLTZuYMXloIpKxLiiOBnYxTKGvQdNNVMTShKVcKcNnbOetsrrQHfldGtgRebrYrRObdtnWtiDTjEmV"
36
"mOdKkjGmYgSCCnvdejmCwjCLgGKweMuOggVclBPeZykqEGGzDabbMixbJHnGxXmfenGRLFZRAXkBzonIuhinjjpdGCbzZwrWRbPO"
36
"CKJcwekfPPdTHKUqVHfxiDLBcOpQkMqAHJDSNrzZvPwEtDlmITxTrphUEZDUuVmTsLdHpIEysThTthItXQETdqdzqpTOCnEgEZDk"
36
"UkNvpzLkudwaVvgMoEmlDsRTXUMmccliFDbCfOIMzWMQbuyNWILDVElcEPuNxYkMDAtCbAOBDRJQaAdFoBnUUyTlQSzvzJubZHTa"
36
"YkFYYpWrDfHtXAOFWeeigXDnpzrHWlIiYJyFkzBEhDRppbGcpXOhAfdaNUPUIMVccZKWDPzWAVCqJCEwwSIcuzagRZfZVZPCuNCm"
3
"MxIbwphLAhAyDFBEJVmcEiFiyMgAbWOUKAljnlMeMUqwTMWcEunMrIAFiXrHLHrnoxmNvtiYVVwFoqbvvBiPiPEhQaesUciOQykD"
21
"fUdZcCKkVuqqZDPsXTAhdQYKEhNiqwITVNBOadaxzYtKCaQiXCkZZKSVqmUIEpTYYBlbcRPxaPdcyUNIhUJfjSYANfSuZNXjxhKs"
34
"RDCsSCbSCaBJPJJdgRaxtoeuXZUlUCzKSakUksayursXrYYtiHRtjClsTvesYkRCfspYpmDfAmMRXVSVEpQsQcdtsmzSotLluMcN"
6
"ZRhLyxpxBjDMoPSYKfAZtBMrTvZvWtBRmxmWnQaXuYQAEtHNQPMCDqeUcvlLwaJFjVZnMtIPtAoWITUXSoPDiaatAbKhBHhgktvW"
15
"lMdmKJeAFNbUrItPNPxdtVtAFXiFVsRFbBCHwfvVGcERHKoXJOhGaNTbYSDSDEFAdrOBMEAweJnijPWQrUgftRoKCEjmMekmujZF"
39
"hVSHAUOuJDuDrMYIvQhIjIbTobdxmDDVRiSBpNSjHMlyZAcGizBYLLuuEWAHEywrhlkOWlgQDVUwFkBctdHuZtsiaTIpIKNKzAAE"
15
"QCzkgYSNApGTmIwaYPUAleOXkdReOVVrlKrKHIRzXQpXqoNZoGEIfJQsTPkntQdDlPePzSiEdJYhtgiLIJTjjCvCpakWmTTdfyos"
36
"OQqiVlagWyPOkzUUptOJxdJccbsLUXFNmDODjdvzItohpJjbiLIDUuFVPAeOiCcBcssxXqDcgDRIsQYNxgtztPtUOFHTIXhSpFQV"
6
"VUuVafRSCVOPUgEEoJnhLiJRRhjUmarpPMJEEqPzEHfdqhaFyFScttNGFglSYLkvcuiISLxEYTNBozqgosHELTdgnIOMcxfLJZPC"
34
"EFuPzxcluGACYFStYGVTUdUoGWSjqJZipiRTzHChSiLLWfOvCBsCFeyHmbJFyFEEOSiiBNPcuYzaojtDoDCuNVEaNzxvMdlhJRzd"
40
"aKXDqbLSejhBihxneeAyLvnBEMFFcmsThkNxpSczfTyruEmrkCUalYHbXnvEwdqCgYWzYDELHpGDxyHMXxIjowuScondamFWzNBq"
33
"jBXJBLMwatcVCIADzBuCKcgWCcsCxNvYYGgRMuRrTwprNJooXbCunUNpxVPnNsjSkWaRYIFPjvQpvJSYPLyqFdMVvloBgsrjKhRz"
31
"tVDUoIxtWqVbBfQjXEPJqOMiigypMDwBkSmqyphHTKgUiPBpfFfZvdaBQgNGlgAwuhlAUVfNsDbZJRIHVnnrJoNHXAgenSNeJaLt"
30
"HcFboyYKzLdmOJGNXYpXaeKhdTTifLiJUGPHGxczWCfGgikbYuGeHESgNcflTRdAbrkQBsShMxGHXDyhcdbUImBfYhBTRivVaWlQ"
9
"owGzTyalrRxMAQkMrbdFSeirDSzyHTKAJTmmzUNqCqVsYDiHsPTeiXRHIzstvOejwtHMyfvwhWvsDddeYHONTblAbyLYedlOSRuz"
3
"KrCCtztINqvWGeuuObBGVKGdiCVCpAAcsRVxIdZHxJadspOejrWeYFAAIecJHWyxGyesexflxGzLFoESEfjotfeDHvESovqzlOVY"
30
"OAiiAdFkNDkVuTLqdSgPxDAxtpJVsuuRdCNqsXaCNnbdqulunNFmAKJzTASEkmyhyzQMuvdrdAhdJxLGTwUnLLHUIsABBbTYZOnP"
38
"INvPvcaOyWzBARECTyRJCZvFmftdthcceuMioFTlWgBEOyXrqlAynBVmZdTohYPxAKjtjSFjRttFgRrEwKgbHSLkEGwCitNgyRXY"
4
"NBBzNZsalNEqijyXNPLWPJnbKOLNHJjOjRXfDfjlktbwmTBUjvyImSOSXuTyOygIVwNYnzsMUFtcQdSFyDNVBsAuPlRssfzJFnPr"
2
"cGXeohgTpxIWJhYYSyqgXUDqndcdZCkjvXAeQJpMzrqnmBaRfATdHonxscoQXKUNdqAPFMBKlsFocNkCFtAZIPDlUQGiGwoLdrgx"
14
"VabIovOrSKRQgabBwsvozHtMddYRJxZVgImsiRkahQNTCAgqaBaTNlGcuYPBvaFpsVGaIBtTngeiWfkarUXJRanwJPfdnbEHMlMw"
33
"CbtmuVhVbRAJLoSqxxsYOXAHjRLYzARFPuLwmuspqvUHPbhvGuJQcgZaMUdQvnQUfRuxkTmOICvhIkTTfAoqtyunUNOetRzrrnoJ"
4
"ABPPyrWFRuVhWOsSwSNqWUgonpaqBCazCMEkLhOJhrNHNUGLtRMZzWwrPkyUKApOszJOJMaFOsMhDbwRsTocxWHfrzGoopiKRCON"
4
"kldGsXTprRAqhSXiZLTDoXkCSUjzuVTnRtEXxmQXDAfrZZyatbHQPKzXeaiLZqzgpTixxCPkGhBZUxOQRWcERbMucshRyKUzrhHf"
37
"RwsBLUbyphIoInWdNAeKukrspHWjPDjRhXEpdicosuIKYhrevLpjsksvJcaxiTTAwVAZqLGxvOgPMIKflWKrIgsPZVMEIqlWtKXD"
10
"LWJUlnrlccKIzpQqCxrEIGCHPyaCCVeFzeAbkFYRLVLHJsNuMFhRuVcZZwOTRNAaOGsxLSPULbuMnruqFEjNMAjsofcJUqlvlSQn"
31
"HyVlprxVxAeDBBHSEQqLlbVipPPQHDyILdhmaKxlmXFCjRqadnAnJBNFPrvSkSdOHcJQxnBFmRLOiHGbqYejeaFavQRqgAZLkzck"
30
"hbyyutoYNlytPNOaryBkuAIotODqTwQXaMZSKbIsYhDoDXMHYGzpRBWIOVVXWaBJnSMqIefFgharfDeMEerUyrICJiWZumfhFCIZ"
39
"gUjBKIWkgFjCuLBIEIdxXMKiXTaCkpbjZUMigzpBsiArJwikcuCMTjLopDtVzFggWmxVOQAdnKqvLbjauPvHVwWuhYkSrafGqpyj"
15
"fjJQfHYVfOgdpgPwwRCQCLhPIzAMofjcQVvRYtQeeVGqTiOLUqDnslLxIWXnbiWoqWjgMFndduaeFGMUFLkOshntvOuNgQTJzuCI"
12
"PWUfWknRdoeFriHnomwKuChNySZpfmDFHVFHVOTQrScXSxNAysQFludnnrzlXfUMNiLWDoQBYhpzNSmhXllsytYDcIDQgzETDgce"
37
"RJqNxxdGPmYQYuewPXvKIeeLVCSGCcoVCAMYMLgFmeEnqrCVFjeUiKwQnAzkrUAanFtZIWfAHhFurOZlPvwsBbDSLYMSKCPVzYwx"
11
"wlbhYBkVwtzlhvQTOfyadRlgZaUEIqIjfldzGqFQhPBCOlnsSGygPPanCqgluMdBMqiEhxSiAMZyqoxuhUoaTjPIQckjUMqhbwtH"
39
"HSjNVRKvxQiASrEskEIabOTGEJDsvvTnYwBizbKIkejVpKjDLiWThYfhKfCEftdcVnaxNJyTAVIldbfRWgpFFMSftGNFKvoMYlqz"
40
"UtFIpUjfeWyEiUujiNUJPxuLeJEcORluIhlsBaDojTXaYWLUGmRTLCGvevTWhTjMjgOFBtESsEQUXhtYsUjYTiurNXabBExOluEW"
7
"jntUdOclHoOWiKeIccxQuZLrCcCpPvMLZHmejnMDzATWLibMHpnVXADXNQQePZXJdUPYbxKwVrvjWAFZSPvbDFTAjANWhiCwIkhA"
26
"KWrdUykMJDsLaXIFLbtvLMisEAOKkABGeLVSWJEprtzdWAhpuOtFsKQfZFoaKeHKORBCWjnQHtsTUiIGZaDdJxnCTiXrhttPCsMU"
23
"GPjjgSqKmFUhcbONzBGlINgkqDpuxhdvFxtXLctnnwnYxKaiHNTMZKAAWADfWGgrnAMOrUJwbKZczaRHryeQWeDDrXFASeGrzpql"
6
"ADkkzROBbUYWiXUtiNVrbpiXhrqcyLqBQELksAVbxPqmpgnXdeLMxKmbPyTrWsEYkpPvvzbbhwvAUqGhnqjWKEwwmbTEnklKsUTM"
30
"DPUHIzzAiIuywNFAORhOruNmzjkuNDYGmkBkMgPDkdHGqQxuXzOtfobvqdcCxsgQsqsBksgMkNNdQXUbYqFOuEaEkheTrYFuZUhZ"
29
"GwbJtadIcZzywgFHnhprfSlxQToYSKeDhFtKbnCEfqPOcFYRGRwdLafXSYGEAOqkFPnbDnOkNGMHoMkEGvKTJYQPqwzZplBflAnN"
13
"GrjsLMKhmEpsIghoNfXHVFbmtWqQNssubXWoKuPftRPAnmuFwkRvnRsKTmJmHUYmjjMoLTqRHaXhWGgKcfFZjNrPqdZxGuhePYQs"
23
"MDMmNuQtyRffGtYUkRgbsoBGTEclEtpoDntAZYkEGWIzPdDRGXHUMmtvYjvvDwrGhrMTuTvbAOtgBIzSBeECXSyNUELmnuafljoR"
34
"lsyrJBKCIsistnVBxhavrvegONOObhdjbABnaZCmzUBRmCPqjDMJMSXOSJcOcHNKhIxLmSGofkjJQJlfFMaAXTsEMgKvsTlhnVQV"
7
"CwPFTdyGryHyputDZJaQtTOHdIkDbelWpPlqOhUgFhCjfAbgWmDhRfNehGTuUMfFuEUzoebuQUBGnmmgdkhLQaYpHJlNImlyMJHD"
18
"VWrqFEGISEGfAGjbnEHWVMTxLOnzzzRmQXHSdDwSHZKApnxcQJbwYZTGPypTaaAQuWYdsvgPToXiiEFQAhITaEZRxrStpxyVwSrL"
32
"MNPqcNyLfIOKngytPDZFKvBdQfAiLnoOgtHkOZefsvNOcnFZdlwTDbHFJwylFCXNHmesmWFaefqPFAaBHPYoTAlxUXubeodvFkAG"
18
"XHPdaiJwoHgOwLUMssgjlLczkStyQEVDrTreasTGLERcBfjOxFhPgtVibHzzHykpriDbidwfUTmTxxuZUwIsGEfXMRFmFlzgnNJL"
12
"KPRfaGLNXpoXsvOhhpbKvijwDizOpSUszHGBFqZSmnYJDZjtoAeCEvehpYbwrlScprdeAAicCNcOKaxedYtjtIJqzAljMKpNbXXh"
31
"BcHKHkvjriuzlFcHoIQSxtFgTwlWmqijqiVgEDOsuXasjjSWDQNmyNhNDmDowbqpqNXhCFvdvXpvrgUiqcgpbapMupEAyWahXxZS"
20
"WcNiljjNrRaidPgVdUfNaaDAhvqDltOHUMRIAiUYPFkqjVZnYVwjMHhWlrOMNAsuMWCCCWkBepSsKFFyvNwtWUMqMqJSuHZgVBWY"
14
"abJQXfwbMHduusJKSnQcThCshDnzCqzmubpVuZXLWxOiSmMDlmGeMKKbxcfPXHWJwZlwGtQcbkkdxdnqnOsMeBNAwLnmoGFTarYW"
8
"giLsgPAmLYBKCySJtdGsgqFtiIpgSKMuhagDxNhXpDXFIcKtVlyBAnEhKqdtwTeZGhCyOygVzJjjUlpyASgXGMlmkRpjXNHUmIPN"
5
"kyHvphKGRTeENYRJMGlaHTDimmlzISYDkVxoHOaBuKWIpJcnuKUIKRncyJCensKnphMLypBHbVikiXhvETLuZNdZrJEDdxWUvhUP"
29
"fEqTHAHnRqjheMMTIJxzKHUmwTVrEAbJplMECFZHFwSacriNqprJYsBRyABtzKKXqiPijIeiTTAfeEGzSvhIjXqMNtutFUAMLKrW"
26
"GCnILzUOyZqiRLwxtjjQRpCWWNXhBVNJVIgRJoYLKThMujeIGIMPDEIEbxpFcMUjqcuoxdeOlkhRQikMgqcIdHFQCsdnZYWeWtnU"
21
"LjTlJzgIWkoQXPqAuNFSjZFZbUHTKfxHFTsAzZwFDwfuhDMvKWJIdJBGzrbuPndyyakGyQZIUrBqAULVsUNBhNKCosOQUUIGKsDR"
35
"YdRhDzNhNmRhEPMcMQZzlxnWhTASabqPgoMgBXEwAvVEMzSFZSVDbmnguiMpCtLghGgidIGAEjDQqJZglXRaxeXvIoUqKwwiHCRH"
22
"YPSbYMuJZGVEMxatDuSSbpUsylPnDWWUnFiqkzHixzQBuwJMTSgGFhHKWQHJKzjlihGgoOmoEocNxZBLWTKbtkvYDpIHmPRSEgPh"
31
"YlCDEKmGgjRjOCrvpNUgMvvRQBzQeLpWrJJwgGikhBcvXljfMnYlOlxsFtjJkeebnbufrPkHYgdvvbNWIogMeztkwVghQpxPOqmv"
28
"UhbBnKSPtDWKhKrZonBpkNEhOUBtJtiOuoBNWAqyyZEUiwtPiLQXxadFhgrNwcCmnrvPRBMtpcJsgiDRcKhyCDHESfVtjMIMQBqz"
19
"UwPoOMvguoaCocjvSVwrsnblOCOsRAVFRrtKxNxaoKBzkbIOuGmlLukagtUfixftFuKMqtnDSRASUVudztTcUzjMoYxtHvFXbkey"
13
"HbsnFwTmzplepYnqvgZKnyuZcYzqrWffXgJnFYqFOLCTqQcpqKyMgDoulZORvywXrVSkoSZtiJSfEQBZYcYRCvgsgSdfJOBZHjwh"
14
"bvLiLVtbqzdvdtTNbzvjPtVGPqjINoNWeInLTEhehvKSfehDUsvYWGyEDUftLastcvoEgevybgemxBJqnsoJRngYlVKepalqULCw"
3
"HORVxFPlyWBthCKxIkEOYExKlMCupsWNWZyvwuaVFQQJapSYKNUHczRmGLycHgbZJVFcArchQlFmPLBRLVVTqMgTBClcNKbxqDyB"
36
"rDtzBGPjChyQIdYIJBApfCsrIanBSPnCLiVfDqEUfQgjvrdNsdeawkcEyGwcljaxszaiOhSRgDxdWMIrZmViehCsVRxyquLEGaFf"
16
"WdgCIsIGWgxbEAEcqvkVdsOtTIGQWjTZiNldFmQCZWBTIVxnaTvRqAYZpGfLkMfxAryRuEyOhOYOyvWgxzTjWTsJnrRfOrQJFzkp"
1
"VeOasdaFEtbWJizcMlYivLIZBQpInWZfLiWoAQvlOaCrOJzmCYInEfzRfdsoStlTYjMmvLHLZjGzTqDpHiejesyvVvwtZSQDRUhw"
39
"bUwnaStgvvrpyiSvpejPSTaDzmEFhCOrjdlnmhxvqwTSCJzvhIYDwBVuTljjvJiEZwJlzfpvGtbHFAakJomyHEIIrPPFRgFAwDse"
9
"lGDqyeNqCmdwYJgVEyisifTBYieMSyIWcyaooLcfoOFTXUxVCFYyDmohDTjCjtweGkMdlvMyUFlRATkLgDHPnIJNEFMUwLQhZbio"
40
"gLrTDGcfnzesmWvWskyLtvBlfhNIFDieLeAxDqvhPgbfZSoTYrmtOdOfFKiKEzEfqtBQzJVMdDBAcNCUSglKEDiRKudxChOtjLzp"
3
"bDjSvUtbDVykLDMCIsmCdPSVdhyEfsKSIbFfbMEVBoDguoyzUTweELeJLPYvgvFYUKwZNkcoLPSreTskwJfuItrYwKjNcwvrAcRT"
39
"mqtJJQmIwQnxZZZgrtItvyCkTZxjTDCPWjIZLPISDhmsvCvvfvjcJPdgLvkCFKxIhvtIdoUfRHePXQiJEhPiPsQZmRVcPUNnihfk"
14

 */
