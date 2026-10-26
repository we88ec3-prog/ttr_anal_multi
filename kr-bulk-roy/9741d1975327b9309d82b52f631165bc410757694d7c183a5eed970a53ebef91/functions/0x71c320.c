
bool FUN_0071c320(uint param_1,uint param_2)

{
  uint in_EAX;
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint unaff_EDI;
  uint local_1c;
  uint local_18 [3];
  uint local_c;
  uint local_8;
  
  if (in_EAX < unaff_EDI) {
    iVar2 = unaff_EDI - in_EAX;
    do {
      if (param_1 == 0) {
        local_c = 0;
        puVar1 = &local_c;
      }
      else {
        local_8 = *(uint *)(param_1 + 4);
        puVar1 = &local_8;
      }
      iVar2 = iVar2 + -1;
      param_1 = *puVar1;
    } while (iVar2 != 0);
  }
  if (unaff_EDI < in_EAX) {
    iVar2 = in_EAX - unaff_EDI;
    do {
      if (param_2 == 0) {
        local_8 = 0;
        puVar1 = &local_8;
      }
      else {
        local_c = *(uint *)(param_2 + 4);
        puVar1 = &local_c;
      }
      iVar2 = iVar2 + -1;
      param_2 = *puVar1;
    } while (iVar2 != 0);
  }
  if (param_1 == param_2) {
    return unaff_EDI < in_EAX;
  }
  while( true ) {
    if (param_2 == 0) {
      local_8 = 0;
      puVar1 = &local_8;
    }
    else {
      local_c = *(uint *)(param_2 + 4);
      puVar1 = &local_c;
    }
    if (param_1 == 0) {
      local_18[1] = 0;
      puVar3 = local_18 + 1;
    }
    else {
      local_18[2] = *(undefined4 *)(param_1 + 4);
      puVar3 = local_18 + 2;
    }
    if (*puVar3 == *puVar1) break;
    if (param_1 == 0) {
      local_1c = 0;
      puVar1 = &local_1c;
    }
    else {
      local_18[0] = *(uint *)(param_1 + 4);
      puVar1 = local_18;
    }
    param_1 = *puVar1;
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = *(uint *)(param_2 + 4);
    }
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) {
    do {
      if (param_1 == param_2) {
        return true;
      }
      if (param_1 == 0) {
        param_1 = 0;
      }
      else {
        param_1 = *(uint *)(param_1 + 0x18);
      }
    } while (param_1 != 0);
    return false;
  }
  return param_1 < param_2;
}

