
void FUN_007d37b0(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  bool bVar7;
  
  FUN_007d3130();
  FUN_007d39b0(in_EAX);
  uVar6 = 0;
  *(undefined4 *)(in_EAX + 0x14) = 0;
  iVar1 = FUN_007c6430(*(undefined4 *)(in_EAX + 0x10),"Actor",0,0);
  if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 0xdc) - *(int *)(iVar1 + 0xd8) >> 2, 0 < iVar2)) {
    bVar7 = iVar2 != 0;
    do {
      if (bVar7) {
        piVar5 = *(int **)(*(int *)(iVar1 + 0xd8) + uVar6 * 4);
      }
      else {
        piVar5 = (int *)0x0;
      }
      iVar2 = (**(code **)(*piVar5 + 4))();
      if (*(int *)(iVar2 + 4) == -0x5edf0000) {
        if (uVar6 < (uint)(*(int *)(iVar1 + 0xdc) - *(int *)(iVar1 + 0xd8) >> 2)) {
          iVar2 = *(int *)(*(int *)(iVar1 + 0xd8) + uVar6 * 4);
        }
        else {
          iVar2 = 0;
        }
        *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(iVar2 + 0x74);
      }
      uVar6 = uVar6 + 1;
      uVar3 = *(int *)(iVar1 + 0xdc) - *(int *)(iVar1 + 0xd8) >> 2;
      bVar7 = uVar6 < uVar3;
    } while ((int)uVar6 < (int)uVar3);
  }
  uVar4 = FUN_007c6430(*(undefined4 *)(in_EAX + 0x10),&DAT_00c4fde8,0,0);
  *(undefined4 *)(in_EAX + 0x18) = uVar4;
  FUN_007d3760();
  return;
}

