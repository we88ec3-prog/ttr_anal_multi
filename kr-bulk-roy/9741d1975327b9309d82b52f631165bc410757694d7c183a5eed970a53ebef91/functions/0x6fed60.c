
void FUN_006fed60(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EDI;
  
  if (0xffffffe5 < param_1) {
    FUN_006f8b60();
  }
  iVar1 = *(int *)(unaff_EDI + 0x10);
  iVar3 = param_1 + 0x18;
  puVar2 = (undefined4 *)(**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,iVar3);
  if ((puVar2 == (undefined4 *)0x0) && (iVar3 != 0)) {
    puVar2 = (undefined4 *)FUN_006fdb40();
  }
  *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + iVar3;
  *(byte *)((int)puVar2 + 5) = *(byte *)(*(int *)(unaff_EDI + 0x10) + 0x14) & 3;
  *(undefined1 *)(puVar2 + 1) = 7;
  puVar2[4] = param_1;
  puVar2[2] = 0;
  puVar2[3] = param_2;
  *puVar2 = **(undefined4 **)(*(int *)(unaff_EDI + 0x10) + 0x70);
  **(undefined4 **)(*(int *)(unaff_EDI + 0x10) + 0x70) = puVar2;
  return;
}

