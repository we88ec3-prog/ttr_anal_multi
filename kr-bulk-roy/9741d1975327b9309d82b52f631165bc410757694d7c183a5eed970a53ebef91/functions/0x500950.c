
void FUN_00500950(int param_1,int param_2,undefined4 *param_3)

{
  void *_Dst;
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  int local_c;
  uint local_8;
  
  _Dst = (void *)*param_3;
  if (_Dst != (void *)param_3[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_3[1],0);
    param_3[1] = _Dst;
  }
  puVar1 = *(ushort **)(param_1 + 0x5ec4);
  for (puVar3 = *(ushort **)(param_1 + 0x5ec0); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    local_8 = (uint)*puVar3;
    iVar2 = *(int *)(param_1 + 0x5eac);
    FUN_00503d20(&local_8);
    if (local_c == *(int *)(iVar2 + 4)) {
      local_8 = 0;
    }
    else {
      local_8 = local_c + 0x10;
    }
    if (((local_8 != 0) && (*(int *)(local_8 + 0x28) == param_2)) && (*(int *)(local_8 + 4) == 1)) {
      FUN_00443d10();
    }
  }
  return;
}

