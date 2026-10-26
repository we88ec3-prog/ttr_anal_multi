
void FUN_008c2cc0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_1c;
  int local_18;
  ushort local_14;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  local_c = FUN_008b9850(param_2);
  local_18 = FUN_008b9c00(param_2,&local_1c);
  if (((local_1c == 0) && (local_1c = FUN_008bacd0(param_2,&DAT_00bd7db8,&local_18), local_1c == 0))
     && ((local_18 == 0x4f54544f || (local_1c = FUN_008c2b40(), local_1c == 0)))) {
    *(ushort *)(param_1 + 0x98) = local_14;
    *(int *)(param_1 + 0x94) = local_18;
    uVar1 = FUN_008bc7d0(uVar1,0x10,0,local_14,0,&local_1c);
    *(undefined4 *)(param_1 + 0x9c) = uVar1;
    if (((local_1c == 0) && (local_1c = FUN_008b97e0(param_2,local_c + 0xc), local_1c == 0)) &&
       (local_1c = FUN_008babe0(param_2,(uint)*(ushort *)(param_1 + 0x98) << 4), local_1c == 0)) {
      puVar4 = *(undefined4 **)(param_1 + 0x9c);
      iVar3 = 0;
      if (local_14 != 0) {
        do {
          uVar1 = FUN_008b99c0(param_2);
          *puVar4 = uVar1;
          uVar1 = FUN_008b99c0(param_2);
          puVar4[1] = uVar1;
          uVar1 = FUN_008b99c0(param_2);
          puVar4[2] = uVar1;
          iVar2 = FUN_008b99c0(param_2);
          puVar4[3] = iVar2;
          if ((uint)(puVar4[2] + iVar2) <= *(uint *)(param_2 + 4)) {
            puVar4 = puVar4 + 4;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)local_14);
      }
      FUN_008baca0(param_2);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

