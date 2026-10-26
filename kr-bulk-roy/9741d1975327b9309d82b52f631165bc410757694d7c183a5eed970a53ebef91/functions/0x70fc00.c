
void FUN_0070fc00(int param_1,int *param_2,uint param_3)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_28 [28];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = *(int *)(param_1 + 0x34);
  psVar1 = (short *)(iVar2 + 0x34);
  *psVar1 = *psVar1 + 1;
  if (200 < *(ushort *)(iVar2 + 0x34)) {
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,"chunk has too many syntax levels",0);
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (((iVar2 == 0x23) || (iVar2 == 0x2d)) || (iVar2 == 0x10e)) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar3 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
    FUN_0070fc00(param_1,param_2,8);
    FUN_00713060(param_2);
  }
  else {
    FUN_0070f860(param_1);
  }
  iVar2 = FUN_0070fa50();
  do {
    if ((iVar2 == 0xf) || ((byte)(&DAT_00c0b858)[iVar2 * 2] <= param_3)) {
      psVar1 = (short *)(*(int *)(param_1 + 0x34) + 0x34);
      *psVar1 = *psVar1 + -1;
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar3 = FUN_006ffec0(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
    switch(iVar2) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if (((*param_2 != 5) || (param_2[4] != -1)) || (param_2[5] != -1))
      goto switchD_0070fd39_caseD_7;
      break;
    case 6:
      FUN_00712630();
      break;
    default:
switchD_0070fd39_caseD_7:
      FUN_00712740();
      break;
    case 0xd:
      FUN_00712bb0(param_2);
      break;
    case 0xe:
      FUN_00712c50(param_2);
    }
    iVar2 = FUN_0070fc00(param_1,local_28,(&DAT_00c0b859)[iVar2 * 2]);
    FUN_007130f0(param_2,local_28);
  } while( true );
}

