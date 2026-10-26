
void FUN_00474c60(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *in_EAX;
  uint uVar3;
  undefined4 *puVar4;
  int *in_EDX;
  uint uVar5;
  int iVar6;
  int local_8;
  
  uVar3 = 0;
  uVar5 = in_EDX[5] - in_EDX[4] >> 2;
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  if (3 < (int)uVar5) {
    iVar1 = *in_EDX;
    iVar6 = (uVar5 - 4 >> 2) + 1;
    puVar4 = (undefined4 *)(iVar1 + 8);
    uVar3 = iVar6 * 4;
    local_8 = 8;
    do {
      if (*(int *)puVar4[-2] == param_1) {
        iVar2 = *(int *)((int)puVar4 + (-8 - iVar1) + in_EDX[4]);
        *in_EAX = *(undefined4 *)(iVar2 + 4);
        in_EAX[1] = *(undefined4 *)(iVar2 + 8);
        in_EAX[2] = *(undefined4 *)(iVar2 + 0xc);
      }
      if (*(int *)puVar4[-1] == param_1) {
        iVar2 = *(int *)((int)puVar4 + (-8 - iVar1) + in_EDX[4] + 4);
        *in_EAX = *(undefined4 *)(iVar2 + 4);
        in_EAX[1] = *(undefined4 *)(iVar2 + 8);
        in_EAX[2] = *(undefined4 *)(iVar2 + 0xc);
      }
      if (*(int *)*puVar4 == param_1) {
        iVar2 = *(int *)(local_8 + in_EDX[4]);
        *in_EAX = *(undefined4 *)(iVar2 + 4);
        in_EAX[1] = *(undefined4 *)(iVar2 + 8);
        in_EAX[2] = *(undefined4 *)(iVar2 + 0xc);
      }
      if (*(int *)puVar4[1] == param_1) {
        iVar2 = *(int *)((int)puVar4 + (4 - iVar1) + in_EDX[4]);
        *in_EAX = *(undefined4 *)(iVar2 + 4);
        in_EAX[1] = *(undefined4 *)(iVar2 + 8);
        in_EAX[2] = *(undefined4 *)(iVar2 + 0xc);
      }
      local_8 = local_8 + 0x10;
      puVar4 = puVar4 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  for (; uVar3 < uVar5; uVar3 = uVar3 + 1) {
    if (**(int **)(*in_EDX + uVar3 * 4) == param_1) {
      iVar1 = *(int *)(in_EDX[4] + uVar3 * 4);
      *in_EAX = *(undefined4 *)(iVar1 + 4);
      in_EAX[1] = *(undefined4 *)(iVar1 + 8);
      in_EAX[2] = *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return;
}

