
void FUN_00452d50(void)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  undefined1 auStack_90 [12];
  undefined4 uStack_84;
  undefined1 *puStack_80;
  int *piStack_7c;
  undefined1 auStack_64 [4];
  int *piStack_60;
  int iStack_5c;
  int local_58;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_38 [20];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931a5c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  ExceptionList = &local_14;
  FUN_007459c0();
  iVar9 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00452dc4;
    iVar9 = FUN_00745c20();
  }
  if ((((iVar9 != 0) && (*(int *)(iVar9 + 0x60) != 0)) &&
      ((*(uint *)(iVar9 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar9 + 0x60) != 0)) {
    piStack_7c = (int *)0x452dc4;
    FUN_0074a010();
  }
LAB_00452dc4:
  iVar9 = DAT_00fc0c68;
  local_58 = DAT_00fc0c68 + 8;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 0;
    FUN_004f3d80();
    piStack_7c = (int *)0x452df8;
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
  }
  piStack_7c = (int *)0x452e10;
  FUN_004f6a30();
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0xf0) + 200))();
  piStack_7c = *(int **)(iVar9 + 0x42);
  puStack_80 = auStack_38;
  uStack_84 = 0x452e43;
  FUN_00433f80();
  local_c = 1;
  FUN_00757710();
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    piStack_7c = (int *)0x452e86;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  piStack_7c = *(int **)(iVar9 + 0x3a);
  puStack_80 = auStack_38;
  uStack_84 = 0x452eab;
  FUN_00433f80();
  local_c = 2;
  FUN_00757710();
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    piStack_7c = (int *)0x452eed;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  piStack_60 = (int *)auStack_90;
  FUN_00453d70(auStack_90,*(undefined4 *)(iVar9 + 0x46));
  local_c = 3;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 4;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = CONCAT31(local_c._1_3_,3);
  }
  iStack_5c = 0x19;
  FUN_005740f0(&iStack_5c);
  if (piStack_60 == (int *)DAT_00fe5ac8) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  puVar4 = (undefined4 *)((int)piStack_60 + 0x10);
  if (7 < *(uint *)((int)piStack_60 + 0x24)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  local_c = 0xffffffff;
  FUN_00453520(puVar4,*(undefined2 *)(iVar9 + 0x36));
  local_c = 5;
  piStack_7c = (int *)0x452fcb;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < uStack_40) {
    piStack_7c = (int *)0x452fe4;
    FUN_0089120c();
  }
  uStack_54 = uStack_54 & 0xffff0000;
  iVar9 = 0;
  uStack_40 = 7;
  uStack_44 = 0;
  (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
  iStack_5c = 0;
  do {
    if (2 < iVar9) break;
    if ((1 << ((byte)iStack_5c & 0x1f) & (int)*(short *)(local_58 + 0x30)) != 0) {
      iVar1 = *(int *)(*(int *)(in_ECX + 0x100) + 0xcc);
      if (((iVar1 == 0) || (iVar9 < 0)) ||
         (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= iVar9)) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = *(int **)(*(int *)(iVar1 + 0xa8) + iVar9 * 4);
      }
      puStack_80 = (undefined1 *)0x453066;
      piStack_7c = piVar7;
      FUN_004527f0();
      (**(code **)(*piVar7 + 200))();
      iVar9 = iVar9 + 1;
    }
    iStack_5c = iStack_5c + 1;
  } while (iStack_5c < 10);
  piVar7 = *(int **)(in_ECX + 0x100);
  piVar6 = (int *)piVar7[0x19];
  piVar8 = (int *)*piVar6;
  piStack_60 = piVar6;
  if (piVar8 != piVar6) {
    do {
      if ((*(int *)(piVar8[2] + 0x60) != 0) &&
         (piVar2 = *(int **)(piVar8[2] + 0x1c), piVar2[2] != 6)) {
        piStack_7c = (int *)0x4530ae;
        (**(code **)(*piVar2 + 0x30))();
        piVar6 = piStack_60;
      }
      piVar8 = (int *)*piVar8;
    } while (piVar8 != piVar6);
  }
  (**(code **)(*piVar7 + 0x128))();
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  iVar9 = *(int *)(in_ECX + 0x108);
  iVar1 = *(int *)(in_ECX + 0x10c + (uint)*(byte *)(local_58 + 0x42) * 4);
  if ((((*(char *)(iVar9 + 0xa4) != '\0') && (*(int **)(iVar9 + 0x94) != (int *)0x0)) &&
      (iVar5 = (**(code **)(**(int **)(iVar9 + 0x94) + 4))(), iVar5 == 0xbf6b)) &&
     (iVar9 = *(int *)(iVar9 + 0x94), *(int *)(iVar9 + 0x10) != iVar1)) {
    if (((iVar1 != 0) && (piVar7 = *(int **)(iVar1 + 8), piVar7 != (int *)0x0)) &&
       (piVar7[0x27] = piVar7[0x27] + 1, piVar7[0x27] == 1)) {
      (**(code **)(*piVar7 + 0x24))();
    }
    if ((*(int *)(iVar9 + 0x10) != 0) &&
       (piVar7 = *(int **)(*(int *)(iVar9 + 0x10) + 8), piVar7 != (int *)0x0)) {
      piVar6 = piVar7 + 0x27;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        (**(code **)(*piVar7 + 0x28))();
      }
    }
    *(int *)(iVar9 + 0x10) = iVar1;
  }
  (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

