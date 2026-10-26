
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_006f2620(void)

{
  HKL pHVar1;
  UINT UVar2;
  int iVar3;
  DWORD DVar4;
  BOOL BVar5;
  uint uVar6;
  undefined1 *puVar7;
  int unaff_EDI;
  undefined1 local_814 [4];
  DWORD local_810;
  int local_80c;
  WCHAR local_808 [1024];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  pHVar1 = *(HKL *)(unaff_EDI + 0x74);
  *(undefined4 *)(unaff_EDI + 0x88) = 0;
  *(undefined4 *)(unaff_EDI + 0x84) = 0;
  if (((((pHVar1 == (HKL)0xe0080404) || (pHVar1 == (HKL)0xe0090404)) || (pHVar1 == (HKL)0xe0060404))
      || ((pHVar1 == (HKL)0xe00e0804 || (pHVar1 == (HKL)0xe0010804)))) ||
     ((pHVar1 == (HKL)0xe0030804 || ((pHVar1 == (HKL)0xe0040804 || (pHVar1 == (HKL)0x804)))))) {
    UVar2 = ImmGetIMEFileNameW(pHVar1,local_808,0x3ff);
    if (UVar2 != 0) {
      if (*(int *)(unaff_EDI + 0x90) == 0) {
        iVar3 = CompareStringW(0x409,1,local_808,-1,L"TINTLGNT.IME",-1);
        if (iVar3 != 2) {
          iVar3 = CompareStringW(0x409,1,local_808,-1,L"CINTLGNT.IME",-1);
          if (iVar3 != 2) {
            iVar3 = CompareStringW(0x409,1,local_808,-1,L"MSTCIPHA.IME",-1);
            if (iVar3 != 2) {
              iVar3 = CompareStringW(0x409,1,local_808,-1,L"PINTLGNT.IME",-1);
              if (iVar3 != 2) {
                iVar3 = CompareStringW(0x409,1,local_808,-1,L"MSSCIPYA.IME",-1);
                if (iVar3 != 2) {
                  iVar3 = CompareStringW(0x409,1,local_808,-1,L"WINABC.IME",-1);
                  if (iVar3 != 2) goto LAB_006f2874;
                }
              }
            }
          }
        }
      }
      DVar4 = GetFileVersionInfoSizeW(local_808,&local_810);
      if (DVar4 != 0) {
        iVar3 = -DVar4;
        *(int *)((int)local_808 + iVar3 + -0x18) = (int)local_808 + iVar3 + -0x14;
        *(DWORD *)((int)local_808 + iVar3 + -0x1c) = DVar4;
        *(DWORD *)((int)local_808 + iVar3 + -0x20) = local_810;
        *(WCHAR **)(&stack0xfffff7d4 + iVar3) = local_808;
        puVar7 = &stack0xfffff7d0 + iVar3;
        *(undefined4 *)(&stack0xfffff7d0 + iVar3) = 0x6f27a6;
        BVar5 = GetFileVersionInfoW(*(LPCWSTR *)(&stack0xfffff7d4 + iVar3),
                                    *(DWORD *)((int)local_808 + iVar3 + -0x20),
                                    *(DWORD *)((int)local_808 + iVar3 + -0x1c),
                                    *(LPVOID *)((int)local_808 + iVar3 + -0x18));
        if (BVar5 != 0) {
          *(undefined1 **)(puVar7 + -4) = local_814;
          *(int **)(puVar7 + -8) = &local_80c;
          *(undefined **)(puVar7 + -0xc) = &DAT_00c1ae08;
          *(int *)(puVar7 + -0x10) = (int)local_808 + iVar3 + -0x14;
          *(undefined4 *)(puVar7 + -0x14) = 0x6f27c8;
          BVar5 = VerQueryValueW(*(LPCVOID *)(puVar7 + -0x10),*(LPCWSTR *)(puVar7 + -0xc),
                                 *(LPVOID **)(puVar7 + -8),*(PUINT *)(puVar7 + -4));
          if (BVar5 != 0) {
            uVar6 = ((*(uint *)(local_80c + 8) & 0xff) << 8 | *(uint *)(local_80c + 8) & 0xffff0000)
                    * 0x100;
            if (((*(int *)(unaff_EDI + 0x90) != 0) ||
                ((*(short *)(unaff_EDI + 0x72) == 0x404 &&
                 ((((uVar6 == 0x4020000 || (uVar6 == 0x4030000)) || (uVar6 == 0x4040000)) ||
                  (((uVar6 == 0x5000000 || (uVar6 == 0x5010000)) ||
                   ((uVar6 == 0x5020000 || (uVar6 == 0x6000000)))))))))) ||
               ((*(short *)(unaff_EDI + 0x72) == 0x804 &&
                (((uVar6 == 0x4010000 || (uVar6 == 0x4020000)) ||
                 ((uVar6 == 0x5030000 || ((uVar6 == 0x5010000 || (uVar6 == 0x5020000)))))))))) {
              *(uint *)(unaff_EDI + 0x84) = *(ushort *)(unaff_EDI + 0x72) | uVar6;
              *(undefined4 *)(unaff_EDI + 0x88) = *(undefined4 *)(local_80c + 0xc);
            }
          }
        }
      }
    }
  }
LAB_006f2874:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

