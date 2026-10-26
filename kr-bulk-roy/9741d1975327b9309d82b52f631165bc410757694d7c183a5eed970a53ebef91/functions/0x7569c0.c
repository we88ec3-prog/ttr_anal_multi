
void FUN_007569c0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  int local_38;
  int local_30;
  
  if (*(char *)((int)in_ECX + 0xea) != '\0') {
    if (in_ECX[0x18] != 0) {
      FUN_00443da0();
      FUN_00443da0();
    }
    local_30 = in_ECX[4];
    local_38 = in_ECX[2];
    iVar1 = in_ECX[3];
    iVar4 = in_ECX[5];
    switch(param_1) {
    case 0:
      iVar1 = in_ECX[4];
      local_38 = FUN_008fed10();
      iVar3 = iVar1 - in_ECX[0x36];
      if (iVar3 <= local_38) {
        local_38 = iVar3;
      }
      iVar1 = iVar1 - in_ECX[0x38];
      if (local_38 <= iVar1) {
        local_38 = iVar1;
      }
      iVar1 = FUN_008fed10();
      if (iVar4 - in_ECX[0x37] <= iVar1) {
        iVar1 = iVar4 - in_ECX[0x37];
      }
      if (iVar1 <= iVar4 - in_ECX[0x39]) {
        iVar1 = iVar4 - in_ECX[0x39];
      }
      break;
    case 1:
      iVar1 = FUN_008fed10();
      if (iVar4 - in_ECX[0x37] <= iVar1) {
        iVar1 = iVar4 - in_ECX[0x37];
      }
      if (iVar1 <= iVar4 - in_ECX[0x39]) {
        iVar1 = iVar4 - in_ECX[0x39];
      }
      break;
    case 2:
      local_30 = FUN_008fed10();
      if (local_30 <= in_ECX[0x36] + local_38) {
        local_30 = in_ECX[0x36] + local_38;
      }
      if (in_ECX[0x38] + local_38 <= local_30) {
        local_30 = in_ECX[0x38] + local_38;
      }
      iVar1 = FUN_008fed10();
      if (iVar4 - in_ECX[0x37] <= iVar1) {
        iVar1 = iVar4 - in_ECX[0x37];
      }
      if (iVar1 <= iVar4 - in_ECX[0x39]) {
        iVar1 = iVar4 - in_ECX[0x39];
      }
      break;
    case 3:
      iVar3 = in_ECX[4];
      local_38 = FUN_008fed10();
      iVar2 = iVar3 - in_ECX[0x36];
      if (iVar2 <= local_38) {
        local_38 = iVar2;
      }
      iVar3 = iVar3 - in_ECX[0x38];
      if (local_38 <= iVar3) {
        local_38 = iVar3;
      }
      break;
    case 4:
      local_30 = FUN_008fed10();
      if (local_30 <= in_ECX[0x36] + local_38) {
        local_30 = in_ECX[0x36] + local_38;
      }
      if (in_ECX[0x38] + local_38 <= local_30) {
        local_30 = in_ECX[0x38] + local_38;
      }
      break;
    case 5:
      iVar4 = in_ECX[4];
      local_38 = FUN_008fed10();
      iVar3 = iVar4 - in_ECX[0x36];
      if (iVar3 <= local_38) {
        local_38 = iVar3;
      }
      iVar4 = iVar4 - in_ECX[0x38];
      if (local_38 <= iVar4) {
        local_38 = iVar4;
      }
      iVar4 = FUN_008fed10();
      if (iVar4 <= in_ECX[0x37] + iVar1) {
        iVar4 = in_ECX[0x37] + iVar1;
      }
      if (iVar1 + in_ECX[0x39] <= iVar4) {
        iVar4 = iVar1 + in_ECX[0x39];
      }
      break;
    case 6:
      iVar4 = FUN_008fed10();
      if (iVar4 <= iVar1 + in_ECX[0x37]) {
        iVar4 = iVar1 + in_ECX[0x37];
      }
      if (in_ECX[0x39] + iVar1 <= iVar4) {
        iVar4 = in_ECX[0x39] + iVar1;
      }
      break;
    case 7:
      local_30 = FUN_008fed10();
      if (local_30 <= in_ECX[0x36] + local_38) {
        local_30 = in_ECX[0x36] + local_38;
      }
      if (in_ECX[0x38] + local_38 <= local_30) {
        local_30 = in_ECX[0x38] + local_38;
      }
      iVar4 = FUN_008fed10();
      if (iVar4 <= in_ECX[0x37] + iVar1) {
        iVar4 = in_ECX[0x37] + iVar1;
      }
      if (in_ECX[0x39] + iVar1 <= iVar4) {
        iVar4 = in_ECX[0x39] + iVar1;
      }
    }
    (**(code **)(*in_ECX + 0xbc))(local_38,iVar1,local_30,iVar4);
    puVar5 = (undefined4 *)FUN_00891268(0x14);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = FoxUI::FXUIEvent::vftable;
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 300;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

