
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_007ab4e0(void)

{
  int iVar1;
  undefined **local_24 [3];
  undefined4 *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009150e1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = &DAT_00fd92a0;
  _DAT_00fd92a4 = 0;
  iVar1 = FUN_00891268(0xc,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar1 != 0) {
    DAT_00fd92a0 = iVar1;
    *(int *)iVar1 = iVar1;
    *(int *)(DAT_00fd92a0 + 4) = DAT_00fd92a0;
    local_8 = 0;
    _eh_vector_constructor_iterator_
              (&DAT_00fd92ac,0x1c,6,(_func_void_void_ptr *)&LAB_00402c30,FUN_00402c50);
    local_8._0_1_ = 1;
    _eh_vector_constructor_iterator_
              (&DAT_00fd936c,0x1c,4,(_func_void_void_ptr *)&LAB_00402c30,FUN_00402c50);
    local_8._0_1_ = 2;
    DAT_00fd93e0 = 0;
    _DAT_00fd93dc = 0x3f800000;
    _DAT_00fd93e4 = 0;
    _DAT_00fd93e8 = 0;
    FUN_007ac340();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00402a70("DamageEnemy.dds",0xf);
    FUN_00402a70("DamageNumber.dds",0x10);
    FUN_00402a70("NumberHeal.dds",0xe);
    FUN_00402a70("NumberSP.dds",0xc);
    FUN_00402a70("NumberMP.dds",0xc);
    FUN_00402a70("DamageEnemy.dds",0xf);
    _DAT_00fd9354 = 2;
    _DAT_00fd9358 = 2;
    _DAT_00fd935c = 1;
    _DAT_00fd9360 = 3;
    _DAT_00fd9364 = 4;
    _DAT_00fd9368 = 5;
    FUN_00402a70("miss.dds",8);
    FUN_00402a70("block.dds",9);
    FUN_00402a70("EnemyMiss.dds",0xd);
    FUN_00402a70("block.dds",9);
    ExceptionList = local_10;
    return &DAT_00fd92a0;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_24,&local_14);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

