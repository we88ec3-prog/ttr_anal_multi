
void FUN_00644ff0(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  int *unaff_ESI;
  
  cVar2 = (char)param_1;
  *(bool *)((int)unaff_ESI + 0xea) = cVar2 == '\0';
  (**(code **)(*unaff_ESI + 0x16c))(cVar2 == '\0');
  if (cVar2 == '\0') {
    if ((unaff_ESI[10] & 4U) != 0) {
      unaff_ESI[10] = unaff_ESI[10] ^ 4;
    }
  }
  else {
    unaff_ESI[10] = unaff_ESI[10] | 4;
  }
  iVar1 = unaff_ESI[0x20];
  if (cVar2 == '\0') {
    if ((*(uint *)(iVar1 + 0x28) & 4) != 0) {
      *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) ^ 4;
    }
  }
  else {
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) | 4;
  }
  (**(code **)(*(int *)unaff_ESI[0x54] + 0xa0))(param_1);
  return;
}

