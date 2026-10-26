
undefined4 FUN_008ed050(void)

{
  byte bVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  
  *(int *)(in_EAX + 0x168) = *(int *)(in_EAX + 0x168) + *(int *)(in_EAX + 0x174);
  iVar2 = *(int *)(in_EAX + 0x16c);
  if (*(int *)(in_EAX + 0x168) < iVar2) {
    bVar1 = *(byte *)(*(int *)(in_EAX + 0x164) + *(int *)(in_EAX + 0x168));
    *(byte *)(in_EAX + 0x170) = bVar1;
    iVar3 = (int)*(char *)((int)&PTR_Rsrc_Icon_1_412_ImageData_159325__00beae88 + (uint)bVar1);
    *(int *)(in_EAX + 0x174) = iVar3;
    if (iVar3 < 0) {
      if (iVar2 <= *(int *)(in_EAX + 0x168) + 1) goto LAB_008ed0ca;
      *(uint *)(in_EAX + 0x174) =
           2 - (uint)*(byte *)(*(int *)(in_EAX + 0x164) + 1 + *(int *)(in_EAX + 0x168)) * iVar3;
    }
    if (*(int *)(in_EAX + 0x168) + *(int *)(in_EAX + 0x174) <= iVar2) {
      return 0;
    }
  }
LAB_008ed0ca:
  *(undefined4 *)(in_EAX + 0xc) = 0x83;
  return 1;
}

