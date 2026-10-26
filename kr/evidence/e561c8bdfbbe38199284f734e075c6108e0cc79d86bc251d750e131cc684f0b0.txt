
void FUN_004ce7f0(short param_1,short param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009405e8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  switch((int)param_1) {
  case 1:
    in_ECX[0xec] = (int)param_2;
    if (in_ECX[0xda] != 0) {
      iVar5 = FUN_007b4ed0(in_ECX[0xda]);
      *(float *)(iVar5 + 0xc) = (float)(int)param_2 * 0.0001;
    }
    break;
  case 2:
    in_ECX[0xed] = (int)param_2;
    if (in_ECX[0xda] != 0) {
      iVar5 = FUN_007b4ed0(in_ECX[0xda]);
      *(float *)(iVar5 + 0xc) = (float)(int)param_2 / 100.0;
    }
    break;
  case 3:
    in_ECX[0xee] = (int)param_2;
    if (in_ECX[0xda] != 0) {
      iVar5 = FUN_007b4ed0(in_ECX[0xda]);
      *(float *)(iVar5 + 0xc) = (float)(int)param_2 / 100.0;
    }
    break;
  case 4:
    in_ECX[0xfa] = (int)param_2;
    if (in_ECX[0xd9] != 0) {
      if (*(int *)(in_ECX[0xd9] + 0x24) != 0) {
        FUN_007be5f0();
      }
      if (in_ECX[0xd9] != 0) {
        FUN_004c7db0();
        in_ECX[0xd9] = 0;
      }
    }
    if (in_ECX[0xfa] == 1) {
      uVar7 = 0x3f800000;
      uVar3 = 0;
      (**(code **)(*in_ECX + 0x4c))(0,0x3f800000);
      uVar6 = (uint)*(ushort *)(in_ECX + 1);
      FUN_0049b140(uVar6);
      iVar5 = FUN_00551f90(uVar6,uVar3,uVar7);
      in_ECX[0xd9] = iVar5;
    }
    break;
  case 5:
    in_ECX[0x34] = (int)param_2;
    break;
  case 6:
    in_ECX[0x33] = (int)(float)(int)param_2;
    break;
  default:
    FUN_006edb60(&DAT_00c07afc,(int)param_1,(int)param_2);
    break;
  case 0x17:
    if ((int)param_2 != in_ECX[0xf5]) {
      piVar4 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
      if (in_ECX == piVar4) {
        if (in_ECX[0xf5] == 0) goto LAB_004cea98;
        FUN_0040b3c0();
        local_8 = 0;
        uVar3 = FUN_0040b3f0();
        piVar4 = (int *)FUN_0080ab00(uVar3);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x14))();
        }
        local_8 = 0xffffffff;
        FUN_007cf450();
      }
      if (in_ECX[0xf5] != 0) {
        uVar8 = 0x3f800000;
        uVar7 = 0;
        uVar3 = (**(code **)(*in_ECX + 0x4c))(0,0x3f800000);
        uVar6 = (uint)*(ushort *)(in_ECX + 1);
        FUN_0049b140(uVar6,uVar3);
        FUN_00551f20(uVar6,uVar3,uVar7,uVar8);
      }
    }
LAB_004cea98:
    in_ECX[0xf5] = (int)param_2;
    break;
  case 0x19:
    iVar5 = FUN_00489fe0();
    *(undefined4 *)(iVar5 + 0x24) = 0x3f800000;
    *(undefined4 *)(iVar5 + 0x2c) = 0x3c;
    *(undefined4 *)(iVar5 + 0x28) = 0x437f0000;
    *(int *)(iVar5 + 0x34) = (int)param_2;
    break;
  case 0x1d:
    in_ECX[0x24] = (int)param_2;
    break;
  case 0x1e:
    piVar4 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))(uVar2);
    if (in_ECX == piVar4) {
      uVar1 = *(ushort *)(in_ECX + 0x22);
      iVar5 = FUN_00404ba0();
      if (uVar1 < 10) {
        uVar6 = *(int *)(iVar5 + 0x6924) + (uint)uVar1 * 0x210;
        *(int *)((-(uint)(*(int *)(uVar6 + 0x5c) != 0) & uVar6) + 0xdc) = (int)param_2;
      }
      else {
        iRam000000dc = (int)param_2;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

