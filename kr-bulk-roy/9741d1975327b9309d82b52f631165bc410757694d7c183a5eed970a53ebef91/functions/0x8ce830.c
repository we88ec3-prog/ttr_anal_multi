
void FUN_008ce830(void)

{
  int *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  undefined4 uVar4;
  
  puVar3 = *(undefined4 **)(in_EAX[5] + 4);
  iVar2 = *in_EAX;
  if (iVar2 != 0) {
    puVar1 = (undefined4 *)(in_EAX[2] + 0x1c);
    do {
      puVar1[-3] = 0;
      puVar1[-1] = 0;
      if (unaff_EBX == 0) {
        *puVar1 = *puVar3;
        uVar4 = puVar3[1];
      }
      else {
        *puVar1 = puVar3[1];
        uVar4 = *puVar3;
      }
      puVar1[1] = uVar4;
      iVar2 = iVar2 + -1;
      puVar1 = puVar1 + 10;
      puVar3 = puVar3 + 2;
    } while (iVar2 != 0);
  }
  return;
}

