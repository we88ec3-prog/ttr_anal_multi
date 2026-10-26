
void FUN_006f55b0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  
  if (*(uint *)(*(int *)(unaff_ESI + 0x10) + 0x40) <= *(uint *)(*(int *)(unaff_ESI + 0x10) + 0x44))
  {
    FUN_006fb3a0();
  }
  if (*(int *)(unaff_ESI + 0x14) == *(int *)(unaff_ESI + 0x28)) {
    uVar3 = *(undefined4 *)(unaff_ESI + 0x48);
  }
  else {
    uVar3 = *(undefined4 *)(**(int **)(*(int *)(unaff_ESI + 0x14) + 4) + 0xc);
  }
  puVar1 = (undefined4 *)FUN_00700880();
  iVar2 = *(int *)(unaff_ESI + 0x10);
  *puVar1 = *(undefined4 *)(iVar2 + 0x1c);
  *(undefined4 **)(iVar2 + 0x1c) = puVar1;
  *(byte *)((int)puVar1 + 5) = *(byte *)(iVar2 + 0x14) & 3;
  *(undefined1 *)(puVar1 + 1) = 6;
  *(undefined1 *)((int)puVar1 + 6) = 1;
  puVar1[3] = uVar3;
  *(char *)((int)puVar1 + 7) = (char)param_2;
  puVar1[4] = param_1;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + param_2 * -0x10;
  if (param_2 != 0) {
    puVar4 = puVar1 + param_2 * 4 + 6;
    do {
      puVar5 = puVar4 + -4;
      iVar2 = *(int *)(unaff_ESI + 8) + (-0x18 - (int)puVar1);
      param_2 = param_2 + -1;
      *puVar5 = *(undefined4 *)(iVar2 + (int)puVar5);
      puVar4[-3] = *(undefined4 *)(iVar2 + 4 + (int)puVar5);
      puVar4[-2] = *(undefined4 *)(iVar2 + 8 + (int)puVar5);
      puVar4 = puVar5;
    } while (param_2 != 0);
  }
  puVar4 = *(undefined4 **)(unaff_ESI + 8);
  *puVar4 = puVar1;
  puVar4[2] = 6;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}

