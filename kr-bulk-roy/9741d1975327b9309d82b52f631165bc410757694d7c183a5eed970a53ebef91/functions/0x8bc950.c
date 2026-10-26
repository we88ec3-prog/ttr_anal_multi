
undefined4 * FUN_008bc950(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = param_1;
  iVar3 = FUN_008bc7d0(*param_1,8,0,param_1[1] * 2,0,&param_1);
  puVar2 = param_1;
  puVar1[10] = iVar3;
  if (param_1 == (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 4) = 1;
    puVar1[0xb] = iVar3 + puVar1[1] * 8;
    FUN_008b82f0();
  }
  return puVar2;
}

