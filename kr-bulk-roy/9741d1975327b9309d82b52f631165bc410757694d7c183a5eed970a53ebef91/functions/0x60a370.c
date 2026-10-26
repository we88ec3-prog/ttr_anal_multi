
void FUN_0060a370(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_58 [4];
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined1 local_38 [28];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093e630;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_58;
  ExceptionList = &local_14;
  iVar1 = in_ECX[0x3e];
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",DAT_00d61f20 ^ (uint)&stack0xffffffa0);
  }
  local_54 = (uint)local_54._2_2_ << 0x10;
  local_40 = 7;
  local_44 = 0;
  FUN_004026e0(iVar1 + 0x108,0,0xffffffff);
  local_c = 0;
  uVar2 = *(uint *)(param_1 + 0x10);
  if (uVar2 < 0x579) {
    if (uVar2 == 0x578) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
        FUN_0060a610(in_ECX);
      }
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20)) {
        (**(code **)(*in_ECX + 0xd4))();
      }
    }
    else {
      switch(uVar2) {
      case 1000:
        if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
          FUN_00761500();
          cVar3 = FUN_00466920();
          if (cVar3 != '\0') {
            (**(code **)(*(int *)in_ECX[0x42] + 0x94))(0);
            (**(code **)(*(int *)in_ECX[0x3f] + 0x90))(0);
            break;
          }
        }
        (**(code **)(*(int *)in_ECX[0x3f] + 0x90))(1);
        break;
      case 0x3e9:
        FUN_00761500();
        cVar3 = FUN_00466920();
        if (cVar3 != '\0') {
          (**(code **)(*(int *)in_ECX[0x42] + 0x94))(1);
        }
        break;
      case 0x3ea:
        if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
          FUN_00761500();
          cVar3 = FUN_0046df60();
          if (cVar3 != '\0') {
            if ((char)in_ECX[0x46] != '\0') {
              uVar4 = 0x35;
              FUN_005855b0(0x35);
              uVar4 = FUN_00585330(uVar4);
              FUN_00402250(uVar4);
              puVar5 = local_38;
              local_c = CONCAT31(local_c._1_3_,1);
              FUN_0040f8c0(puVar5);
              FUN_004d6b30(puVar5);
              FUN_004fa440();
              FUN_004fa440();
              goto LAB_0060a5d1;
            }
            FUN_0060a610(in_ECX);
          }
        }
        break;
      case 0x3ec:
        FUN_00761500();
        cVar3 = FUN_00466920();
        if (cVar3 == '\0') {
          (**(code **)(*(int *)in_ECX[0x3f] + 0x90))(1);
        }
        else {
          (**(code **)(*(int *)in_ECX[0x3f] + 0x90))(0);
        }
        break;
      case 0x3ed:
        if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3e] + 0x20)) {
          (**(code **)(*in_ECX + 0xd4))();
        }
      }
    }
  }
  if (7 < local_40) {
    FUN_0089120c(local_54);
  }
LAB_0060a5d1:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_58);
  return;
}

