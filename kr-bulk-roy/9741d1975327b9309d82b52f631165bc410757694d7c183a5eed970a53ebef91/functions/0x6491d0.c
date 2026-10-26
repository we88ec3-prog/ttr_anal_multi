
void FUN_006491d0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0xa8);
  puVar2 = (undefined4 *)FUN_00649120(param_1);
  FUN_0064ba50(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10)
               ,*(undefined4 *)(iVar1 + 0x14),*puVar2,puVar2[1],puVar2[2],puVar2[3]);
  FUN_0064ab00(*(undefined4 *)(param_1 + 0xa8),param_2);
  *(undefined4 *)(param_1 + 0xd8) = param_2;
  return;
}

