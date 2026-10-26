
void FUN_00558d40(int param_1)

{
  HANDLE in_ECX;
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  int local_c;
  
  GetObjectW(in_ECX,0x18,local_24);
  local_c = 0;
  if (0 < local_1c) {
    do {
      iVar2 = 0;
      pbVar1 = (byte *)(param_1 + local_20 * local_c * 4);
      if (0 < local_20) {
        do {
          uVar3 = (uint)pbVar1[3];
          *pbVar1 = (byte)((*pbVar1 * uVar3) / 0xff);
          pbVar1[1] = (byte)((pbVar1[1] * uVar3) / 0xff);
          pbVar1[2] = (byte)((pbVar1[2] * uVar3) / 0xff);
          iVar2 = iVar2 + 1;
          pbVar1 = pbVar1 + 4;
        } while (iVar2 < local_20);
      }
      local_c = local_c + 1;
    } while (local_c < local_1c);
  }
  return;
}

