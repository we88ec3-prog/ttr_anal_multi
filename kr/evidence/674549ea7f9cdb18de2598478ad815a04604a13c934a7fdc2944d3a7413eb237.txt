
void FUN_004c8a90(short param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *unaff_ESI;
  undefined4 uVar3;
  float local_c;
  float local_8;
  
  uVar3 = 0;
  if (((float)unaff_ESI[0x36] != 0.0) || ((float)unaff_ESI[0x37] != 0.0)) {
    local_c = (float)unaff_ESI[0x28] + (float)unaff_ESI[0x36];
    local_8 = (float)unaff_ESI[0x37] + (float)unaff_ESI[0x29];
    unaff_ESI[0x36] = 0;
    pcVar1 = *(code **)(*unaff_ESI + 0x44);
    unaff_ESI[0x37] = 0;
    (*pcVar1)(&local_c,1);
  }
  local_8 = (float)CONCAT31(local_8._1_3_,(char)unaff_ESI[0x2c]);
  if (((unaff_ESI[0xea] == 0) &&
      (*(char *)(unaff_ESI + 0xe9) = (char)unaff_ESI[0x2c], unaff_ESI[0xdc] != 0)) &&
     (unaff_ESI[0x57] != 0)) {
    iVar2 = *(int *)(unaff_ESI[0x57] + 4);
    FUN_00444a90(local_8);
    (**(code **)(iVar2 + 0xc))(uVar3);
  }
  (**(code **)(unaff_ESI[0x3c] + 8))(0xd);
  (**(code **)(*unaff_ESI + 0x68))((int)param_1,param_2);
  return;
}

