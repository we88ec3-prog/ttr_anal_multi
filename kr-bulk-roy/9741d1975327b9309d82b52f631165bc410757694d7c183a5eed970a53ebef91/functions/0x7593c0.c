
void FUN_007593c0(undefined4 param_1)

{
  undefined4 *****pppppuVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  char *_Str1;
  int iVar6;
  int *_Str1_00;
  undefined4 *puVar7;
  undefined4 local_7c;
  undefined4 uStack_78;
  char ****ppppcStack_74;
  undefined4 ****local_70 [4];
  undefined4 local_60;
  uint local_5c;
  char ****appppcStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092a790;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_7c = param_1;
  FUN_004297b0(DAT_00d61f20 ^ (uint)&stack0xffffff78);
  pppppuVar1 = (undefined4 *****)local_70[0];
  if (local_5c < 0x10) {
    pppppuVar1 = local_70;
  }
  iVar2 = FUN_0072e2e0(pppppuVar1);
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  local_5c = 0xf;
  local_60 = 0;
  local_70[0] = (undefined4 ****)((uint)local_70[0] & 0xffffff00);
  if (iVar2 != 0) {
    uVar3 = FUN_00764d80(local_38,&DAT_00bed1fc);
    uStack_c = 0;
    FUN_00402800(uVar3);
    uStack_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(local_38[0]);
    }
    piVar4 = (int *)FUN_0072e2e0("Color");
joined_r0x007594b1:
    if (piVar4 != (int *)0x0) {
      uStack_78 = 0;
      FUN_00429860(&uStack_78);
      FUN_004297b0();
      uStack_c = 1;
      if (uStack_40 < 0x10) {
        ppppcStack_74 = (char ****)appppcStack_54;
      }
      else {
        ppppcStack_74 = appppcStack_54[0];
      }
      iVar5 = (**(code **)(*piVar4 + 0x14))();
      for (iVar2 = *(int *)(iVar5 + 0x94); iVar2 != iVar5 + 0x44; iVar2 = *(int *)(iVar2 + 0x50)) {
        _Str1 = (char *)(iVar2 + 0x14);
        if (0xf < *(uint *)(iVar2 + 0x28)) {
          _Str1 = *(char **)_Str1;
        }
        iVar6 = __stricmp(_Str1,(char *)ppppcStack_74);
        if (iVar6 == 0) {
          if (iVar2 != 0) {
            puVar7 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar7 = (undefined4 *)*puVar7;
            }
            if (puVar7 != (undefined4 *)0x0) {
              uVar3 = FUN_008917b4(puVar7);
              goto LAB_00759551;
            }
          }
          break;
        }
      }
      uVar3 = 0;
LAB_00759551:
      uStack_c = 0xffffffff;
      if (0xf < uStack_40) {
        FUN_0089120c(appppcStack_54[0]);
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      appppcStack_54[0] = (char ****)((uint)appppcStack_54[0] & 0xffffff00);
      FUN_00759060(uVar3,0);
      for (piVar4 = (int *)piVar4[0x10]; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x10]) {
        _Str1_00 = piVar4 + 8;
        if (0xf < (uint)piVar4[0xd]) {
          _Str1_00 = (int *)*_Str1_00;
        }
        iVar2 = __stricmp((char *)_Str1_00,"Color");
        if (iVar2 == 0) goto joined_r0x007594b1;
      }
      piVar4 = (int *)0x0;
      goto joined_r0x007594b1;
    }
    FUN_00757940(local_7c,0x7b,0x7d);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

