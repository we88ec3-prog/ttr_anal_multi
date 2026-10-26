
void FUN_006428d0(int param_1)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *piVar4;
  int in_ECX;
  wchar_t *in_EDX;
  undefined4 uVar5;
  undefined1 auStack_42c [4];
  int local_428;
  uint local_424;
  wchar_t local_420 [256];
  undefined1 local_220 [516];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942f4c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_42c;
  ExceptionList = &local_14;
  if ((*in_EDX != L'/') || (in_EDX[param_1 + -1] != L' ')) goto LAB_00642e3a;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffbc8);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_428 = DAT_00fc0bd8;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 1;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  local_424 = (uint)(DAT_00fb7258 != 0);
  iVar1 = FID_conflict__swscanf(in_EDX,L"/%s %s",local_420,0x100,local_220,0x100);
  if (iVar1 == 1) {
    iVar2 = __wcsicmp(local_420,L"a");
    if (iVar2 != 0) {
      uVar5 = 0x29b;
      FUN_00585620(0x29b);
      pwVar3 = (wchar_t *)FUN_00585330(uVar5);
      iVar2 = __wcsicmp(local_420,pwVar3);
      if (iVar2 != 0) {
        uVar5 = 0x239;
        FUN_00585620(0x239);
        pwVar3 = (wchar_t *)FUN_00585330(uVar5);
        iVar2 = __wcsicmp(local_420,pwVar3);
        if (iVar2 != 0) {
          uVar5 = 0x29c;
          FUN_00585620(0x29c);
          pwVar3 = (wchar_t *)FUN_00585330(uVar5);
          iVar2 = __wcsicmp(local_420,pwVar3);
          if (iVar2 != 0) {
            iVar2 = __wcsicmp(local_420,L"r");
            if (iVar2 != 0) {
              iVar2 = __wcsicmp(local_420,L"q");
              if (iVar2 != 0) {
                uVar5 = 0x2a0;
                FUN_00585620(0x2a0);
                pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                iVar2 = __wcsicmp(local_420,pwVar3);
                if (iVar2 != 0) {
                  uVar5 = 0x2a1;
                  FUN_00585620(0x2a1);
                  pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                  iVar2 = __wcsicmp(local_420,pwVar3);
                  if (iVar2 != 0) {
                    uVar5 = 0x2a2;
                    FUN_00585620(0x2a2);
                    pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                    iVar2 = __wcsicmp(local_420,pwVar3);
                    if (iVar2 != 0) {
                      uVar5 = 0x2a3;
                      FUN_00585620(0x2a3);
                      pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                      iVar2 = __wcsicmp(local_420,pwVar3);
                      if (iVar2 != 0) goto LAB_00642c1b;
                    }
                  }
                }
              }
            }
            if (*(int *)(in_ECX + 0x120) == 0) {
              FUN_00642e60(1,0,1);
            }
            else {
              piVar4 = (int *)(in_ECX + 0x110);
              if (7 < *(uint *)(in_ECX + 0x124)) {
                piVar4 = (int *)*piVar4;
              }
              FUN_00642e60(1,piVar4,1);
            }
            goto LAB_00642e3a;
          }
        }
      }
    }
    FUN_00642e60(0,0,1);
    uVar5 = *(undefined4 *)(in_ECX + 0x130);
  }
  else {
    if (iVar1 == 2) {
      iVar2 = __wcsicmp(local_420,L"w");
      if (iVar2 != 0) {
        uVar5 = 0x29d;
        FUN_00585620(0x29d);
        pwVar3 = (wchar_t *)FUN_00585330(uVar5);
        iVar2 = __wcsicmp(local_420,pwVar3);
        if (iVar2 != 0) {
          uVar5 = 0x29e;
          FUN_00585620(0x29e);
          pwVar3 = (wchar_t *)FUN_00585330(uVar5);
          iVar2 = __wcsicmp(local_420,pwVar3);
          if (iVar2 != 0) {
            uVar5 = 0x29f;
            FUN_00585620(0x29f);
            pwVar3 = (wchar_t *)FUN_00585330(uVar5);
            iVar2 = __wcsicmp(local_420,pwVar3);
            if (iVar2 != 0) goto LAB_00642c1b;
          }
        }
      }
      FUN_00642e60(1,local_220,1);
      goto LAB_00642e3a;
    }
LAB_00642c1b:
    if ((local_424 == 0) || (iVar1 != 1)) {
LAB_00642cca:
      if ((local_428 == 0) || (iVar1 != 1)) goto LAB_00642e3a;
      iVar1 = __wcsicmp(local_420,L"g");
      if (iVar1 != 0) {
        uVar5 = 0x2a6;
        FUN_00585620(0x2a6);
        pwVar3 = (wchar_t *)FUN_00585330(uVar5);
        iVar1 = __wcsicmp(local_420,pwVar3);
        if (iVar1 != 0) {
          uVar5 = 0x236;
          FUN_00585620(0x236);
          pwVar3 = (wchar_t *)FUN_00585330(uVar5);
          iVar1 = __wcsicmp(local_420,pwVar3);
          if (iVar1 != 0) {
            uVar5 = 0x2a7;
            FUN_00585620(0x2a7);
            pwVar3 = (wchar_t *)FUN_00585330(uVar5);
            iVar1 = __wcsicmp(local_420,pwVar3);
            if (iVar1 != 0) {
              iVar1 = __wcsicmp(local_420,L"u");
              if (iVar1 != 0) {
                uVar5 = 0x2a8;
                FUN_00585620(0x2a8);
                pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                iVar1 = __wcsicmp(local_420,pwVar3);
                if (iVar1 != 0) {
                  uVar5 = 0x23c;
                  FUN_00585620(0x23c);
                  pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                  iVar1 = __wcsicmp(local_420,pwVar3);
                  if (iVar1 != 0) {
                    uVar5 = 0x2a9;
                    FUN_00585620(0x2a9);
                    pwVar3 = (wchar_t *)FUN_00585330(uVar5);
                    iVar1 = __wcsicmp(local_420,pwVar3);
                    if (iVar1 != 0) goto LAB_00642e3a;
                  }
                }
              }
              FUN_00642e60(0,0,1);
              uVar5 = *(undefined4 *)(in_ECX + 0x130);
              goto LAB_00642e23;
            }
          }
        }
      }
      FUN_00642e60(0,0,1);
      FUN_0075cd30(*(undefined4 *)(in_ECX + 0x130));
      (**(code **)(**(int **)(in_ECX + 0x130) + 200))();
      goto LAB_00642e3a;
    }
    iVar2 = __wcsicmp(local_420,L"p");
    if (iVar2 != 0) {
      uVar5 = 0x2a4;
      FUN_00585620(0x2a4);
      pwVar3 = (wchar_t *)FUN_00585330(uVar5);
      iVar2 = __wcsicmp(local_420,pwVar3);
      if (iVar2 != 0) {
        uVar5 = 0x237;
        FUN_00585620(0x237);
        pwVar3 = (wchar_t *)FUN_00585330(uVar5);
        iVar2 = __wcsicmp(local_420,pwVar3);
        if (iVar2 != 0) {
          uVar5 = 0x2a5;
          FUN_00585620(0x2a5);
          pwVar3 = (wchar_t *)FUN_00585330(uVar5);
          iVar2 = __wcsicmp(local_420,pwVar3);
          if (iVar2 != 0) goto LAB_00642cca;
        }
      }
    }
    FUN_00642e60(0,0,1);
    uVar5 = *(undefined4 *)(in_ECX + 0x130);
  }
LAB_00642e23:
  FUN_0075cd30(uVar5);
  (**(code **)(**(int **)(in_ECX + 0x130) + 200))();
LAB_00642e3a:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_42c);
  return;
}

