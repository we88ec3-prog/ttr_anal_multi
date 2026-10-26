
void FUN_007a35f0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_EAX;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)FUN_00820120();
  *puVar3 = *(undefined4 *)(in_ECX + 4);
  puVar3[1] = *(undefined4 *)(in_ECX + 4);
  puVar3[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar3 + 6) = 0;
  if (puVar3 + 3 != (undefined4 *)0x0) {
    puVar3[3] = *in_EAX;
    puVar4 = puVar3 + 4;
    puVar1 = in_EAX + 1;
    *puVar4 = 0;
    puVar3[5] = 0;
    if (puVar4 != puVar1) {
      uVar2 = puVar3[5];
      puVar3[5] = in_EAX[2];
      in_EAX[2] = uVar2;
      uVar2 = *puVar4;
      *puVar4 = *puVar1;
      *puVar1 = uVar2;
    }
  }
  return;
}

