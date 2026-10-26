
void FUN_00735760(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  undefined4 *in_EDX;
  uint uVar4;
  undefined1 local_34 [4];
  int local_30;
  int *local_2c;
  undefined1 local_28 [24];
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(*(int *)in_EDX[2] + 0x14))();
  *in_EDX = in_ECX;
  (**(code **)(*in_ECX + 0xc))();
  puVar1 = in_EDX + 1;
  iVar2 = D3DXCreateTexture(local_2c,0x800,0x400,0xffffffff,0,0x15,1,puVar1);
  if (iVar2 < 0) {
    in_EDX[0x15] = 0;
    FUN_006edb60(&DAT_00c45560);
  }
  (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,0,local_28);
  iVar2 = (**(code **)(*(int *)*puVar1 + 0x4c))((int *)*puVar1,0,local_34,0,0);
  if (-1 < iVar2) {
    uVar4 = 0;
    if (local_c != 0) {
      do {
        uVar3 = 0;
        if (local_10 != 0) {
          do {
            *(undefined4 *)(local_30 + (local_10 * uVar4 + uVar3) * 4) = 0;
            uVar3 = uVar3 + 1;
          } while (uVar3 < local_10);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_c);
    }
    (**(code **)(*(int *)*puVar1 + 0x50))((int *)*puVar1,0);
  }
  (**(code **)(*local_2c + 8))(local_2c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

