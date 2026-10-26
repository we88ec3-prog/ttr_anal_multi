
void FUN_008348e0(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined1 local_98 [68];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009092a3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (param_2 != 0) {
    iVar2 = FUN_0072e360(uVar1);
    while (iVar2 != 0) {
      iVar3 = FUN_0072e360(uVar1);
      for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar6 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar6 = *(char **)pcVar6;
        }
        iVar4 = __stricmp(pcVar6,"id");
        if (iVar4 == 0) {
          if (iVar5 != 0) {
            puVar8 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 != (undefined4 *)0x0) {
              FUN_008917b4(puVar8);
            }
          }
          break;
        }
      }
      _eh_vector_constructor_iterator_
                (local_54,0x10,4,(_func_void_void_ptr *)&LAB_00689330,FUN_00418290);
      local_8 = 0;
      while (iVar3 != 0) {
        for (iVar2 = *(int *)(iVar3 + 0x94); iVar2 != iVar3 + 0x44; iVar2 = *(int *)(iVar2 + 0x50))
        {
          pcVar6 = (char *)(iVar2 + 0x14);
          if (0xf < *(uint *)(iVar2 + 0x28)) {
            pcVar6 = *(char **)pcVar6;
          }
          iVar5 = __stricmp(pcVar6,"type");
          if (iVar5 == 0) {
            if (iVar2 != 0) {
              puVar8 = (undefined4 *)(iVar2 + 0x30);
              if (0xf < *(uint *)(iVar2 + 0x44)) {
                puVar8 = (undefined4 *)*puVar8;
              }
              if (puVar8 != (undefined4 *)0x0) {
                FUN_008917b4(puVar8);
              }
            }
            break;
          }
        }
        iVar2 = FUN_0072e360();
        while (iVar2 != 0) {
          for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
              ) {
            pcVar6 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar3 = __stricmp(pcVar6,"id");
            if (iVar3 == 0) {
              if (iVar5 != 0) {
                puVar8 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar8 = (undefined4 *)*puVar8;
                }
                if (puVar8 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar8);
                }
              }
              break;
            }
          }
          for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
              ) {
            pcVar6 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar3 = __stricmp(pcVar6,"qty");
            if (iVar3 == 0) {
              if (iVar5 != 0) {
                puVar8 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar8 = (undefined4 *)*puVar8;
                }
                if (puVar8 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar8);
                }
              }
              break;
            }
          }
          FUN_0052ef90();
          iVar2 = FUN_0072e3c0();
        }
        iVar2 = FUN_0072e360();
        while (iVar2 != 0) {
          for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
              ) {
            pcVar6 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar3 = __stricmp(pcVar6,"id");
            if (iVar3 == 0) {
              if (iVar5 != 0) {
                puVar8 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar8 = (undefined4 *)*puVar8;
                }
                if (puVar8 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar8);
                }
              }
              break;
            }
          }
          for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
              ) {
            pcVar6 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar3 = __stricmp(pcVar6,"qty");
            if (iVar3 == 0) {
              if (iVar5 != 0) {
                puVar8 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar8 = (undefined4 *)*puVar8;
                }
                if (puVar8 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar8);
                }
              }
              break;
            }
          }
          FUN_0052ef90();
          iVar2 = FUN_0072e3c0();
        }
        iVar2 = FUN_0072e360();
        while (iVar2 != 0) {
          for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)
              ) {
            pcVar6 = (char *)(iVar5 + 0x14);
            if (0xf < *(uint *)(iVar5 + 0x28)) {
              pcVar6 = *(char **)pcVar6;
            }
            iVar3 = __stricmp(pcVar6,"amount");
            if (iVar3 == 0) {
              if (iVar5 != 0) {
                puVar8 = (undefined4 *)(iVar5 + 0x30);
                if (0xf < *(uint *)(iVar5 + 0x44)) {
                  puVar8 = (undefined4 *)*puVar8;
                }
                if (puVar8 != (undefined4 *)0x0) {
                  FUN_008917b4(puVar8);
                }
              }
              break;
            }
          }
          FUN_0052ef90();
          iVar2 = FUN_0072e3c0();
        }
        iVar3 = FUN_0072e3c0();
      }
      uVar7 = FUN_008353a0();
      local_8._0_1_ = 1;
      uVar7 = FUN_00835610(uVar7);
      FUN_008353d0(param_1,uVar7);
      local_8 = (uint)local_8._1_3_ << 8;
      _eh_vector_destructor_iterator_(local_98,0x10,4,FUN_00418290);
      iVar2 = FUN_0072e3c0();
      local_8 = 0xffffffff;
      _eh_vector_destructor_iterator_(local_54,0x10,4,FUN_00418290);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

