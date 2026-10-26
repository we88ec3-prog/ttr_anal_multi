
void FUN_008ed780(ushort *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if ((*(ushort *)(unaff_ESI + 0x2c) <= *param_1) || (*(ushort *)(unaff_ESI + 0x50) <= param_1[2]))
  {
    if (*(char *)(unaff_ESI + 0x231) != '\0') {
      *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
    }
    param_1[0] = 0;
    param_1[1] = 0;
    return;
  }
  if ((*(byte *)(unaff_ESI + 0x170) & 1) != 0) {
    uVar3 = (**(code **)(unaff_ESI + 0x23c))();
    *(undefined4 *)param_1 = uVar3;
    return;
  }
  if ((*(short *)(unaff_ESI + 0x158) != 0) && (*(short *)(unaff_ESI + 0x15a) != 0)) {
    piVar1 = (int *)(*(int *)(unaff_ESI + 0x38) + (uint)*param_1 * 8);
    piVar2 = (int *)(*(int *)(unaff_ESI + 0x5c) + (uint)param_1[2] * 8);
    if (*(int *)(unaff_ESI + 0xdc) == *(int *)(unaff_ESI + 0xe0)) {
      uVar3 = (**(code **)(unaff_ESI + 0x240))();
      uVar3 = FUN_008b7f10(uVar3,*(undefined4 *)(unaff_ESI + 0xdc));
      *(undefined4 *)param_1 = uVar3;
      return;
    }
    FUN_008b7f10(*piVar1 - *piVar2,*(int *)(unaff_ESI + 0xdc));
    FUN_008b7f10(piVar1[1] - piVar2[1],*(undefined4 *)(unaff_ESI + 0xe0));
    uVar3 = (**(code **)(unaff_ESI + 0x240))();
    *(undefined4 *)param_1 = uVar3;
    return;
  }
  uVar3 = (**(code **)(unaff_ESI + 0x240))();
  *(undefined4 *)param_1 = uVar3;
  return;
}

