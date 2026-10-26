
void FUN_008e68a0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *_Dst;
  int *piVar3;
  size_t _Size;
  int local_4c;
  undefined4 *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_40 = param_2;
  local_3c = 0;
  (**(code **)(param_2 + 0x3c))(param_2,local_38,4,&local_44);
  if (local_44 < 0) {
    iVar2 = 0xa2;
  }
  else {
    if ((local_44 == 0) || (4 < local_44)) {
LAB_008e69a9:
      *(undefined4 *)(param_2 + 0xc) = 3;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar2 = FUN_008e5ee0(param_1,local_44);
    local_3c = iVar2;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 100);
      local_4c = 0;
      if (0 < local_44) {
        local_48 = (undefined4 *)(*(int *)(param_1 + 0x210) + 8);
        piVar3 = local_38;
        local_3c = 0;
        while( true ) {
          if (*(char *)*piVar3 == '/') {
            *piVar3 = (int)((char *)*piVar3 + 1);
          }
          _Size = piVar3[1] - *piVar3;
          if (_Size == 0) break;
          _Dst = (void *)FUN_008baee0(uVar1,_Size + 1,&local_3c);
          *local_48 = _Dst;
          if (local_3c != 0) {
            *(int *)(local_40 + 0xc) = local_3c;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          FID_conflict__memcpy(_Dst,(void *)*piVar3,_Size);
          local_48 = local_48 + 1;
          local_4c = local_4c + 1;
          *(undefined1 *)((int)_Dst + _Size) = 0;
          piVar3 = piVar3 + 3;
          param_2 = local_40;
          if (local_44 <= local_4c) {
            *(int *)(local_40 + 0xc) = local_3c;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
        }
        goto LAB_008e69a9;
      }
    }
  }
  *(int *)(param_2 + 0xc) = iVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

