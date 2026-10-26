
void FUN_0072c4e0(int param_1,ushort *param_2)

{
  short *psVar1;
  ushort uVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int local_c;
  uint local_8;
  
  uVar2 = *(ushort *)(in_EAX + 2);
  iVar4 = 0;
  local_8 = 0xffffffff;
  iVar3 = 7;
  iVar7 = 4;
  if (uVar2 == 0) {
    iVar3 = 0x8a;
    iVar7 = 3;
  }
  *(undefined2 *)(in_EAX + 6 + (int)param_2 * 4) = 0xffff;
  if (-1 < (int)param_2) {
    local_c = (int)param_2 + 1;
    uVar5 = (uint)uVar2;
    param_2 = (ushort *)(in_EAX + 6);
    do {
      uVar6 = (uint)*param_2;
      iVar4 = iVar4 + 1;
      if ((iVar3 <= iVar4) || (uVar5 != uVar6)) {
        if (iVar4 < iVar7) {
          psVar1 = (short *)(param_1 + 0xa7c + uVar5 * 4);
          *psVar1 = *psVar1 + (short)iVar4;
        }
        else if (uVar5 == 0) {
          if (iVar4 < 0xb) {
            *(short *)(param_1 + 0xac0) = *(short *)(param_1 + 0xac0) + 1;
          }
          else {
            *(short *)(param_1 + 0xac4) = *(short *)(param_1 + 0xac4) + 1;
          }
        }
        else {
          if (uVar5 != local_8) {
            psVar1 = (short *)(param_1 + 0xa7c + uVar5 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(param_1 + 0xabc) = *(short *)(param_1 + 0xabc) + 1;
        }
        iVar4 = 0;
        local_8 = uVar5;
        if (uVar6 == 0) {
          iVar3 = 0x8a;
          iVar7 = 3;
        }
        else if (uVar5 == uVar6) {
          iVar3 = 6;
          iVar7 = 3;
        }
        else {
          iVar3 = 7;
          iVar7 = 4;
        }
      }
      param_2 = param_2 + 2;
      local_c = local_c + -1;
      uVar5 = uVar6;
    } while (local_c != 0);
  }
  return;
}

