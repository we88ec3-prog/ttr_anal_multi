
void FUN_006596c0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *piVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x44] + 0x20)) {
      uVar1 = *(uint *)(in_ECX[0x44] + 0x28);
      bVar5 = (uVar1 >> 9 & 1) == 0;
      *(bool *)((int)in_ECX + 0xea) = bVar5;
      (**(code **)(*in_ECX + 0x16c))(CONCAT31((uint3)(uVar1 >> 0x11),bVar5));
      return;
    }
    iVar2 = 0;
    piVar4 = in_ECX + 0x4e;
    while (*(int *)(param_1 + 8) != *(int *)(*piVar4 + 0x20)) {
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      if (3 < iVar2) {
        return;
      }
    }
    if (((iVar2 - 1U < 3) && (in_ECX[iVar2 + 0x46] != 0)) &&
       ((*(uint *)(in_ECX[iVar2 + 0x46] + 0x28) >> 8 & 1) != 0)) {
      uVar7 = *(undefined4 *)(iVar2 * 4 + 0xf861fc);
      uVar6 = 0;
      uVar3 = FUN_0040f8c0(0,uVar7);
      FUN_004d5ae0(uVar3,uVar6,uVar7);
    }
  }
  return;
}

