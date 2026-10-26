
int FUN_008c6600(void)

{
  undefined1 *in_EAX;
  int iVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  puVar2 = in_EAX + 1;
  puVar3 = in_EAX + 2;
  puVar6 = in_EAX + 3;
  uVar4 = CONCAT31(CONCAT21(CONCAT11(*in_EAX,*puVar2),*puVar3),*puVar6);
  iVar1 = FUN_008c5c80();
  if (iVar1 == 0) {
    iVar1 = *(int *)(in_ECX + 0x20);
    uVar5 = 0;
    if (uVar4 != 0) {
      do {
        *(uint *)(iVar1 + uVar5 * 4) = (uint)CONCAT21(CONCAT11(puVar2[3],puVar3[3]),puVar6[3]);
        uVar5 = uVar5 + 1;
        puVar2 = puVar2 + 5;
        puVar3 = puVar3 + 5;
        puVar6 = puVar6 + 5;
      } while (uVar5 < uVar4);
    }
    *(undefined4 *)(iVar1 + uVar5 * 4) = 0;
    return iVar1;
  }
  return 0;
}

