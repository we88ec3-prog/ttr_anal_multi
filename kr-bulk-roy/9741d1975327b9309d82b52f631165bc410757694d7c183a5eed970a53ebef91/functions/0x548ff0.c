
void FUN_00548ff0(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 in_EAX;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 in_ECX;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  *(undefined4 *)(param_1 + 0x50) = in_EAX;
  *(undefined4 *)(param_1 + 0x54) = in_ECX;
  *(undefined4 *)(param_1 + 0x58) = param_2;
  *(int *)(param_1 + 0x5c) = param_3;
  *(int *)(param_1 + 0x60) = param_3 + 1;
  FUN_00549180();
  iVar4 = *(int *)(param_1 + 0x50);
  if (iVar4 == 0) {
    return;
  }
  iVar6 = 0;
  puVar2 = (uint *)(param_1 + 0xa8);
  while (*puVar2 != (uint)*(ushort *)(iVar4 + 4)) {
    iVar6 = iVar6 + 1;
    puVar2 = puVar2 + 4;
    if (2 < iVar6) {
      return;
    }
  }
  if (iVar6 == -1) {
    return;
  }
  iVar7 = *(int *)(param_1 + 0x6c);
  *(int *)(param_1 + 0x108) = iVar6;
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(&DAT_00d6a60c + (param_3 + iVar7 * 3) * 4);
  if (*(int *)(param_1 + 4 + iVar6 * 4) == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x5c);
    uVar5 = (uint)*(ushort *)(iVar4 + 0x88);
    FUN_0048a2e0(uVar5,iVar7,uVar3);
    uVar3 = FUN_0054b870(uVar5,iVar7,uVar3);
    *(undefined4 *)(param_1 + 4 + iVar6 * 4) = uVar3;
  }
  iVar4 = FUN_00549e10();
  if ((((iVar4 == 0) && (iVar4 = FUN_0054a450(), iVar4 == 0)) &&
      (iVar4 = FUN_0054a3a0(), iVar4 == 0)) &&
     ((iVar4 = FUN_0054a200(), iVar4 == 0 && (iVar4 = FUN_0054a2d0(), iVar4 == 0)))) {
    FUN_0054a050();
  }
  *(undefined1 *)(param_1 + 0x4c) = 1;
  if (((*(int *)(param_1 + 4 + iVar6 * 4) != 0) && ((iVar6 + 1) * 0x10 + param_1 != 0)) &&
     (iVar4 = FUN_00807fb0(param_1), iVar4 == 0)) {
    *(undefined4 *)(param_1 + 0xac + *(int *)(param_1 + 0x108) * 0x10) = 1;
  }
  if ((*(char *)(param_1 + 0x4c) != '\0') &&
     ((iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 1000), iVar4 == 1 || (iVar4 == 2)))) {
    piVar1 = (int *)(param_1 + 0x40 + iVar6 * 4);
    *piVar1 = *piVar1 + 1;
  }
  if (*(int *)(param_1 + 0x40 + iVar6 * 4) < 0x3d) goto LAB_00549145;
  iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 1000);
  if (iVar4 == 1) {
    uVar3 = 7;
LAB_00549138:
    FUN_00549c60(0,0,0xffffffff,uVar3);
  }
  else if (iVar4 == 2) {
    uVar3 = 9;
    goto LAB_00549138;
  }
  *(undefined4 *)(param_1 + 0x40 + iVar6 * 4) = 0;
LAB_00549145:
  *param_4 = *(undefined4 *)(param_1 + 0x70);
  *(undefined1 *)(param_4 + 1) = *(undefined1 *)(param_1 + 0x74);
  *(undefined2 *)(param_1 + 0x72) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}

