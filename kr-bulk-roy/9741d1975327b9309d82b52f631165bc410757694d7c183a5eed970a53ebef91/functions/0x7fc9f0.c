
void FUN_007fc9f0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [2];
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    puVar1 = *(undefined4 **)(in_ECX + 0x40);
    FUN_007cc3a0(local_c,&local_14,&local_10);
    uVar2 = puVar1[1];
    puVar3 = *(undefined4 **)(in_ECX + 0x30);
    uVar4 = puVar1[2];
    *puVar3 = *puVar1;
    puVar3[1] = uVar2;
    puVar3[2] = uVar4;
    iVar5 = *(int *)(in_ECX + 0x30);
    *(undefined4 *)(iVar5 + 0xc) = local_14;
    *(undefined4 *)(iVar5 + 0x10) = local_10;
    *(undefined4 *)(iVar5 + 0x14) = local_c[0];
    *(undefined4 *)(*(int *)(in_ECX + 0x30) + 0x18) =
         *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x1c);
    FUN_007d8a50(*(undefined4 *)(in_ECX + 0x30));
  }
  return;
}

