
void FUN_0077ee00(void)

{
  undefined4 *puVar1;
  void *_Dst;
  uint uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ebf3;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbTransformNode::vftable;
  local_8 = 2;
  uVar4 = 0;
  uVar3 = (int)(in_ECX[0x33] - in_ECX[0x32]) >> 2;
  if (uVar3 != 0) {
    do {
      if (*(int *)(in_ECX[0x32] + uVar4 * 4) != 0) {
        puVar1 = *(undefined4 **)(in_ECX[0x32] + uVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1,uVar2);
        }
        *(undefined4 *)(in_ECX[0x32] + uVar4 * 4) = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  _Dst = (void *)in_ECX[0x32];
  if (_Dst != (void *)in_ECX[0x33]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[0x33],0);
    in_ECX[0x33] = _Dst;
  }
  FUN_00860810(in_ECX + 0x36,local_18,in_ECX[0x36],in_ECX[0x37]);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00860880(in_ECX + 0x36);
  if (in_ECX[0x32] != 0) {
    FUN_0089120c(in_ECX[0x32]);
  }
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  local_8 = 0xffffffff;
  *in_ECX = gbNode::vftable;
  FUN_00780000();
  ExceptionList = local_10;
  return;
}

