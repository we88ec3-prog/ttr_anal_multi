
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0071a3e0(undefined4 *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*(code *)PTR_FUN_00d63d48)(in_EAX + 0x38);
  if (iVar1 == 0) {
    return (undefined4 *)0x0;
  }
  puVar2 = (undefined4 *)(iVar1 + 0x1fU & 0xffffffe0);
  if (puVar2 == (undefined4 *)0x0) {
    iRam00000004 = iVar1;
    _DAT_00000000 = *(undefined4 *)*param_1;
    return (undefined4 *)0x0;
  }
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[1] = iVar1;
  *puVar2 = *(undefined4 *)*param_1;
  return puVar2;
}

