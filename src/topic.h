#pragma once

#include "env.h"

class Topic {
public:
    Topic(Env* env, const std::string& name);
    ~Topic();

private:
    Topic(const Topic&);
    Topic& operator=(const Topic&);

public:
    inline Env* getEnv() { return _env; }
    inline const std::string& getName() { return _name; }

    uint32_t getProducerHeadFile(Txn& txn);
    void setProducerHeadFile(Txn& txn, uint32_t file, uint64_t offset);

    uint64_t getProducerHead(Txn& txn);
    void setProducerHead(Txn& txn, uint64_t head);

    uint32_t getConsumerHeadFile(Txn& txn, const std::string& name);
    uint64_t getConsumerHead(Txn& txn, const std::string& name);
    void setConsumerHead(Txn& txn, const std::string& name, uint64_t head);

private:
    Env *_env;

    std::string _name;
    MDB_dbi _desc;
};