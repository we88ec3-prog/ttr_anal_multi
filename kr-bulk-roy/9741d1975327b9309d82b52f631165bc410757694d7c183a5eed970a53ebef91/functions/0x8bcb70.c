
int FUN_008bcb70(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  size_t _Size;
  
  sVar1 = *(short *)(param_2 + 0x14);
  sVar2 = *(short *)(param_2 + 0x16);
  _Size = (size_t)sVar2;
  iVar3 = FUN_008bc9a0(param_1,_Size,(int)sVar1);
  if (iVar3 == 0) {
    FID_conflict__memcpy(*(void **)(param_1 + 0x18),*(void **)(param_2 + 0x18),_Size * 8);
    FID_conflict__memcpy(*(void **)(param_1 + 0x1c),*(void **)(param_2 + 0x1c),_Size);
    FID_conflict__memcpy(*(void **)(param_1 + 0x20),*(void **)(param_2 + 0x20),sVar1 * 2);
    if ((*(char *)(param_1 + 0x10) != '\0') && (*(char *)(param_2 + 0x10) != '\0')) {
      FID_conflict__memcpy(*(void **)(param_1 + 0x28),*(void **)(param_2 + 0x28),_Size * 8);
      FID_conflict__memcpy(*(void **)(param_1 + 0x2c),*(void **)(param_2 + 0x2c),_Size * 8);
    }
    *(short *)(param_1 + 0x14) = sVar1;
    *(short *)(param_1 + 0x16) = sVar2;
    FUN_008b82f0();
  }
  return iVar3;
}

